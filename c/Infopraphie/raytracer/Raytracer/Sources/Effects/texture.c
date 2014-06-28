#include "rt.h"

t_k	*texture(t_objet obj3, t_k *k, int text)
{
  if (text == 1)
    k = chess(obj3, k);
  else if (text == 2)
    k = ring(obj3, k);
  return (k);
}
