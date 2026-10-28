#include "../runtime/slop_runtime.h"
#include "slop_snarl.h"

snarl_types_ValidatorConfig snarl_default_config(void);
snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
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
    return _retval;
}

snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    snarl_types_ValidatorResult _retval = {0};
    _retval = snarl_validate_with_config(arena, data_graph, shapes_graph, snarl_default_config());
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case snarl_types_ValidatorResult_validate_success: { __auto_type report = _mv.data.validate_success; _mr = (((int64_t)((report.results).len)) >= 0); _mm = 1; break; } case snarl_types_ValidatorResult_validate_error: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match $result ((validate-success report) (>= (list-len (. report results)) 0)) ((validate-error _) true))");
    return _retval;
}

snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    {
        __auto_type fast_data = snarl_data_graph_from_indexed(arena, data_graph);
        return snarl_validate_data_graph_with_config(arena, fast_data, shapes_graph, config);
    }
}

snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    snarl_types_ValidatorResult _retval = {0};
    _retval = snarl_validate_data_graph_with_config(arena, data_graph, shapes_graph, snarl_default_config());
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case snarl_types_ValidatorResult_validate_success: { __auto_type report = _mv.data.validate_success; _mr = (((int64_t)((report.results).len)) >= 0); _mm = 1; break; } case snarl_types_ValidatorResult_validate_error: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match $result ((validate-success report) (>= (list-len (. report results)) 0)) ((validate-error _) true))");
    return _retval;
}

snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    snarl_types_ValidatorResult _retval = {0};
    __auto_type _mv_522 = snarl_shapes_graph_recursion_hazard_message(arena, shapes_graph);
    if (_mv_522.has_value) {
        __auto_type msg = _mv_522.value;
        _retval = ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_error, .data.validate_error = msg });
        goto _slop_post;
    } else if (!_mv_522.has_value) {
        {
            __auto_type shapes = snarl_parse_shapes_graph(arena, shapes_graph);
            __auto_type _mv_523 = snarl_engine_shapes_graph_pattern_error_message(arena, shapes);
            if (_mv_523.has_value) {
                __auto_type msg = _mv_523.value;
                _retval = ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_error, .data.validate_error = msg });
                goto _slop_post;
            } else if (!_mv_523.has_value) {
                _retval = snarl_engine_validate(arena, data_graph, shapes, config);
                goto _slop_post;
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case snarl_types_ValidatorResult_validate_success: { __auto_type report = _mv.data.validate_success; _mr = (((int64_t)((report.results).len)) >= 0); _mm = 1; break; } case snarl_types_ValidatorResult_validate_error: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match $result ((validate-success report) (>= (list-len (. report results)) 0)) ((validate-error _) true))");
    return _retval;
}

uint8_t snarl_conforms(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    __auto_type _mv_524 = snarl_validate(arena, data_graph, shapes_graph);
    switch (_mv_524.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_524.data.validate_success;
            return snarl_types_report_conforms(report);
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_524.data.validate_error;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_conforms_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    uint8_t _retval = {0};
    __auto_type _mv_525 = snarl_validate_data_graph(arena, data_graph, shapes_graph);
    switch (_mv_525.tag) {
        case snarl_types_ValidatorResult_validate_success:
        {
            __auto_type report = _mv_525.data.validate_success;
            _retval = snarl_types_report_conforms(report);
            goto _slop_post;
        }
        case snarl_types_ValidatorResult_validate_error:
        {
            __auto_type _ = _mv_525.data.validate_error;
            _retval = 0;
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((((_retval == 1) || (_retval == 0))), "(or (== $result true) (== $result false))");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_get_violations(slop_arena* arena, snarl_types_ValidationReport report) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type result = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = report.results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_526 = r.severity;
                switch (_mv_526) {
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
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
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
                __auto_type _mv_527 = r.severity;
                switch (_mv_527) {
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
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    SLOP_POST(((((int64_t)((_retval).len)) <= ((int64_t)((report.results).len)))), "(<= (list-len $result) (list-len (. report results)))");
    return _retval;
}

int64_t snarl_get_result_count(snarl_types_ValidationReport report) {
    int64_t _retval = {0};
    _retval = SLOP_RANGE(int64_t, ((int64_t)((report.results).len)), 1, 0, 0, 0, "(Int 0 ..) at snarl.slop:198:5");
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval == ((int64_t)((report.results).len)))), "(== $result (list-len (. report results)))");
    return _retval;
}

