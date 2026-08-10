#!/bin/bash
# Regenerate transpiled C source in csrc/ from SLOP source.
# Requires: SLOP toolchain (slop-compiler + slop Python package)
#
# Usage: ./csrc/update_bootstrap.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

# Minimum SLOP toolchain version. Raise this whenever a SLOP codegen fix is
# load-bearing for the generated C committed here, so a stale toolchain fails
# loudly instead of silently regenerating C with the bug still in it.
#
# 0.1.2: map-put declares its value with the map's DECLARED value type. Before
# it, `(map-put m k <int expr>)` on a (Map K Int) sized the arena slot with
# sizeof(C int) = 4 while every map-get read *(int64_t*) = 8, so the upper half
# of every stored Int was uninitialised arena memory. That corrupted the path
# depth memo (spurious "Path nesting depth budget exceeded" on flat paths) and
# the CycleGuard reference counts (spurious "Shape recursion detected").
SLOP_MIN_VERSION="0.1.2"

version_lt() {
    # true when $1 < $2, comparing dot-separated numeric components
    [ "$1" = "$2" ] && return 1
    [ "$(printf '%s\n%s\n' "$1" "$2" | sort -t. -k1,1n -k2,2n -k3,3n | head -1)" = "$1" ]
}

SLOP_VERSION_FILE="${SLOP_HOME}/VERSION"
if [ ! -f "$SLOP_VERSION_FILE" ]; then
    echo "Error: SLOP VERSION file not found at $SLOP_VERSION_FILE"
    echo "       Is SLOP_HOME set correctly? (currently: ${SLOP_HOME:-unset})"
    exit 1
fi
SLOP_VERSION="$(tr -d '[:space:]' < "$SLOP_VERSION_FILE")"
if version_lt "$SLOP_VERSION" "$SLOP_MIN_VERSION"; then
    echo "Error: SLOP toolchain $SLOP_VERSION is older than the required $SLOP_MIN_VERSION."
    echo "       Regenerating with it would reintroduce a fixed codegen bug."
    echo "       Update $SLOP_HOME and run 'make build-native' there first."
    exit 1
fi

# generate_c.py invokes $SLOP_HOME/bin/slop-compiler directly (NOT the one on
# PATH), so a source change in the SLOP repo only takes effect here after
# `make build-native` has been run there.
SLOP_COMPILER="${SLOP_HOME}/bin/slop-compiler"
if [ ! -x "$SLOP_COMPILER" ]; then
    echo "Error: slop-compiler not found at $SLOP_COMPILER"
    echo "       Run 'make build-native' in $SLOP_HOME first."
    exit 1
fi

echo "Generating transpiled C source (SLOP $SLOP_VERSION)..."
echo ""

# 1. Transpile CLI (main entry point + all shared deps)
echo "Pass 1: CLI (main + all dependencies)"
python3 "$SCRIPT_DIR/generate_c.py" "$PROJECT_ROOT/cli" "$SCRIPT_DIR/src"
echo ""

# 2. Transpile tests in append mode (only adds test entry point)
echo "Pass 2: Tests (append mode — adds test entry only)"
python3 "$SCRIPT_DIR/generate_c.py" --append "$PROJECT_ROOT/cli/tests" "$SCRIPT_DIR/src"
echo ""

# 3. Copy runtime header
echo "Copying runtime header..."
mkdir -p "$SCRIPT_DIR/runtime"
SLOP_RUNTIME="${SLOP_HOME}/src/slop/runtime/slop_runtime.h"
if [ ! -f "$SLOP_RUNTIME" ]; then
    echo "Error: Runtime header not found at $SLOP_RUNTIME"
    echo "       Is SLOP_HOME set correctly? (currently: ${SLOP_HOME:-unset})"
    exit 1
fi
cp "$SLOP_RUNTIME" "$SCRIPT_DIR/runtime/"
echo "  Copied $SLOP_RUNTIME -> $SCRIPT_DIR/runtime/"

# 4. Record which toolchain produced this C, so it is answerable from the repo
#    alone. Commit this alongside the regenerated sources.
SLOP_COMMIT="$(git -C "$SLOP_HOME" rev-parse --short HEAD 2>/dev/null || echo unknown)"
printf '%s %s\n' "$SLOP_VERSION" "$SLOP_COMMIT" > "$SCRIPT_DIR/SLOP_VERSION"
echo "  Recorded toolchain provenance: $SLOP_VERSION $SLOP_COMMIT"

echo ""
echo "Done. Files in $SCRIPT_DIR/src/:"
ls "$SCRIPT_DIR/src/"*.c 2>/dev/null | wc -l | tr -d ' '
echo " .c files"
ls "$SCRIPT_DIR/src/"*.h 2>/dev/null | wc -l | tr -d ' '
echo " .h files"
