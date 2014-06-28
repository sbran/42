#include <math.h>
#include <stdlib.h>
#include "rt.h"

double		inter_paraboloide(t_utils utils, t_objet *obj)
{
  double	a;
  double	b;
  double	c;
  double	R;
  double	d;

  R = obj->size * M_PI / 180;
  a = pow(utils.vect.v_x, 2)			\
    + pow(utils.vect.v_y, 2);
  b = 2 * (utils.coord.x * utils.vect.v_x	\
	   + utils.coord.y * utils.vect.v_y)	\
    - tan(R) * utils.vect.v_z;
  c = pow(utils.coord.x, 2)			\
    + pow(utils.coord.y, 2)			\
    - tan(R) * utils.coord.z;
  d = delta(a, b, c);
  return (search_res(a, b, d));
}
