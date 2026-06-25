#include "../runtime/slop_runtime.h"
#include "slop_test_cli.h"

slop_option_index_IndexedGraph test_cli_load_test_graph(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count);
uint8_t test_cli_assert_has_violations(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count);
uint8_t test_cli_test_empty_graph(slop_arena* arena);
uint8_t test_cli_test_valid_person(slop_arena* arena);
uint8_t test_cli_test_rdf12_annotation_block(slop_arena* arena);
uint8_t test_cli_test_cardinality_violation(slop_arena* arena);
uint8_t test_cli_test_datatype_violation(slop_arena* arena);
uint8_t test_cli_test_class_violation(slop_arena* arena);
uint8_t test_cli_test_nodekind_violation(slop_arena* arena);
uint8_t test_cli_test_target_node(slop_arena* arena);
uint8_t test_cli_test_multiple_violations(slop_arena* arena);
uint8_t test_cli_test_report_string(slop_arena* arena);
uint8_t test_cli_test_employee_directory(slop_arena* arena);
uint8_t test_cli_test_product_catalog(slop_arena* arena);
uint8_t test_cli_test_address_book(slop_arena* arena);
uint8_t test_cli_test_valid_library(slop_arena* arena);
uint8_t test_cli_test_multi_shape(slop_arena* arena);
uint8_t test_cli_test_subclass_class_conforms(slop_arena* arena);
uint8_t test_cli_test_subclass_class(slop_arena* arena);
uint8_t test_cli_test_vacuous_or(slop_arena* arena);
int main(int argc, char** _c_argv);

slop_option_index_IndexedGraph test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_227 = ttl_parse_ttl_file(arena, path);
    if (_mv_227.is_ok) {
        __auto_type g = _mv_227.data.ok;
        {
            __auto_type ig = rdf_indexed_graph_create(arena);
            {
                __auto_type _coll = g.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    ig = rdf_indexed_graph_add(arena, ig, t);
                }
            }
            return (slop_option_index_IndexedGraph){.has_value = 1, .value = ig};
        }
    } else if (!_mv_227.is_ok) {
        __auto_type _ = _mv_227.data.err;
        return (slop_option_index_IndexedGraph){.has_value = false};
    }
}

uint8_t test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_228 = test_cli_load_test_graph(arena, path);
    if (_mv_228.has_value) {
        __auto_type g = _mv_228.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (result) {
                printf("%s", "  PASS: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected to conform but got violations");
                return 0;
            }
        }
    } else if (!_mv_228.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_229 = test_cli_load_test_graph(arena, path);
    if (_mv_229.has_value) {
        __auto_type g = _mv_229.value;
        __auto_type _mv_230 = snarl_validate(arena, g, g);
        switch (_mv_230.tag) {
            case types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_230.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if ((actual_count == expected_count)) {
                        printf("%s", "  PASS: ");
                        printf("%.*s", (int)(path).len, (path).data);
                        printf("%s", " has ");
                        printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                        printf("%s\n", " violation(s)");
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        printf("%.*s", (int)(path).len, (path).data);
                        printf("%s", " expected ");
                        printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                        printf("%s", " violation(s) but got ");
                        printf("%.*s\n", (int)(int_to_string(arena, actual_count)).len, (int_to_string(arena, actual_count)).data);
                        return 0;
                    }
                }
            }
            case types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_230.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 0;
            }
        }
    } else if (!_mv_229.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_231 = test_cli_load_test_graph(arena, path);
    if (_mv_231.has_value) {
        __auto_type g = _mv_231.value;
        {
            __auto_type result = snarl_conforms(arena, g, g);
            if (!(result)) {
                printf("%s", "  PASS: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " has violations");
                return 1;
            } else {
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected violations but conforms");
                return 0;
            }
        }
    } else if (!_mv_231.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_232 = test_cli_load_test_graph(arena, data_path);
    if (_mv_232.has_value) {
        __auto_type dg = _mv_232.value;
        __auto_type _mv_233 = test_cli_load_test_graph(arena, shapes_path);
        if (_mv_233.has_value) {
            __auto_type sg = _mv_233.value;
            {
                __auto_type result = snarl_conforms(arena, dg, sg);
                if (result) {
                    printf("%s", "  PASS: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " conforms");
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " expected to conform but got violations");
                    return 0;
                }
            }
        } else if (!_mv_233.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
    } else if (!_mv_232.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
}

uint8_t test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count) {
    __auto_type _mv_234 = test_cli_load_test_graph(arena, data_path);
    if (_mv_234.has_value) {
        __auto_type dg = _mv_234.value;
        __auto_type _mv_235 = test_cli_load_test_graph(arena, shapes_path);
        if (_mv_235.has_value) {
            __auto_type sg = _mv_235.value;
            __auto_type _mv_236 = snarl_validate(arena, dg, sg);
            switch (_mv_236.tag) {
                case types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_236.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if ((actual_count == expected_count)) {
                            printf("%s", "  PASS: ");
                            printf("%.*s", (int)(data_path).len, (data_path).data);
                            printf("%s", " has ");
                            printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                            printf("%s\n", " violation(s)");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: ");
                            printf("%.*s", (int)(data_path).len, (data_path).data);
                            printf("%s", " expected ");
                            printf("%.*s", (int)(int_to_string(arena, expected_count)).len, (int_to_string(arena, expected_count)).data);
                            printf("%s", " violation(s) but got ");
                            printf("%.*s\n", (int)(int_to_string(arena, actual_count)).len, (int_to_string(arena, actual_count)).data);
                            return 0;
                        }
                    }
                }
                case types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_236.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 0;
                }
            }
        } else if (!_mv_235.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
    } else if (!_mv_234.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
}

uint8_t test_cli_test_empty_graph(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/empty.ttl"));
}

uint8_t test_cli_test_valid_person(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/valid-person.ttl"));
}

uint8_t test_cli_test_rdf12_annotation_block(slop_arena* arena) {
    __auto_type _mv_237 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_237.has_value) {
        __auto_type g = _mv_237.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if (((size == 17) && snarl_conforms(arena, g, g))) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                printf("%.*s\n", (int)(int_to_string(arena, size)).len, (int_to_string(arena, size)).data);
                return 0;
            }
        }
    } else if (!_mv_237.has_value) {
        printf("%s\n", "  FAIL: could not load RDF 1.2 annotation fixture");
        return 0;
    }
}

