/*
** my_square_root.c for my_square_root.c in /u/epitech_2016/coutar_t/rendu/lib/my
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 14:40:36 2011 thibaut coutard
** Last update Mon Nov 14 11:27:09 2011 thibaut coutard
*/

int	my_square_root(int nb)
{
  int	n;
  int	nbr;

  n = 0;
  while (n < 46341)
    {
      nbr = n * n;
      if (nbr == nb)
	return (n);
      else
	n = n + 1;
    }
  return (0);
}
