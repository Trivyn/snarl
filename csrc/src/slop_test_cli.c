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
slop_option_string snarl_cli_tests_test_cli_report_text(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t snarl_cli_tests_test_cli_assert_same_report(slop_arena* arena, slop_string data_path, slop_string shapes_a, slop_string shapes_b, slop_string expected_marker);
uint8_t snarl_cli_tests_test_cli_test_sparql_rule_validate_only_violates(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_sparql_rule_validate_only_conforms(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_sparql_rule_run_rules_fails(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_sparql_rule_entailment_fails(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_rules_validate_only(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_af12_rules_run_fails(slop_arena* arena);
snarl_types_ValidatorConfig snarl_cli_tests_test_cli_rule_config(uint8_t run_rules, uint8_t shacl12, uint8_t defer, slop_option_snarl_types_RuleOrder order_min, slop_option_snarl_types_RuleOrder order_max);
slop_option_snarl_types_RuleOrder snarl_cli_tests_test_cli_order_key(double shape_order, double rule_order);
slop_option_snarl_types_RuleOrder snarl_cli_tests_test_cli_no_order(void);
slop_rdf_rdf_Term snarl_cli_tests_test_cli_ex_iri(slop_arena* arena, slop_string local);
uint8_t snarl_cli_tests_test_cli_has_inferred(slop_arena* arena, slop_list_snarl_rules_InferredTriple inferred, slop_string s, slop_string p, slop_rdf_rdf_Term o, slop_string rule, slop_string focus);
int64_t snarl_cli_tests_test_cli_infer_count(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config);
uint8_t snarl_cli_tests_test_cli_assert_infer_count(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected);
uint8_t snarl_cli_tests_test_cli_assert_infer_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring);
uint8_t snarl_cli_tests_test_cli_assert_deferred(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_deferred, slop_string rule, slop_string shape, double shape_order, double rule_order);
uint8_t snarl_cli_tests_test_cli_test_defer_sparql_rules(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_defer_sparql_rules_shacl12(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_defer_off_fails(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_defer_unknown_rule_type_fails(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_defer_follows_order_range(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_defer_validate_entailment(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_order_range_bounds(slop_arena* arena);
slop_option_snarl_rules_InferOutput snarl_cli_tests_test_cli_infer_step(slop_arena* arena, snarl_data_graph_SnarlDataGraph dg, slop_rdf_index_IndexedGraph sg, double lo, double hi);
uint8_t snarl_cli_tests_test_cli_test_order_range_stepping(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_triple_inferred(slop_arena* arena, slop_list_snarl_rules_InferredTriple inferred, slop_string s, slop_string p, slop_rdf_rdf_Term o);
uint8_t snarl_cli_tests_test_cli_test_attribution(slop_arena* arena);
slop_string snarl_cli_tests_test_cli_term_display(slop_arena* arena, slop_rdf_rdf_Term t);
int main(int argc, char** _c_argv);

typedef struct { snarl_data_graph_SnarlDataGraph* dg; slop_arena* arena; } snarl_cli_tests_test_cli__lambda_719_env_t;

static void snarl_cli_tests_test_cli__lambda_719(snarl_cli_tests_test_cli__lambda_719_env_t* _env, slop_rdf_rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_644 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_644.is_ok) {
        __auto_type g = _mv_644.data.ok;
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
    } else if (!_mv_644.is_ok) {
        __auto_type _ = _mv_644.data.err;
        return (slop_option_slop_rdf_index_IndexedGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_645 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_645.has_value) {
        __auto_type g = _mv_645.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (result) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_646 = (path); printf("%.*s", (int)_ps_646.len, _ps_646.data); });
                printf("%s\n", " conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_647 = (path); printf("%.*s", (int)_ps_647.len, _ps_647.data); });
                printf("%s\n", " expected to conform but got violations");
                return 0;
            }
        }
    } else if (!_mv_645.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_648 = (path); printf("%.*s\n", (int)_ps_648.len, _ps_648.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_649 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_649.has_value) {
        __auto_type g = _mv_649.value;
        __auto_type _mv_650 = snarl_validate(arena, g, g);
        switch (_mv_650.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_650.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if (actual_count == expected_count) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_651 = (path); printf("%.*s", (int)_ps_651.len, _ps_651.data); });
                        printf("%s", " has ");
                        ({ slop_string _ps_652 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_652.len, _ps_652.data); });
                        printf("%s\n", " violation(s)");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_653 = (path); printf("%.*s", (int)_ps_653.len, _ps_653.data); });
                        printf("%s", " expected ");
                        ({ slop_string _ps_654 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_654.len, _ps_654.data); });
                        printf("%s", " violation(s) but got ");
                        ({ slop_string _ps_655 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_655.len, _ps_655.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_650.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_656 = (msg); printf("%.*s\n", (int)_ps_656.len, _ps_656.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_649.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_657 = (path); printf("%.*s\n", (int)_ps_657.len, _ps_657.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_658 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_658.has_value) {
        __auto_type g = _mv_658.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (!(result)) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_659 = (path); printf("%.*s", (int)_ps_659.len, _ps_659.data); });
                printf("%s\n", " has violations");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_660 = (path); printf("%.*s", (int)_ps_660.len, _ps_660.data); });
                printf("%s\n", " expected violations but conforms");
                return 0;
            }
        }
    } else if (!_mv_658.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_661 = (path); printf("%.*s\n", (int)_ps_661.len, _ps_661.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_662 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_662.has_value) {
        __auto_type dg = _mv_662.value;
        __auto_type _mv_663 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_663.has_value) {
            __auto_type sg = _mv_663.value;
            {
                __auto_type result = snarl_conforms(arena, dg, sg);
                if (result) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_664 = (data_path); printf("%.*s", (int)_ps_664.len, _ps_664.data); });
                    printf("%s\n", " conforms");
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_665 = (data_path); printf("%.*s", (int)_ps_665.len, _ps_665.data); });
                    printf("%s\n", " expected to conform but got violations");
                    return 0;
                }
            }
        } else if (!_mv_663.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_666 = (shapes_path); printf("%.*s\n", (int)_ps_666.len, _ps_666.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_662.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_667 = (data_path); printf("%.*s\n", (int)_ps_667.len, _ps_667.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring) {
    __auto_type _mv_668 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_668.has_value) {
        __auto_type g = _mv_668.value;
        __auto_type _mv_669 = snarl_validate(arena, g, g);
        switch (_mv_669.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_669.data.validate_error;
                if (std_strlib_contains(msg, expected_substring)) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_670 = (path); printf("%.*s", (int)_ps_670.len, _ps_670.data); });
                    printf("%s", " engine error: ");
                    ({ slop_string _ps_671 = (msg); printf("%.*s\n", (int)_ps_671.len, _ps_671.data); });
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_672 = (path); printf("%.*s", (int)_ps_672.len, _ps_672.data); });
                    printf("%s", " engine error message did not contain '");
                    ({ slop_string _ps_673 = (expected_substring); printf("%.*s", (int)_ps_673.len, _ps_673.data); });
                    printf("%s", "': ");
                    ({ slop_string _ps_674 = (msg); printf("%.*s\n", (int)_ps_674.len, _ps_674.data); });
                    return 0;
                }
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_669.data.validate_success;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_675 = (path); printf("%.*s", (int)_ps_675.len, _ps_675.data); });
                printf("%s\n", " expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_668.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_676 = (path); printf("%.*s\n", (int)_ps_676.len, _ps_676.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring) {
    __auto_type _mv_677 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_677.has_value) {
        __auto_type dg = _mv_677.value;
        __auto_type _mv_678 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_678.has_value) {
            __auto_type sg = _mv_678.value;
            __auto_type _mv_679 = snarl_validate(arena, dg, sg);
            switch (_mv_679.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_679.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_680 = (data_path); printf("%.*s", (int)_ps_680.len, _ps_680.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_681 = (msg); printf("%.*s\n", (int)_ps_681.len, _ps_681.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_682 = (data_path); printf("%.*s", (int)_ps_682.len, _ps_682.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_683 = (expected_substring); printf("%.*s", (int)_ps_683.len, _ps_683.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_684 = (msg); printf("%.*s\n", (int)_ps_684.len, _ps_684.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_679.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_685 = (data_path); printf("%.*s", (int)_ps_685.len, _ps_685.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_678.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_686 = (shapes_path); printf("%.*s\n", (int)_ps_686.len, _ps_686.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_677.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_687 = (data_path); printf("%.*s\n", (int)_ps_687.len, _ps_687.data); });
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
    __auto_type _mv_688 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_688.has_value) {
        __auto_type g = _mv_688.value;
        {
            __auto_type objs = rdf_indexed_graph_objects(arena, g, rdf_make_iri(arena, shape_iri), rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH));
            __auto_type _mv_689 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_689.has_value) {
                __auto_type path_node = _mv_689.value;
                return snarl_parse_path_node_eval_depth(arena, g, path_node);
            } else if (!_mv_689.has_value) {
                return -1;
            }
            SLOP_UNREACHABLE();
        }
    } else if (!_mv_688.has_value) {
        return -2;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path) {
    __auto_type _mv_690 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_690.has_value) {
        __auto_type g = _mv_690.value;
        __auto_type _mv_691 = snarl_validate(arena, g, g);
        switch (_mv_691.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_691.data.validate_success;
                printf("%s", "  PASS: ");
                ({ slop_string _ps_692 = (path); printf("%.*s", (int)_ps_692.len, _ps_692.data); });
                printf("%s\n", " validated (no engine error)");
                return 1;
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_691.data.validate_error;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_693 = (path); printf("%.*s", (int)_ps_693.len, _ps_693.data); });
                printf("%s", " unexpected engine error: ");
                ({ slop_string _ps_694 = (msg); printf("%.*s\n", (int)_ps_694.len, _ps_694.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_690.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_695 = (path); printf("%.*s\n", (int)_ps_695.len, _ps_695.data); });
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
        __auto_type _mv_696 = snarl_cli_tests_test_cli_load_test_graph(arena, fixture);
        if (_mv_696.has_value) {
            __auto_type g = _mv_696.value;
            __auto_type _mv_697 = snarl_validate(arena, g, g);
            switch (_mv_697.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_697.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_697.data.validate_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_698 = (fixture); printf("%.*s", (int)_ps_698.len, _ps_698.data); });
                    printf("%s", " unexpected engine error: ");
                    ({ slop_string _ps_699 = (msg); printf("%.*s\n", (int)_ps_699.len, _ps_699.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_696.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_700 = (fixture); printf("%.*s\n", (int)_ps_700.len, _ps_700.data); });
            ok = 0;
        }
        if (!((snarl_cli_tests_test_cli_path_depth_of(arena, SLOP_STR("fixtures/path-depth-flat.ttl"), SLOP_STR("http://example.org/NameProp")) == 1))) {
            printf("%s", "  FAIL: flat control depth drifted after ");
            (void)(({ slop_string _ps_701 = (fixture); printf("%.*s\n", (int)_ps_701.len, _ps_701.data); }));
            ok = 0;
        }
        __auto_type _mv_702 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/path-depth-flat.ttl"));
        if (_mv_702.has_value) {
            __auto_type fg = _mv_702.value;
            __auto_type _mv_703 = snarl_validate(arena, fg, fg);
            switch (_mv_703.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_703.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_703.data.validate_error;
                    printf("%s", "  FAIL: flat control errored after ");
                    ({ slop_string _ps_704 = (fixture); printf("%.*s", (int)_ps_704.len, _ps_704.data); });
                    printf("%s", ": ");
                    ({ slop_string _ps_705 = (msg); printf("%.*s\n", (int)_ps_705.len, _ps_705.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_702.has_value) {
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
            (void)(({ slop_string _ps_706 = (shape_iri); printf("%.*s", (int)_ps_706.len, _ps_706.data); }));
            printf("%s", " depth = ");
            printf("%lld", (long long)(actual));
            printf("%s\n", "");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            (void)(({ slop_string _ps_707 = (shape_iri); printf("%.*s", (int)_ps_707.len, _ps_707.data); }));
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
    __auto_type _mv_708 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_708.has_value) {
        __auto_type dg = _mv_708.value;
        __auto_type _mv_709 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_709.has_value) {
            __auto_type sg = _mv_709.value;
            __auto_type _mv_710 = snarl_validate(arena, dg, sg);
            switch (_mv_710.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_710.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if (actual_count == expected_count) {
                            printf("%s", "  PASS: ");
                            ({ slop_string _ps_711 = (data_path); printf("%.*s", (int)_ps_711.len, _ps_711.data); });
                            printf("%s", " has ");
                            ({ slop_string _ps_712 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_712.len, _ps_712.data); });
                            printf("%s\n", " violation(s)");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            ({ slop_string _ps_713 = (data_path); printf("%.*s", (int)_ps_713.len, _ps_713.data); });
                            printf("%s", " expected ");
                            ({ slop_string _ps_714 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_714.len, _ps_714.data); });
                            printf("%s", " violation(s) but got ");
                            ({ slop_string _ps_715 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_715.len, _ps_715.data); });
                            return 0;
                        }
                    }
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_710.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    ({ slop_string _ps_716 = (msg); printf("%.*s\n", (int)_ps_716.len, _ps_716.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_709.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_717 = (shapes_path); printf("%.*s\n", (int)_ps_717.len, _ps_717.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_708.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_718 = (data_path); printf("%.*s\n", (int)_ps_718.len, _ps_718.data); });
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
        __auto_type _mv_720 = slop_rdf_ttl_parse_ttl_file_for_each_triple(arena, path, ({ snarl_cli_tests_test_cli__lambda_719_env_t* snarl_cli_tests_test_cli__lambda_719_env = (snarl_cli_tests_test_cli__lambda_719_env_t*)slop_arena_alloc(arena, sizeof(snarl_cli_tests_test_cli__lambda_719_env_t)); *snarl_cli_tests_test_cli__lambda_719_env = (snarl_cli_tests_test_cli__lambda_719_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)snarl_cli_tests_test_cli__lambda_719, (void*)snarl_cli_tests_test_cli__lambda_719_env }; }));
        if (_mv_720.is_ok) {
            __auto_type _ = _mv_720.data.ok;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        } else if (!_mv_720.is_ok) {
            __auto_type _ = _mv_720.data.err;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
}

int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r) {
    __auto_type _mv_721 = r;
    switch (_mv_721.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_721.data.validate_success;
            if (snarl_types_report_conforms(report)) {
                return snarl_get_result_count(report);
            } else {
                return (1000000 + snarl_get_result_count(report));
            }
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_721.data.validate_error;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_722 = snarl_cli_tests_test_cli_load_streamed_data_graph(arena, data_path);
    if (!_mv_722.has_value) {
        printf("%s", "  FAIL: could not stream ");
        ({ slop_string _ps_723 = (data_path); printf("%.*s\n", (int)_ps_723.len, _ps_723.data); });
        return 0;
    } else if (_mv_722.has_value) {
        __auto_type dg = _mv_722.value;
        __auto_type _mv_724 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
        if (!_mv_724.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_725 = (data_path); printf("%.*s\n", (int)_ps_725.len, _ps_725.data); });
            return 0;
        } else if (_mv_724.has_value) {
            __auto_type ig = _mv_724.value;
            __auto_type _mv_726 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
            if (!_mv_726.has_value) {
                printf("%s", "  FAIL: could not load ");
                ({ slop_string _ps_727 = (shapes_path); printf("%.*s\n", (int)_ps_727.len, _ps_727.data); });
                return 0;
            } else if (_mv_726.has_value) {
                __auto_type sg = _mv_726.value;
                {
                    __auto_type config = snarl_default_config();
                    __auto_type streamed = snarl_cli_tests_test_cli_result_summary(snarl_validate_data_graph_with_config(arena, dg, sg, config));
                    __auto_type indexed = snarl_cli_tests_test_cli_result_summary(snarl_validate_with_config(arena, ig, sg, config));
                    if ((snarl_data_graph_size(dg) == rdf_indexed_graph_size(ig)) && ((streamed >= 0) && (streamed == indexed))) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_728 = (data_path); printf("%.*s", (int)_ps_728.len, _ps_728.data); });
                        printf("%s\n", " streams to the same graph and report");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_729 = (data_path); printf("%.*s", (int)_ps_729.len, _ps_729.data); });
                        printf("%s", " streamed size/summary ");
                        ({ slop_string _ps_730 = (int_to_string(arena, snarl_data_graph_size(dg))); printf("%.*s", (int)_ps_730.len, _ps_730.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_731 = (int_to_string(arena, streamed)); printf("%.*s", (int)_ps_731.len, _ps_731.data); });
                        printf("%s", " vs indexed ");
                        ({ slop_string _ps_732 = (int_to_string(arena, rdf_indexed_graph_size(ig))); printf("%.*s", (int)_ps_732.len, _ps_732.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_733 = (int_to_string(arena, indexed)); printf("%.*s\n", (int)_ps_733.len, _ps_733.data); });
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
    __auto_type _mv_734 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_734.has_value) {
        __auto_type g = _mv_734.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if ((size == 17) && snarl_conforms(arena, g, g)) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                ({ slop_string _ps_735 = (int_to_string(arena, size)); printf("%.*s\n", (int)_ps_735.len, _ps_735.data); });
                return 0;
            }
        }
    } else if (!_mv_734.has_value) {
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
    __auto_type _mv_736 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_736.has_value) {
        __auto_type g = _mv_736.value;
        __auto_type _mv_737 = snarl_validate(arena, g, g);
        switch (_mv_737.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_737.data.validate_success;
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
                __auto_type _ = _mv_737.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_736.has_value) {
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
    __auto_type _mv_738 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-data.ttl"));
    if (_mv_738.has_value) {
        __auto_type dg = _mv_738.value;
        __auto_type _mv_739 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-shapes.ttl"));
        if (_mv_739.has_value) {
            __auto_type sg = _mv_739.value;
            {
                __auto_type config = ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 1, .include_warnings = 1, .include_infos = 1});
                __auto_type _mv_740 = snarl_validate_with_config(arena, dg, sg, config);
                switch (_mv_740.tag) {
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_740.data.validate_error;
                        if (std_strlib_contains(msg, SLOP_STR("Shape recursion"))) {
                            printf("%s\n", "  PASS: max-errors=1 still surfaces the engine error");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: max-errors=1 error message did not contain 'Shape recursion': ");
                            ({ slop_string _ps_741 = (msg); printf("%.*s\n", (int)_ps_741.len, _ps_741.data); });
                            return 0;
                        }
                    }
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_740.data.validate_success;
                        printf("%s\n", "  FAIL: max-errors=1 silently truncated the engine error into a success report");
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_739.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-shapes.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_738.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-data.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-scale-acyclic-3000.ttl"), SLOP_STR("depth budget"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena) {
    __auto_type _mv_742 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-scale-cyclic-1000.ttl"));
    if (_mv_742.has_value) {
        __auto_type g = _mv_742.value;
        __auto_type _mv_743 = snarl_validate(arena, g, g);
        switch (_mv_743.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_743.data.validate_error;
                printf("%s", "  PASS: fixtures/cycle-scale-cyclic-1000.ttl engine error: ");
                ({ slop_string _ps_744 = (msg); printf("%.*s\n", (int)_ps_744.len, _ps_744.data); });
                return 1;
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_743.data.validate_success;
                printf("%s\n", "  FAIL: fixtures/cycle-scale-cyclic-1000.ttl expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_742.has_value) {
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
    __auto_type _mv_745 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_745.is_ok) {
        __auto_type g = _mv_745.data.ok;
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
    } else if (!_mv_745.is_ok) {
        __auto_type _ = _mv_745.data.err;
        return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

snarl_types_ValidatorConfig snarl_cli_tests_test_cli_af_config(uint8_t run_rules, uint8_t shacl12) {
    return ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 0, .include_warnings = 1, .include_infos = 1, .run_rules = run_rules, .shacl12 = shacl12});
}

uint8_t snarl_cli_tests_test_cli_assert_inference(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_violations) {
    __auto_type _mv_746 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_746.has_value) {
        __auto_type dg = _mv_746.value;
        __auto_type _mv_747 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_747.has_value) {
            __auto_type sg = _mv_747.value;
            {
                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, dg, sg, config);
                __auto_type inferred = ((int64_t)((outcome.inferred).len));
                __auto_type _mv_748 = outcome.result;
                switch (_mv_748.tag) {
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type report = _mv_748.data.validate_success;
                        {
                            __auto_type violations = ((int64_t)((snarl_get_violations(arena, report)).len));
                            if ((inferred == expected_inferred) && (violations == expected_violations)) {
                                printf("%s", "  PASS: ");
                                ({ slop_string _ps_749 = (path); printf("%.*s", (int)_ps_749.len, _ps_749.data); });
                                printf("%s", " inferred ");
                                ({ slop_string _ps_750 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_750.len, _ps_750.data); });
                                printf("%s", " triple(s), ");
                                ({ slop_string _ps_751 = (int_to_string(arena, violations)); printf("%.*s", (int)_ps_751.len, _ps_751.data); });
                                printf("%s\n", " violation(s)");
                                return 1;
                            } else {
                                printf("%s", "  FAIL: ");
                                ({ slop_string _ps_752 = (path); printf("%.*s", (int)_ps_752.len, _ps_752.data); });
                                printf("%s", " expected ");
                                ({ slop_string _ps_753 = (int_to_string(arena, expected_inferred)); printf("%.*s", (int)_ps_753.len, _ps_753.data); });
                                printf("%s", " inferred / ");
                                ({ slop_string _ps_754 = (int_to_string(arena, expected_violations)); printf("%.*s", (int)_ps_754.len, _ps_754.data); });
                                printf("%s", " violation(s), got ");
                                ({ slop_string _ps_755 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_755.len, _ps_755.data); });
                                printf("%s", " / ");
                                ({ slop_string _ps_756 = (int_to_string(arena, violations)); printf("%.*s\n", (int)_ps_756.len, _ps_756.data); });
                                return 0;
                            }
                        }
                    }
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_748.data.validate_error;
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_757 = (path); printf("%.*s", (int)_ps_757.len, _ps_757.data); });
                        printf("%s", " validation error: ");
                        ({ slop_string _ps_758 = (msg); printf("%.*s\n", (int)_ps_758.len, _ps_758.data); });
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_747.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_759 = (path); printf("%.*s\n", (int)_ps_759.len, _ps_759.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_746.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_760 = (path); printf("%.*s\n", (int)_ps_760.len, _ps_760.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_af_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring) {
    __auto_type _mv_761 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_761.has_value) {
        __auto_type dg = _mv_761.value;
        __auto_type _mv_762 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_762.has_value) {
            __auto_type sg = _mv_762.value;
            __auto_type _mv_763 = snarl_validate_data_graph_with_inference(arena, dg, sg, config).result;
            switch (_mv_763.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_763.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_764 = (path); printf("%.*s", (int)_ps_764.len, _ps_764.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_765 = (msg); printf("%.*s\n", (int)_ps_765.len, _ps_765.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_766 = (path); printf("%.*s", (int)_ps_766.len, _ps_766.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_767 = (expected_substring); printf("%.*s", (int)_ps_767.len, _ps_767.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_768 = (msg); printf("%.*s\n", (int)_ps_768.len, _ps_768.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_763.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_769 = (path); printf("%.*s", (int)_ps_769.len, _ps_769.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_762.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_770 = (path); printf("%.*s\n", (int)_ps_770.len, _ps_770.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_761.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_771 = (path); printf("%.*s\n", (int)_ps_771.len, _ps_771.data); });
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
    __auto_type _mv_772 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_772.has_value) {
        __auto_type g = _mv_772.value;
        __auto_type _mv_773 = snarl_validate(arena, g, g);
        switch (_mv_773.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_773.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if ((std_strlib_contains(text, SLOP_STR("Source constraint: "))) && (std_strlib_contains(text, SLOP_STR("Person must be verified"))) && (std_strlib_contains(text, SLOP_STR("ExpressionConstraintComponent")))) {
                        printf("%s\n", "  PASS: sh:expression results carry sourceConstraint and message");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: sh:expression report is missing sourceConstraint or message:\n");
                        ({ slop_string _ps_774 = (text); printf("%.*s\n", (int)_ps_774.len, _ps_774.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_773.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_775 = (msg); printf("%.*s\n", (int)_ps_775.len, _ps_775.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_772.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-expression.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_af_report_blank_nodes(slop_arena* arena) {
    __auto_type _mv_776 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_776.has_value) {
        __auto_type g = _mv_776.value;
        __auto_type _mv_777 = snarl_validate(arena, g, g);
        switch (_mv_777.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_777.data.validate_success;
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
                        ({ slop_string _ps_778 = (int_to_string(arena, clashes)); printf("%.*s", (int)_ps_778.len, _ps_778.data); });
                        printf("%s", " of ");
                        ({ slop_string _ps_779 = (int_to_string(arena, seen)); printf("%.*s", (int)_ps_779.len, _ps_779.data); });
                        printf("%s\n", " sh:sourceConstraint values are report nodes");
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_777.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_780 = (msg); printf("%.*s\n", (int)_ps_780.len, _ps_780.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_776.has_value) {
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

slop_option_string snarl_cli_tests_test_cli_report_text(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_781 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_781.has_value) {
        __auto_type dg = _mv_781.value;
        __auto_type _mv_782 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_782.has_value) {
            __auto_type sg = _mv_782.value;
            __auto_type _mv_783 = snarl_validate(arena, dg, sg);
            switch (_mv_783.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_783.data.validate_success;
                    return (slop_option_string){.has_value = 1, .value = snarl_report_to_string(arena, report)};
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_783.data.validate_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_784 = (shapes_path); printf("%.*s", (int)_ps_784.len, _ps_784.data); });
                    printf("%s", " engine error: ");
                    ({ slop_string _ps_785 = (msg); printf("%.*s\n", (int)_ps_785.len, _ps_785.data); });
                    return (slop_option_string){.has_value = false};
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_782.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_786 = (shapes_path); printf("%.*s\n", (int)_ps_786.len, _ps_786.data); });
            return (slop_option_string){.has_value = false};
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_781.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_787 = (data_path); printf("%.*s\n", (int)_ps_787.len, _ps_787.data); });
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_same_report(slop_arena* arena, slop_string data_path, slop_string shapes_a, slop_string shapes_b, slop_string expected_marker) {
    __auto_type _mv_788 = snarl_cli_tests_test_cli_report_text(arena, data_path, shapes_a);
    if (_mv_788.has_value) {
        __auto_type a = _mv_788.value;
        __auto_type _mv_789 = snarl_cli_tests_test_cli_report_text(arena, data_path, shapes_b);
        if (_mv_789.has_value) {
            __auto_type b = _mv_789.value;
            if (string_eq(a, b) && std_strlib_contains(a, expected_marker)) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_790 = (data_path); printf("%.*s", (int)_ps_790.len, _ps_790.data); });
                printf("%s", " validates the same against ");
                ({ slop_string _ps_791 = (shapes_a); printf("%.*s", (int)_ps_791.len, _ps_791.data); });
                printf("%s", " and ");
                ({ slop_string _ps_792 = (shapes_b); printf("%.*s\n", (int)_ps_792.len, _ps_792.data); });
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_793 = (data_path); printf("%.*s", (int)_ps_793.len, _ps_793.data); });
                printf("%s", " reports differ, or lack '");
                ({ slop_string _ps_794 = (expected_marker); printf("%.*s", (int)_ps_794.len, _ps_794.data); });
                printf("%s", "':\n");
                ({ slop_string _ps_795 = (a); printf("%.*s\n", (int)_ps_795.len, _ps_795.data); });
                ({ slop_string _ps_796 = (b); printf("%.*s\n", (int)_ps_796.len, _ps_796.data); });
                return 0;
            }
        } else if (!_mv_789.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_788.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_sparql_rule_validate_only_violates(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_same_report(arena, SLOP_STR("fixtures/af-sparql-data-bad.ttl"), SLOP_STR("fixtures/af-sparql-shapes.ttl"), SLOP_STR("fixtures/af-sparql-shapes-norules.ttl"), SLOP_STR("MinCountConstraintComponent"));
}

uint8_t snarl_cli_tests_test_cli_test_sparql_rule_validate_only_conforms(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_same_report(arena, SLOP_STR("fixtures/af-sparql-data-ok.ttl"), SLOP_STR("fixtures/af-sparql-shapes.ttl"), SLOP_STR("fixtures/af-sparql-shapes-norules.ttl"), SLOP_STR("CONFORMS"));
}

uint8_t snarl_cli_tests_test_cli_test_sparql_rule_run_rules_fails(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-sparql-shapes.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), SLOP_STR("sh:SPARQLRule"));
}

uint8_t snarl_cli_tests_test_cli_test_sparql_rule_entailment_fails(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af-sparql-entailment.ttl"), snarl_cli_tests_test_cli_af_config(0, 0), SLOP_STR("sh:SPARQLRule"));
}

uint8_t snarl_cli_tests_test_cli_test_af12_rules_validate_only(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af12-rules-validate-only.ttl"), snarl_cli_tests_test_cli_af_config(0, 1), 0, 0);
}

uint8_t snarl_cli_tests_test_cli_test_af12_rules_run_fails(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_af_error(arena, SLOP_STR("fixtures/af12-rules-validate-only.ttl"), snarl_cli_tests_test_cli_af_config(1, 1), SLOP_STR("not supported"));
}

snarl_types_ValidatorConfig snarl_cli_tests_test_cli_rule_config(uint8_t run_rules, uint8_t shacl12, uint8_t defer, slop_option_snarl_types_RuleOrder order_min, slop_option_snarl_types_RuleOrder order_max) {
    return ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 0, .include_warnings = 1, .include_infos = 1, .run_rules = run_rules, .shacl12 = shacl12, .defer_sparql_rules = defer, .order_min = order_min, .order_max = order_max});
}

slop_option_snarl_types_RuleOrder snarl_cli_tests_test_cli_order_key(double shape_order, double rule_order) {
    return (slop_option_snarl_types_RuleOrder){.has_value = 1, .value = ((snarl_types_RuleOrder){.shape_order = shape_order, .rule_order = rule_order})};
}

slop_option_snarl_types_RuleOrder snarl_cli_tests_test_cli_no_order(void) {
    return (slop_option_snarl_types_RuleOrder){.has_value = false};
}

slop_rdf_rdf_Term snarl_cli_tests_test_cli_ex_iri(slop_arena* arena, slop_string local) {
    return rdf_make_iri(arena, string_concat(arena, SLOP_STR("http://example.org/"), local));
}

uint8_t snarl_cli_tests_test_cli_has_inferred(slop_arena* arena, slop_list_snarl_rules_InferredTriple inferred, slop_string s, slop_string p, slop_rdf_rdf_Term o, slop_string rule, slop_string focus) {
    {
        __auto_type want = rdf_make_triple(arena, snarl_cli_tests_test_cli_ex_iri(arena, s), snarl_cli_tests_test_cli_ex_iri(arena, p), o);
        int64_t hits = 0;
        int64_t right = 0;
        {
            __auto_type _coll = inferred;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (rdf_term_eq(it.triple.subject, want.subject) && (rdf_term_eq(it.triple.predicate, want.predicate) && rdf_term_eq(it.triple.object, want.object))) {
                    hits = (hits + 1);
                    if (rdf_term_eq(it.rule, snarl_cli_tests_test_cli_ex_iri(arena, rule)) && rdf_term_eq(it.focus_node, snarl_cli_tests_test_cli_ex_iri(arena, focus))) {
                        right = (right + 1);
                    }
                }
            }
        }
        return ((hits == 1) && (right == 1));
    }
}

int64_t snarl_cli_tests_test_cli_infer_count(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config) {
    __auto_type _mv_797 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_797.has_value) {
        __auto_type dg = _mv_797.value;
        __auto_type _mv_798 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_798.has_value) {
            __auto_type sg = _mv_798.value;
            __auto_type _mv_799 = snarl_infer(arena, dg, sg, config);
            switch (_mv_799.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_799.data.infer_success;
                    return ((int64_t)((out.inferred).len));
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_799.data.infer_error;
                    printf("%s", "  infer error: ");
                    ({ slop_string _ps_800 = (msg); printf("%.*s\n", (int)_ps_800.len, _ps_800.data); });
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_798.has_value) {
            return -1;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_797.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_infer_count(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected) {
    {
        __auto_type got = snarl_cli_tests_test_cli_infer_count(arena, path, config);
        if (got == expected) {
            printf("%s", "  PASS: ");
            (void)(({ slop_string _ps_801 = (label); printf("%.*s", (int)_ps_801.len, _ps_801.data); }));
            printf("%s", ": ");
            (void)(({ slop_string _ps_802 = (int_to_string(arena, got)); printf("%.*s", (int)_ps_802.len, _ps_802.data); }));
            printf("%s\n", " inferred");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            (void)(({ slop_string _ps_803 = (label); printf("%.*s", (int)_ps_803.len, _ps_803.data); }));
            printf("%s", ": expected ");
            (void)(({ slop_string _ps_804 = (int_to_string(arena, expected)); printf("%.*s", (int)_ps_804.len, _ps_804.data); }));
            printf("%s", " inferred, got ");
            (void)(({ slop_string _ps_805 = (int_to_string(arena, got)); printf("%.*s\n", (int)_ps_805.len, _ps_805.data); }));
            return 0;
        }
    }
}

uint8_t snarl_cli_tests_test_cli_assert_infer_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring) {
    __auto_type _mv_806 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_806.has_value) {
        __auto_type dg = _mv_806.value;
        __auto_type _mv_807 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_807.has_value) {
            __auto_type sg = _mv_807.value;
            __auto_type _mv_808 = snarl_infer(arena, dg, sg, config);
            switch (_mv_808.tag) {
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_808.data.infer_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_809 = (path); printf("%.*s", (int)_ps_809.len, _ps_809.data); });
                        printf("%s", " infer error: ");
                        ({ slop_string _ps_810 = (msg); printf("%.*s\n", (int)_ps_810.len, _ps_810.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_811 = (path); printf("%.*s", (int)_ps_811.len, _ps_811.data); });
                        printf("%s", " infer error did not contain '");
                        ({ slop_string _ps_812 = (expected_substring); printf("%.*s", (int)_ps_812.len, _ps_812.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_813 = (msg); printf("%.*s\n", (int)_ps_813.len, _ps_813.data); });
                        return 0;
                    }
                }
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type _ = _mv_808.data.infer_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_814 = (path); printf("%.*s", (int)_ps_814.len, _ps_814.data); });
                    printf("%s\n", " expected an infer error but inference succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_807.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_815 = (path); printf("%.*s\n", (int)_ps_815.len, _ps_815.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_806.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_816 = (path); printf("%.*s\n", (int)_ps_816.len, _ps_816.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_deferred(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_deferred, slop_string rule, slop_string shape, double shape_order, double rule_order) {
    __auto_type _mv_817 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_817.has_value) {
        __auto_type dg = _mv_817.value;
        __auto_type _mv_818 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_818.has_value) {
            __auto_type sg = _mv_818.value;
            __auto_type _mv_819 = snarl_infer(arena, dg, sg, config);
            switch (_mv_819.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_819.data.infer_success;
                    {
                        uint8_t ok = ((((int64_t)((out.inferred).len)) == expected_inferred) && (((int64_t)((out.deferred).len)) == expected_deferred));
                        if (ok && (expected_deferred > 0)) {
                            __auto_type _mv_820 = ({ __auto_type _lst = out.deferred; size_t _idx = (size_t)0; slop_option_snarl_rules_DeferredRule _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                            if (_mv_820.has_value) {
                                __auto_type d = _mv_820.value;
                                if (!(((rdf_term_eq(d.rule, snarl_cli_tests_test_cli_ex_iri(arena, rule)) && rdf_term_eq(d.shape, snarl_cli_tests_test_cli_ex_iri(arena, shape))) && ((d.order.shape_order == shape_order) && (d.order.rule_order == rule_order))))) {
                                    ok = 0;
                                }
                            } else if (!_mv_820.has_value) {
                                ok = 0;
                            }
                        }
                        if (ok) {
                            printf("%s", "  PASS: ");
                            ({ slop_string _ps_821 = (label); printf("%.*s", (int)_ps_821.len, _ps_821.data); });
                            printf("%s", ": ");
                            ({ slop_string _ps_822 = (int_to_string(arena, ((int64_t)((out.inferred).len)))); printf("%.*s", (int)_ps_822.len, _ps_822.data); });
                            printf("%s", " inferred, ");
                            ({ slop_string _ps_823 = (int_to_string(arena, ((int64_t)((out.deferred).len)))); printf("%.*s", (int)_ps_823.len, _ps_823.data); });
                            printf("%s\n", " deferred");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            ({ slop_string _ps_824 = (label); printf("%.*s", (int)_ps_824.len, _ps_824.data); });
                            printf("%s", ": got ");
                            ({ slop_string _ps_825 = (int_to_string(arena, ((int64_t)((out.inferred).len)))); printf("%.*s", (int)_ps_825.len, _ps_825.data); });
                            printf("%s", " inferred, ");
                            ({ slop_string _ps_826 = (int_to_string(arena, ((int64_t)((out.deferred).len)))); printf("%.*s", (int)_ps_826.len, _ps_826.data); });
                            printf("%s\n", " deferred, or the deferred rule is not the expected one");
                            return 0;
                        }
                    }
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_819.data.infer_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_827 = (label); printf("%.*s", (int)_ps_827.len, _ps_827.data); });
                    printf("%s", " infer error: ");
                    ({ slop_string _ps_828 = (msg); printf("%.*s\n", (int)_ps_828.len, _ps_828.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_818.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_829 = (path); printf("%.*s\n", (int)_ps_829.len, _ps_829.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_817.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_830 = (path); printf("%.*s\n", (int)_ps_830.len, _ps_830.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_defer_sparql_rules(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_deferred(arena, SLOP_STR("defer-sparql-rules"), SLOP_STR("fixtures/af-defer-sparql.ttl"), snarl_cli_tests_test_cli_rule_config(1, 0, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()), 2, 1, SLOP_STR("SparqlRule"), SLOP_STR("NodeShape"), 3.0, 2.0);
}

uint8_t snarl_cli_tests_test_cli_test_defer_sparql_rules_shacl12(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_deferred(arena, SLOP_STR("defer-sparql-rules, shacl12"), SLOP_STR("fixtures/af-defer-sparql.ttl"), snarl_cli_tests_test_cli_rule_config(1, 1, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()), 2, 1, SLOP_STR("SparqlRule"), SLOP_STR("NodeShape"), 0.0, 2.0);
}

uint8_t snarl_cli_tests_test_cli_test_defer_off_fails(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_infer_error(arena, SLOP_STR("fixtures/af-defer-sparql.ttl"), snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()), SLOP_STR("sh:SPARQLRule at http://example.org/SparqlRule is not supported"));
}

uint8_t snarl_cli_tests_test_cli_test_defer_unknown_rule_type_fails(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_infer_error(arena, SLOP_STR("fixtures/af-unknown-rule-type.ttl"), snarl_cli_tests_test_cli_rule_config(1, 0, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()), SLOP_STR("Unsupported SHACL rule type"));
}

uint8_t snarl_cli_tests_test_cli_test_defer_follows_order_range(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_deferred(arena, SLOP_STR("defer-sparql-rules, range below the SPARQL rule"), SLOP_STR("fixtures/af-defer-sparql.ttl"), snarl_cli_tests_test_cli_rule_config(1, 0, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(3.0, 1.0)), 1, 0, SLOP_STR(""), SLOP_STR(""), 0.0, 0.0);
}

uint8_t snarl_cli_tests_test_cli_test_defer_validate_entailment(slop_arena* arena) {
    __auto_type _mv_831 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-sparql-entailment.ttl"));
    if (_mv_831.has_value) {
        __auto_type dg = _mv_831.value;
        __auto_type _mv_832 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-sparql-entailment.ttl"));
        if (_mv_832.has_value) {
            __auto_type sg = _mv_832.value;
            {
                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(0, 0, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()));
                __auto_type _mv_833 = outcome.result;
                switch (_mv_833.tag) {
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_833.data.validate_success;
                        if ((((int64_t)((outcome.inferred).len)) == 1) && ((((int64_t)((outcome.deferred).len)) == 1) && ({ __auto_type _mv = ({ __auto_type _lst = outcome.deferred; size_t _idx = (size_t)0; slop_option_snarl_rules_DeferredRule _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type d = _mv.value; rdf_term_eq(d.rule, snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("SparqlRule"))); }) : (0); }))) {
                            printf("%s\n", "  PASS: validation with deferral reports the SPARQL rule in the outcome");
                            return 1;
                        } else {
                            printf("%s\n", "  FAIL: validation with deferral: wrong inferred or deferred lists");
                            return 0;
                        }
                    }
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_833.data.validate_error;
                        printf("%s", "  FAIL: validation with deferral: ");
                        ({ slop_string _ps_834 = (msg); printf("%.*s\n", (int)_ps_834.len, _ps_834.data); });
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_832.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-sparql-entailment.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_831.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-sparql-entailment.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_order_range_bounds(slop_arena* arena) {
    {
        __auto_type f = SLOP_STR("fixtures/af-order-range.ttl");
        uint8_t ok = 1;
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("no range: a b d e"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()), 4))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("max (0,1): a"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(0.0, 1.0)), 1))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("max (0,2): a b"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(0.0, 2.0)), 2))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("(0,1)..(0,2): a b"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, 1.0), snarl_cli_tests_test_cli_order_key(0.0, 2.0)), 2))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("max (0,3): a b d"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(0.0, 3.0)), 3))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("(0,2)..(0,2) on a fresh graph: nothing has ex:a"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, 2.0), snarl_cli_tests_test_cli_order_key(0.0, 2.0)), 0))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("min (0,2): only e, at (1,0)"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, 2.0), snarl_cli_tests_test_cli_no_order()), 1))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("min (1,0): e"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(1.0, 0.0), snarl_cli_tests_test_cli_no_order()), 1))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("max (0,0): nothing"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(0.0, 0.0)), 0))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("empty range (0,3)..(0,1)"), f, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, 3.0), snarl_cli_tests_test_cli_order_key(0.0, 1.0)), 0))) {
            ok = 0;
        }
        if (!(snarl_cli_tests_test_cli_assert_infer_count(arena, SLOP_STR("shacl12, max (0,0): e, whose key is then (0,0)"), f, snarl_cli_tests_test_cli_rule_config(1, 1, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_order_key(0.0, 0.0)), 1))) {
            ok = 0;
        }
        return ok;
    }
}

