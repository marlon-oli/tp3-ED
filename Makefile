# Makefile for C project

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =
SRC_DIR = tads
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/my_program
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
SRC_FILES += main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.PHONY: all clean run

all: $(TARGET) run

$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: $(TARGET)
	./bin/my_program

clean:
	rm -f $(TARGET) $(OBJ_FILES)

# Default target: compile, run, and clean
default: all run clean

