#ifndef SLOP_rules_H
#define SLOP_rules_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_data_graph.h"
#include "slop_types.h"
#include "slop_target.h"
#include "slop_engine.h"
#include "slop_node_expr.h"

typedef struct snarl_rules_InferredTriple snarl_rules_InferredTriple;
typedef struct snarl_rules_DeferredRule snarl_rules_DeferredRule;
typedef struct snarl_rules_InferOutput snarl_rules_InferOutput;
typedef struct snarl_rules_InferResult snarl_rules_InferResult;
typedef struct snarl_rules_RuleTask snarl_rules_RuleTask;

#ifndef SLOP_LIST_SNARL_TYPES_RULEORDER_DEFINED
#define SLOP_LIST_SNARL_TYPES_RULEORDER_DEFINED
#define SLOP_LIST_SNARL_TYPES_RULEORDER_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_types_RuleOrder, slop_list_snarl_types_RuleOrder)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_RULEORDER_DEFINED
#define SLOP_OPTION_SNARL_TYPES_RULEORDER_DEFINED
SLOP_OPTION_DEFINE(snarl_types_RuleOrder, slop_option_snarl_types_RuleOrder)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

struct snarl_rules_InferredTriple {
    slop_rdf_rdf_Triple triple;
    slop_rdf_rdf_Term rule;
    slop_rdf_rdf_Term focus_node;
};
typedef struct snarl_rules_InferredTriple snarl_rules_InferredTriple;

#ifndef SLOP_OPTION_SNARL_RULES_INFERREDTRIPLE_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFERREDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferredTriple, slop_option_snarl_rules_InferredTriple)
#endif

#ifndef SLOP_LIST_SNARL_RULES_INFERREDTRIPLE_DEFINED
#define SLOP_LIST_SNARL_RULES_INFERREDTRIPLE_DEFINED
#define SLOP_LIST_SNARL_RULES_INFERREDTRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_rules_InferredTriple, slop_list_snarl_rules_InferredTriple)
#endif

struct snarl_rules_DeferredRule {
    slop_rdf_rdf_Term rule;
    slop_rdf_rdf_Term shape;
    snarl_types_RuleOrder order;
};
typedef struct snarl_rules_DeferredRule snarl_rules_DeferredRule;

#ifndef SLOP_OPTION_SNARL_RULES_DEFERREDRULE_DEFINED
#define SLOP_OPTION_SNARL_RULES_DEFERREDRULE_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_DeferredRule, slop_option_snarl_rules_DeferredRule)
#endif

#ifndef SLOP_LIST_SNARL_RULES_DEFERREDRULE_DEFINED
#define SLOP_LIST_SNARL_RULES_DEFERREDRULE_DEFINED
#define SLOP_LIST_SNARL_RULES_DEFERREDRULE_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_rules_DeferredRule, slop_list_snarl_rules_DeferredRule)
#endif

struct snarl_rules_InferOutput {
    snarl_data_graph_SnarlDataGraph graph;
    slop_list_snarl_rules_InferredTriple inferred;
    slop_list_snarl_rules_DeferredRule deferred;
};
typedef struct snarl_rules_InferOutput snarl_rules_InferOutput;

#ifndef SLOP_OPTION_SNARL_RULES_INFEROUTPUT_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFEROUTPUT_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferOutput, slop_option_snarl_rules_InferOutput)
#endif

typedef enum {
    snarl_rules_InferResult_infer_success,
    snarl_rules_InferResult_infer_error
} snarl_rules_InferResult_tag;

struct snarl_rules_InferResult {
    snarl_rules_InferResult_tag tag;
    union {
        snarl_rules_InferOutput infer_success;
        slop_string infer_error;
    } data;
};
typedef struct snarl_rules_InferResult snarl_rules_InferResult;

#ifndef SLOP_OPTION_SNARL_RULES_INFERRESULT_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFERRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferResult, slop_option_snarl_rules_InferResult)
#endif

struct snarl_rules_RuleTask {
    snarl_types_NodeShape shape;
    snarl_types_Rule rule;
    snarl_types_RuleOrder key;
};
typedef struct snarl_rules_RuleTask snarl_rules_RuleTask;

