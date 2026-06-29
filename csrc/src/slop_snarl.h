#ifndef SLOP_snarl_H
#define SLOP_snarl_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_data_graph.h"
#include "slop_types.h"
#include "slop_parse.h"
#include "slop_engine.h"
#include "slop_report.h"

#ifndef SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
SLOP_LIST_DEFINE(types_ValidationResult, slop_list_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

types_ValidatorConfig snarl_default_config(void);
types_ValidatorResult snarl_validate(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph);
types_ValidatorResult snarl_validate_with_config(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph, types_ValidatorConfig config);
types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, data_graph_SnarlDataGraph data_graph, index_IndexedGraph shapes_graph);
types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, data_graph_SnarlDataGraph data_graph, index_IndexedGraph shapes_graph, types_ValidatorConfig config);
uint8_t snarl_conforms(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph);
uint8_t snarl_conforms_data_graph(slop_arena* arena, data_graph_SnarlDataGraph data_graph, index_IndexedGraph shapes_graph);
slop_list_types_ValidationResult snarl_get_violations(slop_arena* arena, types_ValidationReport report);
slop_list_types_ValidationResult snarl_get_warnings(slop_arena* arena, types_ValidationReport report);
int64_t snarl_get_result_count(types_ValidationReport report);

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif


#endif
