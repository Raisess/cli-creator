CXX=clang++
NAME=$(shell basename $(CURDIR))

SRC_DIR=./src
SRC=$(SRC_DIR)/main.cpp

OUT_DIR=./build
OUT=$(OUT_DIR)/$(NAME).o

LIB_PATH=/usr/local/lib/cli-creator/cli-creator.so
BIN_PATH=/usr/local/bin
BIN=$(BIN_PATH)/$(NAME)

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(LIB_PATH) $(SRC) -o $(OUT)

install:
	if [ "$(NO_SUDO)" == "1" ]; then \
		cp $(OUT) $(BIN); \
	else \
		sudo cp $(OUT) $(BIN); \
	fi

uninstall:
	if [ "$(NO_SUDO)" == "1" ]; then \
		rm -rf $(BIN); \
	else \
		sudo rm -rf $(BIN); \
	fi

test:
	$(OUT) --hello

clean:
	rm -rf $(OUT_DIR)
