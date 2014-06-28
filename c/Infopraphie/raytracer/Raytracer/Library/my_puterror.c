/*
** my_puterror.c for RT in /home/lebuha_r//Current/Igraph/RayTracer/2BackUp/Raytracer/Library
** 
** Made by riwal lebuhan
** Login   <lebuha_r@epitech.net>
** 
** Started on  Sat Apr 28 16:32:34 2012 riwal lebuhan
** Last update Sat Apr 28 16:34:49 2012 riwal lebuhan
*/

#include	<stdlib.h>
#include	"../Includes/my.h"

void		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
