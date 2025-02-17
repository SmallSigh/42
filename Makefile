# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIRS = lib/gnl lib/ft_printf lib/libft src
INC_DIRS = $(addprefix -I, $(SRC_DIRS)) -Iinc
OBJ_DIR = o_files

# Source files
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Output executable
NAME = run

# Default target
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/gnl $(OBJ_DIR)/ft_printf $(OBJ_DIR)/libft $(OBJ_DIR)/src

# Link object files to create the executable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# Compile source files into object files
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)

# Clean up everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
