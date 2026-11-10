#include "../runtime/slop_runtime.h"
#include "slop_node_expr.h"

static const slop_string snarl_node_expr_EX_A = SLOP_STR("http://example.org/a");

slop_list_slop_rdf_rdf_Term snarl_eval_node_expr(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeExpr expr, slop_rdf_rdf_Term focus, slop_closure_t conforms, slop_map* errors);
slop_list_slop_rdf_rdf_Term snarl_node_expr_distinct_terms(slop_arena* arena, slop_list_slop_rdf_rdf_Term terms);

slop_list_slop_rdf_rdf_Term snarl_eval_node_expr(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeExpr expr, slop_rdf_rdf_Term focus, slop_closure_t conforms, slop_map* errors) {
    __auto_type _mv_284 = expr;
    switch (_mv_284.tag) {
        case snarl_types_NodeExpr_nx_focus:
        {
            {
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (focus); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return out;
            }
        }
        case snarl_types_NodeExpr_nx_constant:
        {
            __auto_type t = _mv_284.data.nx_constant;
            {
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return out;
            }
        }
        case snarl_types_NodeExpr_nx_list:
        {
            __auto_type ts = _mv_284.data.nx_list;
            return ts;
        }
        case snarl_types_NodeExpr_nx_path:
        {
            __auto_type path = _mv_284.data.nx_path.f0;
            __auto_type input = _mv_284.data.nx_path.f1;
            __auto_type single_input = _mv_284.data.nx_path.f2;
            {
                __auto_type inputs = snarl_eval_node_expr(arena, data_graph, (*input), focus, conforms, errors);
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                if (single_input && (((int64_t)((inputs).len)) > 1)) {
                    if (!(slop_map_has(errors, &(int64_t){0}))) {
                        ({ slop_string _val = std_strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("Node expression evaluation failure: shnex:focusNode produced "); _ll.data[1] = int_to_string(arena, ((int64_t)((inputs).len))); _ll.data[2] = SLOP_STR(" nodes, but a path values expression needs at most one"); _ll; })); slop_map_put(NULL, errors, &(int64_t){0}, &_val, sizeof(_val)); });
                    }
                    return out;
                } else {
                    {
                        __auto_type _coll = inputs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            {
                                __auto_type _coll = snarl_resolve_path(arena, data_graph, i, path);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type v = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                    return snarl_node_expr_distinct_terms(arena, out);
                }
            }
        }
        case snarl_types_NodeExpr_nx_filter:
        {
            __auto_type shape_ref = _mv_284.data.nx_filter.f0;
            __auto_type input = _mv_284.data.nx_filter.f1;
            {
                __auto_type inputs = snarl_eval_node_expr(arena, data_graph, (*input), focus, conforms, errors);
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = inputs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type n = _coll.data[_i];
                        if (((uint8_t(*)(void*, slop_rdf_rdf_Term, slop_rdf_rdf_Term))conforms.fn)(conforms.env, n, shape_ref)) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                return out;
            }
        }
        case snarl_types_NodeExpr_nx_intersection:
        {
            __auto_type members = _mv_284.data.nx_intersection;
            {
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type _mv_287 = ({ __auto_type _lst = members; size_t _idx = (size_t)0; slop_option_snarl_types_NodeExpr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_287.has_value) {
                    __auto_type first = _mv_287.value;
                    {
                        __auto_type others = ((slop_list_map_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        {
                            int64_t i = 1;
                            while (i < ((int64_t)((members).len))) {
                                __auto_type _mv_288 = ({ __auto_type _lst = members; size_t _idx = (size_t)i; slop_option_snarl_types_NodeExpr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_288.has_value) {
                                    __auto_type m = _mv_288.value;
                                    {
                                        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                                        {
                                            __auto_type _coll = snarl_eval_node_expr(arena, data_graph, m, focus, conforms, errors);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type t = _coll.data[_i];
                                                ({ slop_map_put(NULL, s, &(t), NULL, 0); });
                                            }
                                        }
                                        ({ __auto_type _lst_p = &(others); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                } else if (!_mv_288.has_value) {
                                }
                                i = (i + 1);
                            }
                        }
                        {
                            __auto_type _coll = snarl_eval_node_expr(arena, data_graph, first, focus, conforms, errors);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type t = _coll.data[_i];
                                {
                                    uint8_t in_all = 1;
                                    {
                                        __auto_type _coll = others;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type s = _coll.data[_i];
                                            if (!(slop_map_has(s, &(t)))) {
                                                in_all = 0;
                                            }
                                        }
                                    }
                                    if (in_all) {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_287.has_value) {
                }
                return snarl_node_expr_distinct_terms(arena, out);
            }
        }
        case snarl_types_NodeExpr_nx_union:
        {
            __auto_type members = _mv_284.data.nx_union;
            {
                __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = members;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        {
                            __auto_type _coll = snarl_eval_node_expr(arena, data_graph, m, focus, conforms, errors);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type t = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                return snarl_node_expr_distinct_terms(arena, out);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_Term snarl_node_expr_distinct_terms(slop_arena* arena, slop_list_slop_rdf_rdf_Term terms) {
    slop_list_slop_rdf_rdf_Term _retval = {0};
    {
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = terms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(slop_map_has(seen, &(t)))) {
                    (void)(({ slop_map_put(NULL, seen, &(t), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= ((int64_t)((terms).len)))), "(<= (list-len $result) (list-len terms))");
    return _retval;
}

