#include "../runtime/slop_runtime.h"
#include "slop_data_graph.h"

data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena);
index_TermSet data_graph_make_term_set(slop_arena* arena, rdf_Term value);
void data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, rdf_Term first, rdf_Term second, rdf_Term value);
void data_graph_add_to_flat_set(slop_arena* arena, slop_map* outer, rdf_Term key, rdf_Term value);
uint8_t snarl_data_graph_contains(data_graph_SnarlDataGraph g, rdf_Triple t);
slop_option_index_TermSet data_graph_snarl_data_graph_object_set(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
int64_t data_graph_snarl_data_graph_term_set_size(index_TermSet terms);
slop_list_rdf_Term data_graph_snarl_data_graph_term_set_to_list(slop_arena* arena, index_TermSet terms);
uint8_t data_graph_snarl_data_graph_has_object(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred, rdf_Term obj);
uint8_t data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, rdf_Term subj, rdf_Term pred, rdf_Term obj);
data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Triple t);
int64_t snarl_data_graph_size(data_graph_SnarlDataGraph g);
slop_list_rdf_Term snarl_data_graph_objects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_subjects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred, rdf_Term obj);
slop_list_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
slop_list_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, data_graph_SnarlDataGraph g);
data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, index_IndexedGraph g);

data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena) {
    return ((data_graph_SnarlDataGraph){.triples = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 }), .index = ((data_graph_SnarlDataIndex){.sp = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .po = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .p_subjects = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .p_objects = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term)}), .size = 0});
}

index_TermSet data_graph_make_term_set(slop_arena* arena, rdf_Term value) {
    {
        __auto_type values = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        ({ uint8_t _dummy = 1; slop_map_put(arena, values, &(value), &_dummy); });
        return values;
    }
}

