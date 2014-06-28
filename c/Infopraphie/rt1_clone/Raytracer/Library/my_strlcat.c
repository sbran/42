/*
** my_strlcat.c for my_strlcat in /home/coutar_t//test_exo/Jour_07
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 11:35:16 2011 thibaut coutard
** Last update Sun Oct 16 16:12:00 2011 thibaut coutard
*/

char    my_strlen(char *str)
{
  char  i;

  i=0;
  while (str[i] != '\0')
      i = i + 1;
  return i;
}

int    my_strlcat (char *dest, char *src, int size)
{
  char  i;
  char  n;
  char  a;

  i = my_strlen(dest);
  n = my_strlen(src);
  a = 0;
  while (a != size)
    {
      dest[i] = src[a];
      i = i + 1;
      a = a + 1;
    }
  return (my_strlen(dest));
}
