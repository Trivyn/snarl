use std::env;
use std::path::Path;

fn main() {
    let csrc = Path::new("csrc/src");
    let runtime = Path::new("csrc/runtime");
    // The vendored sh:pattern regex engine (vendor/regex, copied in by
    // `make crate-vendor`), so no platform needs a system <regex.h>.
    let regex = Path::new("csrc/regex");
    let regex_sources = ["regcomp.c", "regexec.c", "tre-mem.c", "snarl_regex.c"];

    // Shared rdf/std headers + symbols now come from the -sys crates.
    let rdf_inc = env::var("DEP_SLOP_RDF_INCLUDE").expect("slop-rdf-sys must be a dependency");
    let std_inc = env::var("DEP_SLOP_STD_INCLUDE").expect("slop-std-sys must be a dependency");

    // Only snarl's own modules; shared modules come from libslop_rdf.a / libslop_std.a.
    let sources = [
        "slop_cardinality.c", "slop_data_graph.c", "slop_engine.c", "slop_logical.c",
        "slop_other.c", "slop_pair.c", "slop_parse.c", "slop_path.c", "slop_report.c",
        "slop_shape.c", "slop_snarl.c", "slop_string.c", "slop_target.c", "slop_types.c",
        "slop_value_range.c", "slop_value_type.c",
    ];

    let mut build = cc::Build::new();
    // The generated C uses GNU statement expressions and __auto_type, which
    // MSVC's cl.exe rejects; clang-cl accepts them. CC still overrides this.
    build
        .prefer_clang_cl_over_msvc(true)
        .include(runtime)
        .include(csrc)
        .include(regex)
        .include(&rdf_inc)
        .include(&std_inc)
        .define("SLOP_ARENA_NO_CAP", None)
        .define("SLOP_INTERN_THREADSAFE", None)
        .opt_level(2)
        .warnings(false);
    for src in &sources { build.file(csrc.join(src)); }
    for src in &regex_sources { build.file(regex.join(src)); }
    build.file("csrc_shim.c");
    build.compile("snarl_c");

    // slop_runtime.h threads through pthreads on POSIX and Win32 on Windows.
    if env::var("CARGO_CFG_TARGET_OS").as_deref() != Ok("windows") {
        println!("cargo:rustc-link-lib=pthread");
    }
    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=csrc_shim.c");
    for src in &sources { println!("cargo:rerun-if-changed={}", csrc.join(src).display()); }
    println!("cargo:rerun-if-changed={}", regex.display());
    println!("cargo:rerun-if-changed={}", runtime.join("slop_runtime.h").display());
}
