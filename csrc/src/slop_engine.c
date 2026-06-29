#include "../runtime/slop_runtime.h"
#include "slop_engine.h"

int64_t engine_optional_term_set_size(slop_option_index_TermSet values);
slop_list_rdf_Term engine_optional_term_set_to_list(slop_arena* arena, slop_option_index_TermSet values);
uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited);
uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term node, types_NodeShape shape, slop_map* visited);
uint8_t snarl_property_shape_conforms(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_PropertyShape ps);
uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term node, types_PropertyShape ps);
types_ValidatorResult snarl_engine_validate(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult engine_evaluate_simple_predicate_property_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_PropertyShape shape, rdf_Term focus_node, rdf_Term pred, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);
slop_list_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);
slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult engine_evaluate_constraint_for_simple_predicate_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, rdf_Term pred, slop_option_index_TermSet value_set, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs);

int64_t engine_optional_term_set_size(slop_option_index_TermSet values) {
    int64_t _retval = {0};
    __auto_type _mv_174 = values;
    if (_mv_174.has_value) {
        __auto_type terms = _mv_174.value;
        return data_graph_snarl_data_graph_term_set_size(terms);
    } else if (!_mv_174.has_value) {
        return 0;
    }
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

slop_list_rdf_Term engine_optional_term_set_to_list(slop_arena* arena, slop_option_index_TermSet values) {
    slop_list_rdf_Term _retval = {0};
    __auto_type _mv_175 = values;
    if (_mv_175.has_value) {
        __auto_type terms = _mv_175.value;
        return data_graph_snarl_data_graph_term_set_to_list(arena, terms);
    } else if (!_mv_175.has_value) {
        return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, node, shape, visited);
    }
}

uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term node, types_NodeShape shape, slop_map* visited) {
    {
        __auto_type config = types_default_validator_config();
        __auto_type results = snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, shape, node, visited, config);
        return (((int64_t)((results).len)) == 0);
    }
}

uint8_t snarl_property_shape_conforms(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_PropertyShape ps) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, node, ps);
    }
}

uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term node, types_PropertyShape ps) {
    {
        __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type empty_siblings = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ps, node, rec_visited, types_default_validator_config(), empty_siblings);
        return (((int64_t)((results).len)) == 0);
    }
}

