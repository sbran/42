/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:22:56 by sbran             #+#    #+#             */
/*   Updated: 2014/05/17 01:05:00 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hit_end(t_env *env)
{
	if (((int)env->posx == env->endx && ((int)env->posy + 1) == env->endy) ||
		((int)env->posx == env->endx && ((int)env->posy - 1) == env->endy) ||
		((int)env->posy == env->endy && ((int)env->posx + 1) == env->endx) ||
		((int)env->posy == env->endy && ((int)env->posx - 1) == env->endx))
	{
		ft_putendl("test");
		return (1);
	}
	return (0);
}

void	init(t_env *env, int i)
{
	env->camerax = 2 * i / (double)SCREEN_X - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry) /
	(env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx) /
	(env->raydiry * env->raydiry));
	env->hit = 0;
}

int		check_hit(t_env *env)
{
	while (!env->hit)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			if (env->raydirx > 0)
				env->side = 0.0;
			else
				env->side = 1.0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			if (env->raydiry < 0)
				env->side = 2.0;
			else
				env->side = 3.0;
		}
		if (env->tab[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
	return (env->tab[env->mapx][env->mapy] + 48);
}

void	calc_ray(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

void	calc_draw(t_env *env)
{
	if (env->side < 2.0)
		env->walldist = fabs((env->mapx - env->rayposx +
		(1 - env->stepx) / 2) / env->raydirx);
	else
		env->walldist = fabs((env->mapy - env->rayposy +
		(1 - env->stepy) / 2) / env->raydiry);
	env->lineh = abs((int)(SCREEN_Y / env->walldist));
	env->drawstart = -(env->lineh) / 2 + SCREEN_Y / 2;
	env->drawend = env->lineh / 2 + SCREEN_Y / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	if (env->drawend >= SCREEN_Y)
		env->drawend = SCREEN_Y - 1;
}
