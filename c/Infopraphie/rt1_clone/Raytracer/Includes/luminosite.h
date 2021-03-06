/*
** luminosite.h for RayTracer in /home/lebuha_r//svn/raytracer_12/Raytracer/Includes
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Sat Jun  2 02:42:12 2012 riwal lebuhan
** Last update Sun Jun  3 19:12:31 2012 benjamin bagot
*/

#ifndef		__LUMINOSITE_H__
#define		__LUMINOSITE_H__

void		init_new_color(t_k *k);
void		init_distance(t_spot *spot, t_utils *L, t_objet obj3);
void		calc_coord(t_k *, t_objet *, t_utils *);
t_k		*luminosite(t_spot *, t_k *, t_objet *, t_utils *);
t_k		*shadow(t_param *, t_objet *, t_k *, t_utils *);
t_k		*texture(t_objet obj3, t_k *k, int text);
t_k		*chess(t_objet obj3, t_k *k);
t_k		*ring(t_objet obj3, t_k *k);
void		perturb_norm(double *Nx, double *Ny, double *Nz, t_objet obj3);
int		prod_scal(t_utils *L, t_utils *utils);

#endif
