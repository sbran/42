#include <stdlib.h>
#include "rt.h"
#include "my.h"

void    extract_elem_eye(t_param *param, char *str, char t, char w)
{
  char *new;

  new = extract_str(str);
  if (t == 'p' && w == 'x')
    param->eye_coord.x = atof(new);
  if (t == 'p' && w == 'y')
    param->eye_coord.y = atof(new);
  if (t == 'p' && w == 'z')
    param->eye_coord.z = atof(new);
  if (t == 'r' && w == 'x')
    param->eye_rot.rot_x = atof(new);
  if (t == 'r' && w == 'y')
    param->eye_rot.rot_y = atof(new);
  if (t == 'r' && w == 'z')
    param->eye_rot.rot_z = atof(new);
  free(new);
}

void    get_eye_elem(t_param *param, char **tab, int *i, char t)
{
  while (tab[(*i)++] != NULL && my_strcmp(tab[*i], "<OBJ>") != 0
         && my_strcmp(tab[*i], "<SPOT>") != 0
         && my_strcmp(tab[*i], "<A.A>") != 0
         && my_strcmp(tab[*i], "<AMB>") != 0
         && my_strcmp(tab[*i], "<POS>") != 0
         && my_strcmp(tab[*i], "<ROT>") != 0)
    {
      if (my_strncmp(tab[*i], "<X>", 3) == 0)
        extract_elem_eye(param, tab[*i], t, 'x');
      else if (my_strncmp(tab[*i], "<Y>", 3) == 0)
        extract_elem_eye(param, tab[*i], t, 'y');
      else if (my_strncmp(tab[*i], "<Z>", 3) == 0)
        extract_elem_eye(param, tab[*i], t, 'z');
    }
}

void    get_eye(t_param *param, char **tab, int *i)
{
  (*i)++;
  while (tab[*i] != NULL && my_strcmp(tab[*i], "<OBJ>") != 0
         && my_strcmp(tab[*i], "<SPOT>") != 0
         && my_strcmp(tab[*i], "<EYE>") != 0
         && my_strcmp(tab[*i], "<A.A>") != 0
         && my_strcmp(tab[*i], "<AMB>") != 0)
    {
      if (my_strcmp(tab[*i], "<POS>") == 0)
        get_eye_elem(param, tab, i, 'p');
      else if (my_strcmp(tab[*i], "<ROT>") == 0)
        get_eye_elem(param, tab, i, 'r');
    }
}
