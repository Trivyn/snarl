#include "../runtime/slop_runtime.h"
#include "slop_pair.h"

static const slop_string pair_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string pair_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string pair_EX_A = SLOP_STR("http://example.org/a");
static const slop_string pair_EX_B = SLOP_STR("http://example.org/b");
static const slop_string pair_EX_P2 = SLOP_STR("http://example.org/p2");

data_graph_SnarlDataGraph pair_fixture_g_focus_p2_a(slop_arena* arena);
slop_list_rdf_Term pair_fixture_term_list_a(slop_arena* arena);
slop_list_types_ValidationResult snarl_check_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_disjoint(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

data_graph_SnarlDataGraph pair_fixture_g_focus_p2_a(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, pair_EX_FOCUS), rdf_make_iri(arena, pair_EX_P2), rdf_make_iri(arena, pair_EX_A)));
        return g;
    }
}

slop_list_rdf_Term pair_fixture_term_list_a(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, pair_EX_A)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return terms;
    }
}

slop_list_types_ValidationResult snarl_check_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((value_nodes).len)) >= 0)), "(>= (list-len value-nodes) 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type other_values = snarl_resolve_path(arena, data_graph, focus_node, other_path);
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                {
                    uint8_t found = 0;
                    {
                        __auto_type _coll = other_values;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ov = _coll.data[_i];
                            if (rdf_term_eq(v, ov)) {
                                found = 1;
                            }
                        }
                    }
                    if (!(found)) {
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_EQUALS, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = other_values;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                {
                    uint8_t found = 0;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            if (rdf_term_eq(v, vn)) {
                                found = 1;
                            }
                        }
                    }
                    if (!(found)) {
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_EQUALS, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult snarl_check_disjoint(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((value_nodes).len)) >= 0)), "(>= (list-len value-nodes) 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type other_values = snarl_resolve_path(arena, data_graph, focus_node, other_path);
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                {
                    uint8_t found = 0;
                    {
                        __auto_type _coll = other_values;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ov = _coll.data[_i];
                            if (rdf_term_eq(v, ov)) {
                                found = 1;
                            }
                        }
                    }
                    if (found) {
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_DISJOINT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_types_ValidationResult snarl_check_less_than(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((value_nodes).len)) >= 0)), "(>= (list-len value-nodes) 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type other_values = snarl_resolve_path(arena, data_graph, focus_node, other_path);
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                {
                    __auto_type _coll = other_values;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        {
                            __auto_type cmp = xsd_compare(arena, v, o);
                            __auto_type _mv_133 = cmp;
                            switch (_mv_133) {
                                case xsd_XsdCompareResult_xsd_compare_less: {
                                    break;
                                }
                                default: {
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LESS_THAN, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    break;
                                }
                            }
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

slop_list_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((value_nodes).len)) >= 0)), "(>= (list-len value-nodes) 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type other_values = snarl_resolve_path(arena, data_graph, focus_node, other_path);
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                {
                    __auto_type _coll = other_values;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        {
                            __auto_type cmp = xsd_compare(arena, v, o);
                            __auto_type _mv_134 = cmp;
                            switch (_mv_134) {
                                case xsd_XsdCompareResult_xsd_compare_greater: {
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LESS_THAN_OR_EQUALS, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

