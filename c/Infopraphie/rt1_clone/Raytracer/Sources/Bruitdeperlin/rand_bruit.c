/*
** rand_bruit.c for Raytracer in /home/lebuha_r//Current/Igraph/RayTracer/Bruit
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Tue May 22 22:11:54 2012 riwal lebuhan
** Last update Sun Jun  3 17:57:35 2012 david heang
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#include	<math.h>
#include <sys/types.h>
#include <unistd.h>
#include	<string.h>
#include        "rt.h"
#include	"my.h"

#define POS(x)		((x) < 0) ? (-x) : (x)
static int longueur_max = 0;
static int hauteur_max;

double *initBruit2D(int l, int h, int p, int n)
{
  int i;
  double *valeurs2D;

  i = 0;
  longueur_max = (int) (ceil(l * pow(2, n  - 1)  / p));
  hauteur_max = (int) ceil(h * pow(2, n  - 1)  / p);
  valeurs2D = xmalloc(sizeof(double) * (longueur_max * hauteur_max + 1));
  srand(time(NULL) * getpid());
  while (i < longueur_max * hauteur_max)
    {
      valeurs2D[i] = ((double) rand()) / RAND_MAX;
      i++;
    }
  return (valeurs2D);
}

double bruit2D(int i, int j, double *valeurs2D)
{
  double test;

  test = 0.0;
  if ((i * longueur_max + j) < (longueur_max * hauteur_max))
    test = valeurs2D[i * longueur_max + j];
  return (test);
}
