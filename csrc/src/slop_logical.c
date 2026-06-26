#include "../runtime/slop_runtime.h"
#include "slop_logical.h"

static const slop_string logical_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string logical_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (conforms_to_ref) {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_NOT, .severity = severity, .message = message})};
    } else {
        return (slop_option_types_ValidationResult){.has_value = false};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == !(conforms_to_ref))), "(== (== $result (none)) (not conforms-to-ref))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (all_pass) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_AND, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == all_pass)), "(== (== $result (none)) all-pass)");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (any_pass) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_OR, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == any_pass)), "(== (== $result (none)) any-pass)");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (pass_count == 1) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_XONE, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == (pass_count == 1))), "(== (== $result (none)) (== pass-count 1))");
    return _retval;
}

