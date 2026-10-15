/* snarl.h - Auto-generated FFI header. Do not edit. */
#ifndef SNARL_H
#define SNARL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque runtime types */
typedef struct slop_arena slop_arena;
typedef struct slop_map slop_map;

/* Runtime value types */
typedef struct { size_t len; const char* data; } slop_string;
typedef struct { bool has_value; slop_string value; } slop_option_string;
typedef struct { void* fn; void* env; } slop_closure_t;

/* Type definitions */
typedef struct { size_t len; size_t cap; snarl_types_Constraint* data; slop_arena* arena; } slop_list_snarl_types_Constraint;

struct slop_rdf_index_TripleIndex {
    slop_map* spo;
    slop_map* pso;
    slop_map* osp;
    slop_map* pos;
};
typedef struct slop_rdf_index_TripleIndex slop_rdf_index_TripleIndex;

typedef int64_t slop_rdf_rdf_BlankNodeId;

struct slop_rdf_rdf_BlankNode {
    slop_rdf_rdf_BlankNodeId id;
};
typedef struct slop_rdf_rdf_BlankNode slop_rdf_rdf_BlankNode;

typedef int64_t slop_rdf_rdf_GraphSize;

struct slop_rdf_rdf_IRI {
    slop_string value;
};
typedef struct slop_rdf_rdf_IRI slop_rdf_rdf_IRI;

struct slop_rdf_rdf_Literal {
    slop_string value;
    slop_option_string datatype;
    slop_option_string lang;
};
typedef struct slop_rdf_rdf_Literal slop_rdf_rdf_Literal;

typedef enum {
    slop_rdf_rdf_TermKind_iri,
    slop_rdf_rdf_TermKind_blank,
    slop_rdf_rdf_TermKind_literal,
    slop_rdf_rdf_TermKind_triple
} slop_rdf_rdf_TermKind;

typedef enum {
    slop_rdf_rdf_Term_term_iri,
    slop_rdf_rdf_Term_term_blank,
    slop_rdf_rdf_Term_term_literal,
    slop_rdf_rdf_Term_term_triple
} slop_rdf_rdf_Term_tag;

typedef enum {
    slop_rdf_xsd_XsdCompareResult_xsd_compare_less,
    slop_rdf_xsd_XsdCompareResult_xsd_compare_equal,
    slop_rdf_xsd_XsdCompareResult_xsd_compare_greater,
    slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable
} slop_rdf_xsd_XsdCompareResult;

typedef enum {
    slop_rdf_xsd_XsdType_xsd_string,
    slop_rdf_xsd_XsdType_xsd_integer,
    slop_rdf_xsd_XsdType_xsd_decimal,
    slop_rdf_xsd_XsdType_xsd_float,
    slop_rdf_xsd_XsdType_xsd_double,
    slop_rdf_xsd_XsdType_xsd_boolean,
    slop_rdf_xsd_XsdType_xsd_unknown
} slop_rdf_xsd_XsdType;

typedef enum {
    slop_rdf_xsd_XsdValue_xsd_string_val,
    slop_rdf_xsd_XsdValue_xsd_integer_val,
    slop_rdf_xsd_XsdValue_xsd_decimal_val,
    slop_rdf_xsd_XsdValue_xsd_float_val,
    slop_rdf_xsd_XsdValue_xsd_double_val,
    slop_rdf_xsd_XsdValue_xsd_boolean_val,
    slop_rdf_xsd_XsdValue_xsd_unknown_val
} slop_rdf_xsd_XsdValue_tag;

struct slop_rdf_xsd_XsdValue {
    slop_rdf_xsd_XsdValue_tag tag;
    union {
        slop_string xsd_string_val;
        int64_t xsd_integer_val;
        double xsd_decimal_val;
        float xsd_float_val;
        double xsd_double_val;
        uint8_t xsd_boolean_val;
        slop_string xsd_unknown_val;
    } data;
};
typedef struct slop_rdf_xsd_XsdValue slop_rdf_xsd_XsdValue;

typedef slop_map* snarl_data_graph_IdSet;

