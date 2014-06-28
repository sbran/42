/*
** my_revstr.c for my_revstr in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 10:17:30 2011 thibaut coutard
** Last update Sun Oct 16 15:21:09 2011 thibaut coutard
*/

char	*my_revstr(char *str)
{
  int	i;
  char	tab[255];
  int	n;

  n = 1;
  i = 0;
  while (str[i])
    {
      tab[n] = str[i];
      i = i + 1;
      n = n + 1;
    }
  n = n - 1;
  i = 0;
  while (n != 0)
    {
      str[i] = tab [n];
      n = n - 1;
      i = i + 1;
    }
  return (str);
}
