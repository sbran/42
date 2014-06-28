/*
** transp.c for transp in /home/coutar_t//test_exo/projets/RT/raytracer_12/Raytracer/Sources/transparence
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Thu May 24 14:01:52 2012 thibaut coutard
** Last update Sun Jun  3 19:12:28 2012 thibaut coutard
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "rt.h"

t_k     *check_k(t_k *k2, t_k *k);
t_k     *transp(t_k *k, t_objet *obj, t_utils *v, t_param *param);
t_k     *reflexion(t_k *k, t_objet *obj, t_utils *v, t_param *param);
double          inter_sphere_bis(t_utils *utils, t_objet *obj);
double          inter_cone_bis(t_utils *utils, t_objet *obj);
double          inter_cylindre_bis(t_utils *utils, t_objet *obj);
double          inter_plan_bis(t_utils *utils, t_objet *obj);

t_k	*new_search_k(t_objet *tmp, t_utils *vect, t_k *k, t_param *param)
{
  t_k	*k2;

  k2 = malloc(sizeof(*k));
  if (tmp->type == PLAN)
    k2->k = inter_plan(*vect, tmp);
  else if (tmp->type == SPHERE)
    k2->k = inter_sphere(*vect, tmp);
  else if (tmp->type == CONE)
    k2->k = inter_cone(*vect, tmp);
  else if (tmp->type == CYLINDRE)
    k2->k = inter_cylindre(*vect, tmp);
  else
    k2->k = -1;
  k2->type = tmp->type;
  k2->color.red = tmp->color.red;
  k2->color.green = tmp->color.green;
  k2->color.blue = tmp->color.blue;
  k2->brill = tmp->brill;
  k2->transp = tmp->trans;
  k2->reflex = tmp->reflex;
  k2->nb = tmp->nb;
  if (k2->k >= 0.0)
    {
      k2 = luminosite(param->spot, k2, tmp, vect);
      k2 = shadow(param, tmp, k2, vect);
      if (k2->transp > 0.0)
	k2 = transp(k2, tmp, vect, param);
      if (k2->reflex > 0.0)
	k2 = reflexion(k2, tmp, vect, param);
    }
  k = check_k(k2, k);
  return (k);
}

t_k	*transp(t_k *k, t_objet *obj, t_utils *v, t_param *param)
{
  t_utils	t;
  t_utils	*n;
  t_objet		obj3;
  double	ind;
  t_objet	*tmp;
  t_k		*tmp_k;
  double	c1;
  double	c2;

  ind = IND_MILIEU / k->ind;
  calc_coord(k, &obj3, v);
  n = malloc(sizeof(*n));
  n = my_init_norm(obj, obj3, n);
  v->vect.v_x = v->vect.v_x / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) +\
				    pow(v->vect.v_z, 2)));
  v->vect.v_y = v->vect.v_y / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) +\
				    pow(v->vect.v_z, 2)));
  v->vect.v_z = v->vect.v_z / (sqrt(pow(v->vect.v_x, 2) + pow(v->vect.v_y, 2) +\
				    pow(v->vect.v_z, 2)));

  n->vect.n_x = n->vect.n_x / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) +\
				    pow(n->vect.n_z, 2)));
  n->vect.n_y = n->vect.n_y / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) +\
				    pow(n->vect.n_z, 2)));
  n->vect.n_z = n->vect.n_z / (sqrt(pow(n->vect.n_x, 2) + pow(n->vect.n_y, 2) +\
				    pow(n->vect.n_z, 2)));

  c1 = -(v->vect.v_x * n->vect.n_x) + (v->vect.v_y * n->vect.n_y) + (v->vect.v_z * n->vect.n_z);
  c2 = sqrt(1 - pow(ind, 2) * (1 - pow(c1, 2)));
  t.vect.v_x = (ind * v->vect.v_x) + (ind * c1 - c2) * n->vect.n_x;
  t.vect.v_y = (ind * v->vect.v_y) + (ind * c1 - c2) * n->vect.n_y;
  t.vect.v_z = (ind * v->vect.v_z) + (ind * c1 - c2) * n->vect.n_z;
  t.coord.x = obj3.coord.x;
  t.coord.y = obj3.coord.y;
  t.coord.z = obj3.coord.z;
  tmp = param->objet;
  t.spot = v->spot;
  tmp_k = malloc(sizeof(*tmp_k));
  tmp_k->k = 9999999999999.0;
  tmp_k->color.red = 0.0;
  tmp_k->color.green = 0.0;
  tmp_k->color.blue = 0.0;
  while (tmp != NULL)
    {
      trans_inv(&t, tmp, 1);
      obj_rot(&t, tmp, -1, 1);
      if (k->nb != tmp->nb)
	tmp_k = new_search_k(tmp, &t, tmp_k, param);
      obj_rot(&t, tmp, 1, 1);
      trans_nor(&t, tmp, 1);
      tmp = tmp->next;
    }
  k->color.red = k->color.red * (1 - k->transp) + tmp_k->color.red * k->transp;
  k->color.green = k->color.green * (1 - k->transp) + tmp_k->color.green
    * k->transp;
  k->color.blue = k->color.blue * (1 - k->transp) + tmp_k->color.blue
    * k->transp;
  return (k);
}
