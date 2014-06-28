# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/24 19:35:51 by atouzeau          #+#    #+#              #
#    Updated: 2014/04/24 19:37:03 by atouzeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  mlx.c\
		ft_get_next_line.c\
		ft_gnl_fonctions.c\


FLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

LIBFT = -I libft/includes -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all