typedef slop_map* snarl_data_graph_IdSetMap;

struct snarl_data_graph_SnarlDataIndex {
    slop_map* sp;
    slop_map* po;
    snarl_data_graph_IdSetMap p_subjects;
    snarl_data_graph_IdSetMap p_objects;
};
typedef struct snarl_data_graph_SnarlDataIndex snarl_data_graph_SnarlDataIndex;

struct snarl_data_graph_SnarlDataGraph {
    slop_map* ids;
    slop_map* terms;
    snarl_data_graph_SnarlDataIndex index;
    snarl_data_graph_IdSet no_ids;
    int64_t size;
};
typedef struct snarl_data_graph_SnarlDataGraph snarl_data_graph_SnarlDataGraph;

struct snarl_engine_CycleGuard {
    slop_map* pairs;
    slop_map* depth;
    slop_map* errors;
};
typedef struct snarl_engine_CycleGuard snarl_engine_CycleGuard;

typedef enum {
    snarl_types_NodeKind_node_kind_blank_node,
    snarl_types_NodeKind_node_kind_iri,
    snarl_types_NodeKind_node_kind_literal,
    snarl_types_NodeKind_node_kind_blank_node_or_iri,
    snarl_types_NodeKind_node_kind_blank_node_or_literal,
    snarl_types_NodeKind_node_kind_iri_or_literal
} snarl_types_NodeKind;

typedef struct { bool has_value; snarl_types_NodeKind value; } slop_option_snarl_types_NodeKind;

typedef enum {
    snarl_types_Severity_severity_violation,
    snarl_types_Severity_severity_warning,
    snarl_types_Severity_severity_info
} snarl_types_Severity;

typedef enum {
    snarl_types_ShaclPath_path_predicate,
    snarl_types_ShaclPath_path_sequence,
    snarl_types_ShaclPath_path_alternative,
    snarl_types_ShaclPath_path_inverse,
    snarl_types_ShaclPath_path_zero_or_more,
    snarl_types_ShaclPath_path_one_or_more,
    snarl_types_ShaclPath_path_zero_or_one
} snarl_types_ShaclPath_tag;

struct snarl_types_ValidatorConfig {
    uint8_t verbose;
    int64_t max_errors;
    uint8_t include_warnings;
    uint8_t include_infos;
};
typedef struct snarl_types_ValidatorConfig snarl_types_ValidatorConfig;

typedef enum {
    snarl_types_ValidatorResult_validate_success,
    snarl_types_ValidatorResult_validate_error
} snarl_types_ValidatorResult_tag;

typedef struct { size_t len; size_t cap; slop_rdf_rdf_Term* data; slop_arena* arena; } slop_list_slop_rdf_rdf_Term;

typedef struct { size_t len; size_t cap; slop_rdf_rdf_Triple* data; slop_arena* arena; } slop_list_slop_rdf_rdf_Triple;

typedef struct { size_t len; size_t cap; snarl_target_ClassInstances* data; slop_arena* arena; } slop_list_snarl_target_ClassInstances;

typedef struct { size_t len; size_t cap; snarl_types_NodeShape* data; slop_arena* arena; } slop_list_snarl_types_NodeShape;

typedef struct { size_t len; size_t cap; snarl_types_PropertyShape* data; slop_arena* arena; } slop_list_snarl_types_PropertyShape;

typedef struct { size_t len; size_t cap; snarl_types_ShaclPath* data; slop_arena* arena; } slop_list_snarl_types_ShaclPath;

typedef struct { size_t len; size_t cap; snarl_types_ValidationResult* data; slop_arena* arena; } slop_list_snarl_types_ValidationResult;

typedef struct { bool has_value; slop_rdf_rdf_Term value; } slop_option_slop_rdf_rdf_Term;

typedef struct { bool has_value; snarl_types_ShaclPath value; } slop_option_snarl_types_ShaclPath;

typedef struct { bool has_value; snarl_types_ValidationResult value; } slop_option_snarl_types_ValidationResult;

