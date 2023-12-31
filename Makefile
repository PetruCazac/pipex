# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 10:54:02 by pcazac            #+#    #+#              #
#    Updated: 2023/07/06 11:59:43 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = libft/libft.a

VPATH = src/ ; obj/ ; src_bonus/ ;
LIB_PATH = -Llibft
LIBRARY = -lft
OBJ_PATH = obj

SRC = pipex.c init_check.c parse_args.c error_mngr.c pipex_utils.c
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

CC= cc
CFLAGS= -g -Wall -Wextra -Werror

all: $(NAME) $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	@echo "----I am working here----"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY)

$(LIBFT):
	@echo "---Calling the library---"
	make -C $(@D) fclean
	make -C $(@D) all

$(OBJ_PATH)/%.o : %.c
	@echo "---Santa's making objects---"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "---Cleaning this mess---"
	@/bin/rm -rf $(OBJ_PATH)
	$(MAKE) -C ./libft/ clean

fclean: clean
	@echo "---Making a deep clean---"
	@/bin/rm -f $(NAME) 
	$(MAKE) -C ./libft/ fclean
	
re: fclean all 

memory:
	@echo "---Is this supposed to leak?---"
	@$(CC) $(LIB_PATH) $(LIBRARY) $(CMLAGS) $(OBJ)

.PHONY: all clean fclean re memory
