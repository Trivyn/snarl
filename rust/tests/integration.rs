use snarl::{
    conforms, get_result_count, get_violations, get_warnings, infer, report_to_string, validate,
    validate_data_graph, validate_data_graph_with_inference, validate_with_config, Arena,
    IndexedGraph, InferResult, Inference, OwnedValidationReport, RuleOrder,
    OwnedValidatorResult, Severity, SnarlDataGraph, Validator, ValidatorConfig, ValidatorResult,
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

/// sh:pattern runs through the vendored regex engine (vendor/regex) on every
/// platform, matching code points rather than UTF-8 bytes.
#[test]
fn pattern_matches_code_points() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = IndexedGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);

    let rdf_type = arena.make_iri(&format!("{RDF}type"));
    let word_shape = arena.make_iri(&format!("{EX}WordShape"));
    let word = arena.make_iri(&format!("{EX}Word"));
    let name = arena.make_iri(&format!("{EX}name"));
    let prop = arena.make_blank(1);

    shapes.add_triple(arena.make_triple(word_shape, rdf_type, arena.make_iri(&format!("{SH}NodeShape"))));
    shapes.add_triple(arena.make_triple(word_shape, arena.make_iri(&format!("{SH}targetClass")), word));
    shapes.add_triple(arena.make_triple(word_shape, arena.make_iri(&format!("{SH}property")), prop));
    shapes.add_triple(arena.make_triple(prop, arena.make_iri(&format!("{SH}path")), name));
    shapes.add_triple(arena.make_triple(
        prop,
        arena.make_iri(&format!("{SH}pattern")),
        arena.make_literal("^.{4}$", None, None),
    ));

    // Four characters each (five and seven bytes): conform
    for (node, value) in [("jose", "José"), ("smile", "ab😀c")] {
        let n = arena.make_iri(&format!("{EX}{node}"));
        data.add_triple(arena.make_triple(n, rdf_type, word));
        data.add_triple(arena.make_triple(n, name, arena.make_literal(value, None, None)));
    }
    // Three characters, four bytes: violates
    let zoe = arena.make_iri(&format!("{EX}zoe"));
    data.add_triple(arena.make_triple(zoe, rdf_type, word));
    data.add_triple(arena.make_triple(zoe, name, arena.make_literal("Zoë", None, None)));

    match validate(&arena, &data, &shapes) {
        ValidatorResult::Success(report) => {
            assert_eq!(report.results.len(), 1, "only Zoë should violate");
            assert!(
                matches!(&report.results[0].focus_node, snarl::Term::Iri(v) if v.ends_with("zoe")),
                "focus node should be zoe, got: {:?}",
                report.results[0].focus_node
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

#[test]
fn fast_data_graph_validate() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);

    let rdf_type = arena.make_iri(&format!("{RDF}type"));
    let sh_node_shape = arena.make_iri(&format!("{SH}NodeShape"));
    let sh_target_class = arena.make_iri(&format!("{SH}targetClass"));
    let person_shape = arena.make_iri(&format!("{EX}PersonShape"));
    let person = arena.make_iri(&format!("{EX}Person"));
    let alice = arena.make_iri(&format!("{EX}alice"));

    shapes.add_triple(arena.make_triple(person_shape, rdf_type, sh_node_shape));
    shapes.add_triple(arena.make_triple(person_shape, sh_target_class, person));
    data.add_triple(arena.make_triple(alice, rdf_type, person));

    match validate_data_graph(&arena, &data, &shapes) {
        ValidatorResult::Success(report) => assert!(report.conforms),
        ValidatorResult::Error(msg) => panic!("unexpected error: {}", msg),
    }
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

    let lit = arena.make_literal(
        "hello",
        Some("http://www.w3.org/2001/XMLSchema#string"),
        None,
    );
    let t = snarl::Term::from_ffi(lit);
    assert!(matches!(t, snarl::Term::Literal { value: "hello", .. }));

    let blank = arena.make_blank(42);
    let t = snarl::Term::from_ffi(blank);
    assert_eq!(t, snarl::Term::Blank(42));
}

#[test]
fn rdf12_triple_term_round_trip() {
    let arena = Arena::new(1024 * 1024);

    let subject = arena.make_iri(&format!("{EX}stmt"));
    let predicate = arena.make_iri(&format!("{EX}says"));
    let object = arena.make_literal("hello", None, None);
    let raw_triple = arena.make_triple(subject, predicate, object);
    let raw_term = arena.make_triple_term(raw_triple);

    let term = snarl::Term::from_ffi(raw_term);
    match term {
        snarl::Term::Triple(t) => {
            assert!(matches!(t.subject, snarl::Term::Iri(v) if v.ends_with("stmt")));
            assert!(matches!(t.predicate, snarl::Term::Iri(v) if v.ends_with("says")));
            assert!(matches!(
                t.object,
                snarl::Term::Literal { value: "hello", .. }
            ));
        }
        other => panic!("expected triple term, got {other:?}"),
    }
}

// ---------------------------------------------------------------------------
// SHACL-AF (non-SPARQL subset)
// ---------------------------------------------------------------------------

/// Shapes: every ex:Person gets `ex:status ex:checked` from a TripleRule, and
/// everything with an ex:status needs an ex:label. Data: alice, a Person
/// with no label -- conforms without rules, one violation with them.
fn build_rule_scenario(arena: &Arena, data: &mut SnarlDataGraph, shapes: &mut IndexedGraph) {
    let iri = |s: &str| arena.make_iri(s);
    let rdf_type = iri(&format!("{RDF}type"));
    let person_shape = iri(&format!("{EX}PersonShape"));
    let status_shape = iri(&format!("{EX}StatusShape"));
    let rule = arena.make_blank(1);
    let prop = arena.make_blank(2);
    let status = iri(&format!("{EX}status"));

    shapes.add_triple(arena.make_triple(person_shape, rdf_type, iri(&format!("{SH}NodeShape"))));
    shapes.add_triple(arena.make_triple(person_shape, iri(&format!("{SH}targetClass")), iri(&format!("{EX}Person"))));
    shapes.add_triple(arena.make_triple(person_shape, iri(&format!("{SH}rule")), rule));
    shapes.add_triple(arena.make_triple(rule, rdf_type, iri(&format!("{SH}TripleRule"))));
    shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}subject")), iri(&format!("{SH}this"))));
    shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}predicate")), status));
    shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}object")), iri(&format!("{EX}checked"))));

    shapes.add_triple(arena.make_triple(status_shape, rdf_type, iri(&format!("{SH}NodeShape"))));
    shapes.add_triple(arena.make_triple(status_shape, iri(&format!("{SH}targetSubjectsOf")), status));
    shapes.add_triple(arena.make_triple(status_shape, iri(&format!("{SH}property")), prop));
    shapes.add_triple(arena.make_triple(prop, iri(&format!("{SH}path")), iri(&format!("{EX}label"))));
    let one = arena.make_literal("1", Some(&format!("{XSD}integer")), None);
    shapes.add_triple(arena.make_triple(prop, iri(&format!("{SH}minCount")), one));

    data.add_triple(arena.make_triple(iri(&format!("{EX}alice")), rdf_type, iri(&format!("{EX}Person"))));
}

