#ifndef SLOP_data_graph_H
#define SLOP_data_graph_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"

typedef struct data_graph_SnarlDataIndex data_graph_SnarlDataIndex;
typedef struct data_graph_SnarlDataGraph data_graph_SnarlDataGraph;

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_INDEX_TERMSETMAP_DEFINED
#define SLOP_OPTION_INDEX_TERMSETMAP_DEFINED
SLOP_OPTION_DEFINE(index_TermSetMap, slop_option_index_TermSetMap)
#endif

#ifndef SLOP_OPTION_INDEX_TERMSET_DEFINED
#define SLOP_OPTION_INDEX_TERMSET_DEFINED
SLOP_OPTION_DEFINE(index_TermSet, slop_option_index_TermSet)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

struct data_graph_SnarlDataIndex {
    slop_map* sp;
    slop_map* po;
    slop_map* p_subjects;
    slop_map* p_objects;
};
typedef struct data_graph_SnarlDataIndex data_graph_SnarlDataIndex;

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAINDEX_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAINDEX_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataIndex, slop_option_data_graph_SnarlDataIndex)
#endif

struct data_graph_SnarlDataGraph {
    slop_list_rdf_Triple triples;
    data_graph_SnarlDataIndex index;
    int64_t size;
};
typedef struct data_graph_SnarlDataGraph data_graph_SnarlDataGraph;

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataGraph, slop_option_data_graph_SnarlDataGraph)
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

data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena);
index_TermSet data_graph_make_term_set(slop_arena* arena, rdf_Term value);
void data_graph_add_to_nested_set(slop_arena* arena, slop_map* outer, rdf_Term first, rdf_Term second, rdf_Term value);
void data_graph_add_to_flat_set(slop_arena* arena, slop_map* outer, rdf_Term key, rdf_Term value);
uint8_t snarl_data_graph_contains(data_graph_SnarlDataGraph g, rdf_Triple t);
slop_option_index_TermSet data_graph_snarl_data_graph_object_set(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
int64_t data_graph_snarl_data_graph_term_set_size(index_TermSet terms);
slop_list_rdf_Term data_graph_snarl_data_graph_term_set_to_list(slop_arena* arena, index_TermSet terms);
uint8_t data_graph_snarl_data_graph_has_object(data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred, rdf_Term obj);
uint8_t data_graph_add_to_sp_index_if_new(slop_arena* arena, slop_map* outer, rdf_Term subj, rdf_Term pred, rdf_Term obj);
data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Triple t);
int64_t snarl_data_graph_size(data_graph_SnarlDataGraph g);
slop_list_rdf_Term snarl_data_graph_objects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_subjects(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred, rdf_Term obj);
slop_list_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term pred);
slop_list_rdf_Term data_graph_snarl_data_graph_predicates_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
slop_list_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, data_graph_SnarlDataGraph g, rdf_Term subj);
index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, data_graph_SnarlDataGraph g);
data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, index_IndexedGraph g);

/* Function name aliases for C interop */
#define data_graph_snarl_data_graph_create snarl_data_graph_create
#define data_graph_snarl_data_graph_contains snarl_data_graph_contains
#define data_graph_snarl_data_graph_add snarl_data_graph_add
#define data_graph_snarl_data_graph_size snarl_data_graph_size
#define data_graph_snarl_data_graph_objects snarl_data_graph_objects
#define data_graph_snarl_data_graph_subjects snarl_data_graph_subjects
#define data_graph_snarl_data_graph_subjects_of snarl_data_graph_subjects_of
#define data_graph_snarl_data_graph_objects_of snarl_data_graph_objects_of
#define data_graph_snarl_data_graph_triples_for_subject snarl_data_graph_triples_for_subject
#define data_graph_snarl_data_graph_to_indexed snarl_data_graph_to_indexed
#define data_graph_snarl_data_graph_from_indexed snarl_data_graph_from_indexed

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_INDEX_TERMSETMAP_DEFINED
#define SLOP_OPTION_INDEX_TERMSETMAP_DEFINED
SLOP_OPTION_DEFINE(index_TermSetMap, slop_option_index_TermSetMap)
#endif

#ifndef SLOP_OPTION_INDEX_TERMSET_DEFINED
#define SLOP_OPTION_INDEX_TERMSET_DEFINED
SLOP_OPTION_DEFINE(index_TermSet, slop_option_index_TermSet)
#endif

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAINDEX_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAINDEX_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataIndex, slop_option_data_graph_SnarlDataIndex)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
#define SLOP_OPTION_DATA_GRAPH_SNARLDATAGRAPH_DEFINED
SLOP_OPTION_DEFINE(data_graph_SnarlDataGraph, slop_option_data_graph_SnarlDataGraph)
#endif


#endif
