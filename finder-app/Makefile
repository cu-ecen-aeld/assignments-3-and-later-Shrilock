# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra -Werror -std=gnu99

# Target binary and source files
TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean

# Default target to build the application
all: $(TARGET)

# Build the application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(TARGET) $(OBJ)
