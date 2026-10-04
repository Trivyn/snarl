#include "../runtime/slop_runtime.h"
#include "slop_value_range.h"

static const slop_string value_range_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string value_range_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

uint8_t value_range_min_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_max_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_min_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_max_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
slop_option_types_ValidationResult snarl_check_min_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

uint8_t value_range_min_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit) {
    __auto_type _mv_283 = xsd_compare(arena, value_node, limit);
    switch (_mv_283) {
        case xsd_XsdCompareResult_xsd_compare_equal: {
            return 1;
            break;
        }
        case xsd_XsdCompareResult_xsd_compare_greater: {
            return 1;
            break;
        }
        default: {
            return 0;
            break;
        }
    }
}

uint8_t value_range_max_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit) {
    __auto_type _mv_284 = xsd_compare(arena, value_node, limit);
    switch (_mv_284) {
        case xsd_XsdCompareResult_xsd_compare_equal: {
            return 1;
            break;
        }
        case xsd_XsdCompareResult_xsd_compare_less: {
            return 1;
            break;
        }
        default: {
            return 0;
            break;
        }
    }
}

uint8_t value_range_min_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit) {
    __auto_type _mv_285 = xsd_compare(arena, value_node, limit);
    switch (_mv_285) {
        case xsd_XsdCompareResult_xsd_compare_greater: {
            return 1;
            break;
        }
        default: {
            return 0;
            break;
        }
    }
}

uint8_t value_range_max_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit) {
    __auto_type _mv_286 = xsd_compare(arena, value_node, limit);
    switch (_mv_286) {
        case xsd_XsdCompareResult_xsd_compare_less: {
            return 1;
            break;
        }
        default: {
            return 0;
            break;
        }
    }
}

slop_option_types_ValidationResult snarl_check_min_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_range_min_inclusive_satisfied(arena, value_node, limit)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MIN_INCLUSIVE, .severity = severity, .message = message})};
    }
    SLOP_POST((((!((_retval).has_value)) == value_range_min_inclusive_satisfied(arena, value_node, limit))), "(== (is-none $result) (min-inclusive-satisfied arena value-node limit))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_max_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_range_max_inclusive_satisfied(arena, value_node, limit)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MAX_INCLUSIVE, .severity = severity, .message = message})};
    }
    SLOP_POST((((!((_retval).has_value)) == value_range_max_inclusive_satisfied(arena, value_node, limit))), "(== (is-none $result) (max-inclusive-satisfied arena value-node limit))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_min_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_range_min_exclusive_satisfied(arena, value_node, limit)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MIN_EXCLUSIVE, .severity = severity, .message = message})};
    }
    SLOP_POST((((!((_retval).has_value)) == value_range_min_exclusive_satisfied(arena, value_node, limit))), "(== (is-none $result) (min-exclusive-satisfied arena value-node limit))");
    return _retval;
}

slop_option_types_ValidationResult snarl_check_max_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_range_max_exclusive_satisfied(arena, value_node, limit)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_MAX_EXCLUSIVE, .severity = severity, .message = message})};
    }
    SLOP_POST((((!((_retval).has_value)) == value_range_max_exclusive_satisfied(arena, value_node, limit))), "(== (is-none $result) (max-exclusive-satisfied arena value-node limit))");
    return _retval;
}

