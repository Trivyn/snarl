#include "../runtime/slop_runtime.h"
#include "slop_report.h"

slop_list_snarl_types_ShaclPath snarl_report_fixture_path_list_ab(slop_arena* arena);
void snarl_print_report(slop_arena* arena, snarl_types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, snarl_types_ValidationReport report);
slop_rdf_index_IndexedGraph snarl_report_to_graph(slop_arena* arena, snarl_types_ValidationReport report);
snarl_report_PathEmit snarl_report_emit_path_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_snarl_types_ShaclPath members, int64_t next);
snarl_report_PathEmit snarl_report_emit_path_wrapper(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_string pred, snarl_report_PathEmit inner);
snarl_report_PathEmit snarl_report_emit_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, snarl_types_ShaclPath p, int64_t next);
int64_t snarl_report_blank_id_or_minus_one(slop_rdf_rdf_Term t);
int64_t snarl_report_report_max_blank_id(snarl_types_ValidationReport report);
slop_string snarl_severity_to_string(snarl_types_Severity sev);
slop_string snarl_term_to_display_string(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string snarl_report_sequence_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath steps);
slop_string snarl_report_alternative_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath alts);
slop_string snarl_path_to_display_string(slop_arena* arena, snarl_types_ShaclPath p);

slop_list_snarl_types_ShaclPath snarl_report_fixture_path_list_ab(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_snarl_types_ShaclPath){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(paths); __auto_type _item = (((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = rdf_make_iri(arena, SLOP_STR("http://example.org/a")) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(paths); __auto_type _item = (((snarl_types_ShaclPath){ .tag = snarl_types_ShaclPath_path_predicate, .data.path_predicate = rdf_make_iri(arena, SLOP_STR("http://example.org/b")) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return paths;
    }
}

void snarl_print_report(slop_arena* arena, snarl_types_ValidationReport report) {
    {
        __auto_type results = report.results;
        __auto_type result_count = ((int64_t)((results).len));
        if (report.conforms) {
            printf("%s\n", "Validation Report: CONFORMS");
        } else {
            printf("%s", "Validation Report: ");
            (void)(({ slop_string _ps_450 = (int_to_string(arena, result_count)); printf("%.*s", (int)_ps_450.len, _ps_450.data); }));
            printf("%s\n", " result(s)");
        }
        printf("%s\n", "---");
        {
            __auto_type _coll = results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                printf("%s\n", "");
                printf("%s", "  Severity: ");
                (void)(({ slop_string _ps_451 = (snarl_severity_to_string(r.severity)); printf("%.*s\n", (int)_ps_451.len, _ps_451.data); }));
                printf("%s", "  Focus node: ");
                (void)(({ slop_string _ps_452 = (snarl_term_to_display_string(arena, r.focus_node)); printf("%.*s\n", (int)_ps_452.len, _ps_452.data); }));
                __auto_type _mv_453 = r.result_path;
                if (_mv_453.has_value) {
                    __auto_type p = _mv_453.value;
                    printf("%s", "  Path: ");
                    ({ slop_string _ps_454 = (snarl_path_to_display_string(arena, p)); printf("%.*s\n", (int)_ps_454.len, _ps_454.data); });
                } else if (!_mv_453.has_value) {
                }
                __auto_type _mv_455 = r.value;
                if (_mv_455.has_value) {
                    __auto_type v = _mv_455.value;
                    printf("%s", "  Value: ");
                    ({ slop_string _ps_456 = (snarl_term_to_display_string(arena, v)); printf("%.*s\n", (int)_ps_456.len, _ps_456.data); });
                } else if (!_mv_455.has_value) {
                }
                printf("%s", "  Source shape: ");
                (void)(({ slop_string _ps_457 = (snarl_term_to_display_string(arena, r.source_shape)); printf("%.*s\n", (int)_ps_457.len, _ps_457.data); }));
                printf("%s", "  Component: ");
                (void)(({ slop_string _ps_458 = (r.source_constraint_component); printf("%.*s\n", (int)_ps_458.len, _ps_458.data); }));
                __auto_type _mv_459 = r.source_constraint;
                if (_mv_459.has_value) {
                    __auto_type c = _mv_459.value;
                    printf("%s", "  Source constraint: ");
                    ({ slop_string _ps_460 = (snarl_term_to_display_string(arena, c)); printf("%.*s\n", (int)_ps_460.len, _ps_460.data); });
                } else if (!_mv_459.has_value) {
                }
                __auto_type _mv_461 = r.message;
                if (_mv_461.has_value) {
                    __auto_type msg = _mv_461.value;
                    printf("%s", "  Message: ");
                    ({ slop_string _ps_462 = (msg); printf("%.*s\n", (int)_ps_462.len, _ps_462.data); });
                } else if (!_mv_461.has_value) {
                }
            }
        }
    }
}

slop_string snarl_report_to_string(slop_arena* arena, snarl_types_ValidationReport report) {
    {
        __auto_type results = report.results;
        __auto_type result_count = ((int64_t)((results).len));
        __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (report.conforms) {
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Validation Report: CONFORMS\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        } else {
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Validation Report: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, result_count)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" result(s)\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("---\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Severity: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_severity_to_string(r.severity)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Focus node: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, r.focus_node)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                __auto_type _mv_463 = r.result_path;
                if (_mv_463.has_value) {
                    __auto_type p = _mv_463.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Path: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_path_to_display_string(arena, p)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_463.has_value) {
                }
                __auto_type _mv_464 = r.value;
                if (_mv_464.has_value) {
                    __auto_type v = _mv_464.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Value: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, v)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_464.has_value) {
                }
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Source shape: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, r.source_shape)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Component: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (r.source_constraint_component); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                __auto_type _mv_465 = r.source_constraint;
                if (_mv_465.has_value) {
                    __auto_type c = _mv_465.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Source constraint: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_465.has_value) {
                }
                __auto_type _mv_466 = r.message;
                if (_mv_466.has_value) {
                    __auto_type msg = _mv_466.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Message: ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (msg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_466.has_value) {
                }
            }
        }
        return std_strlib_string_build(arena, parts);
    }
}

