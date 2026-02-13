#include "../runtime/slop_runtime.h"
#include "slop_report.h"

void snarl_print_report(slop_arena* arena, types_ValidationReport report);
slop_string snarl_report_to_string(slop_arena* arena, types_ValidationReport report);
index_IndexedGraph snarl_report_to_graph(slop_arena* arena, types_ValidationReport report);
slop_string snarl_severity_to_string(types_Severity sev);
slop_string snarl_term_to_display_string(slop_arena* arena, rdf_Term t);
slop_string report_sequence_to_display_string(slop_arena* arena, slop_list_types_ShaclPath steps);
slop_string report_alternative_to_display_string(slop_arena* arena, slop_list_types_ShaclPath alts);
slop_string snarl_path_to_display_string(slop_arena* arena, types_ShaclPath p);

void snarl_print_report(slop_arena* arena, types_ValidationReport report) {
    {
        __auto_type results = report.results;
        __auto_type result_count = ((int64_t)((results).len));
        if (report.conforms) {
            printf("%s\n", "Validation Report: CONFORMS");
        } else {
            printf("%s", "Validation Report: ");
            printf("%.*s", (int)(int_to_string(arena, result_count)).len, (int_to_string(arena, result_count)).data);
            printf("%s\n", " result(s)");
        }
        printf("%s\n", "---");
        {
            __auto_type _coll = results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                printf("%s\n", "");
                printf("%s", "  Severity: ");
                printf("%.*s\n", (int)(snarl_severity_to_string(r.severity)).len, (snarl_severity_to_string(r.severity)).data);
                printf("%s", "  Focus node: ");
                printf("%.*s\n", (int)(snarl_term_to_display_string(arena, r.focus_node)).len, (snarl_term_to_display_string(arena, r.focus_node)).data);
                __auto_type _mv_119 = r.result_path;
                if (_mv_119.has_value) {
                    __auto_type p = _mv_119.value;
                    printf("%s", "  Path: ");
                    printf("%.*s\n", (int)(snarl_path_to_display_string(arena, p)).len, (snarl_path_to_display_string(arena, p)).data);
                } else if (!_mv_119.has_value) {
                }
                __auto_type _mv_120 = r.value;
                if (_mv_120.has_value) {
                    __auto_type v = _mv_120.value;
                    printf("%s", "  Value: ");
                    printf("%.*s\n", (int)(snarl_term_to_display_string(arena, v)).len, (snarl_term_to_display_string(arena, v)).data);
                } else if (!_mv_120.has_value) {
                }
                printf("%s", "  Source shape: ");
                printf("%.*s\n", (int)(snarl_term_to_display_string(arena, r.source_shape)).len, (snarl_term_to_display_string(arena, r.source_shape)).data);
                printf("%s", "  Component: ");
                printf("%.*s\n", (int)(r.source_constraint_component).len, (r.source_constraint_component).data);
                __auto_type _mv_121 = r.message;
                if (_mv_121.has_value) {
                    __auto_type msg = _mv_121.value;
                    printf("%s", "  Message: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                } else if (!_mv_121.has_value) {
                }
            }
        }
    }
}

slop_string snarl_report_to_string(slop_arena* arena, types_ValidationReport report) {
    {
        __auto_type results = report.results;
        __auto_type result_count = ((int64_t)((results).len));
        __auto_type parts = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        if (report.conforms) {
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Validation Report: CONFORMS\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("Validation Report: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, result_count)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR(" result(s)\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("---\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = results;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Severity: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_severity_to_string(r.severity)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Focus node: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, r.focus_node)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                __auto_type _mv_122 = r.result_path;
                if (_mv_122.has_value) {
                    __auto_type p = _mv_122.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Path: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_path_to_display_string(arena, p)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_122.has_value) {
                }
                __auto_type _mv_123 = r.value;
                if (_mv_123.has_value) {
                    __auto_type v = _mv_123.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Value: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, v)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_123.has_value) {
                }
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Source shape: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (snarl_term_to_display_string(arena, r.source_shape)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Component: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (r.source_constraint_component); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                __auto_type _mv_124 = r.message;
                if (_mv_124.has_value) {
                    __auto_type msg = _mv_124.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("  Message: ")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (msg); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\n")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_124.has_value) {
                }
            }
        }
        return strlib_string_build(arena, parts);
    }
}

index_IndexedGraph snarl_report_to_graph(slop_arena* arena, types_ValidationReport report) {
    {
        __auto_type g = rdf_indexed_graph_create(arena);
        __auto_type report_node = rdf_make_blank(arena, 0);
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type report_type = rdf_make_iri(arena, vocab_SHACL_VALIDATION_REPORT);
        __auto_type conforms_pred = rdf_make_iri(arena, vocab_SHACL_CONFORMS);
        __auto_type conforms_val = rdf_make_literal(arena, ((report.conforms) ? SLOP_STR("true") : SLOP_STR("false")), (slop_option_string){.has_value = 1, .value = vocab_XSD_BOOLEAN}, ((slop_option_string){.has_value = false}));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, type_pred, report_type));
        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, conforms_pred, conforms_val));
        {
            int64_t result_id = 1;
            {
                __auto_type _coll = report.results;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type r = _coll.data[_i];
                    {
                        __auto_type result_node = rdf_make_blank(arena, result_id);
                        __auto_type result_pred = rdf_make_iri(arena, vocab_SHACL_RESULT);
                        __auto_type result_type = rdf_make_iri(arena, vocab_SHACL_VALIDATION_RESULT);
                        __auto_type focus_pred = rdf_make_iri(arena, vocab_SHACL_FOCUS_NODE);
                        __auto_type sev_pred = rdf_make_iri(arena, vocab_SHACL_RESULT_SEVERITY);
                        __auto_type sev_val = rdf_make_iri(arena, ({ __auto_type _mv = r.severity; slop_string _mr = {0}; switch (_mv) { case types_Severity_severity_violation: { _mr = vocab_SHACL_VIOLATION; break; } case types_Severity_severity_warning: { _mr = vocab_SHACL_WARNING; break; } case types_Severity_severity_info: { _mr = vocab_SHACL_INFO; break; }  } _mr; }));
                        __auto_type src_shape_pred = rdf_make_iri(arena, vocab_SHACL_SOURCE_SHAPE);
                        __auto_type src_comp_pred = rdf_make_iri(arena, vocab_SHACL_SOURCE_CONSTRAINT_COMPONENT);
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, report_node, result_pred, result_node));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, type_pred, result_type));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, focus_pred, r.focus_node));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, sev_pred, sev_val));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, src_shape_pred, r.source_shape));
                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, src_comp_pred, rdf_make_iri(arena, r.source_constraint_component)));
                        __auto_type _mv_125 = r.value;
                        if (_mv_125.has_value) {
                            __auto_type v = _mv_125.value;
                            {
                                __auto_type val_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/ns/shacl#value"));
                                g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, val_pred, v));
                            }
                        } else if (!_mv_125.has_value) {
                        }
                        __auto_type _mv_126 = r.result_path;
                        if (_mv_126.has_value) {
                            __auto_type p = _mv_126.value;
                            {
                                __auto_type path_pred = rdf_make_iri(arena, vocab_SHACL_RESULT_PATH);
                                __auto_type _mv_127 = p;
                                switch (_mv_127.tag) {
                                    case types_ShaclPath_path_predicate:
                                    {
                                        __auto_type pred_term = _mv_127.data.path_predicate;
                                        g = rdf_indexed_graph_add(arena, g, rdf_make_triple(arena, result_node, path_pred, pred_term));
                                        break;
                                    }
                                    default: {
                                        break;
                                    }
                                }
                            }
                        } else if (!_mv_126.has_value) {
                        }
                    }
                    result_id = (result_id + 1);
                }
            }
        }
        return g;
    }
}

