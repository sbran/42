#include	<stdlib.h>
#include	"my.h"

void		init_token(char **tab)
{
  tab[0] = "<GEN>\0";
  tab[1] = "<EYE>\0";
  tab[2] = "<POS>\0";
  tab[3] = "<ROT>\0";
  tab[4] = "<A.A>\0";
  tab[5] = "<AMB>\0";
  tab[6] = "<OBJ>\0";
  tab[7] = "<PLAN>\0";
  tab[8] = "<SPHERE>\0";
  tab[9] = "<CYLINDRE>\0";
  tab[10] = "<CONE>\0";
  tab[11] = "<PARABOLOIDE>\0";
  tab[12] = "<HYPERBOLOIDE>\0";
  tab[13] = "<COL>\0";
  tab[14] = "<SIZE>\0";
  tab[15] = "<BRILL>\0";
  tab[16] = "<TRANS>\0";
  tab[17] = "<REFLEX>\0";
  tab[18] = "<PERLIN>\0";
  tab[19] = "<PERTURB>\0";
  tab[20] = "<TEXTURE>\0";
  tab[21] = "<MIDDLE>\0";
  tab[22] = "<SPOT>\0";
  tab[23] = NULL;
}

char		**token_tab()
{
  char		**tab;

  tab = xmalloc(24 * sizeof(*tab));
  init_token(tab);
  return (tab);
}
