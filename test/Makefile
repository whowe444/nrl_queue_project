INCLUDE_DIR = include
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I../src/include/
CC = gcc
CFLAGS = $(INCLUDE_DIRS) -fPIC -Wall -Wextra -O2 -g -std=c99
LIBRARY_PATH = ${TOP_LEVEL_DIR}/lib64/

OBJ_DIR = ./obj
LIB_DIR = ../lib64
BIN_DIR  = ../bin
TARGET_BIN = ${BIN_DIR}/test_node_generator_main

LIBS = -lnrlqueue

.PHONY: all
all: $(TARGET_BIN)

_DEPS = test_node_generator.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ = test_node_generator.o test_node_generator_main.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ): $(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -L$(LIBRARY_PATH) $(LIBS)

.PHONY: clean
clean:
	rm -f  $(OBJ_DIR)/*.o *~ core $(INCLUDE_DIR)/*~
