#include "../runtime/slop_runtime.h"
#include "slop_data_graph.h"

data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena);
slop_string data_graph_copy_string(slop_arena* arena, slop_string s);
slop_option_string data_graph_copy_option_string(slop_arena* arena, slop_option_string s);
rdf_Term data_graph_copy_term(slop_arena* arena, rdf_Term t);
int64_t data_graph_intern_term(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term t);
slop_option_int data_graph_lookup_term(data_graph_SnarlDataGraph g, rdf_Term t);
rdf_Term snarl_data_graph_term_of(data_graph_SnarlDataGraph g, int64_t id);
slop_list_rdf_Term data_graph_ids_to_terms(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSet ids);
data_graph_IdSet data_graph_make_id_set(slop_arena* arena, int64_t value);
void data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, int64_t first, int64_t second, int64_t value);
void data_graph_add_to_flat_set(slop_arena* arena, data_graph_IdSetMap outer, int64_t key, int64_t value);
uint8_t data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, int64_t subj, int64_t pred, int64_t obj);
data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Triple t);
int64_t snarl_data_graph_size(data_graph_SnarlDataGraph g);
data_graph_IdSet data_graph_object_id_set(data_graph_SnarlDataGraph g, int64_t subj, int64_t pred);
data_graph_IdSet data_graph_snarl_data_graph_object_set(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
int64_t data_graph_snarl_data_graph_id_set_size(slop_map* ids);
slop_list_rdf_Term data_graph_snarl_data_graph_id_set_to_list(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSet ids);
uint8_t data_graph_snarl_data_graph_has_object(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred, rdf_Term obj);
uint8_t snarl_data_graph_contains(data_graph_SnarlDataGraph g, rdf_Triple t);
slop_list_rdf_Term snarl_data_graph_objects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_subjects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred, rdf_Term obj);
slop_list_rdf_Term data_graph_flat_index_terms(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSetMap index, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
slop_list_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, data_graph_SnarlDataGraph g);
data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, index_IndexedGraph g);

data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena) {
    data_graph_SnarlDataGraph _retval = {0};
    _retval = ((data_graph_SnarlDataGraph){.ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_Term, slop_hash_rdf_Term, slop_eq_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .terms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, rdf_Term); slop_map_new_ptr(arena, 0, &_d); }), .index = ((data_graph_SnarlDataIndex){.sp = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .po = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .p_subjects = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .p_objects = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); })}), .no_ids = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); }), .size = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.size == 0)), "(== (. $result size) 0)");
    return _retval;
}

slop_string data_graph_copy_string(slop_arena* arena, slop_string s) {
    slop_string _retval = {0};
    _retval = string_concat(arena, s, SLOP_STR(""));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((string_eq(_retval, s)), "(string-eq $result s)");
    return _retval;
}

