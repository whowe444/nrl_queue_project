CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2 -g -std=c99
LDFLAGS = -shared
RM = rm -f
TARGET_LIB = ../lib64/libnrlqueue.so

SRCS = node_generator.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) ${CFLAGS} -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
