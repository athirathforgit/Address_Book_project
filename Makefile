# Compiler to be used for building the project
CC = gcc

# Compiler options:
# -Wall     -> Enable all warning messages
# -Iinclude -> Search header files inside include folder
CFLAGS = -Wall -Iinclude

# List of all source files required for the project
SRC = src/main.c \
      src/operations.c \
      src/validation.c \
      src/file_handler.c

# Name of the executable file to be generated
TARGET = app

# Default target
# Compiles all source files and creates the executable
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Executes the generated application
run:
	./$(TARGET)

# Removes the generated executable file
# Used to clean the project directory
clean:
	rm -f $(TARGET)