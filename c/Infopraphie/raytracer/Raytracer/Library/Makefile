##
## Makefile for Makefile in /u/epitech_2016/coutar_t/rendu/lib/my
## 
## Made by thibaut coutard
## Login   <coutar_t@epitech.net>
## 
## Started on  Mon Oct 24 09:31:26 2011 thibaut coutard
## Last update Sun Jun  3 19:40:00 2012 david heang
##

SRC	= my_find_prime_sup.c \
	my_getnbr.c \
	my_getnbr_base.c \
	my_putnbr_base.c \
	xmalloc.c \
	xrealloc.c \
	xread.c \
	xopen.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_puterror.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlcat.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c

OBJ	= $(SRC:.c=.o)

all:	$(OBJ)
	ar rc libmy.a $(OBJ)
	ranlib libmy.a

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean all