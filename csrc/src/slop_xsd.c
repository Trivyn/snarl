#include "../runtime/slop_runtime.h"
#include "slop_xsd.h"

slop_rdf_xsd_XsdType xsd_parse_type(slop_string datatype_iri);
slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, slop_rdf_xsd_XsdType dtype);
uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri);
uint8_t xsd_values_equal(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b);
uint8_t xsd_types_compatible(slop_rdf_xsd_XsdType t1, slop_rdf_xsd_XsdType t2);
slop_result_u8_slop_rdf_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, slop_rdf_rdf_Literal a, slop_rdf_rdf_Literal b);
slop_rdf_xsd_XsdCompareResult xsd_float_cmp(double a, double b);
slop_rdf_xsd_XsdCompareResult xsd_values_compare(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b);
slop_rdf_xsd_XsdCompareResult xsd_compare(slop_arena* arena, slop_rdf_rdf_Term a, slop_rdf_rdf_Term b);

slop_rdf_xsd_XsdType xsd_parse_type(slop_string datatype_iri) {
    if (string_eq(datatype_iri, slop_rdf_vocab_XSD_STRING)) {
        return slop_rdf_xsd_XsdType_xsd_string;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_INTEGER)) {
        return slop_rdf_xsd_XsdType_xsd_integer;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_BOOLEAN)) {
        return slop_rdf_xsd_XsdType_xsd_boolean;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DECIMAL)) {
        return slop_rdf_xsd_XsdType_xsd_decimal;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_FLOAT)) {
        return slop_rdf_xsd_XsdType_xsd_float;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DOUBLE)) {
        return slop_rdf_xsd_XsdType_xsd_double;
    } else {
        return slop_rdf_xsd_XsdType_xsd_unknown;
    }
}

slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, slop_rdf_xsd_XsdType dtype) {
    __auto_type _mv_180 = dtype;
    switch (_mv_180) {
        case slop_rdf_xsd_XsdType_xsd_string: {
            return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_string_val, .data.xsd_string_val = lexical }) });
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_integer: {
            __auto_type _mv_181 = std_strlib_parse_int(lexical);
            if (_mv_181.is_ok) {
                __auto_type val = _mv_181.data.ok;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_integer_val, .data.xsd_integer_val = val }) });
            } else if (!_mv_181.is_ok) {
                __auto_type _ = _mv_181.data.err;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = slop_rdf_xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_boolean: {
            if (string_eq(lexical, SLOP_STR("true"))) {
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_boolean_val, .data.xsd_boolean_val = 1 }) });
            } else {
                if (string_eq(lexical, SLOP_STR("false"))) {
                    return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_boolean_val, .data.xsd_boolean_val = 0 }) });
                } else {
                    return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = slop_rdf_xsd_XsdError_invalid_lexical_form });
                }
            }
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_decimal: {
            __auto_type _mv_182 = std_strlib_parse_float(lexical);
            if (_mv_182.is_ok) {
                __auto_type val = _mv_182.data.ok;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_decimal_val, .data.xsd_decimal_val = val }) });
            } else if (!_mv_182.is_ok) {
                __auto_type _ = _mv_182.data.err;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = slop_rdf_xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_float: {
            __auto_type _mv_183 = std_strlib_parse_float(lexical);
            if (_mv_183.is_ok) {
                __auto_type val = _mv_183.data.ok;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_float_val, .data.xsd_float_val = ((float)(val)) }) });
            } else if (!_mv_183.is_ok) {
                __auto_type _ = _mv_183.data.err;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = slop_rdf_xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_double: {
            __auto_type _mv_184 = std_strlib_parse_float(lexical);
            if (_mv_184.is_ok) {
                __auto_type val = _mv_184.data.ok;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_double_val, .data.xsd_double_val = val }) });
            } else if (!_mv_184.is_ok) {
                __auto_type _ = _mv_184.data.err;
                return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = slop_rdf_xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case slop_rdf_xsd_XsdType_xsd_unknown: {
            return ((slop_result_slop_rdf_xsd_XsdValue_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = ((slop_rdf_xsd_XsdValue){ .tag = slop_rdf_xsd_XsdValue_xsd_unknown_val, .data.xsd_unknown_val = lexical }) });
            break;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri) {
    if (string_eq(datatype_iri, slop_rdf_vocab_XSD_STRING)) {
        return 1;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_INTEGER)) {
        __auto_type _mv_185 = std_strlib_parse_int(lexical);
        if (_mv_185.is_ok) {
            __auto_type _ = _mv_185.data.ok;
            return 1;
        } else if (!_mv_185.is_ok) {
            __auto_type _ = _mv_185.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_BOOLEAN)) {
        return ((string_eq(lexical, SLOP_STR("true"))) || (string_eq(lexical, SLOP_STR("false"))) || (string_eq(lexical, SLOP_STR("1"))) || (string_eq(lexical, SLOP_STR("0"))));
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DECIMAL)) {
        __auto_type _mv_186 = std_strlib_parse_float(lexical);
        if (_mv_186.is_ok) {
            __auto_type _ = _mv_186.data.ok;
            return 1;
        } else if (!_mv_186.is_ok) {
            __auto_type _ = _mv_186.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_FLOAT)) {
        __auto_type _mv_187 = std_strlib_parse_float(lexical);
        if (_mv_187.is_ok) {
            __auto_type _ = _mv_187.data.ok;
            return 1;
        } else if (!_mv_187.is_ok) {
            __auto_type _ = _mv_187.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DOUBLE)) {
        __auto_type _mv_188 = std_strlib_parse_float(lexical);
        if (_mv_188.is_ok) {
            __auto_type _ = _mv_188.data.ok;
            return 1;
        } else if (!_mv_188.is_ok) {
            __auto_type _ = _mv_188.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_LONG)) {
        __auto_type _mv_189 = std_strlib_parse_int(lexical);
        if (_mv_189.is_ok) {
            __auto_type _ = _mv_189.data.ok;
            return 1;
        } else if (!_mv_189.is_ok) {
            __auto_type _ = _mv_189.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_INT)) {
        __auto_type _mv_190 = std_strlib_parse_int(lexical);
        if (_mv_190.is_ok) {
            __auto_type v = _mv_190.data.ok;
            return ((v >= -2147483648) && (v <= 2147483647));
        } else if (!_mv_190.is_ok) {
            __auto_type _ = _mv_190.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_SHORT)) {
        __auto_type _mv_191 = std_strlib_parse_int(lexical);
        if (_mv_191.is_ok) {
            __auto_type v = _mv_191.data.ok;
            return ((v >= -32768) && (v <= 32767));
        } else if (!_mv_191.is_ok) {
            __auto_type _ = _mv_191.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_BYTE)) {
        __auto_type _mv_192 = std_strlib_parse_int(lexical);
        if (_mv_192.is_ok) {
            __auto_type v = _mv_192.data.ok;
            return ((v >= -128) && (v <= 127));
        } else if (!_mv_192.is_ok) {
            __auto_type _ = _mv_192.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_UNSIGNED_LONG)) {
        __auto_type _mv_193 = std_strlib_parse_int(lexical);
        if (_mv_193.is_ok) {
            __auto_type v = _mv_193.data.ok;
            return (v >= 0);
        } else if (!_mv_193.is_ok) {
            __auto_type _ = _mv_193.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_UNSIGNED_INT)) {
        __auto_type _mv_194 = std_strlib_parse_int(lexical);
        if (_mv_194.is_ok) {
            __auto_type v = _mv_194.data.ok;
            return ((v >= 0) && (v <= 4294967295));
        } else if (!_mv_194.is_ok) {
            __auto_type _ = _mv_194.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_UNSIGNED_SHORT)) {
        __auto_type _mv_195 = std_strlib_parse_int(lexical);
        if (_mv_195.is_ok) {
            __auto_type v = _mv_195.data.ok;
            return ((v >= 0) && (v <= 65535));
        } else if (!_mv_195.is_ok) {
            __auto_type _ = _mv_195.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_UNSIGNED_BYTE)) {
        __auto_type _mv_196 = std_strlib_parse_int(lexical);
        if (_mv_196.is_ok) {
            __auto_type v = _mv_196.data.ok;
            return ((v >= 0) && (v <= 255));
        } else if (!_mv_196.is_ok) {
            __auto_type _ = _mv_196.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_NON_NEGATIVE_INTEGER)) {
        __auto_type _mv_197 = std_strlib_parse_int(lexical);
        if (_mv_197.is_ok) {
            __auto_type v = _mv_197.data.ok;
            return (v >= 0);
        } else if (!_mv_197.is_ok) {
            __auto_type _ = _mv_197.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_POSITIVE_INTEGER)) {
        __auto_type _mv_198 = std_strlib_parse_int(lexical);
        if (_mv_198.is_ok) {
            __auto_type v = _mv_198.data.ok;
            return (v >= 1);
        } else if (!_mv_198.is_ok) {
            __auto_type _ = _mv_198.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_NEGATIVE_INTEGER)) {
        __auto_type _mv_199 = std_strlib_parse_int(lexical);
        if (_mv_199.is_ok) {
            __auto_type v = _mv_199.data.ok;
            return (v <= -1);
        } else if (!_mv_199.is_ok) {
            __auto_type _ = _mv_199.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_NON_POSITIVE_INTEGER)) {
        __auto_type _mv_200 = std_strlib_parse_int(lexical);
        if (_mv_200.is_ok) {
            __auto_type v = _mv_200.data.ok;
            return (v <= 0);
        } else if (!_mv_200.is_ok) {
            __auto_type _ = _mv_200.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, slop_rdf_vocab_RDF_LANG_STRING)) {
        return 1;
    } else {
        return 1;
    }
}

