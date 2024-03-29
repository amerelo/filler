# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/04 14:49:35 by amerelo           #+#    #+#              #
#    Updated: 2016/06/03 01:11:46 by amerelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

DIR_H = ./inc/

DIR_C = ./src/

DIR_O = ./objs/

FILE_C = main.c place.c tools.c tools2.c

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRC_O)
	@gcc -o $(NAME) $(SRC_O) -L libft/ -lft -fsanitize=address

$(SRC_O): $(SRC_C)
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC_C) -I $(DIR_H)
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean all re
