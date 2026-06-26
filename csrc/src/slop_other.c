#include "../runtime/slop_runtime.h"
#include "slop_other.h"

static const slop_string other_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string other_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string other_EX_A = SLOP_STR("http://example.org/a");
static const slop_string other_EX_B = SLOP_STR("http://example.org/b");
static const slop_string other_EX_C = SLOP_STR("http://example.org/c");
static const slop_string other_EX_NAME = SLOP_STR("http://example.org/name");

slop_list_rdf_Term other_fixture_term_list_ab(slop_arena* arena);
slop_list_rdf_Term other_fixture_allowed_terms_abc(slop_arena* arena);
slop_list_types_ShaclPath other_fixture_allowed_path_name(slop_arena* arena);
index_IndexedGraph other_fixture_g_focus_name(slop_arena* arena);
index_IndexedGraph other_fixture_g_focus_name_age(slop_arena* arena);
uint8_t other_list_contains_term(slop_list_rdf_Term terms, rdf_Term target);
slop_option_types_ValidationResult snarl_check_has_value(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, rdf_Term required_value, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_rdf_Term allowed_values, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_closed(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_types_ShaclPath allowed_paths, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_list_rdf_Term other_fixture_term_list_ab(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, other_EX_A)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, other_EX_B)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return terms;
    }
}

slop_list_rdf_Term other_fixture_allowed_terms_abc(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, other_EX_A)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, other_EX_B)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_iri(arena, other_EX_C)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return terms;
    }
}

slop_list_types_ShaclPath other_fixture_allowed_path_name(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = rdf_make_iri(arena, other_EX_NAME) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return paths;
    }
}

index_IndexedGraph other_fixture_g_focus_name(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, other_EX_FOCUS), rdf_make_iri(arena, other_EX_NAME), rdf_make_literal(arena, SLOP_STR("Alice"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
        return g;
    }
}

index_IndexedGraph other_fixture_g_focus_name_age(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, other_EX_FOCUS), rdf_make_iri(arena, other_EX_NAME), rdf_make_literal(arena, SLOP_STR("Alice"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, other_EX_FOCUS), rdf_make_iri(arena, SLOP_STR("http://example.org/age")), rdf_make_literal(arena, SLOP_STR("30"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
        return g;
    }
}

uint8_t other_list_contains_term(slop_list_rdf_Term terms, rdf_Term target) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = terms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (rdf_term_eq(t, target)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_option_types_ValidationResult snarl_check_has_value(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, rdf_Term required_value, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((value_nodes).len)) >= 0)), "(>= (list-len value-nodes) 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (other_list_contains_term(value_nodes, required_value)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_HAS_VALUE, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == other_list_contains_term(value_nodes, required_value))), "(== (== $result (none)) (list-contains-term value-nodes required-value))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_rdf_Term allowed_values, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_values).len)) > 0)), "(> (list-len allowed-values) 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (other_list_contains_term(allowed_values, value_node)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_IN, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == other_list_contains_term(allowed_values, value_node))), "(== (== $result (none)) (list-contains-term allowed-values value-node))");
    return _retval;
}

slop_list_types_ValidationResult snarl_check_closed(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_types_ShaclPath allowed_paths, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_paths).len)) >= 0)), "(>= (list-len allowed-paths) 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type triples = rdf_indexed_graph_match(arena, data_graph, (slop_option_rdf_Term){.has_value = 1, .value = focus_node}, ((slop_option_rdf_Term){.has_value = false}), ((slop_option_rdf_Term){.has_value = false}));
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type triple = _coll.data[_i];
                {
                    __auto_type pred = rdf_triple_predicate(triple);
                    uint8_t allowed = 0;
                    {
                        __auto_type _coll = allowed_paths;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ap = _coll.data[_i];
                            __auto_type _mv_102 = ap;
                            switch (_mv_102.tag) {
                                case types_ShaclPath_path_predicate:
                                {
                                    __auto_type p = _mv_102.data.path_predicate;
                                    if (rdf_term_eq(p, pred)) {
                                        allowed = 1;
                                    }
                                    break;
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                    }
                    if (!(allowed)) {
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = (slop_option_types_ShaclPath){.has_value = 1, .value = ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = pred })}, .value = (slop_option_rdf_Term){.has_value = 1, .value = pred}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_CLOSED, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

