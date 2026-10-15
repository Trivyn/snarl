/*
 * Thin C shim for static inline arena functions from slop_runtime.h.
 * These are static inline in the header, so they have no exported symbol.
 * We wrap them here so Rust can link to them.
 */

#include "slop_runtime.h"

slop_arena* snarl_arena_new(size_t capacity) {
    slop_arena* a = (slop_arena*)malloc(sizeof(slop_arena));
    if (!a) return NULL;
    *a = slop_arena_new(capacity);
    if (a->base == NULL) {
        free(a);
        return NULL;
    }
    return a;
}

void snarl_arena_free(slop_arena* arena) {
    if (!arena) return;
    slop_arena_free(arena);
    free(arena);
}

slop_string snarl_intern_string(const char* data, size_t len) {
    return slop_intern_string(data, len);
}

/*
 * C-side sizes of the structs ffi.rs mirrors, so a Rust test can catch the
 * mirror drifting when the SLOP runtime or snarl's own types change layout.
 */
#include "slop_snarl.h"

size_t snarl_ffi_sizeof(int which) {
    switch (which) {
        case 0: return sizeof(slop_string);
        case 1: return sizeof(slop_rdf_rdf_Term);
        case 2: return sizeof(slop_rdf_rdf_Triple);
        case 3: return sizeof(slop_list_slop_rdf_rdf_Term);
        case 4: return sizeof(slop_list_slop_rdf_rdf_Triple);
        case 5: return sizeof(slop_list_snarl_types_ValidationResult);
        case 6: return sizeof(slop_list_snarl_types_ShaclPath);
        case 7: return sizeof(slop_rdf_index_IndexedGraph);
        case 8: return sizeof(snarl_data_graph_SnarlDataIndex);
        case 9: return sizeof(snarl_data_graph_SnarlDataGraph);
        case 10: return sizeof(snarl_types_ShaclPath);
        case 11: return sizeof(snarl_types_ValidatorConfig);
        case 12: return sizeof(snarl_types_ValidationReport);
        case 13: return sizeof(snarl_types_ValidationResult);
        case 14: return sizeof(snarl_types_ValidatorResult);
        default: return 0;
    }
}
