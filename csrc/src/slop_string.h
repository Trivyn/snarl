#ifndef SLOP_string_H
#define SLOP_string_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include <snarl_regex.h>

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

slop_string snarl_string_term_string_value(slop_rdf_rdf_Term t);
slop_string snarl_string_term_lang(slop_rdf_rdf_Term t);
uint8_t snarl_string_term_is_literal(slop_rdf_rdf_Term t);
uint8_t snarl_string_regex_match_ffi(slop_string pattern, slop_string input);
uint8_t snarl_string_min_length_satisfied(slop_rdf_rdf_Term value_node, int64_t min_len);
uint8_t snarl_string_max_length_satisfied(slop_rdf_rdf_Term value_node, int64_t max_len);
uint8_t snarl_string_pattern_satisfied(slop_arena* arena, slop_rdf_rdf_Term value_node, slop_string pattern);
slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t max_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_string snarl_string_fixture_allowed_langs(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_string_fixture_unique_langs(slop_arena* arena);
slop_list_snarl_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define snarl_string_check_min_length snarl_check_min_length
#define snarl_string_check_max_length snarl_check_max_length
#define snarl_string_check_pattern snarl_check_pattern
#define snarl_string_check_language_in snarl_check_language_in
#define snarl_string_check_unique_lang snarl_check_unique_lang

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif


#endif
