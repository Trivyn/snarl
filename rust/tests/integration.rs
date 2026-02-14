use snarl::{
    conforms, get_result_count, get_violations, get_warnings, report_to_string, validate,
    validate_with_config, Arena, IndexedGraph, OwnedValidationReport, OwnedValidatorResult,
    Severity, Validator, ValidatorConfig, ValidatorResult,
};

const SH: &str = "http://www.w3.org/ns/shacl#";
const RDF: &str = "http://www.w3.org/1999/02/22-rdf-syntax-ns#";
const XSD: &str = "http://www.w3.org/2001/XMLSchema#";
const EX: &str = "http://example.org/";

/// Helper: build shapes graph with a single NodeShape that has sh:targetClass
/// and one property shape with sh:path + sh:minCount 1.
fn build_min_count_scenario(arena: &Arena, data: &mut IndexedGraph, shapes: &mut IndexedGraph) {
    let rdf_type = arena.make_iri(&format!("{RDF}type"));
    let sh_node_shape = arena.make_iri(&format!("{SH}NodeShape"));
    let sh_target_class = arena.make_iri(&format!("{SH}targetClass"));
    let sh_property = arena.make_iri(&format!("{SH}property"));
    let sh_path = arena.make_iri(&format!("{SH}path"));
    let sh_min_count = arena.make_iri(&format!("{SH}minCount"));

    let person_shape = arena.make_iri(&format!("{EX}PersonShape"));
    let person = arena.make_iri(&format!("{EX}Person"));
    let name = arena.make_iri(&format!("{EX}name"));
    let alice = arena.make_iri(&format!("{EX}alice"));
    let blank_ps = arena.make_blank(1);

    // Shapes graph
    shapes.add_triple(arena.make_triple(person_shape, rdf_type, sh_node_shape));
    shapes.add_triple(arena.make_triple(person_shape, sh_target_class, person));
    shapes.add_triple(arena.make_triple(person_shape, sh_property, blank_ps));
    shapes.add_triple(arena.make_triple(blank_ps, sh_path, name));
    let one = arena.make_literal("1", Some(&format!("{XSD}integer")), None);
    shapes.add_triple(arena.make_triple(blank_ps, sh_min_count, one));

    // Data graph: alice is a Person but has no name -> violation
    data.add_triple(arena.make_triple(alice, rdf_type, person));
}

// ---------------------------------------------------------------------------
// Basic tests
// ---------------------------------------------------------------------------

#[test]
fn empty_graph_conforms() {
    let arena = Arena::new(1024 * 1024);
    let data = IndexedGraph::new(&arena);
    let shapes = IndexedGraph::new(&arena);

    assert!(conforms(&arena, &data, &shapes));
}

