.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Werror

all: bin/life

bin/life: build/main.o
	$(CC) build/main.o -o bin/life

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

clean:
	rm -rf build/*.o bin/life
