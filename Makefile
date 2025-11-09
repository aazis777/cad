# ──────────────────────────────────────────────
#  cad — a cool cat clone
#  Makefile for building cad.c
# ──────────────────────────────────────────────

# App info
APP_NAME     := cad
APP_VERSION  := 0.1.0
BUILD_DATE   := $(shell date +"%Y-%m-%d")
BUILD_TIME   := $(shell date +"%H:%M:%S")

# Compiler and flags
CC           := gcc
CFLAGS       := -O2 -Wall -Wextra -std=c99
LDFLAGS      := 
SRC          := cad.c
BIN          := $(APP_NAME)

# Embed version info
DEFS := -DAPP_NAME=\"$(APP_NAME)\" \
        -DAPP_VERSION=\"$(APP_VERSION)\" \
        -DAPP_BUILD_DATE=\"$(BUILD_DATE)\" \
        -DAPP_BUILD_TIME=\"$(BUILD_TIME)\"

# ──────────────────────────────────────────────
#  Targets
# ──────────────────────────────────────────────

all: build

build: $(SRC)
	@echo "Building $(APP_NAME) v$(APP_VERSION)..."
	$(CC) $(CFLAGS) $(DEFS) -o $(BIN) $(SRC) $(LDFLAGS)
	@echo "Done! Run './$(BIN) --version' to check."

run: build
	@echo "Running $(APP_NAME)..."
	@./$(BIN)

clean:
	@echo "Cleaning up..."
	@rm -f $(BIN)
	@echo "Cleaned."

rebuild: clean build

help:
	@echo "Usage:"
	@echo "  make build     # Build cad"
	@echo "  make run       # Build & run cad"
	@echo "  make clean     # Remove compiled binary"
	@echo "  make rebuild   # Clean & rebuild"
	@echo "  make help      # Show this help message"

.PHONY: all build run clean rebuild help
