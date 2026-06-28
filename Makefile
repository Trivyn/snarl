# Snarl — SHACL Core Validator
# Build from transpiled C sources — no SLOP toolchain required.

CC      ?= cc
SNARL_VERSION ?= 0.3.0
CFLAGS  ?= -O2 -Wall -Wno-unused-function -Wno-unused-variable \
           -Wno-return-type -Wno-pointer-sign \
           -DSLOP_ARENA_NO_CAP \
           -DSNARL_VERSION=\"$(SNARL_VERSION)\"
LDFLAGS ?=
AR      ?= ar

CSRC    = csrc/src
RUNTIME = csrc/runtime
BIN     = build
OBJ     = $(BIN)/obj

ALL_SRCS    := $(wildcard $(CSRC)/*.c)
SHARED_SRCS := $(filter-out $(CSRC)/slop_main.c $(CSRC)/slop_test_cli.c, $(ALL_SRCS))
SHARED_OBJS := $(patsubst $(CSRC)/%.c,$(OBJ)/%.o,$(SHARED_SRCS))

.PHONY: all cli lib test w3c-test bench clean release dist csrc slop-build \
       crate-vendor crate-build crate-test crate-publish

PLATFORM ?= unknown

all: cli

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(CSRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) -c $< -o $@

lib: $(BIN)/libsnarl.a

$(BIN)/libsnarl.a: $(SHARED_OBJS) | $(BIN)
	$(AR) rcs $@ $^
	@echo "  -> $@"

cli: $(BIN)
	@echo "Building snarl..."
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_main.c $(LDFLAGS) -o $(BIN)/snarl
	@echo "  -> $(BIN)/snarl"

test: $(BIN)
	@echo "Building tests..."
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_test_cli.c $(LDFLAGS) -o $(BIN)/snarl-test
	@echo "Running tests..."
	cd cli/tests && ../../$(BIN)/snarl-test

w3c-test: cli
	@echo "Running W3C SHACL conformance tests..."
	cd cli/tests && bash w3c/run-w3c-tests.sh ../../build/snarl

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
	@echo "Release binary built: $(BIN)/snarl"

slop-build:
	slop build
	@mkdir -p include
	cp build/snarl.h include/snarl.h
	@echo "  -> include/snarl.h updated"

csrc:
	./csrc/update_bootstrap.sh

crate-vendor:
	@mkdir -p rust/csrc/src rust/csrc/runtime
	cp csrc/src/*.c csrc/src/*.h rust/csrc/src/
	cp csrc/runtime/slop_runtime.h rust/csrc/runtime/

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
