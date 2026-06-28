#!/usr/bin/env python3
"""SHACL validator comparison: pySHACL (ground truth) vs Rudof vs Snarl.

pySHACL is the Python reference SHACL implementation.
Rudof is a fast Rust-based SHACL validator.
Snarl is our SLOP-based SHACL Core validator.

Usage: cd cli/tests && python benchmark_compare.py
       cd cli/tests && python benchmark_compare.py --generate
       cd cli/tests && python benchmark_compare.py --only snarl
  Requires: pip install pyshacl  (for pySHACL)
  Requires: cargo install rudof  (for Rudof)
  Requires: snarl CLI built at ../../build/snarl
"""

import argparse
import os
import random
import re
import shutil
import subprocess
import sys
import time
from statistics import median

SNARL = "../../build/snarl"
BENCHMARKS_DIR = "fixtures/benchmarks"

FIXTURES = [
    ("employee-dir", "fixtures/employee-dir-data.ttl", "fixtures/employee-dir-shapes.ttl", 25),
    ("library", "fixtures/library-data.ttl", "fixtures/library-shapes.ttl", 18),
    ("product-catalog", "fixtures/product-catalog-data.ttl", "fixtures/product-catalog-shapes.ttl", 18),
    ("address-book", "fixtures/address-book-data.ttl", "fixtures/address-book-shapes.ttl", 14),
    ("multi-shape", "fixtures/multi-shape-data.ttl", "fixtures/multi-shape-shapes.ttl", 11),
    ("employees-1k", f"{BENCHMARKS_DIR}/employees-1k-data.ttl", f"{BENCHMARKS_DIR}/employees-1k-shapes.ttl", 4955),
    ("employees-10k", f"{BENCHMARKS_DIR}/employees-10k-data.ttl", f"{BENCHMARKS_DIR}/employees-10k-shapes.ttl", 49493),
    ("employees-100k", f"{BENCHMARKS_DIR}/employees-100k-data.ttl", f"{BENCHMARKS_DIR}/employees-100k-shapes.ttl", 494962),
    ("meteorites", "../../test_data/large_meteorite_data.ttl", "../../test_data/meteorite_shapes.ttl", 1010109),
]

RUNS = 5
TIMEOUT = 60  # Per-run timeout in seconds


def run_with_timeout(cmd):
    """Run a command with timeout. Returns (subprocess.CompletedProcess, elapsed) or None on timeout."""
    t0 = time.perf_counter()
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=TIMEOUT)
    except subprocess.TimeoutExpired:
        return None, time.perf_counter() - t0
    return result, time.perf_counter() - t0


def run_snarl(data, shapes):
    """Run snarl on data+shapes. Returns (conforms, result_count, median_time_s)."""
    cmd = [SNARL, "-q", data, "-s", shapes]
    times = []
    conforms = None
    result_count = None

    for _ in range(RUNS):
        result, elapsed = run_with_timeout(cmd)
        if result is None:
            return None, None, None
        times.append(elapsed)

        out = result.stdout.strip()
        if result.returncode == 0:
            conforms = True
            result_count = 0
        elif result.returncode == 1:
            conforms = False
            m = re.search(r"(\d+)\s+result", out)
            result_count = int(m.group(1)) if m else -1
        else:
            return None, None, None

    return conforms, result_count, median(times)


def run_pyshacl(data, shapes):
    """Run pySHACL on data+shapes. Returns (conforms, result_count, median_time_s)."""
    cmd = ["pyshacl", "-s", shapes, data]
    times = []
    conforms = None
    result_count = None

    for _ in range(RUNS):
        result, elapsed = run_with_timeout(cmd)
        if result is None:
            return None, None, None
        times.append(elapsed)

        out = result.stdout + result.stderr
        if result.returncode == 0:
            conforms = True
            result_count = 0
        else:
            conforms = False
            m = re.search(r"Results\s*\((\d+)\)", out)
            if m:
                result_count = int(m.group(1))
            else:
                violations = out.count("Constraint Violation") + out.count("Constraint Report")
                result_count = len(re.findall(r"Validation Result in", out))
                if result_count == 0:
                    result_count = violations if violations > 0 else -1

    return conforms, result_count, median(times)


