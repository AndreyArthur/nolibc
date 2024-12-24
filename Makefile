CC=gcc
CFLAGS=-g -std=gnu11 -nostdlib -fno-stack-protector -Werror=vla -Wall -Wextra -Wpedantic -Wno-builtin-declaration-mismatch -DNOSTDLIB_MMAP_TRACKER
OFLAGS=

LIB_DIR=lib
TESTS_DIR=tests
OBJECTS_DIR=objects
BIN_DIR=bin

LIB_SOURCES=$(wildcard $(LIB_DIR)/*.c)
LIB_OBJECTS=$(patsubst $(LIB_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(LIB_SOURCES))

TESTS_SOURCES=$(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJECTS=$(patsubst $(TESTS_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(TESTS_SOURCES))
TESTS_BINS=$(patsubst $(TESTS_DIR)/%.c, $(OBJECTS_DIR)/%, $(TESTS_SOURCES))

runtest: $(TESTS_BINS)
	./$(BIN_DIR)/str_test
	./$(BIN_DIR)/mem_test
	./$(BIN_DIR)/def_test
	./$(BIN_DIR)/bool_test
	./$(BIN_DIR)/int_test
	./$(BIN_DIR)/heap_test

test: $(TESTS_BINS)

clean:
	rm -rf $(BIN_DIR) $(OBJECTS_DIR)

$(LIB_OBJECTS): $(OBJECTS_DIR) $(LIB_SOURCES)
	$(CC) $(CFLAGS) -c $(LIB_DIR)/sys.c -o $(OBJECTS_DIR)/sys.o
	$(CC) $(CFLAGS) -c $(LIB_DIR)/str.c -o $(OBJECTS_DIR)/str.o
	$(CC) $(CFLAGS) -c $(LIB_DIR)/exc.c -o $(OBJECTS_DIR)/exc.o
	$(CC) $(CFLAGS) -c $(LIB_DIR)/io.c -o $(OBJECTS_DIR)/io.o
	$(CC) $(CFLAGS) -c $(LIB_DIR)/mem.c -o $(OBJECTS_DIR)/mem.o
	$(CC) $(CFLAGS) -c $(LIB_DIR)/heap.c -o $(OBJECTS_DIR)/heap.o

$(TESTS_OBJECTS): $(OBJECTS_DIR) $(TESTS_SOURCES)
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/str_test.c -o $(OBJECTS_DIR)/str_test.o
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/mem_test.c -o $(OBJECTS_DIR)/mem_test.o
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/def_test.c -o $(OBJECTS_DIR)/def_test.o
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/bool_test.c -o $(OBJECTS_DIR)/bool_test.o
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/int_test.c -o $(OBJECTS_DIR)/int_test.o
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/heap_test.c -o $(OBJECTS_DIR)/heap_test.o

$(TESTS_BINS): $(BIN_DIR) $(TESTS_OBJECTS) $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/str_test $(OBJECTS_DIR)/str_test.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mem_test $(OBJECTS_DIR)/mem_test.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/def_test $(OBJECTS_DIR)/def_test.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/bool_test $(OBJECTS_DIR)/bool_test.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/int_test $(OBJECTS_DIR)/int_test.o $(LIB_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/heap_test $(OBJECTS_DIR)/heap_test.o $(LIB_OBJECTS)

$(OBJECTS_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@
