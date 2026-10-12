# vendor/regex — the sh:pattern regex engine

Hand-written and vendored C, **not generated** (unlike `csrc/`). It gives
`sh:pattern` one POSIX extended regular expression engine on every platform,
so none needs a system `<regex.h>`: Windows has none, under MinGW or
clang-cl, and the glibc and macOS engines matched differently.

`src/constraints/string.slop` calls it through `ffi "snarl_regex.h"`. The
Makefile compiles it into the CLI, the tests and `libsnarl.a`;
`make crate-vendor` copies it to `rust/csrc/regex/` for the crate's `build.rs`.

This is a stopgap until SLOP's std grows a regex module.

## Files

| File | Origin |
|------|--------|
| `snarl_regex.h`, `snarl_regex.c` | snarl: `snarl_regex_match`, the one entry point |
| `regcomp.c`, `regexec.c`, `tre-mem.c`, `tre.h` | musl v1.2.5 `src/regex/` (TRE) |
| `tre_regex.h` | musl v1.2.5 `include/regex.h`, adapted |
| `COPYRIGHT` | musl v1.2.5 `COPYRIGHT` |

Upstream: <https://git.musl-libc.org/cgit/musl/tree/src/regex?h=v1.2.5>.
musl is MIT-licensed; its regex code derives from Ville Laurikari's TRE
(2-clause BSD, notice kept in each file). Both are compatible with snarl's
Apache-2.0.

## Local changes to the musl files

Each is marked with a `snarl:` comment.

- **Names.** `tre_regex.h` renames `regcomp`/`regexec`/`regfree` and
  `regex_t`/`regmatch_t`/`regoff_t` to `snarl_` names, and `tre.h` renames the
  `__tre_mem_*` internals to `snarl_tre_mem_*`, so nothing collides with the
  system's or musl's own regex at link time. `regoff_t` is `ptrdiff_t`, and
  `<features.h>`/`<bits/alltypes.h>` are replaced by `<stddef.h>`. musl's
  `hidden` visibility macro is defined empty.
- **UTF-8, not the locale.** `mbtowc` is replaced by `tre_mbtowc`, a UTF-8
  decoder in `tre.h`. Matching no longer depends on the C locale (glibc's C
  locale rejects every byte >= 0x80, so non-ASCII input never matched) and is
  on code points, as SHACL's XPath regex is. A byte that does not start
  well-formed UTF-8 decodes as itself, so nothing fails to decode.
- **32-bit characters.** `tre_char_t` and `tre_cint_t` are `int32_t` instead
  of `wchar_t`/`wint_t`, which are 16 bits on Windows and would truncate code
  points above U+FFFF. The `tre_is*`/`tre_to*` class and case helpers pass a
  code point to the C library only where `wint_t` can hold it; above that it
  is in no class and has no case mapping.
- **`ALIGN`** computes through `uintptr_t` instead of `long`, which is 32 bits
  on 64-bit Windows.
- **`CHARCLASS_NAME_MAX` and `RE_DUP_MAX`** (POSIX `<limits.h>`, missing on
  MinGW and MSVC) are defined in `tre.h` at musl's values, 14 and 255, on
  every platform.
- `regerror.c` is not vendored (snarl never formats regex errors).

Character classes (`[[:alpha:]]` and so on) still come from the C library's
`isw*` functions, so outside ASCII they follow the C locale.

To update, diff a newer musl `src/regex/` against these files and carry the
`snarl:` changes over.
