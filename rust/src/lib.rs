//! Safe Rust bindings for the Snarl SHACL Core validator.
//!
//! # Example
//! ```no_run
//! use snarl::{Arena, IndexedGraph, validate, ValidatorResult, Severity};
//!
//! let arena = Arena::new(4 * 1024 * 1024);
//! let mut data = IndexedGraph::new(&arena);
//! let mut shapes = IndexedGraph::new(&arena);
//!
//! // ... add triples to data and shapes graphs ...
//!
//! let result = validate(&arena, &data, &shapes);
//! match result {
//!     ValidatorResult::Success(report) => {
//!         println!("Conforms: {}", report.conforms);
//!         for r in &report.results {
//!             println!("  {:?}: {}", r.severity, r.focus_node);
//!         }
//!     }
//!     ValidatorResult::Error(msg) => eprintln!("Error: {}", msg),
//! }
//! ```

pub mod ffi;

use std::os::raw::c_char;

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------

/// Convert a `SlopString` to a Rust `&str`.
///
/// # Safety
/// The caller must ensure the `SlopString` data pointer is valid and the bytes
/// are valid UTF-8.
unsafe fn slop_string_to_str<'a>(s: ffi::SlopString) -> &'a str {
    if s.data.is_null() || s.len == 0 {
        return "";
    }
    let bytes = std::slice::from_raw_parts(s.data as *const u8, s.len);
    std::str::from_utf8_unchecked(bytes)
}

/// Convert a Rust `&str` to a `SlopString` by interning it.
fn str_to_slop_string(s: &str) -> ffi::SlopString {
    unsafe { ffi::snarl_intern_string(s.as_ptr() as *const c_char, s.len()) }
}

/// Convert `Option<&str>` to `SlopOptionString`.
fn option_str_to_slop(opt: Option<&str>) -> ffi::SlopOptionString {
    match opt {
        Some(s) => ffi::SlopOptionString {
            has_value: true,
            value: str_to_slop_string(s),
        },
        None => ffi::SlopOptionString {
            has_value: false,
            value: ffi::SlopString {
                len: 0,
                data: std::ptr::null(),
            },
        },
    }
}

/// Convert a `Term` to its FFI representation, using the arena for allocation.
fn term_to_ffi(arena: &Arena, term: &Term) -> ffi::RdfTerm {
    match term {
        Term::Iri(value) => arena.make_iri(value),
        Term::Blank(id) => arena.make_blank(*id),
        Term::Literal {
            value,
            datatype,
            lang,
        } => arena.make_literal(value, *datatype, *lang),
    }
}

/// Build a `SlopOptionRdfTerm` with `has_value = false`.
fn none_term() -> ffi::SlopOptionRdfTerm {
    ffi::SlopOptionRdfTerm {
        has_value: false,
        value: unsafe { std::mem::zeroed() },
    }
}

/// Build a `SlopOptionRdfTerm` with `has_value = true`.
fn some_term(t: ffi::RdfTerm) -> ffi::SlopOptionRdfTerm {
    ffi::SlopOptionRdfTerm {
        has_value: true,
        value: t,
    }
}

/// Convert a `SlopListRdfTerm` to `Vec<Term>`.
unsafe fn ffi_term_list_to_vec(list: ffi::SlopListRdfTerm) -> Vec<Term<'static>> {
    let mut v = Vec::with_capacity(list.len);
    for i in 0..list.len {
        let raw = *list.data.add(i);
        v.push(Term::from_ffi(raw));
    }
    v
}

/// Convert a `SlopListRdfTriple` to `Vec<Triple>`.
unsafe fn ffi_triple_list_to_vec(list: ffi::SlopListRdfTriple) -> Vec<Triple<'static>> {
    let mut v = Vec::with_capacity(list.len);
    for i in 0..list.len {
        let raw = *list.data.add(i);
        v.push(Triple::from_ffi(raw));
    }
    v
}

