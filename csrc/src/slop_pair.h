#ifndef SLOP_pair_H
#define SLOP_pair_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_data_graph.h"
#include "slop_path.h"
#include "slop_xsd.h"
#include "slop_vocab.h"
#include "slop_types.h"

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

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

snarl_data_graph_SnarlDataGraph snarl_pair_fixture_g_focus_p2_a(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_pair_fixture_term_list_a(slop_arena* arena);
slop_list_snarl_types_ValidationResult snarl_check_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_disjoint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define snarl_pair_check_equals snarl_check_equals
#define snarl_pair_check_disjoint snarl_check_disjoint
#define snarl_pair_check_less_than snarl_check_less_than
#define snarl_pair_check_less_than_or_equals snarl_check_less_than_or_equals

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif


#endif
