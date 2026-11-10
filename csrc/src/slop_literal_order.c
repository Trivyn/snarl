#include "../runtime/slop_runtime.h"
#include "slop_literal_order.h"

static const slop_string snarl_literal_order_XSD_INT_T = SLOP_STR("http://www.w3.org/2001/XMLSchema#integer");
static const slop_string snarl_literal_order_XSD_DATE_TIME_T = SLOP_STR("http://www.w3.org/2001/XMLSchema#dateTime");
static const slop_string snarl_literal_order_XSD_DATE_T = SLOP_STR("http://www.w3.org/2001/XMLSchema#date");

uint8_t snarl_literal_order_datatype_is_integer(slop_string dt);
uint8_t snarl_literal_order_datatype_is_numeric(slop_string dt);
uint8_t snarl_literal_order_datatype_is_date_time(slop_string dt);
int64_t snarl_literal_order_two_digits(slop_string s, int64_t i);
int64_t snarl_literal_order_days_in_month(int64_t year, int64_t month);
int64_t snarl_literal_order_days_from_civil(int64_t year, int64_t month, int64_t day);
snarl_literal_order_Instant snarl_literal_order_invalid_instant(void);
snarl_literal_order_Instant snarl_literal_order_parse_instant(slop_string s, uint8_t with_time);
uint8_t snarl_literal_order_lexical_form_is_valid(slop_string lexical, slop_string datatype_iri);
slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_ints(int64_t a, int64_t b);
slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_floats(double a, double b);
slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_instants(snarl_literal_order_Instant a, snarl_literal_order_Instant b);
slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_numerics(slop_string lex_a, slop_string dt_a, slop_string lex_b, slop_string dt_b);
slop_string snarl_literal_order_literal_datatype(slop_rdf_rdf_Literal lit);
slop_rdf_xsd_XsdCompareResult snarl_literal_compare(slop_arena* arena, slop_rdf_rdf_Term a, slop_rdf_rdf_Term b);

uint8_t snarl_literal_order_datatype_is_integer(slop_string dt) {
    return ((string_eq(dt, slop_rdf_vocab_XSD_INTEGER)) || (string_eq(dt, slop_rdf_vocab_XSD_LONG)) || (string_eq(dt, slop_rdf_vocab_XSD_INT)) || (string_eq(dt, slop_rdf_vocab_XSD_SHORT)) || (string_eq(dt, slop_rdf_vocab_XSD_BYTE)) || (string_eq(dt, slop_rdf_vocab_XSD_UNSIGNED_LONG)) || (string_eq(dt, slop_rdf_vocab_XSD_UNSIGNED_INT)) || (string_eq(dt, slop_rdf_vocab_XSD_UNSIGNED_SHORT)) || (string_eq(dt, slop_rdf_vocab_XSD_UNSIGNED_BYTE)) || (string_eq(dt, slop_rdf_vocab_XSD_NON_NEGATIVE_INTEGER)) || (string_eq(dt, slop_rdf_vocab_XSD_POSITIVE_INTEGER)) || (string_eq(dt, slop_rdf_vocab_XSD_NEGATIVE_INTEGER)) || (string_eq(dt, slop_rdf_vocab_XSD_NON_POSITIVE_INTEGER)));
}

uint8_t snarl_literal_order_datatype_is_numeric(slop_string dt) {
    return ((snarl_literal_order_datatype_is_integer(dt)) || (string_eq(dt, slop_rdf_vocab_XSD_DECIMAL)) || (string_eq(dt, slop_rdf_vocab_XSD_FLOAT)) || (string_eq(dt, slop_rdf_vocab_XSD_DOUBLE)));
}

uint8_t snarl_literal_order_datatype_is_date_time(slop_string dt) {
    return (string_eq(dt, slop_rdf_vocab_XSD_DATE_TIME) || string_eq(dt, slop_rdf_vocab_XSD_DATE_TIME_STAMP));
}

