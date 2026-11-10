"""Run the W3C SHACL 1.2 test cases against snarl's experimental --shacl12 mode.

Usage: python run-w3c12-tests.py path/to/snarl   (needs rdflib)

Three kinds of test entry are run, each through the snarl CLI:

  sht:Infer         --shacl12 --emit-inferred; the inferred triples must equal
                    mf:result (a list of triples), or snarl must exit 2 when
                    mf:result is sht:Failure.
  sht:EvalNodeExpr  The expression is wrapped as the sh:object of a
                    sh:TripleRule on a shape targeting sht:focusNode, and the
                    inferred objects are its output. They are compared to
                    mf:result as a set: the CLI cannot show output order or
                    duplicates (the draft leaves path value order
                    implementation-defined anyway).
  sht:Validate      --shacl12 --emit; sh:conforms and the set of
                    (focus node, source shape, constraint component, value)
                    results must match mf:result.

Entries listed in xfail.txt are expected to fail. The run fails on an
unexpected failure, and also when no tests were found (a fresh checkout has
none until download.sh runs).
"""

import os
import subprocess
import sys
import tempfile

import rdflib
from rdflib import BNode, Graph, Namespace, URIRef
from rdflib.collection import Collection
from rdflib.compare import isomorphic
from rdflib.namespace import RDF

# Keep literals exactly as written: rdflib otherwise rewrites lexical forms
# ("01"^^xsd:integer becomes "1") when it re-serializes a wrapped test, which
# would change what the term-equality tests test.
rdflib.NORMALIZE_LITERALS = False

MF = Namespace("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#")
SHT = Namespace("http://www.w3.org/ns/shacl-test#")
SH = Namespace("http://www.w3.org/ns/shacl#")
OUT_SUBJECT = URIRef("urn:snarl-test:output")
OUT_PREDICATE = URIRef("urn:snarl-test:value")
NO_FOCUS = URIRef("urn:snarl-test:no-focus-node")

DIR = os.path.dirname(os.path.abspath(__file__))
SUITES = ["inference-rules", "node-expr/shnex", "node-expr/constraints"]


def load(path):
    g = Graph()
    g.parse(path, format="turtle", publicID=URIRef("file://" + os.path.abspath(path)))
    return g


def local_path(uri):
    s = str(uri)
    return s[len("file://"):] if s.startswith("file://") else None


def rdf_list(g, head):
    return list(Collection(g, head)) if head is not None else []


