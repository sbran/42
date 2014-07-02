/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labyrinthe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 15:48:30 by sbran             #+#    #+#             */
/*   Updated: 2014/06/29 15:48:32 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "grimly.h"

void		ft_print_map(char **map, t_infos infos, int i)
{
	while (i < infos.line)
		ft_putendl(map[i++]);
	printf("RESULTAT EN %d COUPS !\n", infos.ln_path);
	exit (0);
}

int			ft_check_exit(char **map, t_infos infos, int i, int j)
{
	if (map[i][j] == infos.enter)
		return (0);
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos.exit)
		return (1);
	if (map[i + 1][j] == infos.exit)
		return (1);
	if (j > 0 && map[i][j - 1] == infos.exit)
		return (1);
	if (i > 0 && map[i - 1][j] == infos.exit)
		return (1);
	return (0);
}

char		**ft_search_path(char **map, int i, int j, t_infos *infos)
{
	int		diff_i;
	int		diff_j;

	if (infos->enter_i >= infos->exit_i)
		diff_i = infos->enter_i - infos->exit_i;
	else
		diff_i = infos->exit_i - infos->enter_i;
	if (infos->enter_j >= infos->exit_j)
		diff_j = infos->enter_j - infos->exit_j;
	else
		diff_j = infos->exit_j - infos->enter_j;
	//printf("diff_i = %d\tdiff j = %d\nenter j = %d\texit j = %d\n\n", diff_i, diff_j, infos->enter_j, infos->exit_j);
	if (diff_i <= diff_j)
	{
		if (infos->enter_j <= infos->exit_j)
		{
			map = ft_right(map, i, j, infos);
		}
		else
			map = ft_left(map, i, j, infos);
	}
	else
	{
		if (infos->enter_i <= infos->exit_i)
		{
			map = ft_down(map, i, j, infos);
		}
		else
			map = ft_up(map, i, j, infos);
	}
	return (map);
}

void		ft_labyrinthe(char **map, t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	//ft_putendl("test");
	while (i <= infos->col)
	{
		//ft_putendl("\ntest WHILE");
		j = 0;
		while (map[i][j] != '\0')
		{
			//printf("i = %d\tj = %d\n", i, j);
			//ft_putendl("test WHILE LINE");
			if (map[i][j] == infos->enter)
				map = ft_search_path(map, i, j, infos);
			j++;
		}
		i++;
	}
}
