# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 16:57:48 by sraccah           #+#    #+#              #
#    Updated: 2013/12/11 16:57:53 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c ft_lib.c ft_lib2.c ft_lib3.c

OBJ = $(SRC:.c=.o)

MAKE = make

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) -I libft/includes/ $(CFLAGS) -c $(SRC)
	@echo "\033[31;1m"
	@echo -n '---> Binarie Creation... <---'
	@echo "\033[0m"
	$(CC) -o $(NAME) $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	@/bin/rm -f $(OBJ)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	@/bin/rm -f $(OBJ) $(NAME)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all