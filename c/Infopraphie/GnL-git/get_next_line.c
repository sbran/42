/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:38:27 by sbran             #+#    #+#             */
/*   Updated: 2014/04/26 19:52:11 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct	s_getline
{
	int		fd_static;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
}				t_getline;

int		read_buff(int const fd)
{
	int					ret;
	int					i;
	static t_getline	t_gnl;

	ret = 0;
	//*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	//*line[BUFF_SIZE] = '\0';
	t_gnl.fd_static = fd;
	i = 0;
	while ((ret = read(t_gnl.fd_static, t_gnl.buff, BUFF_SIZE)))
	{
		//ft_putendl(t_gnl.buff);
		t_gnl.buff[ret] = '\0';
		t_gnl.tmp = ft_strdup(t_gnl.buff);
		i++;
		if (t_gnl.buff[i] == '\n')
		{
			i++;
			t_gnl.tmp = ft_strdup(&t_gnl.buff[i]);
			return (0);
		}
		//if (t_gnl.tmp)
			//ft_putendl(t_gnl.tmp);
	}
	if (!ret)
		return (-1);

	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_getline	t_gnl;

	t_gnl.fd_static = fd;
	while (read_buff(fd) == 1)
	{
		ft_putendl(t_gnl.tmp);
		realloc(*line, BUFF_SIZE);
		if (t_gnl.tmp)
			ft_strjoin(*line, t_gnl.tmp);
		ft_strjoin(*line, t_gnl.buff);
	}
	//free(*line);
	return (0);
}
