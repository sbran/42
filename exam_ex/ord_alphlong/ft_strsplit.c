/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 14:49:42 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/20 10:42:51 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ord_alph_long.h"

bool		is_spacetab(char c)
{
	return (c == ' ' || c == '\t');
}

void		ft_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int			nbr_of_word(char *str)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] && is_spacetab(str[i]))
			++i;
		j = i;
		while (str[i] && !is_spacetab(str[i]))
			++i;
		if (i != j)
			++nbr;
	}
	return (nbr);
}

char		**ft_strsplit_oal(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = (char **)malloc(sizeof(*tab) * nbr_of_word(str) + 1);
	while (str[i])
	{
		while (str[i] && is_spacetab(str[i]))
			++i;
		j = i;
		while (str[i] && !is_spacetab(str[i]))
			++i;
		if (i != j)
		{
			tab[k] = (char *)malloc(sizeof(**tab) * (i - j + 1));
			ft_strncpy(tab[k], &str[j], i - j);
			++k;
		}
	}
	tab[k] = NULL;
	return (tab);
}