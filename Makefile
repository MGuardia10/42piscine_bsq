################################################################################
# COMPILER OPTIONS
################################################################################

NAME		=	bsq
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INC			=	-I inc
RM			=	rm -rf

# COLORS
RED		=		\033[91;1m
GREEN	=		\033[92;1m
YELLOW	=		\033[93;1m
BLUE	=		\033[94;1m
PINK	=		\033[95;1m
CLEAR	=		\033[0m

################################################################################
# SOURCE FILES
################################################################################

# VPATH
VPATH		=	src:src/algorithm:src/parsing:src/utils

# SOURCE
SRC			=	main.c

# PARSING
PARSING			=	validate.c \
				validate_stdin.c

# ALGORITHM
ALGORITHM	=	binary_matrix.c \
				find_square.c \
				initial_matrix.c \
        		numeric_matrix.c

# UTILS
UTILS		=	free_matrix.c \
				ftlib.c

# OBJECTS
OBJ_DIR		=	objs/
OBJ_FILES	=	$(SRC:%.c=$(OBJ_DIR)%.o) \
				$(PARSING:%.c=$(OBJ_DIR)%.o) \
				$(ALGORITHM:%.c=$(OBJ_DIR)%.o) \
				$(UTILS:%.c=$(OBJ_DIR)%.o)

################################################################################
# MAKEFILE RULES
################################################################################

all:	$(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)Compiling bsq program.$(CLEAR)"
	$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[bsq --> OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Object files removed correctly$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Removing binary files.$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Object files and binary removed correctly$(CLEAR)"

re: fclean all

.PHONY:	all clean fclean re