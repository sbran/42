/*
** my_swap.c for my_swap in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Thu Oct  6 10:06:12 2011 thibaut coutard
** Last update Sun Oct 16 16:23:42 2011 thibaut coutard
*/

void	my_swap(int *a, int *b)
{
  int	param_a;
  int	param_b;

  param_a = *a;
  param_b = *b;
  *b = param_a;
  *a = param_b;
}