#[test]
fn rules_do_not_run_by_default() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut data, &mut shapes);
    let (result, inferred) =
        validate_data_graph_with_inference(&arena, &mut data, &shapes, &ValidatorConfig::new());
    assert!(inferred.inferred.is_empty());
    assert!(inferred.deferred.is_empty());
    match result {
        ValidatorResult::Success(report) => assert!(report.conforms),
        ValidatorResult::Error(msg) => panic!("unexpected error: {msg}"),
    }
}

#[test]
fn rules_infer_then_validate() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut data, &mut shapes);
    let before = data.size();
    let config = ValidatorConfig::new().run_rules(true);
    let (result, inferred) = validate_data_graph_with_inference(&arena, &mut data, &shapes, &config);
    assert_eq!(inferred.inferred.len(), 1);
    assert_eq!(
        inferred.inferred[0].triple.to_string(),
        format!("<{EX}alice> <{EX}status> <{EX}checked> .")
    );
    assert!(matches!(inferred.inferred[0].rule, snarl::Term::Blank(1)));
    assert!(matches!(inferred.inferred[0].focus_node, snarl::Term::Iri(v) if v.ends_with("alice")));
    assert_eq!(data.size(), before + 1, "the caller's graph handle sees the inferred triple");
    match result {
        ValidatorResult::Success(report) => assert_eq!(report.results.len(), 1),
        ValidatorResult::Error(msg) => panic!("unexpected error: {msg}"),
    }
}

