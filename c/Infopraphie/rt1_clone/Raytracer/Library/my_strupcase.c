/*
** my_strupcase.c for my_strupcase in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 16:08:16 2011 thibaut coutard
** Last update Sun Oct 16 16:20:51 2011 thibaut coutard
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 97 || str[i] > 122)
	  i = i + 1;
      else
	{
	  str[i] = str[i] - 32;
	  i = i + 1;
	}
    }
  return (str);
}