/// Convert a `SlopListValidationResult` to `Vec<ValidationResult>`.
unsafe fn ffi_validation_result_list_to_vec<'a>(
    list: ffi::SlopListValidationResult,
    arena: &Arena,
) -> Vec<ValidationResult<'a>> {
    let mut v = Vec::with_capacity(list.len);
    for i in 0..list.len {
        let raw = *list.data.add(i);
        v.push(ValidationResult::from_ffi(raw, arena));
    }
    v
}

// ---------------------------------------------------------------------------
// Arena
// ---------------------------------------------------------------------------

/// RAII wrapper around the C arena allocator.
///
/// All RDF terms and graphs created through this arena borrow from it.
/// The arena is freed when dropped.
pub struct Arena {
    ptr: *mut ffi::SlopArena,
}

impl Arena {
    /// Create a new arena with the given capacity in bytes.
    pub fn new(capacity: usize) -> Self {
        let ptr = unsafe { ffi::snarl_arena_new(capacity) };
        assert!(!ptr.is_null(), "snarl_arena_new returned NULL");
        Arena { ptr }
    }

    /// Create a new arena with the default capacity (1 MB).
    pub fn with_default_capacity() -> Self {
        Self::new(1024 * 1024)
    }

    /// Get the raw arena pointer (for FFI calls).
    pub fn as_ptr(&self) -> *mut ffi::SlopArena {
        self.ptr
    }

    /// Create an IRI term.
    pub fn make_iri(&self, value: &str) -> ffi::RdfTerm {
        unsafe { ffi::rdf_make_iri(self.ptr, str_to_slop_string(value)) }
    }

    /// Create a blank node term.
    pub fn make_blank(&self, id: i64) -> ffi::RdfTerm {
        unsafe { ffi::rdf_make_blank(self.ptr, id) }
    }

    /// Create a literal term with optional datatype and language tag.
    pub fn make_literal(
        &self,
        value: &str,
        datatype: Option<&str>,
        lang: Option<&str>,
    ) -> ffi::RdfTerm {
        unsafe {
            ffi::rdf_make_literal(
                self.ptr,
                str_to_slop_string(value),
                option_str_to_slop(datatype),
                option_str_to_slop(lang),
            )
        }
    }

    /// Create a triple from three terms.
    pub fn make_triple(
        &self,
        subject: ffi::RdfTerm,
        predicate: ffi::RdfTerm,
        object: ffi::RdfTerm,
    ) -> ffi::RdfTriple {
        unsafe { ffi::rdf_make_triple(self.ptr, subject, predicate, object) }
    }
}

impl Drop for Arena {
    fn drop(&mut self) {
        unsafe {
            ffi::snarl_arena_free(self.ptr);
        }
    }
}

// ---------------------------------------------------------------------------
// Term (read-side, safe)
// ---------------------------------------------------------------------------

/// A safe, read-side view of an RDF term.
///
/// The lifetime `'a` is tied to the arena that owns the string data.
#[derive(Debug, Clone, PartialEq)]
pub enum Term<'a> {
    Iri(&'a str),
    Blank(i64),
    Literal {
        value: &'a str,
        datatype: Option<&'a str>,
        lang: Option<&'a str>,
    },
}

impl<'a> Term<'a> {
    /// Convert from FFI representation.
    pub fn from_ffi(raw: ffi::RdfTerm) -> Term<'a> {
        unsafe {
            match raw.tag {
                ffi::RdfTermTag::Iri => Term::Iri(slop_string_to_str(raw.data.term_iri.value)),
                ffi::RdfTermTag::Blank => Term::Blank(raw.data.term_blank.id),
                ffi::RdfTermTag::Literal => {
                    let lit = raw.data.term_literal;
                    let dt = if lit.datatype.has_value {
                        Some(slop_string_to_str(lit.datatype.value))
                    } else {
                        None
                    };
                    let lang = if lit.lang.has_value {
                        Some(slop_string_to_str(lit.lang.value))
                    } else {
                        None
                    };
                    Term::Literal {
                        value: slop_string_to_str(lit.value),
                        datatype: dt,
                        lang,
                    }
                }
            }
        }
    }
}

