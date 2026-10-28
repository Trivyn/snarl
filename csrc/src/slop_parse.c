#include "../runtime/slop_runtime.h"
#include "slop_parse.h"

uint8_t snarl_parse_shapes_graph_list_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term head);
slop_list_snarl_parse_PathScanItem snarl_parse_path_scan_work_new(slop_arena* arena);
uint8_t snarl_parse_path_node_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root);
int64_t snarl_parse_path_max_eval_depth(void);
int64_t snarl_parse_path_node_eval_depth(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root);
slop_list_slop_rdf_rdf_Term snarl_parse_path_node_eval_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_depth_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_list_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_string snarl_shapes_graph_recursion_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
uint8_t snarl_parse_shape_has_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term ref);
void snarl_parse_register_inline_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_snarl_types_NodeShape node_shapes, slop_list_snarl_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map);
snarl_types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_NodeShape snarl_parse_node_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_PropertyShape snarl_parse_property_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_ShaclPath snarl_parse_parse_path_built_or_leaf(slop_map* built, slop_rdf_rdf_Term child);
snarl_types_ShaclPath snarl_parse_parse_path_build_node(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_map* built);
snarl_types_ShaclPath snarl_parse_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term path_node);
slop_list_snarl_types_Constraint snarl_parse_constraints(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_snarl_types_NodeKind snarl_parse_node_kind(slop_rdf_rdf_Term term);
snarl_types_Severity snarl_parse_severity(slop_rdf_rdf_Term term);
snarl_types_Severity snarl_parse_parse_shape_severity(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_string snarl_parse_parse_shape_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
uint8_t snarl_parse_parse_shape_deactivated(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_int snarl_parse_term_to_int(slop_rdf_rdf_Term t);
slop_option_string snarl_parse_term_to_string(slop_rdf_rdf_Term t);
slop_option_u8 snarl_parse_term_to_bool(slop_rdf_rdf_Term t);
slop_list_string snarl_parse_parse_string_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term list_head);

uint8_t snarl_parse_shapes_graph_list_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term head) {
    {
        __auto_type rest_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_REST);
        __auto_type nil_term = rdf_make_iri(arena, slop_rdf_vocab_RDF_NIL);
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type visited = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type current = head;
        uint8_t acyclic = 1;
        uint8_t continue_walk = 1;
        while (continue_walk) {
            if (rdf_term_eq(current, nil_term)) {
                continue_walk = 0;
            } else {
                if (slop_map_has(visited, &(current))) {
                    acyclic = 0;
                    continue_walk = 0;
                } else {
                    (void)(({ slop_map_put(NULL, visited, &(current), NULL, 0); }));
                    {
                        __auto_type rest_matches = rdf_indexed_graph_match(arena, g, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = current}, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rest_pred}, no_term);
                        __auto_type _mv_420 = ({ __auto_type _lst = rest_matches; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_420.has_value) {
                            __auto_type rest_triple = _mv_420.value;
                            current = rdf_triple_object(rest_triple);
                        } else if (!_mv_420.has_value) {
                            continue_walk = 0;
                        }
                    }
                }
            }
        }
        return acyclic;
    }
}

slop_list_snarl_parse_PathScanItem snarl_parse_path_scan_work_new(slop_arena* arena) {
    return ((slop_list_snarl_parse_PathScanItem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
}

uint8_t snarl_parse_path_node_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root) {
    {
        __auto_type on_path = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type verified = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type work = snarl_parse_path_scan_work_new(arena);
        uint8_t any_cycle = 0;
        (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = root})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while ((((int64_t)((work).len)) > 0) && !(any_cycle)) {
            __auto_type _mv_421 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_421.has_value) {
                __auto_type item = _mv_421.value;
                {
                    __auto_type n = item.node;
                    if (item.is_exit) {
                        {
                            __auto_type c = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); });
                            ({ int64_t _val = (c - 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                            ({ slop_map_put(NULL, verified, &(n), NULL, 0); });
                        }
                    } else {
                        if (slop_map_has(verified, &(n))) {
                        } else if (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) > 0) {
                            any_cycle = 1;
                        } else if (1) {
                            {
                                slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
                                __auto_type first_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST));
                                __auto_type inverse_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_INVERSE_PATH));
                                __auto_type alt_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ALTERNATIVE_PATH));
                                __auto_type zom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_MORE_PATH));
                                __auto_type oom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ONE_OR_MORE_PATH));
                                __auto_type zoo_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_ONE_PATH));
                                ({ int64_t _val = (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) + 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                                ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 1, .node = n})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                if (((int64_t)((first_objs).len)) > 0) {
                                    if (!(snarl_parse_shapes_graph_list_is_acyclic(arena, g, n))) {
                                        any_cycle = 1;
                                    } else {
                                        {
                                            __auto_type elements = rdf_list_elements_indexed(arena, g, n);
                                            {
                                                __auto_type _coll = elements;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type elem = _coll.data[_i];
                                                    ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = elem})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                } else if (((int64_t)((inverse_objs).len)) > 0) {
                                    __auto_type _mv_429 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_429.has_value) {
                                        __auto_type inner = _mv_429.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_429.has_value) {
                                    }
                                } else if (((int64_t)((alt_objs).len)) > 0) {
                                    __auto_type _mv_430 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_430.has_value) {
                                        __auto_type list_head = _mv_430.value;
                                        if (!(snarl_parse_shapes_graph_list_is_acyclic(arena, g, list_head))) {
                                            any_cycle = 1;
                                        } else {
                                            {
                                                __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
                                                {
                                                    __auto_type _coll = elements;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type elem = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = elem})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                    } else if (!_mv_430.has_value) {
                                    }
                                } else if (((int64_t)((zom_objs).len)) > 0) {
                                    __auto_type _mv_431 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_431.has_value) {
                                        __auto_type inner = _mv_431.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_431.has_value) {
                                    }
                                } else if (((int64_t)((oom_objs).len)) > 0) {
                                    __auto_type _mv_432 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_432.has_value) {
                                        __auto_type inner = _mv_432.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_432.has_value) {
                                    }
                                } else if (((int64_t)((zoo_objs).len)) > 0) {
                                    __auto_type _mv_433 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_433.has_value) {
                                        __auto_type inner = _mv_433.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_433.has_value) {
                                    }
                                } else if (1) {
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_421.has_value) {
            }
        }
        return !(any_cycle);
    }
}

