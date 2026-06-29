use std::path::Path;

fn main() {
    let csrc = Path::new("csrc/src");
    let runtime = Path::new("csrc/runtime");

    let sources = [
        "slop_cardinality.c",
        "slop_common.c",
        "slop_data_graph.c",
        "slop_engine.c",
        "slop_file.c",
        "slop_index.c",
        "slop_list.c",
        "slop_logical.c",
        "slop_other.c",
        "slop_pair.c",
        "slop_parse.c",
        "slop_path.c",
        "slop_rdf.c",
        "slop_report.c",
        "slop_shape.c",
        "slop_snarl.c",
        "slop_string.c",
        "slop_strlib.c",
        "slop_target.c",
        "slop_ttl.c",
        "slop_types.c",
        "slop_value_range.c",
        "slop_value_type.c",
        "slop_vocab.c",
        "slop_xsd.c",
    ];

    let mut build = cc::Build::new();
    build
        .include(runtime)
        .include(csrc)
        .define("SLOP_ARENA_NO_CAP", None)
        .define("SLOP_INTERN_THREADSAFE", None)
        .opt_level(2)
        .warnings(false);

    for src in &sources {
        build.file(csrc.join(src));
    }
    build.file("csrc_shim.c");

    build.compile("snarl_c");

    println!("cargo:rustc-link-lib=pthread");

    // Rerun if any C source changes
    println!("cargo:rerun-if-changed=csrc_shim.c");
    for src in &sources {
        println!("cargo:rerun-if-changed={}", csrc.join(src).display());
    }
    println!(
        "cargo:rerun-if-changed={}",
        runtime.join("slop_runtime.h").display()
    );
}
