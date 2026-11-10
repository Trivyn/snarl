#include "../runtime/slop_runtime.h"
#include "slop_string.h"

static const slop_string snarl_string_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_string_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

slop_string snarl_string_term_string_value(slop_rdf_rdf_Term t);
slop_string snarl_string_term_lang(slop_rdf_rdf_Term t);
uint8_t snarl_string_term_is_literal(slop_rdf_rdf_Term t);
uint8_t snarl_string_pattern_flags_supported(slop_string flags);
uint8_t snarl_string_regex_match_ffi(slop_string pattern, slop_string flags, slop_string input);
slop_string snarl_string_regcomp_error_name(slop_arena* arena, int64_t code);
slop_option_string snarl_string_pattern_compile_error(slop_arena* arena, slop_string pattern);
int64_t snarl_string_string_char_count(slop_string s);
uint8_t snarl_string_term_has_string_form(slop_rdf_rdf_Term value_node);
uint8_t snarl_string_min_length_satisfied(slop_rdf_rdf_Term value_node, int64_t min_len);
uint8_t snarl_string_max_length_satisfied(slop_rdf_rdf_Term value_node, int64_t max_len);
uint8_t snarl_string_pattern_satisfied(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_string pattern, slop_string flags);
uint8_t snarl_string_language_matches(slop_arena* arena, slop_string tag, slop_string range);
uint8_t snarl_string_language_in(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs);
slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t max_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_string flags, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_string snarl_string_fixture_allowed_langs(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_string_fixture_unique_langs(slop_arena* arena);
slop_list_snarl_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

slop_string snarl_string_term_string_value(slop_rdf_rdf_Term t) {
    slop_string _retval = {0};
    __auto_type _mv_302 = t;
    switch (_mv_302.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_302.data.term_literal;
            _retval = lit.value;
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_302.data.term_iri;
            _retval = iri.value;
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_302.data.term_blank;
            _retval = SLOP_STR("");
            goto _slop_post;
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_302.data.term_triple;
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
    __auto_type _mv_303 = t;
    switch (_mv_303.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_303.data.term_literal;
            __auto_type _mv_304 = lit.lang;
            if (_mv_304.has_value) {
                __auto_type lang = _mv_304.value;
                return lang;
            } else if (!_mv_304.has_value) {
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
    __auto_type _mv_305 = t;
    switch (_mv_305.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_305.data.term_literal;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t snarl_string_pattern_flags_supported(slop_string flags) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        __auto_type len = string_len(flags);
        while (i < len) {
            {
                __auto_type c = std_strlib_char_at(flags, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at string.slop:105:33"));
                if ((c != 105) && (c != 115)) {
                    ok = 0;
                }
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t snarl_string_regex_match_ffi(slop_string pattern, slop_string flags, slop_string input) {
    return (snarl_regex_match_flags(((char*)(pattern.data)), ((uint64_t)(pattern.len)), ((char*)(input.data)), ((uint64_t)(input.len)), ((std_strlib_contains(flags, SLOP_STR("i"))) ? 1 : 0)) == 1);
}

slop_string snarl_string_regcomp_error_name(slop_arena* arena, int64_t code) {
    if (code == 2) {
        return SLOP_STR("REG_BADPAT");
    } else if (code == 3) {
        return SLOP_STR("REG_ECOLLATE");
    } else if (code == 4) {
        return SLOP_STR("REG_ECTYPE");
    } else if (code == 5) {
        return SLOP_STR("REG_EESCAPE");
    } else if (code == 6) {
        return SLOP_STR("REG_ESUBREG");
    } else if (code == 7) {
        return SLOP_STR("REG_EBRACK");
    } else if (code == 8) {
        return SLOP_STR("REG_EPAREN");
    } else if (code == 9) {
        return SLOP_STR("REG_EBRACE");
    } else if (code == 10) {
        return SLOP_STR("REG_BADBR");
    } else if (code == 11) {
        return SLOP_STR("REG_ERANGE");
    } else if (code == 12) {
        return SLOP_STR("REG_ESPACE");
    } else if (code == 13) {
        return SLOP_STR("REG_BADRPT");
    } else {
        return string_concat(arena, SLOP_STR("REG_"), int_to_string(arena, code));
    }
}

slop_option_string snarl_string_pattern_compile_error(slop_arena* arena, slop_string pattern) {
    {
        __auto_type rc = snarl_regex_match(((char*)(pattern.data)), ((uint64_t)(pattern.len)), ((char*)(pattern.data)), ((uint64_t)(0)));
        if (rc < 0) {
            return (slop_option_string){.has_value = 1, .value = snarl_string_regcomp_error_name(arena, (0 - rc))};
        } else {
            return (slop_option_string){.has_value = false};
        }
    }
}

int64_t snarl_string_string_char_count(slop_string s) {
    int64_t _retval = {0};
    {
        int64_t n = 0;
        int64_t i = 0;
        __auto_type len = string_len(s);
        while (i < len) {
            {
                __auto_type c = std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at string.slop:180:29"));
                if ((c < 128) || (c > 191)) {
                    n = (n + 1);
                }
            }
            i = (i + 1);
        }
        _retval = n;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= string_len(s))), "(<= $result (string-len s))");
    return _retval;
}

uint8_t snarl_string_term_has_string_form(slop_rdf_rdf_Term value_node) {
    __auto_type _mv_306 = value_node;
    switch (_mv_306.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_306.data.term_literal;
            return 1;
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type _ = _mv_306.data.term_iri;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t snarl_string_min_length_satisfied(slop_rdf_rdf_Term value_node, int64_t min_len) {
    return (snarl_string_term_has_string_form(value_node) && (snarl_string_string_char_count(snarl_string_term_string_value(value_node)) >= min_len));
}

uint8_t snarl_string_max_length_satisfied(slop_rdf_rdf_Term value_node, int64_t max_len) {
    return (snarl_string_term_has_string_form(value_node) && (snarl_string_string_char_count(snarl_string_term_string_value(value_node)) <= max_len));
}

uint8_t snarl_string_pattern_satisfied(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_string pattern, slop_string flags) {
    return (snarl_string_term_has_string_form(value_node) && snarl_string_regex_match_ffi(pattern, flags, snarl_string_term_string_value(value_node)));
}

uint8_t snarl_string_language_matches(slop_arena* arena, slop_string tag, slop_string range) {
    {
        __auto_type t = std_strlib_to_lower(arena, tag);
        __auto_type r = std_strlib_to_lower(arena, range);
        if (string_len(t) == 0) {
            return 0;
        } else if (string_eq(r, SLOP_STR("*"))) {
            return 1;
        } else if (string_eq(t, r)) {
            return 1;
        } else {
            return std_strlib_starts_with(t, string_concat(arena, r, SLOP_STR("-")));
        }
    }
}

uint8_t snarl_string_language_in(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs) {
    {
        __auto_type tag = snarl_string_term_lang(value_node);
        uint8_t found = 0;
        {
            __auto_type _coll = allowed_langs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type al = _coll.data[_i];
                if (snarl_string_language_matches(arena, tag, al)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_len >= 0)), "(>= min-len 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_min_length_satisfied(value_node, min_len)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_MIN_LENGTH_CONSTRAINT_COMPONENT, .severity = severity, .message = message})};
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
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_MAX_LENGTH_CONSTRAINT_COMPONENT, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_max_length_satisfied(value_node, max_len))), "(== (is-none $result) (max-length-satisfied value-node max-len))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_string flags, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_pattern_satisfied(arena, value_node, pattern, flags)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_PATTERN_CONSTRAINT_COMPONENT, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_pattern_satisfied(arena, value_node, pattern, flags))), "(== (is-none $result) (pattern-satisfied arena value-node pattern flags))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_langs).len)) > 0)), "(> (list-len allowed-langs) 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_string_language_in(arena, value_node, allowed_langs)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_LANGUAGE_IN_CONSTRAINT_COMPONENT, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_string_language_in(arena, value_node, allowed_langs))), "(== (is-none $result) (language-in arena value-node allowed-langs))");
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
    {
        __auto_type results = ((slop_list_snarl_types_ValidationResult){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type reported = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = value_nodes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type vn = _coll.data[_i];
                {
                    __auto_type lang = std_strlib_to_lower(arena, snarl_string_term_lang(vn));
                    if (string_len(lang) > 0) {
                        if (slop_map_has(seen, &(lang))) {
                            if (!(slop_map_has(reported, &(lang)))) {
                                (void)(({ slop_map_put(NULL, reported, &(lang), NULL, 0); }));
                                (void)(({ __auto_type _lst_p = &(results); __auto_type _item = (((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_UNIQUE_LANG_CONSTRAINT_COMPONENT, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        } else {
                            (void)(({ slop_map_put(NULL, seen, &(lang), NULL, 0); }));
                        }
                    }
                }
            }
        }
        return results;
    }
}

