# Snarl — SHACL Core Validator
# Build from transpiled C sources — no SLOP toolchain required.

CC      ?= cc
SNARL_VERSION ?= 0.7.1
CFLAGS  ?= -O2 -Wall -Wno-unused-function -Wno-unused-variable \
           -Wno-return-type -Wno-pointer-sign \
           -DSLOP_ARENA_NO_CAP \
           -DSNARL_VERSION=\"$(SNARL_VERSION)\"
LDFLAGS ?=
AR      ?= ar

# Executables carry .exe on Windows (MSYS2/MinGW make sees OS=Windows_NT).
# Windows' default main-thread stack is 1 MB, against 8 MB on Linux and macOS,
# and shape/path evaluation recurses deeply enough to overflow it
# (STATUS_STACK_OVERFLOW in the cycle tests), so reserve 8 MB there too.
ifeq ($(OS),Windows_NT)
EXE = .exe
LDFLAGS += -Wl,--stack,8388608
else
EXE =
endif

CSRC    = csrc/src
RUNTIME = csrc/runtime
# Hand-written, vendored C (not generated): the sh:pattern regex engine
REGEX   = vendor/regex
BIN     = build
OBJ     = $(BIN)/obj
INCLUDES = -I$(RUNTIME) -I$(CSRC) -I$(REGEX)

ALL_SRCS    := $(wildcard $(CSRC)/*.c)
REGEX_SRCS  := $(wildcard $(REGEX)/*.c)
SHARED_SRCS := $(filter-out $(CSRC)/slop_main.c $(CSRC)/slop_test_cli.c, $(ALL_SRCS)) $(REGEX_SRCS)
SHARED_OBJS := $(patsubst $(CSRC)/%.c,$(OBJ)/%.o,$(filter $(CSRC)/%,$(SHARED_SRCS))) \
               $(patsubst $(REGEX)/%.c,$(OBJ)/regex_%.o,$(REGEX_SRCS))

.PHONY: all cli lib test w3c-test bench clean release dist csrc slop-build \
       crate-vendor crate-build crate-test crate-publish

PLATFORM ?= unknown

all: cli

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(CSRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ)/regex_%.o: $(REGEX)/%.c | $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib: $(BIN)/libsnarl.a

$(BIN)/libsnarl.a: $(SHARED_OBJS) | $(BIN)
	$(AR) rcs $@ $^
	@echo "  -> $@"

cli: $(BIN)
	@echo "Building snarl..."
	$(CC) $(CFLAGS) $(INCLUDES) $(SHARED_SRCS) $(CSRC)/slop_main.c $(LDFLAGS) -o $(BIN)/snarl$(EXE)
	@echo "  -> $(BIN)/snarl$(EXE)"

test: $(BIN)
	@echo "Building tests..."
	$(CC) $(CFLAGS) $(INCLUDES) $(SHARED_SRCS) $(CSRC)/slop_test_cli.c $(LDFLAGS) -o $(BIN)/snarl-test$(EXE)
	@echo "Running tests..."
	cd cli/tests && ../../$(BIN)/snarl-test$(EXE)

w3c-test: cli
	@echo "Running W3C SHACL conformance tests..."
	cd cli/tests && bash w3c/run-w3c-tests.sh ../../$(BIN)/snarl$(EXE)

bench: cli
	@cd cli/tests && uv run benchmark_compare.py --generate 2>/dev/null; \
	uv run python benchmark_compare.py

clean:
	rm -rf $(BIN) dist

release: CFLAGS = -O3 -Wall -Wno-unused-function -Wno-unused-variable \
                  -Wno-return-type -Wno-pointer-sign -DNDEBUG \
                  -DSLOP_ARENA_NO_CAP \
                  -DSNARL_VERSION=\"$(SNARL_VERSION)\"
release: clean cli
	@echo "Release binary built: $(BIN)/snarl$(EXE)"

# slop build compiles the generated C itself; SLOP_CFLAGS lets it find
# snarl_regex.h, which the sh:pattern ffi in string.slop includes.
slop-build:
	SLOP_CFLAGS="-I$(CURDIR)/$(REGEX)" slop build
	@mkdir -p include
	cp build/snarl.h include/snarl.h
	@echo "  -> include/snarl.h updated"

csrc:
	./csrc/update_bootstrap.sh

crate-vendor:
	@mkdir -p rust/csrc/src rust/csrc/runtime
	cp csrc/src/*.c csrc/src/*.h rust/csrc/src/
	rm -f rust/csrc/src/slop_common.c rust/csrc/src/slop_common.h \
	      rust/csrc/src/slop_file.c rust/csrc/src/slop_file.h \
	      rust/csrc/src/slop_index.c rust/csrc/src/slop_index.h \
	      rust/csrc/src/slop_list.c rust/csrc/src/slop_list.h \
	      rust/csrc/src/slop_rdf.c rust/csrc/src/slop_rdf.h \
	      rust/csrc/src/slop_strlib.c rust/csrc/src/slop_strlib.h \
	      rust/csrc/src/slop_ttl.c rust/csrc/src/slop_ttl.h \
	      rust/csrc/src/slop_vocab.c rust/csrc/src/slop_vocab.h \
	      rust/csrc/src/slop_xsd.c rust/csrc/src/slop_xsd.h
	cp csrc/runtime/slop_runtime.h rust/csrc/runtime/
	@mkdir -p rust/csrc/regex
	cp $(REGEX)/*.c $(REGEX)/*.h $(REGEX)/COPYRIGHT $(REGEX)/README.md rust/csrc/regex/

crate-build: crate-vendor
	cd rust && cargo build

crate-test: crate-vendor
	cd rust && cargo test

crate-publish: crate-vendor
	cd rust && cargo publish --allow-dirty

dist:
	rm -rf dist
	mkdir -p dist/include dist/lib
	cp include/snarl.h dist/include/
	cp csrc/runtime/slop_runtime.h dist/include/
	cp $(BIN)/libsnarl.a dist/lib/
	cd dist && zip -r ../libsnarl-$(PLATFORM).zip include/ lib/
	@echo "  -> libsnarl-$(PLATFORM).zip"
