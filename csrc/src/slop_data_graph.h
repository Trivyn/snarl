#ifndef SLOP_data_graph_H
#define SLOP_data_graph_H

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

typedef struct snarl_data_graph_SnarlDataIndex snarl_data_graph_SnarlDataIndex;
typedef struct snarl_data_graph_SnarlDataGraph snarl_data_graph_SnarlDataGraph;

typedef slop_map* snarl_data_graph_IdSet;

typedef slop_map* snarl_data_graph_IdSetMap;

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

struct snarl_data_graph_SnarlDataIndex {
    slop_map* sp;
    slop_map* po;
    snarl_data_graph_IdSetMap p_subjects;
    snarl_data_graph_IdSetMap p_objects;
};
typedef struct snarl_data_graph_SnarlDataIndex snarl_data_graph_SnarlDataIndex;

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAINDEX_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAINDEX_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataIndex, slop_option_snarl_data_graph_SnarlDataIndex)
#endif

struct snarl_data_graph_SnarlDataGraph {
    slop_map* ids;
    slop_map* terms;
    snarl_data_graph_SnarlDataIndex index;
    snarl_data_graph_IdSet no_ids;
    int64_t size;
};
typedef struct snarl_data_graph_SnarlDataGraph snarl_data_graph_SnarlDataGraph;

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
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

snarl_data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena);
slop_string snarl_data_graph_copy_string(slop_arena* arena, slop_string s);
slop_option_string snarl_data_graph_copy_option_string(slop_arena* arena, slop_option_string s);
slop_rdf_rdf_Term snarl_data_graph_copy_term(slop_arena* arena, slop_rdf_rdf_Term t);
int64_t snarl_data_graph_intern_term(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term t);
slop_option_int snarl_data_graph_lookup_term(snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term t);
slop_rdf_rdf_Term snarl_data_graph_term_of(snarl_data_graph_SnarlDataGraph g, int64_t id);
slop_list_slop_rdf_rdf_Term snarl_data_graph_ids_to_terms(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, snarl_data_graph_IdSet ids);
snarl_data_graph_IdSet snarl_data_graph_make_id_set(slop_arena* arena, int64_t value);
void snarl_data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, int64_t first, int64_t second, int64_t value);
void snarl_data_graph_add_to_flat_set(slop_arena* arena, snarl_data_graph_IdSetMap outer, int64_t key, int64_t value);
uint8_t snarl_data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, int64_t subj, int64_t pred, int64_t obj);
snarl_data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Triple t);
int64_t snarl_data_graph_size(snarl_data_graph_SnarlDataGraph g);
snarl_data_graph_IdSet snarl_data_graph_object_id_set(snarl_data_graph_SnarlDataGraph g, int64_t subj, int64_t pred);
snarl_data_graph_IdSet snarl_data_graph_snarl_data_graph_object_set(snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
int64_t snarl_data_graph_snarl_data_graph_id_set_size(slop_map* ids);
slop_list_slop_rdf_rdf_Term snarl_data_graph_snarl_data_graph_id_set_to_list(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, snarl_data_graph_IdSet ids);
uint8_t snarl_data_graph_snarl_data_graph_has_object(snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred, slop_rdf_rdf_Term obj);
uint8_t snarl_data_graph_contains(snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Triple t);
slop_list_slop_rdf_rdf_Term snarl_data_graph_objects(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
slop_list_slop_rdf_rdf_Term snarl_data_graph_subjects(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred, slop_rdf_rdf_Term obj);
slop_list_slop_rdf_rdf_Term snarl_data_graph_flat_index_terms(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, snarl_data_graph_IdSetMap index, slop_rdf_rdf_Term pred);
slop_list_slop_rdf_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred);
slop_list_slop_rdf_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred);
slop_list_slop_rdf_rdf_Term snarl_data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj);
slop_list_slop_rdf_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj);
slop_rdf_index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, snarl_data_graph_SnarlDataGraph g);
snarl_data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, slop_rdf_index_IndexedGraph g);

/* Function name aliases for C interop */
#define snarl_data_graph_snarl_data_graph_create snarl_data_graph_create
#define snarl_data_graph_snarl_data_graph_term_of snarl_data_graph_term_of
#define snarl_data_graph_snarl_data_graph_add snarl_data_graph_add
#define snarl_data_graph_snarl_data_graph_size snarl_data_graph_size
#define snarl_data_graph_snarl_data_graph_contains snarl_data_graph_contains
#define snarl_data_graph_snarl_data_graph_objects snarl_data_graph_objects
#define snarl_data_graph_snarl_data_graph_subjects snarl_data_graph_subjects
#define snarl_data_graph_snarl_data_graph_subjects_of snarl_data_graph_subjects_of
#define snarl_data_graph_snarl_data_graph_objects_of snarl_data_graph_objects_of
#define snarl_data_graph_snarl_data_graph_triples_for_subject snarl_data_graph_triples_for_subject
#define snarl_data_graph_snarl_data_graph_to_indexed snarl_data_graph_to_indexed
#define snarl_data_graph_snarl_data_graph_from_indexed snarl_data_graph_from_indexed

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_IDSET_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_IDSET_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_IdSet, slop_option_snarl_data_graph_IdSet)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_IDSETMAP_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_IDSETMAP_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_IdSetMap, slop_option_snarl_data_graph_IdSetMap)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAINDEX_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAINDEX_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataIndex, slop_option_snarl_data_graph_SnarlDataIndex)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_SNARL_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_data_graph_SnarlDataGraph, slop_option_snarl_data_graph_SnarlDataGraph)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif


#endif
