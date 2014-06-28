/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 21:40:18 by sraccah           #+#    #+#             */
/*   Updated: 2013/12/31 21:40:18 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void				ft_putendl_fd(char const *str, int fd)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*bkp;

	if (s1 != 0 && s2 != 0)
	{
		bkp = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
		if (bkp != 0)
		{
			bkp = ft_strcat(ft_strcat(bkp, s1), s2);
			return (bkp);
		}
	}
	return (0);
}

size_t				ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
