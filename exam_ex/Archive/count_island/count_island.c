/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 19:36:02 by sbran             #+#    #+#             */
/*   Updated: 2014/06/13 19:36:58 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "count_island.h"

char		**ft_search_island(char **tab, int i, int j, int isle)
{
	tab[i][j] = isle;
	if (j < ft_strlen(tab[i]) && tab[i][j + 1] == 'X')
		tab = ft_search_island(tab, i, (j + 1), isle);
	if (tab[i + 1][j] == 'X')
		tab = ft_search_island(tab, (i + 1), j, isle);
	if (j > 0 && tab[i][j - 1] == 'X')
		tab = ft_search_island(tab, i, (j - 1), isle);
	if (i > 0 && tab[i - 1][j] == 'X')
		tab = ft_search_island(tab, (i - 1), j, isle);
	return (tab);
}

char		**ft_count_island(char **tab, int len_tab, int isle)
{
	int		i;
	int		j;

	i = 0;
	while (i <= len_tab)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'X')
			{
				if (isle > 57)
					return (NULL);
				tab[i][j] = isle;
				tab = ft_search_island(tab, i, j, isle);
				isle++;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

char		*ft_read(char *buff, int fd, int *len_tab, int *len_str)
{
	int		i;
	int		len_tmp;

	i = 0;
	*len_tab = 1;
	len_tmp = 0;
	while (read(fd, &buff[i], 1) > 0)
	{
		if (buff[i] != 'X' && buff[i] != '.' && buff[i] != '\n')
			return (NULL);
		if (buff[i] == '\n')
		{
			if (*len_tab < 2)
				*len_str = i;
			*len_tab = *len_tab + 1;
			if (*len_str != len_tmp)
				return (NULL);
			len_tmp = -1;
		}
		len_tmp++;
		i++;
	}
	if (buff[i - 1] == '\n')
		return (NULL);
	return (buff);
}

int			ft_island(char *file)
{
	int			fd;
	char		*buff;
	int			len_str;
	int			len_tab;
	char		**tab;

	tab = NULL;
	buff = (char *)malloc(sizeof(char) * 424242);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	if ((buff = ft_read(buff, fd, &len_tab, &len_str)) == NULL)
		return (-1);
	tab = ft_malloc(tab, len_str, len_tab);
	tab = ft_strplit(tab, buff, '\n');
	if ((tab = ft_count_island(tab, len_tab, 48)) == NULL)
		return (-1);
	ft_print_tab(tab, len_tab);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_island(av[1]) == -1)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (42);
}
