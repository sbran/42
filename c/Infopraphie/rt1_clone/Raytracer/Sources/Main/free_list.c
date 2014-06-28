/*
** free_list.c for raytracer in /home/bagot_b//raytracer_12/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Sat Jun  2 16:14:43 2012 benjamin bagot
** Last update Sat Jun  2 16:26:04 2012 benjamin bagot
*/

#include <stdlib.h>
#include "rt.h"

void	free_list(t_param *param)
{
  t_objet	*tmp;
  t_spot	*spot;

  tmp = param->objet;
  spot = param->spot;
  while (param->objet != NULL)
    {
      tmp = tmp->next;
      free(param->objet);
      param->objet = tmp;
    }
  while (param->spot != NULL)
    {
      spot = spot->next;
      free(param->spot);
      param->spot = spot;
    }
}