uint8_t test_cli_test_cardinality_violation(slop_arena* arena) {
    return test_cli_assert_has_violations(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
}

uint8_t test_cli_test_datatype_violation(slop_arena* arena) {
    return test_cli_assert_has_violations(arena, SLOP_STR("fixtures/datatype-violation.ttl"));
}

uint8_t test_cli_test_class_violation(slop_arena* arena) {
    return test_cli_assert_has_violations(arena, SLOP_STR("fixtures/class-violation.ttl"));
}

uint8_t test_cli_test_nodekind_violation(slop_arena* arena) {
    return test_cli_assert_has_violations(arena, SLOP_STR("fixtures/nodekind-violation.ttl"));
}

uint8_t test_cli_test_target_node(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/target-node.ttl"));
}

uint8_t test_cli_test_multiple_violations(slop_arena* arena) {
    return test_cli_assert_has_violations(arena, SLOP_STR("fixtures/multiple-violations.ttl"));
}

uint8_t test_cli_test_report_string(slop_arena* arena) {
    __auto_type _mv_238 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_238.has_value) {
        __auto_type g = _mv_238.value;
        __auto_type _mv_239 = snarl_validate(arena, g, g);
        switch (_mv_239.tag) {
            case types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_239.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if ((string_len(text) > 0)) {
                        printf("%s\n", "  PASS: report-to-string produces output");
                        return 1;
                    } else {
                        printf("%s\n", "  FAIL: report-to-string returned empty string");
                        return 0;
                    }
                }
            }
            case types_ValidatorResult_validate_error:
            {
                __auto_type _ = _mv_239.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
    } else if (!_mv_238.has_value) {
        printf("%s\n", "  FAIL: could not load fixture");
        return 0;
    }
}

uint8_t test_cli_test_employee_directory(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/employee-dir-data.ttl"), SLOP_STR("fixtures/employee-dir-shapes.ttl"), 5);
}

uint8_t test_cli_test_product_catalog(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/product-catalog-data.ttl"), SLOP_STR("fixtures/product-catalog-shapes.ttl"), 3);
}

uint8_t test_cli_test_address_book(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/address-book-data.ttl"), SLOP_STR("fixtures/address-book-shapes.ttl"), 2);
}

uint8_t test_cli_test_valid_library(slop_arena* arena) {
    return test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/library-data.ttl"), SLOP_STR("fixtures/library-shapes.ttl"));
}

uint8_t test_cli_test_multi_shape(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/multi-shape-data.ttl"), SLOP_STR("fixtures/multi-shape-shapes.ttl"), 3);
}

uint8_t test_cli_test_subclass_class_conforms(slop_arena* arena) {
    return test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/subclass-class-conforms-data.ttl"), SLOP_STR("fixtures/subclass-class-conforms-shapes.ttl"));
}

uint8_t test_cli_test_subclass_class(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/subclass-class-data.ttl"), SLOP_STR("fixtures/subclass-class-shapes.ttl"), 1);
}

uint8_t test_cli_test_vacuous_or(slop_arena* arena) {
    return test_cli_assert_violations_separate(arena, SLOP_STR("fixtures/vacuous-or-data.ttl"), SLOP_STR("fixtures/vacuous-or-shapes.ttl"), 1);
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((67108864) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena = slop_arena_new(67108864);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena;
        printf("%s\n", "Snarl CLI Integration Tests");
        printf("%s\n", "===========================");
        printf("%s\n", "");
        {
            int64_t passed = 0;
            int64_t failed = 0;
            if (test_cli_test_empty_graph(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_valid_person(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_rdf12_annotation_block(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cardinality_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_datatype_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_class_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_nodekind_violation(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_target_node(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_multiple_violations(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_report_string(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_employee_directory(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_product_catalog(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_address_book(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_valid_library(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_multi_shape(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_subclass_class_conforms(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_subclass_class(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_vacuous_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            printf("%s\n", "");
            printf("%s\n", "---");
            printf("%.*s", (int)(int_to_string(arena, passed)).len, (int_to_string(arena, passed)).data);
            printf("%s", " passed, ");
            printf("%.*s", (int)(int_to_string(arena, failed)).len, (int_to_string(arena, failed)).data);
            printf("%s\n", " failed");
            if ((failed == 0)) {
                return 0;
            } else {
                return 1;
            }
        }
        slop_arena_free(arena);
    }
}

