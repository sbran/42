/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:49:14 by sbran             #+#    #+#             */
/*   Updated: 2014/06/23 22:12:46 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include "../Lib/includes/libft.h"

int			main(int ac)
{
	//t_coord	*coords;
	//t_pipe	*pipes;
	int		i;
	char	*buff;
	char	**tab;

	i = 0;
	if (ac == 1)
	{
		tab = (char **)malloc(sizeof(char *) * 42);
		while (ft_get_next_line(0, &buff))
		{
			tab[i] = (char *)malloc(sizeof(char) * ft_strlen(buff) + 1);
			ft_strcpy(tab[i++], buff);
		}
		//ft_parser(buff, coords, pipes);
		i = 0;
		while (tab[i])
			printf("%s\n", tab[i++]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
