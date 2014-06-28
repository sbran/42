/*
** rotate.c for raytracer in /home/bagot_b//Documents/I-Graph/Raytracer/rot
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Fri Mar 23 09:57:08 2012 benjamin bagot
** Last update Sun Jun  3 21:15:56 2012 benjamin bagot
*/

#include "rt.h"

int	obj_rot(t_utils *utils, t_objet *list, int sens, int flag)
{
  if (flag == 0)
    utils = rot_eye(utils);
  else if (flag == 1 && list->type != SPHERE)
    {
      utils = rot_pos(utils, list, sens);
      utils = rot_vector(utils, list, sens);
    }
  else if (flag == 2 && list->type != SPHERE)
    utils = norm_rotate(utils, list, sens);
  return (0);
}
