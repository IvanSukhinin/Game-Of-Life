.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Werror

all: bin/life

bin/life: build/main.o build/life.o build/field.o build/field_print.o
	$(CC) $(CFLAGS) build/main.o build/life.o build/field.o build/field_print.o -o bin/life

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/life.o: src/life.c
	$(CC) $(CFLAGS) -c src/life.c -o build/life.o

build/field.o: src/field.c
	$(CC) $(CFLAGS) -c src/field.c -o build/field.o

build/field_print.o: src/field_print.c
	$(CC) $(CFLAGS) -c src/field_print.c -o build/field_print.o


clean:
	rm -rf build/*.o bin/life
