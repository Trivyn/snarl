#!/usr/bin/env bash
# Download the W3C SHACL 1.2 test cases that snarl's experimental --shacl12
# mode is checked against: inference rules, and the shnex: node expression
# and sh:expression constraint cases. The downloaded files are gitignored.
# Usage: bash download.sh

set -euo pipefail

BASE_URL="https://raw.githubusercontent.com/w3c/data-shapes/gh-pages/shacl12-test-suite/tests"
DIR="$(cd "$(dirname "$0")" && pwd)"

# Fetch a directory's manifest, then every .ttl file it names.
download_dir() {
  local sub="$1"
  local dest="$DIR/$sub"
  mkdir -p "$dest"
  curl -sSfL "$BASE_URL/$sub/manifest.ttl" -o "$dest/manifest.ttl"
  for file in $(grep -oE '<[A-Za-z0-9_-]+\.ttl>' "$dest/manifest.ttl" | tr -d '<>' | sort -u); do
    if [ -f "$dest/$file" ]; then
      echo "  [skip] $sub/$file"
    else
      echo "  [get]  $sub/$file"
      curl -sSfL "$BASE_URL/$sub/$file" -o "$dest/$file" || echo "  [FAIL] $sub/$file"
    fi
  done
}

echo "Downloading W3C SHACL 1.2 test files..."
download_dir inference-rules
download_dir node-expr/shnex
download_dir node-expr/constraints