struct slop_rdf_index_IndexedGraph {
    slop_list_slop_rdf_rdf_Triple triples;
    slop_rdf_index_TripleIndex index;
    int64_t size;
};
typedef struct slop_rdf_index_IndexedGraph slop_rdf_index_IndexedGraph;

struct slop_rdf_rdf_Graph {
    slop_list_slop_rdf_rdf_Triple triples;
    slop_rdf_rdf_GraphSize size;
};
typedef struct slop_rdf_rdf_Graph slop_rdf_rdf_Graph;

struct slop_rdf_rdf_Term {
    slop_rdf_rdf_Term_tag tag;
    union {
        slop_rdf_rdf_IRI term_iri;
        slop_rdf_rdf_BlankNode term_blank;
        slop_rdf_rdf_Literal term_literal;
        slop_rdf_rdf_Triple* term_triple;
    } data;
};
typedef struct slop_rdf_rdf_Term slop_rdf_rdf_Term;

struct slop_rdf_rdf_Triple {
    slop_rdf_rdf_Term subject;
    slop_rdf_rdf_Term predicate;
    slop_rdf_rdf_Term object;
};
typedef struct slop_rdf_rdf_Triple slop_rdf_rdf_Triple;

struct snarl_target_ClassIndex {
    slop_list_snarl_target_ClassInstances entries;
    slop_map* entry_map;
};
typedef struct snarl_target_ClassIndex snarl_target_ClassIndex;

struct snarl_target_ClassInstances {
    slop_rdf_rdf_Term class_term;
    slop_map* instances;
};
typedef struct snarl_target_ClassInstances snarl_target_ClassInstances;

