/*
** my_putnbr_base1.c for my_putnbr_base in /home/coutar_t//test_exo/Jour_06
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Oct 12 20:41:34 2011 thibaut coutard
** Last update Thu Nov 24 19:38:15 2011 thibaut coutard
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	n;
  char	basei;
  char	res[255];
  int	u;

  n = 0;
  basei = my_strlen(base);
  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  while (nbr > 0)
    {
      u = nbr % basei;
      nbr = nbr / basei;
      res[n] = base[u];
      n = n + 1;
    }
  my_revstr(res);
  res[n] = '\0';
  nbr = my_getnbr(res);
  my_putstr(res);
}
