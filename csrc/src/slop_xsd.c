#include "../runtime/slop_runtime.h"
#include "slop_xsd.h"

xsd_XsdType xsd_parse_type(slop_string datatype_iri);
slop_result_xsd_XsdValue_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, xsd_XsdType dtype);
uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri);
uint8_t xsd_values_equal(xsd_XsdValue a, xsd_XsdValue b);
uint8_t xsd_types_compatible(xsd_XsdType t1, xsd_XsdType t2);
slop_result_u8_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, rdf_Literal a, rdf_Literal b);
xsd_XsdCompareResult xsd_float_cmp(double a, double b);
xsd_XsdCompareResult xsd_values_compare(xsd_XsdValue a, xsd_XsdValue b);
xsd_XsdCompareResult xsd_compare(slop_arena* arena, rdf_Term a, rdf_Term b);

xsd_XsdType xsd_parse_type(slop_string datatype_iri) {
    if (string_eq(datatype_iri, vocab_XSD_STRING)) {
        return xsd_XsdType_xsd_string;
    } else if (string_eq(datatype_iri, vocab_XSD_INTEGER)) {
        return xsd_XsdType_xsd_integer;
    } else if (string_eq(datatype_iri, vocab_XSD_BOOLEAN)) {
        return xsd_XsdType_xsd_boolean;
    } else if (string_eq(datatype_iri, vocab_XSD_DECIMAL)) {
        return xsd_XsdType_xsd_decimal;
    } else if (string_eq(datatype_iri, vocab_XSD_FLOAT)) {
        return xsd_XsdType_xsd_float;
    } else if (string_eq(datatype_iri, vocab_XSD_DOUBLE)) {
        return xsd_XsdType_xsd_double;
    } else {
        return xsd_XsdType_xsd_unknown;
    }
}

