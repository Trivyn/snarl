#ifndef SLOP_value_type_H
#define SLOP_value_type_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_target.h"

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

index_IndexedGraph value_type_fixture_g_focus_is_person(slop_arena* arena);
index_IndexedGraph value_type_fixture_g_empty(slop_arena* arena);
slop_option_types_ValidationResult snarl_check_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_class, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
uint8_t value_type_datatype_matches(rdf_Term value_node, rdf_Term required_datatype);
slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
uint8_t value_type_node_kind_matches(types_NodeKind required, rdf_TermKind kind);
slop_option_types_ValidationResult snarl_check_node_kind(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, types_NodeKind required_kind, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
types_ValidationResult value_type_make_vr(slop_arena* arena, rdf_Term focus_node, slop_option_types_ShaclPath path, rdf_Term value_node, rdf_Term shape_id, slop_string component, types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define value_type_check_class snarl_check_class
#define value_type_check_datatype snarl_check_datatype
#define value_type_check_node_kind snarl_check_node_kind

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