void data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, rdf_Term first, rdf_Term second, rdf_Term value) {
    __auto_type _mv_55 = ({ void* _ptr = slop_map_get(outer, &(first)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_55.has_value) {
        __auto_type inner = _mv_55.value;
        __auto_type _mv_56 = ({ void* _ptr = slop_map_get(inner, &(second)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_56.has_value) {
            __auto_type values = _mv_56.value;
            ({ uint8_t _dummy = 1; slop_map_put(arena, values, &(value), &_dummy); });
        } else if (!_mv_56.has_value) {
            ({ __auto_type _val = data_graph_make_term_set(arena, value); void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, inner, &(second), _vptr); });
        }
    } else if (!_mv_55.has_value) {
        {
            __auto_type inner_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
            ({ __auto_type _val = data_graph_make_term_set(arena, value); void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, inner_map, &(second), _vptr); });
            ({ __auto_type _val = inner_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, outer, &(first), _vptr); });
        }
    }
}

void data_graph_add_to_flat_set(slop_arena* arena, slop_map* outer, rdf_Term key, rdf_Term value) {
    __auto_type _mv_57 = ({ void* _ptr = slop_map_get(outer, &(key)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_57.has_value) {
        __auto_type values = _mv_57.value;
        ({ uint8_t _dummy = 1; slop_map_put(arena, values, &(value), &_dummy); });
    } else if (!_mv_57.has_value) {
        ({ __auto_type _val = data_graph_make_term_set(arena, value); void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, outer, &(key), _vptr); });
    }
}

uint8_t snarl_data_graph_contains(data_graph_SnarlDataGraph g, rdf_Triple t) {
    {
        __auto_type s = rdf_triple_subject(t);
        __auto_type p = rdf_triple_predicate(t);
        __auto_type o = rdf_triple_object(t);
        __auto_type _mv_58 = ({ void* _ptr = slop_map_get(g.index.sp, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_58.has_value) {
            __auto_type pred_map = _mv_58.value;
            __auto_type _mv_59 = ({ void* _ptr = slop_map_get(pred_map, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_59.has_value) {
                __auto_type objs = _mv_59.value;
                return (slop_map_get(objs, &(o)) != NULL);
            } else if (!_mv_59.has_value) {
                return 0;
            }
        } else if (!_mv_58.has_value) {
            return 0;
        }
    }
}

slop_option_index_TermSet data_graph_snarl_data_graph_object_set(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred) {
    __auto_type _mv_60 = ({ void* _ptr = slop_map_get(g.index.sp, &(subj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_60.has_value) {
        __auto_type pred_map = _mv_60.value;
        __auto_type _mv_61 = ({ void* _ptr = slop_map_get(pred_map, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_61.has_value) {
            __auto_type objs = _mv_61.value;
            return (slop_option_index_TermSet){.has_value = 1, .value = objs};
        } else if (!_mv_61.has_value) {
            return (slop_option_index_TermSet){.has_value = false};
        }
    } else if (!_mv_60.has_value) {
        return (slop_option_index_TermSet){.has_value = false};
    }
}

int64_t data_graph_snarl_data_graph_term_set_size(index_TermSet terms) {
    {
        int64_t n = 0;
        {
            slop_map* _coll = (slop_map*)terms;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    rdf_Term _ = *(rdf_Term*)_coll->entries[_i].key;
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

slop_list_rdf_Term data_graph_snarl_data_graph_term_set_to_list(slop_arena* arena, index_TermSet terms) {
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        {
            slop_map* _coll = (slop_map*)terms;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    rdf_Term t = *(rdf_Term*)_coll->entries[_i].key;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return result;
    }
}

uint8_t data_graph_snarl_data_graph_has_object(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred, rdf_Term obj) {
    __auto_type _mv_62 = data_graph_snarl_data_graph_object_set(g, subj, pred);
    if (_mv_62.has_value) {
        __auto_type objs = _mv_62.value;
        return (slop_map_get(objs, &(obj)) != NULL);
    } else if (!_mv_62.has_value) {
        return 0;
    }
}

uint8_t data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, rdf_Term subj, rdf_Term pred, rdf_Term obj) {
    __auto_type _mv_63 = ({ void* _ptr = slop_map_get(outer, &(subj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_63.has_value) {
        __auto_type pred_map = _mv_63.value;
        __auto_type _mv_64 = ({ void* _ptr = slop_map_get(pred_map, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_64.has_value) {
            __auto_type objs = _mv_64.value;
            if (slop_map_get(objs, &(obj)) != NULL) {
                return 0;
            } else {
                ({ uint8_t _dummy = 1; slop_map_put(arena, objs, &(obj), &_dummy); });
                return 1;
            }
        } else if (!_mv_64.has_value) {
            ({ __auto_type _val = data_graph_make_term_set(arena, obj); void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pred_map, &(pred), _vptr); });
            return 1;
        }
    } else if (!_mv_63.has_value) {
        {
            __auto_type pred_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
            ({ __auto_type _val = data_graph_make_term_set(arena, obj); void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pred_map, &(pred), _vptr); });
            ({ __auto_type _val = pred_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, outer, &(subj), _vptr); });
            return 1;
        }
    }
}

data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Triple t) {
    {
        __auto_type s = rdf_triple_subject(t);
        __auto_type p = rdf_triple_predicate(t);
        __auto_type o = rdf_triple_object(t);
        if (data_graph_add_to_sp_index_if_new(arena, g.index.sp, s, p, o)) {
            ({ __auto_type _lst_p = &(g.triples); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            data_graph_add_to_nested_set(arena, g.index.po, p, o, s);
            data_graph_add_to_flat_set(arena, g.index.p_subjects, p, s);
            data_graph_add_to_flat_set(arena, g.index.p_objects, p, o);
            return ((data_graph_SnarlDataGraph){.triples = g.triples, .index = g.index, .size = (g.size + 1)});
        } else {
            return g;
        }
    }
}

int64_t snarl_data_graph_size(data_graph_SnarlDataGraph g) {
    return g.size;
}

slop_list_rdf_Term snarl_data_graph_objects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred) {
    __auto_type _mv_65 = data_graph_snarl_data_graph_object_set(g, subj, pred);
    if (_mv_65.has_value) {
        __auto_type objs = _mv_65.value;
        return data_graph_snarl_data_graph_term_set_to_list(arena, objs);
    } else if (!_mv_65.has_value) {
        return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
    }
}

slop_list_rdf_Term snarl_data_graph_subjects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred, rdf_Term obj) {
    __auto_type _mv_66 = ({ void* _ptr = slop_map_get(g.index.po, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_66.has_value) {
        __auto_type obj_map = _mv_66.value;
        __auto_type _mv_67 = ({ void* _ptr = slop_map_get(obj_map, &(obj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_67.has_value) {
            __auto_type subjects = _mv_67.value;
            return data_graph_snarl_data_graph_term_set_to_list(arena, subjects);
        } else if (!_mv_67.has_value) {
            return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        }
    } else if (!_mv_66.has_value) {
        return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
    }
}

slop_list_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred) {
    __auto_type _mv_68 = ({ void* _ptr = slop_map_get(g.index.p_subjects, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_68.has_value) {
        __auto_type subjects = _mv_68.value;
        return data_graph_snarl_data_graph_term_set_to_list(arena, subjects);
    } else if (!_mv_68.has_value) {
        return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
    }
}

slop_list_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred) {
    __auto_type _mv_69 = ({ void* _ptr = slop_map_get(g.index.p_objects, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_69.has_value) {
        __auto_type objects = _mv_69.value;
        return data_graph_snarl_data_graph_term_set_to_list(arena, objects);
    } else if (!_mv_69.has_value) {
        return ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
    }
}

slop_list_rdf_Term data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj) {
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type _mv_70 = ({ void* _ptr = slop_map_get(g.index.sp, &(subj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_70.has_value) {
            __auto_type pred_map = _mv_70.value;
            {
                slop_map* _coll = (slop_map*)pred_map;
                for (size_t _i = 0; _i < _coll->cap; _i++) {
                    if (_coll->entries[_i].occupied) {
                        rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                        index_TermSet _ = *(index_TermSet*)_coll->entries[_i].value;
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        } else if (!_mv_70.has_value) {
        }
        return result;
    }
}

slop_list_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj) {
    {
        __auto_type result = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        __auto_type _mv_71 = ({ void* _ptr = slop_map_get(g.index.sp, &(subj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_71.has_value) {
            __auto_type pred_map = _mv_71.value;
            {
                slop_map* _coll = (slop_map*)pred_map;
                for (size_t _i = 0; _i < _coll->cap; _i++) {
                    if (_coll->entries[_i].occupied) {
                        rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                        index_TermSet objs = *(index_TermSet*)_coll->entries[_i].value;
                        {
                            slop_map* _coll = (slop_map*)objs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (rdf_make_triple(arena, subj, p, o)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        } else if (!_mv_71.has_value) {
        }
        return result;
    }
}

index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, data_graph_SnarlDataGraph g) {
    {
        __auto_type out = rdf_indexed_graph_create(arena);
        {
            __auto_type _coll = g.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                out = rdf_indexed_graph_add(arena, out, t);
            }
        }
        return out;
    }
}

data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, index_IndexedGraph g) {
    {
        __auto_type out = snarl_data_graph_create(arena);
        {
            __auto_type _coll = g.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                out = snarl_data_graph_add(arena, out, t);
            }
        }
        return out;
    }
}

