.PHONY: all test run_test clean install uninstall

CC := gcc
CFLAGS := -Wall -Werror
LIFE := ./bin/life
TEST := ./bin/test
BUILD_SRC_DIR := ./build/src
BUILD_TEST_DIR := ./build/test
INSTALL_PATH := ./usr/local/bin

all: $(LIFE)

$(LIFE): $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/gui.o $(BUILD_SRC_DIR)/life.o $(BUILD_SRC_DIR)/logic.o $(BUILD_SRC_DIR)/field.o $(BUILD_SRC_DIR)/field_print.o
	$(CC) $(CFLAGS) $(BUILD_SRC_DIR)/main.o $(BUILD_SRC_DIR)/gui.o $(BUILD_SRC_DIR)/life.o $(BUILD_SRC_DIR)/logic.o $(BUILD_SRC_DIR)/field.o $(BUILD_SRC_DIR)/field_print.o -o $(LIFE) `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/main.o: src/main.c 
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_SRC_DIR)/main.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/gui.o: src/gui.c src/gui.h src/figures.h
	$(CC) $(CFLAGS) -c src/gui.c -o $(BUILD_SRC_DIR)/gui.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/life.o: src/life.c src/life.h
	$(CC) $(CFLAGS) -c src/life.c -o $(BUILD_SRC_DIR)/life.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_SRC_DIR)/logic.o: src/logic.c src/logic.h
	$(CC) $(CFLAGS) -c src/logic.c -o $(BUILD_SRC_DIR)/logic.o

$(BUILD_SRC_DIR)/field.o: src/field.c src/field.h
	$(CC) $(CFLAGS) -c src/field.c -o $(BUILD_SRC_DIR)/field.o

$(BUILD_SRC_DIR)/field_print.o: src/field_print.c src/field_print.h
	$(CC) $(CFLAGS) -c src/field_print.c -o $(BUILD_SRC_DIR)/field_print.o `pkg-config --cflags --libs gtk+-3.0`

test: $(TEST)

$(TEST): $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/gui.o $(BUILD_TEST_DIR)/life.o $(BUILD_TEST_DIR)/logic.o $(BUILD_TEST_DIR)/field.o $(BUILD_TEST_DIR)/field_print.o
	$(CC) $(CFLAGS) $(BUILD_TEST_DIR)/main.o $(BUILD_TEST_DIR)/gui.o $(BUILD_TEST_DIR)/life.o $(BUILD_TEST_DIR)/logic.o $(BUILD_TEST_DIR)/field.o $(BUILD_TEST_DIR)/field_print.o -o $(TEST) `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_TEST_DIR)/main.o: test/main.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o $(BUILD_TEST_DIR)/main.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_TEST_DIR)/gui.o: src/gui.c src/gui.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/gui.c -o $(BUILD_TEST_DIR)/gui.o `pkg-config --cflags --libs gtk+-3.0` 

$(BUILD_TEST_DIR)/life.o: src/life.c src/life.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/life.c -o $(BUILD_TEST_DIR)/life.o `pkg-config --cflags --libs gtk+-3.0`

$(BUILD_TEST_DIR)/logic.o: src/logic.c src/logic.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/logic.c -o $(BUILD_TEST_DIR)/logic.o

$(BUILD_TEST_DIR)/field.o: src/field.c src/field.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/field.c -o $(BUILD_TEST_DIR)/field.o

$(BUILD_TEST_DIR)/field_print.o: src/field_print.c src/field_print.h
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/field_print.c -o $(BUILD_TEST_DIR)/field_print.o `pkg-config --cflags --libs gtk+-3.0`

run_test: test
	$(TEST)

clean:
	rm -rf $(BUILD_TEST_DIR)/*.o $(BUILD_SRC_DIR)/*.o $(LIFE) $(TEST)

install: 
	install bin/life $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/life