uint8_t xsd_values_equal(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b) {
    __auto_type _mv_201 = a;
    switch (_mv_201.tag) {
        case slop_rdf_xsd_XsdValue_xsd_string_val:
        {
            __auto_type s1 = _mv_201.data.xsd_string_val;
            __auto_type _mv_202 = b;
            switch (_mv_202.tag) {
                case slop_rdf_xsd_XsdValue_xsd_string_val:
                {
                    __auto_type s2 = _mv_202.data.xsd_string_val;
                    return string_eq(s1, s2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_integer_val:
        {
            __auto_type i1 = _mv_201.data.xsd_integer_val;
            __auto_type _mv_203 = b;
            switch (_mv_203.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_203.data.xsd_integer_val;
                    return (i1 == i2);
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_203.data.xsd_decimal_val;
                    return (((double)(i1)) == d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_203.data.xsd_float_val;
                    return (((double)(i1)) == ((double)(f2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_203.data.xsd_double_val;
                    return (((double)(i1)) == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_decimal_val:
        {
            __auto_type d1 = _mv_201.data.xsd_decimal_val;
            __auto_type _mv_204 = b;
            switch (_mv_204.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_204.data.xsd_integer_val;
                    return (d1 == ((double)(i2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_204.data.xsd_decimal_val;
                    return (d1 == d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_204.data.xsd_float_val;
                    return (d1 == ((double)(f2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_204.data.xsd_double_val;
                    return (d1 == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_float_val:
        {
            __auto_type f1 = _mv_201.data.xsd_float_val;
            __auto_type _mv_205 = b;
            switch (_mv_205.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_205.data.xsd_integer_val;
                    return (((double)(f1)) == ((double)(i2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_205.data.xsd_decimal_val;
                    return (((double)(f1)) == d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_205.data.xsd_float_val;
                    return (f1 == f2);
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_205.data.xsd_double_val;
                    return (((double)(f1)) == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_double_val:
        {
            __auto_type d1 = _mv_201.data.xsd_double_val;
            __auto_type _mv_206 = b;
            switch (_mv_206.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_206.data.xsd_integer_val;
                    return (d1 == ((double)(i2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_206.data.xsd_decimal_val;
                    return (d1 == d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_206.data.xsd_float_val;
                    return (d1 == ((double)(f2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_206.data.xsd_double_val;
                    return (d1 == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_boolean_val:
        {
            __auto_type b1 = _mv_201.data.xsd_boolean_val;
            __auto_type _mv_207 = b;
            switch (_mv_207.tag) {
                case slop_rdf_xsd_XsdValue_xsd_boolean_val:
                {
                    __auto_type b2 = _mv_207.data.xsd_boolean_val;
                    return (b1 == b2);
                }
                default: {
                    return 0;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_unknown_val:
        {
            __auto_type u1 = _mv_201.data.xsd_unknown_val;
            __auto_type _mv_208 = b;
            switch (_mv_208.tag) {
                case slop_rdf_xsd_XsdValue_xsd_unknown_val:
                {
                    __auto_type u2 = _mv_208.data.xsd_unknown_val;
                    return string_eq(u1, u2);
                }
                default: {
                    return 0;
                }
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t xsd_types_compatible(slop_rdf_xsd_XsdType t1, slop_rdf_xsd_XsdType t2) {
    return ((t1 == t2) || ((((t1 == slop_rdf_xsd_XsdType_xsd_integer)) || ((t1 == slop_rdf_xsd_XsdType_xsd_decimal)) || ((t1 == slop_rdf_xsd_XsdType_xsd_float)) || ((t1 == slop_rdf_xsd_XsdType_xsd_double))) && (((t2 == slop_rdf_xsd_XsdType_xsd_integer)) || ((t2 == slop_rdf_xsd_XsdType_xsd_decimal)) || ((t2 == slop_rdf_xsd_XsdType_xsd_float)) || ((t2 == slop_rdf_xsd_XsdType_xsd_double)))));
}

slop_result_u8_slop_rdf_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, slop_rdf_rdf_Literal a, slop_rdf_rdf_Literal b) {
    __auto_type _mv_209 = a.lang;
    if (_mv_209.has_value) {
        __auto_type lang_a = _mv_209.value;
        __auto_type _mv_210 = b.lang;
        if (_mv_210.has_value) {
            __auto_type lang_b = _mv_210.value;
            if (string_eq(lang_a, lang_b)) {
                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = string_eq(a.value, b.value) });
            } else {
                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            }
        } else if (!_mv_210.has_value) {
            return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_209.has_value) {
        __auto_type _mv_211 = a.datatype;
        if (_mv_211.has_value) {
            __auto_type dt_a = _mv_211.value;
            __auto_type _mv_212 = b.datatype;
            if (_mv_212.has_value) {
                __auto_type dt_b = _mv_212.value;
                {
                    __auto_type type_a = xsd_parse_type(dt_a);
                    {
                        __auto_type type_b = xsd_parse_type(dt_b);
                        {
                            __auto_type val_a = ({ __auto_type _tmp = xsd_parse_value(arena, a.value, type_a); if (!_tmp.is_ok) return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = _tmp.data.err }); _tmp.data.ok; });
                            {
                                __auto_type val_b = ({ __auto_type _tmp = xsd_parse_value(arena, b.value, type_b); if (!_tmp.is_ok) return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = false, .data.err = _tmp.data.err }); _tmp.data.ok; });
                                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = xsd_values_equal(val_a, val_b) });
                            }
                        }
                    }
                }
            } else if (!_mv_212.has_value) {
                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_211.has_value) {
            __auto_type _mv_213 = b.datatype;
            if (_mv_213.has_value) {
                __auto_type dt_b = _mv_213.value;
                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            } else if (!_mv_213.has_value) {
                return ((slop_result_u8_slop_rdf_xsd_XsdError){ .is_ok = true, .data.ok = string_eq(a.value, b.value) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_rdf_xsd_XsdCompareResult xsd_float_cmp(double a, double b) {
    if (a < b) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_less;
    } else {
        if (a > b) {
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_greater;
        } else {
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_equal;
        }
    }
}

slop_rdf_xsd_XsdCompareResult xsd_values_compare(slop_rdf_xsd_XsdValue a, slop_rdf_xsd_XsdValue b) {
    __auto_type _mv_214 = a;
    switch (_mv_214.tag) {
        case slop_rdf_xsd_XsdValue_xsd_integer_val:
        {
            __auto_type i1 = _mv_214.data.xsd_integer_val;
            {
                __auto_type d1 = ((double)(i1));
                __auto_type _mv_215 = b;
                switch (_mv_215.tag) {
                    case slop_rdf_xsd_XsdValue_xsd_integer_val:
                    {
                        __auto_type i2 = _mv_215.data.xsd_integer_val;
                        return xsd_float_cmp(d1, ((double)(i2)));
                    }
                    case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                    {
                        __auto_type d2 = _mv_215.data.xsd_decimal_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    case slop_rdf_xsd_XsdValue_xsd_float_val:
                    {
                        __auto_type f2 = _mv_215.data.xsd_float_val;
                        return xsd_float_cmp(d1, ((double)(f2)));
                    }
                    case slop_rdf_xsd_XsdValue_xsd_double_val:
                    {
                        __auto_type d2 = _mv_215.data.xsd_double_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    default: {
                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_decimal_val:
        {
            __auto_type d1 = _mv_214.data.xsd_decimal_val;
            __auto_type _mv_216 = b;
            switch (_mv_216.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_216.data.xsd_integer_val;
                    return xsd_float_cmp(d1, ((double)(i2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_216.data.xsd_decimal_val;
                    return xsd_float_cmp(d1, d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_216.data.xsd_float_val;
                    return xsd_float_cmp(d1, ((double)(f2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_216.data.xsd_double_val;
                    return xsd_float_cmp(d1, d2);
                }
                default: {
                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_float_val:
        {
            __auto_type f1 = _mv_214.data.xsd_float_val;
            {
                __auto_type d1 = ((double)(f1));
                __auto_type _mv_217 = b;
                switch (_mv_217.tag) {
                    case slop_rdf_xsd_XsdValue_xsd_integer_val:
                    {
                        __auto_type i2 = _mv_217.data.xsd_integer_val;
                        return xsd_float_cmp(d1, ((double)(i2)));
                    }
                    case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                    {
                        __auto_type d2 = _mv_217.data.xsd_decimal_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    case slop_rdf_xsd_XsdValue_xsd_float_val:
                    {
                        __auto_type f2 = _mv_217.data.xsd_float_val;
                        return xsd_float_cmp(d1, ((double)(f2)));
                    }
                    case slop_rdf_xsd_XsdValue_xsd_double_val:
                    {
                        __auto_type d2 = _mv_217.data.xsd_double_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    default: {
                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_double_val:
        {
            __auto_type d1 = _mv_214.data.xsd_double_val;
            __auto_type _mv_218 = b;
            switch (_mv_218.tag) {
                case slop_rdf_xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_218.data.xsd_integer_val;
                    return xsd_float_cmp(d1, ((double)(i2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_218.data.xsd_decimal_val;
                    return xsd_float_cmp(d1, d2);
                }
                case slop_rdf_xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_218.data.xsd_float_val;
                    return xsd_float_cmp(d1, ((double)(f2)));
                }
                case slop_rdf_xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_218.data.xsd_double_val;
                    return xsd_float_cmp(d1, d2);
                }
                default: {
                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_string_val:
        {
            __auto_type s1 = _mv_214.data.xsd_string_val;
            __auto_type _mv_219 = b;
            switch (_mv_219.tag) {
                case slop_rdf_xsd_XsdValue_xsd_string_val:
                {
                    __auto_type s2 = _mv_219.data.xsd_string_val;
                    if (string_eq(s1, s2)) {
                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_equal;
                    } else {
                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
                default: {
                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_boolean_val:
        {
            __auto_type b1 = _mv_214.data.xsd_boolean_val;
            __auto_type _mv_220 = b;
            switch (_mv_220.tag) {
                case slop_rdf_xsd_XsdValue_xsd_boolean_val:
                {
                    __auto_type b2 = _mv_220.data.xsd_boolean_val;
                    if (b1 == b2) {
                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_equal;
                    } else {
                        if (b2) {
                            return slop_rdf_xsd_XsdCompareResult_xsd_compare_less;
                        } else {
                            return slop_rdf_xsd_XsdCompareResult_xsd_compare_greater;
                        }
                    }
                }
                default: {
                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case slop_rdf_xsd_XsdValue_xsd_unknown_val:
        {
            __auto_type _ = _mv_214.data.xsd_unknown_val;
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
        }
    }
    SLOP_UNREACHABLE();
}

slop_rdf_xsd_XsdCompareResult xsd_compare(slop_arena* arena, slop_rdf_rdf_Term a, slop_rdf_rdf_Term b) {
    __auto_type _mv_221 = a;
    switch (_mv_221.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit_a = _mv_221.data.term_literal;
            __auto_type _mv_222 = b;
            switch (_mv_222.tag) {
                case slop_rdf_rdf_Term_term_literal:
                {
                    __auto_type lit_b = _mv_222.data.term_literal;
                    {
                        __auto_type dt_a = ({ __auto_type _mv = lit_a.datatype; _mv.has_value ? ({ __auto_type d = _mv.value; d; }) : (slop_rdf_vocab_XSD_STRING); });
                        __auto_type dt_b = ({ __auto_type _mv = lit_b.datatype; _mv.has_value ? ({ __auto_type d = _mv.value; d; }) : (slop_rdf_vocab_XSD_STRING); });
                        {
                            __auto_type type_a = xsd_parse_type(dt_a);
                            __auto_type type_b = xsd_parse_type(dt_b);
                            if (!(xsd_types_compatible(type_a, type_b))) {
                                return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                            } else {
                                __auto_type _mv_223 = xsd_parse_value(arena, lit_a.value, type_a);
                                if (_mv_223.is_ok) {
                                    __auto_type val_a = _mv_223.data.ok;
                                    __auto_type _mv_224 = xsd_parse_value(arena, lit_b.value, type_b);
                                    if (_mv_224.is_ok) {
                                        __auto_type val_b = _mv_224.data.ok;
                                        return xsd_values_compare(val_a, val_b);
                                    } else if (!_mv_224.is_ok) {
                                        __auto_type _ = _mv_224.data.err;
                                        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                                    }
                                    SLOP_UNREACHABLE();
                                } else if (!_mv_223.is_ok) {
                                    __auto_type _ = _mv_223.data.err;
                                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                                }
                                SLOP_UNREACHABLE();
                            }
                        }
                    }
                }
                default: {
                    return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        default: {
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
        }
    }
}

