#ifndef __PERLIN_H__
#define __PERLIN_H_
#define LIGNES          30
#define PERT	        0.25
#define OCTAVES         8
#define PAS             128
#define PERSISTANCE     0.01

double		bruit2D(int, int, double *);
void		my_perlin(double, int, t_objet *, double);
double		bruit_coherent2D(double, double, double *);
double		*initBruit2D(int, int, int, int);

#endif
