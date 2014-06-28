# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 16:57:48 by sraccah           #+#    #+#              #
#    Updated: 2014/05/04 02:37:43 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

MAKE = make
CC = gcc
RM = /bin/rm
SDIR = srcs/

SRC = $(SDIR)main.c \
		$(SDIR)ft_action.c \
		$(SDIR)ft_error.c \
		$(SDIR)ft_lib.c \
		$(SDIR)ft_term.c

OBJ = $(SRC:.c=.o)
INC = -I includes
LIB = -L /usr/lib -ltermcap
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	$(RM) -f $(OBJ)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	$(RM) -f $(OBJ) $(NAME)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all

.PHONY: all name clean fclean re