#[test]
fn infer_without_validating() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut data, &mut shapes);
    match infer(&arena, &mut data, &shapes, &ValidatorConfig::new()) {
        InferResult::Success(inference) => {
            assert_eq!(inference.triples().len(), 1);
            assert_eq!(data.size(), 2);
        }
        InferResult::Error(msg) => panic!("unexpected error: {msg}"),
    }
}

#[test]
fn sparql_rule_is_an_error() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut data, &mut shapes);
    let rule = arena.make_blank(3);
    shapes.add_triple(arena.make_triple(
        arena.make_iri(&format!("{EX}PersonShape")),
        arena.make_iri(&format!("{SH}rule")),
        rule,
    ));
    shapes.add_triple(arena.make_triple(
        rule,
        arena.make_iri(&format!("{RDF}type")),
        arena.make_iri(&format!("{SH}SPARQLRule")),
    ));
    match infer(&arena, &mut data, &shapes, &ValidatorConfig::new()) {
        InferResult::Error(msg) => assert!(msg.contains("SPARQLRule"), "{msg}"),
        InferResult::Success(_) => panic!("expected an error for sh:SPARQLRule"),
    }
}

#[test]
fn expression_result_carries_source_constraint() {
    let mut v = Validator::new();
    let expr = v.make_blank(1);
    let shape = v.make_iri(&format!("{EX}S"));
    let t = |v: &Validator, s, p: &str, o| v.make_triple(s, v.make_iri(p), o);
    v.add_shapes_triple(t(&v, shape, &format!("{RDF}type"), v.make_iri(&format!("{SH}NodeShape"))));
    v.add_shapes_triple(t(&v, shape, &format!("{SH}targetNode"), v.make_iri(&format!("{EX}a"))));
    v.add_shapes_triple(t(&v, shape, &format!("{SH}expression"), expr));
    v.add_shapes_triple(t(&v, expr, &format!("{SH}path"), v.make_iri(&format!("{EX}ok"))));
    match v.validate() {
        OwnedValidatorResult::Success(report) => {
            assert_eq!(report.results.len(), 1);
            let r = &report.results[0];
            assert!(r.source_constraint_component.ends_with("ExpressionConstraintComponent"));
            assert!(r.source_constraint.is_some());
        }
        OwnedValidatorResult::Error(msg) => panic!("unexpected error: {msg}"),
    }
}

// ---------------------------------------------------------------------------
// SPARQL rules beside triple rules (0.8.1)
// ---------------------------------------------------------------------------

/// `build_rule_scenario` plus an `sh:SPARQLRule` (ex:SparqlRule, sh:order 5) on
/// ex:PersonShape, which itself gets sh:order 2.
fn build_mixed_rule_scenario(arena: &Arena, data: &mut SnarlDataGraph, shapes: &mut IndexedGraph) {
    build_rule_scenario(arena, data, shapes);
    let iri = |s: &str| arena.make_iri(s);
    let person_shape = iri(&format!("{EX}PersonShape"));
    let sparql_rule = iri(&format!("{EX}SparqlRule"));
    let dec = |v: &str| arena.make_literal(v, Some(&format!("{XSD}decimal")), None);
    shapes.add_triple(arena.make_triple(person_shape, iri(&format!("{SH}order")), dec("2")));
    shapes.add_triple(arena.make_triple(person_shape, iri(&format!("{SH}rule")), sparql_rule));
    shapes.add_triple(arena.make_triple(sparql_rule, iri(&format!("{RDF}type")), iri(&format!("{SH}SPARQLRule"))));
    shapes.add_triple(arena.make_triple(sparql_rule, iri(&format!("{SH}order")), dec("5")));
    let construct = arena.make_literal("CONSTRUCT { $this <http://example.org/seen> true } WHERE { }", None, None);
    shapes.add_triple(arena.make_triple(sparql_rule, iri(&format!("{SH}construct")), construct));
}

