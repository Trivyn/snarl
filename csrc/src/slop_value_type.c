#include "../runtime/slop_runtime.h"
#include "slop_value_type.h"

static const slop_string snarl_value_type_EX_FOCUS = SLOP_STR("http://example.org/focus");
static const slop_string snarl_value_type_EX_SHAPE = SLOP_STR("http://example.org/Shape1");
static const slop_string snarl_value_type_EX_PERSON = SLOP_STR("http://example.org/Person");
static const slop_string snarl_value_type_EX_VALUE = SLOP_STR("http://example.org/value");

snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_focus_is_person(slop_arena* arena);
snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_empty(slop_arena* arena);
slop_option_snarl_types_ValidationResult snarl_check_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
snarl_types_ValidationResult snarl_value_type_make_class_violation(slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
slop_option_snarl_types_ValidationResult snarl_value_type_check_class_with_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
uint8_t snarl_value_type_datatype_matches(slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype);
slop_option_snarl_types_ValidationResult snarl_check_datatype(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
uint8_t snarl_value_type_node_kind_matches(snarl_types_NodeKind required, slop_rdf_rdf_TermKind kind);
slop_option_snarl_types_ValidationResult snarl_check_node_kind(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_NodeKind required_kind, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message);
snarl_types_ValidationResult snarl_value_type_make_vr(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term shape_id, slop_string component, snarl_types_Severity severity, slop_option_string message);

snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_focus_is_person(slop_arena* arena) {
    {
        __auto_type g = snarl_data_graph_create(arena);
        g = snarl_data_graph_add(arena, g, rdf_make_triple(arena, rdf_make_iri(arena, snarl_value_type_EX_FOCUS), rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE), rdf_make_iri(arena, snarl_value_type_EX_PERSON)));
        return g;
    }
}

snarl_data_graph_SnarlDataGraph snarl_value_type_fixture_g_empty(slop_arena* arena) {
    return snarl_data_graph_create(arena);
}

slop_option_snarl_types_ValidationResult snarl_check_class(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    SLOP_PRE(((snarl_data_graph_size(data_graph) >= 0)), "(>= (snarl-data-graph-size data-graph) 0)");
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_is_shacl_instance_of_class(arena, data_graph, value_node, required_class)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_CLASS, .severity = severity, .message = message})};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_is_shacl_instance_of_class(arena, data_graph, value_node, required_class))), "(== (is-none $result) (is-shacl-instance-of-class arena data-graph value-node required-class))");
    return _retval;
}

snarl_types_ValidationResult snarl_value_type_make_class_violation(slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    return ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = slop_rdf_vocab_SHACL_CLASS, .severity = severity, .message = message});
}

slop_option_snarl_types_ValidationResult snarl_value_type_check_class_with_index(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_class, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    if (snarl_target_class_index_has_class(class_index, required_class)) {
        if (snarl_target_class_index_has_instance(class_index, value_node, required_class)) {
            return (slop_option_snarl_types_ValidationResult){.has_value = false};
        } else {
            return (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = snarl_value_type_make_class_violation(focus_node, value_node, required_class, path, shape_id, severity, message)};
        }
    } else {
        return snarl_check_class(arena, data_graph, focus_node, value_node, required_class, path, shape_id, severity, message);
    }
}

uint8_t snarl_value_type_datatype_matches(slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype) {
    __auto_type _mv_292 = value_node;
    switch (_mv_292.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_292.data.term_literal;
            {
                __auto_type required_dt_str = ({ __auto_type _mv = required_datatype; slop_string _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_iri: { __auto_type iri = _mv.data.term_iri; _mr = iri.value; break; } default: { _mr = SLOP_STR(""); break; }  } _mr; });
                __auto_type _mv_293 = lit.datatype;
                if (_mv_293.has_value) {
                    __auto_type dt = _mv_293.value;
                    return string_eq(dt, required_dt_str);
                } else if (!_mv_293.has_value) {
                    return string_eq(required_dt_str, slop_rdf_vocab_XSD_STRING);
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            return 0;
        }
    }
}

