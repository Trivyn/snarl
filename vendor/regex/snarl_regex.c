/*
 * snarl_regex.c -- see snarl_regex.h.
 */
#include "snarl_regex.h"
#include "tre_regex.h"

#include <stdlib.h>
#include <string.h>

/* A NUL-terminated heap copy of a length-delimited string, as regcomp and
 * regexec take. SLOP strings carry a length and need not be terminated. */
static char *terminated_copy(const char *s, size_t len)
{
    char *copy = malloc(len + 1);
    if (copy) {
        if (len)
            memcpy(copy, s, len);
        copy[len] = '\0';
    }
    return copy;
}

int64_t snarl_regex_match(const char *pattern, size_t pattern_len,
                          const char *input, size_t input_len)
{
    return snarl_regex_match_flags(pattern, pattern_len, input, input_len, 0);
}

int64_t snarl_regex_match_flags(const char *pattern, size_t pattern_len,
                                const char *input, size_t input_len,
                                int64_t ignore_case)
{
    char *pat = terminated_copy(pattern, pattern_len);
    char *str = terminated_copy(input, input_len);
    regex_t re;
    int rc;

    if (!pat || !str) {
        free(pat);
        free(str);
        return -REG_ESPACE;
    }
    rc = regcomp(&re, pat, REG_EXTENDED | REG_NOSUB | (ignore_case ? REG_ICASE : 0));
    free(pat);
    if (rc != REG_OK) {
        free(str);
        return -rc;
    }
    rc = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
    free(str);
    return rc == REG_OK ? 1 : 0;
}