fn expect_inference<'a>(result: InferResult<'a>) -> Inference<'a> {
    match result {
        InferResult::Success(inference) => inference,
        InferResult::Error(msg) => panic!("unexpected error: {msg}"),
    }
}

#[test]
fn sparql_rule_is_ignored_when_no_rules_run() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut plain_data = SnarlDataGraph::new(&arena);
    let mut plain_shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut plain_data, &mut plain_shapes);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_mixed_rule_scenario(&arena, &mut data, &mut shapes);

    let config = ValidatorConfig::new();
    let (plain, _) = validate_data_graph_with_inference(&arena, &mut plain_data, &plain_shapes, &config);
    let (mixed, inference) = validate_data_graph_with_inference(&arena, &mut data, &shapes, &config);
    assert!(inference.inferred.is_empty() && inference.deferred.is_empty());
    match (plain, mixed) {
        (ValidatorResult::Success(a), ValidatorResult::Success(b)) => {
            assert_eq!(report_to_string(&arena, &a), report_to_string(&arena, &b));
            assert!(b.conforms);
        }
        _ => panic!("validation that runs no rules must not fail on an sh:SPARQLRule"),
    }

    // The same graphs through the IndexedGraph entry point and the Validator.
    let data_ig = data.to_indexed();
    assert!(conforms(&arena, &data_ig, &shapes));
}

#[test]
fn sparql_rule_fails_when_rules_run_without_deferral() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_mixed_rule_scenario(&arena, &mut data, &mut shapes);

    let config = ValidatorConfig::new().run_rules(true);
    let (result, _) = validate_data_graph_with_inference(&arena, &mut data, &shapes, &config);
    match result {
        ValidatorResult::Error(msg) => assert!(msg.contains("sh:SPARQLRule"), "{msg}"),
        ValidatorResult::Success(_) => panic!("expected an error: the rules run"),
    }

    // Declaring the entailment makes plain validation run the rules too.
    shapes.add_triple(arena.make_triple(
        arena.make_iri(&format!("{EX}Shapes")),
        arena.make_iri(&format!("{SH}entailment")),
        arena.make_iri(&format!("{SH}Rules")),
    ));
    let (result, _) =
        validate_data_graph_with_inference(&arena, &mut data, &shapes, &ValidatorConfig::new());
    assert!(matches!(result, ValidatorResult::Error(_)));
}

#[test]
fn deferred_sparql_rule_is_reported_with_shape_and_order() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_mixed_rule_scenario(&arena, &mut data, &mut shapes);

    let config = ValidatorConfig::new().defer_sparql_rules(true);
    let inference = expect_inference(infer(&arena, &mut data, &shapes, &config));
    assert_eq!(inference.inferred.len(), 1, "the triple rule still runs");
    assert_eq!(inference.deferred.len(), 1);
    let d = &inference.deferred[0];
    assert!(matches!(d.rule, snarl::Term::Iri(v) if v.ends_with("SparqlRule")));
    assert!(matches!(d.shape, snarl::Term::Iri(v) if v.ends_with("PersonShape")));
    assert_eq!(d.order, RuleOrder::new(2.0, 5.0));

    // SHACL 1.2 mode ignores the shape's sh:order.
    let mut data12 = SnarlDataGraph::new(&arena);
    let mut shapes12 = IndexedGraph::new(&arena);
    build_mixed_rule_scenario(&arena, &mut data12, &mut shapes12);
    let config12 = ValidatorConfig::new().defer_sparql_rules(true).shacl12(true);
    let inference12 = expect_inference(infer(&arena, &mut data12, &shapes12, &config12));
    assert_eq!(inference12.deferred[0].order, RuleOrder::new(0.0, 5.0));

    // Validation with deferral reports it in the outcome as well.
    let mut data_v = SnarlDataGraph::new(&arena);
    let mut shapes_v = IndexedGraph::new(&arena);
    build_mixed_rule_scenario(&arena, &mut data_v, &mut shapes_v);
    let config_v = ValidatorConfig::new().run_rules(true).defer_sparql_rules(true);
    let (result, outcome) = validate_data_graph_with_inference(&arena, &mut data_v, &shapes_v, &config_v);
    assert!(matches!(result, ValidatorResult::Success(_)));
    assert_eq!(outcome.inferred.len(), 1);
    assert_eq!(outcome.deferred.len(), 1);
}