slop_string snarl_severity_to_string(types_Severity sev) {
    __auto_type _mv_128 = sev;
    switch (_mv_128) {
        case types_Severity_severity_violation: {
            return SLOP_STR("Violation");
            break;
        }
        case types_Severity_severity_warning: {
            return SLOP_STR("Warning");
            break;
        }
        case types_Severity_severity_info: {
            return SLOP_STR("Info");
            break;
        }
    }
}

slop_string snarl_term_to_display_string(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_129 = t;
    switch (_mv_129.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type iri = _mv_129.data.term_iri;
            return iri.value;
        }
        case rdf_Term_term_blank:
        {
            __auto_type blank = _mv_129.data.term_blank;
            return string_concat(arena, SLOP_STR("_:"), int_to_string(arena, blank.id));
        }
        case rdf_Term_term_literal:
        {
            __auto_type lit = _mv_129.data.term_literal;
            {
                __auto_type parts = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\"")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (lit.value); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("\"")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                __auto_type _mv_130 = lit.datatype;
                if (_mv_130.has_value) {
                    __auto_type dt = _mv_130.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("^^")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (dt); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_130.has_value) {
                }
                __auto_type _mv_131 = lit.lang;
                if (_mv_131.has_value) {
                    __auto_type lang = _mv_131.value;
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (SLOP_STR("@")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(parts); __auto_type _item = (lang); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_131.has_value) {
                }
                return strlib_string_build(arena, parts);
            }
        }
    }
}

slop_string report_sequence_to_display_string(slop_arena* arena, slop_list_types_ShaclPath steps) {
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

slop_string report_alternative_to_display_string(slop_arena* arena, slop_list_types_ShaclPath alts) {
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

slop_string snarl_path_to_display_string(slop_arena* arena, types_ShaclPath p) {
    __auto_type _mv_132 = p;
    switch (_mv_132.tag) {
        case types_ShaclPath_path_predicate:
        {
            __auto_type pred = _mv_132.data.path_predicate;
            return snarl_term_to_display_string(arena, pred);
        }
        case types_ShaclPath_path_inverse:
        {
            __auto_type inner = _mv_132.data.path_inverse;
            return string_concat(arena, SLOP_STR("^"), snarl_path_to_display_string(arena, (*inner)));
        }
        case types_ShaclPath_path_sequence:
        {
            __auto_type steps = _mv_132.data.path_sequence;
            return report_sequence_to_display_string(arena, steps);
        }
        case types_ShaclPath_path_alternative:
        {
            __auto_type alts = _mv_132.data.path_alternative;
            return report_alternative_to_display_string(arena, alts);
        }
        case types_ShaclPath_path_zero_or_more:
        {
            __auto_type inner = _mv_132.data.path_zero_or_more;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("*"));
        }
        case types_ShaclPath_path_one_or_more:
        {
            __auto_type inner = _mv_132.data.path_one_or_more;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("+"));
        }
        case types_ShaclPath_path_zero_or_one:
        {
            __auto_type inner = _mv_132.data.path_zero_or_one;
            return string_concat(arena, snarl_path_to_display_string(arena, (*inner)), SLOP_STR("?"));
        }
    }
}

