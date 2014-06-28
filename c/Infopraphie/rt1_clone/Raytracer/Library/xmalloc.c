/*
** xmalloc.c for xmalloc in /home/coutar_t//test_exo/projets/RT/raytracer_12/Thibaut/my
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Mar 28 10:13:33 2012 thibaut coutard
** Last update Sun Jun  3 19:18:55 2012 david heang
*/

#include <stdlib.h>

void    *xmalloc(int size)
{
  void  *element;

  element = malloc(size);
  if (element == NULL)
    {
      my_putstr("Malloc of size ");
      my_put_nbr(size);
      my_putstr(" failed.\n");
      exit(EXIT_FAILURE);
    }
  return (element);
}
