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
slop_map* snarl_parse_parse_custom_severities(slop_arena* arena, slop_rdf_index_IndexedGraph g);
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
int64_t snarl_parse_node_expr_max_eval_depth(void);
slop_list_slop_rdf_rdf_Term snarl_parse_objects_of(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string pred);
uint8_t snarl_parse_term_is_blank(slop_rdf_rdf_Term t);
slop_option_string snarl_parse_unsupported_shnex_predicate(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_option_string snarl_parse_first_unsupported_property_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_string props);
slop_option_string snarl_parse_first_unsupported_class_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_string classes);
slop_option_string snarl_parse_global_rule_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_string snarl_parse_shapes_graph_shacl12_unsupported_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t rules_run);
uint8_t snarl_parse_node_has_no_properties(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_option_string snarl_parse_literal_lexical(slop_rdf_rdf_Term t);
uint8_t snarl_parse_term_is_iri_value(slop_rdf_rdf_Term t, slop_string iri_value);
uint8_t snarl_parse_rule_is_active(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule);
slop_list_slop_rdf_rdf_Term snarl_parse_node_expr_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_list_slop_rdf_rdf_Term snarl_parse_active_rule_nodes(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_list_slop_rdf_rdf_Term snarl_parse_node_expr_roots(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t include_rules);
int64_t snarl_parse_node_expr_depth(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root, slop_map* depths);
slop_option_string snarl_parse_shapes_graph_node_expr_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_string snarl_parse_list_arity_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string pred, slop_string label);
slop_string snarl_parse_function_expression_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string label);
slop_option_string snarl_parse_node_expr_12_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string label);
slop_option_string snarl_parse_node_expr_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, uint8_t shacl12);
uint8_t snarl_parse_rule_has_type(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, slop_string type_iri);
slop_option_string snarl_parse_rule_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, uint8_t shacl12, uint8_t defer_sparql);
uint8_t snarl_parse_shapes_graph_declares_rules_entailment(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t shacl12);
slop_option_string snarl_shapes_graph_unsupported_feature_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t shacl12, uint8_t rules_run, uint8_t defer_sparql);
snarl_types_NodeExpr* snarl_parse_node_expr_box(slop_arena* arena, snarl_types_NodeExpr e);
snarl_types_NodeExpr snarl_parse_parse_node_expr_input(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_slop_rdf_rdf_Term nodes_objs);
snarl_types_NodeExpr snarl_parse_node_expr(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_list_snarl_types_NodeExpr snarl_parse_parse_node_expr_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_slop_rdf_rdf_Term heads);
slop_list_slop_rdf_rdf_Term snarl_node_expr_shape_refs(slop_arena* arena, snarl_types_NodeExpr e);
slop_list_slop_rdf_rdf_Term snarl_parse_rule_shape_refs(slop_arena* arena, slop_list_snarl_types_Rule rules);
double snarl_parse_parse_order(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
snarl_types_NodeExpr snarl_parse_parse_rule_slot(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, slop_string pred);
slop_list_snarl_types_Rule snarl_parse_parse_shape_rules(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_list_snarl_types_SparqlRuleRef snarl_parse_parse_shape_sparql_rules(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);

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
                        __auto_type _mv_494 = ({ __auto_type _lst = rest_matches; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_494.has_value) {
                            __auto_type rest_triple = _mv_494.value;
                            current = rdf_triple_object(rest_triple);
                        } else if (!_mv_494.has_value) {
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
            __auto_type _mv_495 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_495.has_value) {
                __auto_type item = _mv_495.value;
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
                                    __auto_type _mv_503 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_503.has_value) {
                                        __auto_type inner = _mv_503.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_503.has_value) {
                                    }
                                } else if (((int64_t)((alt_objs).len)) > 0) {
                                    __auto_type _mv_504 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_504.has_value) {
                                        __auto_type list_head = _mv_504.value;
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
                                    } else if (!_mv_504.has_value) {
                                    }
                                } else if (((int64_t)((zom_objs).len)) > 0) {
                                    __auto_type _mv_505 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_505.has_value) {
                                        __auto_type inner = _mv_505.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_505.has_value) {
                                    }
                                } else if (((int64_t)((oom_objs).len)) > 0) {
                                    __auto_type _mv_506 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_506.has_value) {
                                        __auto_type inner = _mv_506.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_506.has_value) {
                                    }
                                } else if (((int64_t)((zoo_objs).len)) > 0) {
                                    __auto_type _mv_507 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_507.has_value) {
                                        __auto_type inner = _mv_507.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_507.has_value) {
                                    }
                                } else if (1) {
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_495.has_value) {
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
            __auto_type _mv_508 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_508.has_value) {
                __auto_type item = _mv_508.value;
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
            } else if (!_mv_508.has_value) {
            }
        }
        __auto_type _mv_513 = ({ void* _ptr = slop_map_get(depths, &(root)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        if (_mv_513.has_value) {
            __auto_type d = _mv_513.value;
            _retval = d;
            goto _slop_post;
        } else if (!_mv_513.has_value) {
            _retval = 0;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

slop_list_slop_rdf_rdf_Term snarl_parse_path_node_eval_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
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
                        __auto_type _mv_514 = ({ __auto_type _lst = objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_514.has_value) {
                            __auto_type inner = _mv_514.value;
                            cur = inner;
                        } else if (!_mv_514.has_value) {
                            peeling = 0;
                        }
                    }
                }
                (void)(({ __auto_type _lst_p = &(kids); __auto_type _item = (cur); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        } else if (((int64_t)((alt_objs).len)) > 0) {
            __auto_type _mv_515 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_515.has_value) {
                __auto_type list_head = _mv_515.value;
                {
                    __auto_type _coll = rdf_list_elements_indexed(arena, g, list_head);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type elem = _coll.data[_i];
                        ({ __auto_type _lst_p = &(kids); __auto_type _item = (elem); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            } else if (!_mv_515.has_value) {
            }
        } else if (((int64_t)((zom_objs).len)) > 0) {
            __auto_type _mv_516 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_516.has_value) {
                __auto_type inner = _mv_516.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_516.has_value) {
            }
        } else if (((int64_t)((oom_objs).len)) > 0) {
            __auto_type _mv_517 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_517.has_value) {
                __auto_type inner = _mv_517.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_517.has_value) {
            }
        } else if (((int64_t)((zoo_objs).len)) > 0) {
            __auto_type _mv_518 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_518.has_value) {
                __auto_type inner = _mv_518.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (inner); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_518.has_value) {
            }
        } else if (1) {
        }
        return kids;
    }
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
                __auto_type _mv_519 = result;
                if (!_mv_519.has_value) {
                    {
                        __auto_type path_node = rdf_triple_object(tr);
                        if (snarl_parse_path_node_eval_depth(arena, g, path_node) > snarl_parse_path_max_eval_depth()) {
                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = path_node};
                        }
                    }
                } else if (_mv_519.has_value) {
                    __auto_type _ = _mv_519.value;
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
                __auto_type _mv_520 = result;
                if (!_mv_520.has_value) {
                    {
                        __auto_type path_node = rdf_triple_object(tr);
                        if (!(snarl_parse_path_node_is_acyclic(arena, g, path_node))) {
                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = path_node};
                        }
                    }
                } else if (_mv_520.has_value) {
                    __auto_type _ = _mv_520.value;
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
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, snarl_af_vocab_SHACL_INTERSECTION)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, snarl_af_vocab_SHACL_UNION)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(list_preds); __auto_type _item = (rdf_make_iri(arena, snarl_af_vocab_SHNEX_INTERSECTION)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                                __auto_type _mv_521 = result;
                                if (!_mv_521.has_value) {
                                    {
                                        __auto_type list_head = rdf_triple_object(tr);
                                        if (!(snarl_parse_shapes_graph_list_is_acyclic(arena, g, list_head))) {
                                            result = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = list_head};
                                        }
                                    }
                                } else if (_mv_521.has_value) {
                                    __auto_type _ = _mv_521.value;
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
    __auto_type _mv_522 = snarl_parse_shapes_graph_path_cycle_message(arena, g);
    if (_mv_522.has_value) {
        __auto_type node = _mv_522.value;
        {
            __auto_type label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
            __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Cyclic sh:path expression detected at ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" (path expression references itself)")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
        }
    } else if (!_mv_522.has_value) {
        __auto_type _mv_523 = snarl_parse_shapes_graph_list_cycle_message(arena, g);
        if (_mv_523.has_value) {
            __auto_type node = _mv_523.value;
            {
                __auto_type label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
                __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Malformed RDF list detected at ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" (rdf:rest chain does not terminate at rdf:nil)")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
            }
        } else if (!_mv_523.has_value) {
            __auto_type _mv_524 = snarl_parse_shapes_graph_path_depth_message(arena, g);
            if (_mv_524.has_value) {
                __auto_type node = _mv_524.value;
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
            } else if (!_mv_524.has_value) {
                return snarl_parse_shapes_graph_node_expr_hazard_message(arena, g);
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
                    __auto_type _coll = snarl_parse_rule_shape_refs(arena, ns.rules);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                {
                    __auto_type _coll = ns.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        __auto_type _mv_525 = c;
                        switch (_mv_525.tag) {
                            case snarl_types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_525.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_525.data.con_and;
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
                                __auto_type refs = _mv_525.data.con_or;
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
                                __auto_type refs = _mv_525.data.con_xone;
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
                                __auto_type ref = _mv_525.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_525.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_expression:
                            {
                                __auto_type e = _mv_525.data.con_expression.f0;
                                {
                                    __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_525.data.con_property;
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
                                __auto_type _mv_526 = c;
                                switch (_mv_526.tag) {
                                    case snarl_types_Constraint_con_not:
                                    {
                                        __auto_type ref = _mv_526.data.con_not;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_and:
                                    {
                                        __auto_type refs = _mv_526.data.con_and;
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
                                        __auto_type refs = _mv_526.data.con_or;
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
                                        __auto_type refs = _mv_526.data.con_xone;
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
                                        __auto_type ref = _mv_526.data.con_node;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_526.data.con_qualified_value_shape.f0;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case snarl_types_Constraint_con_expression:
                                    {
                                        __auto_type e = _mv_526.data.con_expression.f0;
                                        {
                                            __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case snarl_types_Constraint_con_property:
                                    {
                                        __auto_type ref = _mv_526.data.con_property;
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
                        __auto_type _mv_527 = c;
                        switch (_mv_527.tag) {
                            case snarl_types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_527.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_527.data.con_and;
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
                                __auto_type refs = _mv_527.data.con_or;
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
                                __auto_type refs = _mv_527.data.con_xone;
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
                                __auto_type ref = _mv_527.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_527.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case snarl_types_Constraint_con_expression:
                            {
                                __auto_type e = _mv_527.data.con_expression.f0;
                                {
                                    __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case snarl_types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_527.data.con_property;
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
                    __auto_type _mv_528 = ({ __auto_type _lst = ns_queue; size_t _idx = (size_t)ns_i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_528.has_value) {
                        __auto_type ref = _mv_528.value;
                        __auto_type _mv_530 = ({ void* _ptr = slop_map_get(shape_map, &(ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                        if (!_mv_530.has_value) {
                            if (snarl_parse_shape_has_path(arena, g, ref)) {
                                __auto_type _mv_532 = ({ void* _ptr = slop_map_get(property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                                if (!_mv_532.has_value) {
                                    changed = 1;
                                    ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (_mv_532.has_value) {
                                    __auto_type _ = _mv_532.value;
                                }
                            } else {
                                changed = 1;
                                {
                                    __auto_type ns = snarl_parse_node_shape(arena, g, ref);
                                    ({ snarl_types_NodeShape _val = ns; slop_map_put(NULL, shape_map, &(ref), &_val, sizeof(_val)); });
                                    {
                                        __auto_type _coll = snarl_parse_rule_shape_refs(arena, ns.rules);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type r = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type _coll = ns.constraints;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type c = _coll.data[_i];
                                            __auto_type _mv_534 = c;
                                            switch (_mv_534.tag) {
                                                case snarl_types_Constraint_con_not:
                                                {
                                                    __auto_type r = _mv_534.data.con_not;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_and:
                                                {
                                                    __auto_type rs = _mv_534.data.con_and;
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
                                                    __auto_type rs = _mv_534.data.con_or;
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
                                                    __auto_type rs = _mv_534.data.con_xone;
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
                                                    __auto_type r = _mv_534.data.con_node;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_qualified_value_shape:
                                                {
                                                    __auto_type r = _mv_534.data.con_qualified_value_shape.f0;
                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_expression:
                                                {
                                                    __auto_type e = _mv_534.data.con_expression.f0;
                                                    {
                                                        __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type r = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                    break;
                                                }
                                                case snarl_types_Constraint_con_property:
                                                {
                                                    __auto_type r = _mv_534.data.con_property;
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
                                            __auto_type _mv_536 = ({ void* _ptr = slop_map_get(property_shape_map, &(ps.id)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                                            if (!_mv_536.has_value) {
                                                ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ps.id), &_val, sizeof(_val)); });
                                            } else if (_mv_536.has_value) {
                                                __auto_type _ = _mv_536.value;
                                            }
                                            {
                                                __auto_type _coll = ps.constraints;
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type c = _coll.data[_i];
                                                    __auto_type _mv_538 = c;
                                                    switch (_mv_538.tag) {
                                                        case snarl_types_Constraint_con_not:
                                                        {
                                                            __auto_type r = _mv_538.data.con_not;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_and:
                                                        {
                                                            __auto_type rs = _mv_538.data.con_and;
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
                                                            __auto_type rs = _mv_538.data.con_or;
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
                                                            __auto_type rs = _mv_538.data.con_xone;
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
                                                            __auto_type r = _mv_538.data.con_node;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_qualified_value_shape:
                                                        {
                                                            __auto_type r = _mv_538.data.con_qualified_value_shape.f0;
                                                            ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_expression:
                                                        {
                                                            __auto_type e = _mv_538.data.con_expression.f0;
                                                            {
                                                                __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                    __auto_type r = _coll.data[_i];
                                                                    ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case snarl_types_Constraint_con_property:
                                                        {
                                                            __auto_type r = _mv_538.data.con_property;
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
                        } else if (_mv_530.has_value) {
                            __auto_type _ = _mv_530.value;
                        }
                    } else if (!_mv_528.has_value) {
                    }
                    ns_i = (ns_i + 1);
                }
                while (ps_i < ((int64_t)((ps_queue).len))) {
                    __auto_type _mv_539 = ({ __auto_type _lst = ps_queue; size_t _idx = (size_t)ps_i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_539.has_value) {
                        __auto_type ref = _mv_539.value;
                        __auto_type _mv_541 = ({ void* _ptr = slop_map_get(property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                        if (!_mv_541.has_value) {
                            changed = 1;
                            {
                                __auto_type ps = snarl_parse_property_shape(arena, g, ref);
                                ({ snarl_types_PropertyShape _val = ps; slop_map_put(NULL, property_shape_map, &(ref), &_val, sizeof(_val)); });
                                {
                                    __auto_type _coll = ps.constraints;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        __auto_type _mv_543 = c;
                                        switch (_mv_543.tag) {
                                            case snarl_types_Constraint_con_not:
                                            {
                                                __auto_type r = _mv_543.data.con_not;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_and:
                                            {
                                                __auto_type rs = _mv_543.data.con_and;
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
                                                __auto_type rs = _mv_543.data.con_or;
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
                                                __auto_type rs = _mv_543.data.con_xone;
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
                                                __auto_type r = _mv_543.data.con_node;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_qualified_value_shape:
                                            {
                                                __auto_type r = _mv_543.data.con_qualified_value_shape.f0;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case snarl_types_Constraint_con_expression:
                                            {
                                                __auto_type e = _mv_543.data.con_expression.f0;
                                                {
                                                    __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case snarl_types_Constraint_con_property:
                                            {
                                                __auto_type r = _mv_543.data.con_property;
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
                        } else if (_mv_541.has_value) {
                            __auto_type _ = _mv_541.value;
                        }
                    } else if (!_mv_539.has_value) {
                    }
                    ps_i = (ps_i + 1);
                }
            }
        }
    }
}

snarl_types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph) {
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
                                __auto_type ns = ((snarl_types_NodeShape){.id = ps_id, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .severity = snarl_types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated, .rules = snarl_parse_parse_shape_rules(arena, shapes_graph, ps_id), .order = snarl_parse_parse_order(arena, shapes_graph, ps_id), .sparql_rules = snarl_parse_parse_shape_sparql_rules(arena, shapes_graph, ps_id)});
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
                                    __auto_type _mv_549 = ({ void* _ptr = slop_map_get(shape_map, &(subj)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                    if (_mv_549.has_value) {
                                        __auto_type _ = _mv_549.value;
                                    } else if (!_mv_549.has_value) {
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
                                                            __auto_type ns = ((snarl_types_NodeShape){.id = subj, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_snarl_types_Constraint){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .severity = snarl_types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated, .rules = snarl_parse_parse_shape_rules(arena, shapes_graph, subj), .order = snarl_parse_parse_order(arena, shapes_graph, subj), .sparql_rules = snarl_parse_parse_shape_sparql_rules(arena, shapes_graph, subj)});
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
        return ((snarl_types_ShapesGraph){.node_shapes = node_shapes, .property_shapes = prop_shapes, .shape_map = shape_map, .property_shape_map = property_shape_map, .custom_severities = snarl_parse_parse_custom_severities(arena, shapes_graph)});
    }
}

slop_map* snarl_parse_parse_custom_severities(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        __auto_type custom = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, slop_rdf_rdf_Term); slop_map_new_ptr(arena, 0, &_d); });
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#severity"))}, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                __auto_type _mv_554 = rdf_triple_object(t);
                switch (_mv_554.tag) {
                    case slop_rdf_rdf_Term_term_iri:
                    {
                        __auto_type iri = _mv_554.data.term_iri;
                        if (!(string_eq(iri.value, slop_rdf_vocab_SHACL_VIOLATION)) && (!(string_eq(iri.value, slop_rdf_vocab_SHACL_WARNING)) && !(string_eq(iri.value, slop_rdf_vocab_SHACL_INFO)))) {
                            ({ slop_rdf_rdf_Term _key_555 = (rdf_triple_subject(t)); slop_rdf_rdf_Term _val = rdf_triple_object(t); slop_map_put(NULL, custom, &_key_555, &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return custom;
    }
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
        __auto_type rules = snarl_parse_parse_shape_rules(arena, g, shape_id);
        __auto_type order = snarl_parse_parse_order(arena, g, shape_id);
        {
            __auto_type _coll = prop_refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps_ref = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(prop_shapes); __auto_type _item = (snarl_parse_property_shape(arena, g, ps_ref)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((snarl_types_NodeShape){.id = shape_id, .target_nodes = target_nodes, .target_classes = target_classes, .target_subjects_of = target_subjects_of, .target_objects_of = target_objects_of, .property_shapes = prop_shapes, .constraints = constraints, .severity = severity, .message = message, .deactivated = deactivated, .rules = rules, .order = order, .sparql_rules = snarl_parse_parse_shape_sparql_rules(arena, g, shape_id)});
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
    __auto_type _mv_557 = ({ void* _ptr = slop_map_get(built, &(child)); _ptr ? (slop_option_snarl_types_ShaclPath){ .has_value = true, .value = *(snarl_types_ShaclPath*)_ptr } : (slop_option_snarl_types_ShaclPath){ .has_value = false }; });
    if (_mv_557.has_value) {
        __auto_type p = _mv_557.value;
        return p;
    } else if (!_mv_557.has_value) {
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
            __auto_type _mv_558 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_558.has_value) {
                __auto_type inner = _mv_558.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_inverse, .data.path_inverse = ptr });
                }
            } else if (!_mv_558.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((alt_objs).len)) > 0) {
            __auto_type _mv_559 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_559.has_value) {
                __auto_type list_head = _mv_559.value;
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
            } else if (!_mv_559.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((zom_objs).len)) > 0) {
            __auto_type _mv_560 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_560.has_value) {
                __auto_type inner = _mv_560.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_zero_or_more, .data.path_zero_or_more = ptr });
                }
            } else if (!_mv_560.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((oom_objs).len)) > 0) {
            __auto_type _mv_561 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_561.has_value) {
                __auto_type inner = _mv_561.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_one_or_more, .data.path_one_or_more = ptr });
                }
            } else if (!_mv_561.has_value) {
                return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = n });
            }
            SLOP_UNREACHABLE();
        } else if (((int64_t)((zoo_objs).len)) > 0) {
            __auto_type _mv_562 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_562.has_value) {
                __auto_type inner = _mv_562.value;
                {
                    __auto_type p = snarl_parse_parse_path_built_or_leaf(built, inner);
                    __auto_type ptr = ((snarl_types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_zero_or_one, .data.path_zero_or_one = ptr });
                }
            } else if (!_mv_562.has_value) {
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
            __auto_type _mv_563 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_563.has_value) {
                __auto_type item = _mv_563.value;
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
                                    __auto_type _mv_572 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_572.has_value) {
                                        __auto_type inner = _mv_572.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_572.has_value) {
                                    }
                                } else if (((int64_t)((alt_objs).len)) > 0) {
                                    __auto_type _mv_573 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_573.has_value) {
                                        __auto_type list_head = _mv_573.value;
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
                                    } else if (!_mv_573.has_value) {
                                    }
                                } else if (((int64_t)((zom_objs).len)) > 0) {
                                    __auto_type _mv_574 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_574.has_value) {
                                        __auto_type inner = _mv_574.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_574.has_value) {
                                    }
                                } else if (((int64_t)((oom_objs).len)) > 0) {
                                    __auto_type _mv_575 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_575.has_value) {
                                        __auto_type inner = _mv_575.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_575.has_value) {
                                    }
                                } else if (((int64_t)((zoo_objs).len)) > 0) {
                                    __auto_type _mv_576 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_576.has_value) {
                                        __auto_type inner = _mv_576.value;
                                        ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = inner})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_576.has_value) {
                                    }
                                } else if (1) {
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_563.has_value) {
            }
        }
        __auto_type _mv_578 = ({ void* _ptr = slop_map_get(built, &(path_node)); _ptr ? (slop_option_snarl_types_ShaclPath){ .has_value = true, .value = *(snarl_types_ShaclPath*)_ptr } : (slop_option_snarl_types_ShaclPath){ .has_value = false }; });
        if (_mv_578.has_value) {
            __auto_type p = _mv_578.value;
            return p;
        } else if (!_mv_578.has_value) {
            return ((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = path_node });
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_snarl_types_Constraint snarl_parse_constraints(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
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
                    __auto_type _mv_579 = snarl_parse_node_kind(v);
                    if (_mv_579.has_value) {
                        __auto_type nk = _mv_579.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_node_kind, .data.con_node_kind = nk })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_579.has_value) {
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
                    __auto_type _mv_580 = snarl_parse_term_to_int(v);
                    if (_mv_580.has_value) {
                        __auto_type n = _mv_580.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_count, .data.con_min_count = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_580.has_value) {
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
                    __auto_type _mv_581 = snarl_parse_term_to_int(v);
                    if (_mv_581.has_value) {
                        __auto_type n = _mv_581.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_count, .data.con_max_count = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_581.has_value) {
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
                    __auto_type _mv_582 = snarl_parse_term_to_int(v);
                    if (_mv_582.has_value) {
                        __auto_type n = _mv_582.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_min_length, .data.con_min_length = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_582.has_value) {
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
                    __auto_type _mv_583 = snarl_parse_term_to_int(v);
                    if (_mv_583.has_value) {
                        __auto_type n = _mv_583.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_max_length, .data.con_max_length = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_583.has_value) {
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
                    __auto_type _mv_584 = snarl_parse_term_to_string(v);
                    if (_mv_584.has_value) {
                        __auto_type s = _mv_584.value;
                        {
                            __auto_type flags = ({ __auto_type _mv = ({ __auto_type _lst = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, slop_rdf_vocab_SHACL_FLAGS)); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; ({ __auto_type _mv = snarl_parse_term_to_string(f); _mv.has_value ? ({ __auto_type fs = _mv.value; fs; }) : (SLOP_STR("")); }); }) : (SLOP_STR("")); });
                            ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_pattern, .data.con_pattern = { .f0 = s, .f1 = flags } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_584.has_value) {
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
                    __auto_type _mv_585 = snarl_parse_term_to_string(v);
                    if (_mv_585.has_value) {
                        __auto_type s = _mv_585.value;
                        if (string_eq(s, SLOP_STR("true"))) {
                            ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_unique_lang, .data.con_unique_lang = 1 })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_585.has_value) {
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
                    __auto_type _mv_586 = snarl_parse_term_to_bool(v);
                    if (_mv_586.has_value) {
                        __auto_type b = _mv_586.value;
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
                    } else if (!_mv_586.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, snarl_af_vocab_SHACL_EXPRESSION));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(constraints); __auto_type _item = (((snarl_types_Constraint){ .tag = snarl_types_Constraint_con_expression, .data.con_expression = { .f0 = snarl_parse_node_expr(arena, g, v), .f1 = v, .f2 = snarl_parse_parse_shape_message(arena, g, v) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return constraints;
    }
}

slop_option_snarl_types_NodeKind snarl_parse_node_kind(slop_rdf_rdf_Term term) {
    __auto_type _mv_587 = term;
    switch (_mv_587.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_587.data.term_iri;
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
    __auto_type _mv_588 = term;
    switch (_mv_588.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_588.data.term_iri;
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
            __auto_type _mv_589 = ({ __auto_type _lst = sev_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_589.has_value) {
                __auto_type v = _mv_589.value;
                return snarl_parse_severity(v);
            } else if (!_mv_589.has_value) {
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
            __auto_type _mv_590 = ({ __auto_type _lst = msg_vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_590.has_value) {
                __auto_type v = _mv_590.value;
                return snarl_parse_term_to_string(v);
            } else if (!_mv_590.has_value) {
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
            __auto_type _mv_591 = ({ __auto_type _lst = vals; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_591.has_value) {
                __auto_type v = _mv_591.value;
                __auto_type _mv_592 = snarl_parse_term_to_bool(v);
                if (_mv_592.has_value) {
                    __auto_type b = _mv_592.value;
                    return b;
                } else if (!_mv_592.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_591.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        } else {
            return 0;
        }
    }
}

slop_option_int snarl_parse_term_to_int(slop_rdf_rdf_Term t) {
    __auto_type _mv_593 = t;
    switch (_mv_593.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_593.data.term_literal;
            __auto_type _mv_594 = std_strlib_parse_int(lit.value);
            if (_mv_594.is_ok) {
                __auto_type n = _mv_594.data.ok;
                if (n >= 0) {
                    return (slop_option_int){.has_value = 1, .value = n};
                } else {
                    return (slop_option_int){.has_value = false};
                }
            } else if (!_mv_594.is_ok) {
                __auto_type _ = _mv_594.data.err;
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
    __auto_type _mv_595 = t;
    switch (_mv_595.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_595.data.term_literal;
            return (slop_option_string){.has_value = 1, .value = lit.value};
        }
        default: {
            return (slop_option_string){.has_value = false};
        }
    }
}

slop_option_u8 snarl_parse_term_to_bool(slop_rdf_rdf_Term t) {
    __auto_type _mv_596 = t;
    switch (_mv_596.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_596.data.term_literal;
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
                __auto_type _mv_597 = snarl_parse_term_to_string(elem);
                if (_mv_597.has_value) {
                    __auto_type s = _mv_597.value;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_597.has_value) {
                }
            }
        }
        return result;
    }
}

int64_t snarl_parse_node_expr_max_eval_depth(void) {
    return 256;
}

slop_list_slop_rdf_rdf_Term snarl_parse_objects_of(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string pred) {
    return rdf_indexed_graph_objects(arena, g, n, rdf_make_iri(arena, pred));
}

uint8_t snarl_parse_term_is_blank(slop_rdf_rdf_Term t) {
    __auto_type _mv_598 = t;
    switch (_mv_598.tag) {
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_598.data.term_blank;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

slop_option_string snarl_parse_unsupported_shnex_predicate(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type supported = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 6 * sizeof(slop_string)), .len = 6, .cap = 6, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHNEX_VAR; _ll.data[1] = snarl_af_vocab_SHNEX_PATH_VALUES; _ll.data[2] = snarl_af_vocab_SHNEX_FOCUS_NODE; _ll.data[3] = snarl_af_vocab_SHNEX_FILTER_SHAPE; _ll.data[4] = snarl_af_vocab_SHNEX_NODES; _ll.data[5] = snarl_af_vocab_SHNEX_INTERSECTION; _ll; });
        slop_option_string found = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = n}, no_term, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                __auto_type _mv_599 = rdf_triple_predicate(tr);
                switch (_mv_599.tag) {
                    case slop_rdf_rdf_Term_term_iri:
                    {
                        __auto_type iri = _mv_599.data.term_iri;
                        if ((!((found).has_value)) && std_strlib_starts_with(iri.value, snarl_af_vocab_SHNEX_NS)) {
                            {
                                uint8_t known = 0;
                                {
                                    __auto_type _coll = supported;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type s = _coll.data[_i];
                                        if (string_eq(s, iri.value)) {
                                            known = 1;
                                        }
                                    }
                                }
                                if (!(known)) {
                                    found = (slop_option_string){.has_value = 1, .value = iri.value};
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return found;
    }
}

slop_option_string snarl_parse_first_unsupported_property_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_string props) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = props;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!((result).has_value)) {
                    __auto_type _mv_600 = ({ __auto_type _lst = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, p)}, no_term); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_600.has_value) {
                        __auto_type tr = _mv_600.value;
                        result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 5 * sizeof(slop_string)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = SLOP_STR("SHACL 1.2 property "); _ll.data[1] = p; _ll.data[2] = SLOP_STR(" (at "); _ll.data[3] = snarl_types_term_display_label(rdf_triple_subject(tr), SLOP_STR("[anonymous node]")); _ll.data[4] = SLOP_STR(") is not supported by snarl's experimental SHACL 1.2 mode"); _ll; }))};
                    } else if (!_mv_600.has_value) {
                    }
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_parse_first_unsupported_class_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_string classes) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((result).has_value)) {
                    __auto_type _mv_601 = ({ __auto_type _lst = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = type_pred}, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, c)}); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_601.has_value) {
                        __auto_type tr = _mv_601.value;
                        result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 5 * sizeof(slop_string)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = SLOP_STR("SHACL 1.2 class "); _ll.data[1] = c; _ll.data[2] = SLOP_STR(" (at "); _ll.data[3] = snarl_types_term_display_label(rdf_triple_subject(tr), SLOP_STR("[anonymous node]")); _ll.data[4] = SLOP_STR(") is not supported by snarl's experimental SHACL 1.2 mode"); _ll; }))};
                    } else if (!_mv_601.has_value) {
                    }
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_parse_global_rule_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 2 * sizeof(slop_string)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHACL_TRIPLE_RULE; _ll.data[1] = snarl_af_vocab_SHACL_SPARQL_RULE; _ll; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type rule_type = _coll.data[_i];
                {
                    __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = type_pred}, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, rule_type)});
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type tr = _coll.data[_i];
                        {
                            __auto_type rule = rdf_triple_subject(tr);
                            if ((!((result).has_value)) && (((int64_t)((rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, snarl_af_vocab_SHACL_RULE)}, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rule})).len)) == 0)) {
                                result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Rule "); _ll.data[1] = snarl_types_term_display_label(rule, SLOP_STR("[anonymous node]")); _ll.data[2] = SLOP_STR(" is not attached to a shape through sh:rule: SHACL 1.2 global rules are not supported"); _ll; }))};
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_parse_shapes_graph_shacl12_unsupported_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t rules_run) {
    {
        __auto_type result = snarl_parse_first_unsupported_property_message(arena, g, snarl_af_vocab_shacl12_unsupported_properties(arena));
        if (!((result).has_value)) {
            result = snarl_parse_first_unsupported_class_message(arena, g, snarl_af_vocab_shacl12_unsupported_classes(arena));
        }
        if (rules_run) {
            if (!((result).has_value)) {
                result = snarl_parse_first_unsupported_property_message(arena, g, snarl_af_vocab_shacl12_unsupported_rule_properties(arena));
            }
            if (!((result).has_value)) {
                result = snarl_parse_first_unsupported_class_message(arena, g, snarl_af_vocab_shacl12_unsupported_rule_classes(arena));
            }
            if (!((result).has_value)) {
                result = snarl_parse_global_rule_message(arena, g);
            }
        }
        return result;
    }
}

uint8_t snarl_parse_node_has_no_properties(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        return (((int64_t)((rdf_indexed_graph_match(arena, g, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = n}, no_term, no_term)).len)) == 0);
    }
}

slop_option_string snarl_parse_literal_lexical(slop_rdf_rdf_Term t) {
    __auto_type _mv_602 = t;
    switch (_mv_602.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_602.data.term_literal;
            return (slop_option_string){.has_value = 1, .value = lit.value};
        }
        default: {
            return (slop_option_string){.has_value = false};
        }
    }
}

uint8_t snarl_parse_term_is_iri_value(slop_rdf_rdf_Term t, slop_string iri_value) {
    __auto_type _mv_603 = t;
    switch (_mv_603.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_603.data.term_iri;
            return string_eq(iri.value, iri_value);
        }
        default: {
            return 0;
        }
    }
}

uint8_t snarl_parse_rule_is_active(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule) {
    return !(snarl_parse_parse_shape_deactivated(arena, g, rule));
}

slop_list_slop_rdf_rdf_Term snarl_parse_node_expr_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    {
        __auto_type kids = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (snarl_parse_term_is_blank(n)) {
            {
                __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHACL_NODES; _ll.data[1] = snarl_af_vocab_SHNEX_NODES; _ll.data[2] = snarl_af_vocab_SHNEX_FOCUS_NODE; _ll; });
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type pred = _coll.data[_i];
                    {
                        __auto_type _coll = snarl_parse_objects_of(arena, g, n, pred);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type k = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(kids); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
            {
                __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHACL_INTERSECTION; _ll.data[1] = snarl_af_vocab_SHACL_UNION; _ll.data[2] = snarl_af_vocab_SHNEX_INTERSECTION; _ll; });
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type pred = _coll.data[_i];
                    {
                        __auto_type _coll = snarl_parse_objects_of(arena, g, n, pred);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type head = _coll.data[_i];
                            {
                                __auto_type _coll = rdf_list_elements_indexed(arena, g, head);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type k = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(kids); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return kids;
    }
}

slop_list_slop_rdf_rdf_Term snarl_parse_active_rule_nodes(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type rules = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, snarl_af_vocab_SHACL_RULE)}, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                {
                    __auto_type rule = rdf_triple_object(tr);
                    if (snarl_parse_rule_is_active(arena, g, rule)) {
                        (void)(({ __auto_type _lst_p = &(rules); __auto_type _item = (rule); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return rules;
    }
}

slop_list_slop_rdf_rdf_Term snarl_parse_node_expr_roots(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t include_rules) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type roots = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, snarl_af_vocab_SHACL_EXPRESSION)}, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(roots); __auto_type _item = (rdf_triple_object(tr)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (include_rules) {
            {
                __auto_type _coll = snarl_parse_active_rule_nodes(arena, g);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type rule = _coll.data[_i];
                    {
                        __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHACL_SUBJECT; _ll.data[1] = snarl_af_vocab_SHACL_PREDICATE; _ll.data[2] = snarl_af_vocab_SHACL_OBJECT; _ll; });
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type pred = _coll.data[_i];
                            {
                                __auto_type _coll = snarl_parse_objects_of(arena, g, rule, pred);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type v = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(roots); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return roots;
    }
}

int64_t snarl_parse_node_expr_depth(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root, slop_map* depths) {
    int64_t _retval = {0};
    {
        __auto_type on_path = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type work = snarl_parse_path_scan_work_new(arena);
        uint8_t cyclic = 0;
        (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = root})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while ((((int64_t)((work).len)) > 0) && !(cyclic)) {
            __auto_type _mv_604 = ({ __auto_type _lst_p = &(work); slop_option_snarl_parse_PathScanItem _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
            if (_mv_604.has_value) {
                __auto_type item = _mv_604.value;
                {
                    __auto_type n = item.node;
                    if (item.is_exit) {
                        {
                            int64_t best = 0;
                            {
                                __auto_type _coll = snarl_parse_node_expr_children(arena, g, n);
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
                            ({ int64_t _val = (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) - 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                        }
                    } else {
                        if (slop_map_has(depths, &(n))) {
                        } else if (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) > 0) {
                            cyclic = 1;
                        } else if (snarl_parse_term_is_blank(n) && ((((int64_t)((snarl_parse_objects_of(arena, g, n, slop_rdf_vocab_RDF_FIRST)).len)) > 0) && !(snarl_parse_shapes_graph_list_is_acyclic(arena, g, n)))) {
                            cyclic = 1;
                        } else if (1) {
                            ({ int64_t _val = (({ __auto_type _mv = ({ void* _ptr = slop_map_get(on_path, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (0); }) + 1); slop_map_put(NULL, on_path, &(n), &_val, sizeof(_val)); });
                            ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 1, .node = n})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            {
                                __auto_type _coll = snarl_parse_node_expr_children(arena, g, n);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(work); __auto_type _item = (((snarl_parse_PathScanItem){.is_exit = 0, .node = c})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_604.has_value) {
            }
        }
        if (cyclic) {
            _retval = -1;
            goto _slop_post;
        } else {
            __auto_type _mv_614 = ({ void* _ptr = slop_map_get(depths, &(root)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_614.has_value) {
                __auto_type d = _mv_614.value;
                _retval = d;
                goto _slop_post;
            } else if (!_mv_614.has_value) {
                _retval = 0;
                goto _slop_post;
            }
            SLOP_UNREACHABLE();
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    return _retval;
}

slop_option_string snarl_parse_shapes_graph_node_expr_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g) {
    {
        __auto_type depths = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = snarl_parse_node_expr_roots(arena, g, 1);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type root = _coll.data[_i];
                if (!((result).has_value)) {
                    {
                        __auto_type d = snarl_parse_node_expr_depth(arena, g, root, depths);
                        __auto_type label = snarl_types_term_display_label(root, SLOP_STR("[anonymous node]"));
                        if (d < 0) {
                            result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Cyclic node expression detected at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" (node expression contains itself)"); _ll; }))};
                        } else if (d > snarl_parse_node_expr_max_eval_depth()) {
                            result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4, .arena = arena }; _ll.data[0] = SLOP_STR("Node expression nesting depth budget ("); _ll.data[1] = int_to_string(arena, snarl_parse_node_expr_max_eval_depth()); _ll.data[2] = SLOP_STR(") exceeded at "); _ll.data[3] = label; _ll; }))};
                        } else if (1) {
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_parse_list_arity_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string pred, slop_string label) {
    {
        __auto_type heads = snarl_parse_objects_of(arena, g, n, pred);
        if (((int64_t)((heads).len)) == 1) {
            __auto_type _mv_615 = ({ __auto_type _lst = heads; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_615.has_value) {
                __auto_type head = _mv_615.value;
                if (((int64_t)((rdf_list_elements_indexed(arena, g, head)).len)) >= 2) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 5 * sizeof(slop_string)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": "); _ll.data[3] = pred; _ll.data[4] = SLOP_STR(" needs a list of at least two node expressions"); _ll; }))};
                }
            } else if (!_mv_615.has_value) {
                return (slop_option_string){.has_value = false};
            }
            SLOP_UNREACHABLE();
        } else {
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one "); _ll.data[3] = pred; _ll; }))};
        }
    }
}

slop_string snarl_parse_function_expression_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string label) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        __auto_type triples = rdf_indexed_graph_match(arena, g, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = n}, no_term, no_term);
        __auto_type _mv_616 = ({ __auto_type _lst = triples; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_616.has_value) {
            __auto_type tr = _mv_616.value;
            {
                __auto_type obj = rdf_triple_object(tr);
                if ((((int64_t)((triples).len)) == 1) && (snarl_parse_term_is_iri_value(obj, slop_rdf_vocab_RDF_NIL) || (((int64_t)((snarl_parse_objects_of(arena, g, obj, slop_rdf_vocab_RDF_FIRST)).len)) > 0))) {
                    return std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 5 * sizeof(slop_string)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = SLOP_STR("SHACL function expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" calls "); _ll.data[3] = snarl_types_term_display_label(rdf_triple_predicate(tr), SLOP_STR("[anonymous node]")); _ll.data[4] = SLOP_STR(": SHACL functions need SPARQL, which snarl does not implement"); _ll; }));
                } else {
                    return std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 2 * sizeof(slop_string)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll; }));
                }
            }
        } else if (!_mv_616.has_value) {
            return std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 2 * sizeof(slop_string)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll; }));
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_string snarl_parse_node_expr_12_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_string label) {
    {
        __auto_type n_var = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_VAR)).len));
        __auto_type n_path = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_PATH_VALUES)).len));
        __auto_type n_focus = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_FOCUS_NODE)).len));
        __auto_type n_filter = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_FILTER_SHAPE)).len));
        __auto_type n_nodes = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_NODES)).len));
        __auto_type n_inter = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_INTERSECTION)).len));
        __auto_type n_first = ((int64_t)((snarl_parse_objects_of(arena, g, n, slop_rdf_vocab_RDF_FIRST)).len));
        int64_t kinds = 0;
        {
            __auto_type _coll = ({ slop_list_int _ll = (slop_list_int){ .data = (int64_t*)slop_arena_alloc(arena, 5 * sizeof(int64_t)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = n_var; _ll.data[1] = n_path; _ll.data[2] = n_filter; _ll.data[3] = n_inter; _ll.data[4] = n_first; _ll; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (k > 0) {
                    kinds = (kinds + 1);
                }
            }
        }
        if (kinds == 0) {
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": shnex:nodes and shnex:focusNode need a shnex:filterShape or shnex:pathValues"); _ll; }))};
        } else if (kinds > 1) {
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it combines more than one kind of expression"); _ll; }))};
        } else if (n_var > 0) {
            {
                __auto_type name = ({ __auto_type _mv = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_VAR); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; snarl_parse_literal_lexical(t); }) : (((slop_option_string){.has_value = false})); });
                __auto_type _mv_617 = name;
                if (_mv_617.has_value) {
                    __auto_type v = _mv_617.value;
                    if (((n_var == 1)) && ((string_len(v) > 0)) && (((n_focus + n_nodes) == 0))) {
                        return (slop_option_string){.has_value = false};
                    } else {
                        return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed var expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one non-empty string shnex:var"); _ll; }))};
                    }
                } else if (!_mv_617.has_value) {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed var expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one non-empty string shnex:var"); _ll; }))};
                }
                SLOP_UNREACHABLE();
            }
        } else if (n_path > 0) {
            if (((n_path == 1)) && ((n_focus <= 1)) && ((n_nodes == 0))) {
                return (slop_option_string){.has_value = false};
            } else {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed path values expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one shnex:pathValues and at most one shnex:focusNode"); _ll; }))};
            }
        } else if (n_filter > 0) {
            if (((n_filter == 1)) && ((n_nodes == 1)) && ((n_focus == 0))) {
                return (slop_option_string){.has_value = false};
            } else {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed filter shape expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one shnex:filterShape and one shnex:nodes"); _ll; }))};
            }
        } else if (n_inter > 0) {
            {
                __auto_type heads = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_INTERSECTION);
                if ((n_inter == 1) && ({ __auto_type _mv = ({ __auto_type _lst = heads; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type head = _mv.value; (((int64_t)((rdf_list_elements_indexed(arena, g, head)).len)) > 0); }) : (0); })) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed intersection expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one shnex:intersection, a non-empty list of node expressions"); _ll; }))};
                }
            }
        } else if (1) {
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = rdf_list_elements_indexed(arena, g, n);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        if (snarl_parse_term_is_blank(m)) {
                            ok = 0;
                        }
                    }
                }
                if (ok) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed list expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": its members must be constants (IRIs, literals or triple terms)"); _ll; }))};
                }
            }
        }
    }
}

