/*
** my_getnbr_base.c for my_getnbr_base in /home/coutar_t//test_exo/Jour_06
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Wed Oct 12 21:30:35 2011 thibaut coutard
** Last update Mon Jan  2 14:47:36 2012 thibaut coutard
*/

int	compt(int *res, char *str, char *base)
{
  int	c;
  int	n;
  int	u;

  c = 0;
  while (c < my_strlen(str))
    {
      n = 0;
      u = str[c];
      while (base[n] != u)
	n = n + 1;
      res[c] = n;
      c = c + 1;
    }
}

int	my_getnbr_base(char *str, char *base)
{
  int	c;
  int	nb;
  int	a;
  int	res[my_strlen(str)];

  compt(res, str, base);
  nb = 0;
  a = my_strlen(str) - 1;
  c = 0;
  while (c < my_strlen(str))
    {
      nb = nb + res[c] * my_power_rec(my_strlen(base), a);
      c = c + 1;
      a = a - 1;
    }
  return (nb);
}
