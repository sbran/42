#include <math.h>
#include <stdlib.h>
#include "rt.h"

double		inter_hyperboloide(t_utils utils, t_objet *obj)
{
  double	a;
  double	b;
  double	c;
  double	R;
  double	d;

  R = obj->size * M_PI / 180;
  a = SQ(utils.vect.v_x)				\
    + SQ(utils.vect.v_y)				\
    - (SQ(utils.vect.v_z)				\
       * (SQ(tan(R))));
  b = (2 * utils.vect.v_x * utils.coord.x)				\
    + (2 * utils.vect.v_y * utils.coord.y)				\
    - ((2 * utils.vect.v_z * utils.coord.z) * (SQ(tan(R))));
  c = (SQ(utils.coord.x)						\
       + SQ(utils.coord.y)						\
       - (SQ(utils.coord.z) * SQ(tan(R))) + HYPER_OPEN);
  d = delta(a, b, c);
  return (search_res(a, b, d));
}
