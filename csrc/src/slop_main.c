#include "../runtime/slop_runtime.h"
#include "slop_main.h"

void snarl_cli_main_print_elapsed(slop_arena* arena, int64_t elapsed);
slop_string snarl_cli_main_argv_to_string(uint8_t** argv, int64_t index);
snarl_cli_main_CliArgs snarl_cli_main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv);
void snarl_cli_main_print_usage(void);
void snarl_cli_main_print_ttl_error(slop_arena* arena, slop_string path, slop_rdf_ttl_TtlFileError e);
slop_option_slop_rdf_index_IndexedGraph snarl_cli_main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet);
slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet);
uint8_t snarl_cli_main_write_turtle(slop_arena* arena, slop_string path, slop_list_slop_rdf_rdf_Triple triples);
void snarl_cli_main_write_inferred(slop_arena* arena, slop_string path, slop_list_slop_rdf_rdf_Triple inferred, uint8_t quiet);
void snarl_cli_main_write_report(slop_arena* arena, slop_string path, snarl_types_ValidationReport report, uint8_t quiet);
int main(int argc, char** _c_argv);

typedef struct { snarl_data_graph_SnarlDataGraph* dg; slop_arena* arena; } snarl_cli_main__lambda_668_env_t;

static void snarl_cli_main__lambda_668(snarl_cli_main__lambda_668_env_t* _env, slop_rdf_rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

void snarl_cli_main_print_elapsed(slop_arena* arena, int64_t elapsed) {
    (void)(({ slop_string _ps_657 = (int_to_string(arena, (elapsed / 1000))); printf("%.*s", (int)_ps_657.len, _ps_657.data); }));
    printf("%s", ".");
    {
        __auto_type ms = (elapsed % 1000);
        if (ms < 100) {
            printf("%s", "0");
        }
        if (ms < 10) {
            printf("%s", "0");
        }
        (void)(({ slop_string _ps_658 = (int_to_string(arena, ms)); printf("%.*s", (int)_ps_658.len, _ps_658.data); }));
    }
    printf("%s", "s");
}

slop_string snarl_cli_main_argv_to_string(uint8_t** argv, int64_t index) {
    {
        __auto_type ptr = argv[index];
        return (slop_string){.len = strlen(ptr), .data = ptr};
    }
}

snarl_cli_main_CliArgs snarl_cli_main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv) {
    {
        slop_option_string data = (slop_option_string){.has_value = false};
        slop_option_string shapes = (slop_option_string){.has_value = false};
        slop_option_string emit = (slop_option_string){.has_value = false};
        uint8_t quiet = 0;
        int64_t max_errors = 0;
        uint8_t no_warnings = 0;
        uint8_t no_infos = 0;
        uint8_t rules = 0;
        slop_option_string emit_inferred = (slop_option_string){.has_value = false};
        uint8_t shacl12 = 0;
        uint8_t help = 0;
        uint8_t version = 0;
        int64_t i = 1;
        int64_t positional_count = 0;
        while (i < argc) {
            {
                __auto_type arg = snarl_cli_main_argv_to_string(argv, i);
                if (string_eq(arg, SLOP_STR("--help")) || string_eq(arg, SLOP_STR("-h"))) {
                    help = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--version")) || string_eq(arg, SLOP_STR("-V"))) {
                    version = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--quiet")) || string_eq(arg, SLOP_STR("-q"))) {
                    quiet = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--shapes")) || string_eq(arg, SLOP_STR("-s"))) {
                    if ((i + 1) < argc) {
                        shapes = (slop_option_string){.has_value = 1, .value = snarl_cli_main_argv_to_string(argv, (i + 1))};
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --shapes requires a file path");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--emit")) || string_eq(arg, SLOP_STR("-o"))) {
                    if ((i + 1) < argc) {
                        emit = (slop_option_string){.has_value = 1, .value = snarl_cli_main_argv_to_string(argv, (i + 1))};
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --emit requires a file path");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--max-errors")) || string_eq(arg, SLOP_STR("-m"))) {
                    if ((i + 1) < argc) {
                        {
                            __auto_type val_str = snarl_cli_main_argv_to_string(argv, (i + 1));
                            __auto_type _mv_659 = std_strlib_parse_int(val_str);
                            if (_mv_659.is_ok) {
                                __auto_type n = _mv_659.data.ok;
                                max_errors = n;
                            } else if (!_mv_659.is_ok) {
                                __auto_type _ = _mv_659.data.err;
                                printf("%s\n", "Error: --max-errors requires a number");
                            }
                        }
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --max-errors requires a number");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--no-warnings"))) {
                    no_warnings = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--no-infos"))) {
                    no_infos = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--rules")) || string_eq(arg, SLOP_STR("-r"))) {
                    rules = 1;
                    i = (i + 1);
                } else if (string_eq(arg, SLOP_STR("--emit-inferred"))) {
                    if ((i + 1) < argc) {
                        emit_inferred = (slop_option_string){.has_value = 1, .value = snarl_cli_main_argv_to_string(argv, (i + 1))};
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --emit-inferred requires a file path");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--shacl12"))) {
                    shacl12 = 1;
                    i = (i + 1);
                } else if (1) {
                    if (positional_count == 0) {
                        data = (slop_option_string){.has_value = 1, .value = arg};
                    } else {
                        shapes = (slop_option_string){.has_value = 1, .value = arg};
                    }
                    positional_count = (positional_count + 1);
                    i = (i + 1);
                }
            }
        }
        return ((snarl_cli_main_CliArgs){.data_file = data, .shapes_file = shapes, .emit_file = emit, .quiet = quiet, .max_errors = SLOP_RANGE(int64_t, max_errors, 1, 0, 0, 0, "(Int 0 ..) at main.slop:172:21"), .no_warnings = no_warnings, .no_infos = no_infos, .rules = rules, .emit_inferred_file = emit_inferred, .shacl12 = shacl12, .show_help = help, .show_version = version});
    }
}

