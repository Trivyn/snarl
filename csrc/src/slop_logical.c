#include "../runtime/slop_runtime.h"
#include "slop_logical.h"

slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    if (conforms_to_ref) {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_NOT, .severity = severity, .message = message})};
    } else {
        return (slop_option_types_ValidationResult){.has_value = false};
    }
}

slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    if (all_pass) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_AND, .severity = severity, .message = message})};
    }
}

slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    if (any_pass) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_OR, .severity = severity, .message = message})};
    }
}

slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    if ((pass_count == 1)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_XONE, .severity = severity, .message = message})};
    }
}

