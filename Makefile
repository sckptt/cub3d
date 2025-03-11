# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 15:54:55 by vitakinsfat       #+#    #+#              #
#    Updated: 2025/03/11 14:01:24 by vitakinsfat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = error_handling/error_handling_utils1.c \
error_handling/error_handling_utils2.c \
error_handling/error_handling1.c \
error_handling/error_handling2.c \
utils/free_things.c \
utils/get_next_line_utils.c \
utils/get_next_line.c \
utils/parsing_utils.c \
init.c \
main.c \
parse_map.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./include/ -I $(LIBFT_DIR)/include/

# set the name
NAME = cub3D
LIBNAME = libft.a
LIBFT_DIR = Libft/

# rules
all: $(LIBFT_DIR)$(LIBNAME) $(OBJ_PATH) $(NAME)

$(LIBFT_DIR)$(LIBNAME):
	@make -C $(LIBFT_DIR)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/cub3d.h | $(OBJ_PATH)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_DIR)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean:
	@make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_PATH)
	rm -f $(NAME)
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m