impl<'a> std::fmt::Display for Term<'a> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Term::Iri(v) => write!(f, "<{}>", v),
            Term::Blank(id) => write!(f, "_:b{}", id),
            Term::Literal {
                value,
                datatype,
                lang,
            } => {
                write!(f, "\"{}\"", value)?;
                if let Some(dt) = datatype {
                    write!(f, "^^<{}>", dt)?;
                }
                if let Some(l) = lang {
                    write!(f, "@{}", l)?;
                }
                Ok(())
            }
        }
    }
}

// ---------------------------------------------------------------------------
// Triple (read-side, safe)
// ---------------------------------------------------------------------------

/// A safe, read-side view of an RDF triple.
#[derive(Debug, Clone, PartialEq)]
pub struct Triple<'a> {
    pub subject: Term<'a>,
    pub predicate: Term<'a>,
    pub object: Term<'a>,
}

impl<'a> Triple<'a> {
    /// Convert from FFI representation.
    pub fn from_ffi(raw: ffi::RdfTriple) -> Triple<'a> {
        Triple {
            subject: Term::from_ffi(raw.subject),
            predicate: Term::from_ffi(raw.predicate),
            object: Term::from_ffi(raw.object),
        }
    }
}

impl<'a> std::fmt::Display for Triple<'a> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} {} {} .", self.subject, self.predicate, self.object)
    }
}

// ---------------------------------------------------------------------------
// IndexedGraph
// ---------------------------------------------------------------------------

/// An indexed RDF graph backed by the C library's triple index.
pub struct IndexedGraph<'a> {
    raw: ffi::IndexedGraphFfi,
    arena: &'a Arena,
}

impl<'a> IndexedGraph<'a> {
    /// Create a new, empty indexed graph.
    pub fn new(arena: &'a Arena) -> Self {
        let raw = unsafe { ffi::rdf_indexed_graph_create(arena.as_ptr()) };
        IndexedGraph { raw, arena }
    }

    /// Add a raw FFI triple to the graph.
    pub fn add_triple(&mut self, triple: ffi::RdfTriple) {
        self.raw = unsafe { ffi::rdf_indexed_graph_add(self.arena.as_ptr(), self.raw, triple) };
    }

    /// Add a triple from safe `Term` values.
    pub fn add(&mut self, subject: &Term, predicate: &Term, object: &Term) {
        let s = term_to_ffi(self.arena, subject);
        let p = term_to_ffi(self.arena, predicate);
        let o = term_to_ffi(self.arena, object);
        let triple = self.arena.make_triple(s, p, o);
        self.add_triple(triple);
    }

    /// Check whether the graph contains the given triple.
    pub fn contains_triple(&self, triple: ffi::RdfTriple) -> bool {
        unsafe { ffi::rdf_indexed_graph_contains(self.raw, triple) != 0 }
    }

    /// Return the number of triples in the graph.
    pub fn size(&self) -> i64 {
        unsafe { ffi::rdf_indexed_graph_size(self.raw) }
    }

