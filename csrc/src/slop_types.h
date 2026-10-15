#ifndef SLOP_types_H
#define SLOP_types_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"

typedef struct snarl_types_ShaclPath snarl_types_ShaclPath;
typedef struct snarl_types_Constraint snarl_types_Constraint;
typedef struct snarl_types_PropertyShape snarl_types_PropertyShape;
typedef struct snarl_types_NodeShape snarl_types_NodeShape;
typedef struct snarl_types_ShapesGraph snarl_types_ShapesGraph;
typedef struct snarl_types_ValidationResult snarl_types_ValidationResult;
typedef struct snarl_types_ValidationReport snarl_types_ValidationReport;
typedef struct snarl_types_ValidatorConfig snarl_types_ValidatorConfig;
typedef struct snarl_types_ValidatorResult snarl_types_ValidatorResult;

typedef enum {
    snarl_types_NodeKind_node_kind_blank_node,
    snarl_types_NodeKind_node_kind_iri,
    snarl_types_NodeKind_node_kind_literal,
    snarl_types_NodeKind_node_kind_blank_node_or_iri,
    snarl_types_NodeKind_node_kind_blank_node_or_literal,
    snarl_types_NodeKind_node_kind_iri_or_literal
} snarl_types_NodeKind;

typedef enum {
    snarl_types_Severity_severity_violation,
    snarl_types_Severity_severity_warning,
    snarl_types_Severity_severity_info
} snarl_types_Severity;

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

