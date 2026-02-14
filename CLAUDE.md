# Snarl — SHACL Core Validator

SHACL Core constraint validator written in SLOP. Apache 2.0 licensed.

Validates an RDF data graph against a SHACL shapes graph, producing a validation report per the W3C SHACL specification. SHACL Core only — no SHACL-SPARQL.

## Dependencies

- **slop-rdf** (`../slop-rdf`): Turtle parsing, RDF types (`Term`, `Triple`, `IndexedGraph`), vocabulary constants, XSD datatype support, RDF list utilities.

## Directory Structure

```
src/                    Library source
  snarl.slop            Public API (validate, conforms, report helpers)
  types.slop            Core type definitions
  engine.slop           Validation engine (shape eval loop)
  parse.slop            Shapes graph extraction from RDF triples
  path.slop             SHACL property path evaluation
  target.slop           Target resolution
  report.slop           Report construction + serialization
  constraints/          One file per constraint group
    value-type.slop     sh:class, sh:datatype, sh:nodeKind
    cardinality.slop    sh:minCount, sh:maxCount
    value-range.slop    sh:minInclusive/maxInclusive/minExclusive/maxExclusive
    string.slop         sh:minLength, sh:maxLength, sh:pattern, sh:languageIn, sh:uniqueLang
    pair.slop           sh:equals, sh:disjoint, sh:lessThan, sh:lessThanOrEquals
    logical.slop        sh:not, sh:and, sh:or, sh:xone
    shape.slop          sh:node, sh:property, sh:qualifiedValueShape
    other.slop          sh:closed, sh:ignoredProperties, sh:hasValue, sh:in
cli/
  main.slop             CLI entry point
  tests/                Integration tests + fixtures
```

## Build Commands

```bash
make all        # Build CLI executable (default)
make lib        # Build build/libsnarl.a static library
make cli        # Build build/snarl executable
make test       # Build + run CLI integration tests
make bench      # Build + run benchmark comparison (pySHACL, Rudof, Snarl)
make release    # Optimized -O3 build
make slop-build # Transpile SLOP sources, update include/snarl.h
make csrc       # Update pre-transpiled C
make dist       # Package lib + header for distribution
make clean      # Remove build/
```

## Public API (`:c-name` mappings)

| Function | C Name | Signature |
|----------|--------|-----------|
| `validate` | `snarl_validate` | `(Arena IndexedGraph IndexedGraph) -> ValidatorResult` |
| `validate-with-config` | `snarl_validate_with_config` | `(Arena IndexedGraph IndexedGraph ValidatorConfig) -> ValidatorResult` |
| `conforms` | `snarl_conforms` | `(Arena IndexedGraph IndexedGraph) -> Bool` |
| `default-config` | `snarl_default_config` | `() -> ValidatorConfig` |
| `get-violations` | `snarl_get_violations` | `(ValidationReport) -> (List ValidationResult)` |
| `get-warnings` | `snarl_get_warnings` | `(ValidationReport) -> (List ValidationResult)` |
| `get-result-count` | `snarl_get_result_count` | `(ValidationReport) -> Int` |
| `report-to-graph` | `snarl_report_to_graph` | `(Arena ValidationReport) -> IndexedGraph` |
| `report-to-string` | `snarl_report_to_string` | `(Arena ValidationReport) -> String` |

Both `data-graph` and `shapes-graph` are `IndexedGraph` from slop-rdf. Caller handles Turtle parsing.

## Constraint Module Map

| Module | Constraints | W3C Section |
|--------|-------------|-------------|
| value-type | sh:class, sh:datatype, sh:nodeKind | 4.1-4.3 |
| cardinality | sh:minCount, sh:maxCount | 4.4 |
| value-range | sh:min/maxInclusive, sh:min/maxExclusive | 4.5 |
| string | sh:minLength, sh:maxLength, sh:pattern, sh:languageIn, sh:uniqueLang | 4.6-4.7 |
| pair | sh:equals, sh:disjoint, sh:lessThan, sh:lessThanOrEquals | 4.8 |
| logical | sh:not, sh:and, sh:or, sh:xone | 4.9 |
| shape | sh:node, sh:property, sh:qualifiedValueShape | 4.10 |
| other | sh:closed, sh:ignoredProperties, sh:hasValue, sh:in | 4.11-4.12 |

## Implementation Status

- [x] Phase 1: Skeleton + basic constraints (types, parse, target, engine, value-type, cardinality, report, API, CLI)
- [ ] Phase 2: Remaining simple constraints (value-range, string, other, remaining targets)
- [ ] Phase 3: Complex constraints + paths (inverse/sequence/alternative, pair, logical, shape, cycle detection)
- [ ] Phase 4: Advanced paths + polish (zero-or-more/one-or-more, regex, RDF report, full tests)

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

Exit codes: 0 = conforms, 1 = violations, 2 = parse/internal error.

## Useful SLOP Commands

- `slop ref <module> <function>` — Look up function signatures and documentation from the SLOP stdlib. Use this to verify that a function exists and check its parameters before using it.
- `slop doc <module>` — Browse documentation for an entire SLOP stdlib module. Useful for discovering available functions in modules like `strlib`, `core`, etc.

## Conventions

- All public functions use `:c-name "snarl_*"` for stable C FFI
- Full contracts on all functions: `@intent`, `@spec`, `@pre`, `@post`, `@property`, `@example`, `@alloc`
- Arena-based allocation — no manual memory management
- Single-threaded, single-pass validation (no fixpoint)
- Recursive shape evaluation with cycle detection via visited set
- Use `string-build` (from `strlib`) for joining lists of strings; use `string-concat` for binary concatenation
- `parse-int` is in the `strlib` module
