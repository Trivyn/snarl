#include "../runtime/slop_runtime.h"
#include "slop_af_vocab.h"

const slop_string snarl_af_vocab_SHACL_CLASS_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#ClassConstraintComponent");
const slop_string snarl_af_vocab_SHACL_DATATYPE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#DatatypeConstraintComponent");
const slop_string snarl_af_vocab_SHACL_NODE_KIND_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#NodeKindConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MIN_COUNT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MinCountConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MAX_COUNT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MaxCountConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MIN_INCLUSIVE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MinInclusiveConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MAX_INCLUSIVE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MaxInclusiveConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MIN_EXCLUSIVE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MinExclusiveConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MAX_EXCLUSIVE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MaxExclusiveConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MIN_LENGTH_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MinLengthConstraintComponent");
const slop_string snarl_af_vocab_SHACL_MAX_LENGTH_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#MaxLengthConstraintComponent");
const slop_string snarl_af_vocab_SHACL_PATTERN_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#PatternConstraintComponent");
const slop_string snarl_af_vocab_SHACL_LANGUAGE_IN_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#LanguageInConstraintComponent");
const slop_string snarl_af_vocab_SHACL_UNIQUE_LANG_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#UniqueLangConstraintComponent");
const slop_string snarl_af_vocab_SHACL_EQUALS_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#EqualsConstraintComponent");
const slop_string snarl_af_vocab_SHACL_DISJOINT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#DisjointConstraintComponent");
const slop_string snarl_af_vocab_SHACL_LESS_THAN_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#LessThanConstraintComponent");
const slop_string snarl_af_vocab_SHACL_LESS_THAN_OR_EQUALS_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#LessThanOrEqualsConstraintComponent");
const slop_string snarl_af_vocab_SHACL_NOT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#NotConstraintComponent");
const slop_string snarl_af_vocab_SHACL_AND_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#AndConstraintComponent");
const slop_string snarl_af_vocab_SHACL_OR_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#OrConstraintComponent");
const slop_string snarl_af_vocab_SHACL_XONE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#XoneConstraintComponent");
const slop_string snarl_af_vocab_SHACL_NODE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#NodeConstraintComponent");
const slop_string snarl_af_vocab_SHACL_PROPERTY_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#PropertyConstraintComponent");
const slop_string snarl_af_vocab_SHACL_QUALIFIED_MIN_COUNT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#QualifiedMinCountConstraintComponent");
const slop_string snarl_af_vocab_SHACL_QUALIFIED_MAX_COUNT_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#QualifiedMaxCountConstraintComponent");
const slop_string snarl_af_vocab_SHACL_HAS_VALUE_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#HasValueConstraintComponent");
const slop_string snarl_af_vocab_SHACL_IN_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#InConstraintComponent");
const slop_string snarl_af_vocab_SHACL_CLOSED_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#ClosedConstraintComponent");
const slop_string snarl_af_vocab_SHACL_THIS = SLOP_STR("http://www.w3.org/ns/shacl#this");
const slop_string snarl_af_vocab_SHACL_FILTER_SHAPE = SLOP_STR("http://www.w3.org/ns/shacl#filterShape");
const slop_string snarl_af_vocab_SHACL_NODES = SLOP_STR("http://www.w3.org/ns/shacl#nodes");
const slop_string snarl_af_vocab_SHACL_INTERSECTION = SLOP_STR("http://www.w3.org/ns/shacl#intersection");
const slop_string snarl_af_vocab_SHACL_UNION = SLOP_STR("http://www.w3.org/ns/shacl#union");
const slop_string snarl_af_vocab_SHACL_EXPRESSION = SLOP_STR("http://www.w3.org/ns/shacl#expression");
const slop_string snarl_af_vocab_SHACL_EXPRESSION_CONSTRAINT_COMPONENT = SLOP_STR("http://www.w3.org/ns/shacl#ExpressionConstraintComponent");
const slop_string snarl_af_vocab_SHACL_SOURCE_CONSTRAINT = SLOP_STR("http://www.w3.org/ns/shacl#sourceConstraint");
const slop_string snarl_af_vocab_SHACL_RULE = SLOP_STR("http://www.w3.org/ns/shacl#rule");
const slop_string snarl_af_vocab_SHACL_TRIPLE_RULE = SLOP_STR("http://www.w3.org/ns/shacl#TripleRule");
const slop_string snarl_af_vocab_SHACL_SPARQL_RULE = SLOP_STR("http://www.w3.org/ns/shacl#SPARQLRule");
const slop_string snarl_af_vocab_SHACL_SUBJECT = SLOP_STR("http://www.w3.org/ns/shacl#subject");
const slop_string snarl_af_vocab_SHACL_PREDICATE = SLOP_STR("http://www.w3.org/ns/shacl#predicate");
const slop_string snarl_af_vocab_SHACL_OBJECT = SLOP_STR("http://www.w3.org/ns/shacl#object");
const slop_string snarl_af_vocab_SHACL_CONDITION = SLOP_STR("http://www.w3.org/ns/shacl#condition");
const slop_string snarl_af_vocab_SHACL_ORDER = SLOP_STR("http://www.w3.org/ns/shacl#order");
const slop_string snarl_af_vocab_SHACL_DEACTIVATED = SLOP_STR("http://www.w3.org/ns/shacl#deactivated");
const slop_string snarl_af_vocab_SHACL_ENTAILMENT = SLOP_STR("http://www.w3.org/ns/shacl#entailment");
const slop_string snarl_af_vocab_SHACL_RULES = SLOP_STR("http://www.w3.org/ns/shacl#Rules");
const slop_string snarl_af_vocab_SHACL_RULES_ENTAILMENT = SLOP_STR("http://www.w3.org/ns/shacl#RulesEntailment");
const slop_string snarl_af_vocab_SHNEX_NS = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#");
const slop_string snarl_af_vocab_SHNEX_VAR = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#var");
const slop_string snarl_af_vocab_SHNEX_PATH_VALUES = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#pathValues");
const slop_string snarl_af_vocab_SHNEX_FOCUS_NODE = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#focusNode");
const slop_string snarl_af_vocab_SHNEX_FILTER_SHAPE = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#filterShape");
const slop_string snarl_af_vocab_SHNEX_NODES = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#nodes");
const slop_string snarl_af_vocab_SHNEX_INTERSECTION = SLOP_STR("http://www.w3.org/ns/shacl-node-expr#intersection");
const slop_string snarl_af_vocab_SHNEX_FOCUS_NODE_VAR = SLOP_STR("focusNode");

