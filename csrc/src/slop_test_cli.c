#include "../runtime/slop_runtime.h"
#include "slop_test_cli.h"

slop_option_index_IndexedGraph test_cli_load_test_graph(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count);
uint8_t test_cli_assert_has_violations(slop_arena* arena, slop_string path);
uint8_t test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path);
uint8_t test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring);
uint8_t test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring);
void test_cli_reset_test_arena(slop_arena* arena);
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
uint8_t test_cli_test_cycle_self_loop(slop_arena* arena);
uint8_t test_cli_test_cycle_mutual(slop_arena* arena);
uint8_t test_cli_test_cycle_acyclic_chain(slop_arena* arena);
uint8_t test_cli_test_cycle_diamond(slop_arena* arena);
uint8_t test_cli_test_cycle_recursive_person_acyclic(slop_arena* arena);
uint8_t test_cli_test_cycle_recursive_person_cyclic(slop_arena* arena);
uint8_t test_cli_test_cycle_path_inverse_self(slop_arena* arena);
uint8_t test_cli_test_cycle_in_list(slop_arena* arena);
uint8_t test_cli_test_cycle_path_legitimate(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_node(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_and(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_or(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_xone(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_not(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_acyclic_control(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_swallowed(slop_arena* arena);
uint8_t test_cli_test_cycle_propshape_swallowed_control(slop_arena* arena);
uint8_t test_cli_test_cycle_qualified_value_shape(slop_arena* arena);
uint8_t test_cli_test_cycle_list_and(slop_arena* arena);
uint8_t test_cli_test_cycle_list_or(slop_arena* arena);
uint8_t test_cli_test_cycle_list_xone(slop_arena* arena);
uint8_t test_cli_test_cycle_list_language_in(slop_arena* arena);
uint8_t test_cli_test_cycle_list_ignored_properties(slop_arena* arena);
uint8_t test_cli_test_max_errors_precedence(slop_arena* arena);
uint8_t test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena);
uint8_t test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena);
uint8_t test_cli_test_cycle_path_linear_50000(slop_arena* arena);
uint8_t test_cli_test_cycle_path_shared_dag_30(slop_arena* arena);
int main(int argc, char** _c_argv);

slop_option_index_IndexedGraph test_cli_load_test_graph(slop_arena* arena, slop_string path) {
    __auto_type _mv_307 = ttl_parse_ttl_file(arena, path);
    if (_mv_307.is_ok) {
        __auto_type g = _mv_307.data.ok;
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
    } else if (!_mv_307.is_ok) {
        __auto_type _ = _mv_307.data.err;
        return (slop_option_index_IndexedGraph){.has_value = false};
    }
}

uint8_t test_cli_assert_conforms(slop_arena* arena, slop_string path) {
    __auto_type _mv_308 = test_cli_load_test_graph(arena, path);
    if (_mv_308.has_value) {
        __auto_type g = _mv_308.value;
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
    } else if (!_mv_308.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_violations(slop_arena* arena, slop_string path, int64_t expected_count) {
    __auto_type _mv_309 = test_cli_load_test_graph(arena, path);
    if (_mv_309.has_value) {
        __auto_type g = _mv_309.value;
        __auto_type _mv_310 = snarl_validate(arena, g, g);
        switch (_mv_310.tag) {
            case types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_310.data.validate_success;
                {
                    __auto_type violations = snarl_get_violations(arena, report);
                    __auto_type actual_count = ((int64_t)((violations).len));
                    if (actual_count == expected_count) {
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
                __auto_type msg = _mv_310.data.validate_error;
                printf("%s", "  FAIL: validation error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 0;
            }
        }
    } else if (!_mv_309.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_has_violations(slop_arena* arena, slop_string path) {
    __auto_type _mv_311 = test_cli_load_test_graph(arena, path);
    if (_mv_311.has_value) {
        __auto_type g = _mv_311.value;
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
    } else if (!_mv_311.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_conforms_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path) {
    __auto_type _mv_312 = test_cli_load_test_graph(arena, data_path);
    if (_mv_312.has_value) {
        __auto_type dg = _mv_312.value;
        __auto_type _mv_313 = test_cli_load_test_graph(arena, shapes_path);
        if (_mv_313.has_value) {
            __auto_type sg = _mv_313.value;
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
        } else if (!_mv_313.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
    } else if (!_mv_312.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
}

uint8_t test_cli_assert_engine_error(slop_arena* arena, slop_string path, slop_string expected_substring) {
    __auto_type _mv_314 = test_cli_load_test_graph(arena, path);
    if (_mv_314.has_value) {
        __auto_type g = _mv_314.value;
        __auto_type _mv_315 = snarl_validate(arena, g, g);
        switch (_mv_315.tag) {
            case types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_315.data.validate_error;
                if (strlib_contains(msg, expected_substring)) {
                    printf("%s", "  PASS: ");
                    printf("%.*s", (int)(path).len, (path).data);
                    printf("%s", " engine error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 1;
                } else {
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(path).len, (path).data);
                    printf("%s", " engine error message did not contain '");
                    printf("%.*s", (int)(expected_substring).len, (expected_substring).data);
                    printf("%s", "': ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 0;
                }
            }
            case types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_315.data.validate_success;
                printf("%s", "  FAIL: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s\n", " expected engine error but validation succeeded");
                return 0;
            }
        }
    } else if (!_mv_314.has_value) {
        printf("%s", "  FAIL: could not load ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    }
}

uint8_t test_cli_assert_engine_error_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, slop_string expected_substring) {
    __auto_type _mv_316 = test_cli_load_test_graph(arena, data_path);
    if (_mv_316.has_value) {
        __auto_type dg = _mv_316.value;
        __auto_type _mv_317 = test_cli_load_test_graph(arena, shapes_path);
        if (_mv_317.has_value) {
            __auto_type sg = _mv_317.value;
            __auto_type _mv_318 = snarl_validate(arena, dg, sg);
            switch (_mv_318.tag) {
                case types_ValidatorResult_validate_error:
                {
                    __auto_type msg = _mv_318.data.validate_error;
                    if (strlib_contains(msg, expected_substring)) {
                        printf("%s", "  PASS: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s", " engine error: ");
                        printf("%.*s\n", (int)(msg).len, (msg).data);
                        return 1;
                    } else {
                        printf("%s", "  FAIL: ");
                        printf("%.*s", (int)(data_path).len, (data_path).data);
                        printf("%s", " engine error message did not contain '");
                        printf("%.*s", (int)(expected_substring).len, (expected_substring).data);
                        printf("%s", "': ");
                        printf("%.*s\n", (int)(msg).len, (msg).data);
                        return 0;
                    }
                }
                case types_ValidatorResult_validate_success:
                {
                    __auto_type _ = _mv_318.data.validate_success;
                    printf("%s", "  FAIL: ");
                    printf("%.*s", (int)(data_path).len, (data_path).data);
                    printf("%s\n", " expected engine error but validation succeeded");
                    return 0;
                }
            }
        } else if (!_mv_317.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
    } else if (!_mv_316.has_value) {
        printf("%s", "  FAIL: could not load data ");
        printf("%.*s\n", (int)(data_path).len, (data_path).data);
        return 0;
    }
}

void test_cli_reset_test_arena(slop_arena* arena) {
    slop_arena_reset(arena);
}

uint8_t test_cli_assert_violations_separate(slop_arena* arena, slop_string data_path, slop_string shapes_path, int64_t expected_count) {
    __auto_type _mv_319 = test_cli_load_test_graph(arena, data_path);
    if (_mv_319.has_value) {
        __auto_type dg = _mv_319.value;
        __auto_type _mv_320 = test_cli_load_test_graph(arena, shapes_path);
        if (_mv_320.has_value) {
            __auto_type sg = _mv_320.value;
            __auto_type _mv_321 = snarl_validate(arena, dg, sg);
            switch (_mv_321.tag) {
                case types_ValidatorResult_validate_success:
                {
                    __auto_type report = _mv_321.data.validate_success;
                    {
                        __auto_type violations = snarl_get_violations(arena, report);
                        __auto_type actual_count = ((int64_t)((violations).len));
                        if (actual_count == expected_count) {
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
                    __auto_type msg = _mv_321.data.validate_error;
                    printf("%s", "  FAIL: validation error: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    return 0;
                }
            }
        } else if (!_mv_320.has_value) {
            printf("%s", "  FAIL: could not load shapes ");
            printf("%.*s\n", (int)(shapes_path).len, (shapes_path).data);
            return 0;
        }
    } else if (!_mv_319.has_value) {
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
    __auto_type _mv_322 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/rdf12-annotation-valid.ttl"));
    if (_mv_322.has_value) {
        __auto_type g = _mv_322.value;
        {
            __auto_type size = rdf_indexed_graph_size(g);
            if ((size == 17) && snarl_conforms(arena, g, g)) {
                printf("%s\n", "  PASS: RDF 1.2 annotation block parses and conforms");
                return 1;
            } else {
                printf("%s", "  FAIL: RDF 1.2 annotation expected 17 triples and conformance, got ");
                printf("%.*s\n", (int)(int_to_string(arena, size)).len, (int_to_string(arena, size)).data);
                return 0;
            }
        }
    } else if (!_mv_322.has_value) {
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
    __auto_type _mv_323 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/cardinality-violation.ttl"));
    if (_mv_323.has_value) {
        __auto_type g = _mv_323.value;
        __auto_type _mv_324 = snarl_validate(arena, g, g);
        switch (_mv_324.tag) {
            case types_ValidatorResult_validate_success:
            {
                __auto_type report = _mv_324.data.validate_success;
                {
                    __auto_type text = snarl_report_to_string(arena, report);
                    if (string_len(text) > 0) {
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
                __auto_type _ = _mv_324.data.validate_error;
                printf("%s\n", "  FAIL: validation error");
                return 0;
            }
        }
    } else if (!_mv_323.has_value) {
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

uint8_t test_cli_test_cycle_self_loop(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-self-loop.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_mutual(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-mutual.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_acyclic_chain(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-chain.ttl"));
}

uint8_t test_cli_test_cycle_diamond(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-diamond.ttl"));
}

uint8_t test_cli_test_cycle_recursive_person_acyclic(slop_arena* arena) {
    return test_cli_assert_conforms_separate(arena, SLOP_STR("fixtures/cycle-recursive-person-acyclic-data.ttl"), SLOP_STR("fixtures/cycle-recursive-person-shapes.ttl"));
}

uint8_t test_cli_test_cycle_recursive_person_cyclic(slop_arena* arena) {
    return test_cli_assert_engine_error_separate(arena, SLOP_STR("fixtures/cycle-recursive-person-cyclic-data.ttl"), SLOP_STR("fixtures/cycle-recursive-person-shapes.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_path_inverse_self(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-path-inverse-self.ttl"), SLOP_STR("Cyclic sh:path expression detected"));
}

uint8_t test_cli_test_cycle_in_list(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-in-list.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_cycle_path_legitimate(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-legitimate.ttl"));
}

uint8_t test_cli_test_cycle_propshape_node(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-node.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_and(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-and.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_or(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-or.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_xone(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-xone.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_not(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-not.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_acyclic_control(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-acyclic-control.ttl"));
}

uint8_t test_cli_test_cycle_propshape_swallowed(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-propshape-swallowed.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_propshape_swallowed_control(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-propshape-swallowed-control.ttl"));
}

uint8_t test_cli_test_cycle_qualified_value_shape(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-qualified-value-shape.ttl"), SLOP_STR("Shape recursion detected"));
}

uint8_t test_cli_test_cycle_list_and(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-and.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_cycle_list_or(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-or.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_cycle_list_xone(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-xone.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_cycle_list_language_in(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-language-in.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_cycle_list_ignored_properties(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-list-ignored-properties.ttl"), SLOP_STR("Malformed RDF list detected"));
}

uint8_t test_cli_test_max_errors_precedence(slop_arena* arena) {
    __auto_type _mv_325 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-data.ttl"));
    if (_mv_325.has_value) {
        __auto_type dg = _mv_325.value;
        __auto_type _mv_326 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-maxerrors-shapes.ttl"));
        if (_mv_326.has_value) {
            __auto_type sg = _mv_326.value;
            {
                __auto_type config = ((types_ValidatorConfig){.verbose = 0, .max_errors = 1, .include_warnings = 1, .include_infos = 1});
                __auto_type _mv_327 = snarl_validate_with_config(arena, dg, sg, config);
                switch (_mv_327.tag) {
                    case types_ValidatorResult_validate_error:
                    {
                        __auto_type msg = _mv_327.data.validate_error;
                        if (strlib_contains(msg, SLOP_STR("Shape recursion"))) {
                            printf("%s\n", "  PASS: max-errors=1 still surfaces the engine error");
                            return 1;
                        } else {
                            printf("%s", "  FAIL: max-errors=1 error message did not contain 'Shape recursion': ");
                            printf("%.*s\n", (int)(msg).len, (msg).data);
                            return 0;
                        }
                    }
                    case types_ValidatorResult_validate_success:
                    {
                        __auto_type _ = _mv_327.data.validate_success;
                        printf("%s\n", "  FAIL: max-errors=1 silently truncated the engine error into a success report");
                        return 0;
                    }
                }
            }
        } else if (!_mv_326.has_value) {
            printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-shapes.ttl");
            return 0;
        }
    } else if (!_mv_325.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-maxerrors-data.ttl");
        return 0;
    }
}

uint8_t test_cli_test_cycle_scale_acyclic_3000(slop_arena* arena) {
    return test_cli_assert_engine_error(arena, SLOP_STR("fixtures/cycle-scale-acyclic-3000.ttl"), SLOP_STR("depth budget"));
}

uint8_t test_cli_test_cycle_scale_cyclic_1000(slop_arena* arena) {
    __auto_type _mv_328 = test_cli_load_test_graph(arena, SLOP_STR("fixtures/cycle-scale-cyclic-1000.ttl"));
    if (_mv_328.has_value) {
        __auto_type g = _mv_328.value;
        __auto_type _mv_329 = snarl_validate(arena, g, g);
        switch (_mv_329.tag) {
            case types_ValidatorResult_validate_error:
            {
                __auto_type msg = _mv_329.data.validate_error;
                printf("%s", "  PASS: fixtures/cycle-scale-cyclic-1000.ttl engine error: ");
                printf("%.*s\n", (int)(msg).len, (msg).data);
                return 1;
            }
            case types_ValidatorResult_validate_success:
            {
                __auto_type _ = _mv_329.data.validate_success;
                printf("%s\n", "  FAIL: fixtures/cycle-scale-cyclic-1000.ttl expected engine error but validation succeeded");
                return 0;
            }
        }
    } else if (!_mv_328.has_value) {
        printf("%s\n", "  FAIL: could not load fixtures/cycle-scale-cyclic-1000.ttl");
        return 0;
    }
}

uint8_t test_cli_test_cycle_path_linear_50000(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-linear-50000.ttl"));
}

uint8_t test_cli_test_cycle_path_shared_dag_30(slop_arena* arena) {
    return test_cli_assert_conforms(arena, SLOP_STR("fixtures/cycle-path-shared-dag-30.ttl"));
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
            if (test_cli_test_cycle_self_loop(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_mutual(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_acyclic_chain(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_diamond(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_recursive_person_acyclic(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_recursive_person_cyclic(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_path_inverse_self(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_in_list(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_path_legitimate(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_node(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_and(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_xone(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_not(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_acyclic_control(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_swallowed(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_propshape_swallowed_control(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_qualified_value_shape(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_list_and(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_list_or(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_list_xone(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_list_language_in(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_cycle_list_ignored_properties(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            if (test_cli_test_max_errors_precedence(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            test_cli_reset_test_arena(arena);
            if (test_cli_test_cycle_scale_acyclic_3000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            test_cli_reset_test_arena(arena);
            if (test_cli_test_cycle_scale_cyclic_1000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            test_cli_reset_test_arena(arena);
            if (test_cli_test_cycle_path_linear_50000(arena)) {
                passed = (passed + 1);
            } else {
                failed = (failed + 1);
            }
            test_cli_reset_test_arena(arena);
            if (test_cli_test_cycle_path_shared_dag_30(arena)) {
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
            if (failed == 0) {
                return 0;
            } else {
                return 1;
            }
        }
        slop_arena_free(arena);
    }
}