    /// Match triples by optional subject/predicate/object pattern.
    pub fn match_pattern(
        &self,
        subject: Option<ffi::RdfTerm>,
        predicate: Option<ffi::RdfTerm>,
        object: Option<ffi::RdfTerm>,
    ) -> Vec<Triple<'a>> {
        let subj = subject.map_or_else(none_term, some_term);
        let pred = predicate.map_or_else(none_term, some_term);
        let obj = object.map_or_else(none_term, some_term);
        unsafe {
            let list =
                ffi::rdf_indexed_graph_match(self.arena.as_ptr(), self.raw, subj, pred, obj);
            ffi_triple_list_to_vec(list)
        }
    }

    /// Get all objects for the given subject and predicate.
    pub fn objects(&self, subject: ffi::RdfTerm, predicate: ffi::RdfTerm) -> Vec<Term<'a>> {
        unsafe {
            let list =
                ffi::rdf_indexed_graph_objects(self.arena.as_ptr(), self.raw, subject, predicate);
            ffi_term_list_to_vec(list)
        }
    }

    /// Get all subjects for the given predicate and object.
    pub fn subjects(&self, predicate: ffi::RdfTerm, object: ffi::RdfTerm) -> Vec<Term<'a>> {
        unsafe {
            let list =
                ffi::rdf_indexed_graph_subjects(self.arena.as_ptr(), self.raw, predicate, object);
            ffi_term_list_to_vec(list)
        }
    }

    /// Get the raw FFI graph (for passing to validator functions).
    pub fn raw(&self) -> ffi::IndexedGraphFfi {
        self.raw
    }
}

// ---------------------------------------------------------------------------
// Severity
// ---------------------------------------------------------------------------

/// SHACL validation result severity.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Severity {
    Violation,
    Warning,
    Info,
}

impl Severity {
    fn from_ffi(raw: ffi::Severity) -> Self {
        match raw {
            ffi::Severity::Violation => Severity::Violation,
            ffi::Severity::Warning => Severity::Warning,
            ffi::Severity::Info => Severity::Info,
        }
    }
}

impl std::fmt::Display for Severity {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Severity::Violation => write!(f, "Violation"),
            Severity::Warning => write!(f, "Warning"),
            Severity::Info => write!(f, "Info"),
        }
    }
}

// ---------------------------------------------------------------------------
// ValidatorConfig
// ---------------------------------------------------------------------------

/// Configuration for the SHACL validator.
pub struct ValidatorConfig {
    raw: ffi::ValidatorConfigFfi,
}

impl ValidatorConfig {
    /// Create a new config with default values.
    pub fn new() -> Self {
        let raw = unsafe { ffi::snarl_default_config() };
        ValidatorConfig { raw }
    }

    pub fn verbose(mut self, v: bool) -> Self {
        self.raw.verbose = v as u8;
        self
    }

    pub fn max_errors(mut self, n: i64) -> Self {
        self.raw.max_errors = n;
        self
    }

    pub fn include_warnings(mut self, v: bool) -> Self {
        self.raw.include_warnings = v as u8;
        self
    }

    pub fn include_infos(mut self, v: bool) -> Self {
        self.raw.include_infos = v as u8;
        self
    }
}

impl Default for ValidatorConfig {
    fn default() -> Self {
        Self::new()
    }
}

// ---------------------------------------------------------------------------
// ValidationResult
// ---------------------------------------------------------------------------

/// A single validation result from the SHACL report.
#[derive(Debug, Clone)]
pub struct ValidationResult<'a> {
    pub focus_node: Term<'a>,
    pub result_path: Option<String>,
    pub value: Option<Term<'a>>,
    pub source_shape: Term<'a>,
    pub source_constraint_component: &'a str,
    pub severity: Severity,
    pub message: Option<&'a str>,
}

impl<'a> ValidationResult<'a> {
    unsafe fn from_ffi(raw: ffi::ValidationResultFfi, arena: &Arena) -> ValidationResult<'a> {
        let result_path = if raw.result_path.has_value {
            let display =
                ffi::snarl_path_to_display_string(arena.as_ptr(), raw.result_path.value);
            Some(slop_string_to_str(display).to_string())
        } else {
            None
        };

        let value = if raw.value.has_value {
            Some(Term::from_ffi(raw.value.value))
        } else {
            None
        };

        let message = if raw.message.has_value {
            Some(slop_string_to_str(raw.message.value))
        } else {
            None
        };