#[test]
fn deferral_does_not_cover_unknown_rule_types() {
    let arena = Arena::new(4 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_rule_scenario(&arena, &mut data, &mut shapes);
    let rule = arena.make_blank(7);
    shapes.add_triple(arena.make_triple(
        arena.make_iri(&format!("{EX}PersonShape")),
        arena.make_iri(&format!("{SH}rule")),
        rule,
    ));
    shapes.add_triple(arena.make_triple(
        rule,
        arena.make_iri(&format!("{RDF}type")),
        arena.make_iri(&format!("{EX}ScriptRule")),
    ));
    let config = ValidatorConfig::new().defer_sparql_rules(true);
    match infer(&arena, &mut data, &shapes, &config) {
        InferResult::Error(msg) => assert!(msg.contains("Unsupported SHACL rule type"), "{msg}"),
        InferResult::Success(_) => panic!("expected an error for an unknown rule type"),
    }
}

/// One shape targeting ex:n with three rules, at rule order 1, 2 and 3. Rule k
/// adds `ex:n ex:p<k> true`; rules 2 and 3 only fire once ex:n has ex:p1 /
/// ex:p2 (an sh:condition shape with sh:minCount 1).
fn build_three_level_scenario(arena: &Arena, data: &mut SnarlDataGraph, shapes: &mut IndexedGraph) {
    let iri = |s: &str| arena.make_iri(s);
    let int = |v: &str| arena.make_literal(v, Some(&format!("{XSD}integer")), None);
    let tru = arena.make_literal("true", Some(&format!("{XSD}boolean")), None);
    let rdf_type = iri(&format!("{RDF}type"));
    let shape = iri(&format!("{EX}NodeShape"));
    let n = iri(&format!("{EX}n"));
    data.add_triple(arena.make_triple(n, rdf_type, iri(&format!("{EX}Node"))));
    shapes.add_triple(arena.make_triple(shape, rdf_type, iri(&format!("{SH}NodeShape"))));
    shapes.add_triple(arena.make_triple(shape, iri(&format!("{SH}targetClass")), iri(&format!("{EX}Node"))));
    for k in 1..=3 {
        let rule = iri(&format!("{EX}Rule{k}"));
        shapes.add_triple(arena.make_triple(shape, iri(&format!("{SH}rule")), rule));
        shapes.add_triple(arena.make_triple(rule, rdf_type, iri(&format!("{SH}TripleRule"))));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}order")), int(&k.to_string())));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}subject")), iri(&format!("{SH}this"))));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}predicate")), iri(&format!("{EX}p{k}"))));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}object")), tru));
        if k > 1 {
            let cond = iri(&format!("{EX}HasP{}", k - 1));
            let prop = arena.make_blank(100 + k as i64);
            shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}condition")), cond));
            shapes.add_triple(arena.make_triple(cond, iri(&format!("{SH}property")), prop));
            shapes.add_triple(arena.make_triple(prop, iri(&format!("{SH}path")), iri(&format!("{EX}p{}", k - 1))));
            shapes.add_triple(arena.make_triple(prop, iri(&format!("{SH}minCount")), int("1")));
        }
    }
}

fn level(k: f64) -> Option<RuleOrder> {
    Some(RuleOrder::new(0.0, k))
}

