#ifndef SLOP_parse_H
#define SLOP_parse_H

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
#include "slop_list.h"
#include "slop_vocab.h"
#include "slop_strlib.h"
#include "slop_types.h"

typedef struct snarl_parse_PathScanItem snarl_parse_PathScanItem;

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_NODESHAPE_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_NodeShape, slop_list_snarl_types_NodeShape)
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

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeShape, slop_option_snarl_types_NodeShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_Constraint, slop_option_snarl_types_Constraint)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODEKIND_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODEKIND_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeKind, slop_option_snarl_types_NodeKind)
#endif

struct snarl_parse_PathScanItem {
    uint8_t is_exit;
    slop_rdf_rdf_Term node;
};
typedef struct snarl_parse_PathScanItem snarl_parse_PathScanItem;

#ifndef SLOP_OPTION_SNARL_PARSE_PATHSCANITEM_DEFINED
#define SLOP_OPTION_SNARL_PARSE_PATHSCANITEM_DEFINED
SLOP_OPTION_DEFINE(snarl_parse_PathScanItem, slop_option_snarl_parse_PathScanItem)
#endif

#ifndef SLOP_LIST_SNARL_PARSE_PATHSCANITEM_DEFINED
#define SLOP_LIST_SNARL_PARSE_PATHSCANITEM_DEFINED
#define SLOP_LIST_SNARL_PARSE_PATHSCANITEM_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_parse_PathScanItem, slop_list_snarl_parse_PathScanItem)
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

uint8_t snarl_parse_shapes_graph_list_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term head);
slop_list_snarl_parse_PathScanItem snarl_parse_path_scan_work_new(slop_arena* arena);
uint8_t snarl_parse_path_node_is_acyclic(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root);
int64_t snarl_parse_path_max_eval_depth(void);
int64_t snarl_parse_path_node_eval_depth(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term root);
slop_list_slop_rdf_rdf_Term snarl_parse_path_node_eval_children(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_depth_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_path_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_slop_rdf_rdf_Term snarl_parse_shapes_graph_list_cycle_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_option_string snarl_shapes_graph_recursion_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
uint8_t snarl_parse_shape_has_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term ref);
void snarl_parse_register_inline_shapes(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_snarl_types_NodeShape node_shapes, slop_list_snarl_types_PropertyShape prop_shapes, slop_map* shape_map, slop_map* property_shape_map);
snarl_types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_NodeShape snarl_parse_node_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_PropertyShape snarl_parse_property_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_ShaclPath snarl_parse_parse_path_built_or_leaf(slop_map* built, slop_rdf_rdf_Term child);
snarl_types_ShaclPath snarl_parse_parse_path_build_node(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term n, slop_map* built);
snarl_types_ShaclPath snarl_parse_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term path_node);
slop_list_snarl_types_Constraint snarl_parse_constraints(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_snarl_types_NodeKind snarl_parse_node_kind(slop_rdf_rdf_Term term);
snarl_types_Severity snarl_parse_severity(slop_rdf_rdf_Term term);
snarl_types_Severity snarl_parse_parse_shape_severity(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_string snarl_parse_parse_shape_message(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
uint8_t snarl_parse_parse_shape_deactivated(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_int snarl_parse_term_to_int(slop_rdf_rdf_Term t);
slop_option_string snarl_parse_term_to_string(slop_rdf_rdf_Term t);
slop_option_u8 snarl_parse_term_to_bool(slop_rdf_rdf_Term t);
slop_list_string snarl_parse_parse_string_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term list_head);

/* Function name aliases for C interop */
#define snarl_parse_shapes_graph_recursion_hazard_message snarl_shapes_graph_recursion_hazard_message
#define snarl_parse_parse_shapes_graph snarl_parse_shapes_graph
#define snarl_parse_parse_node_shape snarl_parse_node_shape
#define snarl_parse_parse_property_shape snarl_parse_property_shape
#define snarl_parse_parse_path snarl_parse_path
#define snarl_parse_parse_constraints snarl_parse_constraints
#define snarl_parse_parse_node_kind snarl_parse_node_kind
#define snarl_parse_parse_severity snarl_parse_severity

#ifndef SLOP_OPTION_SNARL_PARSE_PATHSCANITEM_DEFINED
#define SLOP_OPTION_SNARL_PARSE_PATHSCANITEM_DEFINED
SLOP_OPTION_DEFINE(snarl_parse_PathScanItem, slop_option_snarl_parse_PathScanItem)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeShape, slop_option_snarl_types_NodeShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_Constraint, slop_option_snarl_types_Constraint)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODEKIND_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODEKIND_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeKind, slop_option_snarl_types_NodeKind)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif


#endif