slop_option_string snarl_parse_node_expr_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, uint8_t shacl12) {
    if (!(snarl_parse_term_is_blank(n))) {
        return (slop_option_string){.has_value = false};
    } else {
        {
            __auto_type label = snarl_types_term_display_label(n, SLOP_STR("[anonymous node]"));
            __auto_type n_filter = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_FILTER_SHAPE)).len));
            __auto_type n_path = ((int64_t)((snarl_parse_objects_of(arena, g, n, slop_rdf_vocab_SHACL_PATH)).len));
            __auto_type n_inter = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_INTERSECTION)).len));
            __auto_type n_union = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_UNION)).len));
            __auto_type n_nodes = ((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_NODES)).len));
            __auto_type unknown_12 = snarl_parse_unsupported_shnex_predicate(arena, g, n);
            int64_t n_12 = 0;
            int64_t kinds = 0;
            {
                __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 7 * sizeof(slop_string)), .len = 7, .cap = 7, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHNEX_VAR; _ll.data[1] = snarl_af_vocab_SHNEX_PATH_VALUES; _ll.data[2] = snarl_af_vocab_SHNEX_FOCUS_NODE; _ll.data[3] = snarl_af_vocab_SHNEX_FILTER_SHAPE; _ll.data[4] = snarl_af_vocab_SHNEX_NODES; _ll.data[5] = snarl_af_vocab_SHNEX_INTERSECTION; _ll.data[6] = slop_rdf_vocab_RDF_FIRST; _ll; });
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type pred = _coll.data[_i];
                    n_12 = (n_12 + ((int64_t)((snarl_parse_objects_of(arena, g, n, pred)).len)));
                }
            }
            if (n_filter > 0) {
                kinds = (kinds + 1);
            }
            if (n_path > 0) {
                kinds = (kinds + 1);
            }
            if (n_inter > 0) {
                kinds = (kinds + 1);
            }
            if (n_union > 0) {
                kinds = (kinds + 1);
            }
            if ((((unknown_12).has_value)) && !(shacl12)) {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" uses SHACL 1.2 syntax, which needs the experimental SHACL 1.2 mode (--shacl12)"); _ll; }))};
            } else if (((unknown_12).has_value)) {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 5 * sizeof(slop_string)), .len = 5, .cap = 5, .arena = arena }; _ll.data[0] = SLOP_STR("SHACL 1.2 node expression "); _ll.data[1] = ({ __auto_type _mv = unknown_12; _mv.has_value ? ({ __auto_type p = _mv.value; p; }) : (SLOP_STR("")); }); _ll.data[2] = SLOP_STR(" at "); _ll.data[3] = label; _ll.data[4] = SLOP_STR(" is not supported by snarl"); _ll; }))};
            } else if ((n_12 > 0) && !(shacl12)) {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" uses SHACL 1.2 syntax, which needs the experimental SHACL 1.2 mode (--shacl12)"); _ll; }))};
            } else if ((n_12 > 0) && (kinds > 0)) {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it combines SHACL-AF and SHACL 1.2 syntax"); _ll; }))};
            } else if (n_12 > 0) {
                return snarl_parse_node_expr_12_form_message(arena, g, n, label);
            } else if (shacl12 && snarl_parse_node_has_no_properties(arena, g, n)) {
                return (slop_option_string){.has_value = false};
            } else if (kinds == 0) {
                return (slop_option_string){.has_value = 1, .value = snarl_parse_function_expression_message(arena, g, n, label)};
            } else if (kinds > 1) {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed node expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it combines more than one kind of expression"); _ll; }))};
            } else if (n_filter > 0) {
                if ((n_filter == 1) && (n_nodes == 1)) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed filter shape expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one sh:filterShape and one sh:nodes"); _ll; }))};
                }
            } else if (n_path > 0) {
                if ((n_path == 1) && (n_nodes <= 1)) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed path expression at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one sh:path and at most one sh:nodes"); _ll; }))};
                }
            } else if (n_inter > 0) {
                return snarl_parse_list_arity_message(arena, g, n, snarl_af_vocab_SHACL_INTERSECTION, label);
            } else if (1) {
                return snarl_parse_list_arity_message(arena, g, n, snarl_af_vocab_SHACL_UNION, label);
            }
        }
    }
}

