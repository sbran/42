/*
** inter_plan.c for raytracer in /home/coutar_t//test_exo/projets/raytracer
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Feb  1 10:39:43 2012 thibaut coutard
** Last update Sun Jun  3 17:56:48 2012 david heang
*/

#include	<stdlib.h>
#include	<math.h>
#include	"rt.h"

/*double		check_whatlim(double k, t_utils *utils)
{
  double	x;
  double	y;
  double	z;

  x = k * utils->vect.v_x + utils->coord.x;
  y = k * utils->vect.v_y + utils->coord.y;
  z = k * utils->vect.v_z + utils->coord.z;
  if ((pow(x, 2) + pow(y, 2)) < pow(700, 2))
    return (k);
  else
    return (-1);
}*/

double	inter_plan(t_utils utils, t_objet *obj)
{
  double	k;

  obj = obj;
  if (utils.vect.v_z == 0.0000)
    k = -1.0;
  else
    k = -(utils.coord.z / utils.vect.v_z);
  return (k);
}
