#include "../runtime/slop_runtime.h"
#include "slop_cardinality.h"

slop_option_types_ValidationResult snarl_check_min_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

slop_option_types_ValidationResult snarl_check_min_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_count >= 0)), "(>= min-count 0)");
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    if ((value_count >= min_count)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MIN_COUNT, .severity = severity, .message = message})};
    }
}

slop_option_types_ValidationResult snarl_check_max_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((max_count >= 0)), "(>= max-count 0)");
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    if ((value_count <= max_count)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MAX_COUNT, .severity = severity, .message = message})};
    }
}

