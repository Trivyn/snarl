"""Compare snarl's validation results with the W3C SHACL Core expected reports.

Usage: python run-w3c-results.py path/to/snarl   (needs rdflib)

run-w3c-tests.sh checks only sh:conforms. This checks the results too, as the
SHACL test-suite document asks: each expected sh:ValidationResult must be
reported, and no other, comparing sh:focusNode, sh:resultPath, sh:value,
sh:sourceShape, sh:sourceConstraintComponent and sh:resultSeverity
(sh:resultMessage is not compared). Results are compared as a multiset.
A sh:resultPath is compared by its path structure; any other blank node
matches any blank node.

Entries listed in results-xfail.txt are expected to fail. The run fails on an
unexpected failure, and when no tests were found (run download.sh first).
"""

import os
import subprocess
import sys
import tempfile
from collections import Counter

import rdflib
from rdflib import BNode, Graph, Namespace, URIRef
from rdflib.collection import Collection
from rdflib.namespace import RDF

# Keep literals as written: "aldi"^^xsd:integer must stay distinguishable.
rdflib.NORMALIZE_LITERALS = False
import logging
logging.getLogger("rdflib").setLevel(logging.CRITICAL)
import warnings
warnings.filterwarnings("ignore")

MF = Namespace("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#")
SHT = Namespace("http://www.w3.org/ns/shacl-test#")
SH = Namespace("http://www.w3.org/ns/shacl#")

DIR = os.path.dirname(os.path.abspath(__file__))
CATEGORIES = ["property", "node", "targets", "path", "misc", "complex", "validation-reports"]
PATH_OPS = [(SH.inversePath, "^"), (SH.alternativePath, "|"), (SH.zeroOrMorePath, "*"),
            (SH.oneOrMorePath, "+"), (SH.zeroOrOnePath, "?")]


def path_key(g, node, depth=0):
    """A canonical string for the SHACL path at node."""
    if not isinstance(node, BNode) or depth > 50:
        return node.n3()
    if g.value(node, RDF.first) is not None:
        return "(" + " / ".join(path_key(g, m, depth + 1) for m in Collection(g, node)) + ")"
    for pred, op in PATH_OPS:
        inner = g.value(node, pred)
        if inner is not None:
            if pred == SH.alternativePath:
                return "(" + " | ".join(path_key(g, m, depth + 1) for m in Collection(g, inner)) + ")"
            return op + path_key(g, inner, depth + 1)
    return "_:"


def term_key(t):
    if t is None:
        return "-"
    return "_:" if isinstance(t, BNode) else t.n3()


def result_keys(g, report):
    keys = Counter()
    for r in g.objects(report, SH.result):
        path = g.value(r, SH.resultPath)
        keys[(term_key(g.value(r, SH.focusNode)),
              "-" if path is None else path_key(g, path),
              term_key(g.value(r, SH.value)),
              term_key(g.value(r, SH.sourceShape)),
              term_key(g.value(r, SH.sourceConstraintComponent)),
              term_key(g.value(r, SH.resultSeverity)))] += 1
    return keys


def local_path(uri):
    s = str(uri)
    return s[len("file://"):] if s.startswith("file://") else None


