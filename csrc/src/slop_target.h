#ifndef SLOP_target_H
#define SLOP_target_H

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
#include "slop_vocab.h"
#include "slop_types.h"

typedef struct snarl_target_ClassInstances snarl_target_ClassInstances;
typedef struct snarl_target_ClassIndex snarl_target_ClassIndex;
typedef struct snarl_target_TargetCache snarl_target_TargetCache;

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_TERMSET_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_TERMSET_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_TermSet, slop_option_slop_rdf_index_TermSet)
#endif

struct snarl_target_ClassInstances {
    slop_rdf_rdf_Term class_term;
    slop_map* instances;
};
typedef struct snarl_target_ClassInstances snarl_target_ClassInstances;

#ifndef SLOP_OPTION_SNARL_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_OPTION_SNARL_TARGET_CLASSINSTANCES_DEFINED
SLOP_OPTION_DEFINE(snarl_target_ClassInstances, slop_option_snarl_target_ClassInstances)
#endif

#ifndef SLOP_LIST_SNARL_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_LIST_SNARL_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_LIST_SNARL_TARGET_CLASSINSTANCES_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_target_ClassInstances, slop_list_snarl_target_ClassInstances)
#endif

struct snarl_target_ClassIndex {
    slop_list_snarl_target_ClassInstances entries;
    slop_map* entry_map;
};
typedef struct snarl_target_ClassIndex snarl_target_ClassIndex;

#ifndef SLOP_OPTION_SNARL_TARGET_CLASSINDEX_DEFINED
#define SLOP_OPTION_SNARL_TARGET_CLASSINDEX_DEFINED
SLOP_OPTION_DEFINE(snarl_target_ClassIndex, slop_option_snarl_target_ClassIndex)
#endif

typedef slop_list_slop_rdf_rdf_Term snarl_target_TermList;

struct snarl_target_TargetCache {
    slop_map* target_classes;
};
typedef struct snarl_target_TargetCache snarl_target_TargetCache;

#ifndef SLOP_OPTION_SNARL_TARGET_TARGETCACHE_DEFINED
#define SLOP_OPTION_SNARL_TARGET_TARGETCACHE_DEFINED
SLOP_OPTION_DEFINE(snarl_target_TargetCache, slop_option_snarl_target_TargetCache)
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

snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_typed(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_name(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_target_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_target_fixture_target_nodes_alice(slop_arena* arena);
snarl_types_NodeShape snarl_target_fixture_ns_target_class(slop_arena* arena);
slop_list_slop_rdf_rdf_Term snarl_resolve_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeShape shape);
snarl_target_TargetCache snarl_target_target_cache_create(slop_arena* arena);
snarl_target_TermList snarl_target_resolve_target_class_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_target_resolve_targets_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_TargetCache cache, snarl_types_NodeShape shape);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_slop_rdf_rdf_Term nodes);
slop_list_slop_rdf_rdf_Term snarl_target_collect_class_constraints(slop_arena* arena, snarl_types_ShapesGraph shapes_graph);
snarl_target_ClassIndex snarl_target_build_class_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph);
uint8_t snarl_target_class_index_has_class(snarl_target_ClassIndex index, slop_rdf_rdf_Term class_term);
uint8_t snarl_target_class_index_has_instance(snarl_target_ClassIndex index, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_target_find_subclasses(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term);
uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term shape_id);

/* Function name aliases for C interop */
#define snarl_target_resolve_targets snarl_resolve_targets
#define snarl_target_resolve_target_node snarl_resolve_target_node
#define snarl_target_is_shacl_instance_of_class snarl_is_shacl_instance_of_class
#define snarl_target_resolve_target_class snarl_resolve_target_class
#define snarl_target_resolve_target_subjects_of snarl_resolve_target_subjects_of
#define snarl_target_resolve_target_objects_of snarl_resolve_target_objects_of
#define snarl_target_resolve_implicit_class_targets snarl_resolve_implicit_class_targets

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_OPTION_SNARL_TARGET_CLASSINSTANCES_DEFINED
SLOP_OPTION_DEFINE(snarl_target_ClassInstances, slop_option_snarl_target_ClassInstances)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_INDEX_TERMSET_DEFINED
#define SLOP_OPTION_SLOP_RDF_INDEX_TERMSET_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_index_TermSet, slop_option_slop_rdf_index_TermSet)
#endif

#ifndef SLOP_OPTION_SNARL_TARGET_CLASSINDEX_DEFINED
#define SLOP_OPTION_SNARL_TARGET_CLASSINDEX_DEFINED
SLOP_OPTION_DEFINE(snarl_target_ClassIndex, slop_option_snarl_target_ClassIndex)
#endif

#ifndef SLOP_OPTION_SNARL_TARGET_TERMLIST_DEFINED
#define SLOP_OPTION_SNARL_TARGET_TERMLIST_DEFINED
SLOP_OPTION_DEFINE(snarl_target_TermList, slop_option_snarl_target_TermList)
#endif

#ifndef SLOP_OPTION_SNARL_TARGET_TARGETCACHE_DEFINED
#define SLOP_OPTION_SNARL_TARGET_TARGETCACHE_DEFINED
SLOP_OPTION_DEFINE(snarl_target_TargetCache, slop_option_snarl_target_TargetCache)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_Constraint, slop_option_snarl_types_Constraint)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_PropertyShape, slop_list_snarl_types_PropertyShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_LIST_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_LIST_SNARL_TYPES_CONSTRAINT_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_Constraint, slop_list_snarl_types_Constraint)
#endif


#endif