slop_rdf_index_IndexedGraph snarl_report_to_graph(slop_arena* arena, snarl_types_ValidationReport report) {
    {
        __auto_type base = (snarl_report_report_max_blank_id(report) + 1);
        __auto_type g = rdf_indexed_graph_create(arena);
        __auto_type report_node = rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, base, 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:151:42"));
        __auto_type type_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE);
        __auto_type report_type = rdf_make_iri(arena, slop_rdf_vocab_SHACL_VALIDATION_REPORT);
        __auto_type conforms_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_CONFORMS);
        __auto_type conforms_val = rdf_make_literal(arena, ((report.conforms) ? SLOP_STR("true") : SLOP_STR("false")), (slop_option_string){.has_value = 1, .value = slop_rdf_vocab_XSD_BOOLEAN}, ((slop_option_string){.has_value = false}));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, type_pred, report_type));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, conforms_pred, conforms_val));
        {
            int64_t result_id = (base + 1);
            int64_t path_id = ((base + 1) + ((int64_t)((report.results).len)));
            {
                __auto_type _coll = report.results;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type r = _coll.data[_i];
                    {
                        __auto_type result_node = rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, result_id, 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:171:48"));
                        __auto_type result_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_RESULT);
                        __auto_type result_type = rdf_make_iri(arena, slop_rdf_vocab_SHACL_VALIDATION_RESULT);
                        __auto_type focus_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_FOCUS_NODE);
                        __auto_type sev_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_RESULT_SEVERITY);
                        __auto_type sev_val = ({ __auto_type _mv = r.severity_iri; _mv.has_value ? ({ __auto_type custom = _mv.value; custom; }) : (rdf_make_iri(arena, ({ __auto_type _mv = r.severity; slop_string _mr = {0}; int _mm = 0; switch (_mv) { case snarl_types_Severity_severity_violation: { _mr = slop_rdf_vocab_SHACL_VIOLATION; _mm = 1; break; } case snarl_types_Severity_severity_warning: { _mr = slop_rdf_vocab_SHACL_WARNING; _mm = 1; break; } case snarl_types_Severity_severity_info: { _mr = slop_rdf_vocab_SHACL_INFO; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }))); });
                        __auto_type src_shape_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_SOURCE_SHAPE);
                        __auto_type src_comp_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_SOURCE_CONSTRAINT_COMPONENT);
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, result_pred, result_node));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, type_pred, result_type));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, focus_pred, r.focus_node));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, sev_pred, sev_val));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, src_shape_pred, r.source_shape));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, src_comp_pred, rdf_make_iri(arena, r.source_constraint_component)));
                        __auto_type _mv_467 = r.value;
                        if (_mv_467.has_value) {
                            __auto_type v = _mv_467.value;
                            {
                                __auto_type val_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#value"));
                                g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, val_pred, v));
                            }
                        } else if (!_mv_467.has_value) {
                        }
                        __auto_type _mv_468 = r.source_constraint;
                        if (_mv_468.has_value) {
                            __auto_type c = _mv_468.value;
                            g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, rdf_make_iri(arena, snarl_af_vocab_SHACL_SOURCE_CONSTRAINT), c));
                        } else if (!_mv_468.has_value) {
                        }
                        __auto_type _mv_469 = r.result_path;
                        if (_mv_469.has_value) {
                            __auto_type p = _mv_469.value;
                            {
                                __auto_type path_pred = rdf_make_iri(arena, slop_rdf_vocab_SHACL_RESULT_PATH);
                                {
                                    __auto_type e = snarl_report_emit_path(arena, g, p, path_id);
                                    path_id = e.next;
                                    g = rdf_indexed_graph_add(arena, e.graph, rdf_make_triple(arena, result_node, path_pred, e.node));
                                }
                            }
                        } else if (!_mv_469.has_value) {
                        }
                        __auto_type _mv_470 = r.message;
                        if (_mv_470.has_value) {
                            __auto_type msg = _mv_470.value;
                            {
                                __auto_type msg_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#resultMessage"));
                                g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, msg_pred, rdf_make_literal(arena, msg, ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}))));
                            }
                        } else if (!_mv_470.has_value) {
                        }
                    }
                    result_id = (result_id + 1);
                }
            }
        }
        return g;
    }
}

