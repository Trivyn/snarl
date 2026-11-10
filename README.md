# Snarl

A SHACL Core validator written in [SLOP](https://github.com/jcadam/slop).

Validates an RDF data graph against a SHACL shapes graph, producing a W3C-conformant validation report. Implements all SHACL Core constraints, plus the part of [SHACL Advanced Features](https://www.w3.org/TR/shacl-af/) that does not need SPARQL: node expressions, `sh:expression` constraints and `sh:TripleRule` inference. No SHACL-SPARQL. Ships as a zero-dependency C library with Rust bindings available.

## Features

- **Full SHACL Core** — all constraint types: value type, cardinality, value range, string, pair-wise, logical, shape-based, and other (closed, hasValue, in)
- **All property path types** — predicate, sequence, alternative, inverse, zeroOrMore, oneOrMore, zeroOrOne
- **All target types** — targetNode, targetClass (with rdfs:subClassOf transitivity), targetSubjectsOf, targetObjectsOf, implicit class targets
- **SHACL-AF (non-SPARQL)** — node expressions (focus node, constant, path, filter shape, intersection, union), `sh:expression`, and `sh:TripleRule` rules with `sh:condition`, `sh:order`, `sh:deactivated` and `sh:entailment sh:Rules`. See [SHACL Advanced Features](#shacl-advanced-features).
- **W3C conformance** — passes 98 of 98 W3C SHACL Core test cases (0 expected failures, 0 skips), comparing every validation result (focus node, path, value, source shape, constraint component, severity), not only `sh:conforms`
- **Fast** — single-pass validation with indexed graph lookups; benchmarks against pySHACL and Rudof included
- **Embeddable** — static library (`libsnarl.a`) with stable C API and auto-generated header
- **Rust bindings** — available via the `snarl` crate (`rust/`)

## Quick Start

```bash
# Build from pre-transpiled C (no SLOP toolchain needed)
make

# Validate a data graph against shapes
./build/snarl data.ttl shapes.ttl

# Single file (serves as both data and shapes)
./build/snarl combined.ttl

# Quiet mode (just exit code)
./build/snarl -q data.ttl shapes.ttl
echo $?  # 0 = conforms, 1 = violations, 2 = error
```

## Building

```bash
make          # Build CLI executable
make lib      # Build static library (build/libsnarl.a)
make test     # Run integration + W3C conformance tests
make bench    # Run benchmark comparison (pySHACL, Rudof, Snarl)
make release  # Optimized -O3 build
make clean    # Remove build artifacts
```

Pre-transpiled C sources are checked in under `csrc/`, so building requires only a C compiler — no SLOP toolchain needed.

Linux and macOS are supported, with prebuilt binaries attached to each GitHub release. **Windows support is preliminary:** build from an MSYS2 MINGW64 shell with `mingw-w64-x86_64-gcc` and `make` installed (the executable is `build/snarl.exe`). Windows CI results are reported but do not gate releases, and a Windows binary is attached to a release only when its tests passed.

## CLI Usage

```
snarl [options] <data.ttl> [shapes.ttl]
  -h, --help         Show usage
  -V, --version      Show version
  -q, --quiet        Only print violation count
  -o, --emit FILE    Write validation report as Turtle
  -s, --shapes FILE  Explicit shapes file
  -m, --max-errors N Stop after N violations
  --no-warnings      Suppress sh:Warning results
  --no-infos         Suppress sh:Info results
  -r, --rules        Run SHACL rules (sh:TripleRule) before validating
  --emit-inferred FILE  Run rules and write the inferred triples as Turtle
  --shacl12          EXPERIMENTAL: also accept SHACL 1.2 Working Draft syntax
```

Exit codes: `0` = conforms, `1` = violations, `2` = parse/internal error
(including a shapes graph snarl rejects, such as an `sh:pattern` its regex
engine cannot compile, or SHACL-AF input it cannot execute, such as an
`sh:SPARQLRule`).

## Literals and regular expressions

- **Ordering** (`sh:minInclusive` and its siblings, `sh:lessThan`): numeric literals of any XSD numeric type compare by value, `xsd:dateTime` and `xsd:date` on the timeline (a value with a timezone and one without are comparable only when more than 14 hours apart, as XSD specifies), `xsd:string` by code point. Other datatypes (`xsd:time`, durations, `gYear`, …) are not ordered, so a range constraint on them reports a violation.
- **`sh:datatype`** rejects a literal whose lexical form is ill-formed for the XSD numeric and boolean types, `xsd:dateTime` and `xsd:date`. Other datatypes are checked by IRI only.
- **`sh:pattern`** uses POSIX extended regular expressions (a vendored engine, the same on every platform), not the XPath dialect SHACL names; most everyday patterns are the same in both. `sh:flags` supports `i` and `s`; any other flag is an error (exit 2).

## SHACL Advanced Features

Snarl implements the part of [SHACL Advanced Features](https://www.w3.org/TR/shacl-af/) (W3C Note, 2017) that does not depend on SPARQL. SHACL Core 1.0 validation is unchanged: a shapes graph without AF terms validates exactly as before.

| AF section | Feature | Status |
|---|---|---|
| §6 | Node expressions: `sh:this`, constants, path (`sh:path` + `sh:nodes`), filter shape, `sh:intersection`, `sh:union` | ✅ |
| §6.4 | Function expressions | ❌ needs SHACL functions (SPARQL) — rejected with an error |
| §7 | `sh:expression` (`sh:ExpressionConstraintComponent`, with `sh:sourceConstraint` in results) | ✅ |
| §8 | `sh:rule` / `sh:TripleRule`, `sh:condition`, `sh:order`, `sh:deactivated` | ✅ |
| §8.3 | `sh:entailment sh:Rules` (rules run automatically before validation) | ✅ |
| §3–5, §8.6 | SPARQL targets, annotations and functions; `sh:SPARQLRule` | ❌ rejected with an error |

**Rules** run as a separate stage before validation, once (AF §8.4 specifies a single iteration). They run when you pass `-r`/`--rules` (or `--emit-inferred`), or when the shapes graph declares `sh:entailment sh:Rules`. Rules are ordered by `sh:order`: by the shape's order, then the rule's. Rules with the same order key run together: none sees another's triples, and a later order level sees everything the earlier levels inferred. Combinations that cannot form an RDF triple (a literal subject, a non-IRI predicate) are skipped. Inferred triples are added to the data graph before validation, so an inferred `rdf:type` creates new `sh:targetClass` focus nodes.

**Unsupported input fails loudly.** A function expression, an `sh:SPARQLRule` or other non-triple rule type, an `sh:entailment` other than `sh:Rules`, an ill-formed node expression or rule, and a cyclic or over-deep node expression all exit with code 2 and a message naming the problem — never a silently skipped rule.

```bash
# Infer, validate the result, and keep the inferred triples
./build/snarl --rules --emit-inferred inferred.ttl data.ttl shapes.ttl
```

### Experimental SHACL 1.2 mode (`--shacl12`)

The SHACL 1.2 Working Drafts ([Inference Rules](https://www.w3.org/TR/shacl12-inference-rules/), [Node Expressions](https://www.w3.org/TR/shacl12-node-expr/)) carry AF's rules and node expressions forward with changes. `--shacl12` (`ValidatorConfig::shacl12` in the API) additionally accepts the 1.2 syntax that overlaps what snarl implements:

- `shnex:` node expressions: `shnex:var "focusNode"`, `shnex:pathValues` (+ `shnex:focusNode`), `shnex:filterShape` + `shnex:nodes`, `shnex:intersection`, list expressions, the empty expression
- `sh:TripleRule` slots that default to the focus node when absent
- the `sh:RulesEntailment` entailment regime
- shape-level `sh:order` is ignored, as 1.2 specifies

This mode is **experimental**: the drafts are still changing, and so will it. 1.2 constructs snarl does not implement — the other `shnex:` functions (`shnex:count`, `shnex:if`, …), global rules, rule sets, layers, `sh:ShapeClass`, `sh:nodeByExpression`, SPARQL rules and templates — are rejected with an error in this mode rather than ignored. Without `--shacl12`, any `shnex:` term is an error that names the flag.

## Library Usage (C)

Snarl provides a C-compatible static library (`libsnarl.a`) with a stable header (`include/snarl.h`).

```c
#include "snarl.h"
#include "slop_runtime.h"

// Existing compatibility path: validate general IndexedGraphs.
types_ValidatorResult result = snarl_validate(arena, data_graph, shapes_graph);

// Fast data path: use SnarlDataGraph for large data graphs and IndexedGraph for shapes.
types_ValidatorResult fast_result =
    snarl_validate_data_graph(arena, snarl_data_graph, shapes_graph);
```

Key API functions:

| Function | Description |
|----------|-------------|
| `snarl_validate` | Full validation, returns report with all results |
| `snarl_validate_with_config` | Validation with custom config (max errors, severity filtering) |
| `snarl_validate_data_graph` | Validate a Snarl-optimized data graph against indexed shapes |
| `snarl_conforms` | Quick boolean conformance check |
| `snarl_report_to_string` | Serialize report as human-readable text |
| `snarl_report_to_graph` | Serialize report as an RDF graph (Turtle) |
| `snarl_get_violations` | Filter report results to violations only |

## Library Usage (Rust)

Rust bindings are in the `rust/` directory:

```rust
use snarl::{Arena, SnarlDataGraph, IndexedGraph, validate_data_graph};

let arena = Arena::with_default_capacity();
let data_graph = SnarlDataGraph::new(&arena);
let shapes_graph = IndexedGraph::new(&arena);
let result = validate_data_graph(&arena, &data_graph, &shapes_graph);
```

SHACL-AF rules: `ValidatorConfig::new().run_rules(true)` with `validate_data_graph_with_inference` (validates, and returns the inferred triples), or `infer` to run the rules alone. Both add the inferred triples to the `SnarlDataGraph`. Results of `sh:expression` constraints carry `source_constraint`.

## Testing

Snarl includes three test suites:

**Integration tests** (`make test`) — CLI-level tests covering basic validation scenarios with purpose-built fixtures, and SHACL-AF: every node-expression kind, `sh:expression`, rules (conditions, order levels, deactivation, entailment) and each rejected input.

**W3C SHACL Core conformance tests** — 98 test cases derived from the W3C SHACL test suite, covering property constraints, node constraints, target resolution, property paths, complex shapes, and validation report structure. All 98 pass with no expected failures, in two runners:

- `make w3c-test` (`cli/tests/w3c/run-w3c-tests.sh`) checks `sh:conforms`. It needs only bash.
- `make w3c-results-test` (`cli/tests/w3c/run-w3c-results.py`) writes each report with `--emit` and compares its results with the expected ones: `sh:focusNode`, `sh:resultPath`, `sh:value`, `sh:sourceShape`, `sh:sourceConstraintComponent` and `sh:resultSeverity`. It needs `uv` (for rdflib).

```bash
# Run W3C conformance suite directly
bash cli/tests/w3c/run-w3c-tests.sh ./build/snarl
```

**W3C SHACL 1.2 tests** (`make w3c12-test`) — the experimental `--shacl12` mode against the W3C SHACL 1.2 inference-rules and node-expression cases. Of 189 cases, 51 pass; the other 138 are listed in `cli/tests/w3c12/xfail.txt`, each with its reason (SPARQL, a 1.2 feature beyond the AF overlap, or a case the CLI-driven runner cannot express). A few expected-failure cases pass only because snarl rejects the unsupported input they contain. Needs `uv` (for rdflib); download the cases first:

```bash
bash cli/tests/w3c12/download.sh
make w3c12-test
```

## Benchmarks

A comparison benchmark script (`cli/tests/benchmark_compare.py`) runs the same validation workloads against [pySHACL](https://github.com/RDFLib/pySHACL) (Python reference implementation) and [Rudof](https://github.com/rudof-project/rudof) (Rust). Results from one same-machine run with pySHACL 0.31.0 and Rudof 0.3.4:

| Dataset | Triples | Snarl | pySHACL | Rudof | vs pySHACL | vs Rudof |
|---------|--------:|------:|--------:|------:|-----------:|---------:|
| employee-dir | 25 | 3ms | 105ms | 298ms | 33.1x | 93.8x |
| library | 18 | 3ms | 93ms | 300ms | 30.9x | 99.9x |
| product-catalog | 18 | 3ms | 106ms | 305ms | 36.9x | 106.3x |
| address-book | 14 | 3ms | 94ms | 299ms | 34.6x | 110.4x |
| multi-shape | 11 | 3ms | 97ms | 298ms | 31.9x | 98.4x |
| employees-1k | 4,955 | 20ms | 288ms | 326ms | 14.7x | 16.6x |
| employees-10k | 49,493 | 193ms | 2.09s | 585ms | 10.8x | 3.0x |
| employees-100k | 494,962 | 2.14s | 21.59s | 4.06s | 10.1x | 1.9x |
| meteorites | 1,010,109 | 2.44s | 22.04s | 4.88s | 9.0x | 2.0x |

All validators produced matching result counts across these benchmarks. The Rudof comparison uses its minimal result format so the benchmark can parse validation counts directly instead of scraping table output. The meteorites row uses the data-only `test_data/large_meteorite_data.ttl` fixture so all three validators can parse the same graph.

```bash
make bench
# or run directly:
cd cli/tests && python benchmark_compare.py
```

## Constraint Coverage

| Category | Constraints | W3C Spec |
|----------|-------------|----------|
| Value Type | sh:class, sh:datatype, sh:nodeKind | §4.1–4.3 |
| Cardinality | sh:minCount, sh:maxCount | §4.4 |
| Value Range | sh:minInclusive, sh:maxInclusive, sh:minExclusive, sh:maxExclusive | §4.5 |
| String | sh:minLength, sh:maxLength, sh:pattern (+ sh:flags `i`, `s`), sh:languageIn, sh:uniqueLang | §4.6–4.7 |
| Pair-wise | sh:equals, sh:disjoint, sh:lessThan, sh:lessThanOrEquals | §4.8 |
| Logical | sh:not, sh:and, sh:or, sh:xone | §4.9 |
| Shape-based | sh:node, sh:property, sh:qualifiedValueShape | §4.10 |
| Other | sh:closed, sh:ignoredProperties, sh:hasValue, sh:in | §4.11–4.12 |
| Expression (SHACL-AF) | sh:expression | AF §7 |

## License

Apache 2.0
