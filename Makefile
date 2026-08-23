# Makefile for MAE.
# This is part of the Micha1207's CPU Architecture Emulator program (MAE)
#
# Author:  Micha1207
# Date:    Aug 21, 2026
# License: GNU GPL v3 (full license in LICENSE file)
# This program comes with NO WARRANTY; to the extent permitted by law.
CC      = gcc
CFLAGS  = -Wall -Wextra -std=gnu99 -Iinclude
LDFLAGS = 
TARGET  = mae
SRC_DIR = src
OBJ_DIR = obj
INSTALL_PATH = /usr/local/bin

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all
all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/ $(TARGET)

install:
	install -m 775 $(TARGET) $(INSTALL_PATH)
