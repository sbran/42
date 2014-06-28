/*
** my_str_islower.c for my_str_islower.c in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 18:52:27 2011 thibaut coutard
** Last update Sun Oct 16 16:03:49 2011 thibaut coutard
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while ( str[i] != '\0')
    {
      if (str[i] >= 'a' &&  str[i] <= 'z')
        i = i + 1;
      else
        return (0);
    }
  return (1);
}