void snarl_cli_main_print_usage(void) {
    printf("%s\n", "snarl - SHACL Core Validator");
    printf("%s\n", "");
    printf("%s\n", "Usage: snarl [options] <data.ttl> [shapes.ttl]");
    printf("%s\n", "");
    printf("%s\n", "If one file is given, it serves as both data and shapes graph.");
    printf("%s\n", "");
    printf("%s\n", "Options:");
    printf("%s\n", "  -h, --help         Show this help message");
    printf("%s\n", "  -V, --version      Show version information");
    printf("%s\n", "  -q, --quiet        Only print violation count");
    printf("%s\n", "  -o, --emit FILE    Write validation report as Turtle");
    printf("%s\n", "  -s, --shapes FILE  Explicit shapes file (alt to positional)");
    printf("%s\n", "  -m, --max-errors N Stop after N violations");
    printf("%s\n", "  --no-warnings      Suppress sh:Warning results");
    printf("%s\n", "  --no-infos         Suppress sh:Info results");
    printf("%s\n", "  -r, --rules        Run SHACL rules (sh:TripleRule) before validating;");
    printf("%s\n", "                     they also run when the shapes graph declares");
    printf("%s\n", "                     sh:entailment sh:Rules");
    printf("%s\n", "  --emit-inferred FILE");
    printf("%s\n", "                     Run rules and write the inferred triples as Turtle");
    printf("%s\n", "  --shacl12          EXPERIMENTAL: also accept SHACL 1.2 Working Draft");
    printf("%s\n", "                     syntax (node expressions in the shnex: namespace,");
    printf("%s\n", "                     sh:RulesEntailment). The drafts are still changing.");
    printf("%s\n", "");
    printf("%s\n", "Exit codes: 0 = conforms, 1 = violations, 2 = parse/internal error");
}

