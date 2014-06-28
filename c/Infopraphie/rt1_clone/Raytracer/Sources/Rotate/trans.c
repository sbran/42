/*
** trans.c for raytracer in /home/bagot_b//Documents/I-Graph/Raytracer/rot
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Fri Mar 23 10:01:01 2012 benjamin bagot
** Last update Fri Jun  1 15:46:58 2012 benjamin bagot
*/

#include <stdlib.h>
#include "rt.h"

void	trans_inv(t_utils *utils, t_objet *obj, int flag)
{
  t_spot *beg;

  beg = utils->spot;
  if (flag == 1 || flag == 0)
    {
      utils->coord.x = utils->coord.x - obj->coord.x;
      utils->coord.y = utils->coord.y - obj->coord.y;
      utils->coord.z = utils->coord.z - obj->coord.z;
    }
  else if (flag == 2 || flag == 0)
    while (utils->spot != NULL)
      {
	utils->spot->coord.x = utils->spot->coord.x - obj->coord.x;
	utils->spot->coord.y = utils->spot->coord.y - obj->coord.y;
	utils->spot->coord.z = utils->spot->coord.z - obj->coord.z;
	utils->spot = utils->spot->next;
      }
  else if (flag == 3)
    {
      utils->vect.n_x = utils->vect.n_x - obj->coord.x;
      utils->vect.n_y = utils->vect.n_y - obj->coord.y;
      utils->vect.n_z = utils->vect.n_z - obj->coord.z;
    }
  utils->spot = beg;
}

void	trans_nor(t_utils *utils, t_objet *obj, int flag)
{
  t_spot *beg;

  beg = utils->spot;
  if (flag == 1 || flag == 0)
    {
      utils->coord.x = utils->coord.x + obj->coord.x;
      utils->coord.y = utils->coord.y + obj->coord.y;
      utils->coord.z = utils->coord.z + obj->coord.z;
    }
  else if (flag == 2 || flag == 0)
    while (utils->spot != NULL)
      {
	utils->spot->coord.x = utils->spot->coord.x + obj->coord.x;
	utils->spot->coord.y = utils->spot->coord.y + obj->coord.y;
	utils->spot->coord.z = utils->spot->coord.z + obj->coord.z;
	utils->spot = utils->spot->next;
      }
  else if (flag == 3)
    {
      utils->vect.n_x = utils->vect.n_x + obj->coord.x;
      utils->vect.n_y = utils->vect.n_y + obj->coord.y;
      utils->vect.n_z = utils->vect.n_z + obj->coord.z;
    }
  utils->spot = beg;
}
