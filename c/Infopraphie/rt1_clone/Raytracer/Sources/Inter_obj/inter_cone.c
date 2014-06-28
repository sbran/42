/*
** inter_cone.c for raytracer in /home/coutar_t//test_exo/projets/raytracer
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Feb  1 16:39:49 2012 thibaut coutard
** Last update Sun Jun  3 17:55:56 2012 david heang
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rt.h"

double		inter_cone(t_utils utils, t_objet *obj)
{
  double	a;
  double	b;
  double	c;
  double	R;
  double	d;

  R = obj->size * M_PI / 180;
  a = pow(utils.vect.v_x, 2)				\
    + pow(utils.vect.v_y, 2)				\
    - (pow(utils.vect.v_z, 2)				\
       * (pow(tan(R), 2)));
  b = (2 * utils.vect.v_x * utils.coord.x)	\
    + (2 * utils.vect.v_y * utils.coord.y)				\
    - ((2 * utils.vect.v_z * utils.coord.z) * (pow(tan(R), 2)));
  c = (pow(utils.coord.x, 2)						\
       + pow(utils.coord.y, 2)						\
       - (pow(utils.coord.z, 2) * pow(tan(R), 2)));
  d = delta(a, b, c);
  return (search_res(a, b, d));
}