uint8_t snarl_parse_rule_has_type(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, slop_string type_iri) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = snarl_parse_objects_of(arena, g, rule, slop_rdf_vocab_RDF_TYPE);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (snarl_parse_term_is_iri_value(t, type_iri)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_option_string snarl_parse_rule_form_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, uint8_t shacl12, uint8_t defer_sparql) {
    {
        __auto_type label = snarl_types_term_display_label(rule, SLOP_STR("[anonymous node]"));
        __auto_type types = snarl_parse_objects_of(arena, g, rule, slop_rdf_vocab_RDF_TYPE);
        uint8_t is_triple = 0;
        uint8_t is_sparql = 0;
        {
            __auto_type _coll = types;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (snarl_parse_term_is_iri_value(t, snarl_af_vocab_SHACL_TRIPLE_RULE)) {
                    is_triple = 1;
                }
                if (snarl_parse_term_is_iri_value(t, snarl_af_vocab_SHACL_SPARQL_RULE)) {
                    is_sparql = 1;
                }
            }
        }
        if (is_triple) {
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = snarl_af_vocab_SHACL_SUBJECT; _ll.data[1] = snarl_af_vocab_SHACL_PREDICATE; _ll.data[2] = snarl_af_vocab_SHACL_OBJECT; _ll; });
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type pred = _coll.data[_i];
                        {
                            __auto_type n = ((int64_t)((snarl_parse_objects_of(arena, g, rule, pred)).len));
                            if ((n > 1) || (!(shacl12) && (n == 0))) {
                                ok = 0;
                            }
                        }
                    }
                }
                if (ok) {
                    return (slop_option_string){.has_value = false};
                } else {
                    return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Ill-formed sh:TripleRule at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(": it needs exactly one each of sh:subject, sh:predicate and sh:object"); _ll; }))};
                }
            }
        } else if (is_sparql) {
            if (defer_sparql) {
                return (slop_option_string){.has_value = false};
            } else {
                return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("sh:SPARQLRule at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" is not supported: snarl does not implement SPARQL"); _ll; }))};
            }
        } else if (1) {
            return (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Unsupported SHACL rule type at "); _ll.data[1] = label; _ll.data[2] = SLOP_STR(" (snarl executes sh:TripleRule only)"); _ll; }))};
        }
    }
}

