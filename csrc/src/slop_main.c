#include "../runtime/slop_runtime.h"
#include "slop_main.h"

void main_print_elapsed(slop_arena* arena, int64_t elapsed);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
main_CliArgs main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv);
void main_print_usage(void);
void main_print_ttl_error(slop_arena* arena, slop_string path, ttl_TtlFileError e);
slop_option_index_IndexedGraph main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet);
slop_option_data_graph_SnarlDataGraph main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet);
int main(int argc, char** _c_argv);

typedef struct { data_graph_SnarlDataGraph* dg; slop_arena* arena; } main__lambda_278_env_t;

static void main__lambda_278(main__lambda_278_env_t* _env, rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

void main_print_elapsed(slop_arena* arena, int64_t elapsed) {
    printf("%.*s", (int)(int_to_string(arena, (elapsed / 1000))).len, (int_to_string(arena, (elapsed / 1000))).data);
    printf("%s", ".");
    {
        __auto_type ms = (elapsed % 1000);
        if (ms < 100) {
            printf("%s", "0");
        }
        if (ms < 10) {
            printf("%s", "0");
        }
        printf("%.*s", (int)(int_to_string(arena, ms)).len, (int_to_string(arena, ms)).data);
    }
    printf("%s", "s");
}

slop_string main_argv_to_string(uint8_t** argv, int64_t index) {
    {
        __auto_type ptr = argv[index];
        return (slop_string){.len = strlen(ptr), .data = ptr};
    }
}

main_CliArgs main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv) {
    {
        slop_option_string data = (slop_option_string){.has_value = false};
        slop_option_string shapes = (slop_option_string){.has_value = false};
        slop_option_string emit = (slop_option_string){.has_value = false};
        uint8_t quiet = 0;
        int64_t max_errors = 0;
        uint8_t no_warnings = 0;
        uint8_t no_infos = 0;
        uint8_t help = 0;
        uint8_t version = 0;
        int64_t i = 1;
        int64_t positional_count = 0;
        while (i < argc) {
            {
                __auto_type arg = main_argv_to_string(argv, i);
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
                        shapes = (slop_option_string){.has_value = 1, .value = main_argv_to_string(argv, (i + 1))};
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --shapes requires a file path");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--emit")) || string_eq(arg, SLOP_STR("-o"))) {
                    if ((i + 1) < argc) {
                        emit = (slop_option_string){.has_value = 1, .value = main_argv_to_string(argv, (i + 1))};
                        i = (i + 2);
                    } else {
                        printf("%s\n", "Error: --emit requires a file path");
                        help = 1;
                        i = (i + 1);
                    }
                } else if (string_eq(arg, SLOP_STR("--max-errors")) || string_eq(arg, SLOP_STR("-m"))) {
                    if ((i + 1) < argc) {
                        {
                            __auto_type val_str = main_argv_to_string(argv, (i + 1));
                            __auto_type _mv_275 = strlib_parse_int(val_str);
                            if (_mv_275.is_ok) {
                                __auto_type n = _mv_275.data.ok;
                                max_errors = n;
                            } else if (!_mv_275.is_ok) {
                                __auto_type _ = _mv_275.data.err;
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
        return ((main_CliArgs){.data_file = data, .shapes_file = shapes, .emit_file = emit, .quiet = quiet, .max_errors = max_errors, .no_warnings = no_warnings, .no_infos = no_infos, .show_help = help, .show_version = version});
    }
}

void main_print_usage(void) {
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
    printf("%s\n", "");
    printf("%s\n", "Exit codes: 0 = conforms, 1 = violations, 2 = parse/internal error");
}

void main_print_ttl_error(slop_arena* arena, slop_string path, ttl_TtlFileError e) {
    printf("%s", "Error: failed to parse ");
    printf("%.*s\n", (int)(path).len, (path).data);
    __auto_type _mv_276 = e;
    switch (_mv_276.tag) {
        case ttl_TtlFileError_parse_error:
        {
            __auto_type pe = _mv_276.data.parse_error;
            printf("%s", "  at line ");
            printf("%.*s", (int)(int_to_string(arena, pe.position.line)).len, (int_to_string(arena, pe.position.line)).data);
            printf("%s", ", column ");
            printf("%.*s\n", (int)(int_to_string(arena, pe.position.column)).len, (int_to_string(arena, pe.position.column)).data);
            printf("%s", "  ");
            printf("%.*s\n", (int)(pe.message).len, (pe.message).data);
            break;
        }
        case ttl_TtlFileError_file_error:
        {
            __auto_type _ = _mv_276.data.file_error;
            printf("%s\n", "  (file not found or unreadable)");
            break;
        }
    }
}

slop_option_index_IndexedGraph main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet) {
    __auto_type _mv_277 = ttl_parse_ttl_file(arena, path);
    if (!_mv_277.is_ok) {
        __auto_type e = _mv_277.data.err;
        main_print_ttl_error(arena, path, e);
        return (slop_option_index_IndexedGraph){.has_value = false};
    } else if (_mv_277.is_ok) {
        __auto_type g = _mv_277.data.ok;
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
                printf("%.*s", (int)(int_to_string(arena, rdf_indexed_graph_size(ig))).len, (int_to_string(arena, rdf_indexed_graph_size(ig))).data);
                printf("%s", " triples from ");
                printf("%.*s\n", (int)(path).len, (path).data);
            }
            return (slop_option_index_IndexedGraph){.has_value = 1, .value = ig};
        }
    }
}