def check(snarl, g, entry):
    expected = g.value(entry, MF.result)
    action = g.value(entry, MF.action)
    data = local_path(g.value(action, SHT.dataGraph))
    shapes = local_path(g.value(action, SHT.shapesGraph)) or data
    with tempfile.TemporaryDirectory() as tmp:
        out = os.path.join(tmp, "report.ttl")
        r = subprocess.run([snarl, "-q", "--emit", out, "-s", shapes, data], capture_output=True, text=True)
        if expected == SHT.Failure:
            return (r.returncode == 2, [f"expected failure, got exit {r.returncode}"])
        if r.returncode == 2:
            return (False, [(r.stdout + r.stderr).strip().splitlines()[-1]])
        got = Graph()
        if os.path.exists(out) and os.path.getsize(out) > 0:
            try:
                got.parse(out, format="turtle")
            except Exception as e:  # a report rdflib cannot read is a failure, not a crash
                with open(out) as f:
                    lines = f.read().splitlines()
                at = getattr(e, "lines", None)
                where = lines[at] if isinstance(at, int) and at < len(lines) else ""
                return (False, ["snarl's report is not valid Turtle: " + where.strip()[:160]])
    report = got.value(None, RDF.type, SH.ValidationReport)
    want = result_keys(g, expected)
    have = result_keys(got, report) if report is not None else Counter()
    want_conforms = g.value(expected, SH.conforms)
    got_conforms = got.value(report, SH.conforms) if report is not None else None
    detail = []
    if want_conforms is None or got_conforms is None or want_conforms.toPython() != got_conforms.toPython():
        detail.append(f"conforms: expected {want_conforms}, got {got_conforms}")
    for k in sorted((want - have).elements()):
        detail.append("missing: " + " ".join(k))
    for k in sorted((have - want).elements()):
        detail.append("extra:   " + " ".join(k))
    return (not detail, detail)


def main():
    snarl = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else "../../build/snarl")
    if not os.access(snarl, os.X_OK):
        print(f"ERROR: snarl binary not found at {snarl}")
        return 2
    xfail = {}
    with open(os.path.join(DIR, "results-xfail.txt")) as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith("#"):
                test_id, _, reason = line.partition(" ")
                xfail[test_id] = reason.strip()

    counts = Counter()
    failures, xpasses, seen = [], [], set()
    for category in CATEGORIES:
        cdir = os.path.join(DIR, category)
        if not os.path.isdir(cdir):
            continue
        for name in sorted(os.listdir(cdir)):
            if not name.endswith(".ttl") or name == "manifest.ttl":
                continue
            path = os.path.join(cdir, name)
            g = Graph()
            g.parse(path, format="turtle", publicID=URIRef("file://" + path))
            manifest = g.value(None, RDF.type, MF.Manifest)
            if manifest is None or g.value(manifest, MF.entries) is None:
                continue
            for entry in Collection(g, g.value(manifest, MF.entries)):
                test_id = f"{category}/{name}"
                seen.add(test_id)
                ok, detail = check(snarl, g, entry)
                if test_id in xfail:
                    key = "xpass" if ok else "xfail"
                    if ok:
                        xpasses.append(test_id)
                else:
                    key = "pass" if ok else "fail"
                    if not ok:
                        failures.append((test_id, detail))
                counts[key] += 1
                print(f"  {test_id:55} {key.upper()}")

    total = sum(counts.values())
    stale = sorted(set(xfail) - seen)
    print("\n========================================")
    print("W3C SHACL Core validation-result comparison")
    print("========================================")
    print(f"  Total:  {total}")
    print(f"  Pass:   {counts['pass']}")
    print(f"  Fail:   {counts['fail']}")
    print(f"  XFail:  {counts['xfail']}  (expected failures)")
    print(f"  XPass:  {counts['xpass']}  (unexpected passes)\n")
    if xpasses:
        print("*** UNEXPECTED PASSES (remove from results-xfail.txt): ***")
        print("\n".join(f"  {t}" for t in xpasses) + "\n")
    if stale:
        print("*** results-xfail.txt entries matching no test: ***")
        print("\n".join(f"  {t}" for t in stale) + "\n")
    if failures:
        print("*** UNEXPECTED FAILURES: ***")
        for test_id, detail in failures:
            print(f"  {test_id}")
            for d in detail:
                print(f"      {d}")
        print()
    if total == 0:
        print("RESULT: FAIL (no test cases found -- run 'bash cli/tests/w3c/download.sh' first)")
        return 1
    if failures or xpasses or stale:
        print(f"RESULT: FAIL ({len(failures)} unexpected failure(s), {len(xpasses)} unexpected pass(es), {len(stale)} stale xfail)")
        return 1
    print("RESULT: OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
