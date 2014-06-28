/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:00:04 by sbran             #+#    #+#             */
/*   Updated: 2014/05/17 02:10:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_init_map(t_env *env)
{
	ft_next_level(env);
	ft_nbr_line_col(env, env->levelT);
	ft_stock_value(env, env->levelT);
	env->posx = 2;
	env->posy = 2;
	env->dirx = 1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->speed = 0.25;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SCREEN_X, SCREEN_Y, "wolf3d");
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_hook(env->win, 2, 1, key_hook, env);
	mlx_loop(env->mlx);
}

void		ft_stock_value(t_env *env, char *argv)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env->tab = (int **)malloc(sizeof(int *) * (env->nbr_line + 1));
	env->tab[env->nbr_line] = '\0';
	while (i < env->nbr_line)
	{
		env->tab[i] = (int *)malloc(sizeof(int) * (env->nbr_col + 1));
		env->tab[i][env->nbr_col] = '\0';
		i++;
	}
	env->fd = open(argv, O_RDONLY);
	while (ft_get_next_line(env->fd, &env->line))
	{
		i = 0;
		tmp = ft_strsplit(env->line, ' ');
		while (i++ < env->nbr_col)
			env->tab[j][i - 1] = ft_atoi(tmp[i - 1]);
		j++;
	}
}

void		check_tmp(t_env *env, char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != '\0')
	{
		ft_putchar(tmp[i]);
		if (tmp[i] == '3')
		{
			env->endx = env->nbr_line;
			env->endy = (i + 1) / 2;
		}
		i++;
	}
	ft_putchar('\n');
}

void		ft_nbr_line_col(t_env *env, char *map)
{
	int		i;
	char	**tmp;

	env->nbr_line = 0;
	env->nbr_col = 0;
	i = 0;
	env->fd = open(map, O_RDONLY);
	while (ft_get_next_line(env->fd, &env->line))
	{
		tmp = ft_strsplit(env->line, ' ');
		check_tmp(env, env->line);
		while (tmp[i])
			i++;
		env->nbr_line++;
	}
	env->nbr_col = i;
	ft_putnbr(i);
}