#[test]
fn order_range_runs_only_rules_in_range() {
    let arena = Arena::new(8 * 1024 * 1024);
    let count = |min: Option<RuleOrder>, max: Option<RuleOrder>| {
        let mut data = SnarlDataGraph::new(&arena);
        let mut shapes = IndexedGraph::new(&arena);
        build_three_level_scenario(&arena, &mut data, &mut shapes);
        let config = ValidatorConfig::new().order_min(min).order_max(max);
        expect_inference(infer(&arena, &mut data, &shapes, &config)).inferred.len()
    };
    assert_eq!(count(None, None), 3);
    assert_eq!(count(None, level(1.0)), 1, "upper bound is inclusive");
    assert_eq!(count(None, level(2.0)), 2);
    assert_eq!(count(level(1.0), level(1.0)), 1);
    assert_eq!(count(level(2.0), None), 0, "level 2 needs level 1's triple, which did not run");
    assert_eq!(count(level(3.0), level(1.0)), 0, "an empty range runs nothing");
    assert_eq!(count(None, Some(RuleOrder::new(-1.0, 9.0))), 0, "shape order compares first");
}

#[test]
fn order_range_steps_one_level_at_a_time() {
    let arena = Arena::new(8 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    build_three_level_scenario(&arena, &mut data, &mut shapes);
    for k in 1..=3 {
        let config = ValidatorConfig::new().order_min(level(k as f64)).order_max(level(k as f64));
        let inference = expect_inference(infer(&arena, &mut data, &shapes, &config));
        assert_eq!(inference.inferred.len(), 1, "level {k}");
        let it = &inference.inferred[0];
        assert_eq!(it.triple.predicate.to_string(), format!("<{EX}p{k}>"));
        assert!(matches!(it.rule, snarl::Term::Iri(v) if v.ends_with(&format!("Rule{k}"))));
        assert!(matches!(it.focus_node, snarl::Term::Iri(v) if v.ends_with("/n")));
    }
    assert_eq!(data.size(), 4);
}

#[test]
fn inferred_triples_name_their_rule_and_focus_node() {
    let arena = Arena::new(8 * 1024 * 1024);
    let mut data = SnarlDataGraph::new(&arena);
    let mut shapes = IndexedGraph::new(&arena);
    let iri = |s: &str| arena.make_iri(s);
    let rdf_type = iri(&format!("{RDF}type"));
    let shape = iri(&format!("{EX}NodeShape"));
    for n in ["n1", "n2"] {
        data.add_triple(arena.make_triple(iri(&format!("{EX}{n}")), rdf_type, iri(&format!("{EX}Node"))));
    }
    shapes.add_triple(arena.make_triple(shape, rdf_type, iri(&format!("{SH}NodeShape"))));
    shapes.add_triple(arena.make_triple(shape, iri(&format!("{SH}targetClass")), iri(&format!("{EX}Node"))));
    // RuleA and RuleB each add one triple per focus node; RuleC repeats
    // RuleA's; RuleD adds one triple whatever the focus node.
    let rules = [
        ("RuleA", format!("{SH}this"), "p", "v"),
        ("RuleB", format!("{SH}this"), "q", "w"),
        ("RuleC", format!("{SH}this"), "p", "v"),
        ("RuleD", format!("{EX}shared"), "from", "k"),
    ];
    for (name, subject, p, o) in &rules {
        let rule = iri(&format!("{EX}{name}"));
        shapes.add_triple(arena.make_triple(shape, iri(&format!("{SH}rule")), rule));
        shapes.add_triple(arena.make_triple(rule, rdf_type, iri(&format!("{SH}TripleRule"))));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}subject")), iri(subject)));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}predicate")), iri(&format!("{EX}{p}"))));
        shapes.add_triple(arena.make_triple(rule, iri(&format!("{SH}object")), iri(&format!("{EX}{o}"))));
    }

    let inference = expect_inference(infer(&arena, &mut data, &shapes, &ValidatorConfig::new()));
    let got: Vec<(String, String, String)> = inference
        .inferred
        .iter()
        .map(|it| (it.triple.to_string(), it.rule.to_string(), it.focus_node.to_string()))
        .collect();
    let row = |s: &str, p: &str, o: &str, rule: &str, focus: &str| {
        (
            format!("<{EX}{s}> <{EX}{p}> <{EX}{o}> ."),
            format!("<{EX}{rule}>"),
            format!("<{EX}{focus}>"),
        )
    };
    // Inference order: rule by rule, focus node by focus node. RuleC adds
    // nothing new, and RuleD's one triple goes to the first focus node.
    assert_eq!(
        got,
        vec![
            row("n1", "p", "v", "RuleA", "n1"),
            row("n2", "p", "v", "RuleA", "n2"),
            row("n1", "q", "w", "RuleB", "n1"),
            row("n2", "q", "w", "RuleB", "n2"),
            row("shared", "from", "k", "RuleD", "n1"),
        ]
    );
}