        ValidationResult {
            focus_node: Term::from_ffi(raw.focus_node),
            result_path,
            value,
            source_shape: Term::from_ffi(raw.source_shape),
            source_constraint_component: slop_string_to_str(raw.source_constraint_component),
            severity: Severity::from_ffi(raw.severity),
            message,
        }
    }
}

// ---------------------------------------------------------------------------
// ValidationReport
// ---------------------------------------------------------------------------

/// A SHACL validation report containing conformance status and results.
pub struct ValidationReport<'a> {
    pub conforms: bool,
    pub results: Vec<ValidationResult<'a>>,
    raw: ffi::ValidationReportFfi,
}

impl<'a> ValidationReport<'a> {
    unsafe fn from_ffi(raw: ffi::ValidationReportFfi, arena: &Arena) -> ValidationReport<'a> {
        let results = ffi_validation_result_list_to_vec(raw.results, arena);
        ValidationReport {
            conforms: raw.conforms != 0,
            results,
            raw,
        }
    }
}

// ---------------------------------------------------------------------------
// ValidatorResult
// ---------------------------------------------------------------------------

/// The result of running the SHACL validator.
pub enum ValidatorResult<'a> {
    /// Validation completed successfully.
    Success(ValidationReport<'a>),
    /// An error occurred during validation.
    Error(String),
}

impl<'a> ValidatorResult<'a> {
    unsafe fn from_ffi(raw: ffi::ValidatorResultFfi, arena: &Arena) -> ValidatorResult<'a> {
        match raw.tag {
            ffi::ValidatorResultTag::Success => {
                let report = ValidationReport::from_ffi(raw.data.validate_success, arena);
                ValidatorResult::Success(report)
            }
            ffi::ValidatorResultTag::Error => {
                let msg = slop_string_to_str(raw.data.validate_error);
                ValidatorResult::Error(msg.to_string())
            }
        }
    }
}

// ---------------------------------------------------------------------------
// Free functions
// ---------------------------------------------------------------------------

/// Validate a data graph against a shapes graph using default configuration.
pub fn validate<'a>(
    arena: &'a Arena,
    data_graph: &IndexedGraph,
    shapes_graph: &IndexedGraph,
) -> ValidatorResult<'a> {
    unsafe {
        let raw = ffi::snarl_validate(arena.as_ptr(), data_graph.raw(), shapes_graph.raw());
        ValidatorResult::from_ffi(raw, arena)
    }
}

/// Validate a data graph against a shapes graph with custom configuration.
pub fn validate_with_config<'a>(
    arena: &'a Arena,
    data_graph: &IndexedGraph,
    shapes_graph: &IndexedGraph,
    config: &ValidatorConfig,
) -> ValidatorResult<'a> {
    unsafe {
        let raw = ffi::snarl_validate_with_config(
            arena.as_ptr(),
            data_graph.raw(),
            shapes_graph.raw(),
            config.raw,
        );
        ValidatorResult::from_ffi(raw, arena)
    }
}

/// Check whether a data graph conforms to a shapes graph.
pub fn conforms(arena: &Arena, data_graph: &IndexedGraph, shapes_graph: &IndexedGraph) -> bool {
    unsafe { ffi::snarl_conforms(arena.as_ptr(), data_graph.raw(), shapes_graph.raw()) != 0 }
}

/// Get only the violation-severity results from a validation report.
pub fn get_violations<'a>(
    arena: &'a Arena,
    report: &ValidationReport,
) -> Vec<ValidationResult<'a>> {
    unsafe {
        let list = ffi::snarl_get_violations(arena.as_ptr(), report.raw);
        ffi_validation_result_list_to_vec(list, arena)
    }
}

/// Get only the warning-severity results from a validation report.
pub fn get_warnings<'a>(
    arena: &'a Arena,
    report: &ValidationReport,
) -> Vec<ValidationResult<'a>> {
    unsafe {
        let list = ffi::snarl_get_warnings(arena.as_ptr(), report.raw);
        ffi_validation_result_list_to_vec(list, arena)
    }
}

