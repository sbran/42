#include <stdlib.h>
#include "rt.h"
#include "init.h"

void	init_k(t_k *k)
{
  k->type = 0;
  k->nb = 0;
  k->reflex = 0.0;
  k->k = 0.0;
  k->ind = 0.0;
  k->transp = 0.0;
  k->brill = 0.0;
  init_color(&k->color);
}

void	init_vect(t_vect *vect)
{
  vect->v_x = 0.0;
  vect->v_y = 0.0;
  vect->v_z = 0.0;
  vect->n_x = 0.0;
  vect->n_y = 0.0;
  vect->n_z = 0.0;
}

void	init_utils(t_utils *utils)
{
  init_coord(&utils->coord);
  init_vect(&utils->vect);
  init_vect(&utils->norm);
  utils->spot = NULL;
}

void	init_spot(t_spot *spot)
{
  init_coord(&spot->coord);
  init_color(&spot->color);
}

void	init_objet(t_objet *obj)
{
  obj->type = 0;
  obj->nb = 0;
  init_coord(&obj->coord);
  init_rot(&obj->rot);
  init_color(&obj->color);
  obj->brill = 0.0;
  obj->trans = 0.0;
  obj->reflex = 0.0;
  obj->middle = 0.0;
  obj->size = 0.0;
  obj->p_type = 0;
  init_color(&obj->pm_color);
  init_color(&obj->ps_color);
  obj->next = NULL;
}