slop_option_snarl_rules_InferOutput snarl_cli_tests_test_cli_infer_step(slop_arena* arena, snarl_data_graph_SnarlDataGraph dg, slop_rdf_index_IndexedGraph sg, double lo, double hi) {
    __auto_type _mv_835 = snarl_infer(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, lo), snarl_cli_tests_test_cli_order_key(0.0, hi)));
    switch (_mv_835.tag) {
        case snarl_rules_InferResult_infer_success:
        {
            __auto_type out = _mv_835.data.infer_success;
            return (slop_option_snarl_rules_InferOutput){.has_value = 1, .value = out};
        }
        case snarl_rules_InferResult_infer_error:
        {
            __auto_type msg = _mv_835.data.infer_error;
            printf("%s", "  infer error: ");
            ({ slop_string _ps_836 = (msg); printf("%.*s\n", (int)_ps_836.len, _ps_836.data); });
            return (slop_option_snarl_rules_InferOutput){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_order_range_stepping(slop_arena* arena) {
    __auto_type _mv_837 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-order-range.ttl"));
    if (_mv_837.has_value) {
        __auto_type dg0 = _mv_837.value;
        __auto_type _mv_838 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-order-range.ttl"));
        if (_mv_838.has_value) {
            __auto_type sg = _mv_838.value;
            {
                __auto_type t = rdf_make_literal(arena, SLOP_STR("true"), (slop_option_string){.has_value = 1, .value = SLOP_STR("http://www.w3.org/2001/XMLSchema#boolean")}, ((slop_option_string){.has_value = false}));
                uint8_t ok = 1;
                __auto_type dg = dg0;
                __auto_type _mv_839 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 1.0, 1.0);
                if (_mv_839.has_value) {
                    __auto_type out = _mv_839.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("a"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_839.has_value) {
                    ok = 0;
                }
                __auto_type _mv_840 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 2.0, 2.0);
                if (_mv_840.has_value) {
                    __auto_type out = _mv_840.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("b"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_840.has_value) {
                    ok = 0;
                }
                __auto_type _mv_841 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 3.0, 3.0);
                if (_mv_841.has_value) {
                    __auto_type out = _mv_841.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("d"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_841.has_value) {
                    ok = 0;
                }
                __auto_type _mv_842 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 2.0, 2.0);
                if (_mv_842.has_value) {
                    __auto_type out = _mv_842.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("c"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_842.has_value) {
                    ok = 0;
                }
                if (ok) {
                    printf("%s\n", "  PASS: stepping levels 1, 2, 3, 2 infers a, b, d, c");
                    return 1;
                } else {
                    printf("%s\n", "  FAIL: stepping levels 1, 2, 3, 2 did not infer a, b, d, c one at a time");
                    return 0;
                }
            }
        } else if (!_mv_838.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-order-range.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_837.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-order-range.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_triple_inferred(slop_arena* arena, slop_list_snarl_rules_InferredTriple inferred, slop_string s, slop_string p, slop_rdf_rdf_Term o) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = inferred;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (rdf_term_eq(it.triple.subject, snarl_cli_tests_test_cli_ex_iri(arena, s)) && (rdf_term_eq(it.triple.predicate, snarl_cli_tests_test_cli_ex_iri(arena, p)) && rdf_term_eq(it.triple.object, o))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t snarl_cli_tests_test_cli_test_attribution(slop_arena* arena) {
    __auto_type _mv_843 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-attribution.ttl"));
    if (_mv_843.has_value) {
        __auto_type dg = _mv_843.value;
        __auto_type _mv_844 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-attribution.ttl"));
        if (_mv_844.has_value) {
            __auto_type sg = _mv_844.value;
            __auto_type _mv_845 = snarl_infer(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()));
            switch (_mv_845.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_845.data.infer_success;
                    {
                        __auto_type inf = out.inferred;
                        if ((((int64_t)((inf).len)) == 5) && ((snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n1"), SLOP_STR("p"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("v")), SLOP_STR("RuleA"), SLOP_STR("n1")) && snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n2"), SLOP_STR("p"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("v")), SLOP_STR("RuleA"), SLOP_STR("n2"))) && ((snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n1"), SLOP_STR("q"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("w")), SLOP_STR("RuleB"), SLOP_STR("n1")) && snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n2"), SLOP_STR("q"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("w")), SLOP_STR("RuleB"), SLOP_STR("n2"))) && (snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("shared"), SLOP_STR("from"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("k")), SLOP_STR("RuleD"), SLOP_STR("n1")) && ({ __auto_type _mv = ({ __auto_type _lst = inf; size_t _idx = (size_t)0; slop_option_snarl_rules_InferredTriple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type first = _mv.value; rdf_term_eq(first.rule, snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("RuleA"))); }) : (0); }))))) {
                            printf("%s\n", "  PASS: each inferred triple names its rule and focus node");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: attribution: ");
                            ({ slop_string _ps_846 = (int_to_string(arena, ((int64_t)((inf).len)))); printf("%.*s", (int)_ps_846.len, _ps_846.data); });
                            printf("%s\n", " inferred, or a wrong rule or focus node");
                            {
                                __auto_type _coll = inf;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type it = _coll.data[_i];
                                    printf("%s", "    ");
                                    ({ slop_string _ps_847 = (snarl_cli_tests_test_cli_term_display(arena, it.triple.subject)); printf("%.*s", (int)_ps_847.len, _ps_847.data); });
                                    printf("%s", " ");
                                    ({ slop_string _ps_848 = (snarl_cli_tests_test_cli_term_display(arena, it.triple.predicate)); printf("%.*s", (int)_ps_848.len, _ps_848.data); });
                                    printf("%s", " by ");
                                    ({ slop_string _ps_849 = (snarl_cli_tests_test_cli_term_display(arena, it.rule)); printf("%.*s", (int)_ps_849.len, _ps_849.data); });
                                    printf("%s", " for ");
                                    ({ slop_string _ps_850 = (snarl_cli_tests_test_cli_term_display(arena, it.focus_node)); printf("%.*s\n", (int)_ps_850.len, _ps_850.data); });
                                }
                            }
                            return 0;
                        }
                    }
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_845.data.infer_error;
                    printf("%s", "  FAIL: attribution: infer error: ");
                    ({ slop_string _ps_851 = (msg); printf("%.*s\n", (int)_ps_851.len, _ps_851.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_844.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-attribution.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_843.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-attribution.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string snarl_cli_tests_test_cli_term_display(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_852 = t;
    switch (_mv_852.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_852.data.term_iri;
            return iri.value;
        }
        default: {
            return SLOP_STR("[non-IRI]");
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
            if (snarl_cli_tests_test_cli_test_sparql_rule_validate_only_violates(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_sparql_rule_validate_only_conforms(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_sparql_rule_run_rules_fails(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_sparql_rule_entailment_fails(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_rules_validate_only(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_af12_rules_run_fails(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_sparql_rules(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_sparql_rules_shacl12(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_off_fails(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_unknown_rule_type_fails(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_follows_order_range(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_defer_validate_entailment(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_order_range_bounds(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_order_range_stepping(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_attribution(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            printf("%s\n", "");
            printf("%s\n", "---");
            (void)(({ slop_string _ps_853 = (int_to_string(arena, passed)); printf("%.*s", (int)_ps_853.len, _ps_853.data); }));
            printf("%s", " passed, ");
            (void)(({ slop_string _ps_854 = (int_to_string(arena, failed)); printf("%.*s", (int)_ps_854.len, _ps_854.data); }));
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

