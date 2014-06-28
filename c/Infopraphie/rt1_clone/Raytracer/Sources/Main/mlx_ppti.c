/*
** mlx_ppti.c for mlx_ppti in /home/coutar_t//test_exo/projets/fdf
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Thu Dec  1 23:14:39 2011 thibaut coutard
** Last update Sun Jun  3 18:48:07 2012 riwal lebuhan
*/

#include <mlx.h>
#include "rt.h"

void		mlx_ppti(int x, int y, t_param *param, t_k *k)
{
  t_ppti	ppti;
  short		color;

  color = (k->color.blue + k->color.green + k->color.red) / 3;
  if (BW_FILTER == 1)
    {
      k->color.blue = color;
      k->color.green = color;
      k->color.red = color;
    }
  if (SEPIA_FILTER == 1)
    {
      k->color.blue = color / 2 + 15;
      k->color.green = color / 2 + 90;
      k->color.red = color / 2 + 127;
    }
  ppti.data = mlx_get_data_addr(param->img, &(ppti.bpp),
				&(ppti.sizeline), &(ppti.endian));
  ppti.data[(y * ppti.sizeline) + (x * (ppti.bpp / 8))] = k->color.blue;
  ppti.data[(y * ppti.sizeline) + (x * (ppti.bpp / 8)) + 1] = k->color.green;
  ppti.data[(y * ppti.sizeline) + (x * (ppti.bpp / 8)) + 2] = k->color.red;
}
