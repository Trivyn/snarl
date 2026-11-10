#ifndef SLOP_literal_order_H
#define SLOP_literal_order_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_strlib.h"
#include "slop_vocab.h"
#include "slop_xsd.h"

typedef struct snarl_literal_order_Instant snarl_literal_order_Instant;

struct snarl_literal_order_Instant {
    uint8_t valid;
    int64_t seconds;
    double fraction;
    uint8_t zoned;
};
typedef struct snarl_literal_order_Instant snarl_literal_order_Instant;

#ifndef SLOP_OPTION_SNARL_LITERAL_ORDER_INSTANT_DEFINED
#define SLOP_OPTION_SNARL_LITERAL_ORDER_INSTANT_DEFINED
SLOP_OPTION_DEFINE(snarl_literal_order_Instant, slop_option_snarl_literal_order_Instant)
#endif

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

/* Function name aliases for C interop */
#define snarl_literal_order_literal_compare snarl_literal_compare

#ifndef SLOP_OPTION_SNARL_LITERAL_ORDER_INSTANT_DEFINED
#define SLOP_OPTION_SNARL_LITERAL_ORDER_INSTANT_DEFINED
SLOP_OPTION_DEFINE(snarl_literal_order_Instant, slop_option_snarl_literal_order_Instant)
#endif


#endif