int64_t snarl_parse_path_max_eval_depth(void) {
    return 1000;
}

int64_t snarl_parse_path_node_eval_depth(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root) {
    int64_t _retval = {0};
    {
        __auto_type depths = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type work = snarl_parse_path_scan_work_new(arena);
        (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = root})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (((int64_t)((work).len)) > 0) {
            __auto_type _mv_434 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_434.has_value) {
                __auto_type item = _mv_434.value;
                {
                    __auto_type n = item.node;
                    __auto_type kids = snarl_parse_path_node_eval_children(arena, g, item.node);
                    if (item.is_exit) {
                        {
                            int64_t best = 0;
                            {
                                __auto_type _coll = kids;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    {
                                        __auto_type d = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(depths, &(c)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); });
                                        if (d > best) {
                                            best = d;
                                        }
                                    }
                                }
                            }
                            ({ int64_t _val = (best + 1); slop_map_put(NULL, depths, &(n), &_val, sizeof(_val)); });
                        }
                    } else {
                        if (({ __auto_type _mv = ({ void* _ptr = slop_map_get(depths, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) {
                            ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 1, .node = n})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            {
                                __auto_type _coll = kids;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = c})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_434.has_value) {
            }
        }
        __auto_type _mv_439 = ({ void* _ptr = slop_map_get(depths, &(root)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        if (_mv_439.has_value) {
            __auto_type d = _mv_439.value;
            _retval = d;
            goto _slop_post;
        } else if (!_mv_439.has_value) {
            _retval = 0;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_parse_path_node_eval_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type kids = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type first_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST));
        __auto_type inverse_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_INVERSE_PATH));
        __auto_type alt_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ALTERNATIVE_PATH));
        __auto_type zom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_MORE_PATH));
        __auto_type oom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ONE_OR_MORE_PATH));
        __auto_type zoo_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_ONE_PATH));
        if (((int64_t)((first_objs).len)) > 0) {
            {
                __auto_type _coll = rdf_list_elements_indexed(arena, g, n);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type elem = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(kids); __auto_type _item = (elem); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        } else if (((int64_t)((inverse_objs).len)) > 0) {
            {
                __auto_type cur = n;
                uint8_t peeling = 1;
                while (peeling) {
                    {
                        __auto_type objs = rdf_indexed_graph_objects(arena, g, cur, rdf_make_iri(arena, slop_rdf_vocab_SHACL_INVERSE_PATH));
                        __auto_type _mv_440 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_440.has_value) {
                            __auto_type inner = _mv_440.value;
                            cur = inner;
                        } else if (!_mv_440.has_value) {
                            peeling = 0;
                        }
                    }
                }
                (void)(({ __auto_type _lst_p = &(kids); __auto_type _item = (cur); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        } else if (((int64_t)((alt_objs).len)) > 0) {
            __auto_type _mv_441 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_441.has_value) {
                __auto_type list_head = _mv_441.value;
                {
                    __auto_type _coll = rdf_list_elements_indexed(arena, g, list_head);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type elem = _coll.data[_i];
                        ({ __auto_type _lst_p = &(kids); __auto_type _item = (elem); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            } else if (!_mv_441.has_value) {
            }
        } else if (((int64_t)((zom_objs).len)) > 0) {
            __auto_type _mv_442 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_442.has_value) {
                __auto_type inner = _mv_442.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_442.has_value) {
            }
        } else if (((int64_t)((oom_objs).len)) > 0) {
            __auto_type _mv_443 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_443.has_value) {
                __auto_type inner = _mv_443.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_443.has_value) {
            }
        } else if (((int64_t)((zoo_objs).len)) > 0) {
            __auto_type _mv_444 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_444.has_value) {
                __auto_type inner = _mv_444.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_444.has_value) {
            }
        } else if (1) {
        }
        _retval = kids;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_depth_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type triples = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH)}, no_term);
        slop_option_slop_rdf_rdf_Term result = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                __auto_type _mv_445 = result;
                if (!_mv_445.has_value) {
                    {
                        __auto_type path_node = rdf_triple_object(tr);
                        if (snarl_parse_path_node_eval_depth(arena, g, path_node) > snarl_parse_path_max_eval_depth()) {
                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = path_node};
                        }
                    }
                } else if (_mv_445.has_value) {
                    __auto_type _ = _mv_445.value;
                }
            }
        }
        return result;
    }
}

slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type triples = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH)}, no_term);
        slop_option_slop_rdf_rdf_Term result = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                __auto_type _mv_446 = result;
                if (!_mv_446.has_value) {
                    {
                        __auto_type path_node = rdf_triple_object(tr);
                        if (!(snarl_parse_path_node_is_acyclic(arena, g, path_node))) {
                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = path_node};
                        }
                    }
                } else if (_mv_446.has_value) {
                    __auto_type _ = _mv_446.value;
                }
            }
        }
        return result;
    }
}

slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_list_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type list_preds = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_slop_rdf_rdf_Term result = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_AND)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_OR)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_XONE)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_IN)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_IGNORED_PROPERTIES)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, slop_rdf_vocab_SHACL_LANGUAGE_IN)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = list_preds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type pred = _coll.data[_i];
                if (({ __auto_type _mv = result; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) {
                    {
                        __auto_type triples = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = pred}, no_term);
                        {
                            __auto_type _coll = triples;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type tr = _coll.data[_i];
                                __auto_type _mv_447 = result;
                                if (!_mv_447.has_value) {
                                    {
                                        __auto_type list_head = rdf_triple_object(tr);
                                        if (!(snarl_parse_shapes_graph_list_is_acyclic(arena, g, list_head))) {
                                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = list_head};
                                        }
                                    }
                                } else if (_mv_447.has_value) {
                                    __auto_type _ = _mv_447.value;
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_shapes_graph_recursion_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    __auto_type _mv_448 = snarl_parse_shapes_graph_path_cycle_message(arena, g);
    if (_mv_448.has_value) {
        __auto_type node = _mv_448.value;
        {
            __auto_type label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
            __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Cyclic sh:path expression detected at ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" (path expression references itself)")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
        }
    } else if (!_mv_448.has_value) {
        __auto_type _mv_449 = snarl_parse_shapes_graph_list_cycle_message(arena, g);
        if (_mv_449.has_value) {
            __auto_type node = _mv_449.value;
            {
                __auto_type label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
                __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Malformed RDF list detected at ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" (rdf:rest chain does not terminate at rdf:nil)")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
            }
        } else if (!_mv_449.has_value) {
            __auto_type _mv_450 = snarl_parse_shapes_graph_path_depth_message(arena, g);
            if (_mv_450.has_value) {
                __auto_type node = _mv_450.value;
                {
                    __auto_type label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
                    __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Path nesting depth budget (")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, snarl_parse_path_max_eval_depth())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(") exceeded at ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" -- a path expression nested this deeply cannot be evaluated without risking a native stack overflow")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
                }
            } else if (!_mv_450.has_value) {
                return (slop_option_string){.has_value = false};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_parse_shape_has_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term ref) {
    return (((int64_t)((rdf_indexed_graph_objects(arena, g, ref, rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH))).len)) > 0);
}

void snarl_parse_register_inline_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_snarl_types_NodeShape node_shapes, slop_list_snarl_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map) {
    {
        __auto_type ns_queue = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ps_queue = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                {
                    __auto_type _coll = ns.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        __auto_type _mv_451 = c;
                        switch (_mv_451.tag) {
                            case snarl_types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_451.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_451.data.con_and;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_or:
                            {
                                __auto_type refs = _mv_451.data.con_or;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_xone:
                            {
                                __auto_type refs = _mv_451.data.con_xone;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_node:
                            {
                                __auto_type ref = _mv_451.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_451.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_451.data.con_property;
                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                __auto_type c = _coll.data[_i];
                                __auto_type _mv_452 = c;
                                switch (_mv_452.tag) {
                                    case snarl_types_Constraint_con_not:
                                    {
                                        __auto_type ref = _mv_452.data.con_not;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_and:
                                    {
                                        __auto_type refs = _mv_452.data.con_and;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case snarl_types_Constraint_con_or:
                                    {
                                        __auto_type refs = _mv_452.data.con_or;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case snarl_types_Constraint_con_xone:
                                    {
                                        __auto_type refs = _mv_452.data.con_xone;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case snarl_types_Constraint_con_node:
                                    {
                                        __auto_type ref = _mv_452.data.con_node;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_452.data.con_qualified_value_shape.f0;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_property:
                                    {
                                        __auto_type ref = _mv_452.data.con_property;
                                        ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            __auto_type _coll = prop_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps = _coll.data[_i];
                {
                    __auto_type _coll = ps.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        __auto_type _mv_453 = c;
                        switch (_mv_453.tag) {
                            case snarl_types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_453.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_453.data.con_and;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_or:
                            {
                                __auto_type refs = _mv_453.data.con_or;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_xone:
                            {
                                __auto_type refs = _mv_453.data.con_xone;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_node:
                            {
                                __auto_type ref = _mv_453.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_453.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_453.data.con_property;
                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        {
            int64_t ns_i = 0;
            int64_t ps_i = 0;
            uint8_t changed = 1;
            while (changed) {
                changed = 0;
                while (ns_i < ((int64_t)((ns_queue).len))) {
                    __auto_type _mv_454 = ({ __auto_type _lst = ns_queue; size_t _idx = (size_t)ns_i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_454.has_value) {
                        __auto_type ref = _mv_454.value;
                        __auto_type _mv_456 = ({ void* _ptr = slop_map_get(shape_map, &(ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                        if (!_mv_456.has_value) {
                            if (snarl_parse_shape_has_path(arena, g, ref)) {
                                __auto_type _mv_458 = ({ void* _ptr = slop_map_get(property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                                if (!_mv_458.has_value) {
                                    changed = 1;
                                    ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (_mv_458.has_value) {
                                    __auto_type _ = _mv_458.value;
                                }
                            } else {
                                changed = 1;
                                {
                                    __auto_type ns = snarl_parse_node_shape(arena, g, ref);
                                    ({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(ref), &_val, sizeof(_val)); });
                                    {
                                        __auto_type _coll = ns.constraints;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type c = _coll.data[_i];
                                            __auto_type _mv_460 = c;
                                            switch (_mv_460.tag) {
                                                case snarl_types_Constraint_con_not:
                                                {
                                                    __auto_type r = _mv_460.data.con_not;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_and:
                                                {
                                                    __auto_type rs = _mv_460.data.con_and;
                                                    {
                                                        __auto_type _coll = rs;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type r = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_or:
                                                {
                                                    __auto_type rs = _mv_460.data.con_or;
                                                    {
                                                        __auto_type _coll = rs;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type r = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_xone:
                                                {
                                                    __auto_type rs = _mv_460.data.con_xone;
                                                    {
                                                        __auto_type _coll = rs;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type r = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_node:
                                                {
                                                    __auto_type r = _mv_460.data.con_node;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_qualified_value_shape:
                                                {
                                                    __auto_type r = _mv_460.data.con_qualified_value_shape.f0;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_property:
                                                {
                                                    __auto_type r = _mv_460.data.con_property;
                                                    ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                            __auto_type _mv_462 = ({ void* _ptr = slop_map_get(property_shape_map, &(ps.id)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                                            if (!_mv_462.has_value) {
                                                ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ps.id), &_val, sizeof(_val)); });
                                            } else if (_mv_462.has_value) {
                                                __auto_type _ = _mv_462.value;
                                            }
                                            {
                                                __auto_type _coll = ps.constraints;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type c = _coll.data[_i];
                                                    __auto_type _mv_464 = c;
                                                    switch (_mv_464.tag) {
                                                        case snarl_types_Constraint_con_not:
                                                        {
                                                            __auto_type r = _mv_464.data.con_not;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_and:
                                                        {
                                                            __auto_type rs = _mv_464.data.con_and;
                                                            {
                                                                __auto_type _coll = rs;
                                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                    __auto_type r = _coll.data[_i];
                                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_or:
                                                        {
                                                            __auto_type rs = _mv_464.data.con_or;
                                                            {
                                                                __auto_type _coll = rs;
                                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                    __auto_type r = _coll.data[_i];
                                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_xone:
                                                        {
                                                            __auto_type rs = _mv_464.data.con_xone;
                                                            {
                                                                __auto_type _coll = rs;
                                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                    __auto_type r = _coll.data[_i];
                                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_node:
                                                        {
                                                            __auto_type r = _mv_464.data.con_node;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_qualified_value_shape:
                                                        {
                                                            __auto_type r = _mv_464.data.con_qualified_value_shape.f0;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_property:
                                                        {
                                                            __auto_type r = _mv_464.data.con_property;
                                                            ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        } else if (_mv_456.has_value) {
                            __auto_type _ = _mv_456.value;
                        }
                    } else if (!_mv_454.has_value) {
                    }
                    ns_i = (ns_i + 1);
                }
                while (ps_i < ((int64_t)((ps_queue).len))) {
                    __auto_type _mv_465 = ({ __auto_type _lst = ps_queue; size_t _idx = (size_t)ps_i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_465.has_value) {
                        __auto_type ref = _mv_465.value;
                        __auto_type _mv_467 = ({ void* _ptr = slop_map_get(property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                        if (!_mv_467.has_value) {
                            changed = 1;
                            {
                                __auto_type ps = snarl_parse_property_shape(arena, g, ref);
                                ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ref), &_val, sizeof(_val)); });
                                {
                                    __auto_type _coll = ps.constraints;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        __auto_type _mv_469 = c;
                                        switch (_mv_469.tag) {
                                            case snarl_types_Constraint_con_not:
                                            {
                                                __auto_type r = _mv_469.data.con_not;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_and:
                                            {
                                                __auto_type rs = _mv_469.data.con_and;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case snarl_types_Constraint_con_or:
                                            {
                                                __auto_type rs = _mv_469.data.con_or;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case snarl_types_Constraint_con_xone:
                                            {
                                                __auto_type rs = _mv_469.data.con_xone;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case snarl_types_Constraint_con_node:
                                            {
                                                __auto_type r = _mv_469.data.con_node;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_qualified_value_shape:
                                            {
                                                __auto_type r = _mv_469.data.con_qualified_value_shape.f0;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_property:
                                            {
                                                __auto_type r = _mv_469.data.con_property;
                                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            default: {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (_mv_467.has_value) {
                            __auto_type _ = _mv_467.value;
                        }
                    } else if (!_mv_465.has_value) {
                    }
                    ps_i = (ps_i + 1);
                }
            }
        }
    }
}

snarl_types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph) {
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    snarl_types_ShapesGraph _retval = {0};
    {
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        __auto_type ns_type = rdf_make_iri(arena, slop_rdf_vocab_SHACL_NODE_SHAPE);
        __auto_type ps_type = rdf_make_iri(arena, slop_rdf_vocab_SHACL_PROPERTY_SHAPE);
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type ns_subjects = rdf_indexed_graph_subjects(arena, shapes_graph, type_pred, ns_type);
        __auto_type ps_subjects = rdf_indexed_graph_subjects(arena, shapes_graph, type_pred, ps_type);
        __auto_type node_shapes = ((slop_list_snarl_types_NodeShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type prop_shapes = ((slop_list_snarl_types_PropertyShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type shape_map = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, snarl_types_NodeShape); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type property_shape_map = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, snarl_types_PropertyShape); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = ns_subjects;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns_id = _coll.data[_i];
                {
                    __auto_type ns = snarl_parse_node_shape(arena, shapes_graph, ns_id);
                    (void)(({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(ns_id), &_val, sizeof(_val)); }));
                    {
                        __auto_type _coll = ns.property_shapes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ps = _coll.data[_i];
                            (void)(({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ps.id), &_val, sizeof(_val)); }));
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = ps_subjects;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps_id = _coll.data[_i];
                {
                    __auto_type ps = snarl_parse_property_shape(arena, shapes_graph, ps_id);
                    __auto_type t_nodes = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_NODE));
                    __auto_type t_classes = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_CLASS));
                    __auto_type t_subj = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_SUBJECTS_OF));
                    __auto_type t_obj = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_OBJECTS_OF));
                    (void)(({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ps_id), &_val, sizeof(_val)); }));
                    if ((((int64_t)((t_nodes).len)) > 0) || ((((int64_t)((t_classes).len)) > 0) || ((((int64_t)((t_subj).len)) > 0) || (((int64_t)((t_obj).len)) > 0)))) {
                        {
                            __auto_type ps_list = ((slop_list_snarl_types_PropertyShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            (void)(({ __auto_type _lst_p = &(ps_list); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            {
                                __auto_type ns = ((snarl_types_NodeShape){.id = ps_id, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .severity = snarl_types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated});
                                (void)(({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(ps_id), &_val, sizeof(_val)); }));
                            }
                        }
                    } else {
                        (void)(({ __auto_type _lst_p = &(prop_shapes); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type target_pred_tn = rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_NODE);
            __auto_type target_pred_tc = rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_CLASS);
            __auto_type target_pred_ts = rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_SUBJECTS_OF);
            __auto_type target_pred_to = rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_OBJECTS_OF);
            __auto_type path_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH);
            __auto_type target_preds = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            (void)(({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_tn); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_tc); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_ts); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_to); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            {
                __auto_type _coll = target_preds;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tp = _coll.data[_i];
                    {
                        __auto_type triples = rdf_indexed_graph_match(arena, shapes_graph, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = tp}, no_term);
                        {
                            __auto_type _coll = triples;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type tr = _coll.data[_i];
                                {
                                    __auto_type subj = rdf_triple_subject(tr);
                                    __auto_type _mv_475 = ({ void* _ptr = slop_map_get(shape_map, &(subj)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                    if (_mv_475.has_value) {
                                        __auto_type _ = _mv_475.value;
                                    } else if (!_mv_475.has_value) {
                                        {
                                            __auto_type path_vals = rdf_indexed_graph_objects(arena, shapes_graph, subj, path_pred);
                                            if (((int64_t)((path_vals).len)) > 0) {
                                                {
                                                    __auto_type ps = snarl_parse_property_shape(arena, shapes_graph, subj);
                                                    __auto_type t_nodes = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_tn);
                                                    __auto_type t_classes = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_tc);
                                                    __auto_type t_subj = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_ts);
                                                    __auto_type t_obj = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_to);
                                                    ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(subj), &_val, sizeof(_val)); });
                                                    {
                                                        __auto_type ps_list = ((slop_list_snarl_types_PropertyShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                                        ({ __auto_type _lst_p = &(ps_list); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        {
                                                            __auto_type ns = ((snarl_types_NodeShape){.id = subj, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .severity = snarl_types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated});
                                                            ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            ({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(subj), &_val, sizeof(_val)); });
                                                        }
                                                    }
                                                }
                                            } else {
                                                {
                                                    __auto_type ns = snarl_parse_node_shape(arena, shapes_graph, subj);
                                                    ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(subj), &_val, sizeof(_val)); });
                                                    {
                                                        __auto_type _coll = ns.property_shapes;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type ps = _coll.data[_i];
                                                            ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ps.id), &_val, sizeof(_val)); });
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
        snarl_parse_register_inline_shapes(arena, shapes_graph, node_shapes, prop_shapes, shape_map, property_shape_map);
        _retval = ((snarl_types_ShapesGraph){.node_shapes = node_shapes, .property_shapes = prop_shapes, .shape_map = shape_map, .property_shape_map = property_shape_map});
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval.node_shapes).len)) >= 0)), "(>= (list-len (. $result node-shapes)) 0)");
    return _retval;
}

snarl_types_NodeShape snarl_parse_node_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type target_nodes = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_NODE));
        __auto_type target_classes = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_CLASS));
        __auto_type target_subjects_of = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_SUBJECTS_OF));
        __auto_type target_objects_of = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_TARGET_OBJECTS_OF));
        __auto_type prop_refs = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_PROPERTY));
        __auto_type prop_shapes = ((slop_list_snarl_types_PropertyShape){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type constraints = snarl_parse_constraints(arena, g, shape_id);
        __auto_type severity = snarl_parse_parse_shape_severity(arena, g, shape_id);
        __auto_type message = snarl_parse_parse_shape_message(arena, g, shape_id);
        __auto_type deactivated = snarl_parse_parse_shape_deactivated(arena, g, shape_id);
        {
            __auto_type _coll = prop_refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps_ref = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(prop_shapes); __auto_type _item = (snarl_parse_property_shape(arena, g, ps_ref)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((snarl_types_NodeShape){.id = shape_id, .target_nodes = target_nodes, .target_classes = target_classes, .target_subjects_of = target_subjects_of, .target_objects_of = target_objects_of, .property_shapes = prop_shapes, .constraints = constraints, .severity = severity, .message = message, .deactivated = deactivated});
    }
}

snarl_types_PropertyShape snarl_parse_property_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type path_objects = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATH));
        __auto_type path = (((((int64_t)((path_objects).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = path_objects; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type path_term = _mv.value; snarl_parse_path(arena, g, path_term); }) : (((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = shape_id })); }) : ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = shape_id }));
        __auto_type constraints = snarl_parse_constraints(arena, g, shape_id);
        __auto_type severity = snarl_parse_parse_shape_severity(arena, g, shape_id);
        __auto_type message = snarl_parse_parse_shape_message(arena, g, shape_id);
        __auto_type deactivated = snarl_parse_parse_shape_deactivated(arena, g, shape_id);
        return ((snarl_types_PropertyShape){.id = shape_id, .path = path, .constraints = constraints, .severity = severity, .message = message, .deactivated = deactivated});
    }
}

snarl_types_ShaclPath snarl_parse_parse_path_built_or_leaf(slop_map* built, slop_rdf_rdf_Term child) {
    __auto_type _mv_481 = ({ void* _ptr = slop_map_get(built, &(child)); _ptr ? (slop_option_snarl_types_ShaclPath){ .has_value = true, .value = *(snarl_types_ShaclPath*)_ptr } : (slop_option_snarl_types_ShaclPath){ .has_value = false }; });
    if (_mv_481.has_value) {
        __auto_type p = _mv_481.value;
        return p;
    } else if (!_mv_481.has_value) {
        return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = child });
    }
    SLOP_UNREACHABLE();
}

snarl_types_ShaclPath snarl_parse_parse_path_build_node(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_map* built) {
    {
        __auto_type first_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST));
        __auto_type inverse_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_INVERSE_PATH));
        __auto_type alt_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ALTERNATIVE_PATH));
        __auto_type zom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_MORE_PATH));
        __auto_type oom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ONE_OR_MORE_PATH));
        __auto_type zoo_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_ONE_PATH));
        if (((int64_t)((first_objs).len)) > 0) {
            {
                __auto_type elements = rdf_list_elements_indexed(arena, g, n);
                __auto_type paths = ((slop_list_snarl_types_ShaclPath){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = elements;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type elem = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(paths); __auto_type _item = (snarl_parse_parse_path_built_or_leaf(built, elem)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_sequence, .data.path_sequence = paths });
            }
        } else if (((int64_t)((inverse_objs).len)) > 0) {
            __auto_type _mv_482 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_482.has_value) {
                __auto_type inner = _mv_482.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_inverse, .data.path_inverse = ptr });
                }
            } else if (!_mv_482.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((alt_objs).len)) > 0) {
            __auto_type _mv_483 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_483.has_value) {
                __auto_type list_head = _mv_483.value;
                {
                    __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
                    __auto_type paths = ((slop_list_snarl_types_ShaclPath){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    {
                        __auto_type _coll = elements;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type elem = _coll.data[_i];
                            ({ __auto_type _lst_p = &(paths); __auto_type _item = (snarl_parse_parse_path_built_or_leaf(built, elem)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_alternative, .data.path_alternative = paths });
                }
            } else if (!_mv_483.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((zom_objs).len)) > 0) {
            __auto_type _mv_484 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_484.has_value) {
                __auto_type inner = _mv_484.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_zero_or_more, .data.path_zero_or_more = ptr });
                }
            } else if (!_mv_484.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((oom_objs).len)) > 0) {
            __auto_type _mv_485 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_485.has_value) {
                __auto_type inner = _mv_485.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_one_or_more, .data.path_one_or_more = ptr });
                }
            } else if (!_mv_485.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((zoo_objs).len)) > 0) {
            __auto_type _mv_486 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_486.has_value) {
                __auto_type inner = _mv_486.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_zero_or_one, .data.path_zero_or_one = ptr });
                }
            } else if (!_mv_486.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (1) {
            return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
        }
    }
}

snarl_types_ShaclPath snarl_parse_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term path_node) {
    {
        __auto_type built = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, snarl_types_ShaclPath); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type on_path = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type work = snarl_parse_path_scan_work_new(arena);
        (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = path_node})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (((int64_t)((work).len)) > 0) {
            __auto_type _mv_487 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_487.has_value) {
                __auto_type item = _mv_487.value;
                {
                    __auto_type n = item.node;
                    if (item.is_exit) {
                        ({ snarl_types_ShaclPath _val = snarl_parse_parse_path_build_node(arena, g, n, built); slop_map_put(NULL, built, &(n), &_val, sizeof(_val)); });
                        ({ int64_t _val = (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) - 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                    } else {
                        if (slop_map_has(built, &(n))) {
                        } else if (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) > 0) {
                            ({ snarl_types_ShaclPath _val = ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n }); slop_map_put(NULL, built, &(n), &_val, sizeof(_val)); });
                        } else if (1) {
                            {
                                __auto_type first_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST));
                                __auto_type inverse_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_INVERSE_PATH));
                                __auto_type alt_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ALTERNATIVE_PATH));
                                __auto_type zom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_MORE_PATH));
                                __auto_type oom_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ONE_OR_MORE_PATH));
                                __auto_type zoo_objs = rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, slop_rdf_vocab_SHACL_ZERO_OR_ONE_PATH));
                                ({ int64_t _val = (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) + 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                                ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 1, .node = n})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                if (((int64_t)((first_objs).len)) > 0) {
                                    {
                                        __auto_type elements = rdf_list_elements_indexed(arena, g, n);
                                        {
                                            __auto_type _coll = elements;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type elem = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = elem})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                } else if (((int64_t)((inverse_objs).len)) > 0) {
                                    __auto_type _mv_496 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_496.has_value) {
                                        __auto_type inner = _mv_496.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_496.has_value) {
                                    }
                                } else if (((int64_t)((alt_objs).len)) > 0) {
                                    __auto_type _mv_497 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_497.has_value) {
                                        __auto_type list_head = _mv_497.value;
                                        {
                                            __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
                                            {
                                                __auto_type _coll = elements;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type elem = _coll.data[_i];
                                                    ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = elem})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    } else if (!_mv_497.has_value) {
                                    }
                                } else if (((int64_t)((zom_objs).len)) > 0) {
                                    __auto_type _mv_498 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_498.has_value) {
                                        __auto_type inner = _mv_498.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_498.has_value) {
                                    }
                                } else if (((int64_t)((oom_objs).len)) > 0) {
                                    __auto_type _mv_499 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_499.has_value) {
                                        __auto_type inner = _mv_499.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_499.has_value) {
                                    }
                                } else if (((int64_t)((zoo_objs).len)) > 0) {
                                    __auto_type _mv_500 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_500.has_value) {
                                        __auto_type inner = _mv_500.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_500.has_value) {
                                    }
                                } else if (1) {
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_487.has_value) {
            }
        }
        __auto_type _mv_502 = ({ void* _ptr = slop_map_get(built, &(path_node)); _ptr ? (slop_option_snarl_types_ShaclPath){ .has_value = true, .value = *(snarl_types_ShaclPath*)_ptr } : (slop_option_snarl_types_ShaclPath){ .has_value = false }; });
        if (_mv_502.has_value) {
            __auto_type p = _mv_502.value;
            return p;
        } else if (!_mv_502.has_value) {
            return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = path_node });
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_snarl_types_Constraint snarl_parse_constraints(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    slop_list_snarl_types_Constraint _retval = {0};
    {
        __auto_type constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type class_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_CLASS));
            {
                __auto_type _coll = class_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_class, .data.con_class = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type dt_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_DATATYPE));
            {
                __auto_type _coll = dt_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_datatype, .data.con_datatype = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type nk_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_NODE_KIND));
            {
                __auto_type _coll = nk_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_503 = snarl_parse_node_kind(v);
                    if (_mv_503.has_value) {
                        __auto_type nk = _mv_503.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_node_kind, .data.con_node_kind = nk })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_503.has_value) {
                    }
                }
            }
        }
        {
            __auto_type mc_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MIN_COUNT));
            {
                __auto_type _coll = mc_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_504 = snarl_parse_term_to_int(v);
                    if (_mv_504.has_value) {
                        __auto_type n = _mv_504.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_count, .data.con_min_count = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_504.has_value) {
                    }
                }
            }
        }
        {
            __auto_type mc_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MAX_COUNT));
            {
                __auto_type _coll = mc_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_505 = snarl_parse_term_to_int(v);
                    if (_mv_505.has_value) {
                        __auto_type n = _mv_505.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_count, .data.con_max_count = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_505.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MIN_INCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_inclusive, .data.con_min_inclusive = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MAX_INCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_inclusive, .data.con_max_inclusive = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MIN_EXCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_exclusive, .data.con_min_exclusive = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MAX_EXCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_exclusive, .data.con_max_exclusive = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MIN_LENGTH));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_506 = snarl_parse_term_to_int(v);
                    if (_mv_506.has_value) {
                        __auto_type n = _mv_506.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_length, .data.con_min_length = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_506.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_MAX_LENGTH));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_507 = snarl_parse_term_to_int(v);
                    if (_mv_507.has_value) {
                        __auto_type n = _mv_507.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_length, .data.con_max_length = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_507.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_PATTERN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_508 = snarl_parse_term_to_string(v);
                    if (_mv_508.has_value) {
                        __auto_type s = _mv_508.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_pattern, .data.con_pattern = s })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_508.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_LANGUAGE_IN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type langs = snarl_parse_parse_string_list(arena, g, v);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_language_in, .data.con_language_in = langs })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_UNIQUE_LANG));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_509 = snarl_parse_term_to_string(v);
                    if (_mv_509.has_value) {
                        __auto_type s = _mv_509.value;
                        if (string_eq(s, SLOP_STR("true"))) {
                            ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_unique_lang, .data.con_unique_lang = 1 })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_509.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_EQUALS));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_equals, .data.con_equals = ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_DISJOINT));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_disjoint, .data.con_disjoint = ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_LESS_THAN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_less_than, .data.con_less_than = ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_LESS_THAN_OR_EQUALS));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_less_than_or_equals, .data.con_less_than_or_equals = ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_NOT));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_not, .data.con_not = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_AND));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_and, .data.con_and = shapes })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_OR));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_or, .data.con_or = shapes })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_XONE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_xone, .data.con_xone = shapes })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_NODE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_node, .data.con_node = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type prop_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_PROPERTY));
            {
                __auto_type _coll = prop_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_property, .data.con_property = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type qvs_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_QUALIFIED_VALUE_SHAPE));
            {
                __auto_type _coll = qvs_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type qmin_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_QUALIFIED_MIN_COUNT));
                        __auto_type qmax_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_QUALIFIED_MAX_COUNT));
                        __auto_type qmin = (((((int64_t)((qmin_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = qmin_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = snarl_parse_term_to_int(t); _mv.has_value ? ({ __auto_type n = _mv.value; n; }) : (0); }); }) : (0); }) : 0);
                        __auto_type qmax = (((((int64_t)((qmax_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = qmax_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = snarl_parse_term_to_int(t); _mv.has_value ? ({ __auto_type n = _mv.value; (slop_option_int){.has_value = 1, .value = n}; }) : ((slop_option_int){.has_value = false}); }); }) : ((slop_option_int){.has_value = false}); }) : (slop_option_int){.has_value = false});
                        __auto_type disjoint_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_QUALIFIED_VALUE_SHAPES_DISJOINT));
                        __auto_type disjoint = (((((int64_t)((disjoint_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = disjoint_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = snarl_parse_term_to_bool(t); _mv.has_value ? ({ __auto_type b = _mv.value; b; }) : (0); }); }) : (0); }) : 0);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_qualified_value_shape, .data.con_qualified_value_shape = { .f0 = v, .f1 = qmin, .f2 = qmax, .f3 = disjoint } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_HAS_VALUE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_has_value, .data.con_has_value = v })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_IN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type elements = rdf_list_elements_indexed(arena, g, v);
                        (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_in, .data.con_in = elements })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type closed_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_CLOSED));
            {
                __auto_type _coll = closed_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_510 = snarl_parse_term_to_bool(v);
                    if (_mv_510.has_value) {
                        __auto_type b = _mv_510.value;
                        if (b) {
                            {
                                __auto_type ignored_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_IGNORED_PROPERTIES));
                                __auto_type ignored_paths = ((slop_list_snarl_types_ShaclPath){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                {
                                    __auto_type _coll = ignored_vals;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type iv = _coll.data[_i];
                                        {
                                            __auto_type elements = rdf_list_elements_indexed(arena, g, iv);
                                            {
                                                __auto_type _coll = elements;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type elem = _coll.data[_i];
                                                    ({ __auto_type _lst_p = &(ignored_paths); __auto_type _item = (((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = elem })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                }
                                ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_closed, .data.con_closed = { .f0 = 1, .f1 = ignored_paths } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    } else if (!_mv_510.has_value) {
                    }
                }
            }
        }
        _retval = constraints;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_option_snarl_types_NodeKind snarl_parse_node_kind(slop_rdf_rdf_Term term) {
    __auto_type _mv_511 = term;
    switch (_mv_511.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_511.data.term_iri;
            if (string_eq(iri.value, slop_rdf_vocab_SHACL_BLANK_NODE)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_blank_node};
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_IRI)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_iri};
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_LITERAL)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_literal};
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_BLANK_NODE_OR_IRI)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_blank_node_or_iri};
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_BLANK_NODE_OR_LITERAL)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_blank_node_or_literal};
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_IRI_OR_LITERAL)) {
                return (slop_option_snarl_types_NodeKind){.has_value = 1, .value = snarl_types_NodeKind_node_kind_iri_or_literal};
            } else {
                return (slop_option_snarl_types_NodeKind){.has_value = false};
            }
        }
        default: {
            return (slop_option_snarl_types_NodeKind){.has_value = false};
        }
    }
}

