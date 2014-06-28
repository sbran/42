#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"rt.h"
#include	"my.h"

double		inter_sphere(t_utils utils, t_objet *obj)
{
  double	a;
  double	b;
  double	c;
  double	R;
  double	d;

  R = obj->size;
  a = pow(utils.vect.v_x, 2.00)					\
    + pow(utils.vect.v_y, 2.00)					\
    + pow(utils.vect.v_z, 2.00);
  b = (2.0 * utils.vect.v_x * utils.coord.x)				\
    + (2.0 * utils.vect.v_y * utils.coord.y)				\
    + (2.0 * utils.vect.v_z * utils.coord.z);
  c = (pow(utils.coord.x, 2.00)				\
       + pow(utils.coord.y, 2.00)			\
       + pow(utils.coord.z, 2.00))			\
    - (pow(R, 2.00));
  d = delta(a, b, c);
  return (search_res(a, b, d));
}
