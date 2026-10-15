#include "../runtime/slop_runtime.h"
#include "slop_target.h"

static const slop_string snarl_target_EX_ALICE = SLOP_STR("http://example.org/alice");
static const slop_string snarl_target_EX_BOB = SLOP_STR("http://example.org/bob");
static const slop_string snarl_target_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string snarl_target_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string snarl_target_EX_NAME = SLOP_STR("http://example.org/name");
static const slop_string snarl_target_EX_KNOWS = SLOP_STR("http://example.org/knows");

snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_typed(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_name(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_target_fixture_target_nodes_alice(slop_arena* arena);
snarl_types_NodeShape snarl_target_fixture_ns_target_class(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_resolve_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeShape shape);
snarl_target_TargetCache snarl_target_target_cache_create(slop_arena* arena);
snarl_target_TermList snarl_target_resolve_target_class_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_target_resolve_targets_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, snarl_types_NodeShape shape);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_slop_rdf_rdf_Term nodes);
slop_list_slop_rdf_rdf_Term snarl_target_collect_class_constraints(slop_arena* arena, snarl_types_ShapesGraph shapes_graph);
snarl_target_ClassIndex snarl_target_build_class_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph);
uint8_t snarl_target_class_index_has_class(snarl_target_ClassIndex index, slop_rdf_rdf_Term class_term);
uint8_t snarl_target_class_index_has_instance(snarl_target_ClassIndex index, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_target_find_subclasses(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term);
uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term shape_id);

snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_typed(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_target_EX_ALICE), rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE), rdf_make_iri(arena, snarl_target_EX_PERSON)));
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_target_EX_BOB), rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE), rdf_make_iri(arena, snarl_target_EX_PERSON)));
        return g;
    }
}

snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_name(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_target_EX_ALICE), rdf_make_iri(arena, snarl_target_EX_NAME), rdf_make_iri(arena, SLOP_STR("http://example.org/AliceName"))));
        return g;
    }
}

snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_knows_bob(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_target_EX_ALICE), rdf_make_iri(arena, snarl_target_EX_KNOWS), rdf_make_iri(arena, snarl_target_EX_BOB)));
        return g;
    }
}

