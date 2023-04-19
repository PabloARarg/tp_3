##################################################################################################
# Copyright (c) <year>, <copyright holders>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial
# portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# SPDX-License-Identifier: MIT
##################################################################################################
# Directorios
SRC_DIR = ./src
BUILD_DIR = ./build
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj
DOC_DIR = $(BUILD_DIR)/doc
# Donde buscar los archivos
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# Para que por deferto hacer all make
.DEFAULT_GOAL := all
# Creando carpeta build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
# Creando carpeta obj
$(OBJ_DIR): $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
# Creando carpeta bin
$(BIN_DIR): $(BUILD_DIR)
	mkdir -p $(BIN_DIR)
# crea la carpeta doc
$(DOC_DIR): $(BUILD_DIR)
	mkdir -p $(DOC_DIR)
# Convertir archivos .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	gcc -c $< -o $@
# Comprobacion por terminal y compila
all: $(OBJ_FILES) $(BIN_DIR)
	echo $(SRC_FILES)
	echo $(OBJ_FILES)
	gcc -o $(BIN_DIR)/app.elf $(OBJ_FILES)

clean: $(BUILD_DIR)
	rm -r $(BUILD_DIR)

doc: $(DOC_DIR)
	doxygen
	open ./build/doc/html/index.html