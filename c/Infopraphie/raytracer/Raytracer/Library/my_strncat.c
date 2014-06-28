/*
** my_strncat.c for my_strncat in /home/coutar_t//test_exo/Jour_07
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 10:57:43 2011 thibaut coutard
** Last update Mon Nov 14 11:28:15 2011 thibaut coutard
*/

char	my_strlen(char *str)
{
  char  i;

  i=0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return i;
}

char	*my_strncat (char *dest, char *src, int nb)
{
  char  i;
  char  n;
  char  a;

  i = my_strlen(dest);
  n = my_strlen(src);
  a = 0;
  while (a != nb)
    {
      dest[i] = src[a];
      a = a + 1;
      i = i + 1;
    }
  return (dest);
}
