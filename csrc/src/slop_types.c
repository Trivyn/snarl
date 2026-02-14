#include "../runtime/slop_runtime.h"
#include "slop_types.h"

static const slop_string types_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string types_EX_SHAPE = SLOP_STR("http://example.org/Shape1");

types_ValidationResult types_fixture_violation(slop_arena* arena);
types_ValidatorConfig types_default_validator_config(void);
types_ValidationReport types_make_validation_report(slop_arena* arena);
types_ValidationReport types_report_add_result(slop_arena* arena, types_ValidationReport report, types_ValidationResult result);
uint8_t types_report_conforms(types_ValidationReport report);

types_ValidationResult types_fixture_violation(slop_arena* arena) {
    return ((types_ValidationResult){.focus_node = rdf_make_iri(arena, types_EX_FOCUS), .result_path = (slop_option_types_ShaclPath){.has_value = false}, .value = (slop_option_rdf_Term){.has_value = false}, .source_shape = rdf_make_iri(arena, types_EX_SHAPE), .source_constraint_component = vocab_SHACL_CLASS, .severity = types_Severity_severity_violation, .message = (slop_option_string){.has_value = false}});
}

types_ValidatorConfig types_default_validator_config(void) {
    types_ValidatorConfig _retval = {0};
    _retval = ((types_ValidatorConfig){.verbose = 0, .max_errors = 0, .include_warnings = 1, .include_infos = 1});
    SLOP_POST(((_retval.verbose == 0)), "(== (. $result verbose) false)");
    SLOP_POST(((_retval.max_errors == 0)), "(== (. $result max-errors) 0)");
    SLOP_POST(((_retval.include_warnings == 1)), "(== (. $result include-warnings) true)");
    SLOP_POST(((_retval.include_infos == 1)), "(== (. $result include-infos) true)");
    return _retval;
}

types_ValidationReport types_make_validation_report(slop_arena* arena) {
    types_ValidationReport _retval = {0};
    _retval = ((types_ValidationReport){.conforms = 1, .results = ((slop_list_types_ValidationResult){ .data = (types_ValidationResult*)slop_arena_alloc(arena, 16 * sizeof(types_ValidationResult)), .len = 0, .cap = 16 })});
    SLOP_POST(((_retval.conforms == 1)), "(== (. $result conforms) true)");
    SLOP_POST(((((int64_t)((_retval.results).len)) == 0)), "(== (list-len (. $result results)) 0)");
    return _retval;
}

types_ValidationReport types_report_add_result(slop_arena* arena, types_ValidationReport report, types_ValidationResult result) {
    types_ValidationReport _retval = {0};
    ({ __auto_type _lst_p = &(report.results); __auto_type _item = (result); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    {
        __auto_type still_conforms = 0;
        _retval = ((types_ValidationReport){.conforms = still_conforms, .results = report.results});
    }
    SLOP_POST(((((int64_t)((_retval.results).len)) == (((int64_t)((report.results).len)) + 1))), "(== (list-len (. $result results)) (+ (list-len (. report results)) 1))");
    SLOP_POST(((_retval.conforms == 0)), "(== (. $result conforms) false)");
    return _retval;
}

uint8_t types_report_conforms(types_ValidationReport report) {
    uint8_t _retval = {0};
    _retval = report.conforms;
    SLOP_POST(((_retval == report.conforms)), "(== $result (. report conforms))");
    return _retval;
}

