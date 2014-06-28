/*
** my_strcmp.c for my_strcmp in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 15:21:46 2011 thibaut coutard
** Last update Mon Nov 14 11:27:47 2011 thibaut coutard
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i = i + 1;
  if (s1[i] != s2[i])
    return (s1[i] - s2[i]);
  else
    return (0);
}