snarl_report_PathEmit snarl_report_emit_path_list(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_list_snarl_types_ShaclPath members, int64_t next) {
    {
        __auto_type n = ((int64_t)((members).len));
        __auto_type first_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST);
        __auto_type rest_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_REST);
        __auto_type list_end = rdf_make_iri(arena, slop_rdf_vocab_RDF_NIL);
        __auto_type graph = g;
        int64_t free = (next + ((int64_t)((members).len)));
        int64_t i = 0;
        {
            __auto_type _coll = members;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type m = _coll.data[_i];
                {
                    __auto_type e = snarl_report_emit_path(arena, graph, m, free);
                    __auto_type cell = rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, (next + i), 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:297:39"));
                    __auto_type rest = ((((i + 1) < n)) ? rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, (next + (i + 1)), 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:298:57")) : list_end);
                    free = e.next;
                    graph = rdf_indexed_graph_add(arena, e.graph, rdf_make_triple(arena, cell, first_pred, e.node));
                    graph = rdf_indexed_graph_add(arena, graph, rdf_make_triple(arena, cell, rest_pred, rest));
                    i = (i + 1);
                }
            }
        }
        return ((snarl_report_PathEmit){.graph = graph, .node = (((n > 0)) ? rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, next, 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:305:45")) : list_end), .next = free});
    }
}

snarl_report_PathEmit snarl_report_emit_path_wrapper(slop_arena* arena, slop_rdf_index_IndexedGraph g, slop_string pred, snarl_report_PathEmit inner) {
    snarl_report_PathEmit _retval = {0};
    {
        __auto_type node = rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, inner.next, 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at report.slop:313:35"));
        _retval = ((snarl_report_PathEmit){.graph = rdf_indexed_graph_add(arena, inner.graph, rdf_make_triple(arena, node, rdf_make_iri(arena, pred), inner.node)), .node = node, .next = (inner.next + 1)});
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.next == (inner.next + 1))), "(== (. $result next) (+ (. inner next) 1))");
    return _retval;
}

