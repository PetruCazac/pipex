# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 08:56:05 by pcazac            #+#    #+#              #
#    Updated: 2023/06/21 11:13:11 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC := ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
	ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
	ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
	ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
	ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
	ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
	ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
	ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
	ft_printf.c ft_printf_utils.c ft_strcmp.c\
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	get_next_line.c get_next_line_utils.c ft_dlstadd_back.c \
	ft_dlstclear.c ft_dlstdelone.c ft_dlstnew.c \

VPATH := src/ ; obj/

OBJ_PATH := obj
OBJ := $(SRC:%.c=$(OBJ_PATH)/%.o)

CC := cc
CFLAGS := -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "---Making the library---"
	@ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	

clean:
	@echo "---Cleaning the books---"
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@echo "---Dusting the library---"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