slop_result_xsd_XsdValue_xsd_XsdError xsd_parse_value(slop_arena* arena, slop_string lexical, xsd_XsdType dtype) {
    __auto_type _mv_159 = dtype;
    switch (_mv_159) {
        case xsd_XsdType_xsd_string: {
            return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_string_val, .data.xsd_string_val = lexical }) });
            break;
        }
        case xsd_XsdType_xsd_integer: {
            __auto_type _mv_160 = strlib_parse_int(lexical);
            if (_mv_160.is_ok) {
                __auto_type val = _mv_160.data.ok;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_integer_val, .data.xsd_integer_val = val }) });
            } else if (!_mv_160.is_ok) {
                __auto_type _ = _mv_160.data.err;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = false, .data.err = xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case xsd_XsdType_xsd_boolean: {
            if (string_eq(lexical, SLOP_STR("true"))) {
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_boolean_val, .data.xsd_boolean_val = 1 }) });
            } else {
                if (string_eq(lexical, SLOP_STR("false"))) {
                    return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_boolean_val, .data.xsd_boolean_val = 0 }) });
                } else {
                    return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = false, .data.err = xsd_XsdError_invalid_lexical_form });
                }
            }
            break;
        }
        case xsd_XsdType_xsd_decimal: {
            __auto_type _mv_161 = strlib_parse_float(lexical);
            if (_mv_161.is_ok) {
                __auto_type val = _mv_161.data.ok;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_decimal_val, .data.xsd_decimal_val = val }) });
            } else if (!_mv_161.is_ok) {
                __auto_type _ = _mv_161.data.err;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = false, .data.err = xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case xsd_XsdType_xsd_float: {
            __auto_type _mv_162 = strlib_parse_float(lexical);
            if (_mv_162.is_ok) {
                __auto_type val = _mv_162.data.ok;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_float_val, .data.xsd_float_val = ((float)(val)) }) });
            } else if (!_mv_162.is_ok) {
                __auto_type _ = _mv_162.data.err;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = false, .data.err = xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case xsd_XsdType_xsd_double: {
            __auto_type _mv_163 = strlib_parse_float(lexical);
            if (_mv_163.is_ok) {
                __auto_type val = _mv_163.data.ok;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_double_val, .data.xsd_double_val = val }) });
            } else if (!_mv_163.is_ok) {
                __auto_type _ = _mv_163.data.err;
                return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = false, .data.err = xsd_XsdError_invalid_lexical_form });
            }
            SLOP_UNREACHABLE();
            break;
        }
        case xsd_XsdType_xsd_unknown: {
            return ((slop_result_xsd_XsdValue_xsd_XsdError){ .is_ok = true, .data.ok = ((xsd_XsdValue){ .tag = xsd_XsdValue_xsd_unknown_val, .data.xsd_unknown_val = lexical }) });
            break;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t xsd_validate_lexical(slop_string lexical, slop_string datatype_iri) {
    if (string_eq(datatype_iri, vocab_XSD_STRING)) {
        return 1;
    } else if (string_eq(datatype_iri, vocab_XSD_INTEGER)) {
        __auto_type _mv_164 = strlib_parse_int(lexical);
        if (_mv_164.is_ok) {
            __auto_type _ = _mv_164.data.ok;
            return 1;
        } else if (!_mv_164.is_ok) {
            __auto_type _ = _mv_164.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_BOOLEAN)) {
        return ((string_eq(lexical, SLOP_STR("true"))) || (string_eq(lexical, SLOP_STR("false"))) || (string_eq(lexical, SLOP_STR("1"))) || (string_eq(lexical, SLOP_STR("0"))));
    } else if (string_eq(datatype_iri, vocab_XSD_DECIMAL)) {
        __auto_type _mv_165 = strlib_parse_float(lexical);
        if (_mv_165.is_ok) {
            __auto_type _ = _mv_165.data.ok;
            return 1;
        } else if (!_mv_165.is_ok) {
            __auto_type _ = _mv_165.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_FLOAT)) {
        __auto_type _mv_166 = strlib_parse_float(lexical);
        if (_mv_166.is_ok) {
            __auto_type _ = _mv_166.data.ok;
            return 1;
        } else if (!_mv_166.is_ok) {
            __auto_type _ = _mv_166.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_DOUBLE)) {
        __auto_type _mv_167 = strlib_parse_float(lexical);
        if (_mv_167.is_ok) {
            __auto_type _ = _mv_167.data.ok;
            return 1;
        } else if (!_mv_167.is_ok) {
            __auto_type _ = _mv_167.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_LONG)) {
        __auto_type _mv_168 = strlib_parse_int(lexical);
        if (_mv_168.is_ok) {
            __auto_type _ = _mv_168.data.ok;
            return 1;
        } else if (!_mv_168.is_ok) {
            __auto_type _ = _mv_168.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_INT)) {
        __auto_type _mv_169 = strlib_parse_int(lexical);
        if (_mv_169.is_ok) {
            __auto_type v = _mv_169.data.ok;
            return ((v >= -2147483648) && (v <= 2147483647));
        } else if (!_mv_169.is_ok) {
            __auto_type _ = _mv_169.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_SHORT)) {
        __auto_type _mv_170 = strlib_parse_int(lexical);
        if (_mv_170.is_ok) {
            __auto_type v = _mv_170.data.ok;
            return ((v >= -32768) && (v <= 32767));
        } else if (!_mv_170.is_ok) {
            __auto_type _ = _mv_170.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_BYTE)) {
        __auto_type _mv_171 = strlib_parse_int(lexical);
        if (_mv_171.is_ok) {
            __auto_type v = _mv_171.data.ok;
            return ((v >= -128) && (v <= 127));
        } else if (!_mv_171.is_ok) {
            __auto_type _ = _mv_171.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_UNSIGNED_LONG)) {
        __auto_type _mv_172 = strlib_parse_int(lexical);
        if (_mv_172.is_ok) {
            __auto_type v = _mv_172.data.ok;
            return (v >= 0);
        } else if (!_mv_172.is_ok) {
            __auto_type _ = _mv_172.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_UNSIGNED_INT)) {
        __auto_type _mv_173 = strlib_parse_int(lexical);
        if (_mv_173.is_ok) {
            __auto_type v = _mv_173.data.ok;
            return ((v >= 0) && (v <= 4294967295));
        } else if (!_mv_173.is_ok) {
            __auto_type _ = _mv_173.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_UNSIGNED_SHORT)) {
        __auto_type _mv_174 = strlib_parse_int(lexical);
        if (_mv_174.is_ok) {
            __auto_type v = _mv_174.data.ok;
            return ((v >= 0) && (v <= 65535));
        } else if (!_mv_174.is_ok) {
            __auto_type _ = _mv_174.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_UNSIGNED_BYTE)) {
        __auto_type _mv_175 = strlib_parse_int(lexical);
        if (_mv_175.is_ok) {
            __auto_type v = _mv_175.data.ok;
            return ((v >= 0) && (v <= 255));
        } else if (!_mv_175.is_ok) {
            __auto_type _ = _mv_175.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_NON_NEGATIVE_INTEGER)) {
        __auto_type _mv_176 = strlib_parse_int(lexical);
        if (_mv_176.is_ok) {
            __auto_type v = _mv_176.data.ok;
            return (v >= 0);
        } else if (!_mv_176.is_ok) {
            __auto_type _ = _mv_176.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_POSITIVE_INTEGER)) {
        __auto_type _mv_177 = strlib_parse_int(lexical);
        if (_mv_177.is_ok) {
            __auto_type v = _mv_177.data.ok;
            return (v >= 1);
        } else if (!_mv_177.is_ok) {
            __auto_type _ = _mv_177.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_NEGATIVE_INTEGER)) {
        __auto_type _mv_178 = strlib_parse_int(lexical);
        if (_mv_178.is_ok) {
            __auto_type v = _mv_178.data.ok;
            return (v <= -1);
        } else if (!_mv_178.is_ok) {
            __auto_type _ = _mv_178.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_XSD_NON_POSITIVE_INTEGER)) {
        __auto_type _mv_179 = strlib_parse_int(lexical);
        if (_mv_179.is_ok) {
            __auto_type v = _mv_179.data.ok;
            return (v <= 0);
        } else if (!_mv_179.is_ok) {
            __auto_type _ = _mv_179.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(datatype_iri, vocab_RDF_LANG_STRING)) {
        return 1;
    } else {
        return 1;
    }
}

uint8_t xsd_values_equal(xsd_XsdValue a, xsd_XsdValue b) {
    __auto_type _mv_180 = a;
    switch (_mv_180.tag) {
        case xsd_XsdValue_xsd_string_val:
        {
            __auto_type s1 = _mv_180.data.xsd_string_val;
            __auto_type _mv_181 = b;
            switch (_mv_181.tag) {
                case xsd_XsdValue_xsd_string_val:
                {
                    __auto_type s2 = _mv_181.data.xsd_string_val;
                    return string_eq(s1, s2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_integer_val:
        {
            __auto_type i1 = _mv_180.data.xsd_integer_val;
            __auto_type _mv_182 = b;
            switch (_mv_182.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_182.data.xsd_integer_val;
                    return (i1 == i2);
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_182.data.xsd_decimal_val;
                    return (((double)(i1)) == d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_182.data.xsd_float_val;
                    return (((double)(i1)) == ((double)(f2)));
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_182.data.xsd_double_val;
                    return (((double)(i1)) == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_decimal_val:
        {
            __auto_type d1 = _mv_180.data.xsd_decimal_val;
            __auto_type _mv_183 = b;
            switch (_mv_183.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_183.data.xsd_integer_val;
                    return (d1 == ((double)(i2)));
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_183.data.xsd_decimal_val;
                    return (d1 == d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_183.data.xsd_float_val;
                    return (d1 == ((double)(f2)));
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_183.data.xsd_double_val;
                    return (d1 == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_float_val:
        {
            __auto_type f1 = _mv_180.data.xsd_float_val;
            __auto_type _mv_184 = b;
            switch (_mv_184.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_184.data.xsd_integer_val;
                    return (((double)(f1)) == ((double)(i2)));
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_184.data.xsd_decimal_val;
                    return (((double)(f1)) == d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_184.data.xsd_float_val;
                    return (f1 == f2);
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_184.data.xsd_double_val;
                    return (((double)(f1)) == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_double_val:
        {
            __auto_type d1 = _mv_180.data.xsd_double_val;
            __auto_type _mv_185 = b;
            switch (_mv_185.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_185.data.xsd_integer_val;
                    return (d1 == ((double)(i2)));
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_185.data.xsd_decimal_val;
                    return (d1 == d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_185.data.xsd_float_val;
                    return (d1 == ((double)(f2)));
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_185.data.xsd_double_val;
                    return (d1 == d2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_boolean_val:
        {
            __auto_type b1 = _mv_180.data.xsd_boolean_val;
            __auto_type _mv_186 = b;
            switch (_mv_186.tag) {
                case xsd_XsdValue_xsd_boolean_val:
                {
                    __auto_type b2 = _mv_186.data.xsd_boolean_val;
                    return (b1 == b2);
                }
                default: {
                    return 0;
                }
            }
        }
        case xsd_XsdValue_xsd_unknown_val:
        {
            __auto_type u1 = _mv_180.data.xsd_unknown_val;
            __auto_type _mv_187 = b;
            switch (_mv_187.tag) {
                case xsd_XsdValue_xsd_unknown_val:
                {
                    __auto_type u2 = _mv_187.data.xsd_unknown_val;
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

uint8_t xsd_types_compatible(xsd_XsdType t1, xsd_XsdType t2) {
    return ((t1 == t2) || ((((t1 == xsd_XsdType_xsd_integer)) || ((t1 == xsd_XsdType_xsd_decimal)) || ((t1 == xsd_XsdType_xsd_float)) || ((t1 == xsd_XsdType_xsd_double))) && (((t2 == xsd_XsdType_xsd_integer)) || ((t2 == xsd_XsdType_xsd_decimal)) || ((t2 == xsd_XsdType_xsd_float)) || ((t2 == xsd_XsdType_xsd_double)))));
}

slop_result_u8_xsd_XsdError xsd_literal_values_equal(slop_arena* arena, rdf_Literal a, rdf_Literal b) {
    __auto_type _mv_188 = a.lang;
    if (_mv_188.has_value) {
        __auto_type lang_a = _mv_188.value;
        __auto_type _mv_189 = b.lang;
        if (_mv_189.has_value) {
            __auto_type lang_b = _mv_189.value;
            if (string_eq(lang_a, lang_b)) {
                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = string_eq(a.value, b.value) });
            } else {
                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            }
        } else if (!_mv_189.has_value) {
            return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_188.has_value) {
        __auto_type _mv_190 = a.datatype;
        if (_mv_190.has_value) {
            __auto_type dt_a = _mv_190.value;
            __auto_type _mv_191 = b.datatype;
            if (_mv_191.has_value) {
                __auto_type dt_b = _mv_191.value;
                {
                    __auto_type type_a = xsd_parse_type(dt_a);
                    {
                        __auto_type type_b = xsd_parse_type(dt_b);
                        {
                            __auto_type val_a = ({ __auto_type _tmp = xsd_parse_value(arena, a.value, type_a); if (!_tmp.is_ok) return ((slop_result_u8_xsd_XsdError){ .is_ok = false, .data.err = _tmp.data.err }); _tmp.data.ok; });
                            {
                                __auto_type val_b = ({ __auto_type _tmp = xsd_parse_value(arena, b.value, type_b); if (!_tmp.is_ok) return ((slop_result_u8_xsd_XsdError){ .is_ok = false, .data.err = _tmp.data.err }); _tmp.data.ok; });
                                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = xsd_values_equal(val_a, val_b) });
                            }
                        }
                    }
                }
            } else if (!_mv_191.has_value) {
                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_190.has_value) {
            __auto_type _mv_192 = b.datatype;
            if (_mv_192.has_value) {
                __auto_type dt_b = _mv_192.value;
                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = 0 });
            } else if (!_mv_192.has_value) {
                return ((slop_result_u8_xsd_XsdError){ .is_ok = true, .data.ok = string_eq(a.value, b.value) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

xsd_XsdCompareResult xsd_float_cmp(double a, double b) {
    if (a < b) {
        return xsd_XsdCompareResult_xsd_compare_less;
    } else {
        if (a > b) {
            return xsd_XsdCompareResult_xsd_compare_greater;
        } else {
            return xsd_XsdCompareResult_xsd_compare_equal;
        }
    }
}

xsd_XsdCompareResult xsd_values_compare(xsd_XsdValue a, xsd_XsdValue b) {
    __auto_type _mv_193 = a;
    switch (_mv_193.tag) {
        case xsd_XsdValue_xsd_integer_val:
        {
            __auto_type i1 = _mv_193.data.xsd_integer_val;
            {
                __auto_type d1 = ((double)(i1));
                __auto_type _mv_194 = b;
                switch (_mv_194.tag) {
                    case xsd_XsdValue_xsd_integer_val:
                    {
                        __auto_type i2 = _mv_194.data.xsd_integer_val;
                        return xsd_float_cmp(d1, ((double)(i2)));
                    }
                    case xsd_XsdValue_xsd_decimal_val:
                    {
                        __auto_type d2 = _mv_194.data.xsd_decimal_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    case xsd_XsdValue_xsd_float_val:
                    {
                        __auto_type f2 = _mv_194.data.xsd_float_val;
                        return xsd_float_cmp(d1, ((double)(f2)));
                    }
                    case xsd_XsdValue_xsd_double_val:
                    {
                        __auto_type d2 = _mv_194.data.xsd_double_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    default: {
                        return xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
            }
        }
        case xsd_XsdValue_xsd_decimal_val:
        {
            __auto_type d1 = _mv_193.data.xsd_decimal_val;
            __auto_type _mv_195 = b;
            switch (_mv_195.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_195.data.xsd_integer_val;
                    return xsd_float_cmp(d1, ((double)(i2)));
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_195.data.xsd_decimal_val;
                    return xsd_float_cmp(d1, d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_195.data.xsd_float_val;
                    return xsd_float_cmp(d1, ((double)(f2)));
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_195.data.xsd_double_val;
                    return xsd_float_cmp(d1, d2);
                }
                default: {
                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case xsd_XsdValue_xsd_float_val:
        {
            __auto_type f1 = _mv_193.data.xsd_float_val;
            {
                __auto_type d1 = ((double)(f1));
                __auto_type _mv_196 = b;
                switch (_mv_196.tag) {
                    case xsd_XsdValue_xsd_integer_val:
                    {
                        __auto_type i2 = _mv_196.data.xsd_integer_val;
                        return xsd_float_cmp(d1, ((double)(i2)));
                    }
                    case xsd_XsdValue_xsd_decimal_val:
                    {
                        __auto_type d2 = _mv_196.data.xsd_decimal_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    case xsd_XsdValue_xsd_float_val:
                    {
                        __auto_type f2 = _mv_196.data.xsd_float_val;
                        return xsd_float_cmp(d1, ((double)(f2)));
                    }
                    case xsd_XsdValue_xsd_double_val:
                    {
                        __auto_type d2 = _mv_196.data.xsd_double_val;
                        return xsd_float_cmp(d1, d2);
                    }
                    default: {
                        return xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
            }
        }
        case xsd_XsdValue_xsd_double_val:
        {
            __auto_type d1 = _mv_193.data.xsd_double_val;
            __auto_type _mv_197 = b;
            switch (_mv_197.tag) {
                case xsd_XsdValue_xsd_integer_val:
                {
                    __auto_type i2 = _mv_197.data.xsd_integer_val;
                    return xsd_float_cmp(d1, ((double)(i2)));
                }
                case xsd_XsdValue_xsd_decimal_val:
                {
                    __auto_type d2 = _mv_197.data.xsd_decimal_val;
                    return xsd_float_cmp(d1, d2);
                }
                case xsd_XsdValue_xsd_float_val:
                {
                    __auto_type f2 = _mv_197.data.xsd_float_val;
                    return xsd_float_cmp(d1, ((double)(f2)));
                }
                case xsd_XsdValue_xsd_double_val:
                {
                    __auto_type d2 = _mv_197.data.xsd_double_val;
                    return xsd_float_cmp(d1, d2);
                }
                default: {
                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case xsd_XsdValue_xsd_string_val:
        {
            __auto_type s1 = _mv_193.data.xsd_string_val;
            __auto_type _mv_198 = b;
            switch (_mv_198.tag) {
                case xsd_XsdValue_xsd_string_val:
                {
                    __auto_type s2 = _mv_198.data.xsd_string_val;
                    if (string_eq(s1, s2)) {
                        return xsd_XsdCompareResult_xsd_compare_equal;
                    } else {
                        return xsd_XsdCompareResult_xsd_compare_incomparable;
                    }
                }
                default: {
                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case xsd_XsdValue_xsd_boolean_val:
        {
            __auto_type b1 = _mv_193.data.xsd_boolean_val;
            __auto_type _mv_199 = b;
            switch (_mv_199.tag) {
                case xsd_XsdValue_xsd_boolean_val:
                {
                    __auto_type b2 = _mv_199.data.xsd_boolean_val;
                    if (b1 == b2) {
                        return xsd_XsdCompareResult_xsd_compare_equal;
                    } else {
                        if (b2) {
                            return xsd_XsdCompareResult_xsd_compare_less;
                        } else {
                            return xsd_XsdCompareResult_xsd_compare_greater;
                        }
                    }
                }
                default: {
                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        case xsd_XsdValue_xsd_unknown_val:
        {
            __auto_type _ = _mv_193.data.xsd_unknown_val;
            return xsd_XsdCompareResult_xsd_compare_incomparable;
        }
    }
    SLOP_UNREACHABLE();
}

xsd_XsdCompareResult xsd_compare(slop_arena* arena, rdf_Term a, rdf_Term b) {
    __auto_type _mv_200 = a;
    switch (_mv_200.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type lit_a = _mv_200.data.term_literal;
            __auto_type _mv_201 = b;
            switch (_mv_201.tag) {
                case rdf_Term_term_literal:
                {
                    __auto_type lit_b = _mv_201.data.term_literal;
                    {
                        __auto_type dt_a = ({ __auto_type _mv = lit_a.datatype; _mv.has_value ? ({ __auto_type d = _mv.value; d; }) : (vocab_XSD_STRING); });
                        __auto_type dt_b = ({ __auto_type _mv = lit_b.datatype; _mv.has_value ? ({ __auto_type d = _mv.value; d; }) : (vocab_XSD_STRING); });
                        {
                            __auto_type type_a = xsd_parse_type(dt_a);
                            __auto_type type_b = xsd_parse_type(dt_b);
                            if (!(xsd_types_compatible(type_a, type_b))) {
                                return xsd_XsdCompareResult_xsd_compare_incomparable;
                            } else {
                                __auto_type _mv_202 = xsd_parse_value(arena, lit_a.value, type_a);
                                if (_mv_202.is_ok) {
                                    __auto_type val_a = _mv_202.data.ok;
                                    __auto_type _mv_203 = xsd_parse_value(arena, lit_b.value, type_b);
                                    if (_mv_203.is_ok) {
                                        __auto_type val_b = _mv_203.data.ok;
                                        return xsd_values_compare(val_a, val_b);
                                    } else if (!_mv_203.is_ok) {
                                        __auto_type _ = _mv_203.data.err;
                                        return xsd_XsdCompareResult_xsd_compare_incomparable;
                                    }
                                    SLOP_UNREACHABLE();
                                } else if (!_mv_202.is_ok) {
                                    __auto_type _ = _mv_202.data.err;
                                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                                }
                                SLOP_UNREACHABLE();
                            }
                        }
                    }
                }
                default: {
                    return xsd_XsdCompareResult_xsd_compare_incomparable;
                }
            }
        }
        default: {
            return xsd_XsdCompareResult_xsd_compare_incomparable;
        }
    }
}

