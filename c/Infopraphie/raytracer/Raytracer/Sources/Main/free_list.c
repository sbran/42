#include <stdlib.h>
#include "rt.h"

void	free_list(t_param *param)
{
  t_objet	*tmp;
  t_spot	*spot;

  tmp = param->objet;
  spot = param->spot;
  while (param->objet != NULL)
    {
      tmp = tmp->next;
      free(param->objet);
      param->objet = tmp;
    }
  while (param->spot != NULL)
    {
      spot = spot->next;
      free(param->spot);
      param->spot = spot;
    }
}
