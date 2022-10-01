CXX=clang++

SRC_DIR=./src
SRC=$(SRC_DIR)/main.cpp

OUT_DIR=./build
OUT=$(OUT_DIR)/$(shell basename $(CURDIR)).o

LIB_PATH=/usr/local/lib/cli-creator/cli-creator.so
BIN_PATH=/usr/local/bin
BIN=$(BIN_PATH)/$(shell basename $(CURDIR))

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(LIB_PATH) $(SRC) -o $(OUT)

install:
	sudo cp $(OUT) $(BIN)

uninstall:
	sudo rm -rf $(BIN)

test:
	$(OUT) --hello

clean:
	rm -rf $(OUT_DIR)
