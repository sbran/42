# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/29 13:27:59 by sbran             #+#    #+#              #
#    Updated: 2014/06/29 13:28:54 by sbran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

SRC = grimly.c\
	ft_lib.c\
	ft_labyrinthe.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all