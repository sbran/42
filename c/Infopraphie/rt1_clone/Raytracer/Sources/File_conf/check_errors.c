#include	<stdlib.h>
#include	<unistd.h>
#include	"rt.h"
#include	"my.h"

void		my_errorconf(int count, char *s1, char *s2, char *s3)
{
  write(2, "Line : ", my_strlen("Line : "));
  my_put_nbr(count);
  write(2, "\n", my_strlen("\n"));
  write(2, s1, my_strlen(s1));
  write(2, s2, my_strlen(s2));
  write(2, s3, my_strlen(s3));
  exit(EXIT_FAILURE);
}

void		check_nbr(char *str, int *check, int i)
{
  int		err;

  err = 0;
  if (str[i] != '<')
    err = 1;
  if (str[i + 1] == '-')
    i++;
  while (str[++i] && str[i] != '>')
    if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
      err = 1;
  if (str[i] != '>')
    err = 1;
  if (err == 0)
    *check = 1;
}

char		*check_error(char *str, int count, char **token)
{
  int		i;
  int		check;

  i = -1;
  check = 0;
  while (token[++i])
    if (my_strcmp(token[i], str) == 0)
      check = 1;
  if (my_strncmp("<X>", str, 3) == 0 || my_strncmp("<Y>", str, 3) == 0	\
      || my_strncmp("<Z>", str, 3) == 0 || my_strncmp("<R>", str, 3) == 0	\
      || my_strncmp("<G>", str, 3) == 0 || my_strncmp("<B>", str, 3) == 0)
    check_nbr(str, &check, 3);
  else
    check_nbr(str, &check, 0);
  if (check == 0)
    my_errorconf(count, "Invalid instruction : \"", str, "\".\n");
  return (str);
}
