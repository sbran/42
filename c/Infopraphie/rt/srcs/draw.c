/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:40:39 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/23 18:51:37 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double		touch_sphere(t_env *env, t_coord *point)
{
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	double		det;

	a = (pow(env->dir.x, 2) + (pow(env->dir.y, 2) + (pow(env->dir.z, 2))));
	b = (2 * (env->dir.x * (env->cam.x - point->x)
			+ env->dir.y * (env->cam.y - point->y)
			+ env->dir.z * (env->cam.z - point->z)));
	c = ((pow((env->cam.x - point->x), 2) + pow((env->cam.y - point->y), 2)
		+ pow((env->cam.z - point->z), 2)) - pow(point->r, 2));
	det = ((pow(b, 2)) - (4 * a * c));
	if (det >= 0)
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		if (t1 > 0 && t1 < t2)
			return (t1);
		else if (t2 > 0)
			return (t2);
	}
	return (0);
}

double		vector_add(t_coord *p1, t_coord *p2)
{
	return (p1->x * p2->x + p1->y * p2->y + p1->z * p2->z);
}

int			diffuse(t_env *env, double dist, int color)
{
	double		diffuse;
	t_color		c;

	env->inter.x = env->dir.x * dist + env->cam.x;
	env->inter.y = env->dir.y * dist + env->cam.y;
	env->inter.z = env->dir.z * dist + env->cam.z;
	env->light.x = env->const_light.x;
    env->light.y = env->const_light.y;
    env->light.z = env->const_light.z;
	env->light.x -= env->inter.x;
	env->light.y -= env->inter.y;
	env->light.z -= env->inter.z;
	(diffuse = vector_add(&env->inter, &env->light)
		/ sqrt(vector_add(&env->inter, &env->inter)
			* vector_add(&env->light, &env->light)));
	if (diffuse < 0)
		diffuse = 0;
	c.c = color;
	c.rgb[0] *= diffuse;
	c.rgb[1] *= diffuse;
	c.rgb[2] *= diffuse;
	return (c.c);
}
