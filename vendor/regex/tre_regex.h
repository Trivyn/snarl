/*
 * musl's include/regex.h (v1.2.5), for the vendored TRE engine only.
 *
 * snarl: musl's <features.h>/<bits/alltypes.h> are replaced by <stddef.h>,
 * and every public name is renamed to a snarl_ one, so this engine never
 * meets the system's own regcomp/regexec at link time (or regex_t, if
 * <regex.h> were ever included alongside). Include only from vendor/regex;
 * snarl calls the engine through snarl_regex.h.
 */
#ifndef SNARL_TRE_REGEX_H
#define SNARL_TRE_REGEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define regoff_t   snarl_regoff_t
#define regex_t    snarl_regex_t
#define regmatch_t snarl_regmatch_t
#define regcomp    snarl_regcomp
#define regexec    snarl_regexec
#define regfree    snarl_regfree

typedef ptrdiff_t regoff_t;

typedef struct snarl_re_pattern_buffer {
	size_t re_nsub;
	void *__opaque, *__padding[4];
	size_t __nsub2;
	char __padding2;
} regex_t;

typedef struct {
	regoff_t rm_so;
	regoff_t rm_eo;
} regmatch_t;

#define REG_EXTENDED    1
#define REG_ICASE       2
#define REG_NEWLINE     4
#define REG_NOSUB       8

#define REG_NOTBOL      1
#define REG_NOTEOL      2

#define REG_OK          0
#define REG_NOMATCH     1
#define REG_BADPAT      2
#define REG_ECOLLATE    3
#define REG_ECTYPE      4
#define REG_EESCAPE     5
#define REG_ESUBREG     6
#define REG_EBRACK      7
#define REG_EPAREN      8
#define REG_EBRACE      9
#define REG_BADBR       10
#define REG_ERANGE      11
#define REG_ESPACE      12
#define REG_BADRPT      13

#define REG_ENOSYS      -1

int regcomp(regex_t *__restrict, const char *__restrict, int);
int regexec(const regex_t *__restrict, const char *__restrict, size_t, regmatch_t *__restrict, int);
void regfree(regex_t *);

#ifdef __cplusplus
}
#endif

#endif