slop_option_snarl_types_ValidationResult snarl_check_datatype(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term required_datatype, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_value_type_datatype_matches(value_node, required_datatype)) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = snarl_value_type_make_vr(arena, focus_node, path, value_node, shape_id, slop_rdf_vocab_SHACL_DATATYPE, severity, message)};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_value_type_datatype_matches(value_node, required_datatype))), "(== (is-none $result) (datatype-matches value-node required-datatype))");
    return _retval;
}

uint8_t snarl_value_type_node_kind_matches(snarl_types_NodeKind required, slop_rdf_rdf_TermKind kind) {
    __auto_type _mv_294 = required;
    switch (_mv_294) {
        case snarl_types_NodeKind_node_kind_blank_node: {
            __auto_type _mv_295 = kind;
            switch (_mv_295) {
                case slop_rdf_rdf_TermKind_blank: {
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
        case snarl_types_NodeKind_node_kind_iri: {
            __auto_type _mv_296 = kind;
            switch (_mv_296) {
                case slop_rdf_rdf_TermKind_iri: {
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
        case snarl_types_NodeKind_node_kind_literal: {
            __auto_type _mv_297 = kind;
            switch (_mv_297) {
                case slop_rdf_rdf_TermKind_literal: {
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
        case snarl_types_NodeKind_node_kind_blank_node_or_iri: {
            __auto_type _mv_298 = kind;
            switch (_mv_298) {
                case slop_rdf_rdf_TermKind_blank: {
                    return 1;
                    break;
                }
                case slop_rdf_rdf_TermKind_iri: {
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
        case snarl_types_NodeKind_node_kind_blank_node_or_literal: {
            __auto_type _mv_299 = kind;
            switch (_mv_299) {
                case slop_rdf_rdf_TermKind_blank: {
                    return 1;
                    break;
                }
                case slop_rdf_rdf_TermKind_literal: {
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
        case snarl_types_NodeKind_node_kind_iri_or_literal: {
            __auto_type _mv_300 = kind;
            switch (_mv_300) {
                case slop_rdf_rdf_TermKind_iri: {
                    return 1;
                    break;
                }
                case slop_rdf_rdf_TermKind_literal: {
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
    SLOP_UNREACHABLE();
}

slop_option_snarl_types_ValidationResult snarl_check_node_kind(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_rdf_rdf_Term value_node, snarl_types_NodeKind required_kind, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term shape_id, snarl_types_Severity severity, slop_option_string message) {
    slop_option_snarl_types_ValidationResult _retval = {0};
    if (snarl_value_type_node_kind_matches(required_kind, rdf_term_kind(value_node))) {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = false};
        goto _slop_post;
    } else {
        _retval = (slop_option_snarl_types_ValidationResult){.has_value = 1, .value = snarl_value_type_make_vr(arena, focus_node, path, value_node, shape_id, slop_rdf_vocab_SHACL_NODE_KIND, severity, message)};
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((!((_retval).has_value)) == snarl_value_type_node_kind_matches(required_kind, rdf_term_kind(value_node)))), "(== (is-none $result) (node-kind-matches required-kind (term-kind value-node)))");
    return _retval;
}

snarl_types_ValidationResult snarl_value_type_make_vr(slop_arena* arena, slop_rdf_rdf_Term focus_node, slop_option_snarl_types_ShaclPath path, slop_rdf_rdf_Term value_node, slop_rdf_rdf_Term shape_id, slop_string component, snarl_types_Severity severity, slop_option_string message) {
    return ((snarl_types_ValidationResult){.focus_node = focus_node, .result_path = path, .value = (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = value_node}, .source_shape = shape_id, .source_constraint_component = component, .severity = severity, .message = message});
}

