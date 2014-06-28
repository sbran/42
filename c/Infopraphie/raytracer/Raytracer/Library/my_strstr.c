/*
** my_strstr.c for my_strstr in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 11:28:54 2011 thibaut coutard
** Last update Sun Oct 16 16:20:23 2011 thibaut coutard
*/

#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  char	*u;
  int	i;
  int	n;

  i = 0;
  n = 0;
   while (str[i] != '\0')
    {
      if (to_find[n] == str[i])
	{
     	  n = n + 1;
	  u = &str[i];
	}
      else if (n != my_strlen(to_find))
	{
	  n = 0;
	  u = 0;
	}
      i = i + 1;
    }
   u = u - n + 1;
  if (n > 0)
      return (u);
  else
    return (NULL);
}
