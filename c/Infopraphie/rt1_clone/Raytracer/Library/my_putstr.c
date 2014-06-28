/*
** my_putstr.c for my_putstr in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Thu Oct  6 10:44:24 2011 thibaut coutard
** Last update Sat Jan 21 09:16:23 2012 thibaut coutard
*/

#include <stdlib.h>

void	my_putstr(char *str)
{
  while (*str != '\0' && str != NULL)
    {
      my_putchar(*str);
      str = str + 1;
    }
}
