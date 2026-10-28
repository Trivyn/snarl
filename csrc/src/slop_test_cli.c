#include "../runtime/slop_runtime.h"
#include "slop_test_cli.h"

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count);
uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring);
uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring);
void snarl_cli_tests_test_cli_reset_test_arena(slop_arena* arena);
void snarl_cli_tests_test_cli_poison_test_arena(slop_arena* arena, int64_t nbytes);
int64_t snarl_cli_tests_test_cli_path_depth_of(slop_arena* arena, slop_string path, slop_string shape_iri);
uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_soak_one(slop_arena* arena, slop_string fixture);
uint8_t snarl_cli_tests_test_cli_assert_depth(slop_arena* arena, slop_string path, slop_string shape_iri, int64_t expected);
uint8_t snarl_cli_tests_test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count);
uint8_t snarl_cli_tests_test_cli_test_empty_graph(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_valid_person(slop_arena* arena);
slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_tests_test_cli_load_streamed_data_graph(slop_arena* arena, slop_string path);
int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r);
uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_employee(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_rdf12(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_rdf12_annotation_block(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cardinality_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_datatype_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_class_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_nodekind_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_target_node(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_multiple_violations(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_report_string(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_employee_directory(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_product_catalog(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_address_book(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_valid_library(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_multi_shape(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_pattern_unicode(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_pattern_noncapturing(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_subclass_class_conforms(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_subclass_class(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_vacuous_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_self_loop(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_mutual(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_chain(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_diamond(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_acyclic(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_cyclic(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_inverse_self(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_in_list(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_legitimate(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_node(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_and(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_xone(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_not(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_acyclic_control(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed_control(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_qualified_value_shape(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_and(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_xone(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_language_in(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_ignored_properties(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_max_errors_precedence(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_linear_50000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_shared_dag_30(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_structural(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_purity(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_poisoned_arena(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_guard_revisit_after_unwind(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_diamond_poisoned(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_controls_poisoned(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_over_budget(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_at_budget(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_diverse_input_soak(slop_arena* arena);
int main(int argc, char** _c_argv);

typedef struct { snarl_data_graph_SnarlDataGraph* dg; slop_arena* arena; } snarl_cli_tests_test_cli__lambda_554_env_t;

static void snarl_cli_tests_test_cli__lambda_554(snarl_cli_tests_test_cli__lambda_554_env_t* _env, slop_rdf_rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_531 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_531.is_ok) {
        __auto_type g = _mv_531.data.ok;
        {
            __auto_type ig = rdf_indexed_graph_create(arena);
            {
                __auto_type _coll = g.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    ig = rdf_indexed_graph_add(arena, ig, t);
                }
            }
            return (slop_option_slop_rdf_index_IndexedGraph){.has_value = 1, .value = ig};
        }
    } else if (!_mv_531.is_ok) {
        __auto_type _ = _mv_531.data.err;
        return (slop_option_slop_rdf_index_IndexedGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_532 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_532.has_value) {
        __auto_type g = _mv_532.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (result) {
                printf("%s", "  PASS: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected to conform but got violations");
                return 0;
            }
        }
    } else if (!_mv_532.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_533 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_533.has_value) {
        __auto_type g = _mv_533.value;
        __auto_type _mv_534 = snarl_validate(arena, g, g);
        switch (_mv_534.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_534.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if (actual_count == expected_count) {
                        printf("%s", "  PASS: ");
                        printf("%.*s", (int)(path).len, (path).data);
                        printf("%s", " has ");
                        printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                        printf("%s\n", " violation(s)");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        printf("%.*s", (int)(path).len, (path).data);
                        printf("%s", " expected ");
                        printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                        printf("%s", " violation(s) but got ");
                        printf("%.*s\n", (int)(int_to_string(arena, actual_count)).len, (int_to_string(arena, actual_count)).data);
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_534.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_533.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_535 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_535.has_value) {
        __auto_type g = _mv_535.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (!(result)) {
                printf("%s", "  PASS: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " has violations");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected violations but conforms");
                return 0;
            }
        }
    } else if (!_mv_535.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_536 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_536.has_value) {
        __auto_type dg = _mv_536.value;
        __auto_type _mv_537 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_537.has_value) {
            __auto_type sg = _mv_537.value;
            {
                __auto_type result = snarl_conforms(arena, dg, sg);
                if (result) {
                    printf("%s", "  PASS: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " conforms");
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " expected to conform but got violations");
                    return 0;
                }
            }
        } else if (!_mv_537.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_536.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring) {
    __auto_type _mv_538 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_538.has_value) {
        __auto_type g = _mv_538.value;
        __auto_type _mv_539 = snarl_validate(arena, g, g);
        switch (_mv_539.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_539.data.validate_error;
                if (std_strlib_contains(msg, expected_substring)) {
                    printf("%s", "  PASS: ");
                    printf("%.*s", (int)(path).len, (path).data);
                    printf("%s", " engine error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(path).len, (path).data);
                    printf("%s", " engine error message did not contain '");
                    printf("%.*s", (int)(expected_substring).len, (expected_substring).data);
                    printf("%s", "': ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 0;
                }
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_539.data.validate_success;
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_538.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring) {
    __auto_type _mv_540 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_540.has_value) {
        __auto_type dg = _mv_540.value;
        __auto_type _mv_541 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_541.has_value) {
            __auto_type sg = _mv_541.value;
            __auto_type _mv_542 = snarl_validate(arena, dg, sg);
            switch (_mv_542.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_542.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s", " engine error: ");
                        printf("%.*s\n", (int)(msg).len, (msg).data);
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s", " engine error message did not contain '");
                        printf("%.*s", (int)(expected_substring).len, (expected_substring).data);
                        printf("%s", "': ");
                        printf("%.*s\n", (int)(msg).len, (msg).data);
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_542.data.validate_success;
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_541.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_540.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

void snarl_cli_tests_test_cli_reset_test_arena(slop_arena* arena) {
    slop_arena_reset(arena);
}

void snarl_cli_tests_test_cli_poison_test_arena(slop_arena* arena, int64_t nbytes) {
    memset(slop_arena_alloc(arena, (size_t)nbytes), 0x01, (size_t)nbytes);
}

int64_t snarl_cli_tests_test_cli_path_depth_of(slop_arena* arena, slop_string path, slop_string shape_iri) {
    __auto_type _mv_543 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_543.has_value) {
        __auto_type g = _mv_543.value;
        {
            __auto_type objs = rdf_indexed_graph_objects(arena, g, rdf_make_iri(arena, shape_iri), rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH));
            __auto_type _mv_544 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_544.has_value) {
                __auto_type path_node = _mv_544.value;
                return snarl_parse_path_node_eval_depth(arena, g, path_node);
            } else if (!_mv_544.has_value) {
                return -1;
            }
            SLOP_UNREACHABLE();
        }
    } else if (!_mv_543.has_value) {
        return -2;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path) {
    __auto_type _mv_545 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_545.has_value) {
        __auto_type g = _mv_545.value;
        __auto_type _mv_546 = snarl_validate(arena, g, g);
        switch (_mv_546.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_546.data.validate_success;
                printf("%s", "  PASS: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " validated (no engine error)");
                return 1;
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_546.data.validate_error;
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s", " unexpected engine error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_545.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_soak_one(slop_arena* arena, slop_string fixture) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 4194304);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    {
        uint8_t ok = 1;
        __auto_type _mv_547 = snarl_cli_tests_test_cli_load_test_graph(arena, fixture);
        if (_mv_547.has_value) {
            __auto_type g = _mv_547.value;
            __auto_type _mv_548 = snarl_validate(arena, g, g);
            switch (_mv_548.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_548.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_548.data.validate_error;
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(fixture).len, (fixture).data);
                    printf("%s", " unexpected engine error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_547.has_value) {
            printf("%s", "  FAIL: could not load ");
            printf("%.*s\n", (int)(fixture).len, (fixture).data);
            ok = 0;
        }
        if (!((snarl_cli_tests_test_cli_path_depth_of(arena, SLOP_STR("fixtures/path-depth-flat.ttl"), SLOP_STR("http://example.org/NameProp")) == 1))) {
            printf("%s", "  FAIL: flat control depth drifted after ");
            printf("%.*s\n", (int)(fixture).len, (fixture).data);
            ok = 0;
        }
        __auto_type _mv_549 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/path-depth-flat.ttl"));
        if (_mv_549.has_value) {
            __auto_type fg = _mv_549.value;
            __auto_type _mv_550 = snarl_validate(arena, fg, fg);
            switch (_mv_550.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_550.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_550.data.validate_error;
                    printf("%s", "  FAIL: flat control errored after ");
                    printf("%.*s", (int)(fixture).len, (fixture).data);
                    printf("%s", ": ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_549.has_value) {
            printf("%s\n", "  FAIL: could not load flat control");
            ok = 0;
        }
        return ok;
    }
}

uint8_t snarl_cli_tests_test_cli_assert_depth(slop_arena* arena, slop_string path, slop_string shape_iri, int64_t expected) {
    {
        __auto_type actual = snarl_cli_tests_test_cli_path_depth_of(arena, path, shape_iri);
        if (actual == expected) {
            printf("%s", "  PASS: ");
            printf("%.*s", (int)(shape_iri).len, (shape_iri).data);
            printf("%s", " depth = ");
            printf("%lld", (long long)(actual));
            printf("%s\n", "");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            printf("%.*s", (int)(shape_iri).len, (shape_iri).data);
            printf("%s", " expected depth ");
            printf("%lld", (long long)(expected));
            printf("%s", " but got ");
            printf("%lld", (long long)(actual));
            printf("%s\n", "");
            return 0;
        }
    }
}

uint8_t snarl_cli_tests_test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count) {
    __auto_type _mv_551 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_551.has_value) {
        __auto_type dg = _mv_551.value;
        __auto_type _mv_552 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_552.has_value) {
            __auto_type sg = _mv_552.value;
            __auto_type _mv_553 = snarl_validate(arena, dg, sg);
            switch (_mv_553.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_553.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if (actual_count == expected_count) {
                            printf("%s", "  PASS: ");
                            printf("%.*s", (int)(data_path).len, (data_path).data);
                            printf("%s", " has ");
                            printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                            printf("%s\n", " violation(s)");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            printf("%.*s", (int)(data_path).len, (data_path).data);
                            printf("%s", " expected ");
                            printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                            printf("%s", " violation(s) but got ");
                            printf("%.*s\n", (int)(int_to_string(arena, actual_count)).len, (int_to_string(arena, actual_count)).data);
                            return 0;
                        }
                    }
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_553.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_552.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_551.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_empty_graph(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/empty.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_valid_person(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/valid-person.ttl"));
}

slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_tests_test_cli_load_streamed_data_graph(slop_arena* arena, slop_string path) {
    {
        __auto_type dg = snarl_data_graph_create(arena);
        __auto_type _mv_555 = slop_rdf_ttl_parse_ttl_file_for_each_triple(arena, path, ({ snarl_cli_tests_test_cli__lambda_554_env_t* snarl_cli_tests_test_cli__lambda_554_env = (snarl_cli_tests_test_cli__lambda_554_env_t*)slop_arena_alloc(arena, sizeof(snarl_cli_tests_test_cli__lambda_554_env_t)); *snarl_cli_tests_test_cli__lambda_554_env = (snarl_cli_tests_test_cli__lambda_554_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)snarl_cli_tests_test_cli__lambda_554, (void*)snarl_cli_tests_test_cli__lambda_554_env }; }));
        if (_mv_555.is_ok) {
            __auto_type _ = _mv_555.data.ok;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        } else if (!_mv_555.is_ok) {
            __auto_type _ = _mv_555.data.err;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
}

int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r) {
    __auto_type _mv_556 = r;
    switch (_mv_556.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_556.data.validate_success;
            if (snarl_types_report_conforms(report)) {
                return snarl_get_result_count(report);
            } else {
                return (1000000 + snarl_get_result_count(report));
            }
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_556.data.validate_error;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_557 = snarl_cli_tests_test_cli_load_streamed_data_graph(arena, data_path);
    if (!_mv_557.has_value) {
        printf("%s", "  FAIL: could not stream ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    } else if (_mv_557.has_value) {
        __auto_type dg = _mv_557.value;
        __auto_type _mv_558 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
        if (!_mv_558.has_value) {
            printf("%s", "  FAIL: could not load ");
            printf("%.*s\n", (int)(data_path).len, (data_path).data);
            return 0;
        } else if (_mv_558.has_value) {
            __auto_type ig = _mv_558.value;
            __auto_type _mv_559 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
            if (!_mv_559.has_value) {
                printf("%s", "  FAIL: could not load ");
                printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
                return 0;
            } else if (_mv_559.has_value) {
                __auto_type sg = _mv_559.value;
                {
                    __auto_type config = snarl_default_config();
                    __auto_type streamed = snarl_cli_tests_test_cli_result_summary(snarl_validate_data_graph_with_config(arena, dg, sg, config));
                    __auto_type indexed = snarl_cli_tests_test_cli_result_summary(snarl_validate_with_config(arena, ig, sg, config));
                    if ((snarl_data_graph_size(dg) == rdf_indexed_graph_size(ig)) && ((streamed >= 0) && (streamed == indexed))) {
                        printf("%s", "  PASS: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s\n", " streams to the same graph and report");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s", " streamed size/summary ");
                        printf("%.*s", (int)(int_to_string(arena, snarl_data_graph_size(dg))).len, (int_to_string(arena, snarl_data_graph_size(dg))).data);
                        printf("%s", "/");
                        printf("%.*s", (int)(int_to_string(arena, streamed)).len, (int_to_string(arena, streamed)).data);
                        printf("%s", " vs indexed ");
                        printf("%.*s", (int)(int_to_string(arena, rdf_indexed_graph_size(ig))).len, (int_to_string(arena, rdf_indexed_graph_size(ig))).data);
                        printf("%s", "/");
                        printf("%.*s\n", (int)(int_to_string(arena, indexed)).len, (int_to_string(arena, indexed)).data);
                        return 0;
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_employee(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_streamed_matches_indexed(arena, SLOP_STR("fixtures/employee-dir-data.ttl"), SLOP_STR("fixtures/employee-dir-shapes.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_rdf12(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_streamed_matches_indexed(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"), SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_rdf12_annotation_block(slop_arena* arena) {
    __auto_type _mv_560 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_560.has_value) {
        __auto_type g = _mv_560.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if ((size == 17) && snarl_conforms(arena, g, g)) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                printf("%.*s\n", (int)(int_to_string(arena, size)).len, (int_to_string(arena, size)).data);
                return 0;
            }
        }
    } else if (!_mv_560.has_value) {
        printf("%s\n", "  FAIL: could not load RDF 1.2 annotation fixture");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cardinality_violation(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_has_violations(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_datatype_violation(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_has_violations(arena, SLOP_STR("fixtures/datatype-violation.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_class_violation(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_has_violations(arena, SLOP_STR("fixtures/class-violation.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_nodekind_violation(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_has_violations(arena, SLOP_STR("fixtures/nodekind-violation.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_target_node(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/target-node.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_multiple_violations(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_has_violations(arena, SLOP_STR("fixtures/multiple-violations.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_report_string(slop_arena* arena) {
    __auto_type _mv_561 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_561.has_value) {
        __auto_type g = _mv_561.value;
        __auto_type _mv_562 = snarl_validate(arena, g, g);
        switch (_mv_562.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_562.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if (string_len(text) > 0) {
                        printf("%s\n", "  PASS: report-to-string produces output");
                        return 1;
                    } else {
                        printf("%s\n", "  FAIL: report-to-string returned empty string");
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type _ = _mv_562.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_561.has_value) {
        printf("%s\n", "  FAIL: could not load fixture");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_employee_directory(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/employee-dir-data.ttl"), SLOP_STR("fixtures/employee-dir-shapes.ttl"), 5);
}

uint8_t snarl_cli_tests_test_cli_test_product_catalog(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/product-catalog-data.ttl"), SLOP_STR("fixtures/product-catalog-shapes.ttl"), 3);
}

uint8_t snarl_cli_tests_test_cli_test_address_book(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/address-book-data.ttl"), SLOP_STR("fixtures/address-book-shapes.ttl"), 2);
}

uint8_t snarl_cli_tests_test_cli_test_valid_library(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/library-data.ttl"), SLOP_STR("fixtures/library-shapes.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_multi_shape(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/multi-shape-data.ttl"), SLOP_STR("fixtures/multi-shape-shapes.ttl"), 3);
}

uint8_t snarl_cli_tests_test_cli_test_pattern_unicode(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/pattern-unicode.ttl"), 2);
}

uint8_t snarl_cli_tests_test_cli_test_pattern_noncapturing(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/pattern-noncapturing.ttl"), 8);
}

uint8_t snarl_cli_tests_test_cli_test_subclass_class_conforms(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/subclass-class-conforms-data.ttl"), SLOP_STR("fixtures/subclass-class-conforms-shapes.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_subclass_class(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/subclass-class-data.ttl"), SLOP_STR("fixtures/subclass-class-shapes.ttl"), 1);
}

uint8_t snarl_cli_tests_test_cli_test_vacuous_or(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/vacuous-or-data.ttl"), SLOP_STR("fixtures/vacuous-or-shapes.ttl"), 1);
}

uint8_t snarl_cli_tests_test_cli_test_cycle_self_loop(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-self-loop.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_mutual(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-mutual.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_chain(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-chain.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_diamond(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-diamond.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_acyclic(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/cycle-recursive-person-acyclic-data.ttl"), SLOP_STR("fixtures/cycle-recursive-person-shapes.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_cyclic(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error_separate(arena, SLOP_STR("fixtures/cycle-recursive-person-cyclic-data.ttl"), SLOP_STR("fixtures/cycle-recursive-person-shapes.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_path_inverse_self(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-path-inverse-self.ttl"), SLOP_STR("Cyclic sh:path expression detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_in_list(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-in-list.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_path_legitimate(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-legitimate.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_node(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-node.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_and(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-and.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_or(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-or.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_xone(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-xone.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_not(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-not.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_acyclic_control(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-acyclic-control.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-swallowed.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed_control(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-swallowed-control.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_qualified_value_shape(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-qualified-value-shape.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_list_and(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-and.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_list_or(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-or.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_list_xone(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-xone.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_list_language_in(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-language-in.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_list_ignored_properties(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-ignored-properties.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t snarl_cli_tests_test_cli_test_max_errors_precedence(slop_arena* arena) {
    __auto_type _mv_563 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-data.ttl"));
    if (_mv_563.has_value) {
        __auto_type dg = _mv_563.value;
        __auto_type _mv_564 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-shapes.ttl"));
        if (_mv_564.has_value) {
            __auto_type sg = _mv_564.value;
            {
                __auto_type config = ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 1, .include_warnings = 1, .include_infos = 1});
                __auto_type _mv_565 = snarl_validate_with_config(arena, dg, sg, config);
                switch (_mv_565.tag) {
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_565.data.validate_error;
                        if (std_strlib_contains(msg, SLOP_STR("Shape recursion"))) {
                            printf("%s\n", "  PASS: max-errors=1 still surfaces the engine error");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: max-errors=1 error message did not contain 'Shape recursion': ");
                            printf("%.*s\n", (int)(msg).len, (msg).data);
                            return 0;
                        }
                    }
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_565.data.validate_success;
                        printf("%s\n", "  FAIL: max-errors=1 silently truncated the engine error into a success report");
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_564.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-shapes.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_563.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-data.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-scale-acyclic-3000.ttl"), SLOP_STR("depth budget"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena) {
    __auto_type _mv_566 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-scale-cyclic-1000.ttl"));
    if (_mv_566.has_value) {
        __auto_type g = _mv_566.value;
        __auto_type _mv_567 = snarl_validate(arena, g, g);
        switch (_mv_567.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_567.data.validate_error;
                printf("%s", "  PASS: fixtures/cycle-scale-cyclic-1000.ttl engine error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 1;
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_567.data.validate_success;
                printf("%s\n", "  FAIL: fixtures/cycle-scale-cyclic-1000.ttl expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_566.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-scale-cyclic-1000.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cycle_path_linear_50000(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-linear-50000.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_path_shared_dag_30(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-shared-dag-30.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_path_depth_structural(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    {
        __auto_type p = SLOP_STR("fixtures/path-depth-cases.ttl");
        uint8_t ok = 1;
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/FlatProp"), 1))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/SeqProp"), 2))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/AltProp"), 2))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/InverseChainProp"), 2))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/NestedProp"), 3))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_depth(arena, p, SLOP_STR("http://example.org/DeepSeqProp"), 4))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t snarl_cli_tests_test_cli_test_path_depth_purity(slop_arena* arena) {
    {
        __auto_type p = SLOP_STR("fixtures/path-depth-cases.ttl");
        __auto_type d1 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/FlatProp"));
        __auto_type d2 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/SeqProp"));
        __auto_type d3 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/NestedProp"));
        __auto_type d4 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/DeepSeqProp"));
        snarl_cli_tests_test_cli_reset_test_arena(arena);
        snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
        snarl_cli_tests_test_cli_reset_test_arena(arena);
        {
            __auto_type e1 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/FlatProp"));
            __auto_type e2 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/SeqProp"));
            __auto_type e3 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/NestedProp"));
            __auto_type e4 = snarl_cli_tests_test_cli_path_depth_of(arena, p, SLOP_STR("http://example.org/DeepSeqProp"));
            if (((d1 == e1) && (d2 == e2)) && ((d3 == e3) && (d4 == e4))) {
                if (((e1 == 1) && (e2 == 2)) && ((e3 == 3) && (e4 == 4))) {
                    printf("%s\n", "  PASS: path depth is stable and correct across a poisoned arena reset");
                    return 1;
                } else {
                    printf("%s\n", "  FAIL: path depths stable but structurally wrong");
                    return 0;
                }
            } else {
                printf("%s", "  FAIL: path depth changed across arena reuse: ");
                printf("%lld", (long long)(d1));
                printf("%s", ",");
                printf("%lld", (long long)(d2));
                printf("%s", ",");
                printf("%lld", (long long)(d3));
                printf("%s", ",");
                printf("%lld", (long long)(d4));
                printf("%s", " -> ");
                printf("%lld", (long long)(e1));
                printf("%s", ",");
                printf("%lld", (long long)(e2));
                printf("%s", ",");
                printf("%lld", (long long)(e3));
                printf("%s", ",");
                printf("%lld\n", (long long)(e4));
                return 0;
            }
        }
    }
}

uint8_t snarl_cli_tests_test_cli_test_path_depth_poisoned_arena(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    {
        __auto_type depth_ok = snarl_cli_tests_test_cli_assert_depth(arena, SLOP_STR("fixtures/path-depth-flat.ttl"), SLOP_STR("http://example.org/NameProp"), 1);
        __auto_type conforms_ok = snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/path-depth-flat.ttl"));
        return (depth_ok && conforms_ok);
    }
}

uint8_t snarl_cli_tests_test_cli_test_cycle_guard_revisit_after_unwind(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-guard-revisit-after-unwind.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_diamond_poisoned(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    return snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-diamond.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_controls_poisoned(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 16777216);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    {
        __auto_type a = snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-acyclic-control.ttl"));
        __auto_type b = snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-swallowed-control.ttl"));
        __auto_type c = snarl_cli_tests_test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-shared-dag-30.ttl"));
        __auto_type d = snarl_cli_tests_test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/cycle-recursive-person-acyclic-data.ttl"), SLOP_STR("fixtures/cycle-recursive-person-shapes.ttl"));
        return ((a && b) && (c && d));
    }
}

uint8_t snarl_cli_tests_test_cli_test_path_depth_over_budget(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 4194304);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/path-depth-over-budget.ttl"), SLOP_STR("Path nesting depth budget"));
}

uint8_t snarl_cli_tests_test_cli_test_path_depth_at_budget(slop_arena* arena) {
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    snarl_cli_tests_test_cli_poison_test_arena(arena, 4194304);
    snarl_cli_tests_test_cli_reset_test_arena(arena);
    return snarl_cli_tests_test_cli_assert_validates(arena, SLOP_STR("fixtures/path-depth-at-budget.ttl"));
}

uint8_t snarl_cli_tests_test_cli_test_diverse_input_soak(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/empty.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/valid-person.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/target-node.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/soak-long-iris.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/soak-blank-nodes.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/soak-lists.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cycle-chain.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cycle-diamond.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cycle-path-legitimate.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cycle-propshape-acyclic-control.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cycle-path-shared-dag-30.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/cardinality-violation.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/multiple-violations.ttl")))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_soak_one(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl")))) {
            ok = 0;
        }
        if (ok) {
            printf("%s\n", "  PASS: diverse-input soak -- no engine errors, flat control stable throughout");
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    (void)argc; (void)argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((67108864) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_3 = slop_arena_new(67108864);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_3.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena_3;
        printf("%s\n", "Snarl CLI Integration Tests");
        printf("%s\n", "===========================");
        printf("%s\n", "");
        {
            int64_t passed = 0;
            int64_t failed = 0;
            if (snarl_cli_tests_test_cli_test_empty_graph(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_valid_person(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_rdf12_annotation_block(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cardinality_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_datatype_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_class_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_nodekind_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_target_node(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_multiple_violations(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_report_string(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_employee_directory(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_product_catalog(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_address_book(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_streamed_data_graph_employee(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_streamed_data_graph_rdf12(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_valid_library(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_multi_shape(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_pattern_unicode(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_pattern_noncapturing(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_subclass_class_conforms(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_subclass_class(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_vacuous_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_self_loop(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_mutual(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_acyclic_chain(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_diamond(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_recursive_person_acyclic(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_recursive_person_cyclic(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_path_inverse_self(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_in_list(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_path_legitimate(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_node(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_and(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_xone(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_not(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_acyclic_control(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_swallowed(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_propshape_swallowed_control(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_qualified_value_shape(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_list_and(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_list_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_list_xone(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_list_language_in(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_list_ignored_properties(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_max_errors_precedence(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            snarl_cli_tests_test_cli_reset_test_arena(arena);
            if (snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            snarl_cli_tests_test_cli_reset_test_arena(arena);
            if (snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            snarl_cli_tests_test_cli_reset_test_arena(arena);
            if (snarl_cli_tests_test_cli_test_cycle_path_linear_50000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            snarl_cli_tests_test_cli_reset_test_arena(arena);
            if (snarl_cli_tests_test_cli_test_cycle_path_shared_dag_30(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_path_depth_structural(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_path_depth_purity(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_path_depth_poisoned_arena(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_guard_revisit_after_unwind(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_diamond_poisoned(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_cycle_acyclic_controls_poisoned(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_path_depth_over_budget(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_path_depth_at_budget(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_diverse_input_soak(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            printf("%s\n", "");
            printf("%s\n", "---");
            printf("%.*s", (int)(int_to_string(arena, passed)).len, (int_to_string(arena, passed)).data);
            printf("%s", " passed, ");
            printf("%.*s", (int)(int_to_string(arena, failed)).len, (int_to_string(arena, failed)).data);
            printf("%s\n", " failed");
            if (failed == 0) {
                {
                    int _wa_ret = 0;
                    slop_arena_free(&_arena_3);
                    return _wa_ret;
                }
            } else {
                {
                    int _wa_ret = 1;
                    slop_arena_free(&_arena_3);
                    return _wa_ret;
                }
            }
        }
        slop_arena_free(arena);
    }
}

