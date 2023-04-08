all: cdg

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

cdg: cdg.c
	$(CC) $(CFLAGS) cdg.c -o cdg

cdg-debug: cdg.c
	$(CC) $(CFLAGS) -O0 cdg.c -o cdg-debug

clean:
	rm -f cdg cdg-debug
