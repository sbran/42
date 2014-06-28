#include <stdlib.h>
#include <stdio.h>
#include "rt.h"
#include "my.h"

extern	int assign;

/*
int	my_strlen(char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);*/

int     get_count_of_extract(char **tab, int *i)
{
  int j;
  int count;

  j = 0;
  count = 0;
  while (tab[*i][j] != '\0')
    {
      if (tab[*i][j] == '<' || tab[*i][j] == '>'
          || tab[*i][j] == 'X' || tab[*i][j] == 'R'
          || tab[*i][j] == 'Y' || tab[*i][j] == 'G'
          || tab[*i][j] == 'Z' || tab[*i][j] == 'B')
        count++;
      j++;
    }
  return (count);
}

void    extract_elem(t_objet **elem, char **tab, int *i)
{
  int j;
  int k;
  int count;
  char *new;

  j = 0;
  k = 0;
  count = get_count_of_extract(tab, i);
  new = xmalloc((my_strlen(tab[*i]) - count + 1) * sizeof(*new));
  while (tab[*i][j] != '\0')
    {
      if (tab[*i][j] != '<' && tab[*i][j] != '>'
          && tab[*i][j] != 'X' && tab[*i][j] != 'R'
          && tab[*i][j] != 'Y' && tab[*i][j] != 'G'
          && tab[*i][j] != 'Z' && tab[*i][j] != 'B')
        {
          new[k] = tab[*i][j];
          k++;
        }
      j++;
    }
  new[k] = '\0';
  assign_value(elem, new);
  free(new);
}

t_objet	*call_extract_elem(t_objet *elem, char **tab, int *i, int f)
{
  assign = assign + f;
  extract_elem(&elem, tab, i);
  assign = assign - f;
  return (elem);
}

t_objet	*get_elem(t_objet *elem, char **tab, int *i)
{
  int type;

  type = 1;
  while (tab[++(*i)] != NULL && check_limit_while(tab, i) == 1)
    {
      if (my_strncmp(tab[*i], "<X>", 3) == 0		\
	  || my_strncmp(tab[*i], "<R>", 3) == 0)
	elem = call_extract_elem(elem, tab, i, type);
      else if (my_strncmp(tab[*i], "<Y>", 3) == 0
	       || my_strncmp(tab[*i], "<G>", 3) == 0)
	elem = call_extract_elem(elem, tab, i, type);
      else if (my_strncmp(tab[*i], "<Z>", 3) == 0
	       || my_strncmp(tab[*i], "<B>", 3) == 0)
	elem = call_extract_elem(elem, tab, i, type);
      else
	elem = call_extract_elem(elem, tab, i, type);
      type++;
    }
  return (elem);
}
