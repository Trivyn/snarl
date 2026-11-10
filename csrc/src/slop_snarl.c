#include "../runtime/slop_runtime.h"
#include "slop_snarl.h"

snarl_types_ValidatorConfig snarl_default_config(void);
snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_ValidationOutcome snarl_validate_data_graph_with_inference(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_result_snarl_types_ShapesGraph_string snarl_prepare_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config, uint8_t rules_run);
snarl_rules_InferResult snarl_infer(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
uint8_t snarl_conforms(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
uint8_t snarl_conforms_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
slop_list_snarl_types_ValidationResult snarl_get_violations(slop_arena* arena, snarl_types_ValidationReport report);
slop_list_snarl_types_ValidationResult snarl_get_warnings(slop_arena* arena, snarl_types_ValidationReport report);
int64_t snarl_get_result_count(snarl_types_ValidationReport report);

snarl_types_ValidatorConfig snarl_default_config(void) {
    snarl_types_ValidatorConfig _retval = {0};
    _retval = snarl_types_default_validator_config();
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.verbose == 0)), "(== (. $result verbose) false)");
    SLOP_POST(((_retval.max_errors == 0)), "(== (. $result max-errors) 0)");
    SLOP_POST(((_retval.include_warnings == 1)), "(== (. $result include-warnings) true)");
    SLOP_POST(((_retval.include_infos == 1)), "(== (. $result include-infos) true)");
    SLOP_POST(((_retval.run_rules == 0)), "(== (. $result run-rules) false)");
    SLOP_POST(((_retval.shacl12 == 0)), "(== (. $result shacl12) false)");
    SLOP_POST(((_retval.defer_sparql_rules == 0)), "(== (. $result defer-sparql-rules) false)");
    SLOP_POST(((!((_retval.order_min).has_value))), "(is-none (. $result order-min))");
    SLOP_POST(((!((_retval.order_max).has_value))), "(is-none (. $result order-max))");
    return _retval;
}

snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    return snarl_validate_with_config(arena, data_graph, shapes_graph, snarl_default_config());
}

snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    {
        __auto_type fast_data = snarl_data_graph_from_indexed(arena, data_graph);
        return snarl_validate_data_graph_with_config(arena, fast_data, shapes_graph, config);
    }
}

snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    return snarl_validate_data_graph_with_config(arena, data_graph, shapes_graph, snarl_default_config());
}

snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    return snarl_validate_data_graph_with_inference(arena, data_graph, shapes_graph, config).result;
}

