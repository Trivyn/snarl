#ifndef SLOP_logical_H
#define SLOP_logical_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
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

slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define logical_check_not snarl_check_not
#define logical_check_and snarl_check_and
#define logical_check_or snarl_check_or
#define logical_check_xone snarl_check_xone

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
