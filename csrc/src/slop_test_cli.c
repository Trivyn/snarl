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
uint8_t snarl_cli_tests_test_cli_test_rdf12_triple_term_equality(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_rdf12_triple_term_reinfer(slop_arena* arena);
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

typedef struct { snarl_data_graph_SnarlDataGraph* dg; slop_arena* arena; } snarl_cli_tests_test_cli__lambda_732_env_t;

static void snarl_cli_tests_test_cli__lambda_732(snarl_cli_tests_test_cli__lambda_732_env_t* _env, slop_rdf_rdf_Triple t) { ({ (*_env->dg) = snarl_data_graph_add(_env->arena, (*_env->dg), t); (void)0; }); }

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_657 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_657.is_ok) {
        __auto_type g = _mv_657.data.ok;
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
    } else if (!_mv_657.is_ok) {
        __auto_type _ = _mv_657.data.err;
        return (slop_option_slop_rdf_index_IndexedGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_658 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_658.has_value) {
        __auto_type g = _mv_658.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (result) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_659 = (path); printf("%.*s", (int)_ps_659.len, _ps_659.data); });
                printf("%s\n", " conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_660 = (path); printf("%.*s", (int)_ps_660.len, _ps_660.data); });
                printf("%s\n", " expected to conform but got violations");
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

uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_662 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_662.has_value) {
        __auto_type g = _mv_662.value;
        __auto_type _mv_663 = snarl_validate(arena, g, g);
        switch (_mv_663.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_663.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if (actual_count == expected_count) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_664 = (path); printf("%.*s", (int)_ps_664.len, _ps_664.data); });
                        printf("%s", " has ");
                        ({ slop_string _ps_665 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_665.len, _ps_665.data); });
                        printf("%s\n", " violation(s)");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_666 = (path); printf("%.*s", (int)_ps_666.len, _ps_666.data); });
                        printf("%s", " expected ");
                        ({ slop_string _ps_667 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_667.len, _ps_667.data); });
                        printf("%s", " violation(s) but got ");
                        ({ slop_string _ps_668 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_668.len, _ps_668.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_663.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_669 = (msg); printf("%.*s\n", (int)_ps_669.len, _ps_669.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_662.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_670 = (path); printf("%.*s\n", (int)_ps_670.len, _ps_670.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_671 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_671.has_value) {
        __auto_type g = _mv_671.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (!(result)) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_672 = (path); printf("%.*s", (int)_ps_672.len, _ps_672.data); });
                printf("%s\n", " has violations");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_673 = (path); printf("%.*s", (int)_ps_673.len, _ps_673.data); });
                printf("%s\n", " expected violations but conforms");
                return 0;
            }
        }
    } else if (!_mv_671.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_674 = (path); printf("%.*s\n", (int)_ps_674.len, _ps_674.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_675 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_675.has_value) {
        __auto_type dg = _mv_675.value;
        __auto_type _mv_676 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_676.has_value) {
            __auto_type sg = _mv_676.value;
            {
                __auto_type result = snarl_conforms(arena, dg, sg);
                if (result) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_677 = (data_path); printf("%.*s", (int)_ps_677.len, _ps_677.data); });
                    printf("%s\n", " conforms");
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_678 = (data_path); printf("%.*s", (int)_ps_678.len, _ps_678.data); });
                    printf("%s\n", " expected to conform but got violations");
                    return 0;
                }
            }
        } else if (!_mv_676.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_679 = (shapes_path); printf("%.*s\n", (int)_ps_679.len, _ps_679.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_675.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_680 = (data_path); printf("%.*s\n", (int)_ps_680.len, _ps_680.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring) {
    __auto_type _mv_681 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_681.has_value) {
        __auto_type g = _mv_681.value;
        __auto_type _mv_682 = snarl_validate(arena, g, g);
        switch (_mv_682.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_682.data.validate_error;
                if (std_strlib_contains(msg, expected_substring)) {
                    printf("%s", "  PASS: ");
                    ({ slop_string _ps_683 = (path); printf("%.*s", (int)_ps_683.len, _ps_683.data); });
                    printf("%s", " engine error: ");
                    ({ slop_string _ps_684 = (msg); printf("%.*s\n", (int)_ps_684.len, _ps_684.data); });
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_685 = (path); printf("%.*s", (int)_ps_685.len, _ps_685.data); });
                    printf("%s", " engine error message did not contain '");
                    ({ slop_string _ps_686 = (expected_substring); printf("%.*s", (int)_ps_686.len, _ps_686.data); });
                    printf("%s", "': ");
                    ({ slop_string _ps_687 = (msg); printf("%.*s\n", (int)_ps_687.len, _ps_687.data); });
                    return 0;
                }
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_682.data.validate_success;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_688 = (path); printf("%.*s", (int)_ps_688.len, _ps_688.data); });
                printf("%s\n", " expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_681.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_689 = (path); printf("%.*s\n", (int)_ps_689.len, _ps_689.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring) {
    __auto_type _mv_690 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_690.has_value) {
        __auto_type dg = _mv_690.value;
        __auto_type _mv_691 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_691.has_value) {
            __auto_type sg = _mv_691.value;
            __auto_type _mv_692 = snarl_validate(arena, dg, sg);
            switch (_mv_692.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_692.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_693 = (data_path); printf("%.*s", (int)_ps_693.len, _ps_693.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_694 = (msg); printf("%.*s\n", (int)_ps_694.len, _ps_694.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_695 = (data_path); printf("%.*s", (int)_ps_695.len, _ps_695.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_696 = (expected_substring); printf("%.*s", (int)_ps_696.len, _ps_696.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_697 = (msg); printf("%.*s\n", (int)_ps_697.len, _ps_697.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_692.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_698 = (data_path); printf("%.*s", (int)_ps_698.len, _ps_698.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_691.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_699 = (shapes_path); printf("%.*s\n", (int)_ps_699.len, _ps_699.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_690.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_700 = (data_path); printf("%.*s\n", (int)_ps_700.len, _ps_700.data); });
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
    __auto_type _mv_701 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_701.has_value) {
        __auto_type g = _mv_701.value;
        {
            __auto_type objs = rdf_indexed_graph_objects(arena, g, rdf_make_iri(arena, shape_iri), rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH));
            __auto_type _mv_702 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_702.has_value) {
                __auto_type path_node = _mv_702.value;
                return snarl_parse_path_node_eval_depth(arena, g, path_node);
            } else if (!_mv_702.has_value) {
                return -1;
            }
            SLOP_UNREACHABLE();
        }
    } else if (!_mv_701.has_value) {
        return -2;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path) {
    __auto_type _mv_703 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
    if (_mv_703.has_value) {
        __auto_type g = _mv_703.value;
        __auto_type _mv_704 = snarl_validate(arena, g, g);
        switch (_mv_704.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_704.data.validate_success;
                printf("%s", "  PASS: ");
                ({ slop_string _ps_705 = (path); printf("%.*s", (int)_ps_705.len, _ps_705.data); });
                printf("%s\n", " validated (no engine error)");
                return 1;
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_704.data.validate_error;
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_706 = (path); printf("%.*s", (int)_ps_706.len, _ps_706.data); });
                printf("%s", " unexpected engine error: ");
                ({ slop_string _ps_707 = (msg); printf("%.*s\n", (int)_ps_707.len, _ps_707.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_703.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_708 = (path); printf("%.*s\n", (int)_ps_708.len, _ps_708.data); });
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
        __auto_type _mv_709 = snarl_cli_tests_test_cli_load_test_graph(arena, fixture);
        if (_mv_709.has_value) {
            __auto_type g = _mv_709.value;
            __auto_type _mv_710 = snarl_validate(arena, g, g);
            switch (_mv_710.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_710.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_710.data.validate_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_711 = (fixture); printf("%.*s", (int)_ps_711.len, _ps_711.data); });
                    printf("%s", " unexpected engine error: ");
                    ({ slop_string _ps_712 = (msg); printf("%.*s\n", (int)_ps_712.len, _ps_712.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_709.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_713 = (fixture); printf("%.*s\n", (int)_ps_713.len, _ps_713.data); });
            ok = 0;
        }
        if (!((snarl_cli_tests_test_cli_path_depth_of(arena, SLOP_STR("fixtures/path-depth-flat.ttl"), SLOP_STR("http://example.org/NameProp")) == 1))) {
            printf("%s", "  FAIL: flat control depth drifted after ");
            (void)(({ slop_string _ps_714 = (fixture); printf("%.*s\n", (int)_ps_714.len, _ps_714.data); }));
            ok = 0;
        }
        __auto_type _mv_715 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/path-depth-flat.ttl"));
        if (_mv_715.has_value) {
            __auto_type fg = _mv_715.value;
            __auto_type _mv_716 = snarl_validate(arena, fg, fg);
            switch (_mv_716.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_716.data.validate_success;
                    break;
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_716.data.validate_error;
                    printf("%s", "  FAIL: flat control errored after ");
                    ({ slop_string _ps_717 = (fixture); printf("%.*s", (int)_ps_717.len, _ps_717.data); });
                    printf("%s", ": ");
                    ({ slop_string _ps_718 = (msg); printf("%.*s\n", (int)_ps_718.len, _ps_718.data); });
                    ok = 0;
                    break;
                }
            }
        } else if (!_mv_715.has_value) {
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
            (void)(({ slop_string _ps_719 = (shape_iri); printf("%.*s", (int)_ps_719.len, _ps_719.data); }));
            printf("%s", " depth = ");
            printf("%lld", (long long)(actual));
            printf("%s\n", "");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            (void)(({ slop_string _ps_720 = (shape_iri); printf("%.*s", (int)_ps_720.len, _ps_720.data); }));
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
    __auto_type _mv_721 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_721.has_value) {
        __auto_type dg = _mv_721.value;
        __auto_type _mv_722 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_722.has_value) {
            __auto_type sg = _mv_722.value;
            __auto_type _mv_723 = snarl_validate(arena, dg, sg);
            switch (_mv_723.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_723.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if (actual_count == expected_count) {
                            printf("%s", "  PASS: ");
                            ({ slop_string _ps_724 = (data_path); printf("%.*s", (int)_ps_724.len, _ps_724.data); });
                            printf("%s", " has ");
                            ({ slop_string _ps_725 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_725.len, _ps_725.data); });
                            printf("%s\n", " violation(s)");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            ({ slop_string _ps_726 = (data_path); printf("%.*s", (int)_ps_726.len, _ps_726.data); });
                            printf("%s", " expected ");
                            ({ slop_string _ps_727 = (int_to_string(arena, expected_count)); printf("%.*s", (int)_ps_727.len, _ps_727.data); });
                            printf("%s", " violation(s) but got ");
                            ({ slop_string _ps_728 = (int_to_string(arena, actual_count)); printf("%.*s\n", (int)_ps_728.len, _ps_728.data); });
                            return 0;
                        }
                    }
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_723.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    ({ slop_string _ps_729 = (msg); printf("%.*s\n", (int)_ps_729.len, _ps_729.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_722.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            ({ slop_string _ps_730 = (shapes_path); printf("%.*s\n", (int)_ps_730.len, _ps_730.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_721.has_value) {
        printf("%s", "  FAIL: could not load data ");
        ({ slop_string _ps_731 = (data_path); printf("%.*s\n", (int)_ps_731.len, _ps_731.data); });
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
        __auto_type _mv_733 = slop_rdf_ttl_parse_ttl_file_for_each_triple(arena, path, ({ snarl_cli_tests_test_cli__lambda_732_env_t* snarl_cli_tests_test_cli__lambda_732_env = (snarl_cli_tests_test_cli__lambda_732_env_t*)slop_arena_alloc(arena, sizeof(snarl_cli_tests_test_cli__lambda_732_env_t)); *snarl_cli_tests_test_cli__lambda_732_env = (snarl_cli_tests_test_cli__lambda_732_env_t){ .dg = &(dg), .arena = arena }; (slop_closure_t){ (void*)snarl_cli_tests_test_cli__lambda_732, (void*)snarl_cli_tests_test_cli__lambda_732_env }; }));
        if (_mv_733.is_ok) {
            __auto_type _ = _mv_733.data.ok;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = 1, .value = dg};
        } else if (!_mv_733.is_ok) {
            __auto_type _ = _mv_733.data.err;
            return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
}

int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r) {
    __auto_type _mv_734 = r;
    switch (_mv_734.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_734.data.validate_success;
            if (snarl_types_report_conforms(report)) {
                return snarl_get_result_count(report);
            } else {
                return (1000000 + snarl_get_result_count(report));
            }
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_734.data.validate_error;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_735 = snarl_cli_tests_test_cli_load_streamed_data_graph(arena, data_path);
    if (!_mv_735.has_value) {
        printf("%s", "  FAIL: could not stream ");
        ({ slop_string _ps_736 = (data_path); printf("%.*s\n", (int)_ps_736.len, _ps_736.data); });
        return 0;
    } else if (_mv_735.has_value) {
        __auto_type dg = _mv_735.value;
        __auto_type _mv_737 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
        if (!_mv_737.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_738 = (data_path); printf("%.*s\n", (int)_ps_738.len, _ps_738.data); });
            return 0;
        } else if (_mv_737.has_value) {
            __auto_type ig = _mv_737.value;
            __auto_type _mv_739 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
            if (!_mv_739.has_value) {
                printf("%s", "  FAIL: could not load ");
                ({ slop_string _ps_740 = (shapes_path); printf("%.*s\n", (int)_ps_740.len, _ps_740.data); });
                return 0;
            } else if (_mv_739.has_value) {
                __auto_type sg = _mv_739.value;
                {
                    __auto_type config = snarl_default_config();
                    __auto_type streamed = snarl_cli_tests_test_cli_result_summary(snarl_validate_data_graph_with_config(arena, dg, sg, config));
                    __auto_type indexed = snarl_cli_tests_test_cli_result_summary(snarl_validate_with_config(arena, ig, sg, config));
                    if ((snarl_data_graph_size(dg) == rdf_indexed_graph_size(ig)) && ((streamed >= 0) && (streamed == indexed))) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_741 = (data_path); printf("%.*s", (int)_ps_741.len, _ps_741.data); });
                        printf("%s\n", " streams to the same graph and report");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_742 = (data_path); printf("%.*s", (int)_ps_742.len, _ps_742.data); });
                        printf("%s", " streamed size/summary ");
                        ({ slop_string _ps_743 = (int_to_string(arena, snarl_data_graph_size(dg))); printf("%.*s", (int)_ps_743.len, _ps_743.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_744 = (int_to_string(arena, streamed)); printf("%.*s", (int)_ps_744.len, _ps_744.data); });
                        printf("%s", " vs indexed ");
                        ({ slop_string _ps_745 = (int_to_string(arena, rdf_indexed_graph_size(ig))); printf("%.*s", (int)_ps_745.len, _ps_745.data); });
                        printf("%s", "/");
                        ({ slop_string _ps_746 = (int_to_string(arena, indexed)); printf("%.*s\n", (int)_ps_746.len, _ps_746.data); });
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
    __auto_type _mv_747 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_747.has_value) {
        __auto_type g = _mv_747.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if ((size == 17) && snarl_conforms(arena, g, g)) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                ({ slop_string _ps_748 = (int_to_string(arena, size)); printf("%.*s\n", (int)_ps_748.len, _ps_748.data); });
                return 0;
            }
        }
    } else if (!_mv_747.has_value) {
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
    __auto_type _mv_749 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_749.has_value) {
        __auto_type g = _mv_749.value;
        __auto_type _mv_750 = snarl_validate(arena, g, g);
        switch (_mv_750.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_750.data.validate_success;
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
                __auto_type _ = _mv_750.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_749.has_value) {
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
    __auto_type _mv_751 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-data.ttl"));
    if (_mv_751.has_value) {
        __auto_type dg = _mv_751.value;
        __auto_type _mv_752 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-shapes.ttl"));
        if (_mv_752.has_value) {
            __auto_type sg = _mv_752.value;
            {
                __auto_type config = ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 1, .include_warnings = 1, .include_infos = 1});
                __auto_type _mv_753 = snarl_validate_with_config(arena, dg, sg, config);
                switch (_mv_753.tag) {
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_753.data.validate_error;
                        if (std_strlib_contains(msg, SLOP_STR("Shape recursion"))) {
                            printf("%s\n", "  PASS: max-errors=1 still surfaces the engine error");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: max-errors=1 error message did not contain 'Shape recursion': ");
                            ({ slop_string _ps_754 = (msg); printf("%.*s\n", (int)_ps_754.len, _ps_754.data); });
                            return 0;
                        }
                    }
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_753.data.validate_success;
                        printf("%s\n", "  FAIL: max-errors=1 silently truncated the engine error into a success report");
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_752.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-shapes.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_751.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-data.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-scale-acyclic-3000.ttl"), SLOP_STR("depth budget"));
}

uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena) {
    __auto_type _mv_755 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-scale-cyclic-1000.ttl"));
    if (_mv_755.has_value) {
        __auto_type g = _mv_755.value;
        __auto_type _mv_756 = snarl_validate(arena, g, g);
        switch (_mv_756.tag) {
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_756.data.validate_error;
                printf("%s", "  PASS: fixtures/cycle-scale-cyclic-1000.ttl engine error: ");
                ({ slop_string _ps_757 = (msg); printf("%.*s\n", (int)_ps_757.len, _ps_757.data); });
                return 1;
            }
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_756.data.validate_success;
                printf("%s\n", "  FAIL: fixtures/cycle-scale-cyclic-1000.ttl expected engine error but validation succeeded");
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_755.has_value) {
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
    __auto_type _mv_758 = slop_rdf_ttl_parse_ttl_file(arena, path);
    if (_mv_758.is_ok) {
        __auto_type g = _mv_758.data.ok;
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
    } else if (!_mv_758.is_ok) {
        __auto_type _ = _mv_758.data.err;
        return (slop_option_snarl_data_graph_SnarlDataGraph){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

snarl_types_ValidatorConfig snarl_cli_tests_test_cli_af_config(uint8_t run_rules, uint8_t shacl12) {
    return ((snarl_types_ValidatorConfig){.verbose = 0, .max_errors = 0, .include_warnings = 1, .include_infos = 1, .run_rules = run_rules, .shacl12 = shacl12});
}

uint8_t snarl_cli_tests_test_cli_assert_inference(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_violations) {
    __auto_type _mv_759 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_759.has_value) {
        __auto_type dg = _mv_759.value;
        __auto_type _mv_760 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_760.has_value) {
            __auto_type sg = _mv_760.value;
            {
                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, dg, sg, config);
                __auto_type inferred = ((int64_t)((outcome.inferred).len));
                __auto_type _mv_761 = outcome.result;
                switch (_mv_761.tag) {
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type report = _mv_761.data.validate_success;
                        {
                            __auto_type violations = ((int64_t)((snarl_get_violations(arena, report)).len));
                            if ((inferred == expected_inferred) && (violations == expected_violations)) {
                                printf("%s", "  PASS: ");
                                ({ slop_string _ps_762 = (path); printf("%.*s", (int)_ps_762.len, _ps_762.data); });
                                printf("%s", " inferred ");
                                ({ slop_string _ps_763 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_763.len, _ps_763.data); });
                                printf("%s", " triple(s), ");
                                ({ slop_string _ps_764 = (int_to_string(arena, violations)); printf("%.*s", (int)_ps_764.len, _ps_764.data); });
                                printf("%s\n", " violation(s)");
                                return 1;
                            } else {
                                printf("%s", "  FAIL: ");
                                ({ slop_string _ps_765 = (path); printf("%.*s", (int)_ps_765.len, _ps_765.data); });
                                printf("%s", " expected ");
                                ({ slop_string _ps_766 = (int_to_string(arena, expected_inferred)); printf("%.*s", (int)_ps_766.len, _ps_766.data); });
                                printf("%s", " inferred / ");
                                ({ slop_string _ps_767 = (int_to_string(arena, expected_violations)); printf("%.*s", (int)_ps_767.len, _ps_767.data); });
                                printf("%s", " violation(s), got ");
                                ({ slop_string _ps_768 = (int_to_string(arena, inferred)); printf("%.*s", (int)_ps_768.len, _ps_768.data); });
                                printf("%s", " / ");
                                ({ slop_string _ps_769 = (int_to_string(arena, violations)); printf("%.*s\n", (int)_ps_769.len, _ps_769.data); });
                                return 0;
                            }
                        }
                    }
                    case snarl_types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_761.data.validate_error;
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_770 = (path); printf("%.*s", (int)_ps_770.len, _ps_770.data); });
                        printf("%s", " validation error: ");
                        ({ slop_string _ps_771 = (msg); printf("%.*s\n", (int)_ps_771.len, _ps_771.data); });
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_760.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_772 = (path); printf("%.*s\n", (int)_ps_772.len, _ps_772.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_759.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_773 = (path); printf("%.*s\n", (int)_ps_773.len, _ps_773.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_af_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring) {
    __auto_type _mv_774 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_774.has_value) {
        __auto_type dg = _mv_774.value;
        __auto_type _mv_775 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_775.has_value) {
            __auto_type sg = _mv_775.value;
            __auto_type _mv_776 = snarl_validate_data_graph_with_inference(arena, dg, sg, config).result;
            switch (_mv_776.tag) {
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_776.data.validate_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_777 = (path); printf("%.*s", (int)_ps_777.len, _ps_777.data); });
                        printf("%s", " engine error: ");
                        ({ slop_string _ps_778 = (msg); printf("%.*s\n", (int)_ps_778.len, _ps_778.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_779 = (path); printf("%.*s", (int)_ps_779.len, _ps_779.data); });
                        printf("%s", " engine error message did not contain '");
                        ({ slop_string _ps_780 = (expected_substring); printf("%.*s", (int)_ps_780.len, _ps_780.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_781 = (msg); printf("%.*s\n", (int)_ps_781.len, _ps_781.data); });
                        return 0;
                    }
                }
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_776.data.validate_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_782 = (path); printf("%.*s", (int)_ps_782.len, _ps_782.data); });
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_775.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_783 = (path); printf("%.*s\n", (int)_ps_783.len, _ps_783.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_774.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_784 = (path); printf("%.*s\n", (int)_ps_784.len, _ps_784.data); });
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
    __auto_type _mv_785 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_785.has_value) {
        __auto_type g = _mv_785.value;
        __auto_type _mv_786 = snarl_validate(arena, g, g);
        switch (_mv_786.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_786.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if ((std_strlib_contains(text, SLOP_STR("Source constraint: "))) && (std_strlib_contains(text, SLOP_STR("Person must be verified"))) && (std_strlib_contains(text, SLOP_STR("ExpressionConstraintComponent")))) {
                        printf("%s\n", "  PASS: sh:expression results carry sourceConstraint and message");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: sh:expression report is missing sourceConstraint or message:\n");
                        ({ slop_string _ps_787 = (text); printf("%.*s\n", (int)_ps_787.len, _ps_787.data); });
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_786.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_788 = (msg); printf("%.*s\n", (int)_ps_788.len, _ps_788.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_785.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-expression.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_af_report_blank_nodes(slop_arena* arena) {
    __auto_type _mv_789 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-expression.ttl"));
    if (_mv_789.has_value) {
        __auto_type g = _mv_789.value;
        __auto_type _mv_790 = snarl_validate(arena, g, g);
        switch (_mv_790.tag) {
            case snarl_types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_790.data.validate_success;
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
                        ({ slop_string _ps_791 = (int_to_string(arena, clashes)); printf("%.*s", (int)_ps_791.len, _ps_791.data); });
                        printf("%s", " of ");
                        ({ slop_string _ps_792 = (int_to_string(arena, seen)); printf("%.*s", (int)_ps_792.len, _ps_792.data); });
                        printf("%s\n", " sh:sourceConstraint values are report nodes");
                        return 0;
                    }
                }
            }
            case snarl_types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_790.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                ({ slop_string _ps_793 = (msg); printf("%.*s\n", (int)_ps_793.len, _ps_793.data); });
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_789.has_value) {
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

uint8_t snarl_cli_tests_test_cli_test_rdf12_triple_term_equality(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/rdf12-triple-term-equality.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 4, 1);
}

uint8_t snarl_cli_tests_test_cli_test_rdf12_triple_term_reinfer(slop_arena* arena) {
    {
        __auto_type path = SLOP_STR("fixtures/rdf12-triple-term-equality.ttl");
        __auto_type _mv_794 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
        if (_mv_794.has_value) {
            __auto_type dg = _mv_794.value;
            __auto_type _mv_795 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
            if (_mv_795.has_value) {
                __auto_type sg = _mv_795.value;
                {
                    __auto_type first = snarl_validate_data_graph_with_inference(arena, dg, sg, snarl_cli_tests_test_cli_af_config(1, 0));
                    __auto_type second = snarl_validate_data_graph_with_inference(arena, first.graph, sg, snarl_cli_tests_test_cli_af_config(1, 0));
                    __auto_type n1 = ((int64_t)((first.inferred).len));
                    __auto_type n2 = ((int64_t)((second.inferred).len));
                    if ((n1 == 4) && (n2 == 0)) {
                        printf("%s\n", "  PASS: a second rules pass over triple-term conclusions infers nothing");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: expected 4 then 0 inferred, got ");
                        ({ slop_string _ps_796 = (int_to_string(arena, n1)); printf("%.*s", (int)_ps_796.len, _ps_796.data); });
                        printf("%s", " then ");
                        ({ slop_string _ps_797 = (int_to_string(arena, n2)); printf("%.*s\n", (int)_ps_797.len, _ps_797.data); });
                        return 0;
                    }
                }
            } else if (!_mv_795.has_value) {
                printf("%s", "  FAIL: could not load ");
                ({ slop_string _ps_798 = (path); printf("%.*s\n", (int)_ps_798.len, _ps_798.data); });
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_794.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_799 = (path); printf("%.*s\n", (int)_ps_799.len, _ps_799.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t snarl_cli_tests_test_cli_test_af12_global_rule_af_mode(slop_arena* arena) {
    return snarl_cli_tests_test_cli_assert_inference(arena, SLOP_STR("fixtures/af12-global-rule.ttl"), snarl_cli_tests_test_cli_af_config(1, 0), 0, 0);
}

slop_option_string snarl_cli_tests_test_cli_report_text(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_800 = snarl_cli_tests_test_cli_load_test_graph(arena, data_path);
    if (_mv_800.has_value) {
        __auto_type dg = _mv_800.value;
        __auto_type _mv_801 = snarl_cli_tests_test_cli_load_test_graph(arena, shapes_path);
        if (_mv_801.has_value) {
            __auto_type sg = _mv_801.value;
            __auto_type _mv_802 = snarl_validate(arena, dg, sg);
            switch (_mv_802.tag) {
                case snarl_types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_802.data.validate_success;
                    return (slop_option_string){.has_value = 1, .value = snarl_report_to_string(arena, report)};
                }
                case snarl_types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_802.data.validate_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_803 = (shapes_path); printf("%.*s", (int)_ps_803.len, _ps_803.data); });
                    printf("%s", " engine error: ");
                    ({ slop_string _ps_804 = (msg); printf("%.*s\n", (int)_ps_804.len, _ps_804.data); });
                    return (slop_option_string){.has_value = false};
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_801.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_805 = (shapes_path); printf("%.*s\n", (int)_ps_805.len, _ps_805.data); });
            return (slop_option_string){.has_value = false};
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_800.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_806 = (data_path); printf("%.*s\n", (int)_ps_806.len, _ps_806.data); });
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_same_report(slop_arena* arena, slop_string data_path, slop_string shapes_a, slop_string shapes_b, slop_string expected_marker) {
    __auto_type _mv_807 = snarl_cli_tests_test_cli_report_text(arena, data_path, shapes_a);
    if (_mv_807.has_value) {
        __auto_type a = _mv_807.value;
        __auto_type _mv_808 = snarl_cli_tests_test_cli_report_text(arena, data_path, shapes_b);
        if (_mv_808.has_value) {
            __auto_type b = _mv_808.value;
            if (string_eq(a, b) && std_strlib_contains(a, expected_marker)) {
                printf("%s", "  PASS: ");
                ({ slop_string _ps_809 = (data_path); printf("%.*s", (int)_ps_809.len, _ps_809.data); });
                printf("%s", " validates the same against ");
                ({ slop_string _ps_810 = (shapes_a); printf("%.*s", (int)_ps_810.len, _ps_810.data); });
                printf("%s", " and ");
                ({ slop_string _ps_811 = (shapes_b); printf("%.*s\n", (int)_ps_811.len, _ps_811.data); });
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                ({ slop_string _ps_812 = (data_path); printf("%.*s", (int)_ps_812.len, _ps_812.data); });
                printf("%s", " reports differ, or lack '");
                ({ slop_string _ps_813 = (expected_marker); printf("%.*s", (int)_ps_813.len, _ps_813.data); });
                printf("%s", "':\n");
                ({ slop_string _ps_814 = (a); printf("%.*s\n", (int)_ps_814.len, _ps_814.data); });
                ({ slop_string _ps_815 = (b); printf("%.*s\n", (int)_ps_815.len, _ps_815.data); });
                return 0;
            }
        } else if (!_mv_808.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_807.has_value) {
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
    __auto_type _mv_816 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_816.has_value) {
        __auto_type dg = _mv_816.value;
        __auto_type _mv_817 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_817.has_value) {
            __auto_type sg = _mv_817.value;
            __auto_type _mv_818 = snarl_infer(arena, dg, sg, config);
            switch (_mv_818.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_818.data.infer_success;
                    return ((int64_t)((out.inferred).len));
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_818.data.infer_error;
                    printf("%s", "  infer error: ");
                    ({ slop_string _ps_819 = (msg); printf("%.*s\n", (int)_ps_819.len, _ps_819.data); });
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_817.has_value) {
            return -1;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_816.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_infer_count(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected) {
    {
        __auto_type got = snarl_cli_tests_test_cli_infer_count(arena, path, config);
        if (got == expected) {
            printf("%s", "  PASS: ");
            (void)(({ slop_string _ps_820 = (label); printf("%.*s", (int)_ps_820.len, _ps_820.data); }));
            printf("%s", ": ");
            (void)(({ slop_string _ps_821 = (int_to_string(arena, got)); printf("%.*s", (int)_ps_821.len, _ps_821.data); }));
            printf("%s\n", " inferred");
            return 1;
        } else {
            printf("%s", "  FAIL: ");
            (void)(({ slop_string _ps_822 = (label); printf("%.*s", (int)_ps_822.len, _ps_822.data); }));
            printf("%s", ": expected ");
            (void)(({ slop_string _ps_823 = (int_to_string(arena, expected)); printf("%.*s", (int)_ps_823.len, _ps_823.data); }));
            printf("%s", " inferred, got ");
            (void)(({ slop_string _ps_824 = (int_to_string(arena, got)); printf("%.*s\n", (int)_ps_824.len, _ps_824.data); }));
            return 0;
        }
    }
}

uint8_t snarl_cli_tests_test_cli_assert_infer_error(slop_arena* arena, slop_string path, snarl_types_ValidatorConfig config, slop_string expected_substring) {
    __auto_type _mv_825 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_825.has_value) {
        __auto_type dg = _mv_825.value;
        __auto_type _mv_826 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_826.has_value) {
            __auto_type sg = _mv_826.value;
            __auto_type _mv_827 = snarl_infer(arena, dg, sg, config);
            switch (_mv_827.tag) {
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_827.data.infer_error;
                    if (std_strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        ({ slop_string _ps_828 = (path); printf("%.*s", (int)_ps_828.len, _ps_828.data); });
                        printf("%s", " infer error: ");
                        ({ slop_string _ps_829 = (msg); printf("%.*s\n", (int)_ps_829.len, _ps_829.data); });
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        ({ slop_string _ps_830 = (path); printf("%.*s", (int)_ps_830.len, _ps_830.data); });
                        printf("%s", " infer error did not contain '");
                        ({ slop_string _ps_831 = (expected_substring); printf("%.*s", (int)_ps_831.len, _ps_831.data); });
                        printf("%s", "': ");
                        ({ slop_string _ps_832 = (msg); printf("%.*s\n", (int)_ps_832.len, _ps_832.data); });
                        return 0;
                    }
                }
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type _ = _mv_827.data.infer_success;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_833 = (path); printf("%.*s", (int)_ps_833.len, _ps_833.data); });
                    printf("%s\n", " expected an infer error but inference succeeded");
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_826.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_834 = (path); printf("%.*s\n", (int)_ps_834.len, _ps_834.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_825.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_835 = (path); printf("%.*s\n", (int)_ps_835.len, _ps_835.data); });
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_assert_deferred(slop_arena* arena, slop_string label, slop_string path, snarl_types_ValidatorConfig config, int64_t expected_inferred, int64_t expected_deferred, slop_string rule, slop_string shape, double shape_order, double rule_order) {
    __auto_type _mv_836 = snarl_cli_tests_test_cli_load_test_data_graph(arena, path);
    if (_mv_836.has_value) {
        __auto_type dg = _mv_836.value;
        __auto_type _mv_837 = snarl_cli_tests_test_cli_load_test_graph(arena, path);
        if (_mv_837.has_value) {
            __auto_type sg = _mv_837.value;
            __auto_type _mv_838 = snarl_infer(arena, dg, sg, config);
            switch (_mv_838.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_838.data.infer_success;
                    {
                        uint8_t ok = ((((int64_t)((out.inferred).len)) == expected_inferred) && (((int64_t)((out.deferred).len)) == expected_deferred));
                        if (ok && (expected_deferred > 0)) {
                            __auto_type _mv_839 = ({ __auto_type _lst = out.deferred; size_t _idx = (size_t)0; slop_option_snarl_rules_DeferredRule _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                            if (_mv_839.has_value) {
                                __auto_type d = _mv_839.value;
                                if (!(((rdf_term_eq(d.rule, snarl_cli_tests_test_cli_ex_iri(arena, rule)) && rdf_term_eq(d.shape, snarl_cli_tests_test_cli_ex_iri(arena, shape))) && ((d.order.shape_order == shape_order) && (d.order.rule_order == rule_order))))) {
                                    ok = 0;
                                }
                            } else if (!_mv_839.has_value) {
                                ok = 0;
                            }
                        }
                        if (ok) {
                            printf("%s", "  PASS: ");
                            ({ slop_string _ps_840 = (label); printf("%.*s", (int)_ps_840.len, _ps_840.data); });
                            printf("%s", ": ");
                            ({ slop_string _ps_841 = (int_to_string(arena, ((int64_t)((out.inferred).len)))); printf("%.*s", (int)_ps_841.len, _ps_841.data); });
                            printf("%s", " inferred, ");
                            ({ slop_string _ps_842 = (int_to_string(arena, ((int64_t)((out.deferred).len)))); printf("%.*s", (int)_ps_842.len, _ps_842.data); });
                            printf("%s\n", " deferred");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            ({ slop_string _ps_843 = (label); printf("%.*s", (int)_ps_843.len, _ps_843.data); });
                            printf("%s", ": got ");
                            ({ slop_string _ps_844 = (int_to_string(arena, ((int64_t)((out.inferred).len)))); printf("%.*s", (int)_ps_844.len, _ps_844.data); });
                            printf("%s", " inferred, ");
                            ({ slop_string _ps_845 = (int_to_string(arena, ((int64_t)((out.deferred).len)))); printf("%.*s", (int)_ps_845.len, _ps_845.data); });
                            printf("%s\n", " deferred, or the deferred rule is not the expected one");
                            return 0;
                        }
                    }
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_838.data.infer_error;
                    printf("%s", "  FAIL: ");
                    ({ slop_string _ps_846 = (label); printf("%.*s", (int)_ps_846.len, _ps_846.data); });
                    printf("%s", " infer error: ");
                    ({ slop_string _ps_847 = (msg); printf("%.*s\n", (int)_ps_847.len, _ps_847.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_837.has_value) {
            printf("%s", "  FAIL: could not load ");
            ({ slop_string _ps_848 = (path); printf("%.*s\n", (int)_ps_848.len, _ps_848.data); });
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_836.has_value) {
        printf("%s", "  FAIL: could not load ");
        ({ slop_string _ps_849 = (path); printf("%.*s\n", (int)_ps_849.len, _ps_849.data); });
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
    __auto_type _mv_850 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-sparql-entailment.ttl"));
    if (_mv_850.has_value) {
        __auto_type dg = _mv_850.value;
        __auto_type _mv_851 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-sparql-entailment.ttl"));
        if (_mv_851.has_value) {
            __auto_type sg = _mv_851.value;
            {
                __auto_type outcome = snarl_validate_data_graph_with_inference(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(0, 0, 1, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()));
                __auto_type _mv_852 = outcome.result;
                switch (_mv_852.tag) {
                    case snarl_types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_852.data.validate_success;
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
                        __auto_type msg = _mv_852.data.validate_error;
                        printf("%s", "  FAIL: validation with deferral: ");
                        ({ slop_string _ps_853 = (msg); printf("%.*s\n", (int)_ps_853.len, _ps_853.data); });
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_851.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-sparql-entailment.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_850.has_value) {
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
    __auto_type _mv_854 = snarl_infer(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_order_key(0.0, lo), snarl_cli_tests_test_cli_order_key(0.0, hi)));
    switch (_mv_854.tag) {
        case snarl_rules_InferResult_infer_success:
        {
            __auto_type out = _mv_854.data.infer_success;
            return (slop_option_snarl_rules_InferOutput){.has_value = 1, .value = out};
        }
        case snarl_rules_InferResult_infer_error:
        {
            __auto_type msg = _mv_854.data.infer_error;
            printf("%s", "  infer error: ");
            ({ slop_string _ps_855 = (msg); printf("%.*s\n", (int)_ps_855.len, _ps_855.data); });
            return (slop_option_snarl_rules_InferOutput){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_cli_tests_test_cli_test_order_range_stepping(slop_arena* arena) {
    __auto_type _mv_856 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-order-range.ttl"));
    if (_mv_856.has_value) {
        __auto_type dg0 = _mv_856.value;
        __auto_type _mv_857 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-order-range.ttl"));
        if (_mv_857.has_value) {
            __auto_type sg = _mv_857.value;
            {
                __auto_type t = rdf_make_literal(arena, SLOP_STR("true"), (slop_option_string){.has_value = 1, .value = SLOP_STR("http://www.w3.org/2001/XMLSchema#boolean")}, ((slop_option_string){.has_value = false}));
                uint8_t ok = 1;
                __auto_type dg = dg0;
                __auto_type _mv_858 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 1.0, 1.0);
                if (_mv_858.has_value) {
                    __auto_type out = _mv_858.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("a"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_858.has_value) {
                    ok = 0;
                }
                __auto_type _mv_859 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 2.0, 2.0);
                if (_mv_859.has_value) {
                    __auto_type out = _mv_859.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("b"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_859.has_value) {
                    ok = 0;
                }
                __auto_type _mv_860 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 3.0, 3.0);
                if (_mv_860.has_value) {
                    __auto_type out = _mv_860.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("d"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_860.has_value) {
                    ok = 0;
                }
                __auto_type _mv_861 = snarl_cli_tests_test_cli_infer_step(arena, dg, sg, 2.0, 2.0);
                if (_mv_861.has_value) {
                    __auto_type out = _mv_861.value;
                    dg = out.graph;
                    if (!(((((int64_t)((out.inferred).len)) == 1) && snarl_cli_tests_test_cli_triple_inferred(arena, out.inferred, SLOP_STR("n"), SLOP_STR("c"), t)))) {
                        ok = 0;
                    }
                } else if (!_mv_861.has_value) {
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
        } else if (!_mv_857.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-order-range.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_856.has_value) {
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
    __auto_type _mv_862 = snarl_cli_tests_test_cli_load_test_data_graph(arena, SLOP_STR("fixtures/af-attribution.ttl"));
    if (_mv_862.has_value) {
        __auto_type dg = _mv_862.value;
        __auto_type _mv_863 = snarl_cli_tests_test_cli_load_test_graph(arena, SLOP_STR("fixtures/af-attribution.ttl"));
        if (_mv_863.has_value) {
            __auto_type sg = _mv_863.value;
            __auto_type _mv_864 = snarl_infer(arena, dg, sg, snarl_cli_tests_test_cli_rule_config(1, 0, 0, snarl_cli_tests_test_cli_no_order(), snarl_cli_tests_test_cli_no_order()));
            switch (_mv_864.tag) {
                case snarl_rules_InferResult_infer_success:
                {
                    __auto_type out = _mv_864.data.infer_success;
                    {
                        __auto_type inf = out.inferred;
                        if ((((int64_t)((inf).len)) == 5) && ((snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n1"), SLOP_STR("p"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("v")), SLOP_STR("RuleA"), SLOP_STR("n1")) && snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n2"), SLOP_STR("p"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("v")), SLOP_STR("RuleA"), SLOP_STR("n2"))) && ((snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n1"), SLOP_STR("q"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("w")), SLOP_STR("RuleB"), SLOP_STR("n1")) && snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("n2"), SLOP_STR("q"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("w")), SLOP_STR("RuleB"), SLOP_STR("n2"))) && (snarl_cli_tests_test_cli_has_inferred(arena, inf, SLOP_STR("shared"), SLOP_STR("from"), snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("k")), SLOP_STR("RuleD"), SLOP_STR("n1")) && ({ __auto_type _mv = ({ __auto_type _lst = inf; size_t _idx = (size_t)0; slop_option_snarl_rules_InferredTriple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type first = _mv.value; rdf_term_eq(first.rule, snarl_cli_tests_test_cli_ex_iri(arena, SLOP_STR("RuleA"))); }) : (0); }))))) {
                            printf("%s\n", "  PASS: each inferred triple names its rule and focus node");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: attribution: ");
                            ({ slop_string _ps_865 = (int_to_string(arena, ((int64_t)((inf).len)))); printf("%.*s", (int)_ps_865.len, _ps_865.data); });
                            printf("%s\n", " inferred, or a wrong rule or focus node");
                            {
                                __auto_type _coll = inf;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type it = _coll.data[_i];
                                    printf("%s", "    ");
                                    ({ slop_string _ps_866 = (snarl_cli_tests_test_cli_term_display(arena, it.triple.subject)); printf("%.*s", (int)_ps_866.len, _ps_866.data); });
                                    printf("%s", " ");
                                    ({ slop_string _ps_867 = (snarl_cli_tests_test_cli_term_display(arena, it.triple.predicate)); printf("%.*s", (int)_ps_867.len, _ps_867.data); });
                                    printf("%s", " by ");
                                    ({ slop_string _ps_868 = (snarl_cli_tests_test_cli_term_display(arena, it.rule)); printf("%.*s", (int)_ps_868.len, _ps_868.data); });
                                    printf("%s", " for ");
                                    ({ slop_string _ps_869 = (snarl_cli_tests_test_cli_term_display(arena, it.focus_node)); printf("%.*s\n", (int)_ps_869.len, _ps_869.data); });
                                }
                            }
                            return 0;
                        }
                    }
                }
                case snarl_rules_InferResult_infer_error:
                {
                    __auto_type msg = _mv_864.data.infer_error;
                    printf("%s", "  FAIL: attribution: infer error: ");
                    ({ slop_string _ps_870 = (msg); printf("%.*s\n", (int)_ps_870.len, _ps_870.data); });
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_863.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/af-attribution.ttl");
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_862.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/af-attribution.ttl");
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string snarl_cli_tests_test_cli_term_display(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_871 = t;
    switch (_mv_871.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_871.data.term_iri;
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
            if (snarl_cli_tests_test_cli_test_rdf12_triple_term_equality(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (snarl_cli_tests_test_cli_test_rdf12_triple_term_reinfer(arena)) {
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
            (void)(({ slop_string _ps_872 = (int_to_string(arena, passed)); printf("%.*s", (int)_ps_872.len, _ps_872.data); }));
            printf("%s", " passed, ");
            (void)(({ slop_string _ps_873 = (int_to_string(arena, failed)); printf("%.*s", (int)_ps_873.len, _ps_873.data); }));
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