slop_option_string data_graph_copy_option_string(slop_arena* arena, slop_option_string s) {
    __auto_type _mv_113 = s;
    if (_mv_113.has_value) {
        __auto_type v = _mv_113.value;
        return (slop_option_string){.has_value = 1, .value = data_graph_copy_string(arena, v)};
    } else if (!_mv_113.has_value) {
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

rdf_Term data_graph_copy_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_114 = t;
    switch (_mv_114.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_114.data.term_iri;
            return ((rdf_Term){ .tag = rdf_Term_term_iri, .data.term_iri = ((rdf_IRI){.value = data_graph_copy_string(arena, i.value)}) });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_114.data.term_blank;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_114.data.term_literal;
            return rdf_make_literal(arena, data_graph_copy_string(arena, l.value), data_graph_copy_option_string(arena, l.datatype), data_graph_copy_option_string(arena, l.lang));
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_114.data.term_triple;
            {
                __auto_type inner = (*tt);
                return rdf_make_triple_term(arena, rdf_make_triple(arena, data_graph_copy_term(arena, rdf_triple_subject(inner)), data_graph_copy_term(arena, rdf_triple_predicate(inner)), data_graph_copy_term(arena, rdf_triple_object(inner))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

int64_t data_graph_intern_term(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term t) {
    int64_t _retval = {0};
    __auto_type _mv_116 = ({ void* _ptr = slop_map_get(g.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_116.has_value) {
        __auto_type id = _mv_116.value;
        _retval = id;
        goto _slop_post;
    } else if (!_mv_116.has_value) {
        {
            __auto_type id = ((int64_t)(g.terms)->len);
            __auto_type owned = data_graph_copy_term(arena, t);
            ({ int64_t _val = id; slop_map_put(NULL, g.ids, &(owned), &_val, sizeof(_val)); });
            ({ rdf_Term _val = owned; slop_map_put(NULL, g.terms, &(int64_t){id}, &_val, sizeof(_val)); });
            _retval = id;
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

slop_option_int data_graph_lookup_term(data_graph_SnarlDataGraph g, rdf_Term t) {
    return ({ void* _ptr = slop_map_get(g.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
}

rdf_Term snarl_data_graph_term_of(data_graph_SnarlDataGraph g, int64_t id) {
    __auto_type _mv_121 = ({ void* _ptr = slop_map_get(g.terms, &(int64_t){id}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
    if (_mv_121.has_value) {
        __auto_type t = _mv_121.value;
        return t;
    } else if (!_mv_121.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

slop_list_rdf_Term data_graph_ids_to_terms(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSet ids) {
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            slop_map* _coll = (slop_map*)ids;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    int64_t id = *(int64_t*)slop_map_key_at(_coll, _i);
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (snarl_data_graph_term_of(g, id)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)(ids)->len))), "(== (list-len $result) (set-len ids))");
    return _retval;
}

data_graph_IdSet data_graph_make_id_set(slop_arena* arena, int64_t value) {
    {
        __auto_type values = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        ({ slop_map_put(NULL, values, &(int64_t){value}, NULL, 0); });
        return values;
    }
}

void data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, int64_t first, int64_t second, int64_t value) {
    __auto_type _mv_124 = ({ void* _ptr = slop_map_get(outer, &(int64_t){first}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_124.has_value) {
        __auto_type inner = _mv_124.value;
        __auto_type _mv_126 = ({ void* _ptr = slop_map_get(inner, &(int64_t){second}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
        if (_mv_126.has_value) {
            __auto_type values = _mv_126.value;
            ({ slop_map_put(NULL, values, &(int64_t){value}, NULL, 0); });
        } else if (!_mv_126.has_value) {
            ({ slop_map* _val = data_graph_make_id_set(arena, value); slop_map_put(NULL, inner, &(int64_t){second}, &_val, sizeof(_val)); });
        }
    } else if (!_mv_124.has_value) {
        {
            __auto_type inner_map = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map* _val = data_graph_make_id_set(arena, value); slop_map_put(NULL, inner_map, &(int64_t){second}, &_val, sizeof(_val)); });
            ({ slop_map* _val = inner_map; slop_map_put(NULL, outer, &(int64_t){first}, &_val, sizeof(_val)); });
        }
    }
}

void data_graph_add_to_flat_set(slop_arena* arena, data_graph_IdSetMap outer, int64_t key, int64_t value) {
    __auto_type _mv_132 = ({ void* _ptr = slop_map_get(outer, &(int64_t){key}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_132.has_value) {
        __auto_type values = _mv_132.value;
        ({ slop_map_put(NULL, values, &(int64_t){value}, NULL, 0); });
    } else if (!_mv_132.has_value) {
        ({ slop_map* _val = data_graph_make_id_set(arena, value); slop_map_put(NULL, outer, &(int64_t){key}, &_val, sizeof(_val)); });
    }
}

uint8_t data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, int64_t subj, int64_t pred, int64_t obj) {
    __auto_type _mv_136 = ({ void* _ptr = slop_map_get(outer, &(int64_t){subj}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_136.has_value) {
        __auto_type pred_map = _mv_136.value;
        __auto_type _mv_138 = ({ void* _ptr = slop_map_get(pred_map, &(int64_t){pred}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
        if (_mv_138.has_value) {
            __auto_type objs = _mv_138.value;
            if (slop_map_has(objs, &(int64_t){obj})) {
                return 0;
            } else {
                ({ slop_map_put(NULL, objs, &(int64_t){obj}, NULL, 0); });
                return 1;
            }
        } else if (!_mv_138.has_value) {
            ({ slop_map* _val = data_graph_make_id_set(arena, obj); slop_map_put(NULL, pred_map, &(int64_t){pred}, &_val, sizeof(_val)); });
            return 1;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_136.has_value) {
        {
            __auto_type pred_map = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map* _val = data_graph_make_id_set(arena, obj); slop_map_put(NULL, pred_map, &(int64_t){pred}, &_val, sizeof(_val)); });
            ({ slop_map* _val = pred_map; slop_map_put(NULL, outer, &(int64_t){subj}, &_val, sizeof(_val)); });
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Triple t) {
    data_graph_SnarlDataGraph _retval = {0};
    {
        __auto_type s = data_graph_intern_term(arena, g, rdf_triple_subject(t));
        __auto_type p = data_graph_intern_term(arena, g, rdf_triple_predicate(t));
        __auto_type o = data_graph_intern_term(arena, g, rdf_triple_object(t));
        if (data_graph_add_to_sp_index_if_new(arena, g.index.sp, s, p, o)) {
            data_graph_add_to_nested_set(arena, g.index.po, p, o, s);
            data_graph_add_to_flat_set(arena, g.index.p_subjects, p, s);
            data_graph_add_to_flat_set(arena, g.index.p_objects, p, o);
            _retval = ((data_graph_SnarlDataGraph){.ids = g.ids, .terms = g.terms, .index = g.index, .no_ids = g.no_ids, .size = (g.size + 1)});
            goto _slop_post;
        } else {
            _retval = g;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval.size >= g.size)), "(>= (. $result size) (. g size))");
    return _retval;
}

int64_t snarl_data_graph_size(data_graph_SnarlDataGraph g) {
    int64_t _retval = {0};
    _retval = g.size;
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

data_graph_IdSet data_graph_object_id_set(data_graph_SnarlDataGraph g, int64_t subj, int64_t pred) {
    __auto_type _mv_145 = ({ void* _ptr = slop_map_get(g.index.sp, &(int64_t){subj}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_145.has_value) {
        __auto_type pred_map = _mv_145.value;
        __auto_type _mv_147 = ({ void* _ptr = slop_map_get(pred_map, &(int64_t){pred}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
        if (_mv_147.has_value) {
            __auto_type objs = _mv_147.value;
            return objs;
        } else if (!_mv_147.has_value) {
            return g.no_ids;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_145.has_value) {
        return g.no_ids;
    }
    SLOP_UNREACHABLE();
}

data_graph_IdSet data_graph_snarl_data_graph_object_set(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred) {
    __auto_type _mv_148 = data_graph_lookup_term(g, subj);
    if (_mv_148.has_value) {
        __auto_type s = _mv_148.value;
        __auto_type _mv_149 = data_graph_lookup_term(g, pred);
        if (_mv_149.has_value) {
            __auto_type p = _mv_149.value;
            return data_graph_object_id_set(g, s, p);
        } else if (!_mv_149.has_value) {
            return g.no_ids;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_148.has_value) {
        return g.no_ids;
    }
    SLOP_UNREACHABLE();
}

int64_t data_graph_snarl_data_graph_id_set_size(slop_map* ids) {
    int64_t _retval = {0};
    _retval = SLOP_RANGE(int64_t, ((int64_t)(ids)->len), 1, 0, 0, 0, "(Int 0 ..) at data-graph.slop:306:5");
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

slop_list_rdf_Term data_graph_snarl_data_graph_id_set_to_list(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSet ids) {
    slop_list_rdf_Term _retval = {0};
    _retval = data_graph_ids_to_terms(arena, g, ids);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)(ids)->len))), "(== (list-len $result) (set-len ids))");
    return _retval;
}

uint8_t data_graph_snarl_data_graph_has_object(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred, rdf_Term obj) {
    __auto_type _mv_150 = data_graph_lookup_term(g, obj);
    if (_mv_150.has_value) {
        __auto_type o = _mv_150.value;
        return slop_map_has(data_graph_snarl_data_graph_object_set(g, subj, pred), &(int64_t){o});
    } else if (!_mv_150.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t snarl_data_graph_contains(data_graph_SnarlDataGraph g, rdf_Triple t) {
    return data_graph_snarl_data_graph_has_object(g, rdf_triple_subject(t), rdf_triple_predicate(t), rdf_triple_object(t));
}

slop_list_rdf_Term snarl_data_graph_objects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred) {
    slop_list_rdf_Term _retval = {0};
    _retval = data_graph_ids_to_terms(arena, g, data_graph_snarl_data_graph_object_set(g, subj, pred));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_data_graph_subjects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred, rdf_Term obj) {
    slop_list_rdf_Term _retval = {0};
    __auto_type _mv_152 = data_graph_lookup_term(g, pred);
    if (_mv_152.has_value) {
        __auto_type p = _mv_152.value;
        __auto_type _mv_153 = data_graph_lookup_term(g, obj);
        if (_mv_153.has_value) {
            __auto_type o = _mv_153.value;
            __auto_type _mv_155 = ({ void* _ptr = slop_map_get(g.index.po, &(int64_t){p}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_155.has_value) {
                __auto_type obj_map = _mv_155.value;
                __auto_type _mv_157 = ({ void* _ptr = slop_map_get(obj_map, &(int64_t){o}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                if (_mv_157.has_value) {
                    __auto_type subjects = _mv_157.value;
                    _retval = data_graph_ids_to_terms(arena, g, subjects);
                    goto _slop_post;
                } else if (!_mv_157.has_value) {
                    _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    goto _slop_post;
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_155.has_value) {
                _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                goto _slop_post;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_153.has_value) {
            _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_152.has_value) {
        _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term data_graph_flat_index_terms(slop_arena* arena, data_graph_SnarlDataGraph g, data_graph_IdSetMap index, rdf_Term pred) {
    slop_list_rdf_Term _retval = {0};
    __auto_type _mv_158 = data_graph_lookup_term(g, pred);
    if (_mv_158.has_value) {
        __auto_type p = _mv_158.value;
        __auto_type _mv_160 = ({ void* _ptr = slop_map_get(index, &(int64_t){p}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
        if (_mv_160.has_value) {
            __auto_type values = _mv_160.value;
            _retval = data_graph_ids_to_terms(arena, g, values);
            goto _slop_post;
        } else if (!_mv_160.has_value) {
            _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_158.has_value) {
        _retval = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred) {
    slop_list_rdf_Term _retval = {0};
    _retval = data_graph_flat_index_terms(arena, g, g.index.p_subjects, pred);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred) {
    slop_list_rdf_Term _retval = {0};
    _retval = data_graph_flat_index_terms(arena, g, g.index.p_objects, pred);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Term data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj) {
    slop_list_rdf_Term _retval = {0};
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_161 = data_graph_lookup_term(g, subj);
        if (_mv_161.has_value) {
            __auto_type s = _mv_161.value;
            __auto_type _mv_163 = ({ void* _ptr = slop_map_get(g.index.sp, &(int64_t){s}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_163.has_value) {
                __auto_type pred_map = _mv_163.value;
                {
                    slop_map* _coll = (slop_map*)pred_map;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t p = *(int64_t*)slop_map_key_at(_coll, _i);
                            data_graph_IdSet _ = *(data_graph_IdSet*)slop_map_value_at(_coll, _i);
                            ({ __auto_type _lst_p = &(result); __auto_type _item = (snarl_data_graph_term_of(g, p)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            } else if (!_mv_163.has_value) {
            }
        } else if (!_mv_161.has_value) {
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_list_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj) {
    slop_list_rdf_Triple _retval = {0};
    {
        __auto_type result = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_164 = data_graph_lookup_term(g, subj);
        if (_mv_164.has_value) {
            __auto_type s = _mv_164.value;
            __auto_type _mv_166 = ({ void* _ptr = slop_map_get(g.index.sp, &(int64_t){s}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_166.has_value) {
                __auto_type pred_map = _mv_166.value;
                {
                    slop_map* _coll = (slop_map*)pred_map;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t p = *(int64_t*)slop_map_key_at(_coll, _i);
                            data_graph_IdSet objs = *(data_graph_IdSet*)slop_map_value_at(_coll, _i);
                            {
                                __auto_type pred = snarl_data_graph_term_of(g, p);
                                {
                                    slop_map* _coll = (slop_map*)objs;
                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                        {
                                            int64_t o = *(int64_t*)slop_map_key_at(_coll, _i);
                                            ({ __auto_type _lst_p = &(result); __auto_type _item = (rdf_make_triple(arena, subj, pred, snarl_data_graph_term_of(g, o))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_166.has_value) {
            }
        } else if (!_mv_164.has_value) {
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, data_graph_SnarlDataGraph g) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    {
        __auto_type out = rdf_indexed_graph_create(arena);
        {
            slop_map* _coll = (slop_map*)g.index.sp;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    int64_t s = *(int64_t*)slop_map_key_at(_coll, _i);
                    data_graph_IdSetMap pred_map = *(data_graph_IdSetMap*)slop_map_value_at(_coll, _i);
                    {
                        __auto_type subj = snarl_data_graph_term_of(g, s);
                        {
                            slop_map* _coll = (slop_map*)pred_map;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    int64_t p = *(int64_t*)slop_map_key_at(_coll, _i);
                                    data_graph_IdSet objs = *(data_graph_IdSet*)slop_map_value_at(_coll, _i);
                                    {
                                        __auto_type pred = snarl_data_graph_term_of(g, p);
                                        {
                                            slop_map* _coll = (slop_map*)objs;
                                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                                {
                                                    int64_t o = *(int64_t*)slop_map_key_at(_coll, _i);
                                                    out = rdf_indexed_graph_add(arena, out, rdf_make_triple(arena, subj, pred, snarl_data_graph_term_of(g, o)));
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
        return out;
    }
}

data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, index_IndexedGraph g) {
    SLOP_PRE(((rdf_indexed_graph_size(g) >= 0)), "(>= (indexed-graph-size g) 0)");
    data_graph_SnarlDataGraph _retval = {0};
    {
        __auto_type out = snarl_data_graph_create(arena);
        {
            __auto_type _coll = g.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                out = snarl_data_graph_add(arena, out, t);
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.size >= 0)), "(>= (. $result size) 0)");
    return _retval;
}

