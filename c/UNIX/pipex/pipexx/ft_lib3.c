/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 21:40:27 by sraccah           #+#    #+#             */
/*   Updated: 2013/12/31 21:40:27 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void				ft_putendl(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void				ft_bzero(void *s, size_t n)
{	
	char			*ps;
	unsigned int	i;

	ps = (char *)s;
	i = 0;
	while (i < n)
	{
		*ps++ = '\0';
		i++;
	}
}

void				ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void    			ft_putchar(char c)
{
	write(1, &c, 1);
}

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str)
		str[len] = '\0';
	else
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
