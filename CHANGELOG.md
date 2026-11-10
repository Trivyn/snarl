# Changelog

Releases before 0.8.1 are described on the
[GitHub releases page](https://github.com/Trivyn/snarl/releases).

## 0.8.1

For shapes graphs that keep `sh:SPARQLRule`s beside `sh:TripleRule`s, with a
caller that runs the SPARQL rules on its own engine. SHACL Core behavior is
unchanged, and so is 0.8.0 behavior with the default config, apart from the
first item.

### Changed

- **Validation that runs no rules ignores them.** Without `run_rules` and
  without `sh:entailment sh:Rules`, an `sh:SPARQLRule`, any other non-triple
  rule type, an ill-formed `sh:TripleRule` or a function expression inside a
  rule is no longer an error: the rules are not examined. In `--shacl12` mode
  the same holds for the rule-only 1.2 constructs (`sh:layer`, `sh:runOnce`,
  `sh:hasRule`, `sh:includesRuleSet`, `sh:ruleProcessor`,
  `sh:expectedPredicate`, `sh:tempTriple`, `sh:RuleSet`,
  `sh:SPARQLRuleTemplate`, global rules). Everything validation depends on
  still fails: function expressions in `sh:expression`, ill-formed node
  expressions used by constraints, unknown entailment regimes, and cyclic or
  over-deep node expressions anywhere, including inside rules. When rules run,
  an unexecutable rule fails as before.

### Added

- **`defer_sparql_rules`** (`ValidatorConfig`). When rules run, an
  `sh:SPARQLRule` is skipped and reported with its shape and order key. Only
  `rdf:type sh:SPARQLRule` is deferred; other unknown rule types still fail.
- **`order_min` / `order_max`** (`ValidatorConfig`). Run only the rules whose
  order key lies in the inclusive range. A key is the pair (shape `sh:order`,
  rule `sh:order`); in `--shacl12` mode the shape part is always 0.
- **Per-triple attribution.** Every inferred triple carries the rule node and
  focus node that produced it. A triple produced more than once in a pass is
  attributed to the first producer.

### Breaking

0.8.1 changes the inference API, although Cargo treats it as compatible with
0.8.0. Callers of `infer` or `validate_data_graph_with_inference` need to
update.

- **Rust.** `InferResult::Success` holds an `Inference` (was
  `Vec<Triple>`), and `validate_data_graph_with_inference` returns
  `(ValidatorResult, Inference)`. `Inference::triples()` gives the plain
  triples back. New types: `Inference`, `InferredTriple`, `DeferredRule`,
  `RuleOrder`.
- **C.** `ValidatorConfig` gains `defer_sparql_rules`, `order_min` and
  `order_max`. `InferOutput.inferred` and `ValidationOutcome.inferred` are
  lists of `InferredTriple` (was `Triple`), and both structs gain `deferred`.
  Initialize configs with `snarl_default_config()`.
- **Internal C symbols.** `snarl_shapes_graph_unsupported_feature_message`
  takes two more arguments.

### Unchanged

- The CLI has no new flags. It gains only the first item: validating without
  `--rules` no longer fails on a shapes graph that holds SPARQL rules.
- Generated with SLOP 0.5.3 against slop-rdf v0.6.2, as 0.8.0 was.
