#ifndef SLOP_report_H
#define SLOP_report_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_vocab.h"
#include "slop_strlib.h"
#include "slop_types.h"

#ifndef SLOP_LIST_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_TYPES_SHACLPATH_DEFINED
SLOP_LIST_DEFINE(types_ShaclPath, slop_list_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

void snarl_print_report(slop_arena* arena, types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, types_ValidationReport report);
index_IndexedGraph snarl_report_to_graph(slop_arena* arena, types_ValidationReport report);
slop_string snarl_severity_to_string(types_Severity sev);
slop_string snarl_term_to_display_string(slop_arena* arena, rdf_Term t);
slop_string report_sequence_to_display_string(slop_arena* arena, slop_list_types_ShaclPath steps);
slop_string report_alternative_to_display_string(slop_arena* arena, slop_list_types_ShaclPath alts);
slop_string snarl_path_to_display_string(slop_arena* arena, types_ShaclPath p);

/* Function name aliases for C interop */
#define report_print_report snarl_print_report
#define report_report_to_string snarl_report_to_string
#define report_report_to_graph snarl_report_to_graph
#define report_severity_to_string snarl_severity_to_string
#define report_term_to_display_string snarl_term_to_display_string
#define report_path_to_display_string snarl_path_to_display_string

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif


#endif