def run_rudof(data, shapes):
    """Run rudof on data+shapes. Returns (conforms, result_count, median_time_s)."""
    cmd = ["rudof", "shacl-validate", "-r", "minimal", "-s", shapes, data]
    times = []
    conforms = None
    result_count = None

    for _ in range(RUNS):
        result, elapsed = run_with_timeout(cmd)
        if result is None:
            return None, None, None
        times.append(elapsed)

        out = result.stdout + result.stderr
        if "Conforms" in out:
            conforms = True
            result_count = 0
        else:
            conforms = False
            m = re.search(r"Does not conform,\s*(\d+)\s+violations", out)
            result_count = int(m.group(1)) if m else -1

    return conforms, result_count, median(times)


def fmt_time(t):
    """Format time in human-readable form."""
    if t is None:
        return "-"
    if t >= 1.0:
        return f"{t:.2f}s"
    return f"{t*1000:.0f}ms"


def fmt_count(n):
    """Format a result count."""
    if n is None:
        return "-"
    if n == 0:
        return "conforms"
    return str(n)


def count_triples(path):
    """Count approximate triples in a TTL file (non-blank, non-prefix lines)."""
    count = 0
    try:
        with open(path) as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith("@prefix") and not line.startswith("#"):
                    # Count semicolons and periods as triple terminators
                    count += line.count(";") + line.count(".")
    except FileNotFoundError:
        return 0
    return count


def generate_benchmark(n, out_dir):
    """Generate N employee records with ~20% violations.

    Uses the employee-dir shapes pattern:
    - ~80% fully valid
    - ~5% missing required name (minCount violation)
    - ~5% underage (minInclusive violation)
    - ~5% bad email pattern (pattern violation)
    - ~5% literal department (nodeKind violation)
    """
    random.seed(42)  # Reproducible output

    first_names = ["Alice", "Bob", "Carol", "Dave", "Eve", "Frank", "Grace",
                   "Heidi", "Ivan", "Judy", "Karl", "Laura", "Mike", "Nina",
                   "Oscar", "Pam", "Quinn", "Ruth", "Steve", "Tina"]
    last_names = ["Smith", "Jones", "Brown", "White", "Black", "Green",
                  "Clark", "Lewis", "Hall", "Young", "King", "Wright",
                  "Adams", "Baker", "Davis", "Evans", "Moore", "Taylor"]
    departments = ["engineering", "marketing", "sales", "hr", "finance",
                   "legal", "ops", "research", "support", "design"]

    os.makedirs(out_dir, exist_ok=True)

    data_path = os.path.join(out_dir, f"employees-{n // 1000}k-data.ttl")
    shapes_path = os.path.join(out_dir, f"employees-{n // 1000}k-shapes.ttl")

    # Copy shapes from employee-dir
    shutil.copy("fixtures/employee-dir-shapes.ttl", shapes_path)

    violations = 0
    with open(data_path, "w") as f:
        f.write("@prefix ex: <http://example.org/> .\n")
        f.write("@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n\n")

        # Departments
        for dept in departments:
            f.write(f"ex:{dept} a ex:Department .\n")
        f.write("\n")

        for i in range(n):
            emp_id = f"emp{i:05d}"
            first = random.choice(first_names)
            last = random.choice(last_names)
            age = random.randint(18, 65)
            dept = random.choice(departments)
            email = f"{first.lower()}.{last.lower()}.{i}@example.com"

            r = random.random()

            f.write(f"ex:{emp_id} a ex:Employee ;\n")

            if r < 0.05:
                # Missing name (minCount violation)
                violations += 1
            else:
                f.write(f'    ex:name "{first} {last}" ;\n')

            if 0.05 <= r < 0.10:
                # Underage (minInclusive violation)
                age = random.randint(10, 17)
                violations += 1

            f.write(f'    ex:age "{age}"^^xsd:integer ;\n')

            if 0.10 <= r < 0.15:
                # Bad email (pattern violation)
                email = f"{first.lower()}-no-at-sign"
                violations += 1

            f.write(f'    ex:email "{email}" ;\n')

            if 0.15 <= r < 0.20:
                # Literal department (nodeKind + class violation = 2 violations)
                f.write(f'    ex:department "{dept}" .\n\n')
                violations += 2
            else:
                f.write(f"    ex:department ex:{dept} .\n\n")

    print(f"  Generated {data_path}: {n} employees, ~{violations} expected violations")
    return data_path, shapes_path


