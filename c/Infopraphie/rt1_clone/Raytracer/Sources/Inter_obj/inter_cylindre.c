/*
** inter_cylindre.c for raytracer in /home/coutar_t//test_exo/projets/raytracer
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Feb  1 16:33:24 2012 thibaut coutard
** Last update Sun Jun  3 17:56:07 2012 david heang
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	"rt.h"

double		inter_cylindre(t_utils utils, t_objet *obj)
{
  double	a;
  double	b;
  double	c;
  double	R;
  double	d;

  R = obj->size;
  a = pow(utils.vect.v_x, 2)			\
    + pow(utils.vect.v_y, 2);
  b = ((2 * utils.vect.v_x * utils.coord.x)	\
       + (2 * utils.vect.v_y * utils.coord.y));
  c = pow(utils.coord.x, 2)			\
    + pow(utils.coord.y, 2)			\
    - pow(R, 2);
  d = delta(a, b, c);
  return (search_res(a, b, d));
}