int64_t snarl_literal_order_two_digits(slop_string s, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    int64_t _retval = {0};
    {
        __auto_type a = std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:67:25"));
        __auto_type b = std_strlib_char_at(s, SLOP_RANGE(int64_t, (i + 1), 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:68:25"));
        if (((a >= 48)) && ((a <= 57)) && ((b >= 48)) && ((b <= 57))) {
            _retval = (((a - 48) * 10) + (b - 48));
            goto _slop_post;
        } else {
            _retval = -1;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((((_retval >= -1) && (_retval <= 99))), "(and (>= $result -1) (<= $result 99))");
    return _retval;
}

int64_t snarl_literal_order_days_in_month(int64_t year, int64_t month) {
    int64_t _retval = {0};
    if (month == 2) {
        if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0))) {
            _retval = 29;
            goto _slop_post;
        } else {
            _retval = 28;
            goto _slop_post;
        }
    } else if (((month == 4)) || ((month == 6)) || ((month == 9)) || ((month == 11))) {
        _retval = 30;
        goto _slop_post;
    } else {
        _retval = 31;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((_retval >= 28) && (_retval <= 31))), "(and (>= $result 28) (<= $result 31))");
    return _retval;
}

int64_t snarl_literal_order_days_from_civil(int64_t year, int64_t month, int64_t day) {
    SLOP_PRE((((month >= 1) && (month <= 12))), "(and (>= month 1) (<= month 12))");
    {
        __auto_type y = (((month <= 2)) ? (year - 1) : year);
        {
            __auto_type era = ((((y >= 0)) ? y : (y - 399)) / 400);
            {
                __auto_type yoe = (y - (era * 400));
                __auto_type mp = (((month > 2)) ? (month - 3) : (month + 9));
                {
                    __auto_type doy = ((((153 * mp) + 2) / 5) + (day - 1));
                    return ((((era * 146097) + ((((yoe * 365) + (yoe / 4)) - (yoe / 100)) + doy)) - 719468) + 0);
                }
            }
        }
    }
}

