#ifndef SLOP_report_H
#define SLOP_report_H

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
#include "slop_vocab.h"
#include "slop_strlib.h"
#include "slop_types.h"

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

slop_list_snarl_types_ShaclPath snarl_report_fixture_path_list_ab(slop_arena* arena);
void snarl_print_report(slop_arena* arena, snarl_types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, snarl_types_ValidationReport report);
slop_rdf_index_IndexedGraph snarl_report_to_graph(slop_arena* arena, snarl_types_ValidationReport report);
slop_string snarl_severity_to_string(snarl_types_Severity sev);
slop_string snarl_term_to_display_string(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string snarl_report_sequence_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath steps);
slop_string snarl_report_alternative_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath alts);
slop_string snarl_path_to_display_string(slop_arena* arena, snarl_types_ShaclPath p);

/* Function name aliases for C interop */
#define snarl_report_print_report snarl_print_report
#define snarl_report_report_to_string snarl_report_to_string
#define snarl_report_report_to_graph snarl_report_to_graph
#define snarl_report_severity_to_string snarl_severity_to_string
#define snarl_report_term_to_display_string snarl_term_to_display_string
#define snarl_report_path_to_display_string snarl_path_to_display_string

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif


#endif
