all: cache_money1

OBJS = 06-cache_money.o text_convert.o memoization.o
CC = clang
CFLAGS = -g -Wall

cache_money1: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

text_convert.o: text_convert.h

memoization.o: memoization.h

06-cache_money.o: text_convert.h memoization.h

clean:
	rm -f cache_money1 $(OBJS)