/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:52:29 by sbran             #+#    #+#             */
/*   Updated: 2014/05/17 01:14:49 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf3d.h"

size_t	ft_get_color(t_env *env)
{
	size_t	color;

	color = 0;
	if (check_hit(env) == '7')
	{
		if (env->side == 0.0)
			color = RGB_WALL_O;
		else if (env->side == 1.0)
			color = RGB_WALL_E;
		else if (env->side == 2.0)
			color = RGB_WALL_S;
		else
			color = RGB_WALL_N;
	}
	else
		color = RGB_ITEM;
	return (color);
}

void	draw(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_X)
	{
		j = 0;
		init(env, i);
		calc_ray(env);
		check_hit(env);
		calc_draw(env);
		while (j < env->drawstart)
			mlx_pixel_put(env->mlx, env->win, i, j++, RGB_SKY);
		while (env->drawstart <= env->drawend)
		{
			mlx_pixel_put(env->mlx, env->win, i, env->drawstart,
							ft_get_color(env));
			env->drawstart++;
			j++;
		}
		while (j < SCREEN_Y)
			mlx_pixel_put(env->mlx, env->win, i, j++, RGB_FLOOR);
		i++;
	}
}

int		expose_hook(t_env *env)
{
	draw(env);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(1);
	if (keycode == 119)
		move_up(env);
	if (keycode == 115)
		move_down(env);
	if (keycode == 97)
		move_left(env);
	if (keycode == 100)
		move_right(env);
	if (keycode == 113)
	{
		if (env->speed < SPEED_MAX)
			env->speed += 0.25;
	}
	if (keycode == 101)
	{
		if (env->speed > SPEED_MIN)
			env->speed -= 0.25;
	}
	draw(env);
	return (0);
}

int		main(void)
{
	t_env	env;

	ft_init_map(&env);
	return (0);
}
