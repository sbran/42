#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "rt.h"
#include "my.h"

t_k   anti_aliasing(int x, int y, t_param *param, t_k k)
{
  double	i;
  double	j;
  t_k		tmp;

  i = (double)x;
  init_k(&k);
  while (i < (double)(x + 1))
    {
      j = (double)y;
      while (j < (double)(y + 1))
	{
	  init_k(&tmp);
	  tmp = calc(i, j, param, &tmp);
	  k.color.blue += tmp.color.blue;
	  k.color.green += tmp.color.green;
	  k.color.red += tmp.color.red;
	  j += 1.0 / param->anti_alias;
	}
      i += 1.0 / param->anti_alias;
    }
  k.color.red = k.color.red / SQ(param->anti_alias);
  k.color.green = k.color.green / SQ(param->anti_alias);
  k.color.blue = k.color.blue / SQ(param->anti_alias);
  k.k = tmp.k;
  return (k);
}

void		set_aa(t_param *param)
{
  if (param->anti_alias < 1.0)
    param->anti_alias = 1.0;
  if (param->anti_alias > 4.0)
    param->anti_alias = 4.0;
}

void		rempli_img(t_param *param)
{
  int	x;
  int	y;
  t_k	k;

  x = -1;
  y = 0;
  param->valeurs2D = initBruit2D(1000, 1000, PAS, OCTAVES);
  my_putstr("Please wait...\n");
  count_obj(param);
  set_aa(param);
  while (x < WIN_X && y < WIN_Y)
    {
      while (++x < WIN_X)
	{
	  k = anti_aliasing(x, y, param, k);
	  if (k.k >= 0)
	    mlx_ppti(x, y, param, &k);
	}
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr	\
				, param->img, 0, 0);
      x = -1;
      y++;
    }
  my_putstr("Done\n");
}
