/*
** count_obj.c for count_obj in /home/coutar_t//test_exo/projets/RT/raytracer_12/Raytracer
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Thu May 31 13:28:05 2012 thibaut coutard
** Last update Thu May 31 13:29:22 2012 thibaut coutard
*/

#include "rt.h"

void	count_obj(t_param *param)
{
  t_objet	*tmp;
  int	i;

  i = 1;
  tmp = param->objet;
  while (tmp)
    {
      tmp->nb = i;
      tmp = tmp->next;
      i++;
    }
}
