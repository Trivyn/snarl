#ifndef SLOP_snarl_H
#define SLOP_snarl_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_data_graph.h"
#include "slop_types.h"
#include "slop_parse.h"
#include "slop_engine.h"
#include "slop_rules.h"
#include "slop_report.h"

typedef struct snarl_ValidationOutcome snarl_ValidationOutcome;

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

struct snarl_ValidationOutcome {
    snarl_types_ValidatorResult result;
    snarl_data_graph_SnarlDataGraph graph;
    slop_list_slop_rdf_rdf_Triple inferred;
};
typedef struct snarl_ValidationOutcome snarl_ValidationOutcome;

#ifndef SLOP_OPTION_SNARL_VALIDATIONOUTCOME_DEFINED
#define SLOP_OPTION_SNARL_VALIDATIONOUTCOME_DEFINED
SLOP_OPTION_DEFINE(snarl_ValidationOutcome, slop_option_snarl_ValidationOutcome)
#endif

#ifndef SLOP_RESULT_SNARL_TYPES_SHAPESGRAPH_STRING_DEFINED
#define SLOP_RESULT_SNARL_TYPES_SHAPESGRAPH_STRING_DEFINED
typedef struct { bool is_ok; union { snarl_types_ShapesGraph ok; slop_string err; } data; } slop_result_snarl_types_ShapesGraph_string;
#endif

snarl_types_ValidatorConfig snarl_default_config(void);
snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_ValidationOutcome snarl_validate_data_graph_with_inference(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_result_snarl_types_ShapesGraph_string snarl_prepare_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_rules_InferResult snarl_infer(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
uint8_t snarl_conforms(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
uint8_t snarl_conforms_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
slop_list_snarl_types_ValidationResult snarl_get_violations(slop_arena* arena, snarl_types_ValidationReport report);
slop_list_snarl_types_ValidationResult snarl_get_warnings(slop_arena* arena, snarl_types_ValidationReport report);
int64_t snarl_get_result_count(snarl_types_ValidationReport report);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_SNARL_VALIDATIONOUTCOME_DEFINED
#define SLOP_OPTION_SNARL_VALIDATIONOUTCOME_DEFINED
SLOP_OPTION_DEFINE(snarl_ValidationOutcome, slop_option_snarl_ValidationOutcome)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif


#endif
