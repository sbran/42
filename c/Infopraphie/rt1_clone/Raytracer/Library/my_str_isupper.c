/*
** my_str_isupper.c for my_str_isupper in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 18:59:08 2011 thibaut coutard
** Last update Sun Oct 16 16:10:19 2011 thibaut coutard
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while ( str[i] != '\0')
    {
      if (str[i] >= 'A' &&  str[i] <= 'Z')
        i = i + 1;
      else
        return (0);
    }
  return (1);
}
