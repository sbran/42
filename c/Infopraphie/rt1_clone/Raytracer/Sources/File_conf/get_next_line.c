/*
** get_next_line.c for get_next_line in /home/heang_d//lem-in_2016
** 
** Made by david heang
** Login   <heang_d@epitech.net>
** 
** Started on  Wed Apr 11 13:50:05 2012 david heang
** Last update Sun Jun  3 19:27:56 2012 david heang
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char	*push(char *str, char *str_out)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] && str[i] != '\n')
    i++;
  while (str[i] == '\n')
    i++;
  while (str[i])
    str[a++] = str[i++];
  str[a] = '\0';
  return (str_out);
}

char		*init(char *buf, int *a)
{
  int   i;
  char  *str_out;

  i = 0;
  str_out = xmalloc(sizeof(*buf) * (my_strlen(buf) + 1));
  str_out[0] = '\0';
  while (buf[(*a)] && buf[(*a)] != '\n')
    str_out[i++] = buf[(*a)++];
  str_out[i] = '\0';
  if (!str_out && !str_out[0])
    {
      free(str_out);
      return (NULL);
    }
  return (str_out);
}

char		*copy(char *buf, char *str, int *a)
{
  int	i;
  char	*str_out;

  i = 0;
  str_out = xmalloc(sizeof(*str) * my_strlen(buf) + my_strlen(str) + 1);
  while (str[i])
    {
      str_out[i] = str[i];
      i = i + 1;
    }
  while (buf[(*a)] && buf[(*a)] != '\n')
    str_out[i++] = buf[(*a)++];
  str_out[i] = '\0';
  free(str);
  return (str_out);
}

char            *get_next_line(const int fd)
{
  char		*str_out;
  static char	buf[READ + 1];
  int		size;
  int		a;

  a = 0;
  if (!(str_out = init(buf, &a)))
    return (NULL);
  if (buf[a] == '\n')
    return (push(buf, str_out));
  while ((size = xread(fd, buf, READ)) > 0)
    {
      a = 0;
      buf[size] = '\0';
      if (!(str_out = copy(buf, str_out, &a)))
	return (NULL);
      if (buf[a] == '\n')
	return (push(buf, str_out));
    }
  if (size <= 0)
    return (NULL);
  buf[size] = '\0';
  if (!size && !str_out[0])
    return (NULL);
  return (str_out);
}
