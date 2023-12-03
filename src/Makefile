INCLUDE_DIR = include
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -fPIC -Wall -Wextra -O2 -g -std=c99
LDFLAGS = -shared

OBJ_DIR = ./obj
LIB_DIR = ../lib64
TARGET_LIB = ${LIB_DIR}/libnrlqueue.so

.PHONY: all
all: $(TARGET_LIB)

_DEPS = node.h node_generator.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ = node_generator.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ): $(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_LIB): $(OBJ)
	$(CC) ${LDFLAGS} -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f  $(OBJ_DIR)/*.o *~ core $(INCLUDE_DIR)/*~
