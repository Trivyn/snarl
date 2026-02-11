#!/usr/bin/env bash
# Download W3C SHACL Core test suite TTL files.
# Usage: bash download.sh

set -euo pipefail

BASE_URL="https://raw.githubusercontent.com/w3c/data-shapes/gh-pages/data-shapes-test-suite/tests/core"
DIR="$(cd "$(dirname "$0")" && pwd)"

download_files() {
  local category="$1"
  shift
  local dest="$DIR/$category"
  mkdir -p "$dest"
  for file in "$@"; do
    local url="$BASE_URL/$category/$file"
    local out="$dest/$file"
    if [ -f "$out" ]; then
      echo "  [skip] $category/$file"
    else
      echo "  [get]  $category/$file"
      curl -sSfL "$url" -o "$out" || echo "  [FAIL] $category/$file"
    fi
  done
}

echo "Downloading W3C SHACL Core test files..."

# --- property/ (43 files) ---
download_files property \
  and-001.ttl \
  class-001.ttl \
  datatype-001.ttl \
  datatype-002.ttl \
  datatype-003.ttl \
  datatype-ill-formed.ttl \
  datatype-ill-formed-data.ttl \
  datatype-ill-formed-shapes.ttl \
  disjoint-001.ttl \
  equals-001.ttl \
  hasValue-001.ttl \
  in-001.ttl \
  languageIn-001.ttl \
  lessThan-001.ttl \
  lessThan-002.ttl \
  lessThanOrEquals-001.ttl \
  maxCount-001.ttl \
  maxCount-002.ttl \
  maxExclusive-001.ttl \
  maxInclusive-001.ttl \
  maxLength-001.ttl \
  minCount-001.ttl \
  minCount-002.ttl \
  minExclusive-001.ttl \
  minExclusive-002.ttl \
  minLength-001.ttl \
  node-001.ttl \
  node-002.ttl \
  nodeKind-001.ttl \
  not-001.ttl \
  or-001.ttl \
  or-datatypes-001.ttl \
  pattern-001.ttl \
  pattern-002.ttl \
  property-001.ttl \
  qualifiedMinCountDisjoint-001.ttl \
  qualifiedValueShape-001.ttl \
  qualifiedValueShapesDisjoint-001.ttl \
  uniqueLang-001.ttl \
  uniqueLang-002.ttl \
  uniqueLang-002-data.ttl \
  uniqueLang-002-shapes.ttl

# --- node/ (37 files) ---
download_files node \
  and-001.ttl \
  and-002.ttl \
  class-001.ttl \
  class-002.ttl \
  class-003.ttl \
  closed-001.ttl \
  closed-002.ttl \
  datatype-001.ttl \
  datatype-002.ttl \
  disjoint-001.ttl \
  equals-001.ttl \
  hasValue-001.ttl \
  in-001.ttl \
  languageIn-001.ttl \
  maxExclusive-001.ttl \
  maxInclusive-001.ttl \
  maxLength-001.ttl \
  minExclusive-001.ttl \
  minInclusive-001.ttl \
  minInclusive-002.ttl \
  minInclusive-003.ttl \
  minLength-001.ttl \
  node-001.ttl \
  nodeKind-001.ttl \
  not-001.ttl \
  not-002.ttl \
  or-001.ttl \
  pattern-001.ttl \
  pattern-002.ttl \
  qualified-001.ttl \
  qualified-001-data.ttl \
  qualified-001-shapes.ttl \
  xone-001.ttl \
  xone-duplicate.ttl \
  xone-duplicate-data.ttl \
  xone-duplicate-shapes.ttl

# --- targets/ (7 files) ---
download_files targets \
  multipleTargets-001.ttl \
  targetClass-001.ttl \
  targetClassImplicit-001.ttl \
  targetNode-001.ttl \
  targetObjectsOf-001.ttl \
  targetSubjectsOf-001.ttl \
  targetSubjectsOf-002.ttl

# --- path/ (18 files) ---
download_files path \
  path-alternative-001.ttl \
  path-complex-001.ttl \
  path-complex-002.ttl \
  path-complex-002-data.ttl \
  path-complex-002-shapes.ttl \
  path-inverse-001.ttl \
  path-oneOrMore-001.ttl \
  path-sequence-001.ttl \
  path-sequence-002.ttl \
  path-sequence-duplicate-001.ttl \
  path-strange-001.ttl \
  path-strange-002.ttl \
  path-unused-001.ttl \
  path-unused-001-data.ttl \
  path-unused-001-shapes.ttl \
  path-zeroOrMore-001.ttl \
  path-zeroOrOne-001.ttl

# --- misc/ (5 files) ---
download_files misc \
  deactivated-001.ttl \
  deactivated-002.ttl \
  message-001.ttl \
  severity-001.ttl \
  severity-002.ttl

# --- complex/ (4 files) ---
download_files complex \
  personexample.ttl \
  shacl-shacl.ttl \
  shacl-shacl-data-shapes.ttl

# --- validation-reports/ (3 files) ---
download_files validation-reports \
  shared.ttl \
  shared-data.ttl \
  shared-shapes.ttl

echo "Done."
