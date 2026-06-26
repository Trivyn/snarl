#ifndef SLOP_string_H
#define SLOP_string_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include <regex.h>

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

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

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

slop_string string_term_string_value(rdf_Term t);
slop_string string_term_lang(rdf_Term t);
uint8_t string_term_is_literal(rdf_Term t);
uint8_t string_regex_match_ffi(slop_arena* arena, slop_string pattern, slop_string input);
uint8_t string_min_length_satisfied(rdf_Term value_node, int64_t min_len);
uint8_t string_max_length_satisfied(rdf_Term value_node, int64_t max_len);
uint8_t string_pattern_satisfied(slop_arena* arena, rdf_Term value_node, slop_string pattern);
slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_string string_fixture_allowed_langs(slop_arena* arena);
slop_list_rdf_Term string_fixture_unique_langs(slop_arena* arena);
slop_list_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define string_check_min_length snarl_check_min_length
#define string_check_max_length snarl_check_max_length
#define string_check_pattern snarl_check_pattern
#define string_check_language_in snarl_check_language_in
#define string_check_unique_lang snarl_check_unique_lang

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif


#endif
