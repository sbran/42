#include <stdio.h>
#include <stdlib.h>
#include "rt.h"

extern	int	assign;

t_objet	*call_get_elem(t_objet *elem, char **tab, int *i, int f)
{
  assign = 10 * f;
  elem = get_elem(elem, tab, i);
  assign = 0;
  return (elem);
}

t_objet	*other_caracs(t_objet *elem, char **tab, int *i)
{
  if (my_strcmp(tab[*i], "<TRANS>") == 0)
    elem = call_get_elem(elem, tab, i, 6);
  else if (my_strcmp(tab[*i], "<MIDDLE>") == 0)
    elem = call_get_elem(elem, tab, i, 7);
  else if (my_strcmp(tab[*i], "<REFLEX>") == 0)
    elem = call_get_elem(elem, tab, i, 8);
  else if (my_strcmp(tab[*i], "<PERLIN>") == 0)
    elem = call_get_elem(elem, tab, i, 9);
  else if (my_strcmp(tab[*i], "<PERTURB>") == 0)
    elem = call_get_elem(elem, tab, i, 10);
  else if (my_strcmp(tab[*i], "<TEXTURE>") == 0)
    elem = call_get_elem(elem, tab, i, 11);
  return (elem);
}

t_objet *get_elem_obj(t_objet *elem, char **tab, int *i, int flag)
{
  if (flag == 1)
    (*i)++;
  while (tab[*i] != NULL && my_strcmp(tab[*i], "<SPOT>") != 0
	 && my_strcmp(tab[*i], "<SPHERE>") != 0
	 && my_strcmp(tab[*i], "<PLAN>") != 0
	 && my_strcmp(tab[*i], "<CYLINDRE>") != 0
	 && my_strcmp(tab[*i], "<CONE>") != 0
	 && my_strcmp(tab[*i], "<PARABOLOIDE>") != 0
	 && my_strcmp(tab[*i], "<HYPERBOLOIDE>") != 0)
    {
      if (my_strcmp(tab[*i], "<POS>") == 0)
	elem = call_get_elem(elem, tab, i, 1);
      else if (my_strcmp(tab[*i], "<COL>") == 0)
	elem = call_get_elem(elem, tab, i, 2);
      else if (my_strcmp(tab[*i], "<ROT>") == 0)
	elem = call_get_elem(elem, tab, i, 3);
      else if (my_strcmp(tab[*i], "<SIZE>") == 0)
	elem = call_get_elem(elem, tab, i, 4);
      else if (my_strcmp(tab[*i], "<BRILL>") == 0)
	elem = call_get_elem(elem, tab, i, 5);
      else
	elem = other_caracs(elem, tab, i);
    }
  return (elem);
}