slop_list_slop_rdf_rdf_Term snarl_target_fixture_target_nodes_alice(slop_arena* arena) {
    {
        __auto_type nodes = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(nodes); __auto_type _item = (rdf_make_iri(arena, snarl_target_EX_ALICE)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return nodes;
    }
}

snarl_types_NodeShape snarl_target_fixture_ns_target_class(slop_arena* arena) {
    return ((snarl_types_NodeShape){.id = rdf_make_iri(arena, snarl_target_EX_SHAPE), .target_nodes = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .target_classes = ({ __auto_type tc = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }); ({ __auto_type _lst_p = &(tc); __auto_type _item = (rdf_make_iri(arena, snarl_target_EX_PERSON)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }); tc; }), .target_subjects_of = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .target_objects_of = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .property_shapes = ((slop_list_snarl_types_PropertyShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .severity = snarl_types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = 0});
}

slop_list_slop_rdf_rdf_Term snarl_resolve_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeShape shape) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type result = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = shape.target_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type node = _coll.data[_i];
                if (!(slop_map_has(seen, &(node)))) {
                    (void)(({ slop_map_put(NULL, seen, &(node), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            if (!(slop_map_has(seen, &(inst)))) {
                                (void)(({ slop_map_put(NULL, seen, &(inst), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            if (!(slop_map_has(seen, &(subj)))) {
                                (void)(({ slop_map_put(NULL, seen, &(subj), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (subj); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            if (!(slop_map_has(seen, &(obj)))) {
                                (void)(({ slop_map_put(NULL, seen, &(obj), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (obj); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                    if (!(slop_map_has(seen, &(inst)))) {
                        (void)(({ slop_map_put(NULL, seen, &(inst), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

snarl_target_TargetCache snarl_target_target_cache_create(slop_arena* arena) {
    return ((snarl_target_TargetCache){.target_classes = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, snarl_target_TermList); slop_map_new_ptr(arena, 0, &_d); })});
}

snarl_target_TermList snarl_target_resolve_target_class_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, slop_rdf_rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    snarl_target_TermList _retval = {0};
    __auto_type _mv_238 = ({ void* _ptr = slop_map_get(cache.target_classes, &(class_term)); _ptr ? (slop_option_snarl_target_TermList){ .has_value = true, .value = *(snarl_target_TermList*)_ptr } : (slop_option_snarl_target_TermList){ .has_value = false }; });
    if (_mv_238.has_value) {
        __auto_type cached = _mv_238.value;
        _retval = cached;
        goto _slop_post;
    } else if (!_mv_238.has_value) {
        {
            snarl_target_TermList resolved = snarl_resolve_target_class(arena, data_graph, class_term);
            ({ snarl_target_TermList _val = resolved; slop_map_put(NULL, cache.target_classes, &(class_term), &_val, sizeof(_val)); });
            _retval = resolved;
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_target_resolve_targets_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, snarl_types_NodeShape shape) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type result = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = shape.target_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type node = _coll.data[_i];
                if (!(slop_map_has(seen, &(node)))) {
                    (void)(({ slop_map_put(NULL, seen, &(node), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = shape.target_classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type cls = _coll.data[_i];
                {
                    __auto_type instances = snarl_target_resolve_target_class_cached(arena, data_graph, cache, cls);
                    {
                        __auto_type _coll = instances;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type inst = _coll.data[_i];
                            if (!(slop_map_has(seen, &(inst)))) {
                                (void)(({ slop_map_put(NULL, seen, &(inst), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            if (!(slop_map_has(seen, &(subj)))) {
                                (void)(({ slop_map_put(NULL, seen, &(subj), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (subj); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            if (!(slop_map_has(seen, &(obj)))) {
                                (void)(({ slop_map_put(NULL, seen, &(obj), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (obj); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type implicit = snarl_target_resolve_target_class_cached(arena, data_graph, cache, shape.id);
            {
                __auto_type _coll = implicit;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type inst = _coll.data[_i];
                    if (!(slop_map_has(seen, &(inst)))) {
                        (void)(({ slop_map_put(NULL, seen, &(inst), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_slop_rdf_rdf_Term nodes) {
    slop_list_slop_rdf_rdf_Term _retval = {0};
    _retval = nodes;
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)((nodes).len)))), "(== (list-len $result) (list-len nodes))");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_target_collect_class_constraints(slop_arena* arena, snarl_types_ShapesGraph shapes_graph) {
    {
        __auto_type classes = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                {
                    __auto_type _coll = ns.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type constraint = _coll.data[_i];
                        __auto_type _mv_250 = constraint;
                        switch (_mv_250.tag) {
                            case snarl_types_Constraint_con_class:
                            {
                                __auto_type class_term = _mv_250.data.con_class;
                                if (!(slop_map_has(seen, &(class_term)))) {
                                    ({ slop_map_put(NULL, seen, &(class_term), NULL, 0); });
                                    ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                __auto_type _mv_253 = constraint;
                                switch (_mv_253.tag) {
                                    case snarl_types_Constraint_con_class:
                                    {
                                        __auto_type class_term = _mv_253.data.con_class;
                                        if (!(slop_map_has(seen, &(class_term)))) {
                                            ({ slop_map_put(NULL, seen, &(class_term), NULL, 0); });
                                            ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        __auto_type _mv_256 = constraint;
                        switch (_mv_256.tag) {
                            case snarl_types_Constraint_con_class:
                            {
                                __auto_type class_term = _mv_256.data.con_class;
                                if (!(slop_map_has(seen, &(class_term)))) {
                                    ({ slop_map_put(NULL, seen, &(class_term), NULL, 0); });
                                    ({ __auto_type _lst_p = &(classes); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

snarl_target_ClassIndex snarl_target_build_class_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type classes = snarl_target_collect_class_constraints(arena, shapes_graph);
        __auto_type entries = ((slop_list_snarl_target_ClassInstances){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type entry_map = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type class_term = _coll.data[_i];
                {
                    __auto_type instance_list = snarl_resolve_target_class(arena, data_graph, class_term);
                    __auto_type instances = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                    {
                        __auto_type _coll = instance_list;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type inst = _coll.data[_i];
                            (void)(({ slop_map_put(NULL, instances, &(inst), NULL, 0); }));
                        }
                    }
                    (void)(({ slop_map* _val = instances; slop_map_put(NULL, entry_map, &(class_term), &_val, sizeof(_val)); }));
                    (void)(({ __auto_type _lst_p = &(entries); __auto_type _item = (((snarl_target_ClassInstances){.class_term = class_term, .instances = instances})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((snarl_target_ClassIndex){.entries = entries, .entry_map = entry_map});
    }
}

uint8_t snarl_target_class_index_has_class(snarl_target_ClassIndex index, slop_rdf_rdf_Term class_term) {
    __auto_type _mv_262 = ({ void* _ptr = slop_map_get(index.entry_map, &(class_term)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_262.has_value) {
        __auto_type _ = _mv_262.value;
        return 1;
    } else if (!_mv_262.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_target_class_index_has_instance(snarl_target_ClassIndex index, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term) {
    __auto_type _mv_264 = ({ void* _ptr = slop_map_get(index.entry_map, &(class_term)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_264.has_value) {
        __auto_type instances = _mv_264.value;
        return slop_map_has(instances, &(node));
    } else if (!_mv_264.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_Term snarl_target_find_subclasses(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term) {
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type subclass_pred = rdf_make_iri(arena, slop_rdf_vocab_RDFS_SUBCLASS_OF);
        __auto_type result = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type visited = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type queue = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t qi = 0;
        (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (class_term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ slop_map_put(NULL, visited, &(class_term), NULL, 0); }));
        while (qi < ((int64_t)((queue).len))) {
            __auto_type _mv_267 = ({ __auto_type _lst = queue; size_t _idx = (size_t)qi; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_267.has_value) {
                __auto_type current = _mv_267.value;
                ({ __auto_type _lst_p = &(result); __auto_type _item = (current); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                {
                    __auto_type subs = snarl_data_graph_subjects(arena, data_graph, subclass_pred, current);
                    {
                        __auto_type _coll = subs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type sub = _coll.data[_i];
                            if (!(slop_map_has(visited, &(sub)))) {
                                ({ slop_map_put(NULL, visited, &(sub), NULL, 0); });
                                ({ __auto_type _lst_p = &(queue); __auto_type _item = (sub); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            } else if (!_mv_267.has_value) {
            }
            qi = (qi + 1);
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 1)), "(>= (list-len $result) 1)");
    return _retval;
}

uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        __auto_type all_classes = snarl_target_find_subclasses(arena, data_graph, class_term);
        uint8_t result = 0;
        {
            __auto_type _coll = all_classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type cls = _coll.data[_i];
                if (!(result)) {
                    {
                        __auto_type type_triple = ((slop_rdf_rdf_Triple){.subject = node, .predicate = type_pred, .object = cls});
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

slop_list_slop_rdf_rdf_Term snarl_resolve_target_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        __auto_type all_classes = snarl_target_find_subclasses(arena, data_graph, class_term);
        __auto_type result = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
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
                            if (!(slop_map_has(seen, &(inst)))) {
                                (void)(({ slop_map_put(NULL, seen, &(inst), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (inst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    _retval = snarl_data_graph_subjects_of(arena, data_graph, predicate);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    _retval = snarl_data_graph_objects_of(arena, data_graph, predicate);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term shape_id) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_list_slop_rdf_rdf_Term _retval = {0};
    _retval = snarl_resolve_target_class(arena, data_graph, shape_id);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

