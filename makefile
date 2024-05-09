UTILS_DIR=./src/utils
CLASSES_DIR=./src/classes
ERRORS_DIR=./src/errors
OBJ_DIR=./obj
BIN_DIR=./bin

BUILD_OPTIONS=-Wall -lm -g
BUILD_OPTIONS_PRODUCTION=-lm

UTILS=$(wildcard $(UTILS_DIR)/*.cpp)
UTILS_OBJ=$(patsubst $(UTILS_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(UTILS))
CLASSES=$(wildcard $(CLASSES_DIR)/*.cpp)
CLASSES_OBJ=$(patsubst $(CLASSES_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CLASSES))
ERRORS=$(wildcard $(ERRORS_DIR)/*.cpp)
ERRORS_OBJ=$(patsubst $(ERRORS_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(ERRORS))

all: xor

xor: $(UTILS_OBJ) $(CLASSES_OBJ) $(ERRORS_OBJ) main.o
	g++ $(BUILD_OPTIONS) $(UTILS_OBJ) $(CLASSES_OBJ) $(ERRORS_OBJ) $(OBJ_DIR)/main.o -o $(BIN_DIR)/xor-lang

main.o: main.cpp
	g++ $(BUILD_OPTIONS) -c main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.cpp
	g++ $(BUILD_OPTIONS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLASSES_DIR)/%.cpp
	g++ $(BUILD_OPTIONS) -c $< -o $@

$(OBJ_DIR)/%.o: $(ERRORS_DIR)/%.cpp
	g++ $(BUILD_OPTIONS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(BIN_DIR)/*

