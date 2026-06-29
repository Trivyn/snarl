#ifndef SLOP_types_H
#define SLOP_types_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"

typedef struct types_ShaclPath types_ShaclPath;
typedef struct types_Constraint types_Constraint;
typedef struct types_PropertyShape types_PropertyShape;
typedef struct types_NodeShape types_NodeShape;
typedef struct types_ShapesGraph types_ShapesGraph;
typedef struct types_ValidationResult types_ValidationResult;
typedef struct types_ValidationReport types_ValidationReport;
typedef struct types_ValidatorConfig types_ValidatorConfig;
typedef struct types_ValidatorResult types_ValidatorResult;

typedef enum {
    types_NodeKind_node_kind_blank_node,
    types_NodeKind_node_kind_iri,
    types_NodeKind_node_kind_literal,
    types_NodeKind_node_kind_blank_node_or_iri,
    types_NodeKind_node_kind_blank_node_or_literal,
    types_NodeKind_node_kind_iri_or_literal
} types_NodeKind;

typedef enum {
    types_Severity_severity_violation,
    types_Severity_severity_warning,
    types_Severity_severity_info
} types_Severity;

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

struct types_ValidatorConfig {
    uint8_t verbose;
    int64_t max_errors;
    uint8_t include_warnings;
    uint8_t include_infos;
};
typedef struct types_ValidatorConfig types_ValidatorConfig;

#ifndef SLOP_OPTION_TYPES_VALIDATORCONFIG_DEFINED
#define SLOP_OPTION_TYPES_VALIDATORCONFIG_DEFINED
SLOP_OPTION_DEFINE(types_ValidatorConfig, slop_option_types_ValidatorConfig)
#endif

#ifndef SLOP_LIST_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_TYPES_SHACLPATH_DEFINED
SLOP_LIST_DECLARE(types_ShaclPath, slop_list_types_ShaclPath)
#endif

#ifndef SLOP_LIST_TYPES_CONSTRAINT_DEFINED
#define SLOP_LIST_TYPES_CONSTRAINT_DEFINED
SLOP_LIST_DECLARE(types_Constraint, slop_list_types_Constraint)
#endif

#ifndef SLOP_LIST_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_LIST_TYPES_PROPERTYSHAPE_DEFINED
SLOP_LIST_DECLARE(types_PropertyShape, slop_list_types_PropertyShape)
#endif

#ifndef SLOP_LIST_TYPES_NODESHAPE_DEFINED
#define SLOP_LIST_TYPES_NODESHAPE_DEFINED
SLOP_LIST_DECLARE(types_NodeShape, slop_list_types_NodeShape)
#endif

#ifndef SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_TYPES_VALIDATIONRESULT_DEFINED
SLOP_LIST_DECLARE(types_ValidationResult, slop_list_types_ValidationResult)
#endif

typedef enum {
    types_ShaclPath_path_predicate,
    types_ShaclPath_path_sequence,
    types_ShaclPath_path_alternative,
    types_ShaclPath_path_inverse,
    types_ShaclPath_path_zero_or_more,
    types_ShaclPath_path_one_or_more,
    types_ShaclPath_path_zero_or_one
} types_ShaclPath_tag;

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

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_LIST_TYPES_SHACLPATH_IMPL_DEFINED
#define SLOP_LIST_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_IMPL(types_ShaclPath, slop_list_types_ShaclPath)
#endif

typedef enum {
    types_Constraint_con_class,
    types_Constraint_con_datatype,
    types_Constraint_con_node_kind,
    types_Constraint_con_min_count,
    types_Constraint_con_max_count,
    types_Constraint_con_min_inclusive,
    types_Constraint_con_max_inclusive,
    types_Constraint_con_min_exclusive,
    types_Constraint_con_max_exclusive,
    types_Constraint_con_min_length,
    types_Constraint_con_max_length,
    types_Constraint_con_pattern,
    types_Constraint_con_language_in,
    types_Constraint_con_unique_lang,
    types_Constraint_con_equals,
    types_Constraint_con_disjoint,
    types_Constraint_con_less_than,
    types_Constraint_con_less_than_or_equals,
    types_Constraint_con_not,
    types_Constraint_con_and,
    types_Constraint_con_or,
    types_Constraint_con_xone,
    types_Constraint_con_node,
    types_Constraint_con_property,
    types_Constraint_con_qualified_value_shape,
    types_Constraint_con_has_value,
    types_Constraint_con_in,
    types_Constraint_con_closed
} types_Constraint_tag;

struct types_Constraint {
    types_Constraint_tag tag;
    union {
        rdf_Term con_class;
        rdf_Term con_datatype;
        types_NodeKind con_node_kind;
        int64_t con_min_count;
        int64_t con_max_count;
        rdf_Term con_min_inclusive;
        rdf_Term con_max_inclusive;
        rdf_Term con_min_exclusive;
        rdf_Term con_max_exclusive;
        int64_t con_min_length;
        int64_t con_max_length;
        slop_string con_pattern;
        slop_list_string con_language_in;
        uint8_t con_unique_lang;
        types_ShaclPath con_equals;
        types_ShaclPath con_disjoint;
        types_ShaclPath con_less_than;
        types_ShaclPath con_less_than_or_equals;
        rdf_Term con_not;
        slop_list_rdf_Term con_and;
        slop_list_rdf_Term con_or;
        slop_list_rdf_Term con_xone;
        rdf_Term con_node;
        rdf_Term con_property;
        struct {
            rdf_Term f0;
            int64_t f1;
            slop_option_int f2;
            uint8_t f3;
        } con_qualified_value_shape;
        rdf_Term con_has_value;
        slop_list_rdf_Term con_in;
        struct {
            uint8_t f0;
            slop_list_types_ShaclPath f1;
        } con_closed;
    } data;
};
typedef struct types_Constraint types_Constraint;

#ifndef SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(types_Constraint, slop_option_types_Constraint)
#endif

#ifndef SLOP_LIST_TYPES_CONSTRAINT_IMPL_DEFINED
#define SLOP_LIST_TYPES_CONSTRAINT_IMPL_DEFINED
SLOP_LIST_IMPL(types_Constraint, slop_list_types_Constraint)
#endif

struct types_PropertyShape {
    rdf_Term id;
    types_ShaclPath path;
    slop_list_types_Constraint constraints;
    types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct types_PropertyShape types_PropertyShape;

#ifndef SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(types_PropertyShape, slop_option_types_PropertyShape)
#endif

#ifndef SLOP_LIST_TYPES_PROPERTYSHAPE_IMPL_DEFINED
#define SLOP_LIST_TYPES_PROPERTYSHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(types_PropertyShape, slop_list_types_PropertyShape)
#endif

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

#ifndef SLOP_OPTION_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(types_NodeShape, slop_option_types_NodeShape)
#endif

#ifndef SLOP_LIST_TYPES_NODESHAPE_IMPL_DEFINED
#define SLOP_LIST_TYPES_NODESHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(types_NodeShape, slop_list_types_NodeShape)
#endif

struct types_ShapesGraph {
    slop_list_types_NodeShape node_shapes;
    slop_list_types_PropertyShape property_shapes;
    slop_map* shape_map;
    slop_map* property_shape_map;
};
typedef struct types_ShapesGraph types_ShapesGraph;

#ifndef SLOP_OPTION_TYPES_SHAPESGRAPH_DEFINED
#define SLOP_OPTION_TYPES_SHAPESGRAPH_DEFINED
SLOP_OPTION_DEFINE(types_ShapesGraph, slop_option_types_ShapesGraph)
#endif

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

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

#ifndef SLOP_LIST_TYPES_VALIDATIONRESULT_IMPL_DEFINED
#define SLOP_LIST_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_IMPL(types_ValidationResult, slop_list_types_ValidationResult)
#endif

struct types_ValidationReport {
    uint8_t conforms;
    slop_list_types_ValidationResult results;
};
typedef struct types_ValidationReport types_ValidationReport;

#ifndef SLOP_OPTION_TYPES_VALIDATIONREPORT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONREPORT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationReport, slop_option_types_ValidationReport)
#endif

typedef enum {
    types_ValidatorResult_validate_success,
    types_ValidatorResult_validate_error
} types_ValidatorResult_tag;

struct types_ValidatorResult {
    types_ValidatorResult_tag tag;
    union {
        types_ValidationReport validate_success;
        slop_string validate_error;
    } data;
};
typedef struct types_ValidatorResult types_ValidatorResult;

#ifndef SLOP_OPTION_TYPES_VALIDATORRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATORRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidatorResult, slop_option_types_ValidatorResult)
#endif

types_ValidationResult types_fixture_violation(slop_arena* arena);
types_ValidatorConfig types_default_validator_config(void);
types_ValidationReport types_make_validation_report(slop_arena* arena);
types_ValidationReport types_report_add_result(slop_arena* arena, types_ValidationReport report, types_ValidationResult result);
uint8_t types_report_conforms(types_ValidationReport report);

#ifndef SLOP_OPTION_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(types_ShaclPath, slop_option_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(types_Constraint, slop_option_types_Constraint)
#endif

#ifndef SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(types_PropertyShape, slop_option_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(types_NodeShape, slop_option_types_NodeShape)
#endif

#ifndef SLOP_OPTION_TYPES_SHAPESGRAPH_DEFINED
#define SLOP_OPTION_TYPES_SHAPESGRAPH_DEFINED
SLOP_OPTION_DEFINE(types_ShapesGraph, slop_option_types_ShapesGraph)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationResult, slop_option_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATIONREPORT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATIONREPORT_DEFINED
SLOP_OPTION_DEFINE(types_ValidationReport, slop_option_types_ValidationReport)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATORCONFIG_DEFINED
#define SLOP_OPTION_TYPES_VALIDATORCONFIG_DEFINED
SLOP_OPTION_DEFINE(types_ValidatorConfig, slop_option_types_ValidatorConfig)
#endif

#ifndef SLOP_OPTION_TYPES_VALIDATORRESULT_DEFINED
#define SLOP_OPTION_TYPES_VALIDATORRESULT_DEFINED
SLOP_OPTION_DEFINE(types_ValidatorResult, slop_option_types_ValidatorResult)
#endif


#endif
