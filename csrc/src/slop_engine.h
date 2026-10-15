#ifndef SLOP_engine_H
#define SLOP_engine_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_strlib.h"
#include "slop_data_graph.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_target.h"
#include "slop_path.h"
#include "slop_value_type.h"
#include "slop_cardinality.h"
#include "slop_value_range.h"
#include "slop_string.h"
#include "slop_other.h"
#include "slop_pair.h"
#include "slop_logical.h"
#include "slop_shape.h"

typedef struct snarl_engine_CycleGuard snarl_engine_CycleGuard;

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

struct snarl_engine_CycleGuard {
    slop_map* pairs;
    slop_map* depth;
    slop_map* errors;
};
typedef struct snarl_engine_CycleGuard snarl_engine_CycleGuard;

#ifndef SLOP_OPTION_SNARL_ENGINE_CYCLEGUARD_DEFINED
#define SLOP_OPTION_SNARL_ENGINE_CYCLEGUARD_DEFINED
SLOP_OPTION_DEFINE(snarl_engine_CycleGuard, slop_option_snarl_engine_CycleGuard)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_BlankNode(const void* key) {
    const slop_rdf_rdf_BlankNode* _k = (const slop_rdf_rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_BlankNode(const void* a, const void* b) {
    const slop_rdf_rdf_BlankNode* _a = (const slop_rdf_rdf_BlankNode*)a;
    const slop_rdf_rdf_BlankNode* _b = (const slop_rdf_rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_Literal(const void* key) {
    const slop_rdf_rdf_Literal* _k = (const slop_rdf_rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Literal(const void* a, const void* b) {
    const slop_rdf_rdf_Literal* _a = (const slop_rdf_rdf_Literal*)a;
    const slop_rdf_rdf_Literal* _b = (const slop_rdf_rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
    ;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Term(const void* key) {
    const slop_rdf_rdf_Term* _k = (const slop_rdf_rdf_Term*)key;
    switch (_k->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_hash_slop_rdf_rdf_BlankNode(&_k->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_hash_slop_rdf_rdf_Literal(&_k->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_slop_rdf_rdf_Term(const void* a, const void* b) {
    const slop_rdf_rdf_Term* _a = (const slop_rdf_rdf_Term*)a;
    const slop_rdf_rdf_Term* _b = (const slop_rdf_rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_eq_slop_rdf_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_eq_slop_rdf_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif

int64_t snarl_engine_cycle_guard_max_recursion_depth(void);
snarl_engine_CycleGuard snarl_engine_cycle_guard_new(slop_arena* arena);
int64_t snarl_engine_cycle_guard_depth(snarl_engine_CycleGuard guard);
uint8_t snarl_engine_cycle_guard_pair_active(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
uint8_t snarl_engine_cycle_guard_has(snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_add(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_remove(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag_depth_budget(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
void snarl_engine_cycle_guard_flag_recursion(slop_arena* arena, snarl_engine_CycleGuard guard, slop_rdf_rdf_Term shape_ref, slop_rdf_rdf_Term node);
uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
uint8_t snarl_property_shape_conforms(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
uint8_t snarl_engine_property_shape_conforms_with_guard(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps, snarl_engine_CycleGuard visited);
snarl_types_ValidatorResult snarl_engine_validate(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_engine_evaluate_simple_predicate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_engine_evaluate_constraint_for_simple_predicate_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term pred, snarl_data_graph_IdSet value_set, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);

/* Function name aliases for C interop */
#define snarl_engine_evaluate_shape_against_node snarl_evaluate_shape_against_node
#define snarl_engine_evaluate_shape_against_node_cached snarl_evaluate_shape_against_node_cached
#define snarl_engine_property_shape_conforms snarl_property_shape_conforms
#define snarl_engine_property_shape_conforms_cached snarl_property_shape_conforms_cached
#define snarl_engine_engine_validate snarl_engine_validate
#define snarl_engine_evaluate_node_shape snarl_evaluate_node_shape
#define snarl_engine_evaluate_node_shape_cached snarl_evaluate_node_shape_cached
#define snarl_engine_evaluate_property_shape snarl_evaluate_property_shape
#define snarl_engine_evaluate_property_shape_cached snarl_evaluate_property_shape_cached
#define snarl_engine_evaluate_constraint snarl_evaluate_constraint
#define snarl_engine_evaluate_constraint_cached snarl_evaluate_constraint_cached
#define snarl_engine_evaluate_constraint_for_property snarl_evaluate_constraint_for_property
#define snarl_engine_evaluate_constraint_for_property_cached snarl_evaluate_constraint_for_property_cached

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_SNARL_ENGINE_CYCLEGUARD_DEFINED
#define SLOP_OPTION_SNARL_ENGINE_CYCLEGUARD_DEFINED
SLOP_OPTION_DEFINE(snarl_engine_CycleGuard, slop_option_snarl_engine_CycleGuard)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeShape, slop_option_snarl_types_NodeShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif


#endif
