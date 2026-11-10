#include "../runtime/slop_runtime.h"
#include "slop_expression.h"

static const slop_string snarl_expression_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_expression_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string snarl_expression_EX_EXPR = SLOP_STR("http://example.org/expr");

slop_list_slop_rdf_rdf_Term snarl_expression_fixture_outputs_true(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_expression_fixture_outputs_false(slop_arena* arena);
uint8_t snarl_expression_term_is_true(slop_rdf_rdf_Term t);
uint8_t snarl_expression_outputs_are_true(slop_list_slop_rdf_rdf_Term outputs);
slop_option_snarl_types_ValidationResult snarl_check_expression(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_slop_rdf_rdf_Term outputs, slop_rdf_rdf_Term expression, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

slop_list_slop_rdf_rdf_Term snarl_expression_fixture_outputs_true(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("true"), (slop_option_string){.has_value = 1, .value = slop_rdf_vocab_XSD_BOOLEAN}, ((slop_option_string){.has_value = false}))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return terms;
    }
}

slop_list_slop_rdf_rdf_Term snarl_expression_fixture_outputs_false(slop_arena* arena) {
    {
        __auto_type terms = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(terms); __auto_type _item = (rdf_make_literal(arena, SLOP_STR("false"), (slop_option_string){.has_value = 1, .value = slop_rdf_vocab_XSD_BOOLEAN}, ((slop_option_string){.has_value = false}))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return terms;
    }
}

uint8_t snarl_expression_term_is_true(slop_rdf_rdf_Term t) {
    __auto_type _mv_293 = t;
    switch (_mv_293.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_293.data.term_literal;
            __auto_type _mv_294 = lit.datatype;
            if (_mv_294.has_value) {
                __auto_type dt = _mv_294.value;
                return (string_eq(dt, slop_rdf_vocab_XSD_BOOLEAN) && (string_eq(lit.value, SLOP_STR("true")) || string_eq(lit.value, SLOP_STR("1"))));
            } else if (!_mv_294.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return 0;
        }
    }
}

uint8_t snarl_expression_outputs_are_true(slop_list_slop_rdf_rdf_Term outputs) {
    if (((int64_t)((outputs).len)) == 1) {
        __auto_type _mv_295 = ({ __auto_type _lst = outputs; size_t _idx = (size_t)0; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_295.has_value) {
            __auto_type t = _mv_295.value;
            return snarl_expression_term_is_true(t);
        } else if (!_mv_295.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else {
        return 0;
    }
}

slop_option_snarl_types_ValidationResult snarl_check_expression(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_slop_rdf_rdf_Term outputs, slop_rdf_rdf_Term expression, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_expression_outputs_are_true(outputs)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = snarl_af_vocab_SHACL_EXPRESSION_CONSTRAINT_COMPONENT, .severity = severity, .message = message, .source_constraint = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = expression}})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_expression_outputs_are_true(outputs))), "(== (is-none $result) (outputs-are-true outputs))");
    return _retval;
}

