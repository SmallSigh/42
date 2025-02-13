# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIRS = gnl ft_printf libft src
INC_DIRS = $(addprefix -I, $(SRC_DIRS))

# Source files
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ_FILES = $(SRC_FILES:.c=.o)

# Output executable
TARGET = my_program

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES)

# Clean up everything
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re