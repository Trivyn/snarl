#include "../runtime/slop_runtime.h"
#include "slop_target.h"

slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, index_IndexedGraph data_graph, types_NodeShape shape);
slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes);
slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term shape_id);

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

slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        _retval = rdf_indexed_graph_subjects(arena, data_graph, type_pred, class_term);
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
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type instances = rdf_indexed_graph_subjects(arena, data_graph, type_pred, shape_id);
        _retval = instances;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

