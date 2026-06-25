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
struct index_TripleIndex {
    slop_map* spo;
    slop_map* pso;
    slop_map* osp;
};
typedef struct index_TripleIndex index_TripleIndex;

typedef int64_t rdf_BlankNodeId;

struct rdf_BlankNode {
    rdf_BlankNodeId id;
};
typedef struct rdf_BlankNode rdf_BlankNode;

typedef int64_t rdf_GraphSize;

struct rdf_IRI {
    slop_string value;
};
typedef struct rdf_IRI rdf_IRI;

struct rdf_Literal {
    slop_string value;
    slop_option_string datatype;
    slop_option_string lang;
};
typedef struct rdf_Literal rdf_Literal;

typedef enum {
    rdf_TermKind_iri,
    rdf_TermKind_blank,
    rdf_TermKind_literal,
    rdf_TermKind_triple
} rdf_TermKind;

typedef enum {
    rdf_Term_term_iri,
    rdf_Term_term_blank,
    rdf_Term_term_literal,
    rdf_Term_term_triple
} rdf_Term_tag;

typedef struct { size_t len; size_t cap; types_Constraint* data; } slop_list_types_Constraint;

typedef enum {
    types_NodeKind_node_kind_blank_node,
    types_NodeKind_node_kind_iri,
    types_NodeKind_node_kind_literal,
    types_NodeKind_node_kind_blank_node_or_iri,
    types_NodeKind_node_kind_blank_node_or_literal,
    types_NodeKind_node_kind_iri_or_literal
} types_NodeKind;

typedef struct { bool has_value; types_NodeKind value; } slop_option_types_NodeKind;

typedef enum {
    types_Severity_severity_violation,
    types_Severity_severity_warning,
    types_Severity_severity_info
} types_Severity;

typedef enum {
    types_ShaclPath_path_predicate,
    types_ShaclPath_path_sequence,
    types_ShaclPath_path_alternative,
    types_ShaclPath_path_inverse,
    types_ShaclPath_path_zero_or_more,
    types_ShaclPath_path_one_or_more,
    types_ShaclPath_path_zero_or_one
} types_ShaclPath_tag;

struct types_ValidatorConfig {
    uint8_t verbose;
    int64_t max_errors;
    uint8_t include_warnings;
    uint8_t include_infos;
};
typedef struct types_ValidatorConfig types_ValidatorConfig;

typedef enum {
    types_ValidatorResult_validate_success,
    types_ValidatorResult_validate_error
} types_ValidatorResult_tag;

typedef enum {
    xsd_XsdCompareResult_xsd_compare_less,
    xsd_XsdCompareResult_xsd_compare_equal,
    xsd_XsdCompareResult_xsd_compare_greater,
    xsd_XsdCompareResult_xsd_compare_incomparable
} xsd_XsdCompareResult;

typedef enum {
    xsd_XsdType_xsd_string,
    xsd_XsdType_xsd_integer,
    xsd_XsdType_xsd_decimal,
    xsd_XsdType_xsd_float,
    xsd_XsdType_xsd_double,
    xsd_XsdType_xsd_boolean,
    xsd_XsdType_xsd_unknown
} xsd_XsdType;

typedef enum {
    xsd_XsdValue_xsd_string_val,
    xsd_XsdValue_xsd_integer_val,
    xsd_XsdValue_xsd_decimal_val,
    xsd_XsdValue_xsd_float_val,
    xsd_XsdValue_xsd_double_val,
    xsd_XsdValue_xsd_boolean_val,
    xsd_XsdValue_xsd_unknown_val
} xsd_XsdValue_tag;

