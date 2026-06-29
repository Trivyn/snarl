#include "../runtime/slop_runtime.h"
#include "slop_path.h"

static const slop_string path_EX_ALICE = SLOP_STR("http://example.org/alice");
static const slop_string path_EX_BOB = SLOP_STR("http://example.org/bob");
static const slop_string path_EX_NAME = SLOP_STR("http://example.org/name");
static const slop_string path_EX_KNOWS = SLOP_STR("http://example.org/knows");
static const slop_string path_EX_NEXT = SLOP_STR("http://example.org/next");
static const slop_string path_EX_A = SLOP_STR("http://example.org/a");
static const slop_string path_EX_B = SLOP_STR("http://example.org/b");
static const slop_string path_EX_C = SLOP_STR("http://example.org/c");

data_graph_SnarlDataGraph path_fixture_g_alice_name(slop_arena* arena);
data_graph_SnarlDataGraph path_fixture_g_chain(slop_arena* arena);
data_graph_SnarlDataGraph path_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_types_ShaclPath path_fixture_path_seq_knows_name(slop_arena* arena);
slop_list_rdf_Term snarl_resolve_path(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, types_ShaclPath path);
slop_list_rdf_Term snarl_resolve_path_from(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term object, types_ShaclPath path);
slop_list_rdf_Term path_resolve_sequence(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, slop_list_types_ShaclPath steps);
slop_list_rdf_Term path_resolve_alternative(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, slop_list_types_ShaclPath alts);
slop_list_rdf_Term path_resolve_inverse(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner);
slop_list_rdf_Term path_resolve_zero_or_more(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner);
slop_list_rdf_Term path_resolve_one_or_more(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner);
slop_list_rdf_Term path_resolve_zero_or_one(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner);

data_graph_SnarlDataGraph path_fixture_g_alice_name(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, path_EX_ALICE), rdf_make_iri(arena, path_EX_NAME), rdf_make_literal(arena, SLOP_STR("Alice"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
        return g;
    }
}

data_graph_SnarlDataGraph path_fixture_g_chain(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, path_EX_A), rdf_make_iri(arena, path_EX_NEXT), rdf_make_iri(arena, path_EX_B)));
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, path_EX_B), rdf_make_iri(arena, path_EX_NEXT), rdf_make_iri(arena, path_EX_C)));
        return g;
    }
}

data_graph_SnarlDataGraph path_fixture_g_alice_knows_bob(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, path_EX_ALICE), rdf_make_iri(arena, path_EX_KNOWS), rdf_make_iri(arena, path_EX_BOB)));
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, path_EX_BOB), rdf_make_iri(arena, path_EX_NAME), rdf_make_literal(arena, SLOP_STR("Bob"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
        return g;
    }
}

