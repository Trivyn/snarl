#include "../runtime/slop_runtime.h"
#include "slop_string.h"

slop_string string_term_string_value(rdf_Term t);
slop_string string_term_lang(rdf_Term t);
uint8_t string_term_is_literal(rdf_Term t);
uint8_t string_regex_match_ffi(slop_arena* arena, slop_string pattern, slop_string input);
slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_string string_term_string_value(rdf_Term t) {
    __auto_type _mv_101 = t;
    switch (_mv_101.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_101.data.term_literal;
            return lit.value;
        }
        case rdf_Term_term_iri:
        {
            __auto_type iri = _mv_101.data.term_iri;
            return iri.value;
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_101.data.term_blank;
            return SLOP_STR("");
        }
    }
}

slop_string string_term_lang(rdf_Term t) {
    __auto_type _mv_102 = t;
    switch (_mv_102.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_102.data.term_literal;
            __auto_type _mv_103 = lit.lang;
            if (_mv_103.has_value) {
                __auto_type lang = _mv_103.value;
                return lang;
            } else if (!_mv_103.has_value) {
                return SLOP_STR("");
            }
        }
        default: {
            return SLOP_STR("");
        }
    }
}

uint8_t string_term_is_literal(rdf_Term t) {
    __auto_type _mv_104 = t;
    switch (_mv_104.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_104.data.term_literal;
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
        if ((regcomp(preg, ((char*)(pattern.data)), 1) != 0)) {
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

slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_len >= 0)), "(>= min-len 0)");
    slop_option_types_ValidationResult _retval = {0};
    {
        __auto_type s = ({ __auto_type _mv = value_node; slop_string _mr = {0}; switch (_mv.tag) { case rdf_Term_term_literal: { __auto_type lit = _mv.data.term_literal; _mr = lit.value; break; } case rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = iri.value; break; } default: { _mr = SLOP_STR(""); break; }  } _mr; });
        if ((string_len(s) >= min_len)) {
            return (slop_option_types_ValidationResult){.has_value = false};
        } else {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MIN_LENGTH, .severity = severity, .message = message})};
        }
    }
    SLOP_POST((((_retval != ((slop_option_types_ValidationResult){.has_value = false})) || (string_len(string_term_string_value(value_node)) >= min_len))), "(or (!= $result (none)) (>= (string-len (term-string-value value-node)) min-len))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((max_len >= 0)), "(>= max-len 0)");
    slop_option_types_ValidationResult _retval = {0};
    {
        __auto_type s = ({ __auto_type _mv = value_node; slop_string _mr = {0}; switch (_mv.tag) { case rdf_Term_term_literal: { __auto_type lit = _mv.data.term_literal; _mr = lit.value; break; } case rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = iri.value; break; } default: { _mr = SLOP_STR(""); break; }  } _mr; });
        if ((string_len(s) <= max_len)) {
            return (slop_option_types_ValidationResult){.has_value = false};
        } else {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MAX_LENGTH, .severity = severity, .message = message})};
        }
    }
    SLOP_POST((((_retval != ((slop_option_types_ValidationResult){.has_value = false})) || (string_len(string_term_string_value(value_node)) <= max_len))), "(or (!= $result (none)) (<= (string-len (term-string-value value-node)) max-len))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((string_len(pattern) > 0)), "(> (string-len pattern) 0)");
    {
        __auto_type s = ({ __auto_type _mv = value_node; slop_string _mr = {0}; switch (_mv.tag) { case rdf_Term_term_literal: { __auto_type lit = _mv.data.term_literal; _mr = lit.value; break; } case rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = iri.value; break; } default: { _mr = SLOP_STR(""); break; }  } _mr; });
        if (string_regex_match_ffi(arena, pattern, s)) {
            return (slop_option_types_ValidationResult){.has_value = false};
        } else {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_PATTERN, .severity = severity, .message = message})};
        }
    }
}

slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((((int64_t)((allowed_langs).len)) > 0)), "(> (list-len allowed-langs) 0)");
    slop_option_types_ValidationResult _retval = {0};
    __auto_type _mv_105 = value_node;
    switch (_mv_105.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_105.data.term_literal;
            __auto_type _mv_106 = lit.lang;
            if (_mv_106.has_value) {
                __auto_type lang = _mv_106.value;
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
            } else if (!_mv_106.has_value) {
                return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
            }
        }
        default: {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_LANGUAGE_IN, .severity = severity, .message = message})};
        }
    }
    return _retval;
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
                __auto_type _mv_107 = vn;
                switch (_mv_107.tag) {
                    case rdf_Term_term_literal:
                    {
                        __auto_type lit = _mv_107.data.term_literal;
                        __auto_type _mv_108 = lit.lang;
                        if (_mv_108.has_value) {
                            __auto_type lang = _mv_108.value;
                            if ((slop_map_get(seen, &(lang)) != NULL)) {
                                ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = vn}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_UNIQUE_LANG, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(lang), &_dummy); });
                            }
                        } else if (!_mv_108.has_value) {
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