uint8_t snarl_parse_shapes_graph_declares_rules_entailment(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t shacl12) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        uint8_t declared = 0;
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, snarl_af_vocab_SHACL_ENTAILMENT)}, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                {
                    __auto_type e = rdf_triple_object(tr);
                    if (snarl_parse_term_is_iri_value(e, snarl_af_vocab_SHACL_RULES) || (shacl12 && snarl_parse_term_is_iri_value(e, snarl_af_vocab_SHACL_RULES_ENTAILMENT))) {
                        declared = 1;
                    }
                }
            }
        }
        return declared;
    }
}

slop_option_string snarl_shapes_graph_unsupported_feature_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, uint8_t shacl12, uint8_t rules_run, uint8_t defer_sparql) {
    {
        slop_option_slop_rdf_rdf_Term no_term = (slop_option_slop_rdf_rdf_Term){.has_value = false};
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = rdf_indexed_graph_match(arena, g, no_term, (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, snarl_af_vocab_SHACL_ENTAILMENT)}, no_term);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tr = _coll.data[_i];
                {
                    __auto_type e = rdf_triple_object(tr);
                    if ((!((result).has_value)) && !((snarl_parse_term_is_iri_value(e, snarl_af_vocab_SHACL_RULES) || (shacl12 && snarl_parse_term_is_iri_value(e, snarl_af_vocab_SHACL_RULES_ENTAILMENT))))) {
                        result = (slop_option_string){.has_value = 1, .value = ((snarl_parse_term_is_iri_value(e, snarl_af_vocab_SHACL_RULES_ENTAILMENT)) ? SLOP_STR("Entailment regime sh:RulesEntailment is SHACL 1.2, which needs the experimental SHACL 1.2 mode (--shacl12)") : std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 2 * sizeof(slop_string)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = SLOP_STR("Unsupported entailment regime "); _ll.data[1] = snarl_types_term_display_label(e, SLOP_STR("[anonymous node]")); _ll; })))};
                    }
                }
            }
        }
        if (shacl12 && (!((result).has_value))) {
            result = snarl_parse_shapes_graph_shacl12_unsupported_message(arena, g, rules_run);
        }
        if (rules_run) {
            {
                __auto_type _coll = snarl_parse_active_rule_nodes(arena, g);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type rule = _coll.data[_i];
                    if (!((result).has_value)) {
                        result = snarl_parse_rule_form_message(arena, g, rule, shacl12, defer_sparql);
                    }
                }
            }
        }
        {
            __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            __auto_type work = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = snarl_parse_node_expr_roots(arena, g, rules_run);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type root = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (root); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            while ((((int64_t)((work).len)) > 0) && (!((result).has_value))) {
                __auto_type _mv_618 = ({ __auto_type _lst_p = &(work); slop_option_slop_rdf_rdf_Term _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
                if (_mv_618.has_value) {
                    __auto_type n = _mv_618.value;
                    if (!(slop_map_has(seen, &(n)))) {
                        ({ slop_map_put(NULL, seen, &(n), NULL, 0); });
                        result = snarl_parse_node_expr_form_message(arena, g, n, shacl12);
                        {
                            __auto_type _coll = snarl_parse_node_expr_children(arena, g, n);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(work); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                } else if (!_mv_618.has_value) {
                }
            }
        }
        return result;
    }
}

snarl_types_NodeExpr* snarl_parse_node_expr_box(slop_arena* arena, snarl_types_NodeExpr e) {
    {
        __auto_type ptr = ((snarl_types_NodeExpr*)(({ __auto_type _alloc = (snarl_types_NodeExpr*)slop_arena_alloc(arena, sizeof(snarl_types_NodeExpr)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*ptr) = e;
        return ptr;
    }
}

snarl_types_NodeExpr snarl_parse_parse_node_expr_input(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_slop_rdf_rdf_Term nodes_objs) {
    __auto_type _mv_621 = ({ __auto_type _lst = nodes_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_621.has_value) {
        __auto_type n = _mv_621.value;
        return snarl_parse_node_expr(arena, g, n);
    } else if (!_mv_621.has_value) {
        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_focus });
    }
    SLOP_UNREACHABLE();
}

snarl_types_NodeExpr snarl_parse_node_expr(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    __auto_type _mv_622 = n;
    switch (_mv_622.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_622.data.term_iri;
            if (string_eq(iri.value, snarl_af_vocab_SHACL_THIS)) {
                return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_focus });
            } else {
                return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
            }
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_622.data.term_blank;
            {
                __auto_type filter_objs = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_FILTER_SHAPE);
                __auto_type path_objs = snarl_parse_objects_of(arena, g, n, slop_rdf_vocab_SHACL_PATH);
                __auto_type inter_objs = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_INTERSECTION);
                __auto_type union_objs = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_UNION);
                __auto_type nodes_objs = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_NODES);
                if (((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_VAR)).len)) > 0) {
                    __auto_type _mv_623 = ({ __auto_type _mv = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_VAR); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; snarl_parse_literal_lexical(t); }) : ((slop_option_string){.has_value = false}); });
                    if (_mv_623.has_value) {
                        __auto_type name = _mv_623.value;
                        if (string_eq(name, snarl_af_vocab_SHNEX_FOCUS_NODE_VAR)) {
                            return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_focus });
                        } else {
                            return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_list, .data.nx_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) });
                        }
                    } else if (!_mv_623.has_value) {
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_list, .data.nx_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) });
                    }
                    SLOP_UNREACHABLE();
                } else if (((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_PATH_VALUES)).len)) > 0) {
                    __auto_type _mv_624 = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_PATH_VALUES); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_624.has_value) {
                        __auto_type path_node = _mv_624.value;
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_path, .data.nx_path = { .f0 = snarl_parse_path(arena, g, path_node), .f1 = snarl_parse_node_expr_box(arena, snarl_parse_parse_node_expr_input(arena, g, snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_FOCUS_NODE))), .f2 = 1 } });
                    } else if (!_mv_624.has_value) {
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
                    }
                    SLOP_UNREACHABLE();
                } else if (((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_FILTER_SHAPE)).len)) > 0) {
                    __auto_type _mv_625 = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_FILTER_SHAPE); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_625.has_value) {
                        __auto_type shape_ref = _mv_625.value;
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_filter, .data.nx_filter = { .f0 = shape_ref, .f1 = snarl_parse_node_expr_box(arena, snarl_parse_parse_node_expr_input(arena, g, snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_NODES))) } });
                    } else if (!_mv_625.has_value) {
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
                    }
                    SLOP_UNREACHABLE();
                } else if (((int64_t)((snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_INTERSECTION)).len)) > 0) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_intersection, .data.nx_intersection = snarl_parse_parse_node_expr_list(arena, g, snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHNEX_INTERSECTION)) });
                } else if (((int64_t)((snarl_parse_objects_of(arena, g, n, slop_rdf_vocab_RDF_FIRST)).len)) > 0) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_list, .data.nx_list = rdf_list_elements_indexed(arena, g, n) });
                } else if (snarl_parse_node_has_no_properties(arena, g, n)) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_list, .data.nx_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) });
                } else if (((int64_t)((filter_objs).len)) > 0) {
                    __auto_type _mv_626 = ({ __auto_type _lst = filter_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_626.has_value) {
                        __auto_type shape_ref = _mv_626.value;
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_filter, .data.nx_filter = { .f0 = shape_ref, .f1 = snarl_parse_node_expr_box(arena, snarl_parse_parse_node_expr_input(arena, g, nodes_objs)) } });
                    } else if (!_mv_626.has_value) {
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
                    }
                    SLOP_UNREACHABLE();
                } else if (((int64_t)((path_objs).len)) > 0) {
                    __auto_type _mv_627 = ({ __auto_type _lst = path_objs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_627.has_value) {
                        __auto_type path_node = _mv_627.value;
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_path, .data.nx_path = { .f0 = snarl_parse_path(arena, g, path_node), .f1 = snarl_parse_node_expr_box(arena, snarl_parse_parse_node_expr_input(arena, g, nodes_objs)), .f2 = 0 } });
                    } else if (!_mv_627.has_value) {
                        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
                    }
                    SLOP_UNREACHABLE();
                } else if (((int64_t)((inter_objs).len)) > 0) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_intersection, .data.nx_intersection = snarl_parse_parse_node_expr_list(arena, g, inter_objs) });
                } else if (((int64_t)((union_objs).len)) > 0) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_union, .data.nx_union = snarl_parse_parse_node_expr_list(arena, g, union_objs) });
                } else if (1) {
                    return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_constant, .data.nx_constant = n });
        }
    }
}

