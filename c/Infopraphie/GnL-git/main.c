/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:40:34 by sbran             #+#    #+#             */
/*   Updated: 2013/12/02 15:41:25 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main()
{
	char	*line;
	char	file[50];
	int		fd;

	printf("What file do you want to use ? ");
	scanf("%s", file);
	ft_strcat(file, ".txt");
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error to open file");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	if (close(fd) == -1)
	{
		ft_putendl("Error to close file");
		return (1);
	}
	return (0);
}

/*int			main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[ac - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error to open file");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf(" FD : %d\n", fd);
		ft_putendl(line);
	}
	printf(" FD : %d\n", fd);
	if (close(fd) == -1)
	{
		ft_putendl("Error to close file");
		return (1);
	}
	return (0);
}*/