def compare_mode(fixtures, only=None):
    """Run comparison benchmark across all fixtures."""
    validators = {}
    install_hints = {
        "snarl": "Build it: make cli (from project root)",
        "pyshacl": "Install it: pip install pyshacl",
        "rudof": "Install it: cargo install rudof_cli",
    }

    # Check availability
    if only is None or "snarl" in only:
        if os.path.exists(SNARL):
            validators["snarl"] = run_snarl
        else:
            print(f"  [skip] snarl not found. {install_hints['snarl']}")

    if only is None or "pyshacl" in only:
        if shutil.which("pyshacl"):
            validators["pyshacl"] = run_pyshacl
        else:
            print(f"  [skip] pySHACL not found. {install_hints['pyshacl']}")

    if only is None or "rudof" in only:
        if shutil.which("rudof"):
            validators["rudof"] = run_rudof
        else:
            print(f"  [skip] rudof not found. {install_hints['rudof']}")

    if not validators:
        print("Error: no validators available.")
        sys.exit(1)

    # Determine reference validator
    ref_name = "pyshacl" if "pyshacl" in validators else list(validators.keys())[0]

    header_parts = []
    if "pyshacl" in validators:
        header_parts.append("pySHACL (ref)")
    if "rudof" in validators:
        header_parts.append("Rudof")
    if "snarl" in validators:
        header_parts.append("Snarl")
    header = " vs ".join(header_parts)

    print()
    print("=" * 72)
    print(f"  SHACL Validator Comparison: {header}")
    print("=" * 72)

    for fixture in fixtures:
        name, data, shapes = fixture[:3]
        triple_count = fixture[3] if len(fixture) > 3 else None
        if not os.path.exists(data) or not os.path.exists(shapes):
            print(f"\n--- {name} --- SKIPPED (files not found)")
            continue

        triples = triple_count if triple_count is not None else count_triples(data)
        print(f"\n--- {name} ({triples} triples) ---")

        results = {}

        for vname, vfunc in validators.items():
            label = f"{vname} (ref)" if vname == ref_name else vname
            print(f"  Running {label}...", end="", flush=True)
            conforms, count, t = vfunc(data, shapes)
            if conforms is None:
                print(f" TIMEOUT (>{TIMEOUT}s)")
                results[vname] = (None, None, None)
            else:
                print(f" done ({fmt_time(t)})")
                results[vname] = (conforms, count, t)

        # Summary table
        print()
        print(f"  {'':20s} {'Results':>10s}  {'Time':>8s}")
        print(f"  {'':20s} {'-------':>10s}  {'------':>8s}")

        ref_count = results.get(ref_name, (None, None, None))[1]

        for vname in validators:
            conforms, count, t = results[vname]
            label = f"{vname} (ref)" if vname == ref_name else vname

            count_str = fmt_count(count)
            time_str = fmt_time(t)

            # Correctness indicator
            if ref_count is not None and count is not None and vname != ref_name:
                if count != ref_count:
                    count_str += f" (!={ref_count})"

            print(f"  {label:20s} {count_str:>10s}  {time_str:>8s}")

        # Speedup summary
        if "snarl" in results and results["snarl"][2] is not None:
            snarl_t = results["snarl"][2]
            for vname in validators:
                if vname == "snarl":
                    continue
                _, _, vt = results[vname]
                if vt is not None and snarl_t > 0:
                    speedup = vt / snarl_t
                    if speedup >= 1.5:
                        print(f"  Snarl is {speedup:.1f}x faster than {vname}")


def main():
    parser = argparse.ArgumentParser(
        description="SHACL validator comparison: pySHACL vs Rudof vs Snarl"
    )
    parser.add_argument("--generate", action="store_true",
                        help="Generate benchmark fixtures at 1k and 10k scales")
    parser.add_argument("--only", type=str, default=None,
                        help="Comma-separated list of validators to run (snarl,pyshacl,rudof)")
    args = parser.parse_args()

    if args.generate:
        print("Generating benchmark fixtures...")
        generate_benchmark(1000, BENCHMARKS_DIR)
        generate_benchmark(10000, BENCHMARKS_DIR)
        generate_benchmark(100000, BENCHMARKS_DIR)
        print("Done.")
        return

    only = None
    if args.only:
        only = [v.strip().lower() for v in args.only.split(",")]

    compare_mode(FIXTURES, only=only)


if __name__ == "__main__":
    main()
