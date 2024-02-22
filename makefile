CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LDFLAGS =
SRC_DIR = src
SOCK_DIR = $(SRC_DIR)/socket
HEADER_DIR = $(SRC_DIR)/header

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SOCK_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRC_FILES))
TARGET = server

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)
