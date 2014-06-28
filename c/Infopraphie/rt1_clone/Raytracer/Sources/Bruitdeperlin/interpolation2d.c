/*
** bruitdeperlin.c for bruitdeperlin in /home/strohe_d//Svn/raytracer_12/Raytracer/Sources/inter_obj
** 
** Made by dorian stroher
** Login   <strohe_d@epitech.net>
** 
** Started on  Tue May 22 22:05:27 2012 dorian stroher
** Last update Sun Jun  3 14:05:54 2012 dorian stroher
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rt.h"
#include "my.h"

double interpolation_cos(double a, double b, double x)
{
  double k;

  k = (1 - cos(x * M_PI)) / 2;
  return (a * (1-k) + b * k);
}

double interpolation_cos2D(t_perlin perlin, double x, double y)
{
  double x1;
  double x2;

  x1 = interpolation_cos(perlin.a, perlin.b, x);
  x2 = interpolation_cos(perlin.c, perlin.d, x);
  return (interpolation_cos(x1, x2, y));
}

double fonction_bruit2D(double x, double y, double *valeurs2D)
{
  int i;
  int j;
  double pas;
  t_perlin perlin;

  pas = PAS;
  j = (int)(y / PAS);
  i = (int)(x / PAS);
  perlin.a = bruit2D(i, j, valeurs2D);
  perlin.b = bruit2D(i + 1, j, valeurs2D);
  perlin.c = bruit2D(i, j + 1, valeurs2D);
  perlin.d = bruit2D(i + 1, j + 1, valeurs2D);
  return (interpolation_cos2D(perlin, fmod((x / pas), 1), fmod((y / pas), 1)));
}

double bruit_coherent2D(double x, double y, double *valeurs2D)
{
  double somme;
  double p;
  int f;
  int i;
  double persistance;

  somme = 0.0;
  f = 1;
  p = 1;
  i = 0;
  persistance = 0.5;
  while (i < OCTAVES)
    {
      somme += p * fonction_bruit2D(x * f, y * f, valeurs2D);
      p *= persistance;
      f *= 2;
      i++;
    }
  return (somme * (1 - persistance) / (1 - p));
}

void    my_perlin(double bruit, int mark, t_objet *tmp, double x)
{
  double va;

  if (mark == 1)
    va = 1 - sqrt(fabs(sin(2 * 3.141592 * bruit)));
  if (mark == 2)
    va = (1 - cos(LIGNES * 2 * M_PI * (x / WIN_Y + PERT * bruit))) / 2;
  if (mark == 3)
    va = bruit;
  tmp->color.red = tmp->pm_color.red * (1 - va) + tmp->ps_color.red * va;
  tmp->color.green = tmp->pm_color.green * (1 - va) + tmp->ps_color.green * va;
  tmp->color.blue = tmp->pm_color.blue * (1 - va) + tmp->ps_color.blue * va;
}
