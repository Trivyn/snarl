# snarl

Safe Rust bindings for the Snarl SHACL Core validator.

Snarl validates an RDF data graph against a SHACL shapes graph and returns a
validation report with conformance status and result details. This crate bundles
the C validator sources and compiles them during the Cargo build.

## Installation

```toml
[dependencies]
snarl = "0.1.0"
```

## Requirements

- Rust 2021 toolchain
- A C compiler available to Cargo

The crate uses the `cc` build dependency to compile the bundled C sources under
`csrc/`. No SLOP toolchain is required when building the crate.

## Quick Start

The high-level `Validator` API owns the arena and graph storage and returns
owned validation results.

```rust
use snarl::{OwnedValidatorResult, Validator};

const RDF_TYPE: &str = "http://www.w3.org/1999/02/22-rdf-syntax-ns#type";
const SH_NODE_SHAPE: &str = "http://www.w3.org/ns/shacl#NodeShape";
const SH_TARGET_CLASS: &str = "http://www.w3.org/ns/shacl#targetClass";
const EX_PERSON: &str = "http://example.org/Person";
const EX_PERSON_SHAPE: &str = "http://example.org/PersonShape";
const EX_ALICE: &str = "http://example.org/alice";

let mut validator = Validator::new();

validator.add_data_iri_triple(EX_ALICE, RDF_TYPE, EX_PERSON);

validator.add_shapes_iri_triple(EX_PERSON_SHAPE, RDF_TYPE, SH_NODE_SHAPE);
validator.add_shapes_iri_triple(EX_PERSON_SHAPE, SH_TARGET_CLASS, EX_PERSON);

match validator.validate() {
    OwnedValidatorResult::Success(report) => {
        println!("conforms: {}", report.conforms);
        println!("results: {}", report.results.len());
    }
    OwnedValidatorResult::Error(message) => {
        eprintln!("validation error: {message}");
    }
}
```

Use `Validator::conforms()` when you only need a boolean conformance check.

## Lower-Level API

For explicit arena and graph control, use `Arena` and `IndexedGraph` directly:

```rust
use snarl::{validate, Arena, IndexedGraph, ValidatorResult};

let arena = Arena::with_default_capacity();
let data = IndexedGraph::new(&arena);
let shapes = IndexedGraph::new(&arena);

match validate(&arena, &data, &shapes) {
    ValidatorResult::Success(report) => {
        assert!(report.conforms);
    }
    ValidatorResult::Error(message) => {
        eprintln!("validation error: {message}");
    }
}
```

Values returned from this lower-level API borrow from the arena. Convert reports
or terms into the corresponding owned types when data must outlive the arena.

## Validation Results

Validation produces either:

- `OwnedValidatorResult::Success(OwnedValidationReport)` or
  `ValidatorResult::Success(ValidationReport)` with `conforms` and `results`.
- `OwnedValidatorResult::Error(String)` or `ValidatorResult::Error(String)` if
  validation fails internally.

Each validation result includes the focus node, optional result path, optional
value, source shape, source constraint component, severity, and optional message.
Severity values are `Violation`, `Warning`, and `Info`.

## Testing

```bash
cd rust
cargo test
```

## License

Apache-2.0
