#ifndef SLOP_main_H
#define SLOP_main_H

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
#include "slop_ttl.h"
#include "slop_common.h"
#include "slop_snarl.h"
#include "slop_report.h"
#include "slop_strlib.h"
#include <string.h>
#include <slop_runtime.h>

typedef struct snarl_cli_main_CliArgs snarl_cli_main_CliArgs;

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_IndexedGraph, slop_option_slop_rdf_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
#endif

struct snarl_cli_main_CliArgs {
    slop_option_string data_file;
    slop_option_string shapes_file;
    slop_option_string emit_file;
    uint8_t quiet;
    int64_t max_errors;
    uint8_t no_warnings;
    uint8_t no_infos;
    uint8_t show_help;
    uint8_t show_version;
};
typedef struct snarl_cli_main_CliArgs snarl_cli_main_CliArgs;

#ifndef SLOP_OPTION_SNARL_CLI_MAIN_CLIARGS_DEFINED
#define SLOP_OPTION_SNARL_CLI_MAIN_CLIARGS_DEFINED
SLOP_OPTION_DEFINE(snarl_cli_main_CliArgs, slop_option_snarl_cli_main_CliArgs)
#endif

void snarl_cli_main_print_elapsed(slop_arena* arena, int64_t elapsed);
slop_string snarl_cli_main_argv_to_string(uint8_t** argv, int64_t index);
snarl_cli_main_CliArgs snarl_cli_main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv);
void snarl_cli_main_print_usage(void);
void snarl_cli_main_print_ttl_error(slop_arena* arena, slop_string path, slop_rdf_ttl_TtlFileError e);
slop_option_slop_rdf_index_IndexedGraph snarl_cli_main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet);
slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_SNARL_CLI_MAIN_CLIARGS_DEFINED
#define SLOP_OPTION_SNARL_CLI_MAIN_CLIARGS_DEFINED
SLOP_OPTION_DEFINE(snarl_cli_main_CliArgs, slop_option_snarl_cli_main_CliArgs)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_IndexedGraph, slop_option_slop_rdf_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
#endif


#endif