struct xsd_XsdValue {
    xsd_XsdValue_tag tag;
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
typedef struct xsd_XsdValue xsd_XsdValue;

struct index_IndexedGraph {
    slop_list_rdf_Triple triples;
    index_TripleIndex index;
    int64_t size;
};
typedef struct index_IndexedGraph index_IndexedGraph;

struct rdf_Graph {
    slop_list_rdf_Triple triples;
    rdf_GraphSize size;
};
typedef struct rdf_Graph rdf_Graph;

struct rdf_Term {
    rdf_Term_tag tag;
    union {
        rdf_IRI term_iri;
        rdf_BlankNode term_blank;
        rdf_Literal term_literal;
        rdf_Triple* term_triple;
    } data;
};
typedef struct rdf_Term rdf_Term;

struct rdf_Triple {
    rdf_Term subject;
    rdf_Term predicate;
    rdf_Term object;
};
typedef struct rdf_Triple rdf_Triple;

typedef struct { size_t len; size_t cap; rdf_Term* data; } slop_list_rdf_Term;

typedef struct { size_t len; size_t cap; rdf_Triple* data; } slop_list_rdf_Triple;

typedef struct { size_t len; size_t cap; types_NodeShape* data; } slop_list_types_NodeShape;

typedef struct { size_t len; size_t cap; types_PropertyShape* data; } slop_list_types_PropertyShape;

typedef struct { size_t len; size_t cap; types_ShaclPath* data; } slop_list_types_ShaclPath;

typedef struct { size_t len; size_t cap; types_ValidationResult* data; } slop_list_types_ValidationResult;

typedef struct { bool has_value; rdf_Term value; } slop_option_rdf_Term;

typedef struct { bool has_value; types_ShaclPath value; } slop_option_types_ShaclPath;

typedef struct { bool has_value; types_ValidationResult value; } slop_option_types_ValidationResult;

struct types_NodeShape {
    rdf_Term id;
    slop_list_rdf_Term target_nodes;
    slop_list_rdf_Term target_classes;
    slop_list_rdf_Term target_subjects_of;
    slop_list_rdf_Term target_objects_of;
    slop_list_types_PropertyShape property_shapes;
    slop_list_types_Constraint constraints;
    types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct types_NodeShape types_NodeShape;

struct types_PropertyShape {
    rdf_Term id;
    types_ShaclPath path;
    slop_list_types_Constraint constraints;
    types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct types_PropertyShape types_PropertyShape;

struct types_ShaclPath {
    types_ShaclPath_tag tag;
    union {
        rdf_Term path_predicate;
        slop_list_types_ShaclPath path_sequence;
        slop_list_types_ShaclPath path_alternative;
        types_ShaclPath* path_inverse;
        types_ShaclPath* path_zero_or_more;
        types_ShaclPath* path_one_or_more;
        types_ShaclPath* path_zero_or_one;
    } data;
};
typedef struct types_ShaclPath types_ShaclPath;

struct types_ShapesGraph {
    slop_list_types_NodeShape node_shapes;
    slop_list_types_PropertyShape property_shapes;
    slop_map* shape_map;
    slop_map* property_shape_map;
};
typedef struct types_ShapesGraph types_ShapesGraph;

struct types_ValidationReport {
    uint8_t conforms;
    slop_list_types_ValidationResult results;
};
typedef struct types_ValidationReport types_ValidationReport;

struct types_ValidationResult {
    rdf_Term focus_node;
    slop_option_types_ShaclPath result_path;
    slop_option_rdf_Term value;
    rdf_Term source_shape;
    slop_string source_constraint_component;
    types_Severity severity;
    slop_option_string message;
};
typedef struct types_ValidationResult types_ValidationResult;

struct types_ValidatorResult {
    types_ValidatorResult_tag tag;
    union {
        types_ValidationReport validate_success;
        slop_string validate_error;
    } data;
};
typedef struct types_ValidatorResult types_ValidatorResult;

/* Public API */
uint8_t rdf_blank_eq(rdf_BlankNode a, rdf_BlankNode b);
rdf_Graph rdf_graph_add(slop_arena* arena, rdf_Graph g, rdf_Triple t);
rdf_Graph rdf_graph_add_unchecked(slop_arena* arena, rdf_Graph g, rdf_Triple t);
uint8_t rdf_graph_contains(rdf_Graph g, rdf_Triple t);
void rdf_graph_free(rdf_Graph* g);
rdf_Graph rdf_graph_match(slop_arena* arena, rdf_Graph g, slop_option_rdf_Term subject, slop_option_rdf_Term predicate, slop_option_rdf_Term object);
rdf_Graph rdf_graph_remove(slop_arena* arena, rdf_Graph g, rdf_Triple t);
rdf_GraphSize rdf_graph_size(rdf_Graph g);
index_IndexedGraph rdf_indexed_graph_add(slop_arena* arena, index_IndexedGraph g, rdf_Triple t);
uint8_t rdf_indexed_graph_contains(index_IndexedGraph g, rdf_Triple t);
index_IndexedGraph rdf_indexed_graph_create(slop_arena* arena);
void rdf_indexed_graph_for_each(index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj, slop_closure_t callback);
slop_list_rdf_Triple rdf_indexed_graph_match(slop_arena* arena, index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj);
slop_list_rdf_Term rdf_indexed_graph_objects(slop_arena* arena, index_IndexedGraph g, rdf_Term subj, rdf_Term pred);
int64_t rdf_indexed_graph_size(index_IndexedGraph g);
slop_list_rdf_Term rdf_indexed_graph_subjects(slop_arena* arena, index_IndexedGraph g, rdf_Term pred, rdf_Term obj);
uint8_t rdf_iri_eq(rdf_IRI a, rdf_IRI b);
uint8_t rdf_list_contains(slop_arena* arena, rdf_Graph g, rdf_Term head, rdf_Term element);
slop_list_rdf_Term rdf_list_elements(slop_arena* arena, rdf_Graph g, rdf_Term head);
slop_list_rdf_Term rdf_list_elements_indexed(slop_arena* arena, index_IndexedGraph g, rdf_Term head);
int64_t rdf_list_length(slop_arena* arena, rdf_Graph g, rdf_Term head);
uint8_t rdf_literal_eq(rdf_Literal a, rdf_Literal b);
rdf_Term rdf_make_blank(slop_arena* arena, rdf_BlankNodeId id);
rdf_Graph rdf_make_graph(slop_arena* arena);
rdf_Term rdf_make_iri(slop_arena* arena, slop_string value);
rdf_Term rdf_make_literal(slop_arena* arena, slop_string value, slop_option_string datatype, slop_option_string lang);
rdf_Triple rdf_make_triple(slop_arena* arena, rdf_Term subject, rdf_Term predicate, rdf_Term object);
rdf_Term rdf_make_triple_term(slop_arena* arena, rdf_Triple t);
uint8_t rdf_option_string_eq(slop_option_string a, slop_option_string b);
uint8_t rdf_term_eq(rdf_Term a, rdf_Term b);
void rdf_term_free(rdf_Term* t);
rdf_TermKind rdf_term_kind(rdf_Term t);
uint8_t rdf_triple_eq(rdf_Triple a, rdf_Triple b);
void rdf_triple_free(rdf_Triple* t);
rdf_Term rdf_triple_object(rdf_Triple t);
rdf_Term rdf_triple_predicate(rdf_Triple t);
rdf_Term rdf_triple_subject(rdf_Triple t);
slop_option_types_ValidationResult snarl_check_and(slop_arena* arena, rdf_Term focus_node, uint8_t all_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_class, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_closed(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_types_ShaclPath allowed_paths, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_disjoint(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_equals(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_has_value(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, rdf_Term required_value, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_rdf_Term allowed_values, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_language_in(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_list_string allowed_langs, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_less_than_or_equals(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, types_ShaclPath other_path, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t max_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_max_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t max_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_count(slop_arena* arena, rdf_Term focus_node, int64_t value_count, int64_t min_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_exclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_inclusive(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term limit, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_min_length(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, int64_t min_len, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_node(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, uint8_t value_conforms, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_node_kind(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, types_NodeKind required_kind, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_not(slop_arena* arena, rdf_Term focus_node, uint8_t conforms_to_ref, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_or(slop_arena* arena, rdf_Term focus_node, uint8_t any_pass, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_pattern(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, slop_string pattern, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_qualified_value_shape(slop_arena* arena, rdf_Term focus_node, int64_t conforming_count, int64_t q_min, slop_option_int q_max, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_list_types_ValidationResult snarl_check_unique_lang(slop_arena* arena, rdf_Term focus_node, slop_list_rdf_Term value_nodes, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_xone(slop_arena* arena, rdf_Term focus_node, int64_t pass_count, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
uint8_t snarl_conforms(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph);
types_ValidatorConfig snarl_default_config(void);
types_ValidatorResult snarl_engine_validate(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_constraint(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, rdf_Term value_node, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited);
slop_list_types_ValidationResult snarl_evaluate_constraint_for_property(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term focus_node, slop_list_rdf_Term value_nodes, int64_t value_count, types_Constraint constraint, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message, slop_map* visited, slop_list_rdf_Term sibling_qvs_refs);
slop_list_types_ValidationResult snarl_evaluate_node_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_NodeShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config);
slop_list_types_ValidationResult snarl_evaluate_property_shape(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, types_PropertyShape shape, rdf_Term focus_node, slop_map* visited, types_ValidatorConfig config, slop_list_rdf_Term sibling_qvs_refs);
uint8_t snarl_evaluate_shape_against_node(slop_arena* arena, index_IndexedGraph data_graph, types_ShapesGraph shapes_graph, rdf_Term node, types_NodeShape shape, slop_map* visited);
int64_t snarl_get_result_count(types_ValidationReport report);
slop_list_types_ValidationResult snarl_get_violations(slop_arena* arena, types_ValidationReport report);
slop_list_types_ValidationResult snarl_get_warnings(slop_arena* arena, types_ValidationReport report);
slop_list_types_Constraint snarl_parse_constraints(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
slop_option_types_NodeKind snarl_parse_node_kind(rdf_Term term);
types_NodeShape snarl_parse_node_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_ShaclPath snarl_parse_path(slop_arena* arena, index_IndexedGraph g, rdf_Term path_node);
types_PropertyShape snarl_parse_property_shape(slop_arena* arena, index_IndexedGraph g, rdf_Term shape_id);
types_Severity snarl_parse_severity(rdf_Term term);
types_ShapesGraph snarl_parse_shapes_graph(slop_arena* arena, index_IndexedGraph shapes_graph);
slop_string snarl_path_to_display_string(slop_arena* arena, types_ShaclPath p);
void snarl_print_report(slop_arena* arena, types_ValidationReport report);
index_IndexedGraph snarl_report_to_graph(slop_arena* arena, types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, types_ValidationReport report);
slop_list_rdf_Term snarl_resolve_implicit_class_targets(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term shape_id);
slop_list_rdf_Term snarl_resolve_path(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, types_ShaclPath path);
slop_list_rdf_Term snarl_resolve_path_from(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term object, types_ShaclPath path);
slop_list_rdf_Term snarl_resolve_target_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term class_term);
slop_list_rdf_Term snarl_resolve_target_node(slop_arena* arena, slop_list_rdf_Term nodes);
slop_list_rdf_Term snarl_resolve_target_objects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_target_subjects_of(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term predicate);
slop_list_rdf_Term snarl_resolve_targets(slop_arena* arena, index_IndexedGraph data_graph, types_NodeShape shape);
slop_string snarl_severity_to_string(types_Severity sev);
slop_string snarl_term_to_display_string(slop_arena* arena, rdf_Term t);
types_ValidatorResult snarl_validate(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph);
types_ValidatorResult snarl_validate_with_config(slop_arena* arena, index_IndexedGraph data_graph, index_IndexedGraph shapes_graph, types_ValidatorConfig config);
xsd_XsdCompareResult xsd_compare(slop_arena* arena, rdf_Term a, rdf_Term b);
xsd_XsdCompareResult xsd_float_cmp(double a, double b);
slop_result_u8_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, rdf_Literal a, rdf_Literal b);
xsd_XsdType xsd_parse_type(slop_string datatype_iri);
slop_result_xsd_XsdValue_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, xsd_XsdType dtype);
uint8_t xsd_types_compatible(xsd_XsdType t1, xsd_XsdType t2);
uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri);
xsd_XsdCompareResult xsd_values_compare(xsd_XsdValue a, xsd_XsdValue b);
uint8_t xsd_values_equal(xsd_XsdValue a, xsd_XsdValue b);

#define cardinality_check_max_count snarl_check_max_count
#define cardinality_check_min_count snarl_check_min_count
#define engine_engine_validate snarl_engine_validate
#define engine_evaluate_constraint snarl_evaluate_constraint
#define engine_evaluate_constraint_for_property snarl_evaluate_constraint_for_property
#define engine_evaluate_node_shape snarl_evaluate_node_shape
#define engine_evaluate_property_shape snarl_evaluate_property_shape
#define engine_evaluate_shape_against_node snarl_evaluate_shape_against_node
#define index_indexed_graph_add rdf_indexed_graph_add
#define index_indexed_graph_contains rdf_indexed_graph_contains
#define index_indexed_graph_create rdf_indexed_graph_create
#define index_indexed_graph_for_each rdf_indexed_graph_for_each
#define index_indexed_graph_match rdf_indexed_graph_match
#define index_indexed_graph_objects rdf_indexed_graph_objects
#define index_indexed_graph_size rdf_indexed_graph_size
#define index_indexed_graph_subjects rdf_indexed_graph_subjects
#define list_rdf_list_contains rdf_list_contains
#define list_rdf_list_elements rdf_list_elements
#define list_rdf_list_elements_indexed rdf_list_elements_indexed
#define list_rdf_list_length rdf_list_length
#define logical_check_and snarl_check_and
#define logical_check_not snarl_check_not
#define logical_check_or snarl_check_or
#define logical_check_xone snarl_check_xone
#define other_check_closed snarl_check_closed
#define other_check_has_value snarl_check_has_value
#define other_check_in snarl_check_in
#define pair_check_disjoint snarl_check_disjoint
#define pair_check_equals snarl_check_equals
#define pair_check_less_than snarl_check_less_than
#define pair_check_less_than_or_equals snarl_check_less_than_or_equals
#define parse_parse_constraints snarl_parse_constraints
#define parse_parse_node_kind snarl_parse_node_kind
#define parse_parse_node_shape snarl_parse_node_shape
#define parse_parse_path snarl_parse_path
#define parse_parse_property_shape snarl_parse_property_shape
#define parse_parse_severity snarl_parse_severity
#define parse_parse_shapes_graph snarl_parse_shapes_graph
#define path_resolve_path snarl_resolve_path
#define path_resolve_path_from snarl_resolve_path_from
#define report_path_to_display_string snarl_path_to_display_string
#define report_print_report snarl_print_report
#define report_report_to_graph snarl_report_to_graph
#define report_report_to_string snarl_report_to_string
#define report_severity_to_string snarl_severity_to_string
#define report_term_to_display_string snarl_term_to_display_string
#define shape_check_node snarl_check_node
#define shape_check_qualified_value_shape snarl_check_qualified_value_shape
#define string_check_language_in snarl_check_language_in
#define string_check_max_length snarl_check_max_length
#define string_check_min_length snarl_check_min_length
#define string_check_pattern snarl_check_pattern
#define string_check_unique_lang snarl_check_unique_lang
#define target_resolve_implicit_class_targets snarl_resolve_implicit_class_targets
#define target_resolve_target_class snarl_resolve_target_class
#define target_resolve_target_node snarl_resolve_target_node
#define target_resolve_target_objects_of snarl_resolve_target_objects_of
#define target_resolve_target_subjects_of snarl_resolve_target_subjects_of
#define target_resolve_targets snarl_resolve_targets
#define value_range_check_max_exclusive snarl_check_max_exclusive
#define value_range_check_max_inclusive snarl_check_max_inclusive
#define value_range_check_min_exclusive snarl_check_min_exclusive
#define value_range_check_min_inclusive snarl_check_min_inclusive
#define value_type_check_class snarl_check_class
#define value_type_check_datatype snarl_check_datatype
#define value_type_check_node_kind snarl_check_node_kind
#define xsd_xsd_compare xsd_compare
#define xsd_xsd_parse_type xsd_parse_type
#define xsd_xsd_parse_value xsd_parse_value
#define xsd_xsd_types_compatible xsd_types_compatible
#define xsd_xsd_validate_lexical xsd_validate_lexical
#define xsd_xsd_values_compare xsd_values_compare
#define xsd_xsd_values_equal xsd_values_equal

#ifdef __cplusplus
}
#endif

#endif /* SNARL_H */
