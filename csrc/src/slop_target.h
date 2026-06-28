#ifndef SLOP_target_H
#define SLOP_target_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_vocab.h"
#include "slop_types.h"

typedef struct target_ClassInstances target_ClassInstances;
typedef struct target_ClassIndex target_ClassIndex;

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

struct target_ClassInstances {
    rdf_Term class_term;
    slop_map* instances;
};
typedef struct target_ClassInstances target_ClassInstances;

#ifndef SLOP_OPTION_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_OPTION_TARGET_CLASSINSTANCES_DEFINED
SLOP_OPTION_DEFINE(target_ClassInstances, slop_option_target_ClassInstances)
#endif

#ifndef SLOP_LIST_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_LIST_TARGET_CLASSINSTANCES_DEFINED
SLOP_LIST_DEFINE(target_ClassInstances, slop_list_target_ClassInstances)
#endif

struct target_ClassIndex {
    slop_list_target_ClassInstances entries;
};
typedef struct target_ClassIndex target_ClassIndex;

#ifndef SLOP_OPTION_TARGET_CLASSINDEX_DEFINED
#define SLOP_OPTION_TARGET_CLASSINDEX_DEFINED
SLOP_OPTION_DEFINE(target_ClassIndex, slop_option_target_ClassIndex)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef RDF_TERM_HASH_EQ_DEFINED
#define RDF_TERM_HASH_EQ_DEFINED
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && slop_eq_string(&_a->value, &_b->value)
    ;
}
#endif
#ifndef RDF_BLANKNODE_HASH_EQ_DEFINED
#define RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_BlankNode(const void* key) {
    const rdf_BlankNode* _k = (const rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    { int64_t _tmp = (int64_t)_k->id; hash ^= slop_hash_int(&_tmp); hash *= 1099511628211ULL; }
    return hash;
}
static inline bool slop_eq_rdf_BlankNode(const void* a, const void* b) {
    const rdf_BlankNode* _a = (const rdf_BlankNode*)a;
    const rdf_BlankNode* _b = (const rdf_BlankNode*)b;
    return true
        && _a->id == _b->id
    ;
}
#endif
#ifndef RDF_LITERAL_HASH_EQ_DEFINED
#define RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_Literal(const void* key) {
    const rdf_Literal* _k = (const rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    { const uint8_t* _b = (const uint8_t*)&_k->datatype; for(size_t _i=0; _i<sizeof(_k->datatype); _i++) { hash ^= _b[_i]; hash *= 1099511628211ULL; } }
    { const uint8_t* _b = (const uint8_t*)&_k->lang; for(size_t _i=0; _i<sizeof(_k->lang); _i++) { hash ^= _b[_i]; hash *= 1099511628211ULL; } }
    return hash;
}
static inline bool slop_eq_rdf_Literal(const void* a, const void* b) {
    const rdf_Literal* _a = (const rdf_Literal*)a;
    const rdf_Literal* _b = (const rdf_Literal*)b;
    return true
        && slop_eq_string(&_a->value, &_b->value)
        && memcmp(&_a->datatype, &_b->datatype, sizeof(_a->datatype)) == 0
        && memcmp(&_a->lang, &_b->lang, sizeof(_a->lang)) == 0
    ;
}
#endif
static inline uint64_t slop_hash_rdf_Term(const void* key) {
    const rdf_Term* _k = (const rdf_Term*)key;
    switch (_k->tag) {
        case rdf_Term_term_iri:
            return slop_hash_rdf_IRI(&_k->data.term_iri);
        case rdf_Term_term_blank:
            return slop_hash_rdf_BlankNode(&_k->data.term_blank);
        case rdf_Term_term_literal:
            return slop_hash_rdf_Literal(&_k->data.term_literal);
        case rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_rdf_Term(const void* a, const void* b) {
    const rdf_Term* _a = (const rdf_Term*)a;
    const rdf_Term* _b = (const rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case rdf_Term_term_iri:
            return slop_eq_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case rdf_Term_term_blank:
            return slop_eq_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case rdf_Term_term_literal:
            return slop_eq_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif

index_IndexedGraph target_fixture_g_typed(slop_arena* arena);
index_IndexedGraph target_fixture_g_alice_name(slop_arena* arena);
index_IndexedGraph target_fixture_g_alice_knows_bob(slop_arena* arena);
slop_list_rdf_Term target_fixture_target_nodes_alice(slop_arena* arena);
types_NodeShape target_fixture_ns_target_class(slop_arena* arena);
slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, index_IndexedGraph data_graph, types_NodeShape shape);
slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes);
void target_add_class_if_needed(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, rdf_Term class_term);
void target_collect_constraint_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_Constraint constraint);
void target_collect_property_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_PropertyShape ps);
void target_collect_node_shape_classes(slop_arena* arena, slop_list_rdf_Term classes, slop_map* seen, types_NodeShape ns);
slop_list_rdf_Term target_collect_class_constraints(slop_arena* arena, types_ShapesGraph shapes_graph);
target_ClassIndex target_build_class_index(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph);
uint8_t target_class_index_has_class(target_ClassIndex index, rdf_Term class_term);
uint8_t target_class_index_has_instance(target_ClassIndex index, rdf_Term node, rdf_Term class_term);
slop_list_rdf_Term target_find_subclasses(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term node, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term shape_id);

/* Function name aliases for C interop */
#define target_resolve_targets snarl_resolve_targets
#define target_resolve_target_node snarl_resolve_target_node
#define target_is_shacl_instance_of_class snarl_is_shacl_instance_of_class
#define target_resolve_target_class snarl_resolve_target_class
#define target_resolve_target_subjects_of snarl_resolve_target_subjects_of
#define target_resolve_target_objects_of snarl_resolve_target_objects_of
#define target_resolve_implicit_class_targets snarl_resolve_implicit_class_targets

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TARGET_CLASSINSTANCES_DEFINED
#define SLOP_OPTION_TARGET_CLASSINSTANCES_DEFINED
SLOP_OPTION_DEFINE(target_ClassInstances, slop_option_target_ClassInstances)
#endif

#ifndef SLOP_OPTION_TARGET_CLASSINDEX_DEFINED
#define SLOP_OPTION_TARGET_CLASSINDEX_DEFINED
SLOP_OPTION_DEFINE(target_ClassIndex, slop_option_target_ClassIndex)
#endif


#endif
