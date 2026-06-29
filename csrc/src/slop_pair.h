#ifndef SLOP_pair_H
#define SLOP_pair_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_data_graph.h"
#include "slop_path.h"
#include "slop_xsd.h"
#include "slop_vocab.h"
#include "slop_types.h"

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
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

data_graph_SnarlDataGraph pair_fixture_g_focus_p2_a(slop_arena* arena);
slop_list_rdf_Term pair_fixture_term_list_a(slop_arena* arena);
slop_list_types_ValidationResult snarl_check_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_disjoint(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, data_graph_SnarlDataGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define pair_check_equals snarl_check_equals
#define pair_check_disjoint snarl_check_disjoint
#define pair_check_less_than snarl_check_less_than
#define pair_check_less_than_or_equals snarl_check_less_than_or_equals

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
