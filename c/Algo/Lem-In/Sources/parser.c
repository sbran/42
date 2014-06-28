/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:57:56 by sbran             #+#    #+#             */
/*   Updated: 2014/06/23 23:03:14 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../Includes/lemin.h"

t_coord		*ft_add_coord(t_coord *coords, char *args)
{
	t_coord	*tmp;
	int		len_name;
	int		i;
	int		j;
	char	tmp_coord[8];

	tmp = coords;
	len_name = 0;
	i = 0;
	while (args[len_name] != ' ')
		len_name++;
	tmp->name = (char *)malloc(sizeof(char) * len_name + 1);
	while (args[i] != '\n' && args[i] != '\0')
	{
		while (args[i] != ' ')
		{
			j = 0;
			if (!tmp->name && args[i] != ' ')
			{
				while (args[i] != ' ')
					tmp->name[j++] = args[i++];
			}
			if (!tmp->coord_x && args[i] != ' ')
			{
				while (args[i] != ' ')
					tmp_coord[j++] = args[i++];
				tmp->coord_x = ft_atoi(tmp_coord);
			}
			if (!tmp->coord_y && args[i] != ' ')
			{
				while (args[i] != ' ')
					tmp_coord[j++] = args[i++];
				tmp->coord_y = ft_atoi(tmp_coord);
			}
		}
		i++;
	}
}

t_pipe		*ft_add_pipe(t_pipe *pipes, char *args)
{
	t_pipe	*tmp;
	int		len_name;
	int		i;
	int		j;
	char	tmp_pipe[8];

	tmp = pipes;
	len_name = 0;
	i = 0;
	while (args[len_enter] != '-')
		len_enter++;
	len_enter++;
	tmp->enter = (char *)malloc(sizeof(char) * len_enter);
	len_exit = 0;
	while (args[len_enter] != '\n' && args[len_enter] != '\0')
		len_exit++;
	tmp->exit = (char *)malloc(sizeof(char) * len_exit + 1);
	while (args[i] != '\n' && args[i] != '\0')
	{
		while (args[i] != '-')
		{
			j = 0;
			if (!tmp->enter && args[i] != '-')
			{
				while (args[i] != '-')
					tmp->enter[j++] = args[i++];
			}
			if (!tmp->exit && args[i] != '-')
			{
				while (args[i] != '-')
					tmp->exit[j++] = args[i++];
			}
		}
		i++;
	}

}

void		ft_parser(char *args, t_coord *coords, t_pipe *pipes)
{
	int		i;
	int		tmp;

	i = 0;
	while (args[i] != '\0')
	{
		while (args[i] != '\0' && args[i] != '\n')
		{
			tmp = i;
			if (args[i] == '#')
			{
				while (args[i] != '\0' && args[i] != '\n')
					i++;
			}
			else
			{
				while (args[tmp] != ' ' && args[tmp] != '-' &&
					args[tmp] != '\n')
					tmp++;
				if (args[tmp] == ' ')
				{
					coords = ft_add_coord(coords, &args[i]);
					coords = coords->next;
				}
				else
				{
					pipes = ft_add_pipe(pipes, &args[i]);
					pipes = pipes->next;
				}
			}
			i++;
		}
		i++;
	}
}
