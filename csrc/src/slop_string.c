#include "../runtime/slop_runtime.h"
#include "slop_string.h"

static const slop_string snarl_string_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_string_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

slop_string snarl_string_term_string_value(slop_rdf_rdf_Term t);
slop_string snarl_string_term_lang(slop_rdf_rdf_Term t);
uint8_t snarl_string_term_is_literal(slop_rdf_rdf_Term t);
uint8_t snarl_string_regex_match_ffi(slop_string pattern, slop_string input);
uint8_t snarl_string_min_length_satisfied(slop_rdf_rdf_Term value_node, int64_t min_len);
uint8_t snarl_string_max_length_satisfied(slop_rdf_rdf_Term value_node, int64_t max_len);
uint8_t snarl_string_pattern_satisfied(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_string pattern);
slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t max_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_string snarl_string_fixture_allowed_langs(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_string_fixture_unique_langs(slop_arena* arena);
slop_list_snarl_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

slop_string snarl_string_term_string_value(slop_rdf_rdf_Term t) {
    slop_string _retval = {0};
    __auto_type _mv_278 = t;
    switch (_mv_278.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_278.data.term_literal;
            _retval = lit.value;
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_278.data.term_iri;
            _retval = iri.value;
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_278.data.term_blank;
            _retval = SLOP_STR("");
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_278.data.term_triple;
            _retval = SLOP_STR("");
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = t; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case slop_rdf_rdf_Term_term_literal: { __auto_type lit = _mv.data.term_literal; _mr = slop_string_eq(_retval, lit.value); _mm = 1; break; } case slop_rdf_rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = slop_string_eq(_retval, iri.value); _mm = 1; break; } case slop_rdf_rdf_Term_term_blank: { _mr = slop_string_eq(_retval, SLOP_STR("")); _mm = 1; break; } case slop_rdf_rdf_Term_term_triple: { _mr = slop_string_eq(_retval, SLOP_STR("")); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match t ((term-literal lit) (== $result (. lit value))) ((term-iri iri) (== $result (. iri value))) ((term-blank _) (== $result \"\")) ((term-triple _) (== $result \"\")))");
    return _retval;
}

slop_string snarl_string_term_lang(slop_rdf_rdf_Term t) {
    __auto_type _mv_279 = t;
    switch (_mv_279.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_279.data.term_literal;
            __auto_type _mv_280 = lit.lang;
            if (_mv_280.has_value) {
                __auto_type lang = _mv_280.value;
                return lang;
            } else if (!_mv_280.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return SLOP_STR("");
        }
    }
}

uint8_t snarl_string_term_is_literal(slop_rdf_rdf_Term t) {
    __auto_type _mv_281 = t;
    switch (_mv_281.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_281.data.term_literal;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t snarl_string_regex_match_ffi(slop_string pattern, slop_string input) {
    return (snarl_regex_match(((char*)(pattern.data)), ((uint64_t)(pattern.len)), ((char*)(input.data)), ((uint64_t)(input.len))) == 1);
}

uint8_t snarl_string_min_length_satisfied(slop_rdf_rdf_Term value_node, int64_t min_len) {
    return (string_len(snarl_string_term_string_value(value_node)) >= min_len);
}

uint8_t snarl_string_max_length_satisfied(slop_rdf_rdf_Term value_node, int64_t max_len) {
    return (string_len(snarl_string_term_string_value(value_node)) <= max_len);
}

uint8_t snarl_string_pattern_satisfied(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_string pattern) {
    return snarl_string_regex_match_ffi(pattern, snarl_string_term_string_value(value_node));
}

slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_len >= 0)), "(>= min-len 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_min_length_satisfied(value_node, min_len)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_MIN_LENGTH, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_min_length_satisfied(value_node, min_len))), "(== (is-none $result) (min-length-satisfied value-node min-len))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_max_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t max_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((max_len >= 0)), "(>= max-len 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_max_length_satisfied(value_node, max_len)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_MAX_LENGTH, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_max_length_satisfied(value_node, max_len))), "(== (is-none $result) (max-length-satisfied value-node max-len))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((string_len(pattern) > 0)), "(> (string-len pattern) 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_pattern_satisfied(arena, value_node, pattern)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_PATTERN, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_pattern_satisfied(arena, value_node, pattern))), "(== (is-none $result) (pattern-satisfied arena value-node pattern))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_langs).len)) > 0)), "(> (list-len allowed-langs) 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    __auto_type _mv_282 = value_node;
    switch (_mv_282.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_282.data.term_literal;
            __auto_type _mv_283 = lit.lang;
            if (_mv_283.has_value) {
                __auto_type lang = _mv_283.value;
                {
                    uint8_t found = 0;
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
                        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
                        goto _slop_post;
                    } else {
                        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
                        goto _slop_post;
                    }
                }
            } else if (!_mv_283.has_value) {
                _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
                goto _slop_post;
            }
            SLOP_UNREACHABLE();
        }
        default: {
            _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = value_node; uint8_t _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_literal: { _mr = 1; break; } default: { _mr = (((_retval).has_value)); break; }  } _mr; })), "(match value-node ((term-literal _) true) (_ (is-some $result)))");
    return _retval;
}

slop_list_string snarl_string_fixture_allowed_langs(slop_arena* arena) {
    {
        __auto_type langs = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(langs); __auto_type _item = (SLOP_STR("en")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(langs); __auto_type _item = (SLOP_STR("fr")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return langs;
    }
}

slop_list_slop_rdf_rdf_Term snarl_string_fixture_unique_langs(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("hi"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("en")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("bonjour"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("fr")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return terms;
    }
}

slop_list_snarl_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    slop_list_snarl_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type vn = _coll.data[_i];
                __auto_type _mv_284 = vn;
                switch (_mv_284.tag) {
                    case slop_rdf_rdf_Term_term_literal:
                    {
                        __auto_type lit = _mv_284.data.term_literal;
                        __auto_type _mv_285 = lit.lang;
                        if (_mv_285.has_value) {
                            __auto_type lang = _mv_285.value;
                            if (slop_map_has(seen, &(lang))) {
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = vn}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_UNIQUE_LANG, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                ({ slop_map_put(NULL, seen, &(lang), NULL, 0); });
                            }
                        } else if (!_mv_285.has_value) {
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
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

