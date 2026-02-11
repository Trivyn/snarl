# Snarl

A SHACL Core validator written in [SLOP](https://github.com/jcadam/slop).

Validates an RDF data graph against a SHACL shapes graph, producing a W3C-conformant validation report. Implements SHACL Core constraints only (no SHACL-SPARQL).

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
make test     # Run tests
make release  # Optimized build
```

## Library Usage

Snarl provides a C-compatible static library (`libsnarl.a`) with a stable header (`include/snarl.h`).

```c
#include "snarl.h"
#include "slop_runtime.h"

// Create arena, parse your TTL files into IndexedGraphs, then:
SnarlValidatorResult result = snarl_validate(arena, data_graph, shapes_graph);
```

## License

Apache 2.0