snarl_literal_order_Instant snarl_literal_order_invalid_instant(void) {
    snarl_literal_order_Instant _retval = {0};
    _retval = ((snarl_literal_order_Instant){.valid = 0, .seconds = 0, .fraction = 0.0, .zoned = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((!(_retval.valid)), "(not (. $result valid))");
    return _retval;
}

snarl_literal_order_Instant snarl_literal_order_parse_instant(slop_string s, uint8_t with_time) {
    {
        __auto_type len = string_len(s);
        __auto_type negative = (std_strlib_char_at(s, 0) == 45);
        int64_t i = 0;
        int64_t year = 0;
        int64_t year_digits = 0;
        double fraction = 0.0;
        double scale = 0.1;
        int64_t hour = 0;
        int64_t minute = 0;
        int64_t second = 0;
        uint8_t zoned = 0;
        int64_t offset = 0;
        uint8_t ok = 1;
        if (negative) {
            i = 1;
        }
        while (((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:130:34")) >= 48)) && ((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:130:56")) <= 57)) && ((year_digits < 9))) {
            year = ((year * 10) + (std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:131:49")) - 48));
            year_digits = (year_digits + 1);
            i = (i + 1);
        }
        if (negative) {
            year = (0 - year);
        }
        {
            __auto_type month = snarl_literal_order_two_digits(s, (i + 1));
            __auto_type day = snarl_literal_order_two_digits(s, (i + 4));
            if (((year_digits < 4)) || ((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:139:32")) != 45)) || ((std_strlib_char_at(s, SLOP_RANGE(int64_t, (i + 3), 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:140:32")) != 45)) || ((month < 1)) || ((month > 12)) || ((day < 1))) {
                ok = 0;
            }
            if (ok) {
                if (day > snarl_literal_order_days_in_month(year, month)) {
                    ok = 0;
                }
            }
            i = (i + 6);
            if (ok && with_time) {
                hour = snarl_literal_order_two_digits(s, (i + 1));
                minute = snarl_literal_order_two_digits(s, (i + 4));
                second = snarl_literal_order_two_digits(s, (i + 7));
                if (((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:152:34")) != 84)) || ((std_strlib_char_at(s, SLOP_RANGE(int64_t, (i + 3), 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:153:34")) != 58)) || ((std_strlib_char_at(s, SLOP_RANGE(int64_t, (i + 6), 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:154:34")) != 58)) || ((hour < 0)) || ((hour > 24)) || ((minute < 0)) || ((minute > 59)) || ((second < 0)) || ((second > 59))) {
                    ok = 0;
                }
                i = (i + 9);
                if (ok && (std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:160:40")) == 46)) {
                    i = (i + 1);
                    if ((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:162:37")) < 48) || (std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:162:58")) > 57)) {
                        ok = 0;
                    }
                    while ((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:163:40")) >= 48) && (std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:163:62")) <= 57)) {
                        fraction = (fraction + (scale * ((double)((std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:164:77")) - 48)))));
                        scale = (scale / 10.0);
                        i = (i + 1);
                    }
                }
                if ((hour == 24) && (((minute != 0)) || ((second != 0)) || ((fraction > 0.0)))) {
                    ok = 0;
                }
            }
            if (ok && (i < len)) {
                {
                    __auto_type c = std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:171:31"));
                    if (c == 90) {
                        zoned = 1;
                        i = (i + 1);
                    } else if ((c == 43) || (c == 45)) {
                        {
                            __auto_type oh = snarl_literal_order_two_digits(s, (i + 1));
                            __auto_type om = snarl_literal_order_two_digits(s, (i + 4));
                            if (((std_strlib_char_at(s, SLOP_RANGE(int64_t, (i + 3), 1, 0, 0, 0, "(Int 0 ..) at literal-order.slop:180:42")) != 58)) || ((oh < 0)) || ((oh > 14)) || ((om < 0)) || ((om > 59)) || (((oh == 14) && (om != 0)))) {
                                ok = 0;
                            }
                            zoned = 1;
                            offset = (((oh * 3600) + (om * 60)) * (((c == 45)) ? -1 : 1));
                            i = (i + 6);
                        }
                    } else {
                        ok = 0;
                    }
                }
            }
            if (i != len) {
                ok = 0;
            }
            if (ok) {
                return ((snarl_literal_order_Instant){.valid = 1, .seconds = (((snarl_literal_order_days_from_civil(year, month, day) * 86400) + ((hour * 3600) + ((minute * 60) + second))) - offset), .fraction = fraction, .zoned = zoned});
            } else {
                return snarl_literal_order_invalid_instant();
            }
        }
    }
}

uint8_t snarl_literal_order_lexical_form_is_valid(slop_string lexical, slop_string datatype_iri) {
    if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DATE_TIME)) {
        return snarl_literal_order_parse_instant(lexical, 1).valid;
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DATE_TIME_STAMP)) {
        {
            __auto_type t = snarl_literal_order_parse_instant(lexical, 1);
            return (t.valid && t.zoned);
        }
    } else if (string_eq(datatype_iri, slop_rdf_vocab_XSD_DATE)) {
        return snarl_literal_order_parse_instant(lexical, 0).valid;
    } else {
        return xsd_validate_lexical(lexical, datatype_iri);
    }
}

slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_ints(int64_t a, int64_t b) {
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

slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_floats(double a, double b) {
    if (a < b) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_less;
    } else if (a > b) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_greater;
    } else if (a == b) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_equal;
    } else {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
    }
}

slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_instants(snarl_literal_order_Instant a, snarl_literal_order_Instant b) {
    if (!(a.valid) || !(b.valid)) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
    } else if (a.zoned == b.zoned) {
        if (a.seconds == b.seconds) {
            return snarl_literal_order_order_floats(a.fraction, b.fraction);
        } else {
            return snarl_literal_order_order_ints(a.seconds, b.seconds);
        }
    } else if ((a.seconds + 50400) < b.seconds) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_less;
    } else if ((a.seconds - 50400) > b.seconds) {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_greater;
    } else {
        return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
    }
}

