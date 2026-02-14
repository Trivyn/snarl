#ifndef SLOP_other_H
#define SLOP_other_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_vocab.h"
#include "slop_types.h"

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

#ifndef SLOP_LIST_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_TYPES_SHACLPATH_DEFINED
SLOP_LIST_DEFINE(types_ShaclPath, slop_list_types_ShaclPath)
#endif

#ifndef SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
SLOP_LIST_DEFINE(types_ValidationResult, slop_list_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

slop_list_rdf_Term other_fixture_term_list_ab(slop_arena* arena);
slop_list_rdf_Term other_fixture_allowed_terms_abc(slop_arena* arena);
slop_list_types_ShaclPath other_fixture_allowed_path_name(slop_arena* arena);
index_IndexedGraph other_fixture_g_focus_name(slop_arena* arena);
index_IndexedGraph other_fixture_g_focus_name_age(slop_arena* arena);
slop_option_types_ValidationResult snarl_check_has_value(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, rdf_Term required_value, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_rdf_Term allowed_values, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_closed(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_types_ShaclPath allowed_paths, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define other_check_has_value snarl_check_has_value
#define other_check_in snarl_check_in
#define other_check_closed snarl_check_closed

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