/// Get the total number of results in a validation report.
pub fn get_result_count(report: &ValidationReport) -> i64 {
    unsafe { ffi::snarl_get_result_count(report.raw) }
}

/// Convert a validation report to an RDF graph.
pub fn report_to_graph<'a>(arena: &'a Arena, report: &ValidationReport) -> IndexedGraph<'a> {
    let raw = unsafe { ffi::snarl_report_to_graph(arena.as_ptr(), report.raw) };
    IndexedGraph { raw, arena }
}

/// Serialize a validation report as a Turtle string.
pub fn report_to_string(arena: &Arena, report: &ValidationReport) -> String {
    unsafe {
        let s = ffi::snarl_report_to_string(arena.as_ptr(), report.raw);
        slop_string_to_str(s).to_string()
    }
}

// ---------------------------------------------------------------------------
// Owned types (no lifetimes, safe to send across threads)
// ---------------------------------------------------------------------------

/// Owned RDF term -- uses String, no lifetime dependency on arena.
#[derive(Debug, Clone, PartialEq)]
pub enum OwnedTerm {
    Iri(String),
    Blank(i64),
    Literal {
        value: String,
        datatype: Option<String>,
        lang: Option<String>,
    },
}

impl<'a> From<Term<'a>> for OwnedTerm {
    fn from(t: Term<'a>) -> Self {
        match t {
            Term::Iri(v) => OwnedTerm::Iri(v.to_string()),
            Term::Blank(id) => OwnedTerm::Blank(id),
            Term::Literal {
                value,
                datatype,
                lang,
            } => OwnedTerm::Literal {
                value: value.to_string(),
                datatype: datatype.map(|s| s.to_string()),
                lang: lang.map(|s| s.to_string()),
            },
        }
    }
}

impl std::fmt::Display for OwnedTerm {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            OwnedTerm::Iri(v) => write!(f, "<{}>", v),
            OwnedTerm::Blank(id) => write!(f, "_:b{}", id),
            OwnedTerm::Literal {
                value,
                datatype,
                lang,
            } => {
                write!(f, "\"{}\"", value)?;
                if let Some(dt) = datatype {
                    write!(f, "^^<{}>", dt)?;
                }
                if let Some(l) = lang {
                    write!(f, "@{}", l)?;
                }
                Ok(())
            }
        }
    }
}

/// Owned RDF triple.
#[derive(Debug, Clone, PartialEq)]
pub struct OwnedTriple {
    pub subject: OwnedTerm,
    pub predicate: OwnedTerm,
    pub object: OwnedTerm,
}

impl<'a> From<Triple<'a>> for OwnedTriple {
    fn from(t: Triple<'a>) -> Self {
        OwnedTriple {
            subject: OwnedTerm::from(t.subject),
            predicate: OwnedTerm::from(t.predicate),
            object: OwnedTerm::from(t.object),
        }
    }
}

impl std::fmt::Display for OwnedTriple {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} {} {} .", self.subject, self.predicate, self.object)
    }
}

/// Owned validation result -- no lifetime dependency.
#[derive(Debug, Clone)]
pub struct OwnedValidationResult {
    pub focus_node: OwnedTerm,
    pub result_path: Option<String>,
    pub value: Option<OwnedTerm>,
    pub source_shape: OwnedTerm,
    pub source_constraint_component: String,
    pub severity: Severity,
    pub message: Option<String>,
}

impl<'a> From<ValidationResult<'a>> for OwnedValidationResult {
    fn from(r: ValidationResult<'a>) -> Self {
        OwnedValidationResult {
            focus_node: OwnedTerm::from(r.focus_node),
            result_path: r.result_path,
            value: r.value.map(OwnedTerm::from),
            source_shape: OwnedTerm::from(r.source_shape),
            source_constraint_component: r.source_constraint_component.to_string(),
            severity: r.severity,
            message: r.message.map(|s| s.to_string()),
        }
    }
}

