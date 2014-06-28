/*
** perturb.c for raytracer in /home/bagot_b//raytracer_12/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Sun Jun  3 13:32:03 2012 benjamin bagot
** Last update Sun Jun  3 18:18:30 2012 benjamin bagot
*/

#include <math.h>
#include "rt.h"

void	perturb_norm(double *Nx, double *Ny, double *Nz, t_objet obj3)
{
  *Ny = *Ny + (cos(obj3.coord.y / 2)
	       * (sqrt(SQ(*Nx) + SQ(*Ny) + SQ(*Nz)) / 2));
}
