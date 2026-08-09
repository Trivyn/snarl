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

### Regenerating `csrc/` (SLOP toolchain)

`csrc/` is **generated — never hand-edit it.** A bug visible in the generated C
is usually a bug in the SLOP transpiler, and belongs there.

```bash
cd $SLOP_HOME && make build-native     # REQUIRED FIRST after any SLOP change
export SLOP_HOME=/Users/jcadam/code/slop
make csrc
```

Three things that are easy to get wrong:

- `make csrc` requires `SLOP_HOME` and invokes **`$SLOP_HOME/bin/slop-compiler`
  directly, not the one on `PATH`** (a second copy often exists at
  `/opt/homebrew/bin/slop-compiler`). Editing SLOP source without
  `make build-native` regenerates byte-identical C and looks like the change
  had no effect.
- `csrc/update_bootstrap.sh` enforces `SLOP_MIN_VERSION` and refuses to run
  against an older toolchain. Raise it whenever a SLOP codegen fix is
  load-bearing for the committed C. Minimum today: **0.1.2** (map-put value
  width — see the note in that script).
- `csrc/SLOP_VERSION` records which toolchain produced the current C. Commit it
  with the regenerated sources.

W3C conformance cases are gitignored, so a fresh checkout has none — run
`bash cli/tests/w3c/download.sh` before `make w3c-test`.

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

<!-- moosedev:begin — MOOSEDev project-memory workflow. Managed by `moosedev init`; edit around this block freely, or delete the whole begin…end block to opt out. -->
> This project uses the **MOOSEDev** MCP server for durable, structured, long-term memory.
> The typed **project knowledge graph is the source of truth** for architectural decisions,
> lessons, constraints, requirements, and patterns — **not** markdown files. Free-text notes
> (e.g. `tasks/lessons.md`, `tasks/todo.md`) are optional human-readable mirrors, never canonical.

## Working with project memory (MOOSEDev)

When the `moosedev` MCP tools are available, prefer them over re-deriving context from scratch.
The loop:

1. **Recall first.** Before non-trivial work, surface prior decisions/lessons/constraints from
   the graph — and show the queries you ran. "Recall first" means a **list-all**
   `get_relevant_context` (no `topic`), not only a topic probe: a topic-scoped empty result
   means nothing cleared the relevance floor, **not** that the graph is empty.
2. **Capture as typed records.** Record durable knowledge as you go with
   `record_important_decision` (pick the right `kind`). Capture the decision **and its
   rationale** (and the rejected alternative), not transient chatter. Always report what was
   written (kind / title / returned IRI) — no silent writes.
3. **Align before coining.** Run `align_concepts` (or `suggest_mappings`) before introducing a
   new term, so the graph doesn't drift.
4. **Correct, don't duplicate.** `supersede_decision` when there is a replacement;
   `retract_decision` to deprecate one without a successor. Never silently duplicate — recall
   (list-all) first to confirm a record is genuinely new.
5. **Validate.** Run `validate_against_architecture` after capturing; resolve violations.

### Tool-selection ladder (cheap → precise)
- `get_relevant_context` — fast, deterministic, **shallow** lexical anchor/browse. Start here.
- `query` — walk-planned, synthesized natural-language answer **with a reasoning trace**. Use
  when you need reasoning over relationships, not just a label match. Keep questions short and
  focused (one question per call).
- `sparql` — exact, deterministic structural reads of the graph. Use for precise listings.

### Capture kinds
`ArchitecturalDecision` (the default — a choice + why + what was rejected) ·
`Constraint` (a hard limit/invariant) · `Requirement` (a goal/need) ·
`Pattern` (a deliberate recurring approach) · `AntiPattern` (something to avoid, + why) ·
`Lesson` (a non-obvious learning/gotcha).
<!-- moosedev:end -->