/// Owned validation report -- no lifetime dependency.
#[derive(Debug, Clone)]
pub struct OwnedValidationReport {
    pub conforms: bool,
    pub results: Vec<OwnedValidationResult>,
}

impl<'a> From<ValidationReport<'a>> for OwnedValidationReport {
    fn from(r: ValidationReport<'a>) -> Self {
        OwnedValidationReport {
            conforms: r.conforms,
            results: r.results.into_iter().map(OwnedValidationResult::from).collect(),
        }
    }
}

/// Owned validator result -- no lifetime dependency.
pub enum OwnedValidatorResult {
    /// Validation completed successfully.
    Success(OwnedValidationReport),
    /// An error occurred during validation.
    Error(String),
}

// ---------------------------------------------------------------------------
// Validator (high-level, owns its Arena)
// ---------------------------------------------------------------------------

/// High-level SHACL validator that owns its arena and graphs.
///
/// This struct hides the arena/FFI details and provides a simple API
/// for loading triples and running validation. The `OwnedValidatorResult`
/// contains owned data that can be freely sent across threads.
///
/// # Example
/// ```no_run
/// use snarl::{Validator, OwnedValidatorResult, OwnedTerm, Severity};
///
/// let mut v = Validator::new();
///
/// // Add data triples
/// v.add_data_iri_triple(
///     "http://example.org/alice",
///     "http://www.w3.org/1999/02/22-rdf-syntax-ns#type",
///     "http://example.org/Person",
/// );
///
/// // Add shapes triples
/// v.add_shapes_iri_triple(
///     "http://example.org/PersonShape",
///     "http://www.w3.org/1999/02/22-rdf-syntax-ns#type",
///     "http://www.w3.org/ns/shacl#NodeShape",
/// );
///
/// match v.validate() {
///     OwnedValidatorResult::Success(report) => {
///         println!("Conforms: {}", report.conforms);
///     }
///     OwnedValidatorResult::Error(msg) => {
///         eprintln!("Error: {}", msg);
///     }
/// }
/// ```
pub struct Validator {
    arena: Arena,
    data_raw: ffi::IndexedGraphFfi,
    shapes_raw: ffi::IndexedGraphFfi,
}

impl Validator {
    /// Create a new validator with 32 MB arena.
    pub fn new() -> Self {
        Self::with_capacity(32 * 1024 * 1024)
    }

    /// Create a new validator with the given arena capacity in bytes.
    pub fn with_capacity(bytes: usize) -> Self {
        let arena = Arena::new(bytes);
        let data_raw = unsafe { ffi::rdf_indexed_graph_create(arena.as_ptr()) };
        let shapes_raw = unsafe { ffi::rdf_indexed_graph_create(arena.as_ptr()) };
        Validator {
            arena,
            data_raw,
            shapes_raw,
        }
    }

    /// Create an IRI term using this validator's arena.
    pub fn make_iri(&self, value: &str) -> ffi::RdfTerm {
        self.arena.make_iri(value)
    }

    /// Create a blank node term using this validator's arena.
    pub fn make_blank(&self, id: i64) -> ffi::RdfTerm {
        self.arena.make_blank(id)
    }

    /// Create a literal term using this validator's arena.
    pub fn make_literal(
        &self,
        value: &str,
        datatype: Option<&str>,
        lang: Option<&str>,
    ) -> ffi::RdfTerm {
        self.arena.make_literal(value, datatype, lang)
    }

    /// Create a triple from three terms using this validator's arena.
    pub fn make_triple(
        &self,
        subject: ffi::RdfTerm,
        predicate: ffi::RdfTerm,
        object: ffi::RdfTerm,
    ) -> ffi::RdfTriple {
        self.arena.make_triple(subject, predicate, object)
    }