slop_list_types_ShaclPath path_fixture_path_seq_knows_name(slop_arena* arena) {
    {
        __auto_type steps = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(steps); __auto_type _item = (((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = rdf_make_iri(arena, path_EX_KNOWS) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(steps); __auto_type _item = (((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = rdf_make_iri(arena, path_EX_NAME) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return steps;
    }
}

slop_list_rdf_Term snarl_resolve_path(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, types_ShaclPath path) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    __auto_type _mv_112 = path;
    switch (_mv_112.tag) {
        case types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_112.data.path_predicate;
            return snarl_data_graph_objects(arena, data_graph, focus_node, pred);
        }
        case types_ShaclPath_path_sequence:
        {
            __auto_type steps = _mv_112.data.path_sequence;
            return path_resolve_sequence(arena, data_graph, focus_node, steps);
        }
        case types_ShaclPath_path_alternative:
        {
            __auto_type alternatives = _mv_112.data.path_alternative;
            return path_resolve_alternative(arena, data_graph, focus_node, alternatives);
        }
        case types_ShaclPath_path_inverse:
        {
            __auto_type inner = _mv_112.data.path_inverse;
            return path_resolve_inverse(arena, data_graph, focus_node, (*inner));
        }
        case types_ShaclPath_path_zero_or_more:
        {
            __auto_type inner = _mv_112.data.path_zero_or_more;
            return path_resolve_zero_or_more(arena, data_graph, focus_node, (*inner));
        }
        case types_ShaclPath_path_one_or_more:
        {
            __auto_type inner = _mv_112.data.path_one_or_more;
            return path_resolve_one_or_more(arena, data_graph, focus_node, (*inner));
        }
        case types_ShaclPath_path_zero_or_one:
        {
            __auto_type inner = _mv_112.data.path_zero_or_one;
            return path_resolve_zero_or_one(arena, data_graph, focus_node, (*inner));
        }
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_path_from(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term object, types_ShaclPath path) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    __auto_type _mv_113 = path;
    switch (_mv_113.tag) {
        case types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_113.data.path_predicate;
            return snarl_data_graph_subjects(arena, data_graph, pred, object);
        }
        default: {
            return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        }
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term path_resolve_sequence(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, slop_list_types_ShaclPath steps) {
    {
        __auto_type current_nodes = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(current_nodes); __auto_type _item = (focus); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = steps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type step = _coll.data[_i];
                {
                    __auto_type next_nodes = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
                    {
                        __auto_type _coll = current_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type node = _coll.data[_i];
                            {
                                __auto_type step_results = snarl_resolve_path(arena, g, node, step);
                                {
                                    __auto_type _coll = step_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(next_nodes); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                    current_nodes = next_nodes;
                }
            }
        }
        return current_nodes;
    }
}

slop_list_rdf_Term path_resolve_alternative(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, slop_list_types_ShaclPath alts) {
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = alts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type alt = _coll.data[_i];
                {
                    __auto_type alt_results = snarl_resolve_path(arena, g, focus, alt);
                    {
                        __auto_type _coll = alt_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(result); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_list_rdf_Term path_resolve_inverse(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner) {
    __auto_type _mv_114 = inner;
    switch (_mv_114.tag) {
        case types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_114.data.path_predicate;
            return snarl_data_graph_subjects(arena, g, pred, focus);
        }
        case types_ShaclPath_path_inverse:
        {
            __auto_type inner2 = _mv_114.data.path_inverse;
            return snarl_resolve_path(arena, g, focus, (*inner2));
        }
        default: {
            return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        }
    }
}

slop_list_rdf_Term path_resolve_zero_or_more(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner) {
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        int64_t qi = 0;
        ({ __auto_type _lst_p = &(queue); __auto_type _item = (focus); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (qi < ((int64_t)((queue).len))) {
            __auto_type _mv_115 = ({ __auto_type _lst = queue; size_t _idx = (size_t)qi; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_115.has_value) {
                __auto_type current = _mv_115.value;
                qi = (qi + 1);
                if (!((slop_map_get(visited, &(current)) != NULL))) {
                    ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(current), &_dummy); });
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (current); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type next = snarl_resolve_path(arena, g, current, inner);
                        {
                            __auto_type _coll = next;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type n = _coll.data[_i];
                                if (!((slop_map_get(visited, &(n)) != NULL))) {
                                    ({ __auto_type _lst_p = &(queue); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_115.has_value) {
                qi = (qi + 1);
            }
        }
        return result;
    }
}

slop_list_rdf_Term path_resolve_one_or_more(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner) {
    {
        __auto_type first_step = snarl_resolve_path(arena, g, focus, inner);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        int64_t qi = 0;
        {
            __auto_type _coll = first_step;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type node = _coll.data[_i];
                ({ __auto_type _lst_p = &(queue); __auto_type _item = (node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        while (qi < ((int64_t)((queue).len))) {
            __auto_type _mv_116 = ({ __auto_type _lst = queue; size_t _idx = (size_t)qi; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_116.has_value) {
                __auto_type current = _mv_116.value;
                qi = (qi + 1);
                if (!((slop_map_get(visited, &(current)) != NULL))) {
                    ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(current), &_dummy); });
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (current); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type next = snarl_resolve_path(arena, g, current, inner);
                        {
                            __auto_type _coll = next;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type n = _coll.data[_i];
                                if (!((slop_map_get(visited, &(n)) != NULL))) {
                                    ({ __auto_type _lst_p = &(queue); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_116.has_value) {
                qi = (qi + 1);
            }
        }
        return result;
    }
}

slop_list_rdf_Term path_resolve_zero_or_one(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term focus, types_ShaclPath inner) {
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(focus), &_dummy); });
        ({ __auto_type _lst_p = &(result); __auto_type _item = (focus); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type one_step = snarl_resolve_path(arena, g, focus, inner);
            {
                __auto_type _coll = one_step;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type n = _coll.data[_i];
                    if (!((slop_map_get(visited, &(n)) != NULL))) {
                        ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(n), &_dummy); });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return result;
    }
}