types_ValidatorResult snarl_engine_validate(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        __auto_type target_cache = target_target_cache_create(arena);
        __auto_type report = types_make_validation_report(arena);
        int64_t error_count = 0;
        __auto_type max_errors = config.max_errors;
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                if (!(ns.deactivated)) {
                    if ((max_errors == 0) || (error_count < max_errors)) {
                        {
                            __auto_type focus_nodes = target_resolve_targets_cached(arena, data_graph, target_cache, ns);
                            __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                            {
                                __auto_type _coll = focus_nodes;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type focus_node = _coll.data[_i];
                                    if ((max_errors == 0) || (error_count < max_errors)) {
                                        {
                                            __auto_type results = snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, ns, focus_node, visited, config);
                                            {
                                                __auto_type _coll = results;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type r = _coll.data[_i];
                                                    {
                                                        __auto_type include = ({ __auto_type _mv = r.severity; uint8_t _mr = {0}; switch (_mv) { case types_Severity_severity_violation: { _mr = 1; break; } case types_Severity_severity_warning: { _mr = config.include_warnings; break; } case types_Severity_severity_info: { _mr = config.include_infos; break; }  } _mr; });
                                                        if (include) {
                                                            report = types_report_add_result(arena, report, r);
                                                            __auto_type _mv_176 = r.severity;
                                                            switch (_mv_176) {
                                                                case types_Severity_severity_violation: {
                                                                    error_count = (error_count + 1);
                                                                    break;
                                                                }
                                                                default: {
                                                                    break;
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
                }
            }
        }
        return ((types_ValidatorResult){ .tag = types_ValidatorResult_validate_success, .data.validate_success = report });
    }
}

slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, visited, config);
    }
}

slop_list_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config) {
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type shape_severity = shape.severity;
        __auto_type shape_message = shape.message;
        __auto_type shape_id = shape.id;
        slop_option_types_ShaclPath no_path = (slop_option_types_ShaclPath){.has_value = false};
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                {
                    __auto_type constraint_results = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, focus_node, constraint, no_path, shape_id, shape_severity, shape_message, visited);
                    {
                        __auto_type _coll = constraint_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                __auto_type _mv_177 = constraint;
                if (_mv_177.tag == types_Constraint_con_closed && _mv_177.data.con_closed.f0 == 1) {
                    __auto_type ignored_paths = _mv_177.data.con_closed.f1;
                    {
                        __auto_type allowed_paths = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
                        __auto_type ign_len = ((int64_t)((ignored_paths).len));
                        {
                            __auto_type _coll = shape.property_shapes;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                ({ __auto_type _lst_p = &(allowed_paths); __auto_type _item = (ps.path); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type i = 0;
                            while (i < ign_len) {
                                __auto_type _mv_178 = ({ __auto_type _lst = ignored_paths; size_t _idx = (size_t)i; slop_option_types_ShaclPath _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_178.has_value) {
                                    __auto_type ip = _mv_178.value;
                                    ({ __auto_type _lst_p = &(allowed_paths); __auto_type _item = (ip); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (!_mv_178.has_value) {
                                }
                                i = (i + 1);
                            }
                        }
                        {
                            __auto_type closed_results = snarl_check_closed(arena, data_graph, focus_node, allowed_paths, no_path, shape_id, shape_severity, shape_message);
                            {
                                __auto_type _coll = closed_results;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else {
                }
            }
        }
        {
            __auto_type all_disjoint_qvs = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
            __auto_type all_disjoint_ps_ids = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
            {
                __auto_type _coll = shape.property_shapes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ps = _coll.data[_i];
                    if (!(ps.deactivated)) {
                        {
                            __auto_type _coll = ps.constraints;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                __auto_type _mv_179 = c;
                                switch (_mv_179.tag) {
                                    case types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_179.data.con_qualified_value_shape.f0;
                                        __auto_type disjoint = _mv_179.data.con_qualified_value_shape.f3;
                                        if (disjoint) {
                                            ({ __auto_type _lst_p = &(all_disjoint_qvs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            ({ __auto_type _lst_p = &(all_disjoint_ps_ids); __auto_type _item = (ps.id); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                        break;
                                    }
                                    default: {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            {
                __auto_type _coll = shape.property_shapes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ps = _coll.data[_i];
                    if (!(ps.deactivated)) {
                        {
                            __auto_type sibling_refs = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                            __auto_type ps_id = ps.id;
                            int64_t i = 0;
                            __auto_type n = ((int64_t)((all_disjoint_qvs).len));
                            while (i < n) {
                                __auto_type _mv_180 = ({ __auto_type _lst = all_disjoint_ps_ids; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_180.has_value) {
                                    __auto_type pid = _mv_180.value;
                                    if (!(rdf_term_eq(pid, ps_id))) {
                                        __auto_type _mv_181 = ({ __auto_type _lst = all_disjoint_qvs; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_181.has_value) {
                                            __auto_type ref = _mv_181.value;
                                            ({ __auto_type _lst_p = &(sibling_refs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_181.has_value) {
                                        }
                                    }
                                } else if (!_mv_180.has_value) {
                                }
                                i = (i + 1);
                            }
                            {
                                __auto_type ps_results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ps, focus_node, visited, config, sibling_refs);
                                {
                                    __auto_type _coll = ps_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
}

slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, visited, config, sibling_qvs_refs);
    }
}

slop_list_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs) {
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type path = shape.path;
        __auto_type _mv_182 = path;
        switch (_mv_182.tag) {
            case types_ShaclPath_path_predicate:
            {
                __auto_type pred = _mv_182.data.path_predicate;
                return engine_evaluate_simple_predicate_property_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, pred, visited, config, sibling_qvs_refs);
            }
            default: {
                {
                    __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
                    __auto_type shape_severity = shape.severity;
                    __auto_type shape_message = shape.message;
                    __auto_type shape_id = shape.id;
                    __auto_type path_opt = (slop_option_types_ShaclPath){.has_value = 1, .value = path};
                    __auto_type value_nodes = snarl_resolve_path(arena, data_graph, focus_node, path);
                    __auto_type value_count = ((int64_t)((value_nodes).len));
                    {
                        __auto_type _coll = shape.constraints;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type constraint = _coll.data[_i];
                            {
                                __auto_type constraint_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited, sibling_qvs_refs);
                                {
                                    __auto_type _coll = constraint_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                    return results;
                }
            }
        }
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult engine_evaluate_simple_predicate_property_shape_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, types_PropertyShape shape, rdf_Term focus_node, rdf_Term pred, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs) {
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type shape_severity = shape.severity;
        __auto_type shape_message = shape.message;
        __auto_type shape_id = shape.id;
        __auto_type path = shape.path;
        __auto_type path_opt = (slop_option_types_ShaclPath){.has_value = 1, .value = path};
        __auto_type value_set = data_graph_snarl_data_graph_object_set(data_graph, focus_node, pred);
        __auto_type value_count = engine_optional_term_set_size(value_set);
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                {
                    __auto_type constraint_results = engine_evaluate_constraint_for_simple_predicate_cached(arena, data_graph, shapes_graph, class_index, focus_node, pred, value_set, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = constraint_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
    }
}

slop_list_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited) {
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_183 = constraint;
        switch (_mv_183.tag) {
            case types_Constraint_con_class:
            {
                __auto_type required_class = _mv_183.data.con_class;
                __auto_type _mv_184 = value_type_check_class_with_index(arena, data_graph, class_index, focus_node, value_node, required_class, path, shape_id, severity, message);
                if (_mv_184.has_value) {
                    __auto_type r = _mv_184.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_184.has_value) {
                }
                break;
            }
            case types_Constraint_con_datatype:
            {
                __auto_type required_dt = _mv_183.data.con_datatype;
                __auto_type _mv_185 = snarl_check_datatype(arena, focus_node, value_node, required_dt, path, shape_id, severity, message);
                if (_mv_185.has_value) {
                    __auto_type r = _mv_185.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_185.has_value) {
                }
                break;
            }
            case types_Constraint_con_node_kind:
            {
                __auto_type required_kind = _mv_183.data.con_node_kind;
                __auto_type _mv_186 = snarl_check_node_kind(arena, focus_node, value_node, required_kind, path, shape_id, severity, message);
                if (_mv_186.has_value) {
                    __auto_type r = _mv_186.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_186.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_count:
            {
                __auto_type _ = _mv_183.data.con_min_count;
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type _ = _mv_183.data.con_max_count;
                break;
            }
            case types_Constraint_con_min_inclusive:
            {
                __auto_type limit = _mv_183.data.con_min_inclusive;
                __auto_type _mv_187 = snarl_check_min_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_187.has_value) {
                    __auto_type r = _mv_187.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_187.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_inclusive:
            {
                __auto_type limit = _mv_183.data.con_max_inclusive;
                __auto_type _mv_188 = snarl_check_max_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_188.has_value) {
                    __auto_type r = _mv_188.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_188.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_exclusive:
            {
                __auto_type limit = _mv_183.data.con_min_exclusive;
                __auto_type _mv_189 = snarl_check_min_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_189.has_value) {
                    __auto_type r = _mv_189.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_189.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_exclusive:
            {
                __auto_type limit = _mv_183.data.con_max_exclusive;
                __auto_type _mv_190 = snarl_check_max_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_190.has_value) {
                    __auto_type r = _mv_190.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_190.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_length:
            {
                __auto_type min_len = _mv_183.data.con_min_length;
                __auto_type _mv_191 = snarl_check_min_length(arena, focus_node, value_node, min_len, path, shape_id, severity, message);
                if (_mv_191.has_value) {
                    __auto_type r = _mv_191.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_191.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_length:
            {
                __auto_type max_len = _mv_183.data.con_max_length;
                __auto_type _mv_192 = snarl_check_max_length(arena, focus_node, value_node, max_len, path, shape_id, severity, message);
                if (_mv_192.has_value) {
                    __auto_type r = _mv_192.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_192.has_value) {
                }
                break;
            }
            case types_Constraint_con_pattern:
            {
                __auto_type pat = _mv_183.data.con_pattern;
                __auto_type _mv_193 = snarl_check_pattern(arena, focus_node, value_node, pat, path, shape_id, severity, message);
                if (_mv_193.has_value) {
                    __auto_type r = _mv_193.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_193.has_value) {
                }
                break;
            }
            case types_Constraint_con_language_in:
            {
                __auto_type allowed_langs = _mv_183.data.con_language_in;
                __auto_type _mv_194 = snarl_check_language_in(arena, focus_node, value_node, allowed_langs, path, shape_id, severity, message);
                if (_mv_194.has_value) {
                    __auto_type r = _mv_194.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_194.has_value) {
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type _ = _mv_183.data.con_unique_lang;
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_183.data.con_equals;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = eq_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_183.data.con_disjoint;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = dj_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_183.data.con_less_than;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = lt_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_183.data.con_less_than_or_equals;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = le_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_183.data.con_has_value;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    __auto_type _mv_195 = snarl_check_has_value(arena, focus_node, single_list, required_value, path, shape_id, severity, message);
                    if (_mv_195.has_value) {
                        __auto_type r = _mv_195.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_195.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_in:
            {
                __auto_type allowed_values = _mv_183.data.con_in;
                __auto_type _mv_196 = snarl_check_in(arena, focus_node, value_node, allowed_values, path, shape_id, severity, message);
                if (_mv_196.has_value) {
                    __auto_type r = _mv_196.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_196.has_value) {
                }
                break;
            }
            case types_Constraint_con_closed:
            {
                break;
            }
            case types_Constraint_con_not:
            {
                __auto_type shape_ref = _mv_183.data.con_not;
                {
                    __auto_type conforms = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(shape_ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_ps = _mv.value; snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_ps); }) : (({ __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term); ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); }); ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, rec_visited); }) : (0); }); })); });
                    __auto_type _mv_197 = snarl_check_not(arena, focus_node, conforms, path, shape_id, severity, message);
                    if (_mv_197.has_value) {
                        __auto_type r = _mv_197.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_197.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_and:
            {
                __auto_type shape_refs = _mv_183.data.con_and;
                {
                    __auto_type all_pass = 1;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_198 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                            if (_mv_198.has_value) {
                                __auto_type ref_ps = _mv_198.value;
                                if (!(snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_ps))) {
                                    all_pass = 0;
                                }
                            } else if (!_mv_198.has_value) {
                                {
                                    __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                    __auto_type _mv_199 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                    if (_mv_199.has_value) {
                                        __auto_type ref_shape = _mv_199.value;
                                        if (!(snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, rec_visited))) {
                                            all_pass = 0;
                                        }
                                    } else if (!_mv_199.has_value) {
                                    }
                                }
                            }
                        }
                    }
                    __auto_type _mv_200 = snarl_check_and(arena, focus_node, all_pass, path, shape_id, severity, message);
                    if (_mv_200.has_value) {
                        __auto_type r = _mv_200.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_200.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_or:
            {
                __auto_type shape_refs = _mv_183.data.con_or;
                {
                    __auto_type any_pass = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_201 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                            if (_mv_201.has_value) {
                                __auto_type ref_ps = _mv_201.value;
                                if (snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_ps)) {
                                    any_pass = 1;
                                }
                            } else if (!_mv_201.has_value) {
                                {
                                    __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                    __auto_type _mv_202 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                    if (_mv_202.has_value) {
                                        __auto_type ref_shape = _mv_202.value;
                                        if (snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, rec_visited)) {
                                            any_pass = 1;
                                        }
                                    } else if (!_mv_202.has_value) {
                                    }
                                }
                            }
                        }
                    }
                    __auto_type _mv_203 = snarl_check_or(arena, focus_node, any_pass, path, shape_id, severity, message);
                    if (_mv_203.has_value) {
                        __auto_type r = _mv_203.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_203.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_xone:
            {
                __auto_type shape_refs = _mv_183.data.con_xone;
                {
                    __auto_type pass_count = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_204 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                            if (_mv_204.has_value) {
                                __auto_type ref_ps = _mv_204.value;
                                if (snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_ps)) {
                                    pass_count = (pass_count + 1);
                                }
                            } else if (!_mv_204.has_value) {
                                {
                                    __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                    __auto_type _mv_205 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                    if (_mv_205.has_value) {
                                        __auto_type ref_shape = _mv_205.value;
                                        if (snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, rec_visited)) {
                                            pass_count = (pass_count + 1);
                                        }
                                    } else if (!_mv_205.has_value) {
                                    }
                                }
                            }
                        }
                    }
                    __auto_type _mv_206 = snarl_check_xone(arena, focus_node, pass_count, path, shape_id, severity, message);
                    if (_mv_206.has_value) {
                        __auto_type r = _mv_206.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_206.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_node:
            {
                __auto_type shape_ref = _mv_183.data.con_node;
                {
                    __auto_type value_conforms = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(shape_ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_ps = _mv.value; snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_ps); }) : (({ __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term); ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); }); ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, rec_visited); }) : (1); }); })); });
                    __auto_type _mv_207 = snarl_check_node(arena, focus_node, value_node, value_conforms, path, shape_id, severity, message);
                    if (_mv_207.has_value) {
                        __auto_type r = _mv_207.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_207.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_property:
            {
                __auto_type _ = _mv_183.data.con_property;
                break;
            }
            case types_Constraint_con_qualified_value_shape:
            {
                break;
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs) {
    {
        __auto_type class_index = target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
    }
}

slop_list_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs) {
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_208 = constraint;
        switch (_mv_208.tag) {
            case types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_208.data.con_min_count;
                __auto_type _mv_209 = snarl_check_min_count(arena, focus_node, value_count, min_c, path, shape_id, severity, message);
                if (_mv_209.has_value) {
                    __auto_type r = _mv_209.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_209.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_208.data.con_max_count;
                __auto_type _mv_210 = snarl_check_max_count(arena, focus_node, value_count, max_c, path, shape_id, severity, message);
                if (_mv_210.has_value) {
                    __auto_type r = _mv_210.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_210.has_value) {
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_208.data.con_unique_lang;
                if (b) {
                    {
                        __auto_type ul_results = snarl_check_unique_lang(arena, focus_node, value_nodes, path, shape_id, severity, message);
                        {
                            __auto_type _coll = ul_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_208.data.con_has_value;
                __auto_type _mv_211 = snarl_check_has_value(arena, focus_node, value_nodes, required_value, path, shape_id, severity, message);
                if (_mv_211.has_value) {
                    __auto_type r = _mv_211.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_211.has_value) {
                }
                break;
            }
            case types_Constraint_con_closed:
            {
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_208.data.con_equals;
                {
                    __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = eq_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_208.data.con_disjoint;
                {
                    __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = dj_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_208.data.con_less_than;
                {
                    __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = lt_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_208.data.con_less_than_or_equals;
                {
                    __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = le_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_qualified_value_shape:
            {
                __auto_type shape_ref = _mv_208.data.con_qualified_value_shape.f0;
                __auto_type q_min = _mv_208.data.con_qualified_value_shape.f1;
                __auto_type q_max = _mv_208.data.con_qualified_value_shape.f2;
                __auto_type disjoint = _mv_208.data.con_qualified_value_shape.f3;
                {
                    __auto_type conforming_count = 0;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); });
                                __auto_type _mv_212 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                if (_mv_212.has_value) {
                                    __auto_type ref_shape = _mv_212.value;
                                    if (snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, vn, ref_shape, rec_visited)) {
                                        if (disjoint && (((int64_t)((sibling_qvs_refs).len)) > 0)) {
                                            {
                                                __auto_type conforms_to_sibling = 0;
                                                {
                                                    __auto_type _coll = sibling_qvs_refs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type sib_ref = _coll.data[_i];
                                                        {
                                                            __auto_type sib_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                                            ({ uint8_t _dummy = 1; slop_map_put(arena, sib_visited, &(sib_ref), &_dummy); });
                                                            __auto_type _mv_213 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(sib_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                                            if (_mv_213.has_value) {
                                                                __auto_type sib_shape = _mv_213.value;
                                                                if (snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, vn, sib_shape, sib_visited)) {
                                                                    conforms_to_sibling = 1;
                                                                }
                                                            } else if (!_mv_213.has_value) {
                                                            }
                                                        }
                                                    }
                                                }
                                                if (!(conforms_to_sibling)) {
                                                    conforming_count = (conforming_count + 1);
                                                }
                                            }
                                        } else {
                                            conforming_count = (conforming_count + 1);
                                        }
                                    }
                                } else if (!_mv_212.has_value) {
                                }
                            }
                        }
                    }
                    {
                        __auto_type qvs_results = snarl_check_qualified_value_shape(arena, focus_node, conforming_count, q_min, q_max, path, shape_id, severity, message);
                        {
                            __auto_type _coll = qvs_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_property:
            {
                __auto_type ps_ref = _mv_208.data.con_property;
                __auto_type _mv_214 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ps_ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                if (_mv_214.has_value) {
                    __auto_type ref_ps = _mv_214.value;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                __auto_type empty_siblings = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                                __auto_type ps_results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ref_ps, vn, rec_visited, types_default_validator_config(), empty_siblings);
                                {
                                    __auto_type _coll = ps_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_214.has_value) {
                }
                break;
            }
            default: {
                {
                    __auto_type _coll = value_nodes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type value_node = _coll.data[_i];
                        {
                            __auto_type vr = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
                            {
                                __auto_type _coll = vr;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult engine_evaluate_constraint_for_simple_predicate_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph, target_ClassIndex class_index, rdf_Term focus_node, rdf_Term pred, slop_option_index_TermSet value_set, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs) {
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_215 = constraint;
        switch (_mv_215.tag) {
            case types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_215.data.con_min_count;
                __auto_type _mv_216 = snarl_check_min_count(arena, focus_node, value_count, min_c, path, shape_id, severity, message);
                if (_mv_216.has_value) {
                    __auto_type r = _mv_216.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_216.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_215.data.con_max_count;
                __auto_type _mv_217 = snarl_check_max_count(arena, focus_node, value_count, max_c, path, shape_id, severity, message);
                if (_mv_217.has_value) {
                    __auto_type r = _mv_217.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_217.has_value) {
                }
                break;
            }
            case types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_215.data.con_has_value;
                if (!(data_graph_snarl_data_graph_has_object(data_graph, focus_node, pred, required_value))) {
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_HAS_VALUE, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case types_Constraint_con_closed:
            {
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_215.data.con_equals;
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = eq_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_215.data.con_disjoint;
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = dj_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_215.data.con_less_than;
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = lt_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_215.data.con_less_than_or_equals;
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = le_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_215.data.con_unique_lang;
                if (b) {
                    {
                        __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                        __auto_type ul_results = snarl_check_unique_lang(arena, focus_node, value_nodes, path, shape_id, severity, message);
                        {
                            __auto_type _coll = ul_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_qualified_value_shape:
            {
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type qvs_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = qvs_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_Constraint_con_property:
            {
                __auto_type _ = _mv_215.data.con_property;
                {
                    __auto_type value_nodes = engine_optional_term_set_to_list(arena, value_set);
                    __auto_type property_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = property_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            default: {
                __auto_type _mv_218 = value_set;
                if (_mv_218.has_value) {
                    __auto_type terms = _mv_218.value;
                    {
                        slop_map* _coll = (slop_map*)terms;
                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                            if (_coll->entries[_i].occupied) {
                                rdf_Term value_node = *(rdf_Term*)_coll->entries[_i].key;
                                {
                                    __auto_type vr = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
                                    {
                                        __auto_type _coll = vr;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type r = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_218.has_value) {
                }
                break;
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

