# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:34:10 by hhedjam           #+#    #+#              #
#    Updated: 2024/06/29 20:01:24 by hhedjam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


# Compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I

## Source directory
#SRC_DIR = ./

# Source files
SRC_FILES = ./main.c \
            ./fonctions.c  \
            ./utils.c	 \
			./utils2.c		\
			./utils3.c		\
			./operation.c	\
			./operation2.c	\
			./operation3.c	\
			./operation4.c	\
			./sort_stack.c	\
			./error_check.c	\




# Concatenate all source files
SRCS 	= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

#pattern substitution ->  OBJ_DIR

OBJ 	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
#SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
#OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Object files for each executable
#CLIENT_OBJ = $(OBJ_DIR)main.o .....

CTL_DIR = ${SRC_FILES:.c=.o}

# Rule to make all
all: $(PUSH_SWAP_NAME)

# Rule to make the client executable
$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "$(MAGENTA)SUPER ALGO files MADE!$(DEF_COLOR)"

# Rules to clean
clean:
	@$(RM) -rf $(CTL_DIR)
	@echo "$(BLUE)Les bails ont ete clean !$(DEF_COLOR)"

fclean: clean
	@$(RM) -f $(PUSH_SWAP_NAME)
	rm -f $(PUSH_SWAP_NAME)
	@echo "$(CYAN)PUSH_SWAP files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for the OUSTANDING project!$(DEF_COLOR)"

# Rule to check the norm
norm:
	norminette $(SRC_FILES) $(INC_DIR)*.h

# Phony targets
.PHONY: all clean fclean re norm