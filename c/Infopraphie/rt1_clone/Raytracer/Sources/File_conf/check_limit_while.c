#include "my.h"

int	check_limit_while(char **tab, int *i)
{
  if (my_strcmp(tab[*i], "<SPOT>") != 0
      && my_strcmp(tab[*i], "<SPHERE>") != 0
      && my_strcmp(tab[*i], "<PLAN>") != 0
      && my_strcmp(tab[*i], "<CYLINDRE>") != 0
      && my_strcmp(tab[*i], "<CONE>") != 0
      && my_strcmp(tab[*i], "<PARABOLOIDE>") != 0
      && my_strcmp(tab[*i], "<HYPERBOLOIDE>") != 0
      && my_strcmp(tab[*i], "<POS>") != 0
      && my_strcmp(tab[*i], "<COL>") != 0
      && my_strcmp(tab[*i], "<ROT>") != 0
      && my_strcmp(tab[*i], "<SIZE>") != 0
      && my_strcmp(tab[*i], "<BRILL>") != 0
      && my_strcmp(tab[*i], "<TRANS>") != 0
      && my_strcmp(tab[*i], "<LIM>") != 0
      && my_strcmp(tab[*i], "<MIDDLE>") != 0
      && my_strcmp(tab[*i], "<REFLEX>") != 0
      && my_strcmp(tab[*i], "<PERTURB>") != 0
      && my_strcmp(tab[*i], "<TEXTURE>") != 0
      && my_strcmp(tab[*i], "<PERLIN>") != 0)
    return (1);
  return (0);
}