slop_rdf_xsd_XsdCompareResult snarl_literal_order_order_numerics(slop_string lex_a, slop_string dt_a, slop_string lex_b, slop_string dt_b) {
    if (snarl_literal_order_datatype_is_integer(dt_a) && snarl_literal_order_datatype_is_integer(dt_b)) {
        __auto_type _mv_244 = std_strlib_parse_int(lex_a);
        if (_mv_244.is_ok) {
            __auto_type a = _mv_244.data.ok;
            __auto_type _mv_245 = std_strlib_parse_int(lex_b);
            if (_mv_245.is_ok) {
                __auto_type b = _mv_245.data.ok;
                return snarl_literal_order_order_ints(a, b);
            } else if (!_mv_245.is_ok) {
                __auto_type _ = _mv_245.data.err;
                return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_244.is_ok) {
            __auto_type _ = _mv_244.data.err;
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
        }
        SLOP_UNREACHABLE();
    } else {
        __auto_type _mv_246 = std_strlib_parse_float(lex_a);
        if (_mv_246.is_ok) {
            __auto_type a = _mv_246.data.ok;
            __auto_type _mv_247 = std_strlib_parse_float(lex_b);
            if (_mv_247.is_ok) {
                __auto_type b = _mv_247.data.ok;
                return snarl_literal_order_order_floats(a, b);
            } else if (!_mv_247.is_ok) {
                __auto_type _ = _mv_247.data.err;
                return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_246.is_ok) {
            __auto_type _ = _mv_246.data.err;
            return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
        }
        SLOP_UNREACHABLE();
    }
}

slop_string snarl_literal_order_literal_datatype(slop_rdf_rdf_Literal lit) {
    __auto_type _mv_248 = lit.lang;
    if (_mv_248.has_value) {
        __auto_type _ = _mv_248.value;
        return SLOP_STR("");
    } else if (!_mv_248.has_value) {
        __auto_type _mv_249 = lit.datatype;
        if (_mv_249.has_value) {
            __auto_type d = _mv_249.value;
            return d;
        } else if (!_mv_249.has_value) {
            return slop_rdf_vocab_XSD_STRING;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_rdf_xsd_XsdCompareResult snarl_literal_compare(slop_arena* arena, slop_rdf_rdf_Term a, slop_rdf_rdf_Term b) {
    __auto_type _mv_250 = a;
    switch (_mv_250.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type lit_a = _mv_250.data.term_literal;
            __auto_type _mv_251 = b;
            switch (_mv_251.tag) {
                case slop_rdf_rdf_Term_term_literal:
                {
                    __auto_type lit_b = _mv_251.data.term_literal;
                    {
                        __auto_type dt_a = snarl_literal_order_literal_datatype(lit_a);
                        __auto_type dt_b = snarl_literal_order_literal_datatype(lit_b);
                        __auto_type lex_a = lit_a.value;
                        __auto_type lex_b = lit_b.value;
                        if ((string_len(dt_a) == 0) || (string_len(dt_b) == 0)) {
                            return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                        } else if (snarl_literal_order_datatype_is_numeric(dt_a) && snarl_literal_order_datatype_is_numeric(dt_b)) {
                            if (snarl_literal_order_lexical_form_is_valid(lex_a, dt_a) && snarl_literal_order_lexical_form_is_valid(lex_b, dt_b)) {
                                return snarl_literal_order_order_numerics(lex_a, dt_a, lex_b, dt_b);
                            } else {
                                return slop_rdf_xsd_XsdCompareResult_xsd_compare_incomparable;
                            }
                        } else if (snarl_literal_order_datatype_is_date_time(dt_a) && snarl_literal_order_datatype_is_date_time(dt_b)) {
                            return snarl_literal_order_order_instants(snarl_literal_order_parse_instant(lex_a, 1), snarl_literal_order_parse_instant(lex_b, 1));
                        } else if (string_eq(dt_a, slop_rdf_vocab_XSD_DATE) && string_eq(dt_b, slop_rdf_vocab_XSD_DATE)) {
                            return snarl_literal_order_order_instants(snarl_literal_order_parse_instant(lex_a, 0), snarl_literal_order_parse_instant(lex_b, 0));
                        } else if (string_eq(dt_a, slop_rdf_vocab_XSD_STRING) && string_eq(dt_b, slop_rdf_vocab_XSD_STRING)) {
                            return snarl_literal_order_order_ints(std_strlib_compare(lex_a, lex_b), 0);
                        } else {
                            return xsd_compare(arena, a, b);
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

