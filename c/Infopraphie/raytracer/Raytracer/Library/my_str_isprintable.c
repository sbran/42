/*
** my_str_isprintable.c for my_str_isprintable in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 19:06:13 2011 thibaut coutard
** Last update Sun Oct 16 16:09:49 2011 thibaut coutard
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while ( str[i] != '\0')
    {
      if (str[i] > 31 &&  str[i] < 127)
        i = i + 1;
      else
        return (0);
    }
  return (1);
}