struct snarl_types_NodeShape {
    slop_rdf_rdf_Term id;
    slop_list_slop_rdf_rdf_Term target_nodes;
    slop_list_slop_rdf_rdf_Term target_classes;
    slop_list_slop_rdf_rdf_Term target_subjects_of;
    slop_list_slop_rdf_rdf_Term target_objects_of;
    slop_list_snarl_types_PropertyShape property_shapes;
    slop_list_snarl_types_Constraint constraints;
    snarl_types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct snarl_types_NodeShape snarl_types_NodeShape;

struct snarl_types_PropertyShape {
    slop_rdf_rdf_Term id;
    snarl_types_ShaclPath path;
    slop_list_snarl_types_Constraint constraints;
    snarl_types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct snarl_types_PropertyShape snarl_types_PropertyShape;

struct snarl_types_ShaclPath {
    snarl_types_ShaclPath_tag tag;
    union {
        slop_rdf_rdf_Term path_predicate;
        slop_list_snarl_types_ShaclPath path_sequence;
        slop_list_snarl_types_ShaclPath path_alternative;
        snarl_types_ShaclPath* path_inverse;
        snarl_types_ShaclPath* path_zero_or_more;
        snarl_types_ShaclPath* path_one_or_more;
        snarl_types_ShaclPath* path_zero_or_one;
    } data;
};
typedef struct snarl_types_ShaclPath snarl_types_ShaclPath;

struct snarl_types_ShapesGraph {
    slop_list_snarl_types_NodeShape node_shapes;
    slop_list_snarl_types_PropertyShape property_shapes;
    slop_map* shape_map;
    slop_map* property_shape_map;
};
typedef struct snarl_types_ShapesGraph snarl_types_ShapesGraph;

struct snarl_types_ValidationReport {
    uint8_t conforms;
    slop_list_snarl_types_ValidationResult results;
};
typedef struct snarl_types_ValidationReport snarl_types_ValidationReport;

struct snarl_types_ValidationResult {
    slop_rdf_rdf_Term focus_node;
    slop_option_snarl_types_ShaclPath result_path;
    slop_option_slop_rdf_rdf_Term value;
    slop_rdf_rdf_Term source_shape;
    slop_string source_constraint_component;
    snarl_types_Severity severity;
    slop_option_string message;
};
typedef struct snarl_types_ValidationResult snarl_types_ValidationResult;

struct snarl_types_ValidatorResult {
    snarl_types_ValidatorResult_tag tag;
    union {
        snarl_types_ValidationReport validate_success;
        slop_string validate_error;
    } data;
};
typedef struct snarl_types_ValidatorResult snarl_types_ValidatorResult;

/* Public API */
uint8_t rdf_blank_eq(slop_rdf_rdf_BlankNode a, slop_rdf_rdf_BlankNode b);
slop_rdf_rdf_Graph rdf_graph_add(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Triple t);
slop_rdf_rdf_Graph rdf_graph_add_unchecked(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Triple t);
uint8_t rdf_graph_contains(slop_rdf_rdf_Graph g, slop_rdf_rdf_Triple t);
void rdf_graph_free(slop_rdf_rdf_Graph* g);
slop_rdf_rdf_Graph rdf_graph_match(slop_arena* arena, slop_rdf_rdf_Graph g, slop_option_slop_rdf_rdf_Term subject, slop_option_slop_rdf_rdf_Term predicate, slop_option_slop_rdf_rdf_Term object);
slop_rdf_rdf_Graph rdf_graph_remove(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Triple t);
slop_rdf_rdf_GraphSize rdf_graph_size(slop_rdf_rdf_Graph g);
slop_rdf_index_IndexedGraph rdf_indexed_graph_add(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Triple t);
uint8_t rdf_indexed_graph_contains(slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Triple t);
slop_rdf_index_IndexedGraph rdf_indexed_graph_create(slop_arena* arena);
void rdf_indexed_graph_for_each(slop_rdf_index_IndexedGraph g, slop_option_slop_rdf_rdf_Term subj, slop_option_slop_rdf_rdf_Term pred, slop_option_slop_rdf_rdf_Term obj, slop_closure_t callback);
slop_list_slop_rdf_rdf_Triple rdf_indexed_graph_match(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_option_slop_rdf_rdf_Term subj, slop_option_slop_rdf_rdf_Term pred, slop_option_slop_rdf_rdf_Term obj);
slop_list_slop_rdf_rdf_Term rdf_indexed_graph_objects(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
int64_t rdf_indexed_graph_size(slop_rdf_index_IndexedGraph g);
slop_list_slop_rdf_rdf_Term rdf_indexed_graph_subjects(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term pred, slop_rdf_rdf_Term obj);
uint8_t rdf_iri_eq(slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
uint8_t rdf_list_contains(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Term head, slop_rdf_rdf_Term element);
slop_list_slop_rdf_rdf_Term rdf_list_elements(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Term head);
slop_list_slop_rdf_rdf_Term rdf_list_elements_indexed(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term head);
int64_t rdf_list_length(slop_arena* arena, slop_rdf_rdf_Graph g, slop_rdf_rdf_Term head);
uint8_t rdf_literal_eq(slop_rdf_rdf_Literal a, slop_rdf_rdf_Literal b);
slop_rdf_rdf_Term rdf_make_blank(slop_arena* arena, slop_rdf_rdf_BlankNodeId id);
slop_rdf_rdf_Graph rdf_make_graph(slop_arena* arena);
slop_rdf_rdf_Term rdf_make_iri(slop_arena* arena, slop_string value);
slop_rdf_rdf_Term rdf_make_literal(slop_arena* arena, slop_string value, slop_option_string datatype, slop_option_string lang);
slop_rdf_rdf_Triple rdf_make_triple(slop_arena* arena, slop_rdf_rdf_Term subject, slop_rdf_rdf_Term predicate, slop_rdf_rdf_Term object);
slop_rdf_rdf_Term rdf_make_triple_term(slop_arena* arena, slop_rdf_rdf_Triple t);
uint8_t rdf_option_string_eq(slop_option_string a, slop_option_string b);
uint8_t rdf_term_eq(slop_rdf_rdf_Term a, slop_rdf_rdf_Term b);
void rdf_term_free(slop_rdf_rdf_Term* t);
slop_rdf_rdf_TermKind rdf_term_kind(slop_rdf_rdf_Term t);
uint8_t rdf_triple_eq(slop_rdf_rdf_Triple a, slop_rdf_rdf_Triple b);
void rdf_triple_free(slop_rdf_rdf_Triple* t);
slop_rdf_rdf_Term rdf_triple_object(slop_rdf_rdf_Triple t);
slop_rdf_rdf_Term rdf_triple_predicate(slop_rdf_rdf_Triple t);
slop_rdf_rdf_Term rdf_triple_subject(slop_rdf_rdf_Triple t);
slop_option_snarl_types_ValidationResult snarl_check_and(slop_arena* arena, slop_rdf_rdf_Term focus_node, uint8_t all_pass, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_closed(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_snarl_types_ShaclPath allowed_paths, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_datatype(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_disjoint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_has_value(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_rdf_rdf_Term required_value, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_slop_rdf_rdf_Term allowed_values, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_language_in(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_list_string allowed_langs, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, snarl_types_ShaclPath other_path, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_exclusive(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term limit, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_inclusive(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term limit, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_max_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t max_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_min_count(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_min_exclusive(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term limit, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_min_inclusive(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term limit, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_min_length(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, int64_t min_len, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_node(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, uint8_t value_conforms, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_node_kind(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_NodeKind required_kind, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_not(slop_arena* arena, slop_rdf_rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_or(slop_arena* arena, slop_rdf_rdf_Term focus_node, uint8_t any_pass, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_pattern(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_string pattern, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_qualified_value_shape(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t conforming_count, int64_t q_min, slop_option_int q_max, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_list_snarl_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_check_xone(slop_arena* arena, slop_rdf_rdf_Term focus_node, int64_t pass_count, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
uint8_t snarl_conforms(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
uint8_t snarl_conforms_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_data_graph_SnarlDataGraph snarl_data_graph_add(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Triple t);
uint8_t snarl_data_graph_contains(snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Triple t);
snarl_data_graph_SnarlDataGraph snarl_data_graph_create(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_data_graph_from_indexed(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_list_slop_rdf_rdf_Term snarl_data_graph_objects(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
slop_list_slop_rdf_rdf_Term snarl_data_graph_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred);
int64_t snarl_data_graph_size(snarl_data_graph_SnarlDataGraph g);
slop_list_slop_rdf_rdf_Term snarl_data_graph_subjects(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred, slop_rdf_rdf_Term obj);
slop_list_slop_rdf_rdf_Term snarl_data_graph_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term pred);
slop_rdf_rdf_Term snarl_data_graph_term_of(snarl_data_graph_SnarlDataGraph g, int64_t id);
slop_rdf_index_IndexedGraph snarl_data_graph_to_indexed(slop_arena* arena, snarl_data_graph_SnarlDataGraph g);
slop_list_slop_rdf_rdf_Triple snarl_data_graph_triples_for_subject(slop_arena* arena, snarl_data_graph_SnarlDataGraph g, slop_rdf_rdf_Term subj);
snarl_types_ValidatorConfig snarl_default_config(void);
snarl_types_ValidatorResult snarl_engine_validate(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_constraint_for_property_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_list_slop_rdf_rdf_Term value_nodes, int64_t value_count, snarl_types_Constraint constraint, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message, snarl_engine_CycleGuard visited, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_node_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_NodeShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
slop_list_snarl_types_ValidationResult snarl_evaluate_property_shape_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, snarl_types_PropertyShape shape, slop_rdf_rdf_Term focus_node, snarl_engine_CycleGuard visited, snarl_types_ValidatorConfig config, slop_list_slop_rdf_rdf_Term sibling_qvs_refs);
uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
uint8_t snarl_evaluate_shape_against_node_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_NodeShape shape, snarl_engine_CycleGuard visited);
int64_t snarl_get_result_count(snarl_types_ValidationReport report);
slop_list_snarl_types_ValidationResult snarl_get_violations(slop_arena* arena, snarl_types_ValidationReport report);
slop_list_snarl_types_ValidationResult snarl_get_warnings(slop_arena* arena, snarl_types_ValidationReport report);
uint8_t snarl_is_shacl_instance_of_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term node, slop_rdf_rdf_Term class_term);
slop_list_snarl_types_Constraint snarl_parse_constraints(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
slop_option_snarl_types_NodeKind snarl_parse_node_kind(slop_rdf_rdf_Term term);
snarl_types_NodeShape snarl_parse_node_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_ShaclPath snarl_parse_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term path_node);
snarl_types_PropertyShape snarl_parse_property_shape(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_rdf_rdf_Term shape_id);
snarl_types_Severity snarl_parse_severity(slop_rdf_rdf_Term term);
snarl_types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, slop_rdf_index_IndexedGraph shapes_graph);
slop_string snarl_path_to_display_string(slop_arena* arena, snarl_types_ShaclPath p);
void snarl_print_report(slop_arena* arena, snarl_types_ValidationReport report);
uint8_t snarl_property_shape_conforms(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
uint8_t snarl_property_shape_conforms_cached(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, snarl_types_PropertyShape ps);
slop_rdf_index_IndexedGraph snarl_report_to_graph(slop_arena* arena, snarl_types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, snarl_types_ValidationReport report);
slop_list_slop_rdf_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term shape_id);
slop_list_slop_rdf_rdf_Term snarl_resolve_path(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, snarl_types_ShaclPath path);
slop_list_slop_rdf_rdf_Term snarl_resolve_path_from(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term object, snarl_types_ShaclPath path);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term class_term);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_slop_rdf_rdf_Term nodes);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term predicate);
slop_list_slop_rdf_rdf_Term snarl_resolve_targets(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_NodeShape shape);
slop_string snarl_severity_to_string(snarl_types_Severity sev);
slop_option_string snarl_shapes_graph_recursion_hazard_message(slop_arena* arena, slop_rdf_index_IndexedGraph g);
slop_string snarl_term_to_display_string(slop_arena* arena, slop_rdf_rdf_Term t);
snarl_types_ValidatorResult snarl_validate(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_data_graph(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph);
snarl_types_ValidatorResult snarl_validate_data_graph_with_config(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
snarl_types_ValidatorResult snarl_validate_with_config(slop_arena* arena, slop_rdf_index_IndexedGraph data_graph, slop_rdf_index_IndexedGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_rdf_xsd_XsdCompareResult xsd_compare(slop_arena* arena, slop_rdf_rdf_Term a, slop_rdf_rdf_Term b);
slop_rdf_xsd_XsdCompareResult xsd_float_cmp(double a, double b);
slop_result_u8_slop_rdf_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, slop_rdf_rdf_Literal a, slop_rdf_rdf_Literal b);
slop_rdf_xsd_XsdType xsd_parse_type(slop_string datatype_iri);
slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, slop_rdf_xsd_XsdType dtype);
uint8_t xsd_types_compatible(slop_rdf_xsd_XsdType t1, slop_rdf_xsd_XsdType t2);
uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri);
slop_rdf_xsd_XsdCompareResult xsd_values_compare(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b);
uint8_t xsd_values_equal(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b);

#define slop_rdf_index_indexed_graph_add rdf_indexed_graph_add
#define slop_rdf_index_indexed_graph_contains rdf_indexed_graph_contains
#define slop_rdf_index_indexed_graph_create rdf_indexed_graph_create
#define slop_rdf_index_indexed_graph_for_each rdf_indexed_graph_for_each
#define slop_rdf_index_indexed_graph_match rdf_indexed_graph_match
#define slop_rdf_index_indexed_graph_objects rdf_indexed_graph_objects
#define slop_rdf_index_indexed_graph_size rdf_indexed_graph_size
#define slop_rdf_index_indexed_graph_subjects rdf_indexed_graph_subjects
#define slop_rdf_list_rdf_list_contains rdf_list_contains
#define slop_rdf_list_rdf_list_elements rdf_list_elements
#define slop_rdf_list_rdf_list_elements_indexed rdf_list_elements_indexed
#define slop_rdf_list_rdf_list_length rdf_list_length
#define slop_rdf_rdf_blank_eq rdf_blank_eq
#define slop_rdf_rdf_graph_add rdf_graph_add
#define slop_rdf_rdf_graph_add_unchecked rdf_graph_add_unchecked
#define slop_rdf_rdf_graph_contains rdf_graph_contains
#define slop_rdf_rdf_graph_free rdf_graph_free
#define slop_rdf_rdf_graph_match rdf_graph_match
#define slop_rdf_rdf_graph_remove rdf_graph_remove
#define slop_rdf_rdf_graph_size rdf_graph_size
#define slop_rdf_rdf_iri_eq rdf_iri_eq
#define slop_rdf_rdf_literal_eq rdf_literal_eq
#define slop_rdf_rdf_make_blank rdf_make_blank
#define slop_rdf_rdf_make_graph rdf_make_graph
#define slop_rdf_rdf_make_iri rdf_make_iri
#define slop_rdf_rdf_make_literal rdf_make_literal
#define slop_rdf_rdf_make_triple rdf_make_triple
#define slop_rdf_rdf_make_triple_term rdf_make_triple_term
#define slop_rdf_rdf_option_string_eq rdf_option_string_eq
#define slop_rdf_rdf_term_eq rdf_term_eq
#define slop_rdf_rdf_term_free rdf_term_free
#define slop_rdf_rdf_term_kind rdf_term_kind
#define slop_rdf_rdf_triple_eq rdf_triple_eq
#define slop_rdf_rdf_triple_free rdf_triple_free
#define slop_rdf_rdf_triple_object rdf_triple_object
#define slop_rdf_rdf_triple_predicate rdf_triple_predicate
#define slop_rdf_rdf_triple_subject rdf_triple_subject
#define slop_rdf_xsd_float_cmp xsd_float_cmp
#define slop_rdf_xsd_literal_values_equal xsd_literal_values_equal
#define slop_rdf_xsd_xsd_compare xsd_compare
#define slop_rdf_xsd_xsd_parse_type xsd_parse_type
#define slop_rdf_xsd_xsd_parse_value xsd_parse_value
#define slop_rdf_xsd_xsd_types_compatible xsd_types_compatible
#define slop_rdf_xsd_xsd_validate_lexical xsd_validate_lexical
#define slop_rdf_xsd_xsd_values_compare xsd_values_compare
#define slop_rdf_xsd_xsd_values_equal xsd_values_equal
#define snarl_cardinality_check_max_count snarl_check_max_count
#define snarl_cardinality_check_min_count snarl_check_min_count
#define snarl_data_graph_snarl_data_graph_add snarl_data_graph_add
#define snarl_data_graph_snarl_data_graph_contains snarl_data_graph_contains
#define snarl_data_graph_snarl_data_graph_create snarl_data_graph_create
#define snarl_data_graph_snarl_data_graph_from_indexed snarl_data_graph_from_indexed
#define snarl_data_graph_snarl_data_graph_objects snarl_data_graph_objects
#define snarl_data_graph_snarl_data_graph_objects_of snarl_data_graph_objects_of
#define snarl_data_graph_snarl_data_graph_size snarl_data_graph_size
#define snarl_data_graph_snarl_data_graph_subjects snarl_data_graph_subjects
#define snarl_data_graph_snarl_data_graph_subjects_of snarl_data_graph_subjects_of
#define snarl_data_graph_snarl_data_graph_term_of snarl_data_graph_term_of
#define snarl_data_graph_snarl_data_graph_to_indexed snarl_data_graph_to_indexed
#define snarl_data_graph_snarl_data_graph_triples_for_subject snarl_data_graph_triples_for_subject
#define snarl_engine_engine_validate snarl_engine_validate
#define snarl_engine_evaluate_constraint snarl_evaluate_constraint
#define snarl_engine_evaluate_constraint_cached snarl_evaluate_constraint_cached
#define snarl_engine_evaluate_constraint_for_property snarl_evaluate_constraint_for_property
#define snarl_engine_evaluate_constraint_for_property_cached snarl_evaluate_constraint_for_property_cached
#define snarl_engine_evaluate_node_shape snarl_evaluate_node_shape
#define snarl_engine_evaluate_node_shape_cached snarl_evaluate_node_shape_cached
#define snarl_engine_evaluate_property_shape snarl_evaluate_property_shape
#define snarl_engine_evaluate_property_shape_cached snarl_evaluate_property_shape_cached
#define snarl_engine_evaluate_shape_against_node snarl_evaluate_shape_against_node
#define snarl_engine_evaluate_shape_against_node_cached snarl_evaluate_shape_against_node_cached
#define snarl_engine_property_shape_conforms snarl_property_shape_conforms
#define snarl_engine_property_shape_conforms_cached snarl_property_shape_conforms_cached
#define snarl_logical_check_and snarl_check_and
#define snarl_logical_check_not snarl_check_not
#define snarl_logical_check_or snarl_check_or
#define snarl_logical_check_xone snarl_check_xone
#define snarl_other_check_closed snarl_check_closed
#define snarl_other_check_has_value snarl_check_has_value
#define snarl_other_check_in snarl_check_in
#define snarl_pair_check_disjoint snarl_check_disjoint
#define snarl_pair_check_equals snarl_check_equals
#define snarl_pair_check_less_than snarl_check_less_than
#define snarl_pair_check_less_than_or_equals snarl_check_less_than_or_equals
#define snarl_parse_parse_constraints snarl_parse_constraints
#define snarl_parse_parse_node_kind snarl_parse_node_kind
#define snarl_parse_parse_node_shape snarl_parse_node_shape
#define snarl_parse_parse_path snarl_parse_path
#define snarl_parse_parse_property_shape snarl_parse_property_shape
#define snarl_parse_parse_severity snarl_parse_severity
#define snarl_parse_parse_shapes_graph snarl_parse_shapes_graph
#define snarl_parse_shapes_graph_recursion_hazard_message snarl_shapes_graph_recursion_hazard_message
#define snarl_path_resolve_path snarl_resolve_path
#define snarl_path_resolve_path_from snarl_resolve_path_from
#define snarl_report_path_to_display_string snarl_path_to_display_string
#define snarl_report_print_report snarl_print_report
#define snarl_report_report_to_graph snarl_report_to_graph
#define snarl_report_report_to_string snarl_report_to_string
#define snarl_report_severity_to_string snarl_severity_to_string
#define snarl_report_term_to_display_string snarl_term_to_display_string
#define snarl_shape_check_node snarl_check_node
#define snarl_shape_check_qualified_value_shape snarl_check_qualified_value_shape
#define snarl_string_check_language_in snarl_check_language_in
#define snarl_string_check_max_length snarl_check_max_length
#define snarl_string_check_min_length snarl_check_min_length
#define snarl_string_check_pattern snarl_check_pattern
#define snarl_string_check_unique_lang snarl_check_unique_lang
#define snarl_target_is_shacl_instance_of_class snarl_is_shacl_instance_of_class
#define snarl_target_resolve_implicit_class_targets snarl_resolve_implicit_class_targets
#define snarl_target_resolve_target_class snarl_resolve_target_class
#define snarl_target_resolve_target_node snarl_resolve_target_node
#define snarl_target_resolve_target_objects_of snarl_resolve_target_objects_of
#define snarl_target_resolve_target_subjects_of snarl_resolve_target_subjects_of
#define snarl_target_resolve_targets snarl_resolve_targets
#define snarl_value_range_check_max_exclusive snarl_check_max_exclusive
#define snarl_value_range_check_max_inclusive snarl_check_max_inclusive
#define snarl_value_range_check_min_exclusive snarl_check_min_exclusive
#define snarl_value_range_check_min_inclusive snarl_check_min_inclusive
#define snarl_value_type_check_class snarl_check_class
#define snarl_value_type_check_datatype snarl_check_datatype
#define snarl_value_type_check_node_kind snarl_check_node_kind

#ifdef __cplusplus
}
#endif

#endif /* SNARL_H */
