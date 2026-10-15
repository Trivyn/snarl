#include "../runtime/slop_runtime.h"
#include "slop_cardinality.h"

static const slop_string snarl_cardinality_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_cardinality_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

slop_option_snarl_types_ValidationResult snarl_check_min_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

slop_option_snarl_types_ValidationResult snarl_check_min_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((min_count >= 0)), "(>= min-count 0)");
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (value_count >= min_count) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_MIN_COUNT, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == (value_count >= min_count))), "(== (is-none $result) (>= value-count min-count))");
    return _retval;
}

slop_option_snarl_types_ValidationResult snarl_check_max_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((max_count >= 0)), "(>= max-count 0)");
    SLOP_PRE(((value_count >= 0)), "(>= value-count 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (value_count <= max_count) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = false}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_MAX_COUNT, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == (value_count <= max_count))), "(== (is-none $result) (<= value-count max-count))");
    return _retval;
}

