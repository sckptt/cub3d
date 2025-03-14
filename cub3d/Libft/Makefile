# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 15:54:16 by vitakinsfat       #+#    #+#              #
#    Updated: 2025/03/09 18:50:39 by vitakinsfat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# set source files and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./include/

# set library name
NAME = libft.a

# to build the library
all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/libft.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m

# phony targets
.PHONY: all clean fclean re