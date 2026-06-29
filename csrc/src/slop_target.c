#include "../runtime/slop_runtime.h"
#include "slop_target.h"

static const slop_string target_EX_ALICE = SLOP_STR("http://example.org/alice");
static const slop_string target_EX_BOB = SLOP_STR("http://example.org/bob");
static const slop_string target_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string target_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string target_EX_NAME = SLOP_STR("http://example.org/name");
static const slop_string target_EX_KNOWS = SLOP_STR("http://example.org/knows");

data_graph_SnarlDataGraph target_fixture_g_typed(slop_arena* arena);
data_graph_SnarlDataGraph target_fixture_g_alice_name(slop_arena* arena);
data_graph_SnarlDataGraph target_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_rdf_Term target_fixture_target_nodes_alice(slop_arena* arena);
types_NodeShape target_fixture_ns_target_class(slop_arena* arena);
slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_NodeShape shape);
target_TargetCache target_target_cache_create(slop_arena* arena);
target_TermList target_resolve_target_class_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, target_TargetCache cache, rdf_Term class_term);
slop_list_rdf_Term target_resolve_targets_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, target_TargetCache cache, types_NodeShape shape);
slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes);
void target_add_class_if_needed(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, rdf_Term class_term);
void target_collect_constraint_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_Constraint constraint);
void target_collect_property_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_PropertyShape ps);
void target_collect_node_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_NodeShape ns);
slop_list_rdf_Term target_collect_class_constraints(slop_arena* arena, types_ShapesGraph shapes_graph);
target_ClassIndex target_build_class_index(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph);
uint8_t target_class_index_has_class(target_ClassIndex index, rdf_Term class_term);
uint8_t target_class_index_has_instance(target_ClassIndex index, rdf_Term node, rdf_Term class_term);
slop_list_rdf_Term target_find_subclasses(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term class_term);
uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term node, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term shape_id);

data_graph_SnarlDataGraph target_fixture_g_typed(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, target_EX_PERSON)));
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_BOB), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, target_EX_PERSON)));
        return g;
    }
}

data_graph_SnarlDataGraph target_fixture_g_alice_name(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, target_EX_NAME), rdf_make_iri(arena, SLOP_STR("http://example.org/AliceName"))));
        return g;
    }
}

data_graph_SnarlDataGraph target_fixture_g_alice_knows_bob(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, target_EX_ALICE), rdf_make_iri(arena, target_EX_KNOWS), rdf_make_iri(arena, target_EX_BOB)));
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

slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_NodeShape shape) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
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

target_TargetCache target_target_cache_create(slop_arena* arena) {
    return ((target_TargetCache){.target_classes = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term)});
}

target_TermList target_resolve_target_class_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, target_TargetCache cache, rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    target_TermList _retval = {0};
    __auto_type _mv_122 = ({ void* _ptr = slop_map_get(cache.target_classes, &(class_term)); _ptr ? (slop_option_target_TermList){ .has_value = true, .value = *(target_TermList*)_ptr } : (slop_option_target_TermList){ .has_value = false }; });
    if (_mv_122.has_value) {
        __auto_type cached = _mv_122.value;
        return cached;
    } else if (!_mv_122.has_value) {
        {
            target_TermList resolved = snarl_resolve_target_class(arena, data_graph, class_term);
            ({ __auto_type _val = resolved; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, cache.target_classes, &(class_term), _vptr); });
            return resolved;
        }
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term target_resolve_targets_cached(slop_arena* arena, data_graph_SnarlDataGraph data_graph, target_TargetCache cache, types_NodeShape shape) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
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
                    __auto_type instances = target_resolve_target_class_cached(arena, data_graph, cache, cls);
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
            __auto_type implicit = target_resolve_target_class_cached(arena, data_graph, cache, shape.id);
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

void target_add_class_if_needed(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, rdf_Term class_term) {
    if (!((slop_map_get(seen, &(class_term)) != NULL))) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(class_term), &_dummy); });
        ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    }
}

void target_collect_constraint_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_Constraint constraint) {
    __auto_type _mv_123 = constraint;
    switch (_mv_123.tag) {
        case types_Constraint_con_class:
        {
            __auto_type class_term = _mv_123.data.con_class;
            target_add_class_if_needed(arena, classes, seen, class_term);
            break;
        }
        default: {
            break;
        }
    }
}

void target_collect_property_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_PropertyShape ps) {
    {
        __auto_type _coll = ps.constraints;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type constraint = _coll.data[_i];
            target_collect_constraint_classes(arena, classes, seen, constraint);
        }
    }
}

void target_collect_node_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_NodeShape ns) {
    {
        __auto_type _coll = ns.constraints;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type constraint = _coll.data[_i];
            target_collect_constraint_classes(arena, classes, seen, constraint);
        }
    }
    {
        __auto_type _coll = ns.property_shapes;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type ps = _coll.data[_i];
            target_collect_property_shape_classes(arena, classes, seen, ps);
        }
    }
}

slop_list_rdf_Term target_collect_class_constraints(slop_arena* arena, types_ShapesGraph shapes_graph) {
    {
        __auto_type classes = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                {
                    __auto_type _coll = ns.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type constraint = _coll.data[_i];
                        __auto_type _mv_124 = constraint;
                        switch (_mv_124.tag) {
                            case types_Constraint_con_class:
                            {
                                __auto_type class_term = _mv_124.data.con_class;
                                if (!((slop_map_get(seen, &(class_term)) != NULL))) {
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(class_term), &_dummy); });
                                    ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = ns.property_shapes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ps = _coll.data[_i];
                        {
                            __auto_type _coll = ps.constraints;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type constraint = _coll.data[_i];
                                __auto_type _mv_125 = constraint;
                                switch (_mv_125.tag) {
                                    case types_Constraint_con_class:
                                    {
                                        __auto_type class_term = _mv_125.data.con_class;
                                        if (!((slop_map_get(seen, &(class_term)) != NULL))) {
                                            ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(class_term), &_dummy); });
                                            ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        }
        {
            __auto_type _coll = shapes_graph.property_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps = _coll.data[_i];
                {
                    __auto_type _coll = ps.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type constraint = _coll.data[_i];
                        __auto_type _mv_126 = constraint;
                        switch (_mv_126.tag) {
                            case types_Constraint_con_class:
                            {
                                __auto_type class_term = _mv_126.data.con_class;
                                if (!((slop_map_get(seen, &(class_term)) != NULL))) {
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(class_term), &_dummy); });
                                    ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return classes;
    }
}

target_ClassIndex target_build_class_index(slop_arena* arena, data_graph_SnarlDataGraph data_graph, types_ShapesGraph shapes_graph) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type classes = target_collect_class_constraints(arena, shapes_graph);
        __auto_type entries = ((slop_list_target_ClassInstances){ .data = (target_ClassInstances*)slop_arena_alloc(arena, 16 * sizeof(target_ClassInstances)), .len = 0, .cap = 16 });
        __auto_type entry_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type class_term = _coll.data[_i];
                {
                    __auto_type instance_list = snarl_resolve_target_class(arena, data_graph, class_term);
                    __auto_type instances = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    {
                        __auto_type _coll = instance_list;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type inst = _coll.data[_i];
                            ({ uint8_t _dummy = 1; slop_map_put(arena, instances, &(inst), &_dummy); });
                        }
                    }
                    ({ __auto_type _val = instances; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, entry_map, &(class_term), _vptr); });
                    ({ __auto_type _lst_p = &(entries); __auto_type _item = (((target_ClassInstances){.class_term = class_term, .instances = instances})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((target_ClassIndex){.entries = entries, .entry_map = entry_map});
    }
}

uint8_t target_class_index_has_class(target_ClassIndex index, rdf_Term class_term) {
    __auto_type _mv_127 = ({ void* _ptr = slop_map_get(index.entry_map, &(class_term)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_127.has_value) {
        __auto_type _ = _mv_127.value;
        return 1;
    } else if (!_mv_127.has_value) {
        return 0;
    }
}

uint8_t target_class_index_has_instance(target_ClassIndex index, rdf_Term node, rdf_Term class_term) {
    __auto_type _mv_128 = ({ void* _ptr = slop_map_get(index.entry_map, &(class_term)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_128.has_value) {
        __auto_type instances = _mv_128.value;
        return (slop_map_get(instances, &(node)) != NULL);
    } else if (!_mv_128.has_value) {
        return 0;
    }
}

slop_list_rdf_Term target_find_subclasses(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term class_term) {
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type subclass_pred = rdf_make_iri(arena, vocab_RDFS_SUBCLASS_OF);
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        int64_t qi = 0;
        ({ __auto_type _lst_p = &(queue); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(class_term), &_dummy); });
        while (qi < ((int64_t)((queue).len))) {
            __auto_type _mv_129 = ({ __auto_type _lst = queue; size_t _idx = (size_t)qi; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_129.has_value) {
                __auto_type current = _mv_129.value;
                ({ __auto_type _lst_p = &(result); __auto_type _item = (current); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                {
                    __auto_type subs = snarl_data_graph_subjects(arena, data_graph, subclass_pred, current);
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
            } else if (!_mv_129.has_value) {
            }
            qi = (qi + 1);
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 1)), "(>= (list-len $result) 1)");
    return _retval;
}

uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term node, rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type all_classes = target_find_subclasses(arena, data_graph, class_term);
        uint8_t result = 0;
        {
            __auto_type _coll = all_classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type cls = _coll.data[_i];
                if (!(result)) {
                    {
                        __auto_type type_triple = ((rdf_Triple){.subject = node, .predicate = type_pred, .object = cls});
                        if (snarl_data_graph_contains(data_graph, type_triple)) {
                            result = 1;
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
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
                    __auto_type instances = snarl_data_graph_subjects(arena, data_graph, type_pred, cls);
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

slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term predicate) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    _retval = snarl_data_graph_subjects_of(arena, data_graph, predicate);
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term predicate) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    _retval = snarl_data_graph_objects_of(arena, data_graph, predicate);
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term shape_id) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_rdf_Term _retval = {0};
    _retval = snarl_resolve_target_class(arena, data_graph, shape_id);
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

