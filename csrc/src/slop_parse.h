#ifndef SLOP_parse_H
#define SLOP_parse_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_list.h"
#include "slop_vocab.h"
#include "slop_strlib.h"
#include "slop_types.h"

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_TYPES_NODESHAPE_DEFINED
#define SLOP_LIST_TYPES_NODESHAPE_DEFINED
SLOP_LIST_DEFINE(types_NodeShape, slop_list_types_NodeShape)
#endif

#ifndef SLOP_LIST_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_LIST_TYPES_PROPERTYSHAPE_DEFINED
SLOP_LIST_DEFINE(types_PropertyShape, slop_list_types_PropertyShape)
#endif

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

#ifndef SLOP_LIST_TYPES_CONSTRAINT_DEFINED
#define SLOP_LIST_TYPES_CONSTRAINT_DEFINED
SLOP_LIST_DEFINE(types_Constraint, slop_list_types_Constraint)
#endif

#ifndef SLOP_OPTION_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(types_NodeShape, slop_option_types_NodeShape)
#endif

#ifndef SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(types_PropertyShape, slop_option_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(types_Constraint, slop_option_types_Constraint)
#endif

#ifndef SLOP_OPTION_TYPES_NODEKIND_DEFINED
#define SLOP_OPTION_TYPES_NODEKIND_DEFINED
SLOP_OPTION_DEFINE(types_NodeKind, slop_option_types_NodeKind)
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

void parse_register_inline_shapes(slop_arena* arena, index_IndexedGraph g, slop_list_types_NodeShape node_shapes, slop_list_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map);
types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, index_IndexedGraph shapes_graph);
types_NodeShape snarl_parse_node_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_PropertyShape snarl_parse_property_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_ShaclPath snarl_parse_path(slop_arena* arena, index_IndexedGraph g, rdf_Term path_node);
slop_list_types_Constraint snarl_parse_constraints(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_types_NodeKind snarl_parse_node_kind(rdf_Term term);
types_Severity snarl_parse_severity(rdf_Term term);
types_Severity parse_parse_shape_severity(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_string parse_parse_shape_message(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
uint8_t parse_parse_shape_deactivated(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_int parse_term_to_int(rdf_Term t);
slop_option_string parse_term_to_string(rdf_Term t);
slop_option_u8 parse_term_to_bool(rdf_Term t);
slop_list_string parse_parse_string_list(slop_arena* arena, index_IndexedGraph g, rdf_Term list_head);

/* Function name aliases for C interop */
#define parse_parse_shapes_graph snarl_parse_shapes_graph
#define parse_parse_node_shape snarl_parse_node_shape
#define parse_parse_property_shape snarl_parse_property_shape
#define parse_parse_path snarl_parse_path
#define parse_parse_constraints snarl_parse_constraints
#define parse_parse_node_kind snarl_parse_node_kind
#define parse_parse_severity snarl_parse_severity

#ifndef SLOP_OPTION_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(types_NodeShape, slop_option_types_NodeShape)
#endif

#ifndef SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(types_PropertyShape, slop_option_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(types_Constraint, slop_option_types_Constraint)
#endif

#ifndef SLOP_OPTION_TYPES_NODEKIND_DEFINED
#define SLOP_OPTION_TYPES_NODEKIND_DEFINED
SLOP_OPTION_DEFINE(types_NodeKind, slop_option_types_NodeKind)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif


#endif
