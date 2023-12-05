INCLUDE_DIR = include
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I../src/include/
CC = gcc
CFLAGS = $(INCLUDE_DIRS) -fPIC -Wall -Wextra -O2 -g -std=c99
LIBRARY_PATH = ${TOP_LEVEL_DIR}/lib64/
LDFLAGS = -Wl,-rpath,${LIBRARY_PATH}

OBJ_DIR = ./obj
LIB_DIR = ../lib64
BIN_DIR  = ../bin
TARGET_BIN1 = ${BIN_DIR}/test_node_generator_main
TARGET_BIN2 = ${BIN_DIR}/test_queue_main
TARGET_BIN3 = ${BIN_DIR}/nrl_test_main

LIBS = -lnrlqueue

.PHONY: all
all: $(TARGET_BIN1) $(TARGET_BIN2) $(TARGET_BIN3)

_DEPS = test_node_generator.h test_queue.h random_str_gen.h nrl_test_bench.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ1 = test_node_generator.o test_node_generator_main.o
OBJ1 = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ1))

$(OBJ1): $(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_BIN1): $(OBJ1)
	$(CC) ${LDFLAGS} -o $@ $^ $(CFLAGS) -L$(LIBRARY_PATH) $(LIBS)

_OBJ2 = test_queue.o test_queue_main.o random_str_gen.o
OBJ2 = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ2))

$(OBJ2): $(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_BIN2): $(OBJ2)
	$(CC) ${LDFLAGS} -o $@ $^ $(CFLAGS) -L$(LIBRARY_PATH) $(LIBS)

_OBJ3 = nrl_test_bench.o nrl_test_main.o
OBJ3 = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ3))

$(OBJ3): $(OBJ_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_BIN3): $(OBJ3)
	$(CC) ${LDFLAGS} -o $@ $^ $(CFLAGS) -L$(LIBRARY_PATH) $(LIBS)

.PHONY: clean
clean:
	rm -f  $(OBJ_DIR)/*.o *~ core $(INCLUDE_DIR)/*~
