/*
** my_str_isalpha.c for my_str_isalpha in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 18:25:56 2011 thibaut coutard
** Last update Sun Oct 16 16:03:16 2011 thibaut coutard
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while ( str[i] != '\0')
    {
    if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
      i = i + 1;
    else
      return (0);
    }
  return (1);
}
