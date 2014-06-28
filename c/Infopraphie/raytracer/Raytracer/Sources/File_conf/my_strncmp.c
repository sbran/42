/*
** my_strncmp.c for raytracer in /home/bagot_b//raytracer_12/2BackUp/Raytracer
** 
** Made by benjamin bagot
** Login   <bagot_b@epitech.net>
** 
** Started on  Tue May  8 14:25:54 2012 benjamin bagot
** Last update Tue May  8 14:26:54 2012 benjamin bagot
*/

int	my_strncmp(char *str1, char *str2, int n)
{
  int i;

  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i] && i < n)
    i++;
  if (i == n)
    return (0);
  return (1);
}
