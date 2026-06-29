//! Raw FFI bindings matching the C types in `snarl.h` and `slop_runtime.h`.

use std::os::raw::{c_char, c_void};

/// Opaque arena allocator.
#[repr(C)]
pub struct SlopArena {
    _private: [u8; 0],
}

/// Length-prefixed string (not null-terminated).
#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopString {
    pub len: usize,
    pub data: *const c_char,
}

/// Optional string.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopOptionString {
    pub has_value: bool,
    pub value: SlopString,
}

// ---------------------------------------------------------------------------
// RDF types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfIri {
    pub value: SlopString,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfBlankNode {
    pub id: i64,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfLiteral {
    pub value: SlopString,
    pub datatype: SlopOptionString,
    pub lang: SlopOptionString,
}

/// Tag for the `rdf_Term` tagged union.
#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
pub enum RdfTermTag {
    Iri = 0,
    Blank = 1,
    Literal = 2,
}

/// Data payload for `rdf_Term` -- a C union.
#[repr(C)]
#[derive(Copy, Clone)]
pub union RdfTermData {
    pub term_iri: RdfIri,
    pub term_blank: RdfBlankNode,
    pub term_literal: RdfLiteral,
}

/// Tagged union representing an RDF term.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfTerm {
    pub tag: RdfTermTag,
    pub data: RdfTermData,
}

/// An RDF triple (subject, predicate, object).
#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfTriple {
    pub subject: RdfTerm,
    pub predicate: RdfTerm,
    pub object: RdfTerm,
}

