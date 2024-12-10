# Davey Getchell
# CS 7680
# 12.5.2024
# test_camera makefile

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

#Linker Flags
LDFLAGS = -lpigpio -lrt

#Source File
SRC = pir_test.c

# Executable Name
EXEC = pir_test

# Default Target
all: $(EXEC)

# Rule to build thermistor
$(EXEC): $(SRC) 
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC) $(LDFLAGS)

.PHONY: clean
# Clean up
clean:
	rm -f $(EXEC)