CXX=clang++

SRC_DIR=./src
SRC=$(SRC_DIR)/CommandParser.cpp \
		$(SRC_DIR)/Cli.cpp

OUT_DIR=./build
LIB_OUT=$(OUT_DIR)/cli-creator.so
BIN_OUT=$(OUT_DIR)/cli-creator.o
TEST_OUT=$(OUT_DIR)/test.o

LIB_PATH=/usr/local/lib/cli-creator
BIN_PATH=/usr/local/bin/cli-creator
INCLUDE_PATH=/usr/local/include/cli-creator

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(SRC) -o $(LIB_OUT)

bin:
	$(CXX) $(LIB_PATH)/cli-creator.so $(SRC_DIR)/main.cpp -o $(BIN_OUT)
	sudo cp $(BIN_OUT) $(BIN_PATH)

test:
	make clean
	make build
	make install
	$(CXX) $(LIB_PATH)/cli-creator.so test.cpp -o $(TEST_OUT)
	$(TEST_OUT) --sum=2,3 --hello --sub=23,3 --fail

install:
	sudo mkdir -p $(LIB_PATH)
	sudo cp $(LIB_OUT) $(LIB_PATH)
	sudo mkdir -p $(INCLUDE_PATH)
	sudo cp $(SRC_DIR)/* $(INCLUDE_PATH)

uninstall:
	sudo rm -r $(LIB_PATH)
	sudo rm -r $(INCLUDE_PATH)

clean:
	rm -rf $(OUT_DIR)
