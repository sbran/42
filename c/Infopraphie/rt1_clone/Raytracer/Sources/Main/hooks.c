/*
** hooks.c for Raytracer in /home/lebuha_r//Current/Igraph/RayTracer/Re-orga/Sources
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Sat Apr 28 16:02:18 2012 riwal lebuhan
** Last update Sat Jun  2 16:23:23 2012 benjamin bagot
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	"rt.h"

int		expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
  param = param;
  return (0);
}

int		key(int bouton, t_param **param)
{
  if (bouton == 65307)
    {
      mlx_destroy_window((*param)->mlx_ptr, (*param)->win_ptr);
      free_list(*param);
      exit(0);
    }
  param = param;
  return (0);
}
