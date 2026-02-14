#include "../runtime/slop_runtime.h"
#include "slop_engine.h"

uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited);
types_ValidatorResult snarl_engine_validate(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);
slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs);

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
                                                            __auto_type _mv_135 = r.severity;
                                                            switch (_mv_135) {
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
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                __auto_type _mv_136 = constraint;
                if (_mv_136.tag == types_Constraint_con_closed && _mv_136.data.con_closed.f0 == 1) {
                    __auto_type ignored_paths = _mv_136.data.con_closed.f1;
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
                            while ((i < ign_len)) {
                                __auto_type _mv_137 = ({ __auto_type _lst = ignored_paths; size_t _idx = (size_t)i; slop_option_types_ShaclPath _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_137.has_value) {
                                    __auto_type ip = _mv_137.value;
                                    ({ __auto_type _lst_p = &(allowed_paths); __auto_type _item = (ip); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (!_mv_137.has_value) {
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
                                __auto_type _mv_138 = c;
                                switch (_mv_138.tag) {
                                    case types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_138.data.con_qualified_value_shape.f0;
                                        __auto_type disjoint = _mv_138.data.con_qualified_value_shape.f3;
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
                            while ((i < n)) {
                                __auto_type _mv_139 = ({ __auto_type _lst = all_disjoint_ps_ids; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_139.has_value) {
                                    __auto_type pid = _mv_139.value;
                                    if (!(rdf_term_eq(pid, ps_id))) {
                                        __auto_type _mv_140 = ({ __auto_type _lst = all_disjoint_qvs; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_140.has_value) {
                                            __auto_type ref = _mv_140.value;
                                            ({ __auto_type _lst_p = &(sibling_refs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_140.has_value) {
                                        }
                                    }
                                } else if (!_mv_139.has_value) {
                                }
                                i = (i + 1);
                            }
                            {
                                __auto_type ps_results = snarl_evaluate_property_shape(arena, data_graph, shapes_graph, ps, focus_node, visited, config, sibling_refs);
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

slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs) {
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
                    __auto_type constraint_results = snarl_evaluate_constraint_for_property(arena, data_graph, shapes_graph, focus_node, value_nodes, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited, sibling_qvs_refs);
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
        __auto_type _mv_141 = constraint;
        switch (_mv_141.tag) {
            case types_Constraint_con_class:
            {
                __auto_type required_class = _mv_141.data.con_class;
                __auto_type _mv_142 = snarl_check_class(arena, data_graph, focus_node, value_node, required_class, path, shape_id, severity, message);
                if (_mv_142.has_value) {
                    __auto_type r = _mv_142.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_142.has_value) {
                }
                break;
            }
            case types_Constraint_con_datatype:
            {
                __auto_type required_dt = _mv_141.data.con_datatype;
                __auto_type _mv_143 = snarl_check_datatype(arena, focus_node, value_node, required_dt, path, shape_id, severity, message);
                if (_mv_143.has_value) {
                    __auto_type r = _mv_143.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_143.has_value) {
                }
                break;
            }
            case types_Constraint_con_node_kind:
            {
                __auto_type required_kind = _mv_141.data.con_node_kind;
                __auto_type _mv_144 = snarl_check_node_kind(arena, focus_node, value_node, required_kind, path, shape_id, severity, message);
                if (_mv_144.has_value) {
                    __auto_type r = _mv_144.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_144.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_count:
            {
                __auto_type _ = _mv_141.data.con_min_count;
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type _ = _mv_141.data.con_max_count;
                break;
            }
            case types_Constraint_con_min_inclusive:
            {
                __auto_type limit = _mv_141.data.con_min_inclusive;
                __auto_type _mv_145 = snarl_check_min_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_145.has_value) {
                    __auto_type r = _mv_145.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_145.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_inclusive:
            {
                __auto_type limit = _mv_141.data.con_max_inclusive;
                __auto_type _mv_146 = snarl_check_max_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_146.has_value) {
                    __auto_type r = _mv_146.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_146.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_exclusive:
            {
                __auto_type limit = _mv_141.data.con_min_exclusive;
                __auto_type _mv_147 = snarl_check_min_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_147.has_value) {
                    __auto_type r = _mv_147.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_147.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_exclusive:
            {
                __auto_type limit = _mv_141.data.con_max_exclusive;
                __auto_type _mv_148 = snarl_check_max_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_148.has_value) {
                    __auto_type r = _mv_148.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_148.has_value) {
                }
                break;
            }
            case types_Constraint_con_min_length:
            {
                __auto_type min_len = _mv_141.data.con_min_length;
                __auto_type _mv_149 = snarl_check_min_length(arena, focus_node, value_node, min_len, path, shape_id, severity, message);
                if (_mv_149.has_value) {
                    __auto_type r = _mv_149.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_149.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_length:
            {
                __auto_type max_len = _mv_141.data.con_max_length;
                __auto_type _mv_150 = snarl_check_max_length(arena, focus_node, value_node, max_len, path, shape_id, severity, message);
                if (_mv_150.has_value) {
                    __auto_type r = _mv_150.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_150.has_value) {
                }
                break;
            }
            case types_Constraint_con_pattern:
            {
                __auto_type pat = _mv_141.data.con_pattern;
                __auto_type _mv_151 = snarl_check_pattern(arena, focus_node, value_node, pat, path, shape_id, severity, message);
                if (_mv_151.has_value) {
                    __auto_type r = _mv_151.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_151.has_value) {
                }
                break;
            }
            case types_Constraint_con_language_in:
            {
                __auto_type allowed_langs = _mv_141.data.con_language_in;
                __auto_type _mv_152 = snarl_check_language_in(arena, focus_node, value_node, allowed_langs, path, shape_id, severity, message);
                if (_mv_152.has_value) {
                    __auto_type r = _mv_152.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_152.has_value) {
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type _ = _mv_141.data.con_unique_lang;
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_141.data.con_equals;
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
                __auto_type other_path = _mv_141.data.con_disjoint;
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
                __auto_type other_path = _mv_141.data.con_less_than;
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
                __auto_type other_path = _mv_141.data.con_less_than_or_equals;
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
                __auto_type required_value = _mv_141.data.con_has_value;
                {
                    __auto_type single_list = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    __auto_type _mv_153 = snarl_check_has_value(arena, focus_node, single_list, required_value, path, shape_id, severity, message);
                    if (_mv_153.has_value) {
                        __auto_type r = _mv_153.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_153.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_in:
            {
                __auto_type allowed_values = _mv_141.data.con_in;
                __auto_type _mv_154 = snarl_check_in(arena, focus_node, value_node, allowed_values, path, shape_id, severity, message);
                if (_mv_154.has_value) {
                    __auto_type r = _mv_154.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_154.has_value) {
                }
                break;
            }
            case types_Constraint_con_closed:
            {
                break;
            }
            case types_Constraint_con_not:
            {
                __auto_type shape_ref = _mv_141.data.con_not;
                {
                    __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type conforms = ({ ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); }); ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, value_node, ref_shape, rec_visited); }) : (0); }); });
                    __auto_type _mv_155 = snarl_check_not(arena, focus_node, conforms, path, shape_id, severity, message);
                    if (_mv_155.has_value) {
                        __auto_type r = _mv_155.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_155.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_and:
            {
                __auto_type shape_refs = _mv_141.data.con_and;
                {
                    __auto_type all_pass = 1;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                __auto_type _mv_156 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                if (_mv_156.has_value) {
                                    __auto_type ref_shape = _mv_156.value;
                                    if (!(snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, value_node, ref_shape, rec_visited))) {
                                        all_pass = 0;
                                    }
                                } else if (!_mv_156.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_157 = snarl_check_and(arena, focus_node, all_pass, path, shape_id, severity, message);
                    if (_mv_157.has_value) {
                        __auto_type r = _mv_157.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_157.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_or:
            {
                __auto_type shape_refs = _mv_141.data.con_or;
                {
                    __auto_type any_pass = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                __auto_type _mv_158 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                if (_mv_158.has_value) {
                                    __auto_type ref_shape = _mv_158.value;
                                    if (snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, value_node, ref_shape, rec_visited)) {
                                        any_pass = 1;
                                    }
                                } else if (!_mv_158.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_159 = snarl_check_or(arena, focus_node, any_pass, path, shape_id, severity, message);
                    if (_mv_159.has_value) {
                        __auto_type r = _mv_159.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_159.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_xone:
            {
                __auto_type shape_refs = _mv_141.data.con_xone;
                {
                    __auto_type pass_count = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(ref), &_dummy); });
                                __auto_type _mv_160 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                if (_mv_160.has_value) {
                                    __auto_type ref_shape = _mv_160.value;
                                    if (snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, value_node, ref_shape, rec_visited)) {
                                        pass_count = (pass_count + 1);
                                    }
                                } else if (!_mv_160.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_161 = snarl_check_xone(arena, focus_node, pass_count, path, shape_id, severity, message);
                    if (_mv_161.has_value) {
                        __auto_type r = _mv_161.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_161.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_node:
            {
                __auto_type shape_ref = _mv_141.data.con_node;
                {
                    __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type value_conforms = ({ ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); }); ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, value_node, ref_shape, rec_visited); }) : (1); }); });
                    __auto_type _mv_162 = snarl_check_node(arena, focus_node, value_node, value_conforms, path, shape_id, severity, message);
                    if (_mv_162.has_value) {
                        __auto_type r = _mv_162.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_162.has_value) {
                    }
                }
                break;
            }
            case types_Constraint_con_property:
            {
                __auto_type _ = _mv_141.data.con_property;
                break;
            }
            case types_Constraint_con_qualified_value_shape:
            {
                break;
            }
        }
        return results;
    }
}

slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs) {
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type _mv_163 = constraint;
        switch (_mv_163.tag) {
            case types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_163.data.con_min_count;
                __auto_type _mv_164 = snarl_check_min_count(arena, focus_node, value_count, min_c, path, shape_id, severity, message);
                if (_mv_164.has_value) {
                    __auto_type r = _mv_164.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_164.has_value) {
                }
                break;
            }
            case types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_163.data.con_max_count;
                __auto_type _mv_165 = snarl_check_max_count(arena, focus_node, value_count, max_c, path, shape_id, severity, message);
                if (_mv_165.has_value) {
                    __auto_type r = _mv_165.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_165.has_value) {
                }
                break;
            }
            case types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_163.data.con_unique_lang;
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
                __auto_type required_value = _mv_163.data.con_has_value;
                __auto_type _mv_166 = snarl_check_has_value(arena, focus_node, value_nodes, required_value, path, shape_id, severity, message);
                if (_mv_166.has_value) {
                    __auto_type r = _mv_166.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_166.has_value) {
                }
                break;
            }
            case types_Constraint_con_closed:
            {
                break;
            }
            case types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_163.data.con_equals;
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
                __auto_type other_path = _mv_163.data.con_disjoint;
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
                __auto_type other_path = _mv_163.data.con_less_than;
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
                __auto_type other_path = _mv_163.data.con_less_than_or_equals;
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
                __auto_type shape_ref = _mv_163.data.con_qualified_value_shape.f0;
                __auto_type q_min = _mv_163.data.con_qualified_value_shape.f1;
                __auto_type q_max = _mv_163.data.con_qualified_value_shape.f2;
                __auto_type disjoint = _mv_163.data.con_qualified_value_shape.f3;
                {
                    __auto_type conforming_count = 0;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                ({ uint8_t _dummy = 1; slop_map_put(arena, rec_visited, &(shape_ref), &_dummy); });
                                __auto_type _mv_167 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                if (_mv_167.has_value) {
                                    __auto_type ref_shape = _mv_167.value;
                                    if (snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, vn, ref_shape, rec_visited)) {
                                        if ((disjoint && (((int64_t)((sibling_qvs_refs).len)) > 0))) {
                                            {
                                                __auto_type conforms_to_sibling = 0;
                                                {
                                                    __auto_type _coll = sibling_qvs_refs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type sib_ref = _coll.data[_i];
                                                        {
                                                            __auto_type sib_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                                            ({ uint8_t _dummy = 1; slop_map_put(arena, sib_visited, &(sib_ref), &_dummy); });
                                                            __auto_type _mv_168 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(sib_ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                                            if (_mv_168.has_value) {
                                                                __auto_type sib_shape = _mv_168.value;
                                                                if (snarl_evaluate_shape_against_node(arena, data_graph, shapes_graph, vn, sib_shape, sib_visited)) {
                                                                    conforms_to_sibling = 1;
                                                                }
                                                            } else if (!_mv_168.has_value) {
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
                                } else if (!_mv_167.has_value) {
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
                __auto_type ps_ref = _mv_163.data.con_property;
                __auto_type _mv_169 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ps_ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                if (_mv_169.has_value) {
                    __auto_type ref_ps = _mv_169.value;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            {
                                __auto_type rec_visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                                __auto_type empty_siblings = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                                __auto_type ps_results = snarl_evaluate_property_shape(arena, data_graph, shapes_graph, ref_ps, vn, rec_visited, types_default_validator_config(), empty_siblings);
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
                } else if (!_mv_169.has_value) {
                }
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

