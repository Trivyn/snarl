#include "../runtime/slop_runtime.h"
#include "slop_shape.h"

static const slop_string shape_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string shape_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string shape_EX_VALUE = SLOP_STR("http://example.org/value");

slop_option_types_ValidationResult snarl_check_node(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, uint8_t value_conforms, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_qualified_value_shape(slop_arena* arena, rdf_Term focus_node, int64_t conforming_count, int64_t q_min, slop_option_int q_max, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_option_types_ValidationResult snarl_check_node(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, uint8_t value_conforms, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_conforms) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_NODE, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == value_conforms)), "(== (== $result (none)) value-conforms)");
    return _retval;
}

slop_list_types_ValidationResult snarl_check_qualified_value_shape(slop_arena* arena, rdf_Term focus_node, int64_t conforming_count, int64_t q_min, slop_option_int q_max, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((conforming_count >= 0)), "(>= conforming-count 0)");
    SLOP_PRE(((q_min >= 0)), "(>= q-min 0)");
    slop_list_types_ValidationResult _retval = {0};
    {
        __auto_type results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 });
        if (conforming_count < q_min) {
            ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_QUALIFIED_VALUE_SHAPE, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        __auto_type _mv_103 = q_max;
        if (_mv_103.has_value) {
            __auto_type max_val = _mv_103.value;
            if (conforming_count > max_val) {
                ({ __auto_type _lst_p = &(results); __auto_type _item = (((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_QUALIFIED_VALUE_SHAPE, .severity = severity, .message = message})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        } else if (!_mv_103.has_value) {
        }
        _retval = results;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    SLOP_POST(((((int64_t)((_retval).len)) <= 2)), "(<= (list-len $result) 2)");
    return _retval;
}

