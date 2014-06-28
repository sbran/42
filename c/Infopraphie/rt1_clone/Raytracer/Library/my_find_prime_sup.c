/*
** my_find_prime_sup.c for my_find_prime_sup in /home/coutar_t//test_exo/Jour_05
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Wed Oct 12 08:02:37 2011 thibaut coutard
** Last update Sun Oct 16 15:10:57 2011 thibaut coutard
*/

int     my_find_prime_sup(int nb)
{
  int   n;
  int   nbr;
  int	i;

  i = 0;
  n = 2;
  while (n != nb)
    {
      nbr = nb % n;
      if (nbr == 0)
	i = 1;
      n = n + 1;
    }
  if (i == 0)
    return (nb);
  else
    my_find_prime_sup(nb + 1);
}
