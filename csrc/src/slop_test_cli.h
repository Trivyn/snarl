#ifndef SLOP_test_cli_H
#define SLOP_test_cli_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_ttl.h"
#include "slop_snarl.h"
#include "slop_types.h"

#ifndef SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(index_IndexedGraph, slop_option_index_IndexedGraph)
#endif

slop_option_index_IndexedGraph test_cli_load_test_graph(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count);
uint8_t test_cli_assert_has_violations(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count);
uint8_t test_cli_test_empty_graph(slop_arena* arena);
uint8_t test_cli_test_valid_person(slop_arena* arena);
uint8_t test_cli_test_rdf12_annotation_block(slop_arena* arena);
uint8_t test_cli_test_cardinality_violation(slop_arena* arena);
uint8_t test_cli_test_datatype_violation(slop_arena* arena);
uint8_t test_cli_test_class_violation(slop_arena* arena);
uint8_t test_cli_test_nodekind_violation(slop_arena* arena);
uint8_t test_cli_test_target_node(slop_arena* arena);
uint8_t test_cli_test_multiple_violations(slop_arena* arena);
uint8_t test_cli_test_report_string(slop_arena* arena);
uint8_t test_cli_test_employee_directory(slop_arena* arena);
uint8_t test_cli_test_product_catalog(slop_arena* arena);
uint8_t test_cli_test_address_book(slop_arena* arena);
uint8_t test_cli_test_valid_library(slop_arena* arena);
uint8_t test_cli_test_multi_shape(slop_arena* arena);
uint8_t test_cli_test_subclass_class_conforms(slop_arena* arena);
uint8_t test_cli_test_subclass_class(slop_arena* arena);
uint8_t test_cli_test_vacuous_or(slop_arena* arena);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(index_IndexedGraph, slop_option_index_IndexedGraph)
#endif


#endif
