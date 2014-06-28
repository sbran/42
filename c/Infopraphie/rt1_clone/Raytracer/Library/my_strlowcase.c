/*
** my_strlowcase.c for my_strlowcase in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 17:00:37 2011 thibaut coutard
** Last update Sun Oct 16 16:13:31 2011 thibaut coutard
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 64 || str[i] > 90)
          i = i + 1;
      else
        {
          str[i] = str[i] + 32;
          i = i + 1;
        }
    }
  return (str);
}