void snarl_cli_main_print_ttl_error(slop_arena* arena, slop_string path, slop_rdf_ttl_TtlFileError e) {
    printf("%s", "Error: failed to parse ");
    (void)(({ slop_string _ps_660 = (path); printf("%.*s\n", (int)_ps_660.len, _ps_660.data); }));
    __auto_type _mv_661 = e;
    switch (_mv_661.tag) {
        case slop_rdf_ttl_TtlFileError_parse_error:
        {
            __auto_type pe = _mv_661.data.parse_error;
            printf("%s", "  at line ");
            ({ slop_string _ps_662 = (int_to_string(arena, pe.position.line)); printf("%.*s", (int)_ps_662.len, _ps_662.data); });
            printf("%s", ", column ");
            ({ slop_string _ps_663 = (int_to_string(arena, pe.position.column)); printf("%.*s\n", (int)_ps_663.len, _ps_663.data); });
            printf("%s", "  ");
            ({ slop_string _ps_664 = (pe.message); printf("%.*s\n", (int)_ps_664.len, _ps_664.data); });
            break;
        }
        case slop_rdf_ttl_TtlFileError_file_error:
        {
            __auto_type _ = _mv_661.data.file_error;
            printf("%s\n", "  (file not found or unreadable)");
            break;
        }
    }
}