snarl_types_Severity snarl_parse_severity(slop_rdf_rdf_Term term) {
    __auto_type _mv_512 = term;
    switch (_mv_512.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_512.data.term_iri;
            if (string_eq(iri.value, slop_rdf_vocab_SHACL_WARNING)) {
                return snarl_types_Severity_severity_warning;
            } else if (string_eq(iri.value, slop_rdf_vocab_SHACL_INFO)) {
                return snarl_types_Severity_severity_info;
            } else {
                return snarl_types_Severity_severity_violation;
            }
        }
        default: {
            return snarl_types_Severity_severity_violation;
        }
    }
}

snarl_types_Severity snarl_parse_parse_shape_severity(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type sev_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#severity")));
        if (((int64_t)((sev_vals).len)) > 0) {
            __auto_type _mv_513 = ({ __auto_type _lst = sev_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_513.has_value) {
                __auto_type v = _mv_513.value;
                return snarl_parse_severity(v);
            } else if (!_mv_513.has_value) {
                return snarl_types_Severity_severity_violation;
            }
            SLOP_UNREACHABLE();
        } else {
            return snarl_types_Severity_severity_violation;
        }
    }
}

slop_option_string snarl_parse_parse_shape_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type msg_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#message")));
        if (((int64_t)((msg_vals).len)) > 0) {
            __auto_type _mv_514 = ({ __auto_type _lst = msg_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_514.has_value) {
                __auto_type v = _mv_514.value;
                return snarl_parse_term_to_string(v);
            } else if (!_mv_514.has_value) {
                return (slop_option_string){.has_value = false};
            }
            SLOP_UNREACHABLE();
        } else {
            return (slop_option_string){.has_value = false};
        }
    }
}

