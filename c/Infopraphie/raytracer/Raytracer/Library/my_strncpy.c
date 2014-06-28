/*
** my_strncpy.c for my_strncpy in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 09:52:57 2011 thibaut coutard
** Last update Sun Oct 16 16:19:39 2011 thibaut coutard
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i != nb)
    {
    dest[i] = src[i];
    i = i + 1;
    }
  if (src[i] != '\0')
    dest[i] = '\0';
  return (dest);
}