snarl_report_PathEmit snarl_report_emit_path(slop_arena* arena, slop_rdf_index_IndexedGraph g, snarl_types_ShaclPath p, int64_t next) {
    __auto_type _mv_471 = p;
    switch (_mv_471.tag) {
        case snarl_types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_471.data.path_predicate;
            return ((snarl_report_PathEmit){.graph = g, .node = pred, .next = next});
        }
        case snarl_types_ShaclPath_path_sequence:
        {
            __auto_type steps = _mv_471.data.path_sequence;
            return snarl_report_emit_path_list(arena, g, steps, next);
        }
        case snarl_types_ShaclPath_path_alternative:
        {
            __auto_type alts = _mv_471.data.path_alternative;
            return snarl_report_emit_path_wrapper(arena, g, slop_rdf_vocab_SHACL_ALTERNATIVE_PATH, snarl_report_emit_path_list(arena, g, alts, next));
        }
        case snarl_types_ShaclPath_path_inverse:
        {
            __auto_type inner = _mv_471.data.path_inverse;
            return snarl_report_emit_path_wrapper(arena, g, slop_rdf_vocab_SHACL_INVERSE_PATH, snarl_report_emit_path(arena, g, (*inner), next));
        }
        case snarl_types_ShaclPath_path_zero_or_more:
        {
            __auto_type inner = _mv_471.data.path_zero_or_more;
            return snarl_report_emit_path_wrapper(arena, g, slop_rdf_vocab_SHACL_ZERO_OR_MORE_PATH, snarl_report_emit_path(arena, g, (*inner), next));
        }
        case snarl_types_ShaclPath_path_one_or_more:
        {
            __auto_type inner = _mv_471.data.path_one_or_more;
            return snarl_report_emit_path_wrapper(arena, g, slop_rdf_vocab_SHACL_ONE_OR_MORE_PATH, snarl_report_emit_path(arena, g, (*inner), next));
        }
        case snarl_types_ShaclPath_path_zero_or_one:
        {
            __auto_type inner = _mv_471.data.path_zero_or_one;
            return snarl_report_emit_path_wrapper(arena, g, slop_rdf_vocab_SHACL_ZERO_OR_ONE_PATH, snarl_report_emit_path(arena, g, (*inner), next));
        }
    }
    SLOP_UNREACHABLE();
}

int64_t snarl_report_blank_id_or_minus_one(slop_rdf_rdf_Term t) {
    int64_t _retval = {0};
    __auto_type _mv_472 = t;
    switch (_mv_472.tag) {
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type b = _mv_472.data.term_blank;
            _retval = b.id;
            goto _slop_post;
        }
        default: {
            _retval = -1;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    return _retval;
}

int64_t snarl_report_report_max_blank_id(snarl_types_ValidationReport report) {
    int64_t _retval = {0};
    {
        int64_t m = -1;
        {
            __auto_type _coll = report.results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type a = snarl_report_blank_id_or_minus_one(r.focus_node);
                    __auto_type b = snarl_report_blank_id_or_minus_one(r.source_shape);
                    __auto_type c = ({ __auto_type _mv = r.value; _mv.has_value ? ({ __auto_type v = _mv.value; snarl_report_blank_id_or_minus_one(v); }) : (-1); });
                    __auto_type d = ({ __auto_type _mv = r.source_constraint; _mv.has_value ? ({ __auto_type x = _mv.value; snarl_report_blank_id_or_minus_one(x); }) : (-1); });
                    if (a > m) {
                        m = a;
                    }
                    if (b > m) {
                        m = b;
                    }
                    if (c > m) {
                        m = c;
                    }
                    if (d > m) {
                        m = d;
                    }
                }
            }
        }
        _retval = m;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    return _retval;
}