def run_snarl(snarl, args):
    r = subprocess.run([snarl, "-q", "--shacl12"] + args, capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def read_ttl(path):
    g = Graph()
    if os.path.exists(path) and os.path.getsize(path) > 0:
        g.parse(path, format="turtle")
    return g


def check_infer(snarl, g, entry, tmp):
    action = g.value(entry, MF.action)
    data = local_path(g.value(action, SHT.dataGraph))
    shapes = local_path(g.value(action, SHT.shapesGraph)) or data
    expected = g.value(entry, MF.result)
    out = os.path.join(tmp, "inferred.ttl")
    code, msg = run_snarl(snarl, ["--emit-inferred", out, "-s", shapes, data])
    if expected == SHT.Failure:
        return (code == 2, f"expected failure, got exit {code}")
    if code == 2:
        return (False, msg.splitlines()[-1] if msg else "exit 2")
    want = Graph()
    for t in rdf_list(g, expected):
        want.add(tuple(rdf_list(g, t)))
    got = read_ttl(out)
    if isomorphic(want, got):
        return (True, "")
    return (False, f"expected {len(want)} triple(s), got {len(got)}: "
                   + " ".join(sorted(f"({s.n3()} {p.n3()} {o.n3()})" for s, p, o in got))[:300])


def check_eval(snarl, g, entry, tmp):
    action = g.value(entry, MF.action)
    expr = g.value(action, SHT.nodeExpr)
    focus = g.value(action, SHT.focusNode) or NO_FOCUS
    expected = g.value(entry, MF.result)
    test = Graph()
    for t in g:
        test.add(t)
    shape, rule = BNode(), BNode()
    test.add((shape, RDF.type, SH.NodeShape))
    test.add((shape, SH.targetNode, focus))
    test.add((shape, SH.rule, rule))
    test.add((rule, RDF.type, SH.TripleRule))
    test.add((rule, SH.subject, OUT_SUBJECT))
    test.add((rule, SH.predicate, OUT_PREDICATE))
    test.add((rule, SH.object, expr))
    path = os.path.join(tmp, "eval.ttl")
    test.serialize(path, format="turtle")
    out = os.path.join(tmp, "inferred.ttl")
    code, msg = run_snarl(snarl, ["--emit-inferred", out, path])
    if expected == SHT.Failure:
        return (code == 2, f"expected failure, got exit {code}")
    if code == 2:
        return (False, msg.splitlines()[-1] if msg else "exit 2")
    want = set(rdf_list(g, expected))
    got = set(read_ttl(out).objects(OUT_SUBJECT, OUT_PREDICATE))
    # Blank node outputs cannot be compared by label: compare their count.
    if any(isinstance(n, BNode) for n in want | got):
        same = len(want) == len(got)
    else:
        same = want == got
    if same:
        return (True, "")
    return (False, "expected {" + ", ".join(sorted(n.n3() for n in want))
                   + "}, got {" + ", ".join(sorted(n.n3() for n in got)) + "}")


def result_keys(g, report):
    keys = set()
    for r in g.objects(report, SH.result):
        keys.add((g.value(r, SH.focusNode), g.value(r, SH.sourceShape),
                  g.value(r, SH.sourceConstraintComponent), g.value(r, SH.value)))
    return keys


def check_validate(snarl, g, entry, tmp):
    action = g.value(entry, MF.action)
    data = local_path(g.value(action, SHT.dataGraph))
    shapes = local_path(g.value(action, SHT.shapesGraph)) or data
    expected = g.value(entry, MF.result)
    out = os.path.join(tmp, "report.ttl")
    code, msg = run_snarl(snarl, ["--emit", out, "-s", shapes, data])
    if expected == SHT.Failure:
        return (code == 2, f"expected failure, got exit {code}")
    if code == 2:
        return (False, msg.splitlines()[-1] if msg else "exit 2")
    got = read_ttl(out)
    report = got.value(None, RDF.type, SH.ValidationReport) or next(got.subjects(SH.conforms, None), None)
    want_conforms = g.value(expected, SH.conforms).toPython()
    got_conforms = got.value(report, SH.conforms).toPython() if report is not None else None
    # Blank-node result fields (an inline sh:expression as source shape or
    # value) match any blank node.
    def norm(keys):
        return {tuple("_:" if isinstance(x, BNode) else x for x in k) for k in keys}
    want, have = norm(result_keys(g, expected)), norm(result_keys(got, report))
    if want_conforms == got_conforms and want == have:
        return (True, "")
    return (False, f"conforms {want_conforms}/{got_conforms}, results {len(want)}/{len(have)}")


CHECKS = {SHT.Infer: check_infer, SHT.EvalNodeExpr: check_eval, SHT.Validate: check_validate}


def main():
    snarl = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else "../../build/snarl")
    if not os.access(snarl, os.X_OK):
        print(f"ERROR: snarl binary not found at {snarl}")
        return 2
    xfail = {}
    with open(os.path.join(DIR, "xfail.txt")) as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith("#"):
                test_id, _, reason = line.partition(" ")
                xfail[test_id] = reason.strip()

    counts = {"pass": 0, "fail": 0, "xfail": 0, "xpass": 0}
    failures, xpasses = [], []
    seen = set()
    for suite in SUITES:
        sdir = os.path.join(DIR, suite)
        if not os.path.isdir(sdir):
            continue
        for name in sorted(os.listdir(sdir)):
            if not name.endswith(".ttl") or name == "manifest.ttl":
                continue
            path = os.path.join(sdir, name)
            try:
                g = load(path)
            except Exception as e:  # an unparseable case is a failure to report, not a crash
                g = None
                load_error = ("rdflib could not parse the file: " + " ".join(str(e).split()))[:200]
            manifest = g.value(None, RDF.type, MF.Manifest) if g is not None else None
            entries = rdf_list(g, g.value(manifest, MF.entries)) if manifest is not None else []
            for entry in entries:
                test_id = f"{suite}/{name[:-4]}#{str(entry).rsplit('/', 1)[-1]}"
                seen.add(test_id)
                kind = g.value(entry, RDF.type)
                check = CHECKS.get(kind)
                with tempfile.TemporaryDirectory() as tmp:
                    ok, detail = check(snarl, g, entry, tmp) if check else (False, f"unknown test type {kind}")
                if test_id in xfail:
                    key = "xpass" if ok else "xfail"
                    if ok:
                        xpasses.append(test_id)
                else:
                    key = "pass" if ok else "fail"
                    if not ok:
                        failures.append(f"{test_id}: {detail}")
                counts[key] += 1
                print(f"  {test_id:70} {key.upper()}" + (f"  ({detail})" if key == "fail" else ""))
            if g is None:
                test_id = f"{suite}/{name[:-4]}"
                seen.add(test_id)
                if test_id in xfail:
                    counts["xfail"] += 1
                    print(f"  {test_id:70} XFAIL")
                else:
                    counts["fail"] += 1
                    failures.append(f"{test_id}: {load_error}")
                    print(f"  {test_id:70} FAIL  ({load_error})")

    total = sum(counts.values())
    stale = sorted(set(xfail) - seen)
    print("\n========================================")
    print("W3C SHACL 1.2 Test Results (--shacl12)")
    print("========================================")
    print(f"  Total:  {total}")
    print(f"  Pass:   {counts['pass']}")
    print(f"  Fail:   {counts['fail']}")
    print(f"  XFail:  {counts['xfail']}  (expected failures)")
    print(f"  XPass:  {counts['xpass']}  (unexpected passes)\n")
    if xpasses:
        print("*** UNEXPECTED PASSES (remove from xfail.txt): ***")
        print("\n".join(f"  {t}" for t in xpasses) + "\n")
    if stale:
        print("*** xfail.txt entries matching no test: ***")
        print("\n".join(f"  {t}" for t in stale) + "\n")
    if failures:
        print("*** UNEXPECTED FAILURES: ***")
        print("\n".join(f"  {t}" for t in failures) + "\n")
    if total == 0:
        print("RESULT: FAIL (no test cases found -- run 'bash cli/tests/w3c12/download.sh' first)")
        return 1
    if failures:
        print(f"RESULT: FAIL ({len(failures)} unexpected failure(s))")
        return 1
    print("RESULT: OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