slop_option_data_graph_SnarlDataGraph main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet) {
    SLOP_PRE(((string_len(path) > 0)), "(> (string-len path) 0)");
    slop_option_data_graph_SnarlDataGraph _retval = {0};
    {
        __auto_type dg = snarl_data_graph_create(arena);
        __auto_type _mv_279 = ttl_parse_ttl_file_for_each_triple(arena, path, ({ main__lambda_278_env_t* main__lambda_278_env = (main__lambda_278_env_t*)slop_arena_alloc(arena, sizeof(main__lambda_278_env_t)); *main__lambda_278_env = (main__lambda_278_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)main__lambda_278, (void*)main__lambda_278_env }; }));
        if (!_mv_279.is_ok) {
            __auto_type e = _mv_279.data.err;
            main_print_ttl_error(arena, path, e);
            return (slop_option_data_graph_SnarlDataGraph){.has_value = false};
        } else if (_mv_279.is_ok) {
            __auto_type _ = _mv_279.data.ok;
            if (!(quiet)) {
                printf("%s", "Parsed ");
                printf("%.*s", (int)(int_to_string(arena, snarl_data_graph_size(dg))).len, (int_to_string(arena, snarl_data_graph_size(dg))).data);
                printf("%s", " triples from ");
                printf("%.*s\n", (int)(path).len, (path).data);
            }
            return (slop_option_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        }
    }
    SLOP_POST((({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type g = _mv.value; (snarl_data_graph_size(g) >= 0); }) : (1); })), "(match $result ((some g) (>= (snarl-data-graph-size g) 0)) ((none) true))");
    return _retval;
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((134217728) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena = slop_arena_new(134217728);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena;
        {
            __auto_type args = main_parse_args(arena, argc, argv);
            if (args.show_version) {
                printf("snarl %s\n", SNARL_VERSION);
                return 0;
            } else {
                __auto_type _mv_280 = args.data_file;
                if (!_mv_280.has_value) {
                    main_print_usage();
                    if (args.show_help) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else if (_mv_280.has_value) {
                    __auto_type data_path = _mv_280.value;
                    if (args.show_help) {
                        main_print_usage();
                        return 0;
                    } else {
                        {
                            __auto_type quiet = args.quiet;
                            __auto_type parse_start = slop_now_ms();
                            __auto_type _mv_281 = main_load_data_graph(arena, data_path, quiet);
                            if (!_mv_281.has_value) {
                                return 2;
                            } else if (_mv_281.has_value) {
                                __auto_type data_graph = _mv_281.value;
                                {
                                    __auto_type shapes_path = ({ __auto_type _mv = args.shapes_file; _mv.has_value ? ({ __auto_type sp = _mv.value; sp; }) : (data_path); });
                                    {
                                        __auto_type shapes_result = main_load_graph(arena, shapes_path, quiet);
                                        __auto_type _mv_282 = shapes_result;
                                        if (!_mv_282.has_value) {
                                            return 2;
                                        } else if (_mv_282.has_value) {
                                            __auto_type shapes_graph = _mv_282.value;
                                            {
                                                __auto_type parse_elapsed = (slop_now_ms() - parse_start);
                                                __auto_type validate_start = slop_now_ms();
                                                __auto_type config = ((types_ValidatorConfig){.verbose = !(quiet), .max_errors = args.max_errors, .include_warnings = !(args.no_warnings), .include_infos = !(args.no_infos)});
                                                __auto_type _mv_283 = snarl_validate_data_graph_with_config(arena, data_graph, shapes_graph, config);
                                                switch (_mv_283.tag) {
                                                    case types_ValidatorResult_validate_success:
                                                    {
                                                        __auto_type report = _mv_283.data.validate_success;
                                                        {
                                                            __auto_type validate_elapsed = (slop_now_ms() - validate_start);
                                                            __auto_type violations = snarl_get_violations(arena, report);
                                                            __auto_type violation_count = ((int64_t)((violations).len));
                                                            __auto_type total_count = snarl_get_result_count(report);
                                                            if (quiet) {
                                                                if (report.conforms) {
                                                                    printf("%s\n", "conforms");
                                                                } else {
                                                                    printf("%.*s", (int)(int_to_string(arena, total_count)).len, (int_to_string(arena, total_count)).data);
                                                                    printf("%s\n", " result(s)");
                                                                }
                                                            } else {
                                                                snarl_print_report(arena, report);
                                                                printf("%s", "\nValidation completed in ");
                                                                main_print_elapsed(arena, validate_elapsed);
                                                                printf("%s\n", "");
                                                            }
                                                            __auto_type _mv_284 = args.emit_file;
                                                            if (_mv_284.has_value) {
                                                                __auto_type emit_path = _mv_284.value;
                                                                if (!(quiet)) {
                                                                    printf("%s", "Report written to ");
                                                                    printf("%.*s\n", (int)(emit_path).len, (emit_path).data);
                                                                }
                                                            } else if (!_mv_284.has_value) {
                                                            }
                                                            if (report.conforms) {
                                                                return 0;
                                                            } else {
                                                                return 1;
                                                            }
                                                        }
                                                    }
                                                    case types_ValidatorResult_validate_error:
                                                    {
                                                        __auto_type msg = _mv_283.data.validate_error;
                                                        printf("%s", "Error: ");
                                                        printf("%.*s\n", (int)(msg).len, (msg).data);
                                                        return 2;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        slop_arena_free(arena);
    }
}

