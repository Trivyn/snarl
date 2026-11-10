#include "../runtime/slop_runtime.h"
#include "slop_pair.h"

static const slop_string snarl_pair_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_pair_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string snarl_pair_EX_A = SLOP_STR("http://example.org/a");
static const slop_string snarl_pair_EX_B = SLOP_STR("http://example.org/b");
static const slop_string snarl_pair_EX_P2 = SLOP_STR("http://example.org/p2");

snarl_data_graph_SnarlDataGraph snarl_pair_fixture_g_focus_p2_a(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_pair_fixture_term_list_a(slop_arena* arena);
slop_list_snarl_types_ValidationResult snarl_check_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_disjoint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

snarl_data_graph_SnarlDataGraph snarl_pair_fixture_g_focus_p2_a(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_pair_EX_FOCUS), rdf_make_iri(arena, snarl_pair_EX_P2), rdf_make_iri(arena, snarl_pair_EX_A)));
        return g;
    }
}

slop_list_slop_rdf_rdf_Term snarl_pair_fixture_term_list_a(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, snarl_pair_EX_A)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return terms;
    }
}

slop_list_snarl_types_ValidationResult snarl_check_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                        (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_EQUALS_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                        (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_EQUALS_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return results;
    }
}

slop_list_snarl_types_ValidationResult snarl_check_disjoint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                        (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_DISJOINT_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return results;
    }
}

slop_list_snarl_types_ValidationResult snarl_check_less_than(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                            __auto_type cmp = snarl_literal_compare(arena, v, o);
                            __auto_type _mv_310 = cmp;
                            switch (_mv_310) {
                                case slop_rdf_xsd_XsdCompareResult_xsd_compare_less: {
                                    break;
                                }
                                default: {
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_LESS_THAN_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    break;
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

slop_list_snarl_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                            __auto_type cmp = snarl_literal_compare(arena, v, o);
                            __auto_type _mv_311 = cmp;
                            switch (_mv_311) {
                                case slop_rdf_xsd_XsdCompareResult_xsd_compare_greater: {
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = v}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_LESS_THAN_OR_EQUALS_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return results;
    }
}

