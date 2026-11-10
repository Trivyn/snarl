#include "../runtime/slop_runtime.h"
#include "slop_rules.h"

uint8_t snarl_rules_task_before(snarl_rules_RuleTask a, snarl_rules_RuleTask b);
uint8_t snarl_rules_task_same_level(snarl_rules_RuleTask a, snarl_rules_RuleTask b);
slop_list_snarl_rules_RuleTask snarl_rules_collect_rule_tasks(slop_arena* arena, snarl_types_ShapesGraph shapes_graph, uint8_t shacl12);
uint8_t snarl_rules_triple_is_well_formed(slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
uint8_t snarl_rules_conforms_to_all(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, slop_list_slop_rdf_rdf_Term shape_refs, snarl_engine_CycleGuard guard);
snarl_rules_InferResult snarl_infer_rules(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);

typedef struct { slop_arena* arena; snarl_data_graph_SnarlDataGraph* graph; snarl_types_ShapesGraph shapes_graph; snarl_target_ClassIndex class_index; snarl_engine_CycleGuard guard; } snarl_rules__lambda_485_env_t;

static uint8_t snarl_rules__lambda_485(snarl_rules__lambda_485_env_t* _env, slop_rdf_rdf_Term n, slop_rdf_rdf_Term ref) { return snarl_node_conforms_to_shape_ref(_env->arena, (*_env->graph), _env->shapes_graph, _env->class_index, n, ref, _env->guard); }

uint8_t snarl_rules_task_before(snarl_rules_RuleTask a, snarl_rules_RuleTask b) {
    return ((a.shape_order < b.shape_order) || ((a.shape_order == b.shape_order) && (a.rule_order < b.rule_order)));
}

uint8_t snarl_rules_task_same_level(snarl_rules_RuleTask a, snarl_rules_RuleTask b) {
    return ((a.shape_order == b.shape_order) && (a.rule_order == b.rule_order));
}

slop_list_snarl_rules_RuleTask snarl_rules_collect_rule_tasks(slop_arena* arena, snarl_types_ShapesGraph shapes_graph, uint8_t shacl12) {
    {
        __auto_type tasks = ((slop_list_snarl_rules_RuleTask){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sorted = ((slop_list_snarl_rules_RuleTask){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                if (!(ns.deactivated)) {
                    {
                        __auto_type _coll = ns.rules;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(tasks); __auto_type _item = (((snarl_rules_RuleTask){.shape = ns, .rule = r, .shape_order = ((shacl12) ? 0.0 : ns.order), .rule_order = r.order})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        {
            __auto_type taken = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
            __auto_type n = ((int64_t)((tasks).len));
            while (((int64_t)((sorted).len)) < n) {
                {
                    int64_t best = -1;
                    int64_t i = 0;
                    while (i < n) {
                        if (!(slop_map_has(taken, &(int64_t){i}))) {
                            if (best < 0) {
                                best = i;
                            } else {
                                __auto_type _mv_479 = ({ __auto_type _lst = tasks; size_t _idx = (size_t)i; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_479.has_value) {
                                    __auto_type ti = _mv_479.value;
                                    __auto_type _mv_480 = ({ __auto_type _lst = tasks; size_t _idx = (size_t)best; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_480.has_value) {
                                        __auto_type tb = _mv_480.value;
                                        if (snarl_rules_task_before(ti, tb)) {
                                            best = i;
                                        }
                                    } else if (!_mv_480.has_value) {
                                    }
                                } else if (!_mv_479.has_value) {
                                }
                            }
                        }
                        i = (i + 1);
                    }
                    (void)(({ slop_map_put(NULL, taken, &(int64_t){best}, NULL, 0); }));
                    __auto_type _mv_482 = ({ __auto_type _lst = tasks; size_t _idx = (size_t)best; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_482.has_value) {
                        __auto_type t = _mv_482.value;
                        ({ __auto_type _lst_p = &(sorted); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_482.has_value) {
                    }
                }
            }
        }
        return sorted;
    }
}

uint8_t snarl_rules_triple_is_well_formed(slop_rdf_rdf_Term s, slop_rdf_rdf_Term p) {
    return (({ __auto_type _mv = s; uint8_t _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_iri: { _mr = 1; break; } case slop_rdf_rdf_Term_term_blank: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }) && ({ __auto_type _mv = p; uint8_t _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_iri: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }));
}

uint8_t snarl_rules_conforms_to_all(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, slop_list_slop_rdf_rdf_Term shape_refs, snarl_engine_CycleGuard guard) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = shape_refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ref = _coll.data[_i];
                if (ok) {
                    if (!(snarl_node_conforms_to_shape_ref(arena, data_graph, shapes_graph, class_index, node, ref, guard))) {
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

snarl_rules_InferResult snarl_infer_rules(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config) {
    {
        __auto_type tasks = snarl_rules_collect_rule_tasks(arena, shapes_graph, config.shacl12);
        __auto_type graph = data_graph;
        __auto_type inferred = ((slop_list_slop_rdf_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string error = (slop_option_string){.has_value = false};
        int64_t i = 0;
        while ((i < ((int64_t)((tasks).len))) && (!((error).has_value))) {
            {
                __auto_type class_index = snarl_target_build_class_index(arena, graph, shapes_graph);
                __auto_type level = ((slop_list_slop_rdf_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type level_seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Triple, slop_hash_slop_rdf_rdf_Triple, slop_eq_slop_rdf_rdf_Triple, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                int64_t j = i;
                __auto_type _mv_483 = ({ __auto_type _lst = tasks; size_t _idx = (size_t)i; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_483.has_value) {
                    __auto_type first = _mv_483.value;
                    while ((j < ((int64_t)((tasks).len))) && ({ __auto_type _mv = ({ __auto_type _lst = tasks; size_t _idx = (size_t)j; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; snarl_rules_task_same_level(t, first); }) : (0); })) {
                        __auto_type _mv_484 = ({ __auto_type _lst = tasks; size_t _idx = (size_t)j; slop_option_snarl_rules_RuleTask _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_484.has_value) {
                            __auto_type task = _mv_484.value;
                            {
                                __auto_type rule = task.rule;
                                __auto_type guard = snarl_engine_cycle_guard_new(arena);
                                __auto_type conforms = ({ snarl_rules__lambda_485_env_t* snarl_rules__lambda_485_env = (snarl_rules__lambda_485_env_t*)slop_arena_alloc(arena, sizeof(snarl_rules__lambda_485_env_t)); *snarl_rules__lambda_485_env = (snarl_rules__lambda_485_env_t){ .arena = arena, .graph = &(graph), .shapes_graph = shapes_graph, .class_index = class_index, .guard = guard }; (slop_closure_t){ (void*)snarl_rules__lambda_485, (void*)snarl_rules__lambda_485_env }; });
                                {
                                    __auto_type _coll = snarl_resolve_targets(arena, graph, task.shape);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type focus = _coll.data[_i];
                                        if ((!((error).has_value)) && snarl_rules_conforms_to_all(arena, graph, shapes_graph, class_index, focus, rule.conditions, guard)) {
                                            {
                                                __auto_type subjects = snarl_eval_node_expr(arena, graph, rule.subject, focus, conforms, guard.errors);
                                                __auto_type predicates = snarl_eval_node_expr(arena, graph, rule.predicate, focus, conforms, guard.errors);
                                                __auto_type objects = snarl_eval_node_expr(arena, graph, rule.object, focus, conforms, guard.errors);
                                                {
                                                    __auto_type _coll = subjects;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type s = _coll.data[_i];
                                                        {
                                                            __auto_type _coll = predicates;
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type p = _coll.data[_i];
                                                                if (snarl_rules_triple_is_well_formed(s, p)) {
                                                                    {
                                                                        __auto_type _coll = objects;
                                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                            __auto_type o = _coll.data[_i];
                                                                            {
                                                                                __auto_type t = rdf_make_triple(arena, s, p, o);
                                                                                if (!(slop_map_has(level_seen, &(t))) && !(snarl_data_graph_contains(graph, t))) {
                                                                                    ({ slop_map_put(NULL, level_seen, &(t), NULL, 0); });
                                                                                    ({ __auto_type _lst_p = &(level); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                            __auto_type _mv_489 = ({ void* _ptr = slop_map_get(guard.errors, &(int64_t){0}); _ptr ? (slop_option_string){ .has_value = true, .value = *(slop_string*)_ptr } : (slop_option_string){ .has_value = false }; });
                                            if (_mv_489.has_value) {
                                                __auto_type msg = _mv_489.value;
                                                error = (slop_option_string){.has_value = 1, .value = msg};
                                            } else if (!_mv_489.has_value) {
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_484.has_value) {
                        }
                        j = (j + 1);
                    }
                } else if (!_mv_483.has_value) {
                    j = (j + 1);
                }
                {
                    __auto_type _coll = level;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type t = _coll.data[_i];
                        graph = snarl_data_graph_add(arena, graph, t);
                        (void)(({ __auto_type _lst_p = &(inferred); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                i = j;
            }
        }
        __auto_type _mv_490 = error;
        if (_mv_490.has_value) {
            __auto_type msg = _mv_490.value;
            return ((snarl_rules_InferResult){ .tag = snarl_rules_InferResult_infer_error, .data.infer_error = msg });
        } else if (!_mv_490.has_value) {
            return ((snarl_rules_InferResult){ .tag = snarl_rules_InferResult_infer_success, .data.infer_success = ((snarl_rules_InferOutput){.graph = graph, .inferred = inferred}) });
        }
        SLOP_UNREACHABLE();
    }
}

