#include "../runtime/slop_runtime.h"
#include "slop_engine.h"

#define snarl_engine_CYCLE_GUARD_SLOT (0)

int64_t snarl_engine_cycle_guard_max_recursion_depth(void);
snarl_engine_CycleGuard snarl_engine_cycle_guard_new(slop_arena* arena);
int64_t snarl_engine_cycle_guard_depth(snarl_engine_CycleGuard guard);
uint8_t snarl_engine_cycle_guard_pair_active(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
uint8_t snarl_engine_cycle_guard_has(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_add(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_remove(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag_depth_budget(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag_recursion(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
uint8_t snarl_property_shape_conforms(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
uint8_t snarl_engine_property_shape_conforms_with_guard(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps, snarl_engine_CycleGuard visited);
slop_option_string snarl_engine_constraints_pattern_error_message(slop_arena* arena, slop_rdf_rdf_Term shape_id, slop_list_snarl_types_Constraint constraints);
slop_option_string snarl_engine_property_shape_pattern_error_message(slop_arena* arena, snarl_types_PropertyShape ps);
slop_option_string snarl_engine_node_shape_pattern_error_message(slop_arena* arena, snarl_types_NodeShape ns);
slop_option_string snarl_engine_shapes_graph_pattern_error_message(slop_arena* arena, snarl_types_ShapesGraph shapes_graph);
snarl_types_ValidatorResult snarl_engine_validate(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_engine_evaluate_simple_predicate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_engine_evaluate_constraint_for_simple_predicate_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_data_graph_IdSet value_set, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);

int64_t snarl_engine_cycle_guard_max_recursion_depth(void) {
    return 400;
}

snarl_engine_CycleGuard snarl_engine_cycle_guard_new(slop_arena* arena) {
    return ((snarl_engine_CycleGuard){.pairs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .depth = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .errors = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_string); slop_map_new_ptr(arena, 0, &_d); })});
}

int64_t snarl_engine_cycle_guard_depth(snarl_engine_CycleGuard guard) {
    __auto_type _mv_321 = ({ void* _ptr = slop_map_get(guard.depth, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_321.has_value) {
        __auto_type d = _mv_321.value;
        return d;
    } else if (!_mv_321.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_engine_cycle_guard_pair_active(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    __auto_type _mv_323 = ({ void* _ptr = slop_map_get(guard.pairs, &(shape_ref)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_323.has_value) {
        __auto_type counts = _mv_323.value;
        __auto_type _mv_325 = ({ void* _ptr = slop_map_get(counts, &(node)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        if (_mv_325.has_value) {
            __auto_type c = _mv_325.value;
            return (c > 0);
        } else if (!_mv_325.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_323.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_engine_cycle_guard_has(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    return (snarl_engine_cycle_guard_pair_active(guard, shape_ref, node) || (snarl_engine_cycle_guard_depth(guard) >= snarl_engine_cycle_guard_max_recursion_depth()));
}

void snarl_engine_cycle_guard_add(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    (void)(({ int64_t _val = (snarl_engine_cycle_guard_depth(guard) + 1); slop_map_put(NULL, guard.depth, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}, &_val, sizeof(_val)); }));
    __auto_type _mv_328 = ({ void* _ptr = slop_map_get(guard.pairs, &(shape_ref)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_328.has_value) {
        __auto_type counts = _mv_328.value;
        __auto_type _mv_330 = ({ void* _ptr = slop_map_get(counts, &(node)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        if (_mv_330.has_value) {
            __auto_type c = _mv_330.value;
            ({ int64_t _val = (c + 1); slop_map_put(NULL, counts, &(node), &_val, sizeof(_val)); });
        } else if (!_mv_330.has_value) {
            ({ int64_t _val = 1; slop_map_put(NULL, counts, &(node), &_val, sizeof(_val)); });
        }
    } else if (!_mv_328.has_value) {
        {
            __auto_type counts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
            ({ int64_t _val = 1; slop_map_put(NULL, counts, &(node), &_val, sizeof(_val)); });
            ({ slop_map* _val = counts; slop_map_put(NULL, guard.pairs, &(shape_ref), &_val, sizeof(_val)); });
        }
    }
}

void snarl_engine_cycle_guard_remove(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    SLOP_PRE((snarl_engine_cycle_guard_pair_active(guard, shape_ref, node)), "(cycle-guard-pair-active guard shape-ref node)");
    (void)(({ int64_t _val = (snarl_engine_cycle_guard_depth(guard) - 1); slop_map_put(NULL, guard.depth, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}, &_val, sizeof(_val)); }));
    __auto_type _mv_337 = ({ void* _ptr = slop_map_get(guard.pairs, &(shape_ref)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_337.has_value) {
        __auto_type counts = _mv_337.value;
        __auto_type _mv_339 = ({ void* _ptr = slop_map_get(counts, &(node)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        if (_mv_339.has_value) {
            __auto_type c = _mv_339.value;
            ({ int64_t _val = (c - 1); slop_map_put(NULL, counts, &(node), &_val, sizeof(_val)); });
        } else if (!_mv_339.has_value) {
        }
    } else if (!_mv_337.has_value) {
    }
}

void snarl_engine_cycle_guard_flag(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    if (snarl_engine_cycle_guard_pair_active(guard, shape_ref, node)) {
        snarl_engine_cycle_guard_flag_recursion(arena, guard, shape_ref, node);
    } else {
        snarl_engine_cycle_guard_flag_depth_budget(arena, guard, shape_ref, node);
    }
}

void snarl_engine_cycle_guard_flag_depth_budget(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    if (!(slop_map_has(guard.errors, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}))) {
        {
            __auto_type shape_label = snarl_types_term_display_label(shape_ref, SLOP_STR("[anonymous shape]"));
            __auto_type node_label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
            __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Shape recursion depth budget (")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, snarl_engine_cycle_guard_max_recursion_depth())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(") exceeded: shape ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (shape_label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" re-entered while resolving node ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (node_label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" -- recursion this deep cannot be proven acyclic without risking a native stack overflow")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ slop_string _val = std_strlib_string_build(arena, parts); slop_map_put(NULL, guard.errors, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}, &_val, sizeof(_val)); }));
        }
    }
}

void snarl_engine_cycle_guard_flag_recursion(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node) {
    if (!(slop_map_has(guard.errors, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}))) {
        {
            __auto_type shape_label = snarl_types_term_display_label(shape_ref, SLOP_STR("[anonymous shape]"));
            __auto_type node_label = snarl_types_term_display_label(node, SLOP_STR("[anonymous node]"));
            __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Shape recursion detected: shape ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (shape_label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" was re-entered for node ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (node_label); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" while still on the current validation path")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ slop_string _val = std_strlib_string_build(arena, parts); slop_map_put(NULL, guard.errors, &(int64_t){snarl_engine_CYCLE_GUARD_SLOT}, &_val, sizeof(_val)); }));
        }
    }
}

uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, node, shape, visited);
    }
}

uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited) {
    {
        __auto_type config = snarl_types_default_validator_config();
        __auto_type results = snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, shape, node, visited, config);
        return (((int64_t)((results).len)) == 0);
    }
}

uint8_t snarl_property_shape_conforms(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_property_shape_conforms_cached(arena, data_graph, shapes_graph, class_index, node, ps);
    }
}

uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps) {
    {
        __auto_type rec_visited = snarl_engine_cycle_guard_new(arena);
        __auto_type empty_siblings = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ps, node, rec_visited, snarl_types_default_validator_config(), empty_siblings);
        return (((int64_t)((results).len)) == 0);
    }
}

uint8_t snarl_engine_property_shape_conforms_with_guard(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps, snarl_engine_CycleGuard visited) {
    {
        __auto_type empty_siblings = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ps, node, visited, snarl_types_default_validator_config(), empty_siblings);
        return (((int64_t)((results).len)) == 0);
    }
}

slop_option_string snarl_engine_constraints_pattern_error_message(slop_arena* arena, slop_rdf_rdf_Term shape_id, slop_list_snarl_types_Constraint constraints) {
    {
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_345 = result;
                if (!_mv_345.has_value) {
                    __auto_type _mv_346 = c;
                    switch (_mv_346.tag) {
                        case snarl_types_Constraint_con_pattern:
                        {
                            __auto_type pat = _mv_346.data.con_pattern;
                            __auto_type _mv_347 = snarl_string_pattern_compile_error(arena, pat);
                            if (_mv_347.has_value) {
                                __auto_type reason = _mv_347.value;
                                {
                                    __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("sh:pattern \"")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (pat); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\" of shape ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_types_term_display_label(shape_id, SLOP_STR("[anonymous shape]"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" does not compile as a regular expression (")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (reason); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(")")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    result = (slop_option_string){.has_value = 1, .value = std_strlib_string_build(arena, parts)};
                                }
                            } else if (!_mv_347.has_value) {
                            }
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                } else if (_mv_345.has_value) {
                    __auto_type _ = _mv_345.value;
                }
            }
        }
        return result;
    }
}

slop_option_string snarl_engine_property_shape_pattern_error_message(slop_arena* arena, snarl_types_PropertyShape ps) {
    if (ps.deactivated) {
        return (slop_option_string){.has_value = false};
    } else {
        return snarl_engine_constraints_pattern_error_message(arena, ps.id, ps.constraints);
    }
}

slop_option_string snarl_engine_node_shape_pattern_error_message(slop_arena* arena, snarl_types_NodeShape ns) {
    if (ns.deactivated) {
        return (slop_option_string){.has_value = false};
    } else {
        {
            __auto_type result = snarl_engine_constraints_pattern_error_message(arena, ns.id, ns.constraints);
            {
                __auto_type _coll = ns.property_shapes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ps = _coll.data[_i];
                    __auto_type _mv_348 = result;
                    if (!_mv_348.has_value) {
                        result = snarl_engine_property_shape_pattern_error_message(arena, ps);
                    } else if (_mv_348.has_value) {
                        __auto_type _ = _mv_348.value;
                    }
                }
            }
            return result;
        }
    }
}

slop_option_string snarl_engine_shapes_graph_pattern_error_message(slop_arena* arena, snarl_types_ShapesGraph shapes_graph) {
    {
        slop_option_string result = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                __auto_type _mv_349 = result;
                if (!_mv_349.has_value) {
                    result = snarl_engine_node_shape_pattern_error_message(arena, ns);
                } else if (_mv_349.has_value) {
                    __auto_type _ = _mv_349.value;
                }
            }
        }
        {
            __auto_type _coll = shapes_graph.property_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps = _coll.data[_i];
                __auto_type _mv_350 = result;
                if (!_mv_350.has_value) {
                    result = snarl_engine_property_shape_pattern_error_message(arena, ps);
                } else if (_mv_350.has_value) {
                    __auto_type _ = _mv_350.value;
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, shapes_graph.shape_map); (slop_list_slop_rdf_rdf_Term){.data = (slop_rdf_rdf_Term*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                __auto_type _mv_351 = result;
                if (!_mv_351.has_value) {
                    __auto_type _mv_353 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(k)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                    if (_mv_353.has_value) {
                        __auto_type ns = _mv_353.value;
                        result = snarl_engine_node_shape_pattern_error_message(arena, ns);
                    } else if (!_mv_353.has_value) {
                    }
                } else if (_mv_351.has_value) {
                    __auto_type _ = _mv_351.value;
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, shapes_graph.property_shape_map); (slop_list_slop_rdf_rdf_Term){.data = (slop_rdf_rdf_Term*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                __auto_type _mv_354 = result;
                if (!_mv_354.has_value) {
                    __auto_type _mv_356 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(k)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                    if (_mv_356.has_value) {
                        __auto_type ps = _mv_356.value;
                        result = snarl_engine_property_shape_pattern_error_message(arena, ps);
                    } else if (!_mv_356.has_value) {
                    }
                } else if (_mv_354.has_value) {
                    __auto_type _ = _mv_354.value;
                }
            }
        }
        return result;
    }
}

snarl_types_ValidatorResult snarl_engine_validate(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        __auto_type target_cache = snarl_target_target_cache_create(arena);
        __auto_type report = snarl_types_make_validation_report(arena);
        int64_t error_count = 0;
        slop_option_string cycle_message = (slop_option_string){.has_value = false};
        __auto_type max_errors = config.max_errors;
        {
            __auto_type _coll = shapes_graph.node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                if (!(ns.deactivated)) {
                    {
                        __auto_type focus_nodes = snarl_target_resolve_targets_cached(arena, data_graph, target_cache, ns);
                        __auto_type visited = snarl_engine_cycle_guard_new(arena);
                        {
                            __auto_type _coll = focus_nodes;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type focus_node = _coll.data[_i];
                                __auto_type _mv_358 = ({ void* _ptr = slop_map_get(visited.errors, &(int64_t){0}); _ptr ? (slop_option_string){ .has_value = true, .value = *(slop_string*)_ptr } : (slop_option_string){ .has_value = false }; });
                                if (_mv_358.has_value) {
                                    __auto_type _ = _mv_358.value;
                                } else if (!_mv_358.has_value) {
                                    {
                                        __auto_type results = snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, ns, focus_node, visited, config);
                                        {
                                            __auto_type _coll = results;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                {
                                                    __auto_type include = ({ __auto_type _mv = r.severity; uint8_t _mr = {0}; int _mm = 0; switch (_mv) { case snarl_types_Severity_severity_violation: { _mr = 1; _mm = 1; break; } case snarl_types_Severity_severity_warning: { _mr = config.include_warnings; _mm = 1; break; } case snarl_types_Severity_severity_info: { _mr = config.include_infos; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; });
                                                    if (include) {
                                                        if ((max_errors == 0) || (error_count < max_errors)) {
                                                            report = snarl_types_report_add_result(arena, report, r);
                                                            __auto_type _mv_359 = r.severity;
                                                            switch (_mv_359) {
                                                                case snarl_types_Severity_severity_violation: {
                                                                    error_count = (error_count + 1);
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
                                }
                            }
                        }
                        __auto_type _mv_360 = cycle_message;
                        if (!_mv_360.has_value) {
                            __auto_type _mv_362 = ({ void* _ptr = slop_map_get(visited.errors, &(int64_t){0}); _ptr ? (slop_option_string){ .has_value = true, .value = *(slop_string*)_ptr } : (slop_option_string){ .has_value = false }; });
                            if (_mv_362.has_value) {
                                __auto_type msg = _mv_362.value;
                                cycle_message = (slop_option_string){.has_value = 1, .value = msg};
                            } else if (!_mv_362.has_value) {
                            }
                        } else if (_mv_360.has_value) {
                            __auto_type _ = _mv_360.value;
                        }
                    }
                }
            }
        }
        __auto_type _mv_363 = cycle_message;
        if (_mv_363.has_value) {
            __auto_type msg = _mv_363.value;
            return ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_error, .data.validate_error = msg });
        } else if (!_mv_363.has_value) {
            return ((snarl_types_ValidatorResult){ .tag = snarl_types_ValidatorResult_validate_success, .data.validate_success = report });
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_node_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, visited, config);
    }
}

slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config) {
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type shape_severity = shape.severity;
        __auto_type shape_message = shape.message;
        __auto_type shape_id = shape.id;
        slop_option_snarl_types_ShaclPath no_path = (slop_option_snarl_types_ShaclPath){.has_value = false};
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                {
                    __auto_type constraint_results = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, focus_node, constraint, no_path, shape_id, shape_severity, shape_message, visited);
                    {
                        __auto_type _coll = constraint_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                __auto_type _mv_364 = constraint;
                if (_mv_364.tag == snarl_types_Constraint_con_closed && _mv_364.data.con_closed.f0 == 1) {
                    __auto_type ignored_paths = _mv_364.data.con_closed.f1;
                    {
                        __auto_type allowed_paths = ((slop_list_snarl_types_ShaclPath){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        __auto_type ign_len = ((int64_t)((ignored_paths).len));
                        {
                            __auto_type _coll = shape.property_shapes;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                ({ __auto_type _lst_p = &(allowed_paths); __auto_type _item = (ps.path); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            int64_t i = 0;
                            while (i < ign_len) {
                                __auto_type _mv_365 = ({ __auto_type _lst = ignored_paths; size_t _idx = (size_t)i; slop_option_snarl_types_ShaclPath _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_365.has_value) {
                                    __auto_type ip = _mv_365.value;
                                    ({ __auto_type _lst_p = &(allowed_paths); __auto_type _item = (ip); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (!_mv_365.has_value) {
                                }
                                i = (i + 1);
                            }
                        }
                        {
                            __auto_type closed_results = snarl_check_closed(arena, data_graph, focus_node, allowed_paths, no_path, shape_id, shape_severity, shape_message);
                            {
                                __auto_type _coll = closed_results;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else {
                }
            }
        }
        {
            __auto_type all_disjoint_qvs = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type all_disjoint_ps_ids = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = shape.property_shapes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ps = _coll.data[_i];
                    if (!(ps.deactivated)) {
                        {
                            __auto_type _coll = ps.constraints;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                __auto_type _mv_366 = c;
                                switch (_mv_366.tag) {
                                    case snarl_types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_366.data.con_qualified_value_shape.f0;
                                        __auto_type disjoint = _mv_366.data.con_qualified_value_shape.f3;
                                        if (disjoint) {
                                            ({ __auto_type _lst_p = &(all_disjoint_qvs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            ({ __auto_type _lst_p = &(all_disjoint_ps_ids); __auto_type _item = (ps.id); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            {
                __auto_type _coll = shape.property_shapes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ps = _coll.data[_i];
                    if (!(ps.deactivated)) {
                        {
                            __auto_type sibling_refs = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            __auto_type ps_id = ps.id;
                            int64_t i = 0;
                            __auto_type n = ((int64_t)((all_disjoint_qvs).len));
                            while (i < n) {
                                __auto_type _mv_367 = ({ __auto_type _lst = all_disjoint_ps_ids; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_367.has_value) {
                                    __auto_type pid = _mv_367.value;
                                    if (!(rdf_term_eq(pid, ps_id))) {
                                        __auto_type _mv_368 = ({ __auto_type _lst = all_disjoint_qvs; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_368.has_value) {
                                            __auto_type ref = _mv_368.value;
                                            ({ __auto_type _lst_p = &(sibling_refs); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_368.has_value) {
                                        }
                                    }
                                } else if (!_mv_367.has_value) {
                                }
                                i = (i + 1);
                            }
                            {
                                __auto_type ps_results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ps, focus_node, visited, config, sibling_refs);
                                {
                                    __auto_type _coll = ps_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
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

slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, visited, config, sibling_qvs_refs);
    }
}

slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type path = shape.path;
        __auto_type _mv_369 = path;
        switch (_mv_369.tag) {
            case snarl_types_ShaclPath_path_predicate:
            {
                __auto_type pred = _mv_369.data.path_predicate;
                _retval = snarl_engine_evaluate_simple_predicate_property_shape_cached(arena, data_graph, shapes_graph, class_index, shape, focus_node, pred, visited, config, sibling_qvs_refs);
                goto _slop_post;
            }
            default: {
                {
                    __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    __auto_type shape_severity = shape.severity;
                    __auto_type shape_message = shape.message;
                    __auto_type shape_id = shape.id;
                    __auto_type path_opt = (slop_option_snarl_types_ShaclPath){.has_value = 1, .value = path};
                    __auto_type value_nodes = snarl_resolve_path(arena, data_graph, focus_node, path);
                    __auto_type value_count = ((int64_t)((value_nodes).len));
                    {
                        __auto_type _coll = shape.constraints;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type constraint = _coll.data[_i];
                            {
                                __auto_type constraint_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited, sibling_qvs_refs);
                                {
                                    __auto_type _coll = constraint_results;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                    _retval = results;
                    goto _slop_post;
                }
            }
        }
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_engine_evaluate_simple_predicate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type shape_severity = shape.severity;
        __auto_type shape_message = shape.message;
        __auto_type shape_id = shape.id;
        __auto_type path = shape.path;
        __auto_type path_opt = (slop_option_snarl_types_ShaclPath){.has_value = 1, .value = path};
        __auto_type value_set = snarl_data_graph_snarl_data_graph_object_set(data_graph, focus_node, pred);
        __auto_type value_count = snarl_data_graph_snarl_data_graph_id_set_size(value_set);
        {
            __auto_type _coll = shape.constraints;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type constraint = _coll.data[_i];
                {
                    __auto_type constraint_results = snarl_engine_evaluate_constraint_for_simple_predicate_cached(arena, data_graph, shapes_graph, class_index, focus_node, pred, value_set, value_count, constraint, path_opt, shape_id, shape_severity, shape_message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = constraint_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        _retval = results;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
    }
}

slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_370 = constraint;
        switch (_mv_370.tag) {
            case snarl_types_Constraint_con_class:
            {
                __auto_type required_class = _mv_370.data.con_class;
                __auto_type _mv_371 = snarl_value_type_check_class_with_index(arena, data_graph, class_index, focus_node, value_node, required_class, path, shape_id, severity, message);
                if (_mv_371.has_value) {
                    __auto_type r = _mv_371.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_371.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_datatype:
            {
                __auto_type required_dt = _mv_370.data.con_datatype;
                __auto_type _mv_372 = snarl_check_datatype(arena, focus_node, value_node, required_dt, path, shape_id, severity, message);
                if (_mv_372.has_value) {
                    __auto_type r = _mv_372.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_372.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_node_kind:
            {
                __auto_type required_kind = _mv_370.data.con_node_kind;
                __auto_type _mv_373 = snarl_check_node_kind(arena, focus_node, value_node, required_kind, path, shape_id, severity, message);
                if (_mv_373.has_value) {
                    __auto_type r = _mv_373.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_373.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_min_count:
            {
                __auto_type _ = _mv_370.data.con_min_count;
                break;
            }
            case snarl_types_Constraint_con_max_count:
            {
                __auto_type _ = _mv_370.data.con_max_count;
                break;
            }
            case snarl_types_Constraint_con_min_inclusive:
            {
                __auto_type limit = _mv_370.data.con_min_inclusive;
                __auto_type _mv_374 = snarl_check_min_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_374.has_value) {
                    __auto_type r = _mv_374.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_374.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_max_inclusive:
            {
                __auto_type limit = _mv_370.data.con_max_inclusive;
                __auto_type _mv_375 = snarl_check_max_inclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_375.has_value) {
                    __auto_type r = _mv_375.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_375.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_min_exclusive:
            {
                __auto_type limit = _mv_370.data.con_min_exclusive;
                __auto_type _mv_376 = snarl_check_min_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_376.has_value) {
                    __auto_type r = _mv_376.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_376.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_max_exclusive:
            {
                __auto_type limit = _mv_370.data.con_max_exclusive;
                __auto_type _mv_377 = snarl_check_max_exclusive(arena, focus_node, value_node, limit, path, shape_id, severity, message);
                if (_mv_377.has_value) {
                    __auto_type r = _mv_377.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_377.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_min_length:
            {
                __auto_type min_len = _mv_370.data.con_min_length;
                __auto_type _mv_378 = snarl_check_min_length(arena, focus_node, value_node, min_len, path, shape_id, severity, message);
                if (_mv_378.has_value) {
                    __auto_type r = _mv_378.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_378.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_max_length:
            {
                __auto_type max_len = _mv_370.data.con_max_length;
                __auto_type _mv_379 = snarl_check_max_length(arena, focus_node, value_node, max_len, path, shape_id, severity, message);
                if (_mv_379.has_value) {
                    __auto_type r = _mv_379.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_379.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_pattern:
            {
                __auto_type pat = _mv_370.data.con_pattern;
                __auto_type _mv_380 = snarl_check_pattern(arena, focus_node, value_node, pat, path, shape_id, severity, message);
                if (_mv_380.has_value) {
                    __auto_type r = _mv_380.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_380.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_language_in:
            {
                __auto_type allowed_langs = _mv_370.data.con_language_in;
                __auto_type _mv_381 = snarl_check_language_in(arena, focus_node, value_node, allowed_langs, path, shape_id, severity, message);
                if (_mv_381.has_value) {
                    __auto_type r = _mv_381.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_381.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_unique_lang:
            {
                __auto_type _ = _mv_370.data.con_unique_lang;
                break;
            }
            case snarl_types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_370.data.con_equals;
                {
                    __auto_type single_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = eq_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_370.data.con_disjoint;
                {
                    __auto_type single_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = dj_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_370.data.con_less_than;
                {
                    __auto_type single_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = lt_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_370.data.con_less_than_or_equals;
                {
                    __auto_type single_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, single_list, other_path, path, shape_id, severity, message);
                        {
                            __auto_type _coll = le_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_370.data.con_has_value;
                {
                    __auto_type single_list = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(single_list); __auto_type _item = (value_node); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    __auto_type _mv_382 = snarl_check_has_value(arena, focus_node, single_list, required_value, path, shape_id, severity, message);
                    if (_mv_382.has_value) {
                        __auto_type r = _mv_382.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_382.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_in:
            {
                __auto_type allowed_values = _mv_370.data.con_in;
                __auto_type _mv_383 = snarl_check_in(arena, focus_node, value_node, allowed_values, path, shape_id, severity, message);
                if (_mv_383.has_value) {
                    __auto_type r = _mv_383.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_383.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_closed:
            {
                break;
            }
            case snarl_types_Constraint_con_not:
            {
                __auto_type shape_ref = _mv_370.data.con_not;
                {
                    __auto_type conforms = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(shape_ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_ps = _mv.value; ((snarl_engine_cycle_guard_has(visited, shape_ref, value_node)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, shape_ref, value_node); 1; }) : ({ snarl_engine_cycle_guard_add(arena, visited, shape_ref, value_node); ({ __auto_type r = snarl_engine_property_shape_conforms_with_guard(arena, data_graph, shapes_graph, class_index, value_node, ref_ps, visited); snarl_engine_cycle_guard_remove(arena, visited, shape_ref, value_node); r; }); })); }) : (({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; ((snarl_engine_cycle_guard_has(visited, shape_ref, value_node)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, shape_ref, value_node); 1; }) : ({ snarl_engine_cycle_guard_add(arena, visited, shape_ref, value_node); ({ __auto_type r = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, visited); snarl_engine_cycle_guard_remove(arena, visited, shape_ref, value_node); r; }); })); }) : (0); })); });
                    __auto_type _mv_386 = snarl_check_not(arena, focus_node, conforms, path, shape_id, severity, message);
                    if (_mv_386.has_value) {
                        __auto_type r = _mv_386.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_386.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_and:
            {
                __auto_type shape_refs = _mv_370.data.con_and;
                {
                    uint8_t all_pass = 1;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_388 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                            if (_mv_388.has_value) {
                                __auto_type ref_ps = _mv_388.value;
                                if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                    snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                    all_pass = 0;
                                } else {
                                    snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                    {
                                        __auto_type ok = snarl_engine_property_shape_conforms_with_guard(arena, data_graph, shapes_graph, class_index, value_node, ref_ps, visited);
                                        snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                        if (!(ok)) {
                                            all_pass = 0;
                                        }
                                    }
                                }
                            } else if (!_mv_388.has_value) {
                                __auto_type _mv_390 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                if (_mv_390.has_value) {
                                    __auto_type ref_shape = _mv_390.value;
                                    if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                        snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                        all_pass = 0;
                                    } else {
                                        snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                        {
                                            __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, visited);
                                            snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                            if (!(ok)) {
                                                all_pass = 0;
                                            }
                                        }
                                    }
                                } else if (!_mv_390.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_391 = snarl_check_and(arena, focus_node, all_pass, path, shape_id, severity, message);
                    if (_mv_391.has_value) {
                        __auto_type r = _mv_391.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_391.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_or:
            {
                __auto_type shape_refs = _mv_370.data.con_or;
                {
                    uint8_t any_pass = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_393 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                            if (_mv_393.has_value) {
                                __auto_type ref_ps = _mv_393.value;
                                if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                    snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                } else {
                                    snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                    {
                                        __auto_type ok = snarl_engine_property_shape_conforms_with_guard(arena, data_graph, shapes_graph, class_index, value_node, ref_ps, visited);
                                        snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                        if (ok) {
                                            any_pass = 1;
                                        }
                                    }
                                }
                            } else if (!_mv_393.has_value) {
                                __auto_type _mv_395 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                if (_mv_395.has_value) {
                                    __auto_type ref_shape = _mv_395.value;
                                    if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                        snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                    } else {
                                        snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                        {
                                            __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, visited);
                                            snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                            if (ok) {
                                                any_pass = 1;
                                            }
                                        }
                                    }
                                } else if (!_mv_395.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_396 = snarl_check_or(arena, focus_node, any_pass, path, shape_id, severity, message);
                    if (_mv_396.has_value) {
                        __auto_type r = _mv_396.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_396.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_xone:
            {
                __auto_type shape_refs = _mv_370.data.con_xone;
                {
                    int64_t pass_count = 0;
                    {
                        __auto_type _coll = shape_refs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ref = _coll.data[_i];
                            __auto_type _mv_398 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                            if (_mv_398.has_value) {
                                __auto_type ref_ps = _mv_398.value;
                                if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                    snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                } else {
                                    snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                    {
                                        __auto_type ok = snarl_engine_property_shape_conforms_with_guard(arena, data_graph, shapes_graph, class_index, value_node, ref_ps, visited);
                                        snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                        if (ok) {
                                            pass_count = (pass_count + 1);
                                        }
                                    }
                                }
                            } else if (!_mv_398.has_value) {
                                __auto_type _mv_400 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                if (_mv_400.has_value) {
                                    __auto_type ref_shape = _mv_400.value;
                                    if (snarl_engine_cycle_guard_has(visited, ref, value_node)) {
                                        snarl_engine_cycle_guard_flag(arena, visited, ref, value_node);
                                    } else {
                                        snarl_engine_cycle_guard_add(arena, visited, ref, value_node);
                                        {
                                            __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, visited);
                                            snarl_engine_cycle_guard_remove(arena, visited, ref, value_node);
                                            if (ok) {
                                                pass_count = (pass_count + 1);
                                            }
                                        }
                                    }
                                } else if (!_mv_400.has_value) {
                                }
                            }
                        }
                    }
                    __auto_type _mv_401 = snarl_check_xone(arena, focus_node, pass_count, path, shape_id, severity, message);
                    if (_mv_401.has_value) {
                        __auto_type r = _mv_401.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_401.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_node:
            {
                __auto_type shape_ref = _mv_370.data.con_node;
                {
                    __auto_type value_conforms = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(shape_ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_ps = _mv.value; ((snarl_engine_cycle_guard_has(visited, shape_ref, value_node)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, shape_ref, value_node); 0; }) : ({ snarl_engine_cycle_guard_add(arena, visited, shape_ref, value_node); ({ __auto_type ok = snarl_engine_property_shape_conforms_with_guard(arena, data_graph, shapes_graph, class_index, value_node, ref_ps, visited); snarl_engine_cycle_guard_remove(arena, visited, shape_ref, value_node); ok; }); })); }) : (({ __auto_type _mv = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; }); _mv.has_value ? ({ __auto_type ref_shape = _mv.value; ((snarl_engine_cycle_guard_has(visited, shape_ref, value_node)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, shape_ref, value_node); 0; }) : ({ snarl_engine_cycle_guard_add(arena, visited, shape_ref, value_node); ({ __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, value_node, ref_shape, visited); snarl_engine_cycle_guard_remove(arena, visited, shape_ref, value_node); ok; }); })); }) : (1); })); });
                    __auto_type _mv_404 = snarl_check_node(arena, focus_node, value_node, value_conforms, path, shape_id, severity, message);
                    if (_mv_404.has_value) {
                        __auto_type r = _mv_404.value;
                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_404.has_value) {
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_property:
            {
                __auto_type _ = _mv_370.data.con_property;
                break;
            }
            case snarl_types_Constraint_con_qualified_value_shape:
            {
                break;
            }
        }
        _retval = results;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    {
        __auto_type class_index = snarl_target_build_class_index(arena, data_graph, shapes_graph);
        return snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
    }
}

slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_405 = constraint;
        switch (_mv_405.tag) {
            case snarl_types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_405.data.con_min_count;
                __auto_type _mv_406 = snarl_check_min_count(arena, focus_node, SLOP_RANGE(int64_t, value_count, 1, 0, 0, 0, "(Int 0 ..) at engine.slop:928:52"), min_c, path, shape_id, severity, message);
                if (_mv_406.has_value) {
                    __auto_type r = _mv_406.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_406.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_405.data.con_max_count;
                __auto_type _mv_407 = snarl_check_max_count(arena, focus_node, SLOP_RANGE(int64_t, value_count, 1, 0, 0, 0, "(Int 0 ..) at engine.slop:932:52"), max_c, path, shape_id, severity, message);
                if (_mv_407.has_value) {
                    __auto_type r = _mv_407.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_407.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_405.data.con_unique_lang;
                if (b) {
                    {
                        __auto_type ul_results = snarl_check_unique_lang(arena, focus_node, value_nodes, path, shape_id, severity, message);
                        {
                            __auto_type _coll = ul_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_405.data.con_has_value;
                __auto_type _mv_408 = snarl_check_has_value(arena, focus_node, value_nodes, required_value, path, shape_id, severity, message);
                if (_mv_408.has_value) {
                    __auto_type r = _mv_408.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_408.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_closed:
            {
                break;
            }
            case snarl_types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_405.data.con_equals;
                {
                    __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = eq_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_405.data.con_disjoint;
                {
                    __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = dj_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_405.data.con_less_than;
                {
                    __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = lt_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_405.data.con_less_than_or_equals;
                {
                    __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = le_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_qualified_value_shape:
            {
                __auto_type shape_ref = _mv_405.data.con_qualified_value_shape.f0;
                __auto_type q_min = _mv_405.data.con_qualified_value_shape.f1;
                __auto_type q_max = _mv_405.data.con_qualified_value_shape.f2;
                __auto_type disjoint = _mv_405.data.con_qualified_value_shape.f3;
                {
                    int64_t conforming_count = 0;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            __auto_type _mv_410 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(shape_ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                            if (_mv_410.has_value) {
                                __auto_type ref_shape = _mv_410.value;
                                {
                                    __auto_type vn_conforms = ((snarl_engine_cycle_guard_has(visited, shape_ref, vn)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, shape_ref, vn); 0; }) : ({ snarl_engine_cycle_guard_add(arena, visited, shape_ref, vn); ({ __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, vn, ref_shape, visited); snarl_engine_cycle_guard_remove(arena, visited, shape_ref, vn); ok; }); }));
                                    if (vn_conforms) {
                                        if (disjoint && (((int64_t)((sibling_qvs_refs).len)) > 0)) {
                                            {
                                                uint8_t conforms_to_sibling = 0;
                                                {
                                                    __auto_type _coll = sibling_qvs_refs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type sib_ref = _coll.data[_i];
                                                        __auto_type _mv_412 = ({ void* _ptr = slop_map_get(shapes_graph.shape_map, &(sib_ref)); _ptr ? (slop_option_snarl_types_NodeShape){ .has_value = true, .value = *(snarl_types_NodeShape*)_ptr } : (slop_option_snarl_types_NodeShape){ .has_value = false }; });
                                                        if (_mv_412.has_value) {
                                                            __auto_type sib_shape = _mv_412.value;
                                                            {
                                                                __auto_type sib_ok = ((snarl_engine_cycle_guard_has(visited, sib_ref, vn)) ? ({ snarl_engine_cycle_guard_flag(arena, visited, sib_ref, vn); 0; }) : ({ snarl_engine_cycle_guard_add(arena, visited, sib_ref, vn); ({ __auto_type ok = snarl_evaluate_shape_against_node_cached(arena, data_graph, shapes_graph, class_index, vn, sib_shape, visited); snarl_engine_cycle_guard_remove(arena, visited, sib_ref, vn); ok; }); }));
                                                                if (sib_ok) {
                                                                    conforms_to_sibling = 1;
                                                                }
                                                            }
                                                        } else if (!_mv_412.has_value) {
                                                        }
                                                    }
                                                }
                                                if (!(conforms_to_sibling)) {
                                                    conforming_count = (conforming_count + 1);
                                                }
                                            }
                                        } else {
                                            conforming_count = (conforming_count + 1);
                                        }
                                    }
                                }
                            } else if (!_mv_410.has_value) {
                            }
                        }
                    }
                    {
                        __auto_type qvs_results = snarl_check_qualified_value_shape(arena, focus_node, conforming_count, q_min, q_max, path, shape_id, severity, message);
                        {
                            __auto_type _coll = qvs_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_property:
            {
                __auto_type ps_ref = _mv_405.data.con_property;
                __auto_type _mv_414 = ({ void* _ptr = slop_map_get(shapes_graph.property_shape_map, &(ps_ref)); _ptr ? (slop_option_snarl_types_PropertyShape){ .has_value = true, .value = *(snarl_types_PropertyShape*)_ptr } : (slop_option_snarl_types_PropertyShape){ .has_value = false }; });
                if (_mv_414.has_value) {
                    __auto_type ref_ps = _mv_414.value;
                    {
                        __auto_type _coll = value_nodes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type vn = _coll.data[_i];
                            {
                                __auto_type empty_siblings = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                if (snarl_engine_cycle_guard_has(visited, ps_ref, vn)) {
                                    snarl_engine_cycle_guard_flag(arena, visited, ps_ref, vn);
                                } else {
                                    snarl_engine_cycle_guard_add(arena, visited, ps_ref, vn);
                                    {
                                        __auto_type ps_results = snarl_evaluate_property_shape_cached(arena, data_graph, shapes_graph, class_index, ref_ps, vn, visited, snarl_types_default_validator_config(), empty_siblings);
                                        snarl_engine_cycle_guard_remove(arena, visited, ps_ref, vn);
                                        {
                                            __auto_type _coll = ps_results;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_414.has_value) {
                }
                break;
            }
            default: {
                {
                    __auto_type _coll = value_nodes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type value_node = _coll.data[_i];
                        {
                            __auto_type vr = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
                            {
                                __auto_type _coll = vr;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        _retval = results;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_snarl_types_ValidationResult snarl_engine_evaluate_constraint_for_simple_predicate_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_data_graph_IdSet value_set, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs) {
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_415 = constraint;
        switch (_mv_415.tag) {
            case snarl_types_Constraint_con_min_count:
            {
                __auto_type min_c = _mv_415.data.con_min_count;
                __auto_type _mv_416 = snarl_check_min_count(arena, focus_node, SLOP_RANGE(int64_t, value_count, 1, 0, 0, 0, "(Int 0 ..) at engine.slop:1035:52"), min_c, path, shape_id, severity, message);
                if (_mv_416.has_value) {
                    __auto_type r = _mv_416.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_416.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_max_count:
            {
                __auto_type max_c = _mv_415.data.con_max_count;
                __auto_type _mv_417 = snarl_check_max_count(arena, focus_node, SLOP_RANGE(int64_t, value_count, 1, 0, 0, 0, "(Int 0 ..) at engine.slop:1039:52"), max_c, path, shape_id, severity, message);
                if (_mv_417.has_value) {
                    __auto_type r = _mv_417.value;
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_417.has_value) {
                }
                break;
            }
            case snarl_types_Constraint_con_has_value:
            {
                __auto_type required_value = _mv_415.data.con_has_value;
                if (!(snarl_data_graph_snarl_data_graph_has_object(data_graph, focus_node, pred, required_value))) {
                    ({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_HAS_VALUE, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case snarl_types_Constraint_con_closed:
            {
                break;
            }
            case snarl_types_Constraint_con_equals:
            {
                __auto_type other_path = _mv_415.data.con_equals;
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type eq_results = snarl_check_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = eq_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_disjoint:
            {
                __auto_type other_path = _mv_415.data.con_disjoint;
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type dj_results = snarl_check_disjoint(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = dj_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than:
            {
                __auto_type other_path = _mv_415.data.con_less_than;
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type lt_results = snarl_check_less_than(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = lt_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_less_than_or_equals:
            {
                __auto_type other_path = _mv_415.data.con_less_than_or_equals;
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type le_results = snarl_check_less_than_or_equals(arena, data_graph, focus_node, value_nodes, other_path, path, shape_id, severity, message);
                    {
                        __auto_type _coll = le_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_unique_lang:
            {
                __auto_type b = _mv_415.data.con_unique_lang;
                if (b) {
                    {
                        __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                        __auto_type ul_results = snarl_check_unique_lang(arena, focus_node, value_nodes, path, shape_id, severity, message);
                        {
                            __auto_type _coll = ul_results;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type r = _coll.data[_i];
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_qualified_value_shape:
            {
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type qvs_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = qvs_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case snarl_types_Constraint_con_property:
            {
                __auto_type _ = _mv_415.data.con_property;
                {
                    __auto_type value_nodes = snarl_data_graph_snarl_data_graph_id_set_to_list(arena, data_graph, value_set);
                    __auto_type property_results = snarl_evaluate_constraint_for_property_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_nodes, value_count, constraint, path, shape_id, severity, message, visited, sibling_qvs_refs);
                    {
                        __auto_type _coll = property_results;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            default: {
                {
                    slop_map* _coll = (slop_map*)value_set;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t value_id = *(int64_t*)slop_map_key_at(_coll, _i);
                            {
                                __auto_type value_node = snarl_data_graph_term_of(data_graph, value_id);
                                __auto_type vr = snarl_evaluate_constraint_cached(arena, data_graph, shapes_graph, class_index, focus_node, value_node, constraint, path, shape_id, severity, message, visited);
                                {
                                    __auto_type _coll = vr;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(results); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        _retval = results;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

