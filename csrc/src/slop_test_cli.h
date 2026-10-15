#ifndef SLOP_test_cli_H
#define SLOP_test_cli_H

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
#include "slop_parse.h"
#include "slop_ttl.h"
#include "slop_data_graph.h"
#include "slop_snarl.h"
#include "slop_types.h"
#include "slop_strlib.h"

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_IndexedGraph, slop_option_slop_rdf_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
#endif

slop_option_slop_rdf_index_IndexedGraph snarl_cli_tests_test_cli_load_test_graph(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_conforms(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count);
uint8_t snarl_cli_tests_test_cli_assert_has_violations(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t snarl_cli_tests_test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring);
uint8_t snarl_cli_tests_test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring);
void snarl_cli_tests_test_cli_reset_test_arena(slop_arena* arena);
void snarl_cli_tests_test_cli_poison_test_arena(slop_arena* arena, int64_t nbytes);
int64_t snarl_cli_tests_test_cli_path_depth_of(slop_arena* arena, slop_string path, slop_string shape_iri);
uint8_t snarl_cli_tests_test_cli_assert_validates(slop_arena* arena, slop_string path);
uint8_t snarl_cli_tests_test_cli_soak_one(slop_arena* arena, slop_string fixture);
uint8_t snarl_cli_tests_test_cli_assert_depth(slop_arena* arena, slop_string path, slop_string shape_iri, int64_t expected);
uint8_t snarl_cli_tests_test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count);
uint8_t snarl_cli_tests_test_cli_test_empty_graph(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_valid_person(slop_arena* arena);
slop_option_snarl_data_graph_SnarlDataGraph snarl_cli_tests_test_cli_load_streamed_data_graph(slop_arena* arena, slop_string path);
int64_t snarl_cli_tests_test_cli_result_summary(snarl_types_ValidatorResult r);
uint8_t snarl_cli_tests_test_cli_assert_streamed_matches_indexed(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_employee(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_streamed_data_graph_rdf12(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_rdf12_annotation_block(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cardinality_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_datatype_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_class_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_nodekind_violation(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_target_node(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_multiple_violations(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_report_string(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_employee_directory(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_product_catalog(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_address_book(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_valid_library(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_multi_shape(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_pattern_unicode(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_subclass_class_conforms(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_subclass_class(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_vacuous_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_self_loop(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_mutual(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_chain(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_diamond(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_acyclic(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_recursive_person_cyclic(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_inverse_self(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_in_list(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_legitimate(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_node(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_and(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_xone(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_not(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_acyclic_control(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_propshape_swallowed_control(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_qualified_value_shape(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_and(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_or(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_xone(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_language_in(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_list_ignored_properties(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_max_errors_precedence(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_linear_50000(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_path_shared_dag_30(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_structural(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_purity(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_poisoned_arena(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_guard_revisit_after_unwind(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_diamond_poisoned(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_cycle_acyclic_controls_poisoned(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_over_budget(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_path_depth_at_budget(slop_arena* arena);
uint8_t snarl_cli_tests_test_cli_test_diverse_input_soak(slop_arena* arena);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_INDEXEDGRAPH_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_IndexedGraph, slop_option_slop_rdf_index_IndexedGraph)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
#endif


#endif
