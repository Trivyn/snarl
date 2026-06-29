#ifndef SLOP_main_H
#define SLOP_main_H

#include "../runtime/slop_runtime.h"
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

typedef struct main_CliArgs main_CliArgs;

#ifndef SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(index_IndexedGraph, slop_option_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataGraph, slop_option_data_graph_SnarlDataGraph)
#endif

struct main_CliArgs {
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
typedef struct main_CliArgs main_CliArgs;

#ifndef SLOP_OPTION_MAIN_CLIARGS_DEFINED
#define SLOP_OPTION_MAIN_CLIARGS_DEFINED
SLOP_OPTION_DEFINE(main_CliArgs, slop_option_main_CliArgs)
#endif

void main_print_elapsed(slop_arena* arena, int64_t elapsed);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
main_CliArgs main_parse_args(slop_arena* arena, int64_t argc, uint8_t** argv);
void main_print_usage(void);
void main_print_ttl_error(slop_arena* arena, slop_string path, ttl_TtlFileError e);
slop_option_index_IndexedGraph main_load_graph(slop_arena* arena, slop_string path, uint8_t quiet);
slop_option_data_graph_SnarlDataGraph main_load_data_graph(slop_arena* arena, slop_string path, uint8_t quiet);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_MAIN_CLIARGS_DEFINED
#define SLOP_OPTION_MAIN_CLIARGS_DEFINED
SLOP_OPTION_DEFINE(main_CliArgs, slop_option_main_CliArgs)
#endif

#ifndef SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(index_IndexedGraph, slop_option_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataGraph, slop_option_data_graph_SnarlDataGraph)
#endif


#endif