#ifndef SLOP_OPTION_SNARL_RULES_RULETASK_DEFINED
#define SLOP_OPTION_SNARL_RULES_RULETASK_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_RuleTask, slop_option_snarl_rules_RuleTask)
#endif

#ifndef SLOP_LIST_SNARL_RULES_RULETASK_DEFINED
#define SLOP_LIST_SNARL_RULES_RULETASK_DEFINED
#define SLOP_LIST_SNARL_RULES_RULETASK_IMPL_DEFINED
SLOP_LIST_DEFINE(snarl_rules_RuleTask, slop_list_snarl_rules_RuleTask)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef SLOP_RDF_RDF_TRIPLE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TRIPLE_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_BlankNode(const void* key) {
    const slop_rdf_rdf_BlankNode* _k = (const slop_rdf_rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_BlankNode(const void* a, const void* b) {
    const slop_rdf_rdf_BlankNode* _a = (const slop_rdf_rdf_BlankNode*)a;
    const slop_rdf_rdf_BlankNode* _b = (const slop_rdf_rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_Literal(const void* key) {
    const slop_rdf_rdf_Literal* _k = (const slop_rdf_rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Literal(const void* a, const void* b) {
    const slop_rdf_rdf_Literal* _a = (const slop_rdf_rdf_Literal*)a;
    const slop_rdf_rdf_Literal* _b = (const slop_rdf_rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
    ;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Term(const void* key) {
    const slop_rdf_rdf_Term* _k = (const slop_rdf_rdf_Term*)key;
    switch (_k->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_hash_slop_rdf_rdf_BlankNode(&_k->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_hash_slop_rdf_rdf_Literal(&_k->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_slop_rdf_rdf_Term(const void* a, const void* b) {
    const slop_rdf_rdf_Term* _a = (const slop_rdf_rdf_Term*)a;
    const slop_rdf_rdf_Term* _b = (const slop_rdf_rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_eq_slop_rdf_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_eq_slop_rdf_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif
#ifndef SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_BlankNode(const void* key) {
    const slop_rdf_rdf_BlankNode* _k = (const slop_rdf_rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_BlankNode(const void* a, const void* b) {
    const slop_rdf_rdf_BlankNode* _a = (const slop_rdf_rdf_BlankNode*)a;
    const slop_rdf_rdf_BlankNode* _b = (const slop_rdf_rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_Literal(const void* key) {
    const slop_rdf_rdf_Literal* _k = (const slop_rdf_rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Literal(const void* a, const void* b) {
    const slop_rdf_rdf_Literal* _a = (const slop_rdf_rdf_Literal*)a;
    const slop_rdf_rdf_Literal* _b = (const slop_rdf_rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
    ;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Term(const void* key) {
    const slop_rdf_rdf_Term* _k = (const slop_rdf_rdf_Term*)key;
    switch (_k->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_hash_slop_rdf_rdf_BlankNode(&_k->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_hash_slop_rdf_rdf_Literal(&_k->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_slop_rdf_rdf_Term(const void* a, const void* b) {
    const slop_rdf_rdf_Term* _a = (const slop_rdf_rdf_Term*)a;
    const slop_rdf_rdf_Term* _b = (const slop_rdf_rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_eq_slop_rdf_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_eq_slop_rdf_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif
#ifndef SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_BlankNode(const void* key) {
    const slop_rdf_rdf_BlankNode* _k = (const slop_rdf_rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_BlankNode(const void* a, const void* b) {
    const slop_rdf_rdf_BlankNode* _a = (const slop_rdf_rdf_BlankNode*)a;
    const slop_rdf_rdf_BlankNode* _b = (const slop_rdf_rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_Literal(const void* key) {
    const slop_rdf_rdf_Literal* _k = (const slop_rdf_rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Literal(const void* a, const void* b) {
    const slop_rdf_rdf_Literal* _a = (const slop_rdf_rdf_Literal*)a;
    const slop_rdf_rdf_Literal* _b = (const slop_rdf_rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
    ;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Term(const void* key) {
    const slop_rdf_rdf_Term* _k = (const slop_rdf_rdf_Term*)key;
    switch (_k->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_hash_slop_rdf_rdf_BlankNode(&_k->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_hash_slop_rdf_rdf_Literal(&_k->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_slop_rdf_rdf_Term(const void* a, const void* b) {
    const slop_rdf_rdf_Term* _a = (const slop_rdf_rdf_Term*)a;
    const slop_rdf_rdf_Term* _b = (const slop_rdf_rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_eq_slop_rdf_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_eq_slop_rdf_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Triple(const void* key) {
    const slop_rdf_rdf_Triple* _k = (const slop_rdf_rdf_Triple*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_slop_rdf_rdf_Term(&_k->subject); hash *= 1099511628211ULL;
    hash ^= slop_hash_slop_rdf_rdf_Term(&_k->predicate); hash *= 1099511628211ULL;
    hash ^= slop_hash_slop_rdf_rdf_Term(&_k->object); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Triple(const void* a, const void* b) {
    const slop_rdf_rdf_Triple* _a = (const slop_rdf_rdf_Triple*)a;
    const slop_rdf_rdf_Triple* _b = (const slop_rdf_rdf_Triple*)b;
    return true
        && (slop_eq_slop_rdf_rdf_Term(&_a->subject, &_b->subject))
        && (slop_eq_slop_rdf_rdf_Term(&_a->predicate, &_b->predicate))
        && (slop_eq_slop_rdf_rdf_Term(&_a->object, &_b->object))
    ;
}
#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif
#endif

uint8_t snarl_rules_order_before(snarl_types_RuleOrder a, snarl_types_RuleOrder b);
uint8_t snarl_rules_order_same(snarl_types_RuleOrder a, snarl_types_RuleOrder b);
uint8_t snarl_rules_order_in_range(snarl_types_RuleOrder key, slop_option_snarl_types_RuleOrder lo, slop_option_snarl_types_RuleOrder hi);
snarl_types_RuleOrder snarl_rules_effective_order(uint8_t shacl12, double shape_order, double rule_order);
slop_list_int snarl_rules_sorted_by_order(slop_arena* arena, slop_list_snarl_types_RuleOrder keys);
slop_list_snarl_rules_RuleTask snarl_rules_collect_rule_tasks(slop_arena* arena, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);
slop_list_snarl_rules_DeferredRule snarl_rules_collect_deferred_rules(slop_arena* arena, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);
uint8_t snarl_rules_triple_is_well_formed(slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
uint8_t snarl_rules_conforms_to_all(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_target_ClassIndex class_index, slop_rdf_rdf_Term node, slop_list_slop_rdf_rdf_Term shape_refs, snarl_engine_CycleGuard guard);
snarl_rules_InferResult snarl_infer_rules(slop_arena* arena, snarl_data_graph_SnarlDataGraph data_graph, snarl_types_ShapesGraph shapes_graph, snarl_types_ValidatorConfig config);

/* Function name aliases for C interop */
#define snarl_rules_infer_rules snarl_infer_rules

#ifndef SLOP_OPTION_SNARL_RULES_INFERREDTRIPLE_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFERREDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferredTriple, slop_option_snarl_rules_InferredTriple)
#endif

#ifndef SLOP_OPTION_SNARL_RULES_DEFERREDRULE_DEFINED
#define SLOP_OPTION_SNARL_RULES_DEFERREDRULE_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_DeferredRule, slop_option_snarl_rules_DeferredRule)
#endif

#ifndef SLOP_OPTION_SNARL_RULES_INFEROUTPUT_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFEROUTPUT_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferOutput, slop_option_snarl_rules_InferOutput)
#endif

#ifndef SLOP_OPTION_SNARL_RULES_INFERRESULT_DEFINED
#define SLOP_OPTION_SNARL_RULES_INFERRESULT_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_InferResult, slop_option_snarl_rules_InferResult)
#endif

#ifndef SLOP_OPTION_SNARL_RULES_RULETASK_DEFINED
#define SLOP_OPTION_SNARL_RULES_RULETASK_DEFINED
SLOP_OPTION_DEFINE(snarl_rules_RuleTask, slop_option_snarl_rules_RuleTask)
#endif

#ifndef SLOP_OPTION_SNARL_TYPES_RULEORDER_DEFINED
#define SLOP_OPTION_SNARL_TYPES_RULEORDER_DEFINED
SLOP_OPTION_DEFINE(snarl_types_RuleOrder, slop_option_snarl_types_RuleOrder)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif


#endif
