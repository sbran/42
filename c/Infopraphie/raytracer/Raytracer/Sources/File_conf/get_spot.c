#include <stdio.h>
#include <stdlib.h>
#include "rt.h"
#include "my.h"

extern	int	assign;

void    assign_value_spot(t_spot **elem, char *str)
{
  if (assign == 11)
    (*elem)->coord.x = my_getnbr(str);
  if (assign == 12)
    (*elem)->coord.y = my_getnbr(str);
  if (assign == 13)
    (*elem)->coord.z = my_getnbr(str);
  if (assign == 21)
    (*elem)->color.red = (short)(my_getnbr(str));
  if (assign == 22)
    (*elem)->color.green = (short)(my_getnbr(str));
  if (assign == 23)
    (*elem)->color.blue = (short)(my_getnbr(str));
}

void	get_this_spot(t_spot *elem, char **tab, int *i, int flag)
{
  if (flag == 1)
    (*i)++;
  while (tab[*i] != NULL && my_strcmp(tab[*i], "<OBJ>") != 0
	 && my_strcmp(tab[*i], "<SPOT>") != 0)
    {
      if (my_strcmp(tab[*i], "<POS>") == 0)
	{
	  assign = 10;
	  elem = extract_elem_spot(elem, tab, i);
	}
      else if (my_strcmp(tab[*i], "<COL>") == 0)
	{
	  assign = 20;
	  elem = extract_elem_spot(elem, tab, i);
	}
    }
  assign = 0;
}

t_spot  *get_one_spot(t_spot *spot, char **tab, int *i)
{
  t_spot elem;

  while (tab[*i] != NULL && my_strcmp(tab[*i], "<OBJ>") != 0)
    {
      if (my_strcmp(tab[*i], "<SPOT>") == 0)
	get_this_spot(&elem, tab, i, 1);
      put_spot_in_list(&spot, elem);
    }
  return (spot);
}