snarl_ValidationOutcome snarl_validate_data_graph_with_inference(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    {
        __auto_type none_inferred = ((slop_list_snarl_rules_InferredTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type none_deferred = ((slop_list_snarl_rules_DeferredRule){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rules_run = (config.run_rules || snarl_parse_shapes_graph_declares_rules_entailment(arena, shapes_graph, config.shacl12));
        __auto_type _mv_661 = snarl_prepare_shapes(arena, shapes_graph, config, rules_run);
        if (!_mv_661.is_ok) {
            __auto_type msg = _mv_661.data.err;
            return ((snarl_ValidationOutcome){.result = ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_error, .data.validate_error = msg }), .graph = data_graph, .inferred = none_inferred, .deferred = none_deferred});
        } else if (_mv_661.is_ok) {
            __auto_type shapes = _mv_661.data.ok;
            if (rules_run) {
                __auto_type _mv_662 = snarl_infer_rules(arena, data_graph, shapes, config);
                switch (_mv_662.tag) {
                    case snarl_rules_InferResult_infer_error:
                    {
                        __auto_type msg = _mv_662.data.infer_error;
                        return ((snarl_ValidationOutcome){.result = ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_error, .data.validate_error = msg }), .graph = data_graph, .inferred = none_inferred, .deferred = none_deferred});
                    }
                    case snarl_rules_InferResult_infer_success:
                    {
                        __auto_type out = _mv_662.data.infer_success;
                        return ((snarl_ValidationOutcome){.result = snarl_engine_validate(arena, out.graph, shapes, config), .graph = out.graph, .inferred = out.inferred, .deferred = out.deferred});
                    }
                }
                SLOP_UNREACHABLE();
            } else {
                return ((snarl_ValidationOutcome){.result = snarl_engine_validate(arena, data_graph, shapes, config), .graph = data_graph, .inferred = none_inferred, .deferred = none_deferred});
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_snarl_types_ShapesGraph_string snarl_prepare_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config, uint8_t rules_run) {
    __auto_type _mv_663 = snarl_shapes_graph_recursion_hazard_message(arena, shapes_graph);
    if (_mv_663.has_value) {
        __auto_type msg = _mv_663.value;
        return ((slop_result_snarl_types_ShapesGraph_string){ .is_ok = false, .data.err = msg });
    } else if (!_mv_663.has_value) {
        __auto_type _mv_664 = snarl_shapes_graph_unsupported_feature_message(arena, shapes_graph, config.shacl12, rules_run, config.defer_sparql_rules);
        if (_mv_664.has_value) {
            __auto_type msg = _mv_664.value;
            return ((slop_result_snarl_types_ShapesGraph_string){ .is_ok = false, .data.err = msg });
        } else if (!_mv_664.has_value) {
            {
                __auto_type shapes = snarl_parse_shapes_graph(arena, snarl_data_graph_canonicalize_triple_terms(arena, shapes_graph));
                __auto_type _mv_665 = snarl_engine_shapes_graph_pattern_error_message(arena, shapes);
                if (_mv_665.has_value) {
                    __auto_type msg = _mv_665.value;
                    return ((slop_result_snarl_types_ShapesGraph_string){ .is_ok = false, .data.err = msg });
                } else if (!_mv_665.has_value) {
                    return ((slop_result_snarl_types_ShapesGraph_string){ .is_ok = true, .data.ok = shapes });
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

snarl_rules_InferResult snarl_infer(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    __auto_type _mv_666 = snarl_prepare_shapes(arena, shapes_graph, config, 1);
    if (!_mv_666.is_ok) {
        __auto_type msg = _mv_666.data.err;
        return ((snarl_rules_InferResult){ .tag = snarl_rules_InferResult_infer_error, .data.infer_error = msg });
    } else if (_mv_666.is_ok) {
        __auto_type shapes = _mv_666.data.ok;
        return snarl_infer_rules(arena, data_graph, shapes, config);
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_conforms(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    __auto_type _mv_667 = snarl_validate(arena, data_graph, shapes_graph);
    switch (_mv_667.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_667.data.validate_success;
            return snarl_types_report_conforms(report);
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_667.data.validate_error;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_conforms_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    __auto_type _mv_668 = snarl_validate_data_graph(arena, data_graph, shapes_graph);
    switch (_mv_668.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_668.data.validate_success;
            return snarl_types_report_conforms(report);
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_668.data.validate_error;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_snarl_types_ValidationResult snarl_get_violations(slop_arena* arena, snarl_types_ValidationReport report) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type result = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = report.results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_669 = r.severity;
                switch (_mv_669) {
                    case snarl_types_Severity_severity_violation: {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= ((int64_t)((report.results).len)))), "(<= (list-len $result) (list-len (. report results)))");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_get_warnings(slop_arena* arena, snarl_types_ValidationReport report) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type result = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = report.results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_670 = r.severity;
                switch (_mv_670) {
                    case snarl_types_Severity_severity_warning: {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= ((int64_t)((report.results).len)))), "(<= (list-len $result) (list-len (. report results)))");
    return _retval;
}

int64_t snarl_get_result_count(snarl_types_ValidationReport report) {
    int64_t _retval = {0};
    _retval = SLOP_RANGE(int64_t, ((int64_t)((report.results).len)), 1, 0, 0, 0, "(Int 0 ..) at snarl.slop:259:5");
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval == ((int64_t)((report.results).len)))), "(== $result (list-len (. report results)))");
    return _retval;
}

