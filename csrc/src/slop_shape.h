#ifndef SLOP_shape_H
#define SLOP_shape_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"

#ifndef SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
SLOP_LIST_DEFINE(types_ValidationResult, slop_list_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

slop_option_types_ValidationResult snarl_check_node(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, uint8_t value_conforms, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_qualified_value_shape(slop_arena* arena, rdf_Term focus_node, int64_t conforming_count, int64_t q_min, slop_option_int q_max, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define shape_check_node snarl_check_node
#define shape_check_qualified_value_shape snarl_check_qualified_value_shape

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
