#include "rt.h"

void	count_obj(t_param *param)
{
  t_objet	*tmp;
  int	i;

  i = 1;
  tmp = param->objet;
  while (tmp)
    {
      tmp->nb = i;
      tmp = tmp->next;
      i++;
    }
}