uint8_t snarl_parse_parse_shape_deactivated(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#deactivated")));
        if (((int64_t)((vals).len)) > 0) {
            __auto_type _mv_515 = ({ __auto_type _lst = vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_515.has_value) {
                __auto_type v = _mv_515.value;
                __auto_type _mv_516 = snarl_parse_term_to_bool(v);
                if (_mv_516.has_value) {
                    __auto_type b = _mv_516.value;
                    return b;
                } else if (!_mv_516.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_515.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        } else {
            return 0;
        }
    }
}

slop_option_int snarl_parse_term_to_int(slop_rdf_rdf_Term t) {
    __auto_type _mv_517 = t;
    switch (_mv_517.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_517.data.term_literal;
            __auto_type _mv_518 = std_strlib_parse_int(lit.value);
            if (_mv_518.is_ok) {
                __auto_type n = _mv_518.data.ok;
                if (n >= 0) {
                    return (slop_option_int){.has_value = 1, .value = n};
                } else {
                    return (slop_option_int){.has_value = false};
                }
            } else if (!_mv_518.is_ok) {
                __auto_type _ = _mv_518.data.err;
                return (slop_option_int){.has_value = false};
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return (slop_option_int){.has_value = false};
        }
    }
}

slop_option_string snarl_parse_term_to_string(slop_rdf_rdf_Term t) {
    __auto_type _mv_519 = t;
    switch (_mv_519.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_519.data.term_literal;
            return (slop_option_string){.has_value = 1, .value = lit.value};
        }
        default: {
            return (slop_option_string){.has_value = false};
        }
    }
}

slop_option_u8 snarl_parse_term_to_bool(slop_rdf_rdf_Term t) {
    __auto_type _mv_520 = t;
    switch (_mv_520.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_520.data.term_literal;
            if (string_eq(lit.value, SLOP_STR("true"))) {
                return (slop_option_u8){.has_value = 1, .value = 1};
            } else if (string_eq(lit.value, SLOP_STR("1"))) {
                return (slop_option_u8){.has_value = 1, .value = 1};
            } else if (string_eq(lit.value, SLOP_STR("false"))) {
                return (slop_option_u8){.has_value = 1, .value = 0};
            } else if (string_eq(lit.value, SLOP_STR("0"))) {
                return (slop_option_u8){.has_value = 1, .value = 0};
            } else {
                return (slop_option_u8){.has_value = false};
            }
        }
        default: {
            return (slop_option_u8){.has_value = false};
        }
    }
}

slop_list_string snarl_parse_parse_string_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term list_head) {
    {
        __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
        __auto_type result = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = elements;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type elem = _coll.data[_i];
                __auto_type _mv_521 = snarl_parse_term_to_string(elem);
                if (_mv_521.has_value) {
                    __auto_type s = _mv_521.value;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_521.has_value) {
                }
            }
        }
        return result;
    }
}