slop_string snarl_severity_to_string(snarl_types_Severity sev) {
    __auto_type _mv_473 = sev;
    switch (_mv_473) {
        case snarl_types_Severity_severity_violation: {
            return SLOP_STR("Violation");
            break;
        }
        case snarl_types_Severity_severity_warning: {
            return SLOP_STR("Warning");
            break;
        }
        case snarl_types_Severity_severity_info: {
            return SLOP_STR("Info");
            break;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string snarl_term_to_display_string(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_474 = t;
    switch (_mv_474.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type iri = _mv_474.data.term_iri;
            return iri.value;
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type blank = _mv_474.data.term_blank;
            return string_concat(arena, SLOP_STR("_:"), int_to_string(arena, blank.id));
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit = _mv_474.data.term_literal;
            {
                __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\"")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (lit.value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\"")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                __auto_type _mv_475 = lit.datatype;
                if (_mv_475.has_value) {
                    __auto_type dt = _mv_475.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("^^")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (dt); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_475.has_value) {
                }
                __auto_type _mv_476 = lit.lang;
                if (_mv_476.has_value) {
                    __auto_type lang = _mv_476.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("@")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (lang); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_476.has_value) {
                }
                return std_strlib_string_build(arena, parts);
            }
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_474.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("<<( ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, rdf_triple_subject(tr))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, rdf_triple_predicate(tr))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" ")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, rdf_triple_object(tr))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" )>>")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return std_strlib_string_build(arena, parts);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_string snarl_report_sequence_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath steps) {
    {
        __auto_type s = SLOP_STR("");
        {
            uint8_t first = 1;
            {
                __auto_type _coll = steps;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type step = _coll.data[_i];
                    if (first) {
                        first = 0;
                    } else {
                        s = string_concat(arena, s, SLOP_STR(" / "));
                    }
                    s = string_concat(arena, s, snarl_path_to_display_string(arena, step));
                }
            }
        }
        return s;
    }
}

slop_string snarl_report_alternative_to_display_string(slop_arena* arena, slop_list_snarl_types_ShaclPath alts) {
    {
        __auto_type s = SLOP_STR("");
        {
            uint8_t first = 1;
            {
                __auto_type _coll = alts;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type alt = _coll.data[_i];
                    if (first) {
                        first = 0;
                    } else {
                        s = string_concat(arena, s, SLOP_STR(" | "));
                    }
                    s = string_concat(arena, s, snarl_path_to_display_string(arena, alt));
                }
            }
        }
        return s;
    }
}

slop_string snarl_path_to_display_string(slop_arena* arena, snarl_types_ShaclPath p) {
    __auto_type _mv_477 = p;
    switch (_mv_477.tag) {
        case snarl_types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_477.data.path_predicate;
            return snarl_term_to_display_string(arena, pred);
        }
        case snarl_types_ShaclPath_path_inverse:
        {
            __auto_type inner = _mv_477.data.path_inverse;
            return string_concat(arena, SLOP_STR("^"), snarl_path_to_display_string(arena, (*inner)));
        }
        case snarl_types_ShaclPath_path_sequence:
        {
            __auto_type steps = _mv_477.data.path_sequence;
            return snarl_report_sequence_to_display_string(arena, steps);
        }
        case snarl_types_ShaclPath_path_alternative:
        {
            __auto_type alts = _mv_477.data.path_alternative;
            return snarl_report_alternative_to_display_string(arena, alts);
        }
        case snarl_types_ShaclPath_path_zero_or_more:
        {
            __auto_type inner = _mv_477.data.path_zero_or_more;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("*"));
        }
        case snarl_types_ShaclPath_path_one_or_more:
        {
            __auto_type inner = _mv_477.data.path_one_or_more;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("+"));
        }
        case snarl_types_ShaclPath_path_zero_or_one:
        {
            __auto_type inner = _mv_477.data.path_zero_or_one;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("?"));
        }
    }
    SLOP_UNREACHABLE();
}

