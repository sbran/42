/*
** my_strlen.c for my_strlen in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Thu Oct  6 12:46:26 2011 thibaut coutard
** Last update Sun Oct 16 16:12:49 2011 thibaut coutard
*/

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
      i = i + 1;
  return i;
}
