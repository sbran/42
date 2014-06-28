/*
** utils_to_inter.c for raytracer in /home/bagot_b//raytracer_12/2BackUp_qui_bug/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Tue May 22 17:05:38 2012 benjamin bagot
** Last update Tue May 22 17:10:23 2012 benjamin bagot
*/

#include "math.h"

double	delta(double a, double b, double c)
{
  return ((b * b) - (4 * a * c));
}

double  search_res(double a, double b, double d)
{
  double res1;
  double res2;

  if (d >= 0.0)
    {
      res1 = (-b - sqrt(d)) / (2 * a);
      res2 = (-b + sqrt(d)) / (2 * a);
      if (res1 < 0.0 && res2 < 0.0)
        return (-1.0);
      else if (res2 < res1 && res2 >= 0.0)
        return (res2);
      else
        return (res1);
    }
  else
    return (-1);
}