slop_list_snarl_types_NodeExpr snarl_parse_parse_node_expr_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_slop_rdf_rdf_Term heads) {
    {
        __auto_type exprs = ((slop_list_snarl_types_NodeExpr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_628 = ({ __auto_type _lst = heads; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_628.has_value) {
            __auto_type head = _mv_628.value;
            {
                __auto_type _coll = rdf_list_elements_indexed(arena, g, head);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type m = _coll.data[_i];
                    ({ __auto_type _lst_p = &(exprs); __auto_type _item = (snarl_parse_node_expr(arena, g, m)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_628.has_value) {
        }
        return exprs;
    }
}

slop_list_slop_rdf_rdf_Term snarl_node_expr_shape_refs(slop_arena* arena, snarl_types_NodeExpr e) {
    {
        __auto_type refs = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_629 = e;
        switch (_mv_629.tag) {
            case snarl_types_NodeExpr_nx_filter:
            {
                __auto_type ref = _mv_629.data.nx_filter.f0;
                __auto_type input = _mv_629.data.nx_filter.f1;
                ({ __auto_type _lst_p = &(refs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                {
                    __auto_type _coll = snarl_node_expr_shape_refs(arena, (*input));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        ({ __auto_type _lst_p = &(refs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case snarl_types_NodeExpr_nx_path:
            {
                __auto_type input = _mv_629.data.nx_path.f1;
                {
                    __auto_type _coll = snarl_node_expr_shape_refs(arena, (*input));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        ({ __auto_type _lst_p = &(refs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case snarl_types_NodeExpr_nx_intersection:
            {
                __auto_type es = _mv_629.data.nx_intersection;
                {
                    __auto_type _coll = es;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        {
                            __auto_type _coll = snarl_node_expr_shape_refs(arena, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(refs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_NodeExpr_nx_union:
            {
                __auto_type es = _mv_629.data.nx_union;
                {
                    __auto_type _coll = es;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        {
                            __auto_type _coll = snarl_node_expr_shape_refs(arena, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(refs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
        return refs;
    }
}

slop_list_slop_rdf_rdf_Term snarl_parse_rule_shape_refs(slop_arena* arena, slop_list_snarl_types_Rule rules) {
    {
        __auto_type refs = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rules;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type rule = _coll.data[_i];
                {
                    __auto_type _coll = rule.conditions;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(refs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                {
                    __auto_type _coll = ({ slop_list_snarl_types_NodeExpr _ll = (slop_list_snarl_types_NodeExpr){ .data = (snarl_types_NodeExpr*)slop_arena_alloc(arena, 3 * sizeof(snarl_types_NodeExpr)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = rule.subject; _ll.data[1] = rule.predicate; _ll.data[2] = rule.object; _ll; });
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type e = _coll.data[_i];
                        {
                            __auto_type _coll = snarl_node_expr_shape_refs(arena, e);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(refs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return refs;
    }
}

double snarl_parse_parse_order(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n) {
    __auto_type _mv_630 = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, n, snarl_af_vocab_SHACL_ORDER); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_630.has_value) {
        __auto_type t = _mv_630.value;
        __auto_type _mv_631 = snarl_parse_term_to_string(t);
        if (_mv_631.has_value) {
            __auto_type s = _mv_631.value;
            __auto_type _mv_632 = std_strlib_parse_float(s);
            if (_mv_632.is_ok) {
                __auto_type f = _mv_632.data.ok;
                return f;
            } else if (!_mv_632.is_ok) {
                __auto_type _ = _mv_632.data.err;
                return 0.0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_631.has_value) {
            return 0.0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_630.has_value) {
        return 0.0;
    }
    SLOP_UNREACHABLE();
}

snarl_types_NodeExpr snarl_parse_parse_rule_slot(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term rule, slop_string pred) {
    __auto_type _mv_633 = ({ __auto_type _lst = snarl_parse_objects_of(arena, g, rule, pred); size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_633.has_value) {
        __auto_type n = _mv_633.value;
        return snarl_parse_node_expr(arena, g, n);
    } else if (!_mv_633.has_value) {
        return ((snarl_types_NodeExpr){ .tag = snarl_types_NodeExpr_nx_focus });
    }
    SLOP_UNREACHABLE();
}

slop_list_snarl_types_Rule snarl_parse_parse_shape_rules(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type rules = ((slop_list_snarl_types_Rule){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = snarl_parse_objects_of(arena, g, shape_id, snarl_af_vocab_SHACL_RULE);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (snarl_parse_rule_is_active(arena, g, r) && snarl_parse_rule_has_type(arena, g, r, snarl_af_vocab_SHACL_TRIPLE_RULE)) {
                    (void)(({ __auto_type _lst_p = &(rules); __auto_type _item = (((snarl_types_Rule){.id = r, .subject = snarl_parse_parse_rule_slot(arena, g, r, snarl_af_vocab_SHACL_SUBJECT), .predicate = snarl_parse_parse_rule_slot(arena, g, r, snarl_af_vocab_SHACL_PREDICATE), .object = snarl_parse_parse_rule_slot(arena, g, r, snarl_af_vocab_SHACL_OBJECT), .conditions = snarl_parse_objects_of(arena, g, r, snarl_af_vocab_SHACL_CONDITION), .order = snarl_parse_parse_order(arena, g, r)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return rules;
    }
}

slop_list_snarl_types_SparqlRuleRef snarl_parse_parse_shape_sparql_rules(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id) {
    {
        __auto_type refs = ((slop_list_snarl_types_SparqlRuleRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = snarl_parse_objects_of(arena, g, shape_id, snarl_af_vocab_SHACL_RULE);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (snarl_parse_rule_is_active(arena, g, r) && (snarl_parse_rule_has_type(arena, g, r, snarl_af_vocab_SHACL_SPARQL_RULE) && !(snarl_parse_rule_has_type(arena, g, r, snarl_af_vocab_SHACL_TRIPLE_RULE)))) {
                    (void)(({ __auto_type _lst_p = &(refs); __auto_type _item = (((snarl_types_SparqlRuleRef){.id = r, .order = snarl_parse_parse_order(arena, g, r)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return refs;
    }
}

