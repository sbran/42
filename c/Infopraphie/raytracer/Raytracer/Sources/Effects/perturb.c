#include <math.h>
#include "rt.h"

void	perturb_norm(double *Nx, double *Ny, double *Nz, t_objet obj3)
{
  *Ny = *Ny + (cos(obj3.coord.y / 2) * (sqrt(SQ(*Nx) + SQ(*Ny) + SQ(*Nz)) / 2));
}
