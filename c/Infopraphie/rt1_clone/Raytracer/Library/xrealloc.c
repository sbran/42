/*
** xrealloc.c for raytracer in /home/heang_d//depots-rendus/raytracer_12/Raytracer
** 
** Made by david heang
** Login   <heang_d@epitech.net>
** 
** Started on  Sun Jun  3 19:33:44 2012 david heang
** Last update Sun Jun  3 19:36:58 2012 david heang
*/

#include	<stdlib.h>

void	*xrealloc(void *ptr, int size)
{
  void	*elem;

  elem = ptr;
  elem = realloc(ptr, size);
  if (elem == NULL)
    {
      my_putstr("Realloc of size ");
      my_put_nbr(size);
      my_putstr(".\n");
      exit(EXIT_FAILURE);
    }
  return (elem);
}
