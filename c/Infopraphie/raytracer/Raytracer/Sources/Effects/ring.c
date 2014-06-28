#include <math.h>
#include "rt.h"

t_k	*ring(t_objet obj3, t_k *k)
{
  double d;

  d = sqrt(SQ(obj3.coord.x) + SQ(obj3.coord.y));
  if ((int)d % 100 < 50)
    {
      k->color.red = 0;
      k->color.green = 0;
      k->color.blue = 0;
    }
  return (k);
}
