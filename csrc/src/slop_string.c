#include "../runtime/slop_runtime.h"
#include "slop_string.h"

static const slop_string string_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string string_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

slop_string string_term_string_value(rdf_Term t);
slop_string string_term_lang(rdf_Term t);
uint8_t string_term_is_literal(rdf_Term t);
uint8_t string_regex_match_ffi(slop_arena* arena, slop_string pattern, slop_string input);
uint8_t string_min_length_satisfied(rdf_Term value_node, int64_t min_len);
uint8_t string_max_length_satisfied(rdf_Term value_node, int64_t max_len);
uint8_t string_pattern_satisfied(slop_arena* arena, rdf_Term value_node, slop_string pattern);
slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_string string_fixture_allowed_langs(slop_arena* arena);
slop_list_rdf_Term string_fixture_unique_langs(slop_arena* arena);
slop_list_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_string string_term_string_value(rdf_Term t) {
    slop_string _retval = {0};
    __auto_type _mv_135 = t;
    switch (_mv_135.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_135.data.term_literal;
            return lit.value;
        }
        case rdf_Term_term_iri:
        {
            __auto_type iri = _mv_135.data.term_iri;
            return iri.value;
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_135.data.term_blank;
            return SLOP_STR("");
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_135.data.term_triple;
            return SLOP_STR("");
        }
    }
    SLOP_POST((({ __auto_type _mv = t; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_literal: { __auto_type lit = _mv.data.term_literal; _mr = slop_string_eq(_retval, lit.value); break; } case rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = slop_string_eq(_retval, iri.value); break; } case rdf_Term_term_blank: { __auto_type _ = _mv.data.term_blank; _mr = slop_string_eq(_retval, SLOP_STR("")); break; } case rdf_Term_term_triple: { __auto_type _ = _mv.data.term_triple; _mr = slop_string_eq(_retval, SLOP_STR("")); break; }  } _mr; })), "(match t ((term-literal lit) (== $result (. lit value))) ((term-iri iri) (== $result (. iri value))) ((term-blank _) (== $result \"\")) ((term-triple _) (== $result \"\")))");
    return _retval;
}

slop_string string_term_lang(rdf_Term t) {
    __auto_type _mv_136 = t;
    switch (_mv_136.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_136.data.term_literal;
            __auto_type _mv_137 = lit.lang;
            if (_mv_137.has_value) {
                __auto_type lang = _mv_137.value;
                return lang;
            } else if (!_mv_137.has_value) {
                return SLOP_STR("");
            }
        }
        default: {
            return SLOP_STR("");
        }
    }
}

uint8_t string_term_is_literal(rdf_Term t) {
    __auto_type _mv_138 = t;
    switch (_mv_138.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_138.data.term_literal;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t string_regex_match_ffi(slop_arena* arena, slop_string pattern, slop_string input) {
    {
        __auto_type preg = ((void*)(({ __auto_type _alloc = (uint8_t*)slop_arena_alloc(arena, 256); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        if (regcomp(preg, ((char*)(pattern.data)), 1) != 0) {
            return 0;
        } else {
            {
                __auto_type result = regexec(preg, ((char*)(input.data)), ((uint64_t)(0)), ((void*)(0)), 0);
                regfree(preg);
                return (result == 0);
            }
        }
    }
}

uint8_t string_min_length_satisfied(rdf_Term value_node, int64_t min_len) {
    return (string_len(string_term_string_value(value_node)) >= min_len);
}

uint8_t string_max_length_satisfied(rdf_Term value_node, int64_t max_len) {
    return (string_len(string_term_string_value(value_node)) <= max_len);
}

uint8_t string_pattern_satisfied(slop_arena* arena, rdf_Term value_node, slop_string pattern) {
    return string_regex_match_ffi(arena, pattern, string_term_string_value(value_node));
}

slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_len >= 0)), "(>= min-len 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (string_min_length_satisfied(value_node, min_len)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MIN_LENGTH, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == string_min_length_satisfied(value_node, min_len))), "(== (== $result (none)) (min-length-satisfied value-node min-len))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((max_len >= 0)), "(>= max-len 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (string_max_length_satisfied(value_node, max_len)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MAX_LENGTH, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == string_max_length_satisfied(value_node, max_len))), "(== (== $result (none)) (max-length-satisfied value-node max-len))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((string_len(pattern) > 0)), "(> (string-len pattern) 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (string_pattern_satisfied(arena, value_node, pattern)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_PATTERN, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == string_pattern_satisfied(arena, value_node, pattern))), "(== (== $result (none)) (pattern-satisfied arena value-node pattern))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_langs).len)) > 0)), "(> (list-len allowed-langs) 0)");
    slop_option_types_ValidationResult _retval = {0};
    __auto_type _mv_139 = value_node;
    switch (_mv_139.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_139.data.term_literal;
            __auto_type _mv_140 = lit.lang;
            if (_mv_140.has_value) {
                __auto_type lang = _mv_140.value;
                {
                    __auto_type found = 0;
                    {
                        __auto_type _coll = allowed_langs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type al = _coll.data[_i];
                            if (string_eq(lang, al)) {
                                found = 1;
                            }
                        }
                    }
                    if (found) {
                        return (slop_option_types_ValidationResult){.has_value = false};
                    } else {
                        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
                    }
                }
            } else if (!_mv_140.has_value) {
                return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
            }
        }
        default: {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
        }
    }
    SLOP_POST((({ __auto_type _mv = value_node; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_literal: { __auto_type _ = _mv.data.term_literal; _mr = 1; break; } default: { _mr = (_retval != ((slop_option_types_ValidationResult){.has_value = false})); break; }  } _mr; })), "(match value-node ((term-literal _) true) (_ (!= $result (none))))");
    return _retval;
}

slop_list_string string_fixture_allowed_langs(slop_arena* arena) {
    {
        __auto_type langs = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(langs); __auto_type _item = (SLOP_STR("en")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(langs); __auto_type _item = (SLOP_STR("fr")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return langs;
    }
}

slop_list_rdf_Term string_fixture_unique_langs(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("hi"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("en")})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("bonjour"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("fr")})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return terms;
    }
}

slop_list_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(slop_string), slop_hash_string, slop_eq_string);
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type vn = _coll.data[_i];
                __auto_type _mv_141 = vn;
                switch (_mv_141.tag) {
                    case rdf_Term_term_literal:
                    {
                        __auto_type lit = _mv_141.data.term_literal;
                        __auto_type _mv_142 = lit.lang;
                        if (_mv_142.has_value) {
                            __auto_type lang = _mv_142.value;
                            if (slop_map_get(seen, &(lang)) != NULL) {
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = vn}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_UNIQUE_LANG, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(lang), &_dummy); });
                            }
                        } else if (!_mv_142.has_value) {
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