#[test]
fn empty_graph_validate() {
    let arena = Arena::new(1024 * 1024);
    let data = IndexedGraph::new(&arena);
    let shapes = IndexedGraph::new(&arena);

    let result = validate(&arena, &data, &shapes);
    match result {
        ValidatorResult::Success(report) => {
            assert!(report.conforms);
            assert!(report.results.is_empty());
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// Violation tests
// ---------------------------------------------------------------------------

#[test]
fn simple_violation() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_min_count_scenario(&arena, &mut data, &mut shapes);

    let result = validate(&arena, &data, &shapes);
    match result {
        ValidatorResult::Success(report) => {
            assert!(!report.conforms, "should not conform");
            assert!(!report.results.is_empty(), "should have results");

            let violation = &report.results[0];
            assert_eq!(violation.severity, Severity::Violation);
            assert!(
                matches!(&violation.focus_node, snarl::Term::Iri(v) if v.ends_with("alice")),
                "focus node should be alice, got: {:?}",
                violation.focus_node
            );
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

#[test]
fn conforming_data() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);

    let rdf_type = arena.make_iri(&format!("{RDF}type"));
    let sh_node_shape = arena.make_iri(&format!("{SH}NodeShape"));
    let sh_target_class = arena.make_iri(&format!("{SH}targetClass"));
    let sh_property = arena.make_iri(&format!("{SH}property"));
    let sh_path = arena.make_iri(&format!("{SH}path"));
    let sh_min_count = arena.make_iri(&format!("{SH}minCount"));

    let person_shape = arena.make_iri(&format!("{EX}PersonShape"));
    let person = arena.make_iri(&format!("{EX}Person"));
    let name_prop = arena.make_iri(&format!("{EX}name"));
    let alice = arena.make_iri(&format!("{EX}alice"));
    let blank_ps = arena.make_blank(1);

    // Shapes
    shapes.add_triple(arena.make_triple(person_shape, rdf_type, sh_node_shape));
    shapes.add_triple(arena.make_triple(person_shape, sh_target_class, person));
    shapes.add_triple(arena.make_triple(person_shape, sh_property, blank_ps));
    shapes.add_triple(arena.make_triple(blank_ps, sh_path, name_prop));
    let one = arena.make_literal("1", Some(&format!("{XSD}integer")), None);
    shapes.add_triple(arena.make_triple(blank_ps, sh_min_count, one));

    // Data: alice has a name -> conforms
    data.add_triple(arena.make_triple(alice, rdf_type, person));
    let name_val = arena.make_literal("Alice", None, None);
    data.add_triple(arena.make_triple(alice, name_prop, name_val));

    assert!(conforms(&arena, &data, &shapes));
}

// ---------------------------------------------------------------------------
// Config tests
// ---------------------------------------------------------------------------

#[test]
fn validate_with_custom_config() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_min_count_scenario(&arena, &mut data, &mut shapes);

    let config = ValidatorConfig::new().verbose(false).max_errors(10);
    let result = validate_with_config(&arena, &data, &shapes, &config);
    match result {
        ValidatorResult::Success(report) => {
            assert!(!report.conforms);
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// Report accessor tests
// ---------------------------------------------------------------------------

#[test]
fn report_accessors() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_min_count_scenario(&arena, &mut data, &mut shapes);

    let result = validate(&arena, &data, &shapes);
    match result {
        ValidatorResult::Success(report) => {
            let count = get_result_count(&report);
            assert!(count > 0, "should have at least one result");

            let violations = get_violations(&arena, &report);
            assert!(!violations.is_empty(), "should have violations");
            assert_eq!(violations[0].severity, Severity::Violation);

            let warnings = get_warnings(&arena, &report);
            assert!(warnings.is_empty(), "should have no warnings");
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// report_to_string
// ---------------------------------------------------------------------------

#[test]
fn test_report_to_string() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_min_count_scenario(&arena, &mut data, &mut shapes);

    let result = validate(&arena, &data, &shapes);
    match result {
        ValidatorResult::Success(report) => {
            let s = report_to_string(&arena, &report);
            assert!(!s.is_empty(), "report string should not be empty");
            assert!(
                s.contains("Violation") || s.contains("ValidationResult") || s.contains("sh:"),
                "report should contain SHACL terms, got: {}",
                &s[..s.len().min(200)]
            );
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// Owned types
// ---------------------------------------------------------------------------

#[test]
fn owned_conversion() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_min_count_scenario(&arena, &mut data, &mut shapes);

    let result = validate(&arena, &data, &shapes);
    match result {
        ValidatorResult::Success(report) => {
            let owned: OwnedValidationReport = report.into();
            assert!(!owned.conforms);
            assert!(!owned.results.is_empty());
            assert_eq!(owned.results[0].severity, Severity::Violation);
        }
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// High-level Validator API tests
// ---------------------------------------------------------------------------

#[test]
fn validator_empty_conforms() {
    let v = Validator::new();
    assert!(v.conforms());
}

#[test]
fn validator_no_constraints_conforms() {
    let mut v = Validator::with_capacity(4 * 1024 * 1024);

    v.add_data_iri_triple(
        &format!("{EX}alice"),
        &format!("{RDF}type"),
        &format!("{EX}Person"),
    );

    assert!(v.conforms());

    match v.validate() {
        OwnedValidatorResult::Success(report) => {
            assert!(report.conforms);
            assert!(report.results.is_empty());
        }
        OwnedValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

#[test]
fn validator_with_violation() {
    let mut v = Validator::with_capacity(4 * 1024 * 1024);

    let rdf_type = v.make_iri(&format!("{RDF}type"));
    let sh_node_shape = v.make_iri(&format!("{SH}NodeShape"));
    let sh_target_class = v.make_iri(&format!("{SH}targetClass"));
    let sh_property = v.make_iri(&format!("{SH}property"));
    let sh_path = v.make_iri(&format!("{SH}path"));
    let sh_min_count = v.make_iri(&format!("{SH}minCount"));
    let person_shape = v.make_iri(&format!("{EX}PersonShape"));
    let person = v.make_iri(&format!("{EX}Person"));
    let name = v.make_iri(&format!("{EX}name"));
    let alice = v.make_iri(&format!("{EX}alice"));
    let blank_ps = v.make_blank(1);
    let one = v.make_literal("1", Some(&format!("{XSD}integer")), None);

    // Shapes graph
    let t = v.make_triple(person_shape, rdf_type, sh_node_shape);
    v.add_shapes_triple(t);
    let t = v.make_triple(person_shape, sh_target_class, person);
    v.add_shapes_triple(t);
    let t = v.make_triple(person_shape, sh_property, blank_ps);
    v.add_shapes_triple(t);
    let t = v.make_triple(blank_ps, sh_path, name);
    v.add_shapes_triple(t);
    let t = v.make_triple(blank_ps, sh_min_count, one);
    v.add_shapes_triple(t);

    // Data graph: alice is a Person but has no name
    let t = v.make_triple(alice, rdf_type, person);
    v.add_data_triple(t);

    assert!(!v.conforms());

    match v.validate() {
        OwnedValidatorResult::Success(report) => {
            assert!(!report.conforms);
            assert!(!report.results.is_empty());
            assert_eq!(report.results[0].severity, Severity::Violation);
        }
        OwnedValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
}

// ---------------------------------------------------------------------------
// Graph operations
// ---------------------------------------------------------------------------

#[test]
fn graph_add_and_query() {
    let arena = Arena::new(1024 * 1024);
    let mut graph = IndexedGraph::new(&arena);

    let s = arena.make_iri(&format!("{EX}fido"));
    let p = arena.make_iri(&format!("{RDF}type"));
    let o = arena.make_iri(&format!("{EX}Dog"));
    let triple = arena.make_triple(s, p, o);

    graph.add_triple(triple);
    assert_eq!(graph.size(), 1);
    assert!(graph.contains_triple(triple));
}

#[test]
fn graph_match_pattern() {
    let arena = Arena::new(1024 * 1024);
    let mut graph = IndexedGraph::new(&arena);

    let fido = arena.make_iri(&format!("{EX}fido"));
    let rex = arena.make_iri(&format!("{EX}rex"));
    let dog = arena.make_iri(&format!("{EX}Dog"));
    let a = arena.make_iri(&format!("{RDF}type"));

    graph.add_triple(arena.make_triple(fido, a, dog));
    graph.add_triple(arena.make_triple(rex, a, dog));

    let matches = graph.match_pattern(None, Some(a), Some(dog));
    assert_eq!(matches.len(), 2);
}

#[test]
fn literal_and_blank_terms() {
    let arena = Arena::new(1024 * 1024);

    let lit = arena.make_literal("hello", Some("http://www.w3.org/2001/XMLSchema#string"), None);
    let t = snarl::Term::from_ffi(lit);
    assert!(matches!(t, snarl::Term::Literal { value: "hello", .. }));

    let blank = arena.make_blank(42);
    let t = snarl::Term::from_ffi(blank);
    assert_eq!(t, snarl::Term::Blank(42));
}
