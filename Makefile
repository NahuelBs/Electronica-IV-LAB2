SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./build/obj
BIN_DIR = ./build/bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o,$(SRC_FILES))

all: $(OBJ_FILES)
	gcc -o $(BIN_DIR)/a.out $(OBJ_FILES)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ -I $(INC_DIR)