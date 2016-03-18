CC=cc
CFLAGS=-O3 -Wall -Wextra

SRCS=cat.c
OBJS=$(SRCS:.c=.o)

cat: $(OBJS)
	$(CC) $(CFLAGS) -o cat $(OBJS)

.PHONY: install
install:
	make cat
	mkdir -p ../../bin
	cp cat ../../bin/gh-cat

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o cat
