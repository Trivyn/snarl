#include "../runtime/slop_runtime.h"
#include "slop_engine.h"

uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited);
types_ValidatorResult snarl_engine_validate(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);
slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);

uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited) {
    {
        __auto_type config = types_default_validator_config();
        __auto_type results = snarl_evaluate_node_shape(arena, data_graph, shapes_graph, shape, node, visited, config);
        return (((int64_t)((results).len)) == 0);
    }
}

types_ValidatorResult snarl_engine_validate(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    {
        __auto_type report = types_make_validation_report(arena);
        int64_t error_count = 0;
        __auto_type max_errors = config.max_errors;
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                if (!(ns.deactivated)) {
                    if (((max_errors == 0) || (error_count < max_errors))) {
                        {
                            __auto_type focus_nodes = snarl_resolve_targets(arena, data_graph, ns);
                            __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                            {
                                __auto_type _coll = focus_nodes;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type focus_node = _coll.data[_i];
                                    if (((max_errors == 0) || (error_count < max_errors))) {
                                        {
                                            __auto_type results = snarl_evaluate_node_shape(arena, data_graph, shapes_graph, ns, focus_node, visited, config);
                                            {
                                                __auto_type _coll = results;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type r = _coll.data[_i];
                                                    {
                                                        __auto_type include = ({ __auto_type _mv = r.severity; uint8_t _mr = {0}; switch (_mv) { case types_Severity_severity_violation: { _mr = 1; break; } case types_Severity_severity_warning: { _mr = config.include_warnings; break; } case types_Severity_severity_info: { _mr = config.include_infos; break; }  } _mr; });
                                                        if (include) {
                                                            report = types_report_add_result(arena, report, r);
                                                            __auto_type _mv_129 = r.severity;
                                                            switch (_mv_129) {
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

slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config) {
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
                    __auto_type constraint_results = snarl_evaluate_constraint(arena, data_graph, shapes_graph, focus_node, focus_node, constraint, no_path, shape_id, shape_severity, shape_message, visited);
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
            __auto_type _coll = shape.property_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps = _coll.data[_i];
                if (!(ps.deactivated)) {
                    {
                        __auto_type ps_results = snarl_evaluate_property_shape(arena, data_graph, shapes_graph, ps, focus_node, visited, config);
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
        return results;
    }
}

slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config) {
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type shape_severity = shape.severity;
        __auto_type shape_message = shape.message;
        __auto_type shape_id = shape.id;
        __auto_type path = shape.path;
        __auto_type path_opt = (slop_option_types_ShaclPath){.has_value = 1, .value = path};
        __auto_type value_nodes = snarl_resolve_path(arena, data_graph, focus_node, path);
        __auto_type value_count = ((int64_t)((value_nodes).len));
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                {
                    __auto_type constraint_results = snarl_evaluate_constraint_for_property(arena, data_graph, shapes_graph, focus_node, value_nodes, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited);
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

slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited) {
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_130 = constraint;
        switch (_mv_130.tag) {
            case types_Constraint_con_class:
            {
                __auto_type required_class = _mv_130.data.con_class;
                __auto_type _mv_131 = snarl_check_class(arena, data_graph, focus_node, value_node, required_class, path, shape_id, severity, message);
                if (_mv_131.has_value) {
                    __auto_type r = _mv_131.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_131.has_value) {
                }
                break;
            }
            case types_Constraint_con_datatype:
            {
                __auto_type required_dt = _mv_130.data.con_datatype;
                __auto_type _mv_132 = snarl_check_datatype(arena, focus_node, value_node, required_dt, path, shape_id, severity, message);
                if (_mv_132.has_value) {
                    __auto_type r = _mv_132.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_132.has_value) {
                }
                break;
            }
            case types_Constraint_con_node_kind:
            {
                __auto_type required_kind = _mv_130.data.con_node_kind;
                __auto_type _mv_133 = snarl_check_node_kind(arena, focus_node, value_node, required_kind, path, shape_id, severity, message);
                if (_mv_133.has_value) {
                    __auto_type r = _mv_133.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_133.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_count:
            {
                __auto_type _ = _mv_130.data.con_min_count;
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type _ = _mv_130.data.con_max_count;
                break;
            }
            case types_Constraint_con_min_inclusive:
            {
                __auto_type limit = _mv_130.data.con_min_inclusive;
                __auto_type _mv_134 = snarl_check_min_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_134.has_value) {
                    __auto_type r = _mv_134.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_134.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_inclusive:
            {
                __auto_type limit = _mv_130.data.con_max_inclusive;
                __auto_type _mv_135 = snarl_check_max_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_135.has_value) {
                    __auto_type r = _mv_135.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_135.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_exclusive:
            {
                __auto_type limit = _mv_130.data.con_min_exclusive;
                __auto_type _mv_136 = snarl_check_min_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_136.has_value) {
                    __auto_type r = _mv_136.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_136.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_exclusive:
            {
                __auto_type limit = _mv_130.data.con_max_exclusive;
                __auto_type _mv_137 = snarl_check_max_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_137.has_value) {
                    __auto_type r = _mv_137.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_137.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_length:
            {
                __auto_type min_len = _mv_130.data.con_min_length;
                __auto_type _mv_138 = snarl_check_min_length(arena, focus_node, value_node, min_len, path, shape_id, severity, message);
                if (_mv_138.has_value) {
                    __auto_type r = _mv_138.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_138.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_length:
            {
                __auto_type max_len = _mv_130.data.con_max_length;
                __auto_type _mv_139 = snarl_check_max_length(arena, focus_node, value_node, max_len, path, shape_id, severity, message);
                if (_mv_139.has_value) {
                    __auto_type r = _mv_139.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_139.has_value) {
                }
                break;
            }
            case types_Constraint_con_pattern:
            {
                __auto_type pat = _mv_130.data.con_pattern;
                __auto_type _mv_140 = snarl_check_pattern(arena, focus_node, value_node, pat, path, shape_id, severity, message);
                if (_mv_140.has_value) {
                    __auto_type r = _mv_140.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_140.has_value) {
                }
                break;
            }
            case types_Constraint_con_language_in:
            {
                __auto_type _ = _mv_130.data.con_language_in;
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type _ = _mv_130.data.con_unique_lang;
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type _ = _mv_130.data.con_equals;
                break;
            }
            case types_Constraint_con_disjoint:
            {
                __auto_type _ = _mv_130.data.con_disjoint;
                break;
            }
            case types_Constraint_con_less_than:
            {
                __auto_type _ = _mv_130.data.con_less_than;
                break;
            }
            case types_Constraint_con_less_than_or_equals:
            {
                __auto_type _ = _mv_130.data.con_less_than_or_equals;
                break;
            }
            case types_Constraint_con_has_value:
            {
                __auto_type _ = _mv_130.data.con_has_value;
                break;
            }
            case types_Constraint_con_in:
            {
                __auto_type _ = _mv_130.data.con_in;
                break;
            }
            case types_Constraint_con_closed:
            {
                __auto_type _ = _mv_130.data.con_closed;
                break;
            }
            case types_Constraint_con_not:
            {
                __auto_type _ = _mv_130.data.con_not;
                break;
            }
            case types_Constraint_con_and:
            {
                __auto_type _ = _mv_130.data.con_and;
                break;
            }
            case types_Constraint_con_or:
            {
                __auto_type _ = _mv_130.data.con_or;
                break;
            }
            case types_Constraint_con_xone:
            {
                __auto_type _ = _mv_130.data.con_xone;
                break;
            }
            case types_Constraint_con_node:
            {
                __auto_type _ = _mv_130.data.con_node;
                break;
            }
            case types_Constraint_con_property:
            {
                __auto_type _ = _mv_130.data.con_property;
                break;
            }
            case types_Constraint_con_qualified_value_shape:
            {
                __auto_type _ = _mv_130.data.con_qualified_value_shape;
                break;
            }
        }
        return results;
    }
}

slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited) {
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_141 = constraint;
        switch (_mv_141.tag) {
            case types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_141.data.con_min_count;
                __auto_type _mv_142 = snarl_check_min_count(arena, focus_node, value_count, min_c, path, shape_id, severity, message);
                if (_mv_142.has_value) {
                    __auto_type r = _mv_142.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_142.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_141.data.con_max_count;
                __auto_type _mv_143 = snarl_check_max_count(arena, focus_node, value_count, max_c, path, shape_id, severity, message);
                if (_mv_143.has_value) {
                    __auto_type r = _mv_143.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_143.has_value) {
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_141.data.con_unique_lang;
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
                __auto_type _ = _mv_141.data.con_has_value;
                break;
            }
            case types_Constraint_con_in:
            {
                __auto_type _ = _mv_141.data.con_in;
                break;
            }
            case types_Constraint_con_closed:
            {
                __auto_type _ = _mv_141.data.con_closed;
                break;
            }
            default: {
                {
                    __auto_type _coll = value_nodes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type value_node = _coll.data[_i];
                        {
                            __auto_type vr = snarl_evaluate_constraint(arena, data_graph, shapes_graph, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
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
        return results;
    }
}

