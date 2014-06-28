/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:38:59 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/23 18:23:02 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_struct(t_env *env)
{
	env->sphere = NULL;
	env->cam.next = NULL;
	env->dir.next = NULL;
	env->inter.next = NULL;
	env->const_light.next = NULL;
	env->light.next = NULL;
}

void	init_camera(t_env *env, char **buff)
{
	env->cam.x = ft_atoi(buff[1]);
	env->cam.y = ft_atoi(buff[2]);
	env->cam.z = ft_atoi(buff[3]);
	env->dir.x = ft_atoi(buff[1]);
	env->dir.y = ft_atoi(buff[2]);
	env->dir.z = -(ft_atoi(buff[3]));
}

void	init_light(t_env *env, char **buff)
{
	env->const_light.x = ft_atoi(buff[1]);
	env->const_light.y = ft_atoi(buff[2]);
	env->const_light.z = ft_atoi(buff[3]);
}

void	init_sphere(t_env *env, char **buff)
{
	t_coord		*point;
	t_coord		*tmp;

	if (!(point = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	point->next = NULL;
	point->x = ft_atoi(buff[1]);
	point->y = ft_atoi(buff[2]);
	point->z = ft_atoi(buff[3]);
	point->r = ft_atoi(buff[4]);
	point->color = ft_atoi(buff[5]);
	if (!(tmp = env->sphere))
		env->sphere = point;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = point;
	}
}
