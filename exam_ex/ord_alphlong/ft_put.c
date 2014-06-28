/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 22:06:27 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/19 22:33:49 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ord_alph_long.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_strcmp_minor(char *s1, char *s2)
{
	int		i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if (MIN(s1[i]) != MIN(s2[i]))
			return (MIN(s1[i]) - MIN(s2[i]));
		++i;
	}
	return (0);
}

void		ft_print_tab(char **tab)
{
	size_t	i;

	i = 0;
	while(tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i] && tab[i + 1] && ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
			ft_putchar(' ');
		else
			ft_putchar('\n');
		++i;
	}
}