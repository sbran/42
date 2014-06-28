/*
** progress.c for rtv1 in /home/heang_d//afs/Igraph/RT-V1
** 
** Made by david heang
** Login   <heang_d@epitech.net>
** 
** Started on  Tue Mar  6 10:49:10 2012 david heang
** Last update Sat Apr 28 10:34:29 2012 benjamin bagot
*/

#include <stdlib.h>
#include <mlx.h>
#include "my.h"
#include "rt.h"

void    *xmalloc(int size);

char    *my_nbr_to_char(int nb)
{
  char  *res;
  int   div;
  int   u;

  div = 1;
  u = 1;
  if (nb < 0)
    nb = -nb;
  while ((nb / div) >= 10)
    {
      u++;
      div *= 10;
    }
  res = xmalloc(sizeof(*res) * u);
  u = 0;
  while (div > 0)
    {
      res[u++] = ((nb / div) % 10) + '0';
      div /= 10;
    }
  res[u] = '\0';
  return (res);
}

char    *schrodinger_cat(char *text, char *nb)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = 0;
  res = xmalloc(sizeof(*res) * (my_strlen(text) + my_strlen(nb) + 2));
  while (text[i])
    {
      res[i] = text[i];
      i = i + 1;
    }
  while (nb[j])
    res[i++] = nb[j++];
  res[i] = '%';
  i = i + 1;
  res[i] = '\0';
  return (res);
}

void    aff_percent(int y, t_param *img)
{
  int   p;
  char  *number;

  p = (y * 100) / WIN_X;
  number = my_nbr_to_char(p);
  number = schrodinger_cat("Filling in progress: ", number);
  mlx_clear_window(img->mlx_ptr, img->win_ptr);
  mlx_string_put(img->mlx_ptr, img->win_ptr, WIN_X - 150, WIN_Y - 10,
                 0x00FFFFFF, number);
}