struct snarl_types_ValidatorConfig {
    uint8_t verbose;
    int64_t max_errors;
    uint8_t include_warnings;
    uint8_t include_infos;
};
typedef struct snarl_types_ValidatorConfig snarl_types_ValidatorConfig;

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATORCONFIG_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATORCONFIG_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidatorConfig, slop_option_snarl_types_ValidatorConfig)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_LIST_DECLARE(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_LIST_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_LIST_DECLARE(snarl_types_Constraint, slop_list_snarl_types_Constraint)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_LIST_DECLARE(snarl_types_PropertyShape, slop_list_snarl_types_PropertyShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_LIST_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_LIST_DECLARE(snarl_types_NodeShape, slop_list_snarl_types_NodeShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_LIST_DECLARE(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif

typedef enum {
    snarl_types_ShaclPath_path_predicate,
    snarl_types_ShaclPath_path_sequence,
    snarl_types_ShaclPath_path_alternative,
    snarl_types_ShaclPath_path_inverse,
    snarl_types_ShaclPath_path_zero_or_more,
    snarl_types_ShaclPath_path_one_or_more,
    snarl_types_ShaclPath_path_zero_or_one
} snarl_types_ShaclPath_tag;

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

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif

typedef enum {
    snarl_types_Constraint_con_class,
    snarl_types_Constraint_con_datatype,
    snarl_types_Constraint_con_node_kind,
    snarl_types_Constraint_con_min_count,
    snarl_types_Constraint_con_max_count,
    snarl_types_Constraint_con_min_inclusive,
    snarl_types_Constraint_con_max_inclusive,
    snarl_types_Constraint_con_min_exclusive,
    snarl_types_Constraint_con_max_exclusive,
    snarl_types_Constraint_con_min_length,
    snarl_types_Constraint_con_max_length,
    snarl_types_Constraint_con_pattern,
    snarl_types_Constraint_con_language_in,
    snarl_types_Constraint_con_unique_lang,
    snarl_types_Constraint_con_equals,
    snarl_types_Constraint_con_disjoint,
    snarl_types_Constraint_con_less_than,
    snarl_types_Constraint_con_less_than_or_equals,
    snarl_types_Constraint_con_not,
    snarl_types_Constraint_con_and,
    snarl_types_Constraint_con_or,
    snarl_types_Constraint_con_xone,
    snarl_types_Constraint_con_node,
    snarl_types_Constraint_con_property,
    snarl_types_Constraint_con_qualified_value_shape,
    snarl_types_Constraint_con_has_value,
    snarl_types_Constraint_con_in,
    snarl_types_Constraint_con_closed
} snarl_types_Constraint_tag;

struct snarl_types_Constraint {
    snarl_types_Constraint_tag tag;
    union {
        slop_rdf_rdf_Term con_class;
        slop_rdf_rdf_Term con_datatype;
        snarl_types_NodeKind con_node_kind;
        int64_t con_min_count;
        int64_t con_max_count;
        slop_rdf_rdf_Term con_min_inclusive;
        slop_rdf_rdf_Term con_max_inclusive;
        slop_rdf_rdf_Term con_min_exclusive;
        slop_rdf_rdf_Term con_max_exclusive;
        int64_t con_min_length;
        int64_t con_max_length;
        slop_string con_pattern;
        slop_list_string con_language_in;
        uint8_t con_unique_lang;
        snarl_types_ShaclPath con_equals;
        snarl_types_ShaclPath con_disjoint;
        snarl_types_ShaclPath con_less_than;
        snarl_types_ShaclPath con_less_than_or_equals;
        slop_rdf_rdf_Term con_not;
        slop_list_slop_rdf_rdf_Term con_and;
        slop_list_slop_rdf_rdf_Term con_or;
        slop_list_slop_rdf_rdf_Term con_xone;
        slop_rdf_rdf_Term con_node;
        slop_rdf_rdf_Term con_property;
        struct {
            slop_rdf_rdf_Term f0;
            int64_t f1;
            slop_option_int f2;
            uint8_t f3;
        } con_qualified_value_shape;
        slop_rdf_rdf_Term con_has_value;
        slop_list_slop_rdf_rdf_Term con_in;
        struct {
            uint8_t f0;
            slop_list_snarl_types_ShaclPath f1;
        } con_closed;
    } data;
};
typedef struct snarl_types_Constraint snarl_types_Constraint;

#ifndef SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_Constraint, slop_option_snarl_types_Constraint)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_CONSTRAINT_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_CONSTRAINT_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_Constraint, slop_list_snarl_types_Constraint)
#endif

struct snarl_types_PropertyShape {
    slop_rdf_rdf_Term id;
    snarl_types_ShaclPath path;
    slop_list_snarl_types_Constraint constraints;
    snarl_types_Severity severity;
    slop_option_string message;
    uint8_t deactivated;
};
typedef struct snarl_types_PropertyShape snarl_types_PropertyShape;

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_PropertyShape, slop_list_snarl_types_PropertyShape)
#endif

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

#ifndef SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeShape, slop_option_snarl_types_NodeShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_NODESHAPE_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_NODESHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_NodeShape, slop_list_snarl_types_NodeShape)
#endif

struct snarl_types_ShapesGraph {
    slop_list_snarl_types_NodeShape node_shapes;
    slop_list_snarl_types_PropertyShape property_shapes;
    slop_map* shape_map;
    slop_map* property_shape_map;
};
typedef struct snarl_types_ShapesGraph snarl_types_ShapesGraph;

#ifndef SLOP_OPTION_SNARL_TYPES_SHAPESGRAPH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHAPESGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShapesGraph, slop_option_snarl_types_ShapesGraph)
#endif

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

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif

struct snarl_types_ValidationReport {
    uint8_t conforms;
    slop_list_snarl_types_ValidationResult results;
};
typedef struct snarl_types_ValidationReport snarl_types_ValidationReport;

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONREPORT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONREPORT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationReport, slop_option_snarl_types_ValidationReport)
#endif

typedef enum {
    snarl_types_ValidatorResult_validate_success,
    snarl_types_ValidatorResult_validate_error
} snarl_types_ValidatorResult_tag;

struct snarl_types_ValidatorResult {
    snarl_types_ValidatorResult_tag tag;
    union {
        snarl_types_ValidationReport validate_success;
        slop_string validate_error;
    } data;
};
typedef struct snarl_types_ValidatorResult snarl_types_ValidatorResult;

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATORRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATORRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidatorResult, slop_option_snarl_types_ValidatorResult)
#endif

slop_string snarl_types_term_display_label(slop_rdf_rdf_Term t, slop_string fallback);
snarl_types_ValidationResult snarl_types_fixture_violation(slop_arena* arena);
snarl_types_ValidatorConfig snarl_types_default_validator_config(void);
snarl_types_ValidationReport snarl_types_make_validation_report(slop_arena* arena);
snarl_types_ValidationReport snarl_types_report_add_result(slop_arena* arena, snarl_types_ValidationReport report, snarl_types_ValidationResult result);
uint8_t snarl_types_report_conforms(snarl_types_ValidationReport report);

#ifndef SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHACLPATH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShaclPath, slop_option_snarl_types_ShaclPath)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_CONSTRAINT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_Constraint, slop_option_snarl_types_Constraint)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_PROPERTYSHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_PropertyShape, slop_option_snarl_types_PropertyShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
#define SLOP_OPTION_SNARL_TYPES_NODESHAPE_DEFINED
SLOP_OPTION_DEFINE(snarl_types_NodeShape, slop_option_snarl_types_NodeShape)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_SHAPESGRAPH_DEFINED
#define SLOP_OPTION_SNARL_TYPES_SHAPESGRAPH_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ShapesGraph, slop_option_snarl_types_ShapesGraph)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationResult, slop_option_snarl_types_ValidationResult)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATIONREPORT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATIONREPORT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidationReport, slop_option_snarl_types_ValidationReport)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATORCONFIG_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATORCONFIG_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidatorConfig, slop_option_snarl_types_ValidatorConfig)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_VALIDATORRESULT_DEFINED
#define SLOP_OPTION_SNARL_TYPES_VALIDATORRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_types_ValidatorResult, slop_option_snarl_types_ValidatorResult)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_SHACLPATH_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_ShaclPath, slop_list_snarl_types_ShaclPath)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_CONSTRAINT_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_CONSTRAINT_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_Constraint, slop_list_snarl_types_Constraint)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_PROPERTYSHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_PropertyShape, slop_list_snarl_types_PropertyShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_NODESHAPE_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_NODESHAPE_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_NodeShape, slop_list_snarl_types_NodeShape)
#endif

#ifndef SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
#define SLOP_LIST_SNARL_TYPES_VALIDATIONRESULT_IMPL_DEFINED
SLOP_LIST_IMPL(snarl_types_ValidationResult, slop_list_snarl_types_ValidationResult)
#endif


#endif
