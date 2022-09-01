CXX=g++

SRC_DIR=./src
SRC=$(SRC_DIR)/CommandParser.cpp \
		$(SRC_DIR)/Cli.cpp

OUT_DIR=./build
LIB_OUT=$(OUT_DIR)/cli-creator.so
TEST_OUT=$(OUT_DIR)/test.o

LIB_PATH=/usr/local/lib/cli-creator
INCLUDE_PATH=/usr/local/include/cli-creator

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(SRC) -o $(LIB_OUT)

test:
	make clean
	make build
	make install
	$(CXX) $(LIB_PATH)/cli-creator.so $(SRC_DIR)/main.cpp -o $(TEST_OUT)
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
