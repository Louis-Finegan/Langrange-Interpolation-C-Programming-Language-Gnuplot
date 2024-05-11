# Makefile for compiling and running the main.c program

# Compiler
CC=gcc

# Linker options
LINKER=-lm

# Directories
SRC=src
BIN=bin
DATA=data

# Source file
FILE=main.c

# Executable file
BINFILE=Interpolate

# Targets
all: $(BIN)/$(BINFILE)

# Rule for compiling the C file
$(BIN)/$(BINFILE): $(SRC)/$(FILE)
	$(CC) $^ -o $@ $(LINKER)

# Rule for running the program
run: $(BIN)/$(BINFILE)
	./$< $(DATA)/$(file)

# Rule for cleaning up
clean:
	rm -f $(BIN)/$(BINFILE)

.PHONY: all run clean
