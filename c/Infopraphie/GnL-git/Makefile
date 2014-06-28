#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 18:05:53 by sbran             #+#    #+#              #
#    Updated: 2014/04/26 00:00:16 by sbran            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_gnl

SRC = get_next_line.c main.c

LIB = get_next_line.o main.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRC)
	make re -C libft/includes
	gcc -o $(NAME) $(LIB) -L libft/ -lft

clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
