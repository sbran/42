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
	if (!ft_check_exit(map, *infos, i, j))
	{
		map[i][j] = infos->empty;
	}
	else
	{
		map[i][j] = infos->path;
		ft_print_map(map, *infos, 0);
	}
	infos->ln_path++;
	if (map[i][j] != infos->enter)
		map[i][j] = infos->path;
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos->empty)
		map = ft_search_path(map, i, (j + 1), infos);
	if (i > 0 && map[i - 1][j] == infos->empty)
		map = ft_search_path(map, (i - 1), j, infos);
	if (map[i + 1][j] == infos->empty)
		map = ft_search_path(map, (i + 1), j, infos);
	if (j > 0 && map[i][j - 1] == infos->empty)
		map = ft_search_path(map, i, (j - 1), infos);
	return (map);
}

void		ft_labyrinthe(char **map, t_infos infos)
{
	int		i;
	int		j;

	i = 0;
	while (i <= infos.col)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == infos.enter)
				map = ft_search_path(map, i, j, &infos);
			j++;
		}
		i++;
	}
}
