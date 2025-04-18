# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 15:54:55 by vitakinsfat       #+#    #+#              #
#    Updated: 2025/03/27 16:10:37 by vitakinsfat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX42 = MLX42/build/libmlx42.a -I include -ldl -L/opt/homebrew/lib -lglfw -pthread -lm

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = error_handling/error_handling_utils1.c \
error_handling/error_handling1.c \
error_handling/error_handling2.c \
error_handling/error_handling3.c \
graphic/start_graphic.c \
graphic/graphic_utils.c \
graphic/move.c \
graphic/turn.c \
maths/maths_utils.c \
maths/maths1.c \
utils/free_things.c \
utils/get_next_line_utils.c \
utils/get_next_line.c \
utils/move_utils.c \
parsing/fill_the_structs.c \
parsing/fill_utils.c \
parsing/parse_map.c \
parsing/parsing_utils.c \
init.c \
main.c
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(LIBMLX_FLAG) $(MLX42)
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_DIR)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean:
	@make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_PATH)
	rm -f $(NAME) libmlx.a
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m