// ---------------------------------------------------------------------------
// List types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopListRdfTerm {
    pub len: usize,
    pub cap: usize,
    pub data: *mut RdfTerm,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopListRdfTriple {
    pub len: usize,
    pub cap: usize,
    pub data: *mut RdfTriple,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopListValidationResult {
    pub len: usize,
    pub cap: usize,
    pub data: *mut ValidationResultFfi,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopListShaclPath {
    pub len: usize,
    pub cap: usize,
    pub data: *mut ShaclPath,
}

// ---------------------------------------------------------------------------
// Option types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopOptionRdfTerm {
    pub has_value: bool,
    pub value: RdfTerm,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopOptionShaclPath {
    pub has_value: bool,
    pub value: ShaclPath,
}

// ---------------------------------------------------------------------------
// Index types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone)]
pub struct TripleIndex {
    pub spo: *mut c_void,
    pub pso: *mut c_void,
    pub osp: *mut c_void,
    pub pos: *mut c_void,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct IndexedGraphFfi {
    pub triples: SlopListRdfTriple,
    pub index: TripleIndex,
    pub size: i64,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SnarlDataIndex {
    pub sp: *mut c_void,
    pub po: *mut c_void,
    pub p_subjects: *mut c_void,
    pub p_objects: *mut c_void,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct SnarlDataGraphFfi {
    pub triples: SlopListRdfTriple,
    pub index: SnarlDataIndex,
    pub size: i64,
}

// ---------------------------------------------------------------------------
// SHACL path types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
pub enum ShaclPathTag {
    Predicate = 0,
    Sequence = 1,
    Alternative = 2,
    Inverse = 3,
    ZeroOrMore = 4,
    OneOrMore = 5,
    ZeroOrOne = 6,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub union ShaclPathData {
    pub path_predicate: RdfTerm,
    pub path_sequence: SlopListShaclPath,
    pub path_alternative: SlopListShaclPath,
    pub path_inverse: *mut ShaclPath,
    pub path_zero_or_more: *mut ShaclPath,
    pub path_one_or_more: *mut ShaclPath,
    pub path_zero_or_one: *mut ShaclPath,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ShaclPath {
    pub tag: ShaclPathTag,
    pub data: ShaclPathData,
}

// ---------------------------------------------------------------------------
// Snarl-specific types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
pub enum Severity {
    Violation = 0,
    Warning = 1,
    Info = 2,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ValidatorConfigFfi {
    pub verbose: u8,
    pub max_errors: i64,
    pub include_warnings: u8,
    pub include_infos: u8,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ValidationReportFfi {
    pub conforms: u8,
    pub results: SlopListValidationResult,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ValidationResultFfi {
    pub focus_node: RdfTerm,
    pub result_path: SlopOptionShaclPath,
    pub value: SlopOptionRdfTerm,
    pub source_shape: RdfTerm,
    pub source_constraint_component: SlopString,
    pub severity: Severity,
    pub message: SlopOptionString,
}

#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
pub enum ValidatorResultTag {
    Success = 0,
    Error = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub union ValidatorResultData {
    pub validate_success: ValidationReportFfi,
    pub validate_error: SlopString,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ValidatorResultFfi {
    pub tag: ValidatorResultTag,
    pub data: ValidatorResultData,
}

// ---------------------------------------------------------------------------
// extern "C" declarations
// ---------------------------------------------------------------------------

extern "C" {
    // Arena and interning (from csrc_shim.c)
    pub fn snarl_arena_new(capacity: usize) -> *mut SlopArena;
    pub fn snarl_arena_free(arena: *mut SlopArena);
    pub fn snarl_intern_string(data: *const c_char, len: usize) -> SlopString;

    // Term constructors
    pub fn rdf_make_iri(arena: *mut SlopArena, value: SlopString) -> RdfTerm;
    pub fn rdf_make_blank(arena: *mut SlopArena, id: i64) -> RdfTerm;
    pub fn rdf_make_literal(
        arena: *mut SlopArena,
        value: SlopString,
        datatype: SlopOptionString,
        lang: SlopOptionString,
    ) -> RdfTerm;
    pub fn rdf_make_triple(
        arena: *mut SlopArena,
        subject: RdfTerm,
        predicate: RdfTerm,
        object: RdfTerm,
    ) -> RdfTriple;

    // Equality
    pub fn rdf_term_eq(a: RdfTerm, b: RdfTerm) -> u8;

    // IndexedGraph
    pub fn rdf_indexed_graph_create(arena: *mut SlopArena) -> IndexedGraphFfi;
    pub fn rdf_indexed_graph_add(
        arena: *mut SlopArena,
        g: IndexedGraphFfi,
        t: RdfTriple,
    ) -> IndexedGraphFfi;
    pub fn rdf_indexed_graph_contains(g: IndexedGraphFfi, t: RdfTriple) -> u8;
    pub fn rdf_indexed_graph_match(
        arena: *mut SlopArena,
        g: IndexedGraphFfi,
        subj: SlopOptionRdfTerm,
        pred: SlopOptionRdfTerm,
        obj: SlopOptionRdfTerm,
    ) -> SlopListRdfTriple;
    pub fn rdf_indexed_graph_size(g: IndexedGraphFfi) -> i64;
    pub fn rdf_indexed_graph_objects(
        arena: *mut SlopArena,
        g: IndexedGraphFfi,
        subj: RdfTerm,
        pred: RdfTerm,
    ) -> SlopListRdfTerm;
    pub fn rdf_indexed_graph_subjects(
        arena: *mut SlopArena,
        g: IndexedGraphFfi,
        pred: RdfTerm,
        obj: RdfTerm,
    ) -> SlopListRdfTerm;

    // SnarlDataGraph
    pub fn snarl_data_graph_create(arena: *mut SlopArena) -> SnarlDataGraphFfi;
    pub fn snarl_data_graph_add(
        arena: *mut SlopArena,
        g: SnarlDataGraphFfi,
        t: RdfTriple,
    ) -> SnarlDataGraphFfi;
    pub fn snarl_data_graph_size(g: SnarlDataGraphFfi) -> i64;
    pub fn snarl_data_graph_contains(g: SnarlDataGraphFfi, t: RdfTriple) -> u8;
    pub fn snarl_data_graph_from_indexed(
        arena: *mut SlopArena,
        g: IndexedGraphFfi,
    ) -> SnarlDataGraphFfi;
    pub fn snarl_data_graph_to_indexed(
        arena: *mut SlopArena,
        g: SnarlDataGraphFfi,
    ) -> IndexedGraphFfi;

    // Snarl API
    pub fn snarl_validate(
        arena: *mut SlopArena,
        data_graph: IndexedGraphFfi,
        shapes_graph: IndexedGraphFfi,
    ) -> ValidatorResultFfi;
    pub fn snarl_validate_with_config(
        arena: *mut SlopArena,
        data_graph: IndexedGraphFfi,
        shapes_graph: IndexedGraphFfi,
        config: ValidatorConfigFfi,
    ) -> ValidatorResultFfi;
    pub fn snarl_conforms(
        arena: *mut SlopArena,
        data_graph: IndexedGraphFfi,
        shapes_graph: IndexedGraphFfi,
    ) -> u8;
    pub fn snarl_validate_data_graph(
        arena: *mut SlopArena,
        data_graph: SnarlDataGraphFfi,
        shapes_graph: IndexedGraphFfi,
    ) -> ValidatorResultFfi;
    pub fn snarl_validate_data_graph_with_config(
        arena: *mut SlopArena,
        data_graph: SnarlDataGraphFfi,
        shapes_graph: IndexedGraphFfi,
        config: ValidatorConfigFfi,
    ) -> ValidatorResultFfi;
    pub fn snarl_conforms_data_graph(
        arena: *mut SlopArena,
        data_graph: SnarlDataGraphFfi,
        shapes_graph: IndexedGraphFfi,
    ) -> u8;
    pub fn snarl_default_config() -> ValidatorConfigFfi;
    pub fn snarl_get_violations(
        arena: *mut SlopArena,
        report: ValidationReportFfi,
    ) -> SlopListValidationResult;
    pub fn snarl_get_warnings(
        arena: *mut SlopArena,
        report: ValidationReportFfi,
    ) -> SlopListValidationResult;
    pub fn snarl_get_result_count(report: ValidationReportFfi) -> i64;
    pub fn snarl_report_to_graph(
        arena: *mut SlopArena,
        report: ValidationReportFfi,
    ) -> IndexedGraphFfi;
    pub fn snarl_report_to_string(arena: *mut SlopArena, report: ValidationReportFfi)
        -> SlopString;
    pub fn snarl_path_to_display_string(arena: *mut SlopArena, path: ShaclPath) -> SlopString;
}
