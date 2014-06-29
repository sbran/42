/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 13:29:07 by sbran             #+#    #+#             */
/*   Updated: 2014/06/29 13:29:12 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "grimly.h"

void	check_size(char *buff, t_infos *infos)
{
	int		i;
	int		j;
	char	*line_str;
	char	*col_str;

	i = -1;
	j = 0;
	line_str = (char *)malloc(sizeof(*line_str) * 10);
	col_str = (char *)malloc(sizeof(*col_str) * 10);
	while (buff[++i] != '\0' && buff[i] >= '0' && buff[i] <= '9')
		line_str[i] = buff[i];
	while (buff[++i] != '\0' && buff[i] >= '0' && buff[i] <= '9')
		col_str[j++] = buff[i];
	infos->line = atoi(line_str);
	infos->col = atoi(col_str);
	infos->full = buff[i];
	while (buff[i] != '\0')
		i++;
}

char	*ft_init_arg_file(int fd, t_infos *infos)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char *)malloc(sizeof(*buff) * 20);
	while ((read(fd, &buff[i], 1)) > 0)
	{
		if (buff[i] == '\n')
			break ;
		i++;
	}
	infos->empty = buff[i - 4];
	infos->path = buff[i - 3];
	infos->enter = buff[i - 2];
	infos->exit = buff[i - 1];
	return (buff);
}

char	*ft_init_arg(t_infos *infos)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char *)malloc(sizeof(*buff) * 20);
	while ((read(0, &buff[i], 1)) > 0)
	{
		if (buff[i] == '\n')
			break ;
		i++;
	}
	infos->empty = buff[i - 4];
	infos->path = buff[i - 3];
	infos->enter = buff[i - 2];
	infos->exit = buff[i - 1];
	return (buff);
}

char	**ft_read(int ac, char **av, t_infos infos)
{
	char	buff;
	char	**map;
	int		i;
	int		j;
	int		fd;

	i = 0;
	map = NULL;
	fd = open(av[1], O_RDONLY);
	map = ft_malloc(map, infos.line, infos.col);
	ac < 2 ? fd = 0 : fd;
	j = 0;
	while ((read(fd, &buff, 1)) > 0)
	{
		map[i][j++] = buff;
		if (buff == '\n')
		{
			map[i++][j - 1] = '\0';
			j = 0;
		}
	}
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**map;
	t_infos	infos;

	infos.ln_path = 0;
	if (ac < 2)
		check_size(ft_init_arg(&infos), &infos);
	else
	{
		fd = open(av[1], O_RDONLY);
		check_size(ft_init_arg_file(fd, &infos), &infos);
	}
	map = ft_read(ac, av, infos);
	ft_labyrinthe(&map[1], infos);
	return (0);
}
