# Snarl

A SHACL Core validator written in [SLOP](https://github.com/jcadam/slop).

Validates an RDF data graph against a SHACL shapes graph, producing a W3C-conformant validation report. Implements all SHACL Core constraints (no SHACL-SPARQL). Ships as a zero-dependency C library with Rust bindings available.

## Features

- **Full SHACL Core** — all constraint types: value type, cardinality, value range, string, pair-wise, logical, shape-based, and other (closed, hasValue, in)
- **All property path types** — predicate, sequence, alternative, inverse, zeroOrMore, oneOrMore, zeroOrOne
- **All target types** — targetNode, targetClass (with rdfs:subClassOf transitivity), targetSubjectsOf, targetObjectsOf, implicit class targets
- **W3C conformance** — passes 98 of 98 W3C SHACL Core test cases (0 expected failures, 0 skips)
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
```

Exit codes: `0` = conforms, `1` = violations, `2` = parse/internal error.

## Library Usage (C)

Snarl provides a C-compatible static library (`libsnarl.a`) with a stable header (`include/snarl.h`).

```c
#include "snarl.h"
#include "slop_runtime.h"

// Create arena, parse your TTL files into IndexedGraphs, then:
types_ValidatorResult result = snarl_validate(arena, data_graph, shapes_graph);

// Check conformance directly:
bool ok = snarl_conforms(arena, data_graph, shapes_graph);
```

Key API functions:

| Function | Description |
|----------|-------------|
| `snarl_validate` | Full validation, returns report with all results |
| `snarl_validate_with_config` | Validation with custom config (max errors, severity filtering) |
| `snarl_conforms` | Quick boolean conformance check |
| `snarl_report_to_string` | Serialize report as human-readable text |
| `snarl_report_to_graph` | Serialize report as an RDF graph (Turtle) |
| `snarl_get_violations` | Filter report results to violations only |

## Library Usage (Rust)

Rust bindings are in the `rust/` directory:

```rust
use snarl::{Arena, validate, conforms};

let arena = Arena::new();
let result = validate(&arena, &data_graph, &shapes_graph);
```

## Testing

Snarl includes two test suites:

**Integration tests** (`make test`) — CLI-level tests covering basic validation scenarios with purpose-built fixtures.

**W3C SHACL Core conformance tests** (`cli/tests/w3c/run-w3c-tests.sh`) — 98 test cases derived from the W3C SHACL test suite, covering property constraints, node constraints, target resolution, property paths, complex shapes, and validation report structure. All 98 pass with no expected failures.

```bash
# Run W3C conformance suite directly
bash cli/tests/w3c/run-w3c-tests.sh ./build/snarl
```

## Benchmarks

A comparison benchmark script (`cli/tests/benchmark_compare.py`) runs the same validation workloads against [pySHACL](https://github.com/RDFLib/pySHACL) (Python reference implementation) and [Rudof](https://github.com/rudof-project/rudof) (Rust). Results from one same-machine run with pySHACL 0.31.0 and Rudof 0.3.4:

| Dataset | Triples | Snarl | pySHACL | Rudof | vs pySHACL | vs Rudof |
|---------|--------:|------:|--------:|------:|-----------:|---------:|
| employee-dir | 25 | 3ms | 106ms | 320ms | 31.0x | 93.8x |
| library | 18 | 4ms | 93ms | 326ms | 25.5x | 89.5x |
| product-catalog | 18 | 4ms | 102ms | 300ms | 28.6x | 84.0x |
| address-book | 14 | 3ms | 93ms | 315ms | 27.9x | 94.5x |
| multi-shape | 11 | 3ms | 101ms | 299ms | 31.4x | 92.9x |
| employees-1k | 4,955 | 23ms | 290ms | 345ms | 12.8x | 15.2x |
| employees-10k | 49,493 | 220ms | 2.10s | 581ms | 9.6x | 2.6x |
| employees-100k | 494,962 | 2.54s | 21.69s | 4.04s | 8.5x | 1.6x |
| meteorites | 1,010,109 | 2.83s | 22.09s | 4.93s | 7.8x | 1.7x |

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
| String | sh:minLength, sh:maxLength, sh:pattern, sh:languageIn, sh:uniqueLang | §4.6–4.7 |
| Pair-wise | sh:equals, sh:disjoint, sh:lessThan, sh:lessThanOrEquals | §4.8 |
| Logical | sh:not, sh:and, sh:or, sh:xone | §4.9 |
| Shape-based | sh:node, sh:property, sh:qualifiedValueShape | §4.10 |
| Other | sh:closed, sh:ignoredProperties, sh:hasValue, sh:in | §4.11–4.12 |

## License

Apache 2.0
