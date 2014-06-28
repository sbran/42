#include "math.h"

double	delta(double a, double b, double c)
{
  return ((b * b) - (4 * a * c));
}

double  search_res(double a, double b, double d)
{
  double res1;
  double res2;

  if (d >= 0.0)
    {
      res1 = (-b - sqrt(d)) / (2 * a);
      res2 = (-b + sqrt(d)) / (2 * a);
      if (res1 < 0.0 && res2 < 0.0)
        return (-1.0);
      else if (res2 < res1 && res2 >= 0.0)
        return (res2);
      else
        return (res1);
    }
  else
    return (-1);
}
