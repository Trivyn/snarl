#ifndef SLOP_value_type_H
#define SLOP_value_type_H

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
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_target.h"

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_focus_is_person(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_empty(slop_arena* arena);
slop_option_snarl_types_ValidationResult snarl_check_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
snarl_types_ValidationResult snarl_value_type_make_class_violation(slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_value_type_check_class_with_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
uint8_t snarl_value_type_datatype_matches(slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype);
slop_option_snarl_types_ValidationResult snarl_check_datatype(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
uint8_t snarl_value_type_node_kind_matches(snarl_types_NodeKind required, slop_rdf_rdf_TermKind kind);
slop_option_snarl_types_ValidationResult snarl_check_node_kind(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_NodeKind required_kind, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
snarl_types_ValidationResult snarl_value_type_make_vr(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term shape_id, slop_string component, snarl_types_Severity severity, slop_option_string message);

/* Function name aliases for C interop */
#define snarl_value_type_check_class snarl_check_class
#define snarl_value_type_check_datatype snarl_check_datatype
#define snarl_value_type_check_node_kind snarl_check_node_kind

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif


#endif
