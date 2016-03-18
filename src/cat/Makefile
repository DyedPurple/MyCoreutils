CC=cc
CFLAGS=-O3 -Wall -Wextra

SRCS=cat.c
OBJS=$(SRCS:.c=.o)

gh-test-cat: $(OBJS)
	$(CC) $(CFLAGS) -o gh-test-cat $(OBJS)

.PHONY: install
install:
	make gh-test-cat
	mkdir -p ../../bin
	cp gh-test-cat ../../bin/gh-cat

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o gh-test-cat -f
