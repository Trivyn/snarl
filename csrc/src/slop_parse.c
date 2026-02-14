#include "../runtime/slop_runtime.h"
#include "slop_parse.h"

void parse_register_inline_shapes(slop_arena* arena, index_IndexedGraph g, slop_list_types_NodeShape node_shapes, slop_list_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map);
types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, index_IndexedGraph shapes_graph);
types_NodeShape snarl_parse_node_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_PropertyShape snarl_parse_property_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_ShaclPath snarl_parse_path(slop_arena* arena, index_IndexedGraph g, rdf_Term path_node);
slop_list_types_Constraint snarl_parse_constraints(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_types_NodeKind snarl_parse_node_kind(rdf_Term term);
types_Severity snarl_parse_severity(rdf_Term term);
types_Severity parse_parse_shape_severity(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_string parse_parse_shape_message(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
uint8_t parse_parse_shape_deactivated(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_int parse_term_to_int(rdf_Term t);
slop_option_string parse_term_to_string(rdf_Term t);
slop_option_u8 parse_term_to_bool(rdf_Term t);
slop_list_string parse_parse_string_list(slop_arena* arena, index_IndexedGraph g, rdf_Term list_head);

void parse_register_inline_shapes(slop_arena* arena, index_IndexedGraph g, slop_list_types_NodeShape node_shapes, slop_list_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map) {
    {
        __auto_type ns_queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type ps_queue = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = node_shapes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns = _coll.data[_i];
                {
                    __auto_type _coll = ns.constraints;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        __auto_type _mv_170 = c;
                        switch (_mv_170.tag) {
                            case types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_170.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_170.data.con_and;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_or:
                            {
                                __auto_type refs = _mv_170.data.con_or;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_xone:
                            {
                                __auto_type refs = _mv_170.data.con_xone;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_node:
                            {
                                __auto_type ref = _mv_170.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_170.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_170.data.con_property;
                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                __auto_type _mv_171 = c;
                                switch (_mv_171.tag) {
                                    case types_Constraint_con_not:
                                    {
                                        __auto_type ref = _mv_171.data.con_not;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case types_Constraint_con_and:
                                    {
                                        __auto_type refs = _mv_171.data.con_and;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case types_Constraint_con_or:
                                    {
                                        __auto_type refs = _mv_171.data.con_or;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case types_Constraint_con_xone:
                                    {
                                        __auto_type refs = _mv_171.data.con_xone;
                                        {
                                            __auto_type _coll = refs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type r = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        break;
                                    }
                                    case types_Constraint_con_node:
                                    {
                                        __auto_type ref = _mv_171.data.con_node;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case types_Constraint_con_qualified_value_shape:
                                    {
                                        __auto_type ref = _mv_171.data.con_qualified_value_shape.f0;
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        break;
                                    }
                                    case types_Constraint_con_property:
                                    {
                                        __auto_type ref = _mv_171.data.con_property;
                                        ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        __auto_type _mv_172 = c;
                        switch (_mv_172.tag) {
                            case types_Constraint_con_not:
                            {
                                __auto_type ref = _mv_172.data.con_not;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_and:
                            {
                                __auto_type refs = _mv_172.data.con_and;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_or:
                            {
                                __auto_type refs = _mv_172.data.con_or;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_xone:
                            {
                                __auto_type refs = _mv_172.data.con_xone;
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type r = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_Constraint_con_node:
                            {
                                __auto_type ref = _mv_172.data.con_node;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_qualified_value_shape:
                            {
                                __auto_type ref = _mv_172.data.con_qualified_value_shape.f0;
                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_Constraint_con_property:
                            {
                                __auto_type ref = _mv_172.data.con_property;
                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (ref); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                while ((ns_i < ((int64_t)((ns_queue).len)))) {
                    __auto_type _mv_173 = ({ __auto_type _lst = ns_queue; size_t _idx = (size_t)ns_i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_173.has_value) {
                        __auto_type ref = _mv_173.value;
                        __auto_type _mv_174 = ({ void* _ptr = slop_map_get(shape_map, &(ref)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                        if (!_mv_174.has_value) {
                            changed = 1;
                            {
                                __auto_type ns = snarl_parse_node_shape(arena, g, ref);
                                ({ __auto_type _val = ns; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, shape_map, &(ref), _vptr); });
                                {
                                    __auto_type _coll = ns.constraints;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        __auto_type _mv_175 = c;
                                        switch (_mv_175.tag) {
                                            case types_Constraint_con_not:
                                            {
                                                __auto_type r = _mv_175.data.con_not;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_and:
                                            {
                                                __auto_type rs = _mv_175.data.con_and;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_or:
                                            {
                                                __auto_type rs = _mv_175.data.con_or;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_xone:
                                            {
                                                __auto_type rs = _mv_175.data.con_xone;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_node:
                                            {
                                                __auto_type r = _mv_175.data.con_node;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_qualified_value_shape:
                                            {
                                                __auto_type r = _mv_175.data.con_qualified_value_shape.f0;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_property:
                                            {
                                                __auto_type r = _mv_175.data.con_property;
                                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                        __auto_type _mv_176 = ({ void* _ptr = slop_map_get(property_shape_map, &(ps.id)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                                        if (!_mv_176.has_value) {
                                            ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(ps.id), _vptr); });
                                        } else if (_mv_176.has_value) {
                                            __auto_type _ = _mv_176.value;
                                        }
                                        {
                                            __auto_type _coll = ps.constraints;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type c = _coll.data[_i];
                                                __auto_type _mv_177 = c;
                                                switch (_mv_177.tag) {
                                                    case types_Constraint_con_not:
                                                    {
                                                        __auto_type r = _mv_177.data.con_not;
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        break;
                                                    }
                                                    case types_Constraint_con_and:
                                                    {
                                                        __auto_type rs = _mv_177.data.con_and;
                                                        {
                                                            __auto_type _coll = rs;
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type r = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case types_Constraint_con_or:
                                                    {
                                                        __auto_type rs = _mv_177.data.con_or;
                                                        {
                                                            __auto_type _coll = rs;
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type r = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case types_Constraint_con_xone:
                                                    {
                                                        __auto_type rs = _mv_177.data.con_xone;
                                                        {
                                                            __auto_type _coll = rs;
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type r = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case types_Constraint_con_node:
                                                    {
                                                        __auto_type r = _mv_177.data.con_node;
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        break;
                                                    }
                                                    case types_Constraint_con_qualified_value_shape:
                                                    {
                                                        __auto_type r = _mv_177.data.con_qualified_value_shape.f0;
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        break;
                                                    }
                                                    case types_Constraint_con_property:
                                                    {
                                                        __auto_type r = _mv_177.data.con_property;
                                                        ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        } else if (_mv_174.has_value) {
                            __auto_type _ = _mv_174.value;
                        }
                    } else if (!_mv_173.has_value) {
                    }
                    ns_i = (ns_i + 1);
                }
                while ((ps_i < ((int64_t)((ps_queue).len)))) {
                    __auto_type _mv_178 = ({ __auto_type _lst = ps_queue; size_t _idx = (size_t)ps_i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_178.has_value) {
                        __auto_type ref = _mv_178.value;
                        __auto_type _mv_179 = ({ void* _ptr = slop_map_get(property_shape_map, &(ref)); _ptr ? (slop_option_types_PropertyShape){ .has_value = true, .value = *(types_PropertyShape*)_ptr } : (slop_option_types_PropertyShape){ .has_value = false }; });
                        if (!_mv_179.has_value) {
                            changed = 1;
                            {
                                __auto_type ps = snarl_parse_property_shape(arena, g, ref);
                                ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(ref), _vptr); });
                                {
                                    __auto_type _coll = ps.constraints;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        __auto_type _mv_180 = c;
                                        switch (_mv_180.tag) {
                                            case types_Constraint_con_not:
                                            {
                                                __auto_type r = _mv_180.data.con_not;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_and:
                                            {
                                                __auto_type rs = _mv_180.data.con_and;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_or:
                                            {
                                                __auto_type rs = _mv_180.data.con_or;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_xone:
                                            {
                                                __auto_type rs = _mv_180.data.con_xone;
                                                {
                                                    __auto_type _coll = rs;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type r = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                                break;
                                            }
                                            case types_Constraint_con_node:
                                            {
                                                __auto_type r = _mv_180.data.con_node;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_qualified_value_shape:
                                            {
                                                __auto_type r = _mv_180.data.con_qualified_value_shape.f0;
                                                ({ __auto_type _lst_p = &(ns_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            case types_Constraint_con_property:
                                            {
                                                __auto_type r = _mv_180.data.con_property;
                                                ({ __auto_type _lst_p = &(ps_queue); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                break;
                                            }
                                            default: {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (_mv_179.has_value) {
                            __auto_type _ = _mv_179.value;
                        }
                    } else if (!_mv_178.has_value) {
                    }
                    ps_i = (ps_i + 1);
                }
            }
        }
    }
}

types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, index_IndexedGraph shapes_graph) {
    SLOP_PRE(((rdf_indexed_graph_size(shapes_graph) >= 0)), "(>= (indexed-graph-size shapes-graph) 0)");
    types_ShapesGraph _retval = {0};
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type ns_type = rdf_make_iri(arena, vocab_SHACL_NODE_SHAPE);
        __auto_type ps_type = rdf_make_iri(arena, vocab_SHACL_PROPERTY_SHAPE);
        slop_option_rdf_Term no_term = (slop_option_rdf_Term){.has_value = false};
        __auto_type ns_subjects = rdf_indexed_graph_subjects(arena, shapes_graph, type_pred, ns_type);
        __auto_type ps_subjects = rdf_indexed_graph_subjects(arena, shapes_graph, type_pred, ps_type);
        __auto_type node_shapes = ((slop_list_types_NodeShape){ .data = (types_NodeShape*)slop_arena_alloc(arena, 16 * sizeof(types_NodeShape)), .len = 0, .cap = 16 });
        __auto_type prop_shapes = ((slop_list_types_PropertyShape){ .data = (types_PropertyShape*)slop_arena_alloc(arena, 16 * sizeof(types_PropertyShape)), .len = 0, .cap = 16 });
        __auto_type shape_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type property_shape_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        {
            __auto_type _coll = ns_subjects;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ns_id = _coll.data[_i];
                {
                    __auto_type ns = snarl_parse_node_shape(arena, shapes_graph, ns_id);
                    ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _val = ns; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, shape_map, &(ns_id), _vptr); });
                    {
                        __auto_type _coll = ns.property_shapes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ps = _coll.data[_i];
                            ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(ps.id), _vptr); });
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
                    __auto_type t_nodes = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, vocab_SHACL_TARGET_NODE));
                    __auto_type t_classes = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, vocab_SHACL_TARGET_CLASS));
                    __auto_type t_subj = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, vocab_SHACL_TARGET_SUBJECTS_OF));
                    __auto_type t_obj = rdf_indexed_graph_objects(arena, shapes_graph, ps_id, rdf_make_iri(arena, vocab_SHACL_TARGET_OBJECTS_OF));
                    ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(ps_id), _vptr); });
                    if (((((int64_t)((t_nodes).len)) > 0) || ((((int64_t)((t_classes).len)) > 0) || ((((int64_t)((t_subj).len)) > 0) || (((int64_t)((t_obj).len)) > 0))))) {
                        {
                            __auto_type ps_list = ((slop_list_types_PropertyShape){ .data = (types_PropertyShape*)slop_arena_alloc(arena, 16 * sizeof(types_PropertyShape)), .len = 0, .cap = 16 });
                            ({ __auto_type _lst_p = &(ps_list); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            {
                                __auto_type ns = ((types_NodeShape){.id = ps_id, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_types_Constraint){ .data = (types_Constraint*)slop_arena_alloc(arena, 16 * sizeof(types_Constraint)), .len = 0, .cap = 16 }), .severity = types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated});
                                ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _val = ns; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, shape_map, &(ps_id), _vptr); });
                            }
                        }
                    } else {
                        ({ __auto_type _lst_p = &(prop_shapes); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type target_pred_tn = rdf_make_iri(arena, vocab_SHACL_TARGET_NODE);
            __auto_type target_pred_tc = rdf_make_iri(arena, vocab_SHACL_TARGET_CLASS);
            __auto_type target_pred_ts = rdf_make_iri(arena, vocab_SHACL_TARGET_SUBJECTS_OF);
            __auto_type target_pred_to = rdf_make_iri(arena, vocab_SHACL_TARGET_OBJECTS_OF);
            __auto_type path_pred = rdf_make_iri(arena, vocab_SHACL_PATH);
            __auto_type target_preds = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
            ({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_tn); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_tc); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_ts); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(target_preds); __auto_type _item = (target_pred_to); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            {
                __auto_type _coll = target_preds;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tp = _coll.data[_i];
                    {
                        __auto_type triples = rdf_indexed_graph_match(arena, shapes_graph, no_term, (slop_option_rdf_Term){.has_value = 1, .value = tp}, no_term);
                        {
                            __auto_type _coll = triples;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type tr = _coll.data[_i];
                                {
                                    __auto_type subj = rdf_triple_subject(tr);
                                    __auto_type _mv_181 = ({ void* _ptr = slop_map_get(shape_map, &(subj)); _ptr ? (slop_option_types_NodeShape){ .has_value = true, .value = *(types_NodeShape*)_ptr } : (slop_option_types_NodeShape){ .has_value = false }; });
                                    if (_mv_181.has_value) {
                                        __auto_type _ = _mv_181.value;
                                    } else if (!_mv_181.has_value) {
                                        {
                                            __auto_type path_vals = rdf_indexed_graph_objects(arena, shapes_graph, subj, path_pred);
                                            if ((((int64_t)((path_vals).len)) > 0)) {
                                                {
                                                    __auto_type ps = snarl_parse_property_shape(arena, shapes_graph, subj);
                                                    __auto_type t_nodes = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_tn);
                                                    __auto_type t_classes = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_tc);
                                                    __auto_type t_subj = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_ts);
                                                    __auto_type t_obj = rdf_indexed_graph_objects(arena, shapes_graph, subj, target_pred_to);
                                                    ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(subj), _vptr); });
                                                    {
                                                        __auto_type ps_list = ((slop_list_types_PropertyShape){ .data = (types_PropertyShape*)slop_arena_alloc(arena, 16 * sizeof(types_PropertyShape)), .len = 0, .cap = 16 });
                                                        ({ __auto_type _lst_p = &(ps_list); __auto_type _item = (ps); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        {
                                                            __auto_type ns = ((types_NodeShape){.id = subj, .target_nodes = t_nodes, .target_classes = t_classes, .target_subjects_of = t_subj, .target_objects_of = t_obj, .property_shapes = ps_list, .constraints = ((slop_list_types_Constraint){ .data = (types_Constraint*)slop_arena_alloc(arena, 16 * sizeof(types_Constraint)), .len = 0, .cap = 16 }), .severity = types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}, .deactivated = ps.deactivated});
                                                            ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            ({ __auto_type _val = ns; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, shape_map, &(subj), _vptr); });
                                                        }
                                                    }
                                                }
                                            } else {
                                                {
                                                    __auto_type ns = snarl_parse_node_shape(arena, shapes_graph, subj);
                                                    ({ __auto_type _lst_p = &(node_shapes); __auto_type _item = (ns); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ __auto_type _val = ns; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, shape_map, &(subj), _vptr); });
                                                    {
                                                        __auto_type _coll = ns.property_shapes;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type ps = _coll.data[_i];
                                                            ({ __auto_type _val = ps; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, property_shape_map, &(ps.id), _vptr); });
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
        parse_register_inline_shapes(arena, shapes_graph, node_shapes, prop_shapes, shape_map, property_shape_map);
        _retval = ((types_ShapesGraph){.node_shapes = node_shapes, .property_shapes = prop_shapes, .shape_map = shape_map, .property_shape_map = property_shape_map});
    }
    SLOP_POST(((((int64_t)((_retval.node_shapes).len)) >= 0)), "(>= (list-len (. $result node-shapes)) 0)");
    return _retval;
}

types_NodeShape snarl_parse_node_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    {
        __auto_type target_nodes = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_TARGET_NODE));
        __auto_type target_classes = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_TARGET_CLASS));
        __auto_type target_subjects_of = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_TARGET_SUBJECTS_OF));
        __auto_type target_objects_of = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_TARGET_OBJECTS_OF));
        __auto_type prop_refs = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_PROPERTY));
        __auto_type prop_shapes = ((slop_list_types_PropertyShape){ .data = (types_PropertyShape*)slop_arena_alloc(arena, 16 * sizeof(types_PropertyShape)), .len = 0, .cap = 16 });
        __auto_type constraints = snarl_parse_constraints(arena, g, shape_id);
        __auto_type severity = parse_parse_shape_severity(arena, g, shape_id);
        __auto_type message = parse_parse_shape_message(arena, g, shape_id);
        __auto_type deactivated = parse_parse_shape_deactivated(arena, g, shape_id);
        {
            __auto_type _coll = prop_refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ps_ref = _coll.data[_i];
                ({ __auto_type _lst_p = &(prop_shapes); __auto_type _item = (snarl_parse_property_shape(arena, g, ps_ref)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((types_NodeShape){.id = shape_id, .target_nodes = target_nodes, .target_classes = target_classes, .target_subjects_of = target_subjects_of, .target_objects_of = target_objects_of, .property_shapes = prop_shapes, .constraints = constraints, .severity = severity, .message = message, .deactivated = deactivated});
    }
}

types_PropertyShape snarl_parse_property_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    {
        __auto_type path_objects = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_PATH));
        __auto_type path = (((((int64_t)((path_objects).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = path_objects; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type path_term = _mv.value; snarl_parse_path(arena, g, path_term); }) : (((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = shape_id })); }) : ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = shape_id }));
        __auto_type constraints = snarl_parse_constraints(arena, g, shape_id);
        __auto_type severity = parse_parse_shape_severity(arena, g, shape_id);
        __auto_type message = parse_parse_shape_message(arena, g, shape_id);
        __auto_type deactivated = parse_parse_shape_deactivated(arena, g, shape_id);
        return ((types_PropertyShape){.id = shape_id, .path = path, .constraints = constraints, .severity = severity, .message = message, .deactivated = deactivated});
    }
}

types_ShaclPath snarl_parse_path(slop_arena* arena, index_IndexedGraph g, rdf_Term path_node) {
    {
        slop_option_rdf_Term no_term = (slop_option_rdf_Term){.has_value = false};
        __auto_type first_pred = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type first_objs = rdf_indexed_graph_objects(arena, g, path_node, first_pred);
        __auto_type inverse_objs = rdf_indexed_graph_objects(arena, g, path_node, rdf_make_iri(arena, vocab_SHACL_INVERSE_PATH));
        __auto_type alt_objs = rdf_indexed_graph_objects(arena, g, path_node, rdf_make_iri(arena, vocab_SHACL_ALTERNATIVE_PATH));
        __auto_type zom_objs = rdf_indexed_graph_objects(arena, g, path_node, rdf_make_iri(arena, vocab_SHACL_ZERO_OR_MORE_PATH));
        __auto_type oom_objs = rdf_indexed_graph_objects(arena, g, path_node, rdf_make_iri(arena, vocab_SHACL_ONE_OR_MORE_PATH));
        __auto_type zoo_objs = rdf_indexed_graph_objects(arena, g, path_node, rdf_make_iri(arena, vocab_SHACL_ZERO_OR_ONE_PATH));
        if ((((int64_t)((first_objs).len)) > 0)) {
            {
                __auto_type elements = rdf_list_elements_indexed(arena, g, path_node);
                __auto_type paths = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
                {
                    __auto_type _coll = elements;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type elem = _coll.data[_i];
                        ({ __auto_type _lst_p = &(paths); __auto_type _item = (snarl_parse_path(arena, g, elem)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_sequence, .data.path_sequence = paths });
            }
        } else if ((((int64_t)((inverse_objs).len)) > 0)) {
            __auto_type _mv_182 = ({ __auto_type _lst = inverse_objs; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_182.has_value) {
                __auto_type inner = _mv_182.value;
                {
                    __auto_type p = snarl_parse_path(arena, g, inner);
                    __auto_type ptr = ((types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((types_ShaclPath){ .tag = types_ShaclPath_path_inverse, .data.path_inverse = ptr });
                }
            } else if (!_mv_182.has_value) {
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
            }
        } else if ((((int64_t)((alt_objs).len)) > 0)) {
            __auto_type _mv_183 = ({ __auto_type _lst = alt_objs; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_183.has_value) {
                __auto_type list_head = _mv_183.value;
                {
                    __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
                    __auto_type paths = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
                    {
                        __auto_type _coll = elements;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type elem = _coll.data[_i];
                            ({ __auto_type _lst_p = &(paths); __auto_type _item = (snarl_parse_path(arena, g, elem)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    return ((types_ShaclPath){ .tag = types_ShaclPath_path_alternative, .data.path_alternative = paths });
                }
            } else if (!_mv_183.has_value) {
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
            }
        } else if ((((int64_t)((zom_objs).len)) > 0)) {
            __auto_type _mv_184 = ({ __auto_type _lst = zom_objs; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_184.has_value) {
                __auto_type inner = _mv_184.value;
                {
                    __auto_type p = snarl_parse_path(arena, g, inner);
                    __auto_type ptr = ((types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((types_ShaclPath){ .tag = types_ShaclPath_path_zero_or_more, .data.path_zero_or_more = ptr });
                }
            } else if (!_mv_184.has_value) {
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
            }
        } else if ((((int64_t)((oom_objs).len)) > 0)) {
            __auto_type _mv_185 = ({ __auto_type _lst = oom_objs; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_185.has_value) {
                __auto_type inner = _mv_185.value;
                {
                    __auto_type p = snarl_parse_path(arena, g, inner);
                    __auto_type ptr = ((types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((types_ShaclPath){ .tag = types_ShaclPath_path_one_or_more, .data.path_one_or_more = ptr });
                }
            } else if (!_mv_185.has_value) {
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
            }
        } else if ((((int64_t)((zoo_objs).len)) > 0)) {
            __auto_type _mv_186 = ({ __auto_type _lst = zoo_objs; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_186.has_value) {
                __auto_type inner = _mv_186.value;
                {
                    __auto_type p = snarl_parse_path(arena, g, inner);
                    __auto_type ptr = ((types_ShaclPath*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 128); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
                    (*ptr) = p;
                    return ((types_ShaclPath){ .tag = types_ShaclPath_path_zero_or_one, .data.path_zero_or_one = ptr });
                }
            } else if (!_mv_186.has_value) {
                return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
            }
        } else if (1) {
            return ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = path_node });
        }
    }
}

slop_list_types_Constraint snarl_parse_constraints(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    slop_list_types_Constraint _retval = {0};
    {
        __auto_type constraints = ((slop_list_types_Constraint){ .data = (types_Constraint*)slop_arena_alloc(arena, 16 * sizeof(types_Constraint)), .len = 0, .cap = 16 });
        {
            __auto_type class_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_CLASS));
            {
                __auto_type _coll = class_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_class, .data.con_class = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type dt_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_DATATYPE));
            {
                __auto_type _coll = dt_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_datatype, .data.con_datatype = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type nk_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_NODE_KIND));
            {
                __auto_type _coll = nk_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_187 = snarl_parse_node_kind(v);
                    if (_mv_187.has_value) {
                        __auto_type nk = _mv_187.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_node_kind, .data.con_node_kind = nk })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_187.has_value) {
                    }
                }
            }
        }
        {
            __auto_type mc_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MIN_COUNT));
            {
                __auto_type _coll = mc_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_188 = parse_term_to_int(v);
                    if (_mv_188.has_value) {
                        __auto_type n = _mv_188.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_min_count, .data.con_min_count = n })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_188.has_value) {
                    }
                }
            }
        }
        {
            __auto_type mc_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MAX_COUNT));
            {
                __auto_type _coll = mc_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_189 = parse_term_to_int(v);
                    if (_mv_189.has_value) {
                        __auto_type n = _mv_189.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_max_count, .data.con_max_count = n })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_189.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MIN_INCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_min_inclusive, .data.con_min_inclusive = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MAX_INCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_max_inclusive, .data.con_max_inclusive = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MIN_EXCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_min_exclusive, .data.con_min_exclusive = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MAX_EXCLUSIVE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_max_exclusive, .data.con_max_exclusive = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MIN_LENGTH));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_190 = parse_term_to_int(v);
                    if (_mv_190.has_value) {
                        __auto_type n = _mv_190.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_min_length, .data.con_min_length = n })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_190.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_MAX_LENGTH));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_191 = parse_term_to_int(v);
                    if (_mv_191.has_value) {
                        __auto_type n = _mv_191.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_max_length, .data.con_max_length = n })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_191.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_PATTERN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_192 = parse_term_to_string(v);
                    if (_mv_192.has_value) {
                        __auto_type s = _mv_192.value;
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_pattern, .data.con_pattern = s })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_192.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_LANGUAGE_IN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type langs = parse_parse_string_list(arena, g, v);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_language_in, .data.con_language_in = langs })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_UNIQUE_LANG));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_193 = parse_term_to_string(v);
                    if (_mv_193.has_value) {
                        __auto_type s = _mv_193.value;
                        if (string_eq(s, SLOP_STR("true"))) {
                            ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_unique_lang, .data.con_unique_lang = 1 })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_193.has_value) {
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_EQUALS));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_equals, .data.con_equals = ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_DISJOINT));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_disjoint, .data.con_disjoint = ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_LESS_THAN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_less_than, .data.con_less_than = ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_LESS_THAN_OR_EQUALS));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_less_than_or_equals, .data.con_less_than_or_equals = ((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = v }) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_NOT));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_not, .data.con_not = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_AND));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_and, .data.con_and = shapes })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_OR));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_or, .data.con_or = shapes })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_XONE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type shapes = rdf_list_elements_indexed(arena, g, v);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_xone, .data.con_xone = shapes })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_NODE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_node, .data.con_node = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type prop_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_PROPERTY));
            {
                __auto_type _coll = prop_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_property, .data.con_property = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type qvs_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_QUALIFIED_VALUE_SHAPE));
            {
                __auto_type _coll = qvs_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type qmin_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_QUALIFIED_MIN_COUNT));
                        __auto_type qmax_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_QUALIFIED_MAX_COUNT));
                        __auto_type qmin = (((((int64_t)((qmin_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = qmin_vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = parse_term_to_int(t); _mv.has_value ? ({ __auto_type n = _mv.value; n; }) : (0); }); }) : (0); }) : 0);
                        __auto_type qmax = (((((int64_t)((qmax_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = qmax_vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = parse_term_to_int(t); _mv.has_value ? ({ __auto_type n = _mv.value; (slop_option_int){.has_value = 1, .value = n}; }) : ((slop_option_int){.has_value = false}); }); }) : ((slop_option_int){.has_value = false}); }) : (slop_option_int){.has_value = false});
                        __auto_type disjoint_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_QUALIFIED_VALUE_SHAPES_DISJOINT));
                        __auto_type disjoint = (((((int64_t)((disjoint_vals).len)) > 0)) ? ({ __auto_type _mv = ({ __auto_type _lst = disjoint_vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type t = _mv.value; ({ __auto_type _mv = parse_term_to_bool(t); _mv.has_value ? ({ __auto_type b = _mv.value; b; }) : (0); }); }) : (0); }) : 0);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_qualified_value_shape, .data.con_qualified_value_shape = { .f0 = v, .f1 = qmin, .f2 = qmax, .f3 = disjoint } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_HAS_VALUE));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_has_value, .data.con_has_value = v })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_IN));
            {
                __auto_type _coll = vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    {
                        __auto_type elements = rdf_list_elements_indexed(arena, g, v);
                        ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_in, .data.con_in = elements })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type closed_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_CLOSED));
            {
                __auto_type _coll = closed_vals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type v = _coll.data[_i];
                    __auto_type _mv_194 = parse_term_to_bool(v);
                    if (_mv_194.has_value) {
                        __auto_type b = _mv_194.value;
                        if (b) {
                            {
                                __auto_type ignored_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, vocab_SHACL_IGNORED_PROPERTIES));
                                __auto_type ignored_paths = ((slop_list_types_ShaclPath){ .data = (types_ShaclPath*)slop_arena_alloc(arena, 16 * sizeof(types_ShaclPath)), .len = 0, .cap = 16 });
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
                                                    ({ __auto_type _lst_p = &(ignored_paths); __auto_type _item = (((types_ShaclPath){ .tag = types_ShaclPath_path_predicate, .data.path_predicate = elem })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                }
                                ({ __auto_type _lst_p = &(constraints); __auto_type _item = (((types_Constraint){ .tag = types_Constraint_con_closed, .data.con_closed = { .f0 = 1, .f1 = ignored_paths } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    } else if (!_mv_194.has_value) {
                    }
                }
            }
        }
        _retval = constraints;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

slop_option_types_NodeKind snarl_parse_node_kind(rdf_Term term) {
    __auto_type _mv_195 = term;
    switch (_mv_195.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type iri = _mv_195.data.term_iri;
            if (string_eq(iri.value, vocab_SHACL_BLANK_NODE)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_blank_node};
            } else if (string_eq(iri.value, vocab_SHACL_IRI)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_iri};
            } else if (string_eq(iri.value, vocab_SHACL_LITERAL)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_literal};
            } else if (string_eq(iri.value, vocab_SHACL_BLANK_NODE_OR_IRI)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_blank_node_or_iri};
            } else if (string_eq(iri.value, vocab_SHACL_BLANK_NODE_OR_LITERAL)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_blank_node_or_literal};
            } else if (string_eq(iri.value, vocab_SHACL_IRI_OR_LITERAL)) {
                return (slop_option_types_NodeKind){.has_value = 1, .value = types_NodeKind_node_kind_iri_or_literal};
            } else {
                return (slop_option_types_NodeKind){.has_value = false};
            }
        }
        default: {
            return (slop_option_types_NodeKind){.has_value = false};
        }
    }
}

