# Davey Getchell
# CS 7680
# 12.5.2024
# game_camera makefile

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

#Linker Flags
LDFLAGS = -lpigpio -lrt

# Directories
SRC_DIR = ./src
CONTROLLER_DIR = $(SRC_DIR)/controller
MODEL_DIR = $(SRC_DIR)/model
VIEW_DIR = $(SRC_DIR)/view
SYSTEM_DIR = $(SRC_DIR)/system

# Source Files
SRC = ./main.c \
	  $(CONTROLLER_DIR)/controller.c \
	  $(MODEL_DIR)/camera.c \
	  $(MODEL_DIR)/led.c \
	  $(MODEL_DIR)/sensor.c \
	  $(MODEL_DIR)/photocell.c \
	  $(VIEW_DIR)/display.c \
	  $(SYSTEM_DIR)/system.c

# Object Files
OBJ = $(SRC:.c=.o)

# Executable Name
EXEC = game_camera

# Default Target
all: $(EXEC)

# Rule to build game camera
$(EXEC): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
# Clean up
clean:
	rm -f $(EXEC) $(OBJ)