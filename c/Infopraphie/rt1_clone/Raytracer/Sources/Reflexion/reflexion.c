/*
** transp.c for transp in /home/coutar_t//test_exo/projets/RT/raytracer_12/Raytracer/Sources/transparence
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Thu May 24 14:01:52 2012 thibaut coutard
** Last update Sun Jun  3 19:14:46 2012 thibaut coutard
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "rt.h"

t_k	*reflexion(t_k *k, t_objet *obj, t_utils *v, t_param *param)
{
  t_utils	t;
  t_utils	*n;
  t_objet	obj3;
  t_objet	*tmp;
  t_k		*tmp_k;
  double	u;

  init_utils(&t);
  init_objet(&obj3);
  calc_coord(k, &obj3, v);
  n = malloc(sizeof(*n));
  init_utils(n);
  n = my_init_norm(obj, obj3, n);

  v->vect.v_x = v->vect.v_x / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) + pow(v->vect.v_z, 2)));
  v->vect.v_y = v->vect.v_y / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) + pow(v->vect.v_z, 2)));
  v->vect.v_z = v->vect.v_z / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) + pow(v->vect.v_z, 2)));

  n->vect.n_x = n->vect.n_x / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) + pow(n->vect.n_z, 2)));
  n->vect.n_y = n->vect.n_y / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) + pow(n->vect.n_z, 2)));
  n->vect.n_z = n->vect.n_z / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) + pow(n->vect.n_z, 2)));

  u = ((v->vect.v_x * n->vect.n_x) + (v->vect.v_y * n->vect.n_y) + (v->vect.v_z * n->vect.n_z));
  t.vect.v_x = v->vect.v_x - (2.0 * n->vect.n_x * u);
  t.vect.v_y = v->vect.v_y - (2.0 * n->vect.n_y * u);
  t.vect.v_z = v->vect.v_z - (2.0 * n->vect.n_z * u);
  tmp = param->objet;
  t.coord.x = obj3.coord.x;
  t.coord.y = obj3.coord.y;
  t.coord.z = obj3.coord.z;
  t.spot = v->spot;
  tmp_k = malloc(sizeof(*tmp_k));
  init_k(tmp_k);
  tmp_k->k = 999999999999.0;
  tmp_k->color.red = 0.0;
  tmp_k->color.green = 0.0;
  tmp_k->color.blue = 0.0;
  while (tmp != NULL)
    {
      trans_inv(&t, tmp, 1);
      if (k->nb != tmp->nb)
	tmp_k = new_search_k(tmp,  &t/* v */ , tmp_k, param);
      trans_nor(&t, tmp, 1);
      tmp = tmp->next;
    }
  k->color.red = k->color.red * (1.000-k->reflex) + tmp_k->color.red * k->reflex;
  k->color.green = k->color.green * (1.000-k->reflex) + tmp_k->color.green * k->reflex;
  k->color.blue = k->color.blue * (1.000-k->reflex) + tmp_k->color.blue * k->reflex;
  return (k);
}
