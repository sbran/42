/*
** ring.c for raytracer in /home/bagot_b//raytracer_12/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Sun Jun  3 15:39:25 2012 benjamin bagot
** Last update Sun Jun  3 16:08:41 2012 benjamin bagot
*/

#include <math.h>
#include "rt.h"

t_k	*ring(t_objet obj3, t_k *k)
{
  double d;

  d = sqrt(SQ(obj3.coord.x) + SQ(obj3.coord.y));
  if ((int)d % 100 < 50)
    {
      k->color.red = 0;
      k->color.green = 0;
      k->color.blue = 0;
    }
  return (k);
}
