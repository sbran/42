/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/27 19:45:18 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "rt.h"

int				ft_expose_hook(t_env *env)
{
	double		dist;
	double		tmp_dist;
	double		x;
	double		y;
	int			color;
	int			color2;
	t_coord		*tmp;

	dist = 0;
	tmp_dist = 0;
	x = 0;
	y = 0;
	color = 0;
	color2 = 0;
	while (y < SCREEN_Y)
	{
		x = 0;
		while (x < SCREEN_X)
		{
			env->dir.x = x - (SCREEN_X / 2);
			env->dir.y = y - (SCREEN_Y / 2);
			tmp = env->sphere;
			while (tmp)
			{
				tmp_dist = touch_sphere(env, tmp);
				if ((tmp_dist != 0 && tmp_dist < dist) || dist == 0)
				{
					dist = tmp_dist;
					color2 = tmp->color;
				}
				tmp = tmp->next;
			}
			if (dist > 0)
			{
				color = diffuse(env, dist, color2);
				mlx_pixel_put(env->mlx, env->win, x, y, color);
				dist = 0;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				ft_key_hook(int keycode, t_env *env)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	(void)env;
	if (keycode == 65307)
		exit(1);
	if (keycode == 65453)
		env->const_light.z = (env->const_light.z - 100);
	if (keycode == 65451)
		env->const_light.z = (env->const_light.z + 100);
	if (keycode == 65363)
		env->const_light.x = (env->const_light.x + 100);
	if (keycode == 65361)
		env->const_light.x = (env->const_light.x - 100);
	if (keycode == 65364)
		env->const_light.y = (env->const_light.y + 100);
    if (keycode == 65362)
		env->const_light.y = (env->const_light.y - 100);
	ft_expose_hook(env);
	return (0);
}

int				ft_mouse_hook(int button, int x, int y)
{
	ft_putstr("mouse : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(" : ");
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

void			ray_tracing(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SCREEN_X, SCREEN_Y, "RT - Bros");
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_mouse_hook(env->win, ft_mouse_hook, env);
	mlx_expose_hook(env->win, ft_expose_hook, env);
	mlx_loop(env->mlx);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (av[1])
	{
		if ((env.fd = open(av[1], O_RDONLY | S_IRUSR)) == -1)
		{
			ft_putstr("Open file failed.\n");
			return (-1);
		}
		init_struct(&env);
		while (ft_get_next_line(env.fd, &env.line))
		{
			ft_putendl(env.line);
			env.buff = ft_strsplit(env.line, ',');
			if (ft_strequ(env.buff[0], "camera") == 1)
				init_camera(&env, env.buff);
			else if (ft_strequ(env.buff[0], "light") == 1)
				init_light(&env, env.buff);
			else if (ft_strequ(env.buff[0], "sphere") == 1)
				init_sphere(&env, env.buff);
			else
			{
				ft_putstr("'.rt' not valid, try another one ;)");
				return (0);
			}
		}
		close(env.fd);
	}
	if (ac == 2)
		ray_tracing(&env);
	else
		ft_putstr("RT need a '.rt' file to work...thx ;)");
	return (0);
}