// ---------------------------------------------------------------------------
// Triple terms compare by value (#19)
// ---------------------------------------------------------------------------

#[test]
fn equal_triple_terms_are_one_value() {
    let arena = Arena::new(4 * 1024 * 1024);
    let iri = |s: &str| arena.make_iri(&format!("{EX}{s}"));
    let sh = |s: &str| arena.make_iri(&format!("{SH}{s}"));
    let rdf = |s: &str| arena.make_iri(&format!("{RDF}{s}"));
    // A fresh allocation each time, so no two share a pointer.
    let abc = || arena.make_triple_term(arena.make_triple(iri("a"), iri("b"), iri("c")));

    // :x :p <<( :a :b :c )>> (twice) ; :q <<( :a :b :c )>>
    let mut data = SnarlDataGraph::new(&arena);
    data.add_triple(arena.make_triple(iri("x"), iri("p"), abc()));
    data.add_triple(arena.make_triple(iri("x"), iri("p"), abc()));
    data.add_triple(arena.make_triple(iri("x"), iri("q"), abc()));
    assert_eq!(data.size(), 2, "a repeated statement is one triple");

    // :S sh:targetNode :x ; sh:rule [ a sh:TripleRule ; sh:subject sh:this ;
    //   sh:predicate :r ; sh:object [ sh:intersection ( [sh:path :p] [sh:path :q] ) ] ]
    let mut shapes = IndexedGraph::new(&arena);
    let (rule, obj, l1, l2, pp, pq) = (
        arena.make_blank(1), arena.make_blank(2), arena.make_blank(3),
        arena.make_blank(4), arena.make_blank(5), arena.make_blank(6),
    );
    for (s, p, o) in [
        (iri("S"), rdf("type"), sh("NodeShape")),
        (iri("S"), sh("targetNode"), iri("x")),
        (iri("S"), sh("rule"), rule),
        (rule, rdf("type"), sh("TripleRule")),
        (rule, sh("subject"), sh("this")),
        (rule, sh("predicate"), iri("r")),
        (rule, sh("object"), obj),
        (obj, sh("intersection"), l1),
        (l1, rdf("first"), pp),
        (l1, rdf("rest"), l2),
        (l2, rdf("first"), pq),
        (l2, rdf("rest"), rdf("nil")),
        (pp, sh("path"), iri("p")),
        (pq, sh("path"), iri("q")),
    ] {
        shapes.add_triple(arena.make_triple(s, p, o));
    }

    let config = ValidatorConfig::new();
    let first = expect_inference(infer(&arena, &mut data, &shapes, &config));
    assert_eq!(first.inferred.len(), 1, "the intersection holds the triple term");
    match &first.inferred[0].triple.object {
        snarl::Term::Triple(t) => {
            assert!(matches!(t.subject, snarl::Term::Iri(v) if v.ends_with("a")));
            assert!(matches!(t.object, snarl::Term::Iri(v) if v.ends_with("c")));
        }
        other => panic!("expected a triple term, got {other:?}"),
    }

    // A caller running a level to its fixpoint settles.
    let second = expect_inference(infer(&arena, &mut data, &shapes, &config));
    assert!(second.inferred.is_empty(), "the graph already holds the conclusion");
}
