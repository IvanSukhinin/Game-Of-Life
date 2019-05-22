.PHONY: all test run_test clean

CC := gcc
CFLAGS := -Wall -Werror
LIFE := ./bin/life
TEST := ./bin/test
BUILD_SRC_DIR := ./build/src
BUILD_TEST_DIR := ./build/test

all: $(LIFE)

$(LIFE): $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/gui.o $(BUILD_SRC_DIR)/life.o $(BUILD_SRC_DIR)/logic.o $(BUILD_SRC_DIR)/field.o $(BUILD_SRC_DIR)/field_print.o
	$(CC) $(CFLAGS) $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/gui.o $(BUILD_SRC_DIR)/life.o $(BUILD_SRC_DIR)/logic.o $(BUILD_SRC_DIR)/field.o $(BUILD_SRC_DIR)/field_print.o -o $(LIFE) `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/main.o: src/main.c src/const.h src/figures.h 
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_SRC_DIR)/main.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/gui.o: src/gui.c src/const.h
	$(CC) $(CFLAGS) -c src/gui.c -o $(BUILD_SRC_DIR)/gui.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/life.o: src/life.c src/const.h
	$(CC) $(CFLAGS) -c src/life.c -o $(BUILD_SRC_DIR)/life.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/logic.o: src/logic.c src/const.h
	$(CC) $(CFLAGS) -c src/logic.c -o $(BUILD_SRC_DIR)/logic.o

$(BUILD_SRC_DIR)/field.o: src/field.c src/const.h
	$(CC) $(CFLAGS) -c src/field.c -o $(BUILD_SRC_DIR)/field.o

$(BUILD_SRC_DIR)/field_print.o: src/field_print.c src/const.h
	$(CC) $(CFLAGS) -c src/field_print.c -o $(BUILD_SRC_DIR)/field_print.o `pkg-config --cflags --libs gtk+-3.0`

test: $(TEST)

$(TEST): $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/life.o $(BUILD_TEST_DIR)/logic.o $(BUILD_TEST_DIR)/field.o $(BUILD_TEST_DIR)/field_print.o
	$(CC) $(CFLAGS) $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/life.o $(BUILD_TEST_DIR)/logic.o $(BUILD_TEST_DIR)/field.o $(BUILD_TEST_DIR)/field_print.o -o $(TEST)

$(BUILD_TEST_DIR)/main.o: test/main.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o $(BUILD_TEST_DIR)/main.o 

$(BUILD_TEST_DIR)/life.o: src/life.c src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/life.c -o $(BUILD_TEST_DIR)/life.o

$(BUILD_TEST_DIR)/logic.o: src/logic.c src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/logic.c -o $(BUILD_TEST_DIR)/logic.o

$(BUILD_TEST_DIR)/field.o: src/field.c src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/field.c -o $(BUILD_TEST_DIR)/field.o

$(BUILD_TEST_DIR)/field_print.o: src/field_print.c src/const.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/field_print.c -o $(BUILD_TEST_DIR)/field_print.o

run_test: test
	$(TEST)

clean:
	rm -rf $(BUILD_TEST_DIR)/*.o $(BUILD_SRC_DIR)/*.o $(LIFE) $(TEST)
