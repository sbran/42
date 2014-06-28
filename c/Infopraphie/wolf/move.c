/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:00:00 by sbran             #+#    #+#             */
/*   Updated: 2014/05/16 20:42:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	ft_next_level(t_env *env)
{
	if (env->level > 10 || env->level == 0)
		env->level = 1;
	ft_strcpy(env->levelT, "map");
	ft_strcat(env->levelT, ft_itoa(env->level));
	ft_strcat(env->levelT, ".w3d");
	env->level += 1;
	ft_putendl(env->levelT);
}

void	move_up(t_env *env)
{
	printf("%lf\n", env->speed);
	if (env->tab[(int)(env->posx +
		(env->dirx * env->speed))][(int)(env->posy)] == 0)
		env->posx += (env->dirx * env->speed);
	if (env->tab[(int)(env->posx)][(int)(env->posy +
		(env->diry * env->speed))] == 0)
		env->posy += (env->diry * env->speed);
	if (hit_end(env) == 1)
		ft_init_map(env);
}

void	move_down(t_env *env)
{
	if (env->tab[(int)(env->posx -
		(env->dirx * env->speed))][(int)(env->posy)] == 0)
		env->posx -= (env->dirx * env->speed);
	if (env->tab[(int)(env->posx)][(int)(env->posy -
		(env->diry * env->speed))] == 0)
		env->posy -= (env->diry * env->speed);
	if (hit_end(env) == 1)
		ft_init_map(env);
}

void	move_left(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(-(0.175000)) - env->diry * sin(-(0.175000));
	env->diry = env->olddirx * sin(-(0.175000)) + env->diry * cos(-(0.175000));
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(-(0.175000)) - env->planey *
					sin(-(0.175000));
	env->planey = env->oldplanex * sin(-(0.175000)) + env->planey *
					cos(-(0.175000));
	if (hit_end(env) == 1)
		ft_init_map(env);
}

void	move_right(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos((0.175000)) - env->diry * sin((0.175000));
	env->diry = env->olddirx * sin((0.175000)) + env->diry * cos((0.175000));
	env->oldplanex = env->planex;
	env->planex = env->planex * cos((0.175000)) - env->planey *
				sin((0.175000));
	env->planey = env->oldplanex * sin((0.175000)) + env->planey *
				cos((0.175000));
	if (hit_end(env) == 1)
		ft_init_map(env);
}
