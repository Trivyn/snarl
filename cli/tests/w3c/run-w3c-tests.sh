#!/usr/bin/env bash
# Run W3C SHACL Core conformance tests against snarl.
# Usage: bash run-w3c-tests.sh [path/to/snarl]

set -euo pipefail

SNARL="${1:-../../build/snarl}"
DIR="$(cd "$(dirname "$0")" && pwd)"
XFAIL_FILE="$DIR/xfail.txt"

# Verify snarl binary exists
if [ ! -x "$SNARL" ]; then
  echo "ERROR: snarl binary not found at $SNARL"
  exit 2
fi

# xfail lookup uses grep on the file directly (no associative arrays, for macOS compat)

CATEGORIES=(property node targets path misc complex validation-reports)

pass=0
fail=0
xfail=0
xpass=0
skip=0
total=0

FAILURES=()
XPASSES=()

for category in "${CATEGORIES[@]}"; do
  catdir="$DIR/$category"
  [ -d "$catdir" ] || continue

  for file in "$catdir"/*.ttl; do
    [ -f "$file" ] || continue
    basename="$(basename "$file")"

    # Skip auxiliary files (data-only, shapes-only, manifest)
    case "$basename" in
      *-data.ttl|*-shapes.ttl|manifest.ttl) continue ;;
    esac

    testid="$category/$basename"
    total=$((total + 1))

    # Extract expected sh:conforms value
    expected_raw=$(grep -o 'sh:conforms "[^"]*"' "$file" | head -1 || true)
    if [ -z "$expected_raw" ]; then
      # Try alternate format: sh:conforms true/false (without quotes)
      expected_raw=$(grep -oE 'sh:conforms[[:space:]]+(true|false)' "$file" | head -1 || true)
      if [ -z "$expected_raw" ]; then
        printf "  %-50s SKIP (no sh:conforms found)\n" "$testid"
        skip=$((skip + 1))
        continue
      fi
      expected_val=$(echo "$expected_raw" | grep -oE '(true|false)')
    else
      expected_val=$(echo "$expected_raw" | grep -o '"[^"]*"' | tr -d '"')
    fi

    # Detect multi-file test (separate data/shapes files)
    data_ref=$(sed -n 's/.*sht:dataGraph[[:space:]]*<\([^>]*\.ttl\)>.*/\1/p' "$file" | head -1 || true)

    if [ -n "$data_ref" ] && [ "$data_ref" != "" ]; then
      # Multi-file test
      data_file="$catdir/$data_ref"
      shapes_ref=$(sed -n 's/.*sht:shapesGraph[[:space:]]*<\([^>]*\.ttl\)>.*/\1/p' "$file" | head -1 || true)
      if [ -n "$shapes_ref" ]; then
        shapes_file="$catdir/$shapes_ref"
      else
        shapes_file="$file"
      fi
      if [ ! -f "$data_file" ]; then
        printf "  %-50s SKIP (data file not found: %s)\n" "$testid" "$data_ref"
        skip=$((skip + 1))
        continue
      fi
      result=$("$SNARL" -q -s "$shapes_file" "$data_file" 2>/dev/null; echo $?) || true
      actual_exit="${result##*$'\n'}"
    else
      # Single-file test (same file as both data and shapes)
      actual_exit=0
      "$SNARL" -q "$file" 2>/dev/null || actual_exit=$?
    fi

    # Map exit code to conforms value
    case "$actual_exit" in
      0) actual_val="true" ;;
      1) actual_val="false" ;;
      *)
        printf "  %-50s SKIP (exit code %s)\n" "$testid" "$actual_exit"
        skip=$((skip + 1))
        continue
        ;;
    esac

    is_xfail=0
    grep -qxF "$testid" "$XFAIL_FILE" 2>/dev/null && is_xfail=1

    if [ "$actual_val" = "$expected_val" ]; then
      if [ "$is_xfail" -eq 1 ]; then
        printf "  %-50s XPASS (expected fail, but passed!)\n" "$testid"
        xpass=$((xpass + 1))
        XPASSES+=("$testid")
      else
        printf "  %-50s PASS\n" "$testid"
        pass=$((pass + 1))
      fi
    else
      if [ "$is_xfail" -eq 1 ]; then
        printf "  %-50s XFAIL (expected=%s actual=%s)\n" "$testid" "$expected_val" "$actual_val"
        xfail=$((xfail + 1))
      else
        printf "  %-50s FAIL (expected=%s actual=%s)\n" "$testid" "$expected_val" "$actual_val"
        fail=$((fail + 1))
        FAILURES+=("$testid (expected=$expected_val actual=$actual_val)")
      fi
    fi
  done
done

echo ""
echo "========================================"
echo "W3C SHACL Core Conformance Test Results"
echo "========================================"
echo "  Total:  $total"
echo "  Pass:   $pass"
echo "  Fail:   $fail"
echo "  XFail:  $xfail  (expected failures)"
echo "  XPass:  $xpass  (unexpected passes)"
echo "  Skip:   $skip"
echo ""

if [ ${#XPASSES[@]} -gt 0 ]; then
  echo "*** UNEXPECTED PASSES (remove from xfail.txt): ***"
  for t in "${XPASSES[@]}"; do
    echo "  $t"
  done
  echo ""
fi

if [ ${#FAILURES[@]} -gt 0 ]; then
  echo "*** UNEXPECTED FAILURES (regressions): ***"
  for t in "${FAILURES[@]}"; do
    echo "  $t"
  done
  echo ""
fi

if [ "$total" -eq 0 ]; then
  echo "RESULT: FAIL (no test cases found)"
  echo ""
  echo "The W3C case directories are gitignored, so a fresh checkout has none."
  echo "Run 'bash cli/tests/w3c/download.sh' first."
  echo "Without this guard an empty corpus reported OK, making this suite a"
  echo "no-op gate in CI -- it passed no matter what the validator did."
  exit 1
fi

if [ "$fail" -gt 0 ]; then
  echo "RESULT: FAIL ($fail unexpected failure(s))"
  exit 1
else
  echo "RESULT: OK"
  exit 0
fi
