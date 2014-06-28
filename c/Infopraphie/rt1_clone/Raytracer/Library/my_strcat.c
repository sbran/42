/*
** my_strcat.c for my_strcat in /home/coutar_t//test_exo/Jour_07
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 10:36:57 2011 thibaut coutard
** Last update Fri Dec  9 16:10:31 2011 thibaut coutard
*/

int     my_strlen(char *str)
{
  int  i;

  i = 0;
  while (str[i] != '\0')
      i = i + 1;
  return i;
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;
  int	a;

  i = my_strlen(dest);
  n = my_strlen(src);
  a = 0;
  while (a != n)
    {
      dest[i] = src[a];
      a = a + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
