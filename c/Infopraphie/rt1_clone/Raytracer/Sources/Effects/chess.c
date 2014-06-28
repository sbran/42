/*
** chess.c for raytracer in /home/bagot_b//raytracer_12/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Sun Jun  3 15:03:21 2012 benjamin bagot
** Last update Sun Jun  3 18:18:10 2012 benjamin bagot
*/

#include <math.h>
#include "rt.h"

t_k	*turn_to_black(t_k *k)
{
  k->color.red = 0;
  k->color.green = 0;
  k->color.blue = 0;
  return (k);
}

t_k	*chess(t_objet obj3, t_k *k)
{
  if ((obj3.coord.x >= 0.0 && obj3.coord.y >= 0.0)
      || (obj3.coord.x < 0.0 && obj3.coord.y < 0.0))
    {
      if (((int)ABS(obj3.coord.x) % 100 <= 50
	   && (int)ABS(obj3.coord.y) % 100 <= 50)
	  || ((int)ABS(obj3.coord.x) % 100 > 50
	      && (int)ABS(obj3.coord.y) % 100 > 50))
	k = turn_to_black(k);
    }
  else
    {
      if (((int)ABS(obj3.coord.x) % 100 <= 50
	   && (int)ABS(obj3.coord.y) % 100 <= 50)
	  || ((int)ABS(obj3.coord.x) % 100 > 50
	      && (int)ABS(obj3.coord.y) % 100 > 50))
	k = k;
      else
	k = turn_to_black(k);
    }
  return (k);
}