    /// Add a triple to the data graph.
    pub fn add_data_triple(&mut self, triple: ffi::RdfTriple) {
        self.data_raw =
            unsafe { ffi::rdf_indexed_graph_add(self.arena.as_ptr(), self.data_raw, triple) };
    }

    /// Convenience: add a triple where all three terms are IRIs to the data graph.
    pub fn add_data_iri_triple(&mut self, s: &str, p: &str, o: &str) {
        let sf = self.arena.make_iri(s);
        let pf = self.arena.make_iri(p);
        let of = self.arena.make_iri(o);
        let triple = self.arena.make_triple(sf, pf, of);
        self.add_data_triple(triple);
    }

    /// Add a triple to the shapes graph.
    pub fn add_shapes_triple(&mut self, triple: ffi::RdfTriple) {
        self.shapes_raw =
            unsafe { ffi::rdf_indexed_graph_add(self.arena.as_ptr(), self.shapes_raw, triple) };
    }

    /// Convenience: add a triple where all three terms are IRIs to the shapes graph.
    pub fn add_shapes_iri_triple(&mut self, s: &str, p: &str, o: &str) {
        let sf = self.arena.make_iri(s);
        let pf = self.arena.make_iri(p);
        let of = self.arena.make_iri(o);
        let triple = self.arena.make_triple(sf, pf, of);
        self.add_shapes_triple(triple);
    }

    /// Run SHACL validation with default configuration.
    pub fn validate(&self) -> OwnedValidatorResult {
        unsafe {
            let raw = ffi::snarl_validate(self.arena.as_ptr(), self.data_raw, self.shapes_raw);
            self.convert_result(raw)
        }
    }

    /// Check whether the data graph conforms to the shapes graph.
    pub fn conforms(&self) -> bool {
        unsafe { ffi::snarl_conforms(self.arena.as_ptr(), self.data_raw, self.shapes_raw) != 0 }
    }

    // -- private helpers --

    unsafe fn convert_result(&self, raw: ffi::ValidatorResultFfi) -> OwnedValidatorResult {
        match raw.tag {
            ffi::ValidatorResultTag::Success => {
                let report_raw = raw.data.validate_success;
                let results = self.convert_results(report_raw.results);
                OwnedValidatorResult::Success(OwnedValidationReport {
                    conforms: report_raw.conforms != 0,
                    results,
                })
            }
            ffi::ValidatorResultTag::Error => {
                let msg = slop_string_to_str(raw.data.validate_error);
                OwnedValidatorResult::Error(msg.to_string())
            }
        }
    }

    unsafe fn convert_results(
        &self,
        list: ffi::SlopListValidationResult,
    ) -> Vec<OwnedValidationResult> {
        let mut results = Vec::with_capacity(list.len);
        for i in 0..list.len {
            let raw = *list.data.add(i);
            results.push(self.convert_validation_result(raw));
        }
        results
    }

    unsafe fn convert_validation_result(
        &self,
        raw: ffi::ValidationResultFfi,
    ) -> OwnedValidationResult {
        let result_path = if raw.result_path.has_value {
            let display =
                ffi::snarl_path_to_display_string(self.arena.as_ptr(), raw.result_path.value);
            Some(slop_string_to_str(display).to_string())
        } else {
            None
        };

        OwnedValidationResult {
            focus_node: OwnedTerm::from(Term::from_ffi(raw.focus_node)),
            result_path,
            value: if raw.value.has_value {
                Some(OwnedTerm::from(Term::from_ffi(raw.value.value)))
            } else {
                None
            },
            source_shape: OwnedTerm::from(Term::from_ffi(raw.source_shape)),
            source_constraint_component: slop_string_to_str(raw.source_constraint_component)
                .to_string(),
            severity: Severity::from_ffi(raw.severity),
            message: if raw.message.has_value {
                Some(slop_string_to_str(raw.message.value).to_string())
            } else {
                None
            },
        }
    }
}

impl Default for Validator {
    fn default() -> Self {
        Self::new()
    }
}
