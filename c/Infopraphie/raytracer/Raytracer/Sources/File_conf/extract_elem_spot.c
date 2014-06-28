#include <stdio.h>
#include <stdlib.h>
#include "rt.h"
#include "my.h"

extern	int assign;

int     get_count_of_extract(char **tab, int *i);

void    extract_spot(t_spot **elem, char **tab, int *i)
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
  assign_value_spot(elem, new);
  free(new);
}

t_spot	*call_extract_spot(t_spot *elem, char **tab, int *i, int f)
{
  assign = assign + f;
  extract_spot(&elem, tab, i);
  assign = assign - f;
  return (elem);
}

t_spot	*extract_elem_spot(t_spot *elem, char **tab, int *i)
{
  while (tab[++(*i)] != NULL && my_strcmp(tab[*i], "<OBJ>") != 0
      && my_strcmp(tab[*i], "<POS>") != 0 && my_strcmp(tab[*i], "<COL>") != 0
      && my_strcmp(tab[*i], "<SPOT>") != 0)
    {
      if (my_strncmp(tab[*i], "<X>", 3) == 0		\
	  || my_strncmp(tab[*i], "<R>", 3) == 0)
	elem = call_extract_spot(elem, tab, i, 1);
      else if (my_strncmp(tab[*i], "<Y>", 3) == 0
	       || my_strncmp(tab[*i], "<G>", 3) == 0)
	elem = call_extract_spot(elem, tab, i, 2);
      else if (my_strncmp(tab[*i], "<Z>", 3) == 0
	       || my_strncmp(tab[*i], "<B>", 3) == 0)
	elem = call_extract_spot(elem, tab, i, 3);
    }
  return (elem);
}
