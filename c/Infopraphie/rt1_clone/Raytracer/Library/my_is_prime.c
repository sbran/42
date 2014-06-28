/*
** my_is_prime.c for my_is_prime in /u/epitech_2016/coutar_t/rendu/lib/my
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 14:50:07 2011 thibaut coutard
** Last update Sun Oct 16 15:16:35 2011 thibaut coutard
*/

int	my_is_prime(int nombre)
{
  int	n;
  int	nbr;

  n = 2;
  while (n < nombre)
    {
      nbr = nombre % n;
      if (nbr == 0)
	return (0);
      n = n + 1;
    }
  return (1);
}