slop_list_string snarl_af_vocab_shacl12_unsupported_properties(slop_arena* arena);
slop_list_string snarl_af_vocab_shacl12_unsupported_classes(slop_arena* arena);
slop_list_string snarl_af_vocab_shacl12_unsupported_rule_properties(slop_arena* arena);
slop_list_string snarl_af_vocab_shacl12_unsupported_rule_classes(slop_arena* arena);

slop_list_string snarl_af_vocab_shacl12_unsupported_properties(slop_arena* arena) {
    return ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 3 * sizeof(slop_string)), .len = 3, .cap = 3, .arena = arena }; _ll.data[0] = SLOP_STR("http://www.w3.org/ns/shacl#nodeByExpression"); _ll.data[1] = SLOP_STR("http://www.w3.org/ns/shacl#values"); _ll.data[2] = SLOP_STR("http://www.w3.org/ns/shacl#defaultValue"); _ll; });
}

slop_list_string snarl_af_vocab_shacl12_unsupported_classes(slop_arena* arena) {
    return ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 1 * sizeof(slop_string)), .len = 1, .cap = 1, .arena = arena }; _ll.data[0] = SLOP_STR("http://www.w3.org/ns/shacl#ShapeClass"); _ll; });
}

slop_list_string snarl_af_vocab_shacl12_unsupported_rule_properties(slop_arena* arena) {
    return ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 7 * sizeof(slop_string)), .len = 7, .cap = 7, .arena = arena }; _ll.data[0] = SLOP_STR("http://www.w3.org/ns/shacl#layer"); _ll.data[1] = SLOP_STR("http://www.w3.org/ns/shacl#runOnce"); _ll.data[2] = SLOP_STR("http://www.w3.org/ns/shacl#hasRule"); _ll.data[3] = SLOP_STR("http://www.w3.org/ns/shacl#includesRuleSet"); _ll.data[4] = SLOP_STR("http://www.w3.org/ns/shacl#ruleProcessor"); _ll.data[5] = SLOP_STR("http://www.w3.org/ns/shacl#expectedPredicate"); _ll.data[6] = SLOP_STR("http://www.w3.org/ns/shacl#tempTriple"); _ll; });
}

slop_list_string snarl_af_vocab_shacl12_unsupported_rule_classes(slop_arena* arena) {
    return ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 2 * sizeof(slop_string)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = SLOP_STR("http://www.w3.org/ns/shacl#RuleSet"); _ll.data[1] = SLOP_STR("http://www.w3.org/ns/shacl#SPARQLRuleTemplate"); _ll; });
}

