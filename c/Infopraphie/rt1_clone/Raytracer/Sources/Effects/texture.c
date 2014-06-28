/*
** texture.c for raytracer in /home/bagot_b//raytracer_12/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Sun Jun  3 16:34:58 2012 benjamin bagot
** Last update Sun Jun  3 16:40:00 2012 benjamin bagot
*/

#include "rt.h"

t_k	*texture(t_objet obj3, t_k *k, int text)
{
  if (text == 1)
    k = chess(obj3, k);
  else if (text == 2)
    k = ring(obj3, k);
  return (k);
}
