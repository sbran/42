/*
** main.h for RayTracer in /home/lebuha_r//svn/raytracer_12/Raytracer/Includes
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Sat Jun  2 02:32:08 2012 riwal lebuhan
** Last update Sun Jun  3 17:21:03 2012 dorian stroher
*/

#ifndef		__MAIN_H__
#define		__MAIN_H__

void		rempli_img(t_param *);
void		aff_percent(int, t_param *);
t_k		calc(double, double, t_param *, t_k *);
int		expose(t_param *);
int		key(int, t_param **);
void		mlx_ppti(int, int, t_param *, t_k *);
void		free_list(t_param *);

#endif

