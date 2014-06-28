#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "rt.h"
#include "my.h"

void	my_show_list(t_objet *list);

void		treat_image(t_param *param, char *file)
{
  int ret;

  ret = get_scene(param, file);
  if (ret == -1)
    exit(0);
  rempli_img(param);
}

void		init_libx(t_param *param, char *file)
{
  param->mlx_ptr = mlx_init();
  if (param->mlx_ptr == 0)
    my_puterror("Can not init LibX.\n");
  param->win_ptr = mlx_new_window(param->mlx_ptr, WIN_X, WIN_Y, "Raytracer");
  param->img = mlx_new_image(param->mlx_ptr, WIN_X, WIN_Y);
  treat_image(param, file);
  mlx_key_hook(param->win_ptr, &key, &param);
  mlx_expose_hook(param->win_ptr, &expose, param);
  mlx_loop(param->mlx_ptr);
}

int     main(int ac, char **av)
{
  t_param       param;

  if (ac == 2)
    init_libx(&param, av[1]);
  else if (ac == 1)
    my_putstr("Please select a configuration file.\n");
  else
    my_putstr("Select just one configuration file.\n");
  return (0);
}
