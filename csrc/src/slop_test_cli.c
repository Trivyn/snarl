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
uint8_t snarl_cli_tests_test_cli_test_core_value_range_types(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_core_string_details(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_core_flags_unsupported(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_pattern_uncompilable(slop_arena* arena);
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
slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_tests_test_cli_load_test_data_graph(slop_arena* arena, slop_string path);
snarl_types_ValidatorConfig snarl_cli_tests_test_cli_af_config(uint8_t run_rules, uint8_t shacl12);
uint8_t snarl_cli_tests_test_cli_assert_inference(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_violations);
uint8_t snarl_cli_tests_test_cli_assert_af_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring);
uint8_t snarl_cli_tests_test_cli_test_af_node_exprs(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_rules_off(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_rules_condition(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_entailment(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_entailment_shacl12_name(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_order_visible(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_order_same(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_deactivated(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_expression(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_expression_report(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_report_blank_nodes(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_sparql_rule(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_function_expr(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_unknown_entailment(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_shnex_without_flag(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_expr_cycle(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_triplerule_missing_slot(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af_triplerule_default_slot_shacl12(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_node_exprs(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_list_duplicates(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_unsupported_function(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_global_rule(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_global_rule_af_mode(slop_arena* arena);
int main(int argc, char** _c_argv);

typedef struct { snarl_data_graph_SnarlDataGraph* dg; slop_arena* arena; } snarl_cli_tests_test_cli__lambda_718_env_t;

static void snarl_cli_tests_test_cli__lambda_718(snarl_cli_tests_test_cli__lambda_718_env_t* _env, slop_rdf_rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_643 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_643.is_ok) {
        __auto_type g = _mv_643.data.ok;
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
    } else if (!_mv_643.is_ok) {
        __auto_type _ = _mv_643.data.err;
        return (slop_option_slop_rdf_index_IndexedGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_644 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_644.has_value) {
        __auto_type g = _mv_644.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (result) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_645 = (path); printf("%.*s", (int)_ps_645.len, _ps_645.data); });
                printf("%s\n", " conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_646 = (path); printf("%.*s", (int)_ps_646.len, _ps_646.data); });
                printf("%s\n", " expected to conform but got violations");
                return 0;
            }
        }
    } else if (!_mv_644.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_647 = (path); printf("%.*s\n", (int)_ps_647.len, _ps_647.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_648 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_648.has_value) {
        __auto_type g = _mv_648.value;
        __auto_type _mv_649 = snarl_validate(arena, g, g);
        switch (_mv_649.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_649.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if (actual_count == expected_count) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_650 = (path); printf("%.*s", (int)_ps_650.len, _ps_650.data); });
                        printf("%s", " has ");
                        ({ slop_string _ps_651 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_651.len, _ps_651.data); });
                        printf("%s\n", " violation(s)");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_652 = (path); printf("%.*s", (int)_ps_652.len, _ps_652.data); });
                        printf("%s", " expected ");
                        ({ slop_string _ps_653 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_653.len, _ps_653.data); });
                        printf("%s", " violation(s) but got ");
                        ({ slop_string _ps_654 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_654.len, _ps_654.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_649.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_655 = (msg); printf("%.*s\n", (int)_ps_655.len, _ps_655.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_648.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_656 = (path); printf("%.*s\n", (int)_ps_656.len, _ps_656.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_657 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_657.has_value) {
        __auto_type g = _mv_657.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (!(result)) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_658 = (path); printf("%.*s", (int)_ps_658.len, _ps_658.data); });
                printf("%s\n", " has violations");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_659 = (path); printf("%.*s", (int)_ps_659.len, _ps_659.data); });
                printf("%s\n", " expected violations but conforms");
                return 0;
            }
        }
    } else if (!_mv_657.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_660 = (path); printf("%.*s\n", (int)_ps_660.len, _ps_660.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_661 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_661.has_value) {
        __auto_type dg = _mv_661.value;
        __auto_type _mv_662 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_662.has_value) {
            __auto_type sg = _mv_662.value;
            {
                __auto_type result = snarl_conforms(arena, dg, sg);
                if (result) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_663 = (data_path); printf("%.*s", (int)_ps_663.len, _ps_663.data); });
                    printf("%s\n", " conforms");
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_664 = (data_path); printf("%.*s", (int)_ps_664.len, _ps_664.data); });
                    printf("%s\n", " expected to conform but got violations");
                    return 0;
                }
            }
        } else if (!_mv_662.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_665 = (shapes_path); printf("%.*s\n", (int)_ps_665.len, _ps_665.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_661.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_666 = (data_path); printf("%.*s\n", (int)_ps_666.len, _ps_666.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring) {
    __auto_type _mv_667 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_667.has_value) {
        __auto_type g = _mv_667.value;
        __auto_type _mv_668 = snarl_validate(arena, g, g);
        switch (_mv_668.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_668.data.validate_error;
                if (std_strlib_contains(msg, expected_substring)) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_669 = (path); printf("%.*s", (int)_ps_669.len, _ps_669.data); });
                    printf("%s", " engine error: ");
                    ({ slop_string _ps_670 = (msg); printf("%.*s\n", (int)_ps_670.len, _ps_670.data); });
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_671 = (path); printf("%.*s", (int)_ps_671.len, _ps_671.data); });
                    printf("%s", " engine error message did not contain '");
                    ({ slop_string _ps_672 = (expected_substring); printf("%.*s", (int)_ps_672.len, _ps_672.data); });
                    printf("%s", "': ");
                    ({ slop_string _ps_673 = (msg); printf("%.*s\n", (int)_ps_673.len, _ps_673.data); });
                    return 0;
                }
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_668.data.validate_success;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_674 = (path); printf("%.*s", (int)_ps_674.len, _ps_674.data); });
                printf("%s\n", " expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_667.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_675 = (path); printf("%.*s\n", (int)_ps_675.len, _ps_675.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring) {
    __auto_type _mv_676 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_676.has_value) {
        __auto_type dg = _mv_676.value;
        __auto_type _mv_677 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_677.has_value) {
            __auto_type sg = _mv_677.value;
            __auto_type _mv_678 = snarl_validate(arena, dg, sg);
            switch (_mv_678.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_678.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_679 = (data_path); printf("%.*s", (int)_ps_679.len, _ps_679.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_680 = (msg); printf("%.*s\n", (int)_ps_680.len, _ps_680.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_681 = (data_path); printf("%.*s", (int)_ps_681.len, _ps_681.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_682 = (expected_substring); printf("%.*s", (int)_ps_682.len, _ps_682.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_683 = (msg); printf("%.*s\n", (int)_ps_683.len, _ps_683.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_678.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_684 = (data_path); printf("%.*s", (int)_ps_684.len, _ps_684.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_677.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_685 = (shapes_path); printf("%.*s\n", (int)_ps_685.len, _ps_685.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_676.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_686 = (data_path); printf("%.*s\n", (int)_ps_686.len, _ps_686.data); });
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
    __auto_type _mv_687 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_687.has_value) {
        __auto_type g = _mv_687.value;
        {
            __auto_type objs = rdf_indexed_graph_objects(arena, g, rdf_make_iri(arena, shape_iri), rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH));
            __auto_type _mv_688 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_688.has_value) {
                __auto_type path_node = _mv_688.value;
                return snarl_parse_path_node_eval_depth(arena, g, path_node);
            } else if (!_mv_688.has_value) {
                return -1;
            }
            SLOP_UNREACHABLE();
        }
    } else if (!_mv_687.has_value) {
        return -2;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path) {
    __auto_type _mv_689 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_689.has_value) {
        __auto_type g = _mv_689.value;
        __auto_type _mv_690 = snarl_validate(arena, g, g);
        switch (_mv_690.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_690.data.validate_success;
                printf("%s", "  PASS: ");
                ({ slop_string _ps_691 = (path); printf("%.*s", (int)_ps_691.len, _ps_691.data); });
                printf("%s\n", " validated (no engine error)");
                return 1;
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_690.data.validate_error;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_692 = (path); printf("%.*s", (int)_ps_692.len, _ps_692.data); });
                printf("%s", " unexpected engine error: ");
                ({ slop_string _ps_693 = (msg); printf("%.*s\n", (int)_ps_693.len, _ps_693.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_689.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_694 = (path); printf("%.*s\n", (int)_ps_694.len, _ps_694.data); });
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
        __auto_type _mv_695 = snarl_cli_tests_test_cli_load_test_graph(arena, fixture);
        if (_mv_695.has_value) {
            __auto_type g = _mv_695.value;
            __auto_type _mv_696 = snarl_validate(arena, g, g);
            switch (_mv_696.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_696.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_696.data.validate_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_697 = (fixture); printf("%.*s", (int)_ps_697.len, _ps_697.data); });
                    printf("%s", " unexpected engine error: ");
                    ({ slop_string _ps_698 = (msg); printf("%.*s\n", (int)_ps_698.len, _ps_698.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_695.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_699 = (fixture); printf("%.*s\n", (int)_ps_699.len, _ps_699.data); });
            ok = 0;
        }
        if (!((snarl_cli_tests_test_cli_path_depth_of(arena, SLOP_STR("fixtures/path-depth-flat.ttl"), SLOP_STR("http://example.org/NameProp")) == 1))) {
            printf("%s", "  FAIL: flat control depth drifted after ");
            (void)(({ slop_string _ps_700 = (fixture); printf("%.*s\n", (int)_ps_700.len, _ps_700.data); }));
            ok = 0;
        }
        __auto_type _mv_701 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/path-depth-flat.ttl"));
        if (_mv_701.has_value) {
            __auto_type fg = _mv_701.value;
            __auto_type _mv_702 = snarl_validate(arena, fg, fg);
            switch (_mv_702.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_702.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_702.data.validate_error;
                    printf("%s", "  FAIL: flat control errored after ");
                    ({ slop_string _ps_703 = (fixture); printf("%.*s", (int)_ps_703.len, _ps_703.data); });
                    printf("%s", ": ");
                    ({ slop_string _ps_704 = (msg); printf("%.*s\n", (int)_ps_704.len, _ps_704.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_701.has_value) {
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
            (void)(({ slop_string _ps_705 = (shape_iri); printf("%.*s", (int)_ps_705.len, _ps_705.data); }));
            printf("%s", " depth = ");
            printf("%lld", (long long)(actual));
            printf("%s\n", "");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            (void)(({ slop_string _ps_706 = (shape_iri); printf("%.*s", (int)_ps_706.len, _ps_706.data); }));
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
    __auto_type _mv_707 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_707.has_value) {
        __auto_type dg = _mv_707.value;
        __auto_type _mv_708 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_708.has_value) {
            __auto_type sg = _mv_708.value;
            __auto_type _mv_709 = snarl_validate(arena, dg, sg);
            switch (_mv_709.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_709.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if (actual_count == expected_count) {
                            printf("%s", "  PASS: ");
                            ({ slop_string _ps_710 = (data_path); printf("%.*s", (int)_ps_710.len, _ps_710.data); });
                            printf("%s", " has ");
                            ({ slop_string _ps_711 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_711.len, _ps_711.data); });
                            printf("%s\n", " violation(s)");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            ({ slop_string _ps_712 = (data_path); printf("%.*s", (int)_ps_712.len, _ps_712.data); });
                            printf("%s", " expected ");
                            ({ slop_string _ps_713 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_713.len, _ps_713.data); });
                            printf("%s", " violation(s) but got ");
                            ({ slop_string _ps_714 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_714.len, _ps_714.data); });
                            return 0;
                        }
                    }
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_709.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    ({ slop_string _ps_715 = (msg); printf("%.*s\n", (int)_ps_715.len, _ps_715.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_708.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_716 = (shapes_path); printf("%.*s\n", (int)_ps_716.len, _ps_716.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_707.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_717 = (data_path); printf("%.*s\n", (int)_ps_717.len, _ps_717.data); });
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
        __auto_type _mv_719 = slop_rdf_ttl_parse_ttl_file_for_each_triple(arena, path, ({ snarl_cli_tests_test_cli__lambda_718_env_t* snarl_cli_tests_test_cli__lambda_718_env = (snarl_cli_tests_test_cli__lambda_718_env_t*)slop_arena_alloc(arena, sizeof(snarl_cli_tests_test_cli__lambda_718_env_t)); *snarl_cli_tests_test_cli__lambda_718_env = (snarl_cli_tests_test_cli__lambda_718_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)snarl_cli_tests_test_cli__lambda_718, (void*)snarl_cli_tests_test_cli__lambda_718_env }; }));
        if (_mv_719.is_ok) {
            __auto_type _ = _mv_719.data.ok;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        } else if (!_mv_719.is_ok) {
            __auto_type _ = _mv_719.data.err;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
}

int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r) {
    __auto_type _mv_720 = r;
    switch (_mv_720.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_720.data.validate_success;
            if (snarl_types_report_conforms(report)) {
                return snarl_get_result_count(report);
            } else {
                return (1000000 + snarl_get_result_count(report));
            }
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_720.data.validate_error;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_721 = snarl_cli_tests_test_cli_load_streamed_data_graph(arena, data_path);
    if (!_mv_721.has_value) {
        printf("%s", "  FAIL: could not stream ");
        ({ slop_string _ps_722 = (data_path); printf("%.*s\n", (int)_ps_722.len, _ps_722.data); });
        return 0;
    } else if (_mv_721.has_value) {
        __auto_type dg = _mv_721.value;
        __auto_type _mv_723 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
        if (!_mv_723.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_724 = (data_path); printf("%.*s\n", (int)_ps_724.len, _ps_724.data); });
            return 0;
        } else if (_mv_723.has_value) {
            __auto_type ig = _mv_723.value;
            __auto_type _mv_725 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
            if (!_mv_725.has_value) {
                printf("%s", "  FAIL: could not load ");
                ({ slop_string _ps_726 = (shapes_path); printf("%.*s\n", (int)_ps_726.len, _ps_726.data); });
                return 0;
            } else if (_mv_725.has_value) {
                __auto_type sg = _mv_725.value;
                {
                    __auto_type config = snarl_default_config();
                    __auto_type streamed = snarl_cli_tests_test_cli_result_summary(snarl_validate_data_graph_with_config(arena, dg, sg, config));
                    __auto_type indexed = snarl_cli_tests_test_cli_result_summary(snarl_validate_with_config(arena, ig, sg, config));
                    if ((snarl_data_graph_size(dg) == rdf_indexed_graph_size(ig)) && ((streamed >= 0) && (streamed == indexed))) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_727 = (data_path); printf("%.*s", (int)_ps_727.len, _ps_727.data); });
                        printf("%s\n", " streams to the same graph and report");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_728 = (data_path); printf("%.*s", (int)_ps_728.len, _ps_728.data); });
                        printf("%s", " streamed size/summary ");
                        ({ slop_string _ps_729 = (int_to_string(arena, snarl_data_graph_size(dg))); printf("%.*s", (int)_ps_729.len, _ps_729.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_730 = (int_to_string(arena, streamed)); printf("%.*s", (int)_ps_730.len, _ps_730.data); });
                        printf("%s", " vs indexed ");
                        ({ slop_string _ps_731 = (int_to_string(arena, rdf_indexed_graph_size(ig))); printf("%.*s", (int)_ps_731.len, _ps_731.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_732 = (int_to_string(arena, indexed)); printf("%.*s\n", (int)_ps_732.len, _ps_732.data); });
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
    __auto_type _mv_733 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_733.has_value) {
        __auto_type g = _mv_733.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if ((size == 17) && snarl_conforms(arena, g, g)) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                ({ slop_string _ps_734 = (int_to_string(arena, size)); printf("%.*s\n", (int)_ps_734.len, _ps_734.data); });
                return 0;
            }
        }
    } else if (!_mv_733.has_value) {
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
    __auto_type _mv_735 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_735.has_value) {
        __auto_type g = _mv_735.value;
        __auto_type _mv_736 = snarl_validate(arena, g, g);
        switch (_mv_736.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_736.data.validate_success;
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
                __auto_type _ = _mv_736.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_735.has_value) {
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

uint8_t snarl_cli_tests_test_cli_test_core_value_range_types(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/core-value-range-types.ttl"), 5);
}

uint8_t snarl_cli_tests_test_cli_test_core_string_details(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/core-string-details.ttl"), 6);
}

uint8_t snarl_cli_tests_test_cli_test_core_flags_unsupported(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/core-flags-unsupported.ttl"), SLOP_STR("sh:flags \"x\" of shape [anonymous shape] is not supported"));
}

uint8_t snarl_cli_tests_test_cli_test_pattern_uncompilable(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/pattern-uncompilable.ttl"), SLOP_STR("sh:pattern \"^(ab$\" of shape [anonymous shape] does not compile as a regular expression (REG_EPAREN)"));
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
    __auto_type _mv_737 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-data.ttl"));
    if (_mv_737.has_value) {
        __auto_type dg = _mv_737.value;
        __auto_type _mv_738 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-shapes.ttl"));
        if (_mv_738.has_value) {
            __auto_type sg = _mv_738.value;
            {
                __auto_type config = ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 1, .include_warnings = 1, .include_infos = 1});
                __auto_type _mv_739 = snarl_validate_with_config(arena, dg, sg, config);
                switch (_mv_739.tag) {
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_739.data.validate_error;
                        if (std_strlib_contains(msg, SLOP_STR("Shape recursion"))) {
                            printf("%s\n", "  PASS: max-errors=1 still surfaces the engine error");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: max-errors=1 error message did not contain 'Shape recursion': ");
                            ({ slop_string _ps_740 = (msg); printf("%.*s\n", (int)_ps_740.len, _ps_740.data); });
                            return 0;
                        }
                    }
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_739.data.validate_success;
                        printf("%s\n", "  FAIL: max-errors=1 silently truncated the engine error into a success report");
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_738.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-shapes.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_737.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-data.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-scale-acyclic-3000.ttl"), SLOP_STR("depth budget"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena) {
    __auto_type _mv_741 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-scale-cyclic-1000.ttl"));
    if (_mv_741.has_value) {
        __auto_type g = _mv_741.value;
        __auto_type _mv_742 = snarl_validate(arena, g, g);
        switch (_mv_742.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_742.data.validate_error;
                printf("%s", "  PASS: fixtures/cycle-scale-cyclic-1000.ttl engine error: ");
                ({ slop_string _ps_743 = (msg); printf("%.*s\n", (int)_ps_743.len, _ps_743.data); });
                return 1;
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_742.data.validate_success;
                printf("%s\n", "  FAIL: fixtures/cycle-scale-cyclic-1000.ttl expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_741.has_value) {
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

slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_tests_test_cli_load_test_data_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_744 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_744.is_ok) {
        __auto_type g = _mv_744.data.ok;
        {
            __auto_type dg = snarl_data_graph_create(arena);
            {
                __auto_type _coll = g.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    dg = snarl_data_graph_add(arena, dg, t);
                }
            }
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        }
    } else if (!_mv_744.is_ok) {
        __auto_type _ = _mv_744.data.err;
        return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

snarl_types_ValidatorConfig snarl_cli_tests_test_cli_af_config(uint8_t run_rules, uint8_t shacl12) {
    return ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 0, .include_warnings = 1, .include_infos = 1, .run_rules = run_rules, .shacl12 = shacl12});
}

uint8_t snarl_cli_tests_test_cli_assert_inference(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_violations) {
    __auto_type _mv_745 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_745.has_value) {
        __auto_type dg = _mv_745.value;
        __auto_type _mv_746 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_746.has_value) {
            __auto_type sg = _mv_746.value;
            {
                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, dg, sg, config);
                __auto_type inferred = ((int64_t)((outcome.inferred).len));
                __auto_type _mv_747 = outcome.result;
                switch (_mv_747.tag) {
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type report = _mv_747.data.validate_success;
                        {
                            __auto_type violations = ((int64_t)((snarl_get_violations(arena, report)).len));
                            if ((inferred == expected_inferred) && (violations == expected_violations)) {
                                printf("%s", "  PASS: ");
                                ({ slop_string _ps_748 = (path); printf("%.*s", (int)_ps_748.len, _ps_748.data); });
                                printf("%s", " inferred ");
                                ({ slop_string _ps_749 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_749.len, _ps_749.data); });
                                printf("%s", " triple(s), ");
                                ({ slop_string _ps_750 = (int_to_string(arena, violations)); printf("%.*s", (int)_ps_750.len, _ps_750.data); });
                                printf("%s\n", " violation(s)");
                                return 1;
                            } else {
                                printf("%s", "  FAIL: ");
                                ({ slop_string _ps_751 = (path); printf("%.*s", (int)_ps_751.len, _ps_751.data); });
                                printf("%s", " expected ");
                                ({ slop_string _ps_752 = (int_to_string(arena, expected_inferred)); printf("%.*s", (int)_ps_752.len, _ps_752.data); });
                                printf("%s", " inferred / ");
                                ({ slop_string _ps_753 = (int_to_string(arena, expected_violations)); printf("%.*s", (int)_ps_753.len, _ps_753.data); });
                                printf("%s", " violation(s), got ");
                                ({ slop_string _ps_754 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_754.len, _ps_754.data); });
                                printf("%s", " / ");
                                ({ slop_string _ps_755 = (int_to_string(arena, violations)); printf("%.*s\n", (int)_ps_755.len, _ps_755.data); });
                                return 0;
                            }
                        }
                    }
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_747.data.validate_error;
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_756 = (path); printf("%.*s", (int)_ps_756.len, _ps_756.data); });
                        printf("%s", " validation error: ");
                        ({ slop_string _ps_757 = (msg); printf("%.*s\n", (int)_ps_757.len, _ps_757.data); });
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_746.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_758 = (path); printf("%.*s\n", (int)_ps_758.len, _ps_758.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_745.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_759 = (path); printf("%.*s\n", (int)_ps_759.len, _ps_759.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_af_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring) {
    __auto_type _mv_760 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_760.has_value) {
        __auto_type dg = _mv_760.value;
        __auto_type _mv_761 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_761.has_value) {
            __auto_type sg = _mv_761.value;
            __auto_type _mv_762 = snarl_validate_data_graph_with_inference(arena, dg, sg, config).result;
            switch (_mv_762.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_762.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_763 = (path); printf("%.*s", (int)_ps_763.len, _ps_763.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_764 = (msg); printf("%.*s\n", (int)_ps_764.len, _ps_764.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_765 = (path); printf("%.*s", (int)_ps_765.len, _ps_765.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_766 = (expected_substring); printf("%.*s", (int)_ps_766.len, _ps_766.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_767 = (msg); printf("%.*s\n", (int)_ps_767.len, _ps_767.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_762.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_768 = (path); printf("%.*s", (int)_ps_768.len, _ps_768.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_761.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_769 = (path); printf("%.*s\n", (int)_ps_769.len, _ps_769.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_760.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_770 = (path); printf("%.*s\n", (int)_ps_770.len, _ps_770.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_af_node_exprs(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-node-exprs.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 11, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af_rules_off(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-rules.ttl"), snarl_cli_tests_test_cli_af_config(0, 0), 0, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af_rules_condition(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-rules.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 1, 1);
}

uint8_t snarl_cli_tests_test_cli_test_af_entailment(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/af-entailment.ttl"), 1);
}

uint8_t snarl_cli_tests_test_cli_test_af_entailment_shacl12_name(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-entailment.ttl"), snarl_cli_tests_test_cli_af_config(0, 1), 1, 1);
}

uint8_t snarl_cli_tests_test_cli_test_af_order_visible(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-order-visible.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 2, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af_order_same(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-order-same.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 1, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af_deactivated(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-deactivated.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 1, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af_expression(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_violations(arena, SLOP_STR("fixtures/af-expression.ttl"), 4);
}

uint8_t snarl_cli_tests_test_cli_test_af_expression_report(slop_arena* arena) {
    __auto_type _mv_771 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_771.has_value) {
        __auto_type g = _mv_771.value;
        __auto_type _mv_772 = snarl_validate(arena, g, g);
        switch (_mv_772.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_772.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if ((std_strlib_contains(text, SLOP_STR("Source constraint: "))) && (std_strlib_contains(text, SLOP_STR("Person must be verified"))) && (std_strlib_contains(text, SLOP_STR("ExpressionConstraintComponent")))) {
                        printf("%s\n", "  PASS: sh:expression results carry sourceConstraint and message");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: sh:expression report is missing sourceConstraint or message:\n");
                        ({ slop_string _ps_773 = (text); printf("%.*s\n", (int)_ps_773.len, _ps_773.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_772.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_774 = (msg); printf("%.*s\n", (int)_ps_774.len, _ps_774.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_771.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-expression.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_af_report_blank_nodes(slop_arena* arena) {
    __auto_type _mv_775 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_775.has_value) {
        __auto_type g = _mv_775.value;
        __auto_type _mv_776 = snarl_validate(arena, g, g);
        switch (_mv_776.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_776.data.validate_success;
                {
                    __auto_type rg = snarl_report_to_graph(arena, report);
                    slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
                    __auto_type type_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/1999/02/22-rdf-syntax-ns#type"));
                    int64_t seen = 0;
                    int64_t clashes = 0;
                    {
                        __auto_type _coll = rdf_indexed_graph_match(arena, rg, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#sourceConstraint"))}, no_term);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type tr = _coll.data[_i];
                            seen = (seen + 1);
                            if (((int64_t)((rdf_indexed_graph_objects(arena, rg, rdf_triple_object(tr), type_pred)).len)) > 0) {
                                clashes = (clashes + 1);
                            }
                        }
                    }
                    if ((seen == 4) && (clashes == 0)) {
                        printf("%s\n", "  PASS: report blank nodes do not collide with sh:sourceConstraint nodes");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_777 = (int_to_string(arena, clashes)); printf("%.*s", (int)_ps_777.len, _ps_777.data); });
                        printf("%s", " of ");
                        ({ slop_string _ps_778 = (int_to_string(arena, seen)); printf("%.*s", (int)_ps_778.len, _ps_778.data); });
                        printf("%s\n", " sh:sourceConstraint values are report nodes");
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_776.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_779 = (msg); printf("%.*s\n", (int)_ps_779.len, _ps_779.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_775.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-expression.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_af_sparql_rule(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-sparql-rule.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), SLOP_STR("sh:SPARQLRule"));
}

uint8_t snarl_cli_tests_test_cli_test_af_function_expr(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-function-expr.ttl"), snarl_cli_tests_test_cli_af_config(0, 0), SLOP_STR("isAdult"));
}

uint8_t snarl_cli_tests_test_cli_test_af_unknown_entailment(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-unknown-entailment.ttl"), snarl_cli_tests_test_cli_af_config(0, 0), SLOP_STR("entailment"));
}

uint8_t snarl_cli_tests_test_cli_test_af_shnex_without_flag(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-shnex-without-flag.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), SLOP_STR("--shacl12"));
}

uint8_t snarl_cli_tests_test_cli_test_af_expr_cycle(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-expr-cycle.ttl"), snarl_cli_tests_test_cli_af_config(0, 0), SLOP_STR("Cyclic node expression"));
}

uint8_t snarl_cli_tests_test_cli_test_af_triplerule_missing_slot(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-triplerule-missing-slot.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), SLOP_STR("sh:subject"));
}

uint8_t snarl_cli_tests_test_cli_test_af_triplerule_default_slot_shacl12(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af-triplerule-missing-slot.ttl"), snarl_cli_tests_test_cli_af_config(1, 1), 1, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af12_node_exprs(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af12-node-exprs.ttl"), snarl_cli_tests_test_cli_af_config(1, 1), 8, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af12_list_duplicates(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af12-list-duplicates.ttl"), snarl_cli_tests_test_cli_af_config(0, 1), 0, 1);
}

uint8_t snarl_cli_tests_test_cli_test_af12_unsupported_function(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af12-unsupported-function.ttl"), snarl_cli_tests_test_cli_af_config(1, 1), SLOP_STR("shacl-node-expr#count at"));
}

uint8_t snarl_cli_tests_test_cli_test_af12_global_rule(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af12-global-rule.ttl"), snarl_cli_tests_test_cli_af_config(1, 1), SLOP_STR("global rules"));
}

uint8_t snarl_cli_tests_test_cli_test_af12_global_rule_af_mode(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af12-global-rule.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 0, 0);
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
            if (snarl_cli_tests_test_cli_test_pattern_uncompilable(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_core_value_range_types(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_core_string_details(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_core_flags_unsupported(arena)) {
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
            if (snarl_cli_tests_test_cli_test_af_node_exprs(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_rules_off(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_rules_condition(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_entailment(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_entailment_shacl12_name(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_order_visible(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_order_same(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_deactivated(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_expression(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_expression_report(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_report_blank_nodes(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_sparql_rule(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_function_expr(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_unknown_entailment(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_shnex_without_flag(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_expr_cycle(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_triplerule_missing_slot(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af_triplerule_default_slot_shacl12(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_node_exprs(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_list_duplicates(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_unsupported_function(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_global_rule(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_global_rule_af_mode(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            printf("%s\n", "");
            printf("%s\n", "---");
            (void)(({ slop_string _ps_780 = (int_to_string(arena, passed)); printf("%.*s", (int)_ps_780.len, _ps_780.data); }));
            printf("%s", " passed, ");
            (void)(({ slop_string _ps_781 = (int_to_string(arena, failed)); printf("%.*s", (int)_ps_781.len, _ps_781.data); }));
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

