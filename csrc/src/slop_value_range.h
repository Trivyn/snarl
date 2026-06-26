#ifndef SLOP_value_range_H
#define SLOP_value_range_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_xsd.h"
#include "slop_vocab.h"
#include "slop_types.h"

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

uint8_t value_range_min_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_max_inclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_min_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
uint8_t value_range_max_exclusive_satisfied(slop_arena* arena, rdf_Term value_node, rdf_Term limit);
slop_option_types_ValidationResult snarl_check_min_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define value_range_check_min_inclusive snarl_check_min_inclusive
#define value_range_check_max_inclusive snarl_check_max_inclusive
#define value_range_check_min_exclusive snarl_check_min_exclusive
#define value_range_check_max_exclusive snarl_check_max_exclusive

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
