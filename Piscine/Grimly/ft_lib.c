/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 15:17:05 by sbran             #+#    #+#             */
/*   Updated: 2014/06/29 15:17:10 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "grimly.h"

char	**ft_malloc(char **map, int line, int col)
{
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * line + 1);
	while (i <= line)
		map[i++] = (char *)malloc(sizeof(char) * col + 1);
	return (map);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}
