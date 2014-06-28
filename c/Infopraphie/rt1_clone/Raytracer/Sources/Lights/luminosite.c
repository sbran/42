/*
** luminosite.c for luminosite in /home/strohe_d//Igraph/Raytracing/Raytracer
** 
** Made by dorian stroher
** Login   <strohe_d@epitech.net>
** 
** Started on  Fri Mar 23 09:43:25 2012 dorian stroher
** Last update Sun Jun  3 21:18:28 2012 benjamin bagot
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"

void	calc_coord(t_k *k, t_objet *obj3, t_utils *utils)
{
  obj3->coord.x = (utils->coord.x + k->k * utils->vect.v_x);
  obj3->coord.y = (utils->coord.y + k->k * utils->vect.v_y);
  obj3->coord.z = (utils->coord.z + k->k * utils->vect.v_z);
}

void	get_new_color(t_k *k, double tmp, t_objet *obj, t_spot *spot)
{
  int tmpcolor;

  tmpcolor = (int) k->color.red * tmp;
  tmpcolor = tmpcolor + (obj->brill * tmp * spot->color.red);
  k->color.new_red = k->color.new_red + tmpcolor;
  tmpcolor = (int) k->color.green * tmp;
  tmpcolor = tmpcolor + (obj->brill * tmp * spot->color.green);
  k->color.new_green = k->color.new_green + tmpcolor;
  tmpcolor = (int) k->color.blue * tmp;
  tmpcolor = tmpcolor + (obj->brill * tmp * spot->color.blue);
  k->color.new_blue = k->color.new_blue + tmpcolor;
}

void	check_color(t_k *k, double a, t_utils *utils)
{
  if (a == 0)
    a = 1.0;
  k->color.red = (int)(k->color.new_red / a) + k->color.red * utils->amb;
  k->color.green = (int)(k->color.new_green / a) + k->color.green * utils->amb;
  k->color.blue = (int)(k->color.new_blue / a) + k->color.blue * utils->amb;
  if (k->color.red > 255)
    k->color.red = 255;
  if (k->color.blue > 255)
    k->color.blue = 255;
  if (k->color.green > 255)
    k->color.green = 255;
  if (k->color.red < 0)
    k->color.red = 0;
  if (k->color.blue < 0)
    k->color.blue = 0;
  if (k->color.green < 0)
    k->color.green = 0;
}

double	calc_cos(t_utils *utils, t_utils L)
{
  double num;
  double den1;
  double den2;

  num = ((utils->vect.n_x * L.vect.v_x
	  + utils->vect.n_y * L.vect.v_y + utils->vect.n_z * L.vect.v_z));
  den1 = sqrt((L.vect.v_x * L.vect.v_x)
	      + (L.vect.v_y * L.vect.v_y) + (L.vect.v_z * L.vect.v_z));
  den2 = sqrt(powf(utils->vect.n_x, 2)
	      + powf(utils->vect.n_y, 2) + powf(utils->vect.n_z, 2));
  return (num / (den1 * den2));
}

t_k	*luminosite(t_spot *spot, t_k *k, t_objet *obj, t_utils *utils)
{
  t_utils	L;
  t_objet	obj3;
  double	tmp;
  double	a;

  a = 0.0;
  init_new_color(k);
  trans_inv(utils, obj, 0);
  obj_rot(utils, obj, -1, 1);
  calc_coord(k, &obj3, utils);
  utils = my_init_norm(obj, obj3, utils);
  while (spot != NULL)
    {
      init_distance(spot, &L, obj3);
      tmp = calc_cos(utils, L);
      if (obj->texture == 1 || obj->texture == 2)
	k = texture(obj3, k, obj->texture);
      get_new_color(k, (tmp < 0.0 ? tmp = 0.0 : tmp), obj, spot);
      spot = spot->next;
      a++;
    }
  obj_rot(utils, obj, 1, 1);
  trans_nor(utils, obj, 0);
  check_color(k, a, utils);
  return (k);
}