types_Severity snarl_parse_severity(rdf_Term term) {
    __auto_type _mv_196 = term;
    switch (_mv_196.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type iri = _mv_196.data.term_iri;
            if (string_eq(iri.value, vocab_SHACL_WARNING)) {
                return types_Severity_severity_warning;
            } else if (string_eq(iri.value, vocab_SHACL_INFO)) {
                return types_Severity_severity_info;
            } else {
                return types_Severity_severity_violation;
            }
        }
        default: {
            return types_Severity_severity_violation;
        }
    }
}

types_Severity parse_parse_shape_severity(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    {
        __auto_type sev_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#severity")));
        if ((((int64_t)((sev_vals).len)) > 0)) {
            __auto_type _mv_197 = ({ __auto_type _lst = sev_vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_197.has_value) {
                __auto_type v = _mv_197.value;
                return snarl_parse_severity(v);
            } else if (!_mv_197.has_value) {
                return types_Severity_severity_violation;
            }
        } else {
            return types_Severity_severity_violation;
        }
    }
}

slop_option_string parse_parse_shape_message(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    {
        __auto_type msg_vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#message")));
        if ((((int64_t)((msg_vals).len)) > 0)) {
            __auto_type _mv_198 = ({ __auto_type _lst = msg_vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_198.has_value) {
                __auto_type v = _mv_198.value;
                return parse_term_to_string(v);
            } else if (!_mv_198.has_value) {
                return (slop_option_string){.has_value = false};
            }
        } else {
            return (slop_option_string){.has_value = false};
        }
    }
}

uint8_t parse_parse_shape_deactivated(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id) {
    {
        __auto_type vals = rdf_indexed_graph_objects(arena, g, shape_id, rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#deactivated")));
        if ((((int64_t)((vals).len)) > 0)) {
            __auto_type _mv_199 = ({ __auto_type _lst = vals; size_t _idx = (size_t)0; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_199.has_value) {
                __auto_type v = _mv_199.value;
                __auto_type _mv_200 = parse_term_to_bool(v);
                if (_mv_200.has_value) {
                    __auto_type b = _mv_200.value;
                    return b;
                } else if (!_mv_200.has_value) {
                    return 0;
                }
            } else if (!_mv_199.has_value) {
                return 0;
            }
        } else {
            return 0;
        }
    }
}

slop_option_int parse_term_to_int(rdf_Term t) {
    __auto_type _mv_201 = t;
    switch (_mv_201.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_201.data.term_literal;
            __auto_type _mv_202 = strlib_parse_int(lit.value);
            if (_mv_202.is_ok) {
                __auto_type n = _mv_202.data.ok;
                if ((n >= 0)) {
                    return (slop_option_int){.has_value = 1, .value = n};
                } else {
                    return (slop_option_int){.has_value = false};
                }
            } else if (!_mv_202.is_ok) {
                __auto_type _ = _mv_202.data.err;
                return (slop_option_int){.has_value = false};
            }
        }
        default: {
            return (slop_option_int){.has_value = false};
        }
    }
}

slop_option_string parse_term_to_string(rdf_Term t) {
    __auto_type _mv_203 = t;
    switch (_mv_203.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_203.data.term_literal;
            return (slop_option_string){.has_value = 1, .value = lit.value};
        }
        default: {
            return (slop_option_string){.has_value = false};
        }
    }
}

slop_option_u8 parse_term_to_bool(rdf_Term t) {
    __auto_type _mv_204 = t;
    switch (_mv_204.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_204.data.term_literal;
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

slop_list_string parse_parse_string_list(slop_arena* arena, index_IndexedGraph g, rdf_Term list_head) {
    {
        __auto_type elements = rdf_list_elements_indexed(arena, g, list_head);
        __auto_type result = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = elements;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type elem = _coll.data[_i];
                __auto_type _mv_205 = parse_term_to_string(elem);
                if (_mv_205.has_value) {
                    __auto_type s = _mv_205.value;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_205.has_value) {
                }
            }
        }
        return result;
    }
}

