/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/01 19:06:29 by sbran             #+#    #+#             */
/*   Updated: 2014/07/01 19:07:25 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "grimly.h"

void	ft_init_coord(t_infos *infos, char buff, int i, int j)
{
	if (buff == infos->enter)
	{
		infos->enter_i = i;
		infos->enter_j = j;
	}
	else if (buff == infos->exit)
	{
		//printf("i = %d\tj = %d\n\n\n", i, j);
		infos->exit_i = i;
		infos->exit_j = j;
	}
}

char	**ft_right(char **map, int i, int j, t_infos *infos)
{
	if (!ft_check_exit(map, *infos, i, j))
		map[i][j] = infos->empty;
	else
	{
		if (map[i][j] != infos->enter)
			map[i][j] = infos->path;
		ft_print_map(map, *infos, 0);
	}
	//printf("test RIGHT; i = %d\n", i);
	infos->ln_path++;
	if (map[i][j] != infos->enter)
		map[i][j] = infos->path;
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos->empty)
		map = ft_right(map, i, (j + 1), infos);
	if (i < ft_strlen(map[2]) && map[i + 1][j] == infos->empty)
		map = ft_right(map, (i + 1), j, infos);
	if (j > 0 && map[i][j - 1] == infos->empty)
		map = ft_right(map, i, (j - 1), infos);
	if (i > 0 && map[i - 1][j] == infos->empty)
		map = ft_right(map, (i - 1), j, infos);
	return (map);
}

char	**ft_left(char **map, int i, int j, t_infos *infos)
{
	if (!ft_check_exit(map, *infos, i, j))
		map[i][j] = infos->empty;
	else
	{
		if (map[i][j] != infos->enter)
			map[i][j] = infos->path;
		ft_print_map(map, *infos, 0);
	}
	infos->ln_path++;
	if (map[i][j] != infos->enter)
		map[i][j] = infos->path;
	if (j > 0 && map[i][j - 1] == infos->empty)
		map = ft_left(map, i, (j - 1), infos);
	if (i > 0 && map[i - 1][j] == infos->empty)
		map = ft_left(map, (i - 1), j, infos);
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos->empty)
		map = ft_left(map, i, (j + 1), infos);
	if (map[i + 1][j] == infos->empty)
		map = ft_left(map, (i + 1), j, infos);
	return (map);
}

char	**ft_down(char **map, int i, int j, t_infos *infos)
{
	if (!ft_check_exit(map, *infos, i, j))
		map[i][j] = infos->empty;
	else
	{
		if (map[i][j] != infos->enter)
			map[i][j] = infos->path;
		ft_print_map(map, *infos, 0);
	}
	infos->ln_path++;
	if (map[i][j] != infos->enter)
		map[i][j] = infos->path;
	if (map[i + 1][j] == infos->empty)
		map = ft_down(map, (i + 1), j, infos);
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos->empty)
		map = ft_down(map, i, (j + 1), infos);
	if (i > 0 && map[i - 1][j] == infos->empty)
		map = ft_down(map, (i - 1), j, infos);
	if (j > 0 && map[i][j - 1] == infos->empty)
		map = ft_down(map, i, (j - 1), infos);
	return (map);
}

char	**ft_up(char **map, int i, int j, t_infos *infos)
{
	if (!ft_check_exit(map, *infos, i, j))
		map[i][j] = infos->empty;
	else
	{
		if (map[i][j] != infos->enter)
			map[i][j] = infos->path;
		ft_print_map(map, *infos, 0);
	}
	infos->ln_path++;
	if (map[i][j] != infos->enter)
		map[i][j] = infos->path;
	if (i > 0 && map[i - 1][j] == infos->empty)
		map = ft_up(map, (i - 1), j, infos);
	if (j > 0 && map[i][j - 1] == infos->empty)
		map = ft_up(map, i, (j - 1), infos);
	if (j < ft_strlen(map[2]) && map[i][j + 1] == infos->empty)
		map = ft_up(map, i, (j + 1), infos);
	if (map[i + 1][j] == infos->empty)
		map = ft_up(map, (i + 1), j, infos);
	return (map);
}