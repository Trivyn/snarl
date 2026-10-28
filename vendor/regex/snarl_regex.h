/*
 * snarl_regex.h -- the regex matcher behind sh:pattern.
 *
 * A portable POSIX extended regular expression matcher: musl's TRE engine,
 * vendored here so every platform (Linux, macOS, Windows with MinGW or
 * clang-cl) matches the same way and none needs a system <regex.h>.
 * src/constraints/string.slop calls it through `ffi`.
 */
#ifndef SNARL_REGEX_H
#define SNARL_REGEX_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Match `input` against the POSIX ERE `pattern`, unanchored, on Unicode
 * code points decoded from UTF-8. Both are length-delimited and need not be
 * NUL-terminated; each ends at its first NUL byte if it holds one.
 *
 * Returns 1 if the input matches, 0 if it does not, and a negative
 * -REG_* code from tre_regex.h if the pattern does not compile: -REG_EPAREN
 * for unbalanced parentheses, -REG_BADRPT for a misplaced repetition
 * operator, and so on, or -REG_ESPACE if memory runs out.
 */
int64_t snarl_regex_match(const char *pattern, size_t pattern_len,
                          const char *input, size_t input_len);

#ifdef __cplusplus
}
#endif

#endif
