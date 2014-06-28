/*
** my_getnbr.c for my_getnbr in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Fri Oct  7 19:46:49 2011 thibaut coutard
** Last update Mon Nov 14 11:25:35 2011 thibaut coutard
*/

int	my_getnbr( char *str)
{
  int	nb;
  int	nb_r;
  int	a;

  a = 1;
  nb_r = 0;
  nb = 0;
  while (*str > '9' || *str < '0')
    {
      if (*str == '-')
    {
      a = -a;
    }
      str = str + 1;
    }

  while (*str <= '9' && *str >= '0')
    {
      nb_r = nb_r * 10;
      nb = *str - '0';
      str = str + 1;
      nb_r = nb_r + nb;
    }
  nb_r = nb_r * a;
  return (nb_r);
}