slop_option_slop_rdf_index_IndexedGraph snarl_cli_main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet) {
    __auto_type _mv_665 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (!_mv_665.is_ok) {
        __auto_type e = _mv_665.data.err;
        snarl_cli_main_print_ttl_error(arena, path, e);
        return (slop_option_slop_rdf_index_IndexedGraph){.has_value = false};
    } else if (_mv_665.is_ok) {
        __auto_type g = _mv_665.data.ok;
        {
            __auto_type ig = rdf_indexed_graph_create(arena);
            {
                __auto_type _coll = g.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    ig = rdf_indexed_graph_add(arena, ig, t);
                }
            }
            if (!(quiet)) {
                printf("%s", "Parsed ");
                ({ slop_string _ps_666 = (int_to_string(arena, rdf_indexed_graph_size(ig))); printf("%.*s", (int)_ps_666.len, _ps_666.data); });
                printf("%s", " triples from ");
                ({ slop_string _ps_667 = (path); printf("%.*s\n", (int)_ps_667.len, _ps_667.data); });
            }
            return (slop_option_slop_rdf_index_IndexedGraph){.has_value = 1, .value = ig};
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet) {
    SLOP_PRE(((string_len(path) > 0)), "(> (string-len path) 0)");
    {
        __auto_type dg = snarl_data_graph_create(arena);
        __auto_type _mv_669 = slop_rdf_ttl_parse_ttl_file_for_each_triple(arena, path, ({ snarl_cli_main__lambda_668_env_t* snarl_cli_main__lambda_668_env = (snarl_cli_main__lambda_668_env_t*)slop_arena_alloc(arena, sizeof(snarl_cli_main__lambda_668_env_t)); *snarl_cli_main__lambda_668_env = (snarl_cli_main__lambda_668_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)snarl_cli_main__lambda_668, (void*)snarl_cli_main__lambda_668_env }; }));
        if (!_mv_669.is_ok) {
            __auto_type e = _mv_669.data.err;
            snarl_cli_main_print_ttl_error(arena, path, e);
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
        } else if (_mv_669.is_ok) {
            __auto_type _ = _mv_669.data.ok;
            if (!(quiet)) {
                printf("%s", "Parsed ");
                ({ slop_string _ps_670 = (int_to_string(arena, snarl_data_graph_size(dg))); printf("%.*s", (int)_ps_670.len, _ps_670.data); });
                printf("%s", " triples from ");
                ({ slop_string _ps_671 = (path); printf("%.*s\n", (int)_ps_671.len, _ps_671.data); });
            }
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t snarl_cli_main_write_turtle(slop_arena* arena, slop_string path, slop_list_slop_rdf_rdf_Triple triples) {
    {
        __auto_type g = rdf_make_graph(arena);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                g = rdf_graph_add(arena, g, t);
            }
        }
        __auto_type _mv_672 = slop_rdf_serialize_ttl_serialize_ttl_file(arena, g, ((slop_rdf_serialize_ttl_SerializeConfig){.prefixes = slop_rdf_ttl_make_prefix_map(arena), .base_iri = (slop_option_string){.has_value = false}, .indent_width = 2}), path);
        if (_mv_672.is_ok) {
            __auto_type _ = _mv_672.data.ok;
            return 1;
        } else if (!_mv_672.is_ok) {
            __auto_type _ = _mv_672.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

void snarl_cli_main_write_inferred(slop_arena* arena, slop_string path, slop_list_slop_rdf_rdf_Triple inferred, uint8_t quiet) {
    if (snarl_cli_main_write_turtle(arena, path, inferred)) {
        if (!(quiet)) {
            printf("%s", "Wrote ");
            (void)(({ slop_string _ps_673 = (int_to_string(arena, ((int64_t)((inferred).len)))); printf("%.*s", (int)_ps_673.len, _ps_673.data); }));
            printf("%s", " inferred triple(s) to ");
            (void)(({ slop_string _ps_674 = (path); printf("%.*s\n", (int)_ps_674.len, _ps_674.data); }));
        }
    } else {
        printf("%s", "Error: could not write inferred triples to ");
        (void)(({ slop_string _ps_675 = (path); printf("%.*s\n", (int)_ps_675.len, _ps_675.data); }));
    }
}

void snarl_cli_main_write_report(slop_arena* arena, slop_string path, snarl_types_ValidationReport report, uint8_t quiet) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type triples = rdf_indexed_graph_match(arena, snarl_report_to_graph(arena, report), no_term, no_term, no_term);
        if (snarl_cli_main_write_turtle(arena, path, triples)) {
            if (!(quiet)) {
                printf("%s", "Report written to ");
                (void)(({ slop_string _ps_676 = (path); printf("%.*s\n", (int)_ps_676.len, _ps_676.data); }));
            }
        } else {
            printf("%s", "Error: could not write the report to ");
            (void)(({ slop_string _ps_677 = (path); printf("%.*s\n", (int)_ps_677.len, _ps_677.data); }));
        }
    }
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    (void)argc; (void)argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((134217728) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_4 = slop_arena_new(134217728);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_4.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena_4;
        {
            __auto_type args = snarl_cli_main_parse_args(arena, argc, argv);
            if (args.show_version) {
                printf("snarl %s\n", SNARL_VERSION);
                {
                    int _wa_ret = 0;
                    slop_arena_free(&_arena_4);
                    return _wa_ret;
                }
            } else {
                __auto_type _mv_678 = args.data_file;
                if (!_mv_678.has_value) {
                    snarl_cli_main_print_usage();
                    if (args.show_help) {
                        {
                            int _wa_ret = 0;
                            slop_arena_free(&_arena_4);
                            return _wa_ret;
                        }
                    } else {
                        {
                            int _wa_ret = 1;
                            slop_arena_free(&_arena_4);
                            return _wa_ret;
                        }
                    }
                } else if (_mv_678.has_value) {
                    __auto_type data_path = _mv_678.value;
                    if (args.show_help) {
                        snarl_cli_main_print_usage();
                        {
                            int _wa_ret = 0;
                            slop_arena_free(&_arena_4);
                            return _wa_ret;
                        }
                    } else {
                        {
                            __auto_type quiet = args.quiet;
                            __auto_type parse_start = slop_now_ms();
                            __auto_type _mv_679 = snarl_cli_main_load_data_graph(arena, data_path, quiet);
                            if (!_mv_679.has_value) {
                                {
                                    int _wa_ret = 2;
                                    slop_arena_free(&_arena_4);
                                    return _wa_ret;
                                }
                            } else if (_mv_679.has_value) {
                                __auto_type data_graph = _mv_679.value;
                                {
                                    __auto_type shapes_path = ({ __auto_type _mv = args.shapes_file; _mv.has_value ? ({ __auto_type sp = _mv.value; sp; }) : (data_path); });
                                    {
                                        __auto_type shapes_result = snarl_cli_main_load_graph(arena, shapes_path, quiet);
                                        __auto_type _mv_680 = shapes_result;
                                        if (!_mv_680.has_value) {
                                            {
                                                int _wa_ret = 2;
                                                slop_arena_free(&_arena_4);
                                                return _wa_ret;
                                            }
                                        } else if (_mv_680.has_value) {
                                            __auto_type shapes_graph = _mv_680.value;
                                            {
                                                __auto_type parse_elapsed = (slop_now_ms() - parse_start);
                                                __auto_type validate_start = slop_now_ms();
                                                __auto_type config = ((snarl_types_ValidatorConfig){.verbose = !(quiet), .max_errors = args.max_errors, .include_warnings = !(args.no_warnings), .include_infos = !(args.no_infos), .run_rules = (args.rules || (((args.emit_inferred_file).has_value))), .shacl12 = args.shacl12});
                                                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, data_graph, shapes_graph, config);
                                                __auto_type _mv_681 = args.emit_inferred_file;
                                                if (_mv_681.has_value) {
                                                    __auto_type path = _mv_681.value;
                                                    __auto_type _mv_682 = outcome.result;
                                                    switch (_mv_682.tag) {
                                                        case snarl_types_ValidatorResult_validate_success:
                                                        {
                                                            __auto_type _ = _mv_682.data.validate_success;
                                                            snarl_cli_main_write_inferred(arena, path, outcome.inferred, quiet);
                                                            break;
                                                        }
                                                        case snarl_types_ValidatorResult_validate_error:
                                                        {
                                                            __auto_type _ = _mv_682.data.validate_error;
                                                            break;
                                                        }
                                                    }
                                                } else if (!_mv_681.has_value) {
                                                }
                                                __auto_type _mv_683 = outcome.result;
                                                switch (_mv_683.tag) {
                                                    case snarl_types_ValidatorResult_validate_success:
                                                    {
                                                        __auto_type report = _mv_683.data.validate_success;
                                                        {
                                                            __auto_type validate_elapsed = (slop_now_ms() - validate_start);
                                                            __auto_type violations = snarl_get_violations(arena, report);
                                                            __auto_type violation_count = ((int64_t)((violations).len));
                                                            __auto_type total_count = snarl_get_result_count(report);
                                                            if (quiet) {
                                                                if (report.conforms) {
                                                                    printf("%s\n", "conforms");
                                                                } else {
                                                                    ({ slop_string _ps_684 = (int_to_string(arena, total_count)); printf("%.*s", (int)_ps_684.len, _ps_684.data); });
                                                                    printf("%s\n", " result(s)");
                                                                }
                                                            } else {
                                                                snarl_print_report(arena, report);
                                                                printf("%s", "\nValidation completed in ");
                                                                snarl_cli_main_print_elapsed(arena, validate_elapsed);
                                                                printf("%s\n", "");
                                                            }
                                                            __auto_type _mv_685 = args.emit_file;
                                                            if (_mv_685.has_value) {
                                                                __auto_type emit_path = _mv_685.value;
                                                                snarl_cli_main_write_report(arena, emit_path, report, quiet);
                                                            } else if (!_mv_685.has_value) {
                                                            }
                                                            if (report.conforms) {
                                                                {
                                                                    int _wa_ret = 0;
                                                                    slop_arena_free(&_arena_4);
                                                                    return _wa_ret;
                                                                }
                                                            } else {
                                                                {
                                                                    int _wa_ret = 1;
                                                                    slop_arena_free(&_arena_4);
                                                                    return _wa_ret;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    case snarl_types_ValidatorResult_validate_error:
                                                    {
                                                        __auto_type msg = _mv_683.data.validate_error;
                                                        printf("%s", "Error: ");
                                                        ({ slop_string _ps_686 = (msg); printf("%.*s\n", (int)_ps_686.len, _ps_686.data); });
                                                        {
                                                            int _wa_ret = 2;
                                                            slop_arena_free(&_arena_4);
                                                            return _wa_ret;
                                                        }
                                                    }
                                                }
                                                SLOP_UNREACHABLE();
                                            }
                                        }
                                        SLOP_UNREACHABLE();
                                    }
                                }
                            }
                            SLOP_UNREACHABLE();
                        }
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        slop_arena_free(arena);
    }
}

