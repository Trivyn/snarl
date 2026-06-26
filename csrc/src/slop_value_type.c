#include "../runtime/slop_runtime.h"
#include "slop_value_type.h"

static const slop_string value_type_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string value_type_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string value_type_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string value_type_EX_VALUE = SLOP_STR("http://example.org/value");

index_IndexedGraph value_type_fixture_g_focus_is_person(slop_arena* arena);
index_IndexedGraph value_type_fixture_g_empty(slop_arena* arena);
slop_option_types_ValidationResult snarl_check_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_class, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
uint8_t value_type_datatype_matches(rdf_Term value_node, rdf_Term required_datatype);
slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
uint8_t value_type_node_kind_matches(types_NodeKind required, rdf_TermKind kind);
slop_option_types_ValidationResult snarl_check_node_kind(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, types_NodeKind required_kind, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
types_ValidationResult value_type_make_vr(slop_arena* arena, rdf_Term focus_node, slop_option_types_ShaclPath path, rdf_Term value_node, rdf_Term shape_id, slop_string component, types_Severity severity, slop_option_string message);

index_IndexedGraph value_type_fixture_g_focus_is_person(slop_arena* arena) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, value_type_EX_FOCUS), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, value_type_EX_PERSON)));
        return g;
    }
}

index_IndexedGraph value_type_fixture_g_empty(slop_arena* arena) {
    return rdf_indexed_graph_create(arena);
}

slop_option_types_ValidationResult snarl_check_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_class, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    SLOP_PRE(((rdf_indexed_graph_size(data_graph) >= 0)), "(>= (indexed-graph-size data-graph) 0)");
    slop_option_types_ValidationResult _retval = {0};
    if (snarl_is_shacl_instance_of_class(arena, data_graph, value_node, required_class)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_CLASS, .severity = severity, .message = message})};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == snarl_is_shacl_instance_of_class(arena, data_graph, value_node, required_class))), "(== (== $result (none)) (is-shacl-instance-of-class arena data-graph value-node required-class))");
    return _retval;
}

uint8_t value_type_datatype_matches(rdf_Term value_node, rdf_Term required_datatype) {
    __auto_type _mv_115 = value_node;
    switch (_mv_115.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_115.data.term_literal;
            {
                __auto_type required_dt_str = ({ __auto_type _mv = required_datatype; slop_string _mr = {0}; switch (_mv.tag) { case rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = iri.value; break; } default: { _mr = SLOP_STR(""); break; }  } _mr; });
                __auto_type _mv_116 = lit.datatype;
                if (_mv_116.has_value) {
                    __auto_type dt = _mv_116.value;
                    return string_eq(dt, required_dt_str);
                } else if (!_mv_116.has_value) {
                    return string_eq(required_dt_str, vocab_XSD_STRING);
                }
            }
        }
        default: {
            return 0;
        }
    }
}

slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_type_datatype_matches(value_node, required_datatype)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_DATATYPE, severity, message)};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == value_type_datatype_matches(value_node, required_datatype))), "(== (== $result (none)) (datatype-matches value-node required-datatype))");
    return _retval;
}

uint8_t value_type_node_kind_matches(types_NodeKind required, rdf_TermKind kind) {
    __auto_type _mv_117 = required;
    switch (_mv_117) {
        case types_NodeKind_node_kind_blank_node: {
            __auto_type _mv_118 = kind;
            switch (_mv_118) {
                case rdf_TermKind_blank: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
        case types_NodeKind_node_kind_iri: {
            __auto_type _mv_119 = kind;
            switch (_mv_119) {
                case rdf_TermKind_iri: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
        case types_NodeKind_node_kind_literal: {
            __auto_type _mv_120 = kind;
            switch (_mv_120) {
                case rdf_TermKind_literal: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
        case types_NodeKind_node_kind_blank_node_or_iri: {
            __auto_type _mv_121 = kind;
            switch (_mv_121) {
                case rdf_TermKind_blank: {
                    return 1;
                    break;
                }
                case rdf_TermKind_iri: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
        case types_NodeKind_node_kind_blank_node_or_literal: {
            __auto_type _mv_122 = kind;
            switch (_mv_122) {
                case rdf_TermKind_blank: {
                    return 1;
                    break;
                }
                case rdf_TermKind_literal: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
        case types_NodeKind_node_kind_iri_or_literal: {
            __auto_type _mv_123 = kind;
            switch (_mv_123) {
                case rdf_TermKind_iri: {
                    return 1;
                    break;
                }
                case rdf_TermKind_literal: {
                    return 1;
                    break;
                }
                default: {
                    return 0;
                    break;
                }
            }
            break;
        }
    }
}

slop_option_types_ValidationResult snarl_check_node_kind(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, types_NodeKind required_kind, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    slop_option_types_ValidationResult _retval = {0};
    if (value_type_node_kind_matches(required_kind, rdf_term_kind(value_node))) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_NODE_KIND, severity, message)};
    }
    SLOP_POST((((_retval == ((slop_option_types_ValidationResult){.has_value = false})) == value_type_node_kind_matches(required_kind, rdf_term_kind(value_node)))), "(== (== $result (none)) (node-kind-matches required-kind (term-kind value-node)))");
    return _retval;
}

types_ValidationResult value_type_make_vr(slop_arena* arena, rdf_Term focus_node, slop_option_types_ShaclPath path, rdf_Term value_node, rdf_Term shape_id, slop_string component, types_Severity severity, slop_option_string message) {
    return ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = component, .severity = severity, .message = message});
}

