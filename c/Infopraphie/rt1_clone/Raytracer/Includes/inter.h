/*
** inter.h for RayTracer in /home/lebuha_r//svn/raytracer_12/Raytracer/Includes
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Sat Jun  2 02:34:12 2012 riwal lebuhan
** Last update Sun Jun  3 00:07:03 2012 riwal lebuhan
*/

#ifndef		__INTER_H__
#define		__INTER_H__

double		inter_plan(t_utils, t_objet *);
double		inter_cylindre(t_utils, t_objet *);
double		inter_cone(t_utils, t_objet *);
double		inter_sphere(t_utils, t_objet *);
double		inter_paraboloide(t_utils, t_objet *);
double		inter_hyperboloide(t_utils, t_objet *);
double		search_res(double, double, double);
double		delta(double, double, double);

#endif
