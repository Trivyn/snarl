#include "../runtime/slop_runtime.h"
#include "slop_target.h"

static const slop_string target_EX_ALICE = SLOP_STR("http://example.org/alice");
static const slop_string target_EX_BOB = SLOP_STR("http://example.org/bob");
static const slop_string target_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string target_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string target_EX_NAME = SLOP_STR("http://example.org/name");
static const slop_string target_EX_KNOWS = SLOP_STR("http://example.org/knows");

index_IndexedGraph target_fixture_g_typed(slop_arena* arena);
index_IndexedGraph target_fixture_g_alice_name(slop_arena* arena);
index_IndexedGraph target_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_rdf_Term target_fixture_target_nodes_alice(slop_arena* arena);
types_NodeShape target_fixture_ns_target_class(slop_arena* arena);
slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, index_IndexedGraph data_graph, types_NodeShape shape);
slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes);
slop_list_rdf_Term target_find_subclasses(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term shape_id);

index_IndexedGraph target_fixture_g_typed(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, target_EX_PERSON)));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_BOB), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, target_EX_PERSON)));
        return g;
    }
}

index_IndexedGraph target_fixture_g_alice_name(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, target_EX_NAME), rdf_make_iri(arena, SLOP_STR("http://example.org/AliceName"))));
        return g;
    }
}

index_IndexedGraph target_fixture_g_alice_knows_bob(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, target_EX_KNOWS), rdf_make_iri(arena, target_EX_BOB)));
        return g;
    }
}

slop_list_rdf_Term target_fixture_target_nodes_alice(slop_arena* arena) {
    {
        __auto_type nodes = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(nodes); __auto_type _item = (rdf_make_iri(arena, target_EX_ALICE)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return nodes;
    }
}

types_NodeShape target_fixture_ns_target_class(slop_arena* arena) {
    return ((types_NodeShape){.id = rdf_make_iri(arena, target_EX_SHAPE), .target_nodes = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 }), .target_classes = ({ __auto_type tc = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 }); ({ __auto_type _lst_p = &(tc); __auto_type _item = (rdf_make_iri(arena, target_EX_PERSON)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; }); tc; }), .target_subjects_of = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 }), .target_objects_of = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 }), .property_shapes = ((slop_list_types_PropertyShape){ .data = (types_PropertyShape*)slop_arena_alloc(arena, 16 * sizeof(types_PropertyShape)), .len = 0, .cap = 16 }), .constraints = ((slop_list_types_Constraint){ .data = (types_Constraint*)slop_arena_alloc(arena, 16 * sizeof(types_Constraint)), .len = 0, .cap = 16 }), .severity = types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = 0});
}

slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, index_IndexedGraph data_graph, types_NodeShape shape) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = shape.target_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type node = _coll.data[_i];
                if (!((slop_map_get(seen, &(node)) != NULL))) {
                    ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(node), &_dummy); });
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (node); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type _coll = shape.target_classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type cls = _coll.data[_i];
                {
                    __auto_type instances = snarl_resolve_target_class(arena, data_graph, cls);
                    {
                        __auto_type _coll = instances;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type inst = _coll.data[_i];
                            if (!((slop_map_get(seen, &(inst)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(inst), &_dummy); });
                                ({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = shape.target_subjects_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type pred = _coll.data[_i];
                {
                    __auto_type subjects = snarl_resolve_target_subjects_of(arena, data_graph, pred);
                    {
                        __auto_type _coll = subjects;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type subj = _coll.data[_i];
                            if (!((slop_map_get(seen, &(subj)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(subj), &_dummy); });
                                ({ __auto_type _lst_p = &(result); __auto_type _item = (subj); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = shape.target_objects_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type pred = _coll.data[_i];
                {
                    __auto_type objects = snarl_resolve_target_objects_of(arena, data_graph, pred);
                    {
                        __auto_type _coll = objects;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type obj = _coll.data[_i];
                            if (!((slop_map_get(seen, &(obj)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(obj), &_dummy); });
                                ({ __auto_type _lst_p = &(result); __auto_type _item = (obj); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type implicit = snarl_resolve_implicit_class_targets(arena, data_graph, shape.id);
            {
                __auto_type _coll = implicit;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type inst = _coll.data[_i];
                    if (!((slop_map_get(seen, &(inst)) != NULL))) {
                        ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(inst), &_dummy); });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes) {
    slop_list_rdf_Term _retval = {0};
    _retval = nodes;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)((nodes).len)))), "(== (list-len $result) (list-len nodes))");
    return _retval;
}

slop_list_rdf_Term target_find_subclasses(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term) {
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type subclass_pred = rdf_make_iri(arena, vocab_RDFS_SUBCLASS_OF);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        int64_t qi = 0;
        ({ __auto_type _lst_p = &(queue); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(class_term), &_dummy); });
        while ((qi < ((int64_t)((queue).len)))) {
            __auto_type _mv_116 = ({ __auto_type _lst = queue; size_t _idx = (size_t)qi; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_116.has_value) {
                __auto_type current = _mv_116.value;
                ({ __auto_type _lst_p = &(result); __auto_type _item = (current); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                {
                    __auto_type subs = rdf_indexed_graph_subjects(arena, data_graph, subclass_pred, current);
                    {
                        __auto_type _coll = subs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type sub = _coll.data[_i];
                            if (!((slop_map_get(visited, &(sub)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(sub), &_dummy); });
                                ({ __auto_type _lst_p = &(queue); __auto_type _item = (sub); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            } else if (!_mv_116.has_value) {
            }
            qi = (qi + 1);
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 1)), "(>= (list-len $result) 1)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type all_classes = target_find_subclasses(arena, data_graph, class_term);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = all_classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type cls = _coll.data[_i];
                {
                    __auto_type instances = rdf_indexed_graph_subjects(arena, data_graph, type_pred, cls);
                    {
                        __auto_type _coll = instances;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type inst = _coll.data[_i];
                            if (!((slop_map_get(seen, &(inst)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(inst), &_dummy); });
                                ({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    {
        slop_option_rdf_Term no_term = (slop_option_rdf_Term){.has_value = false};
        __auto_type matches = rdf_indexed_graph_match(arena, data_graph, no_term, (slop_option_rdf_Term){.has_value = 1, .value = predicate}, no_term);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = matches;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                {
                    __auto_type subj = rdf_triple_subject(t);
                    if (!((slop_map_get(seen, &(subj)) != NULL))) {
                        ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(subj), &_dummy); });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (subj); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    {
        slop_option_rdf_Term no_term = (slop_option_rdf_Term){.has_value = false};
        __auto_type matches = rdf_indexed_graph_match(arena, data_graph, no_term, (slop_option_rdf_Term){.has_value = 1, .value = predicate}, no_term);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = matches;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                {
                    __auto_type obj = rdf_triple_object(t);
                    if (!((slop_map_get(seen, &(obj)) != NULL))) {
                        ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(obj), &_dummy); });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (obj); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term shape_id) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    _retval = snarl_resolve_target_class(arena, data_graph, shape_id);
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

