#include "../runtime/slop_runtime.h"
#include "slop_value_type.h"

static const slop_string value_type_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string value_type_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string value_type_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string value_type_EX_VALUE = SLOP_STR("http://example.org/value");

index_IndexedGraph value_type_fixture_g_focus_is_person(slop_arena* arena);
index_IndexedGraph value_type_fixture_g_empty(slop_arena* arena);
slop_option_types_ValidationResult snarl_check_class(slop_arena* arena, index_IndexedGraph data_graph, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_class, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message);
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
    if (snarl_is_shacl_instance_of_class(arena, data_graph, value_node, required_class)) {
        return (slop_option_types_ValidationResult){.has_value = false};
    } else {
        return (slop_option_types_ValidationResult){.has_value = 1, .value = ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = vocab_SHACL_CLASS, .severity = severity, .message = message})};
    }
}

slop_option_types_ValidationResult snarl_check_datatype(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, rdf_Term required_datatype, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
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
                    if (string_eq(dt, required_dt_str)) {
                        return (slop_option_types_ValidationResult){.has_value = false};
                    } else {
                        return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_DATATYPE, severity, message)};
                    }
                } else if (!_mv_116.has_value) {
                    if (string_eq(required_dt_str, vocab_XSD_STRING)) {
                        return (slop_option_types_ValidationResult){.has_value = false};
                    } else {
                        return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_DATATYPE, severity, message)};
                    }
                }
            }
        }
        default: {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_DATATYPE, severity, message)};
        }
    }
}

slop_option_types_ValidationResult snarl_check_node_kind(slop_arena* arena, rdf_Term focus_node, rdf_Term value_node, types_NodeKind required_kind, slop_option_types_ShaclPath path, rdf_Term shape_id, types_Severity severity, slop_option_string message) {
    {
        __auto_type kind = rdf_term_kind(value_node);
        __auto_type passes = ({ __auto_type _mv = required_kind; uint8_t _mr = {0}; switch (_mv) { case types_NodeKind_node_kind_blank_node: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_blank: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; } case types_NodeKind_node_kind_iri: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_iri: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; } case types_NodeKind_node_kind_literal: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_literal: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; } case types_NodeKind_node_kind_blank_node_or_iri: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_blank: { _mr = 1; break; } case rdf_TermKind_iri: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; } case types_NodeKind_node_kind_blank_node_or_literal: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_blank: { _mr = 1; break; } case rdf_TermKind_literal: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; } case types_NodeKind_node_kind_iri_or_literal: { _mr = ({ __auto_type _mv = kind; uint8_t _mr = {0}; switch (_mv) { case rdf_TermKind_iri: { _mr = 1; break; } case rdf_TermKind_literal: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }); break; }  } _mr; });
        if (passes) {
            return (slop_option_types_ValidationResult){.has_value = false};
        } else {
            return (slop_option_types_ValidationResult){.has_value = 1, .value = value_type_make_vr(arena, focus_node, path, value_node, shape_id, vocab_SHACL_NODE_KIND, severity, message)};
        }
    }
}

types_ValidationResult value_type_make_vr(slop_arena* arena, rdf_Term focus_node, slop_option_types_ShaclPath path, rdf_Term value_node, rdf_Term shape_id, slop_string component, types_Severity severity, slop_option_string message) {
    return ((types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = component, .severity = severity, .message = message});
}

