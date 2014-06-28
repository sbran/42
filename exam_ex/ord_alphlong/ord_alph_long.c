/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alph_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:20:08 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/19 23:02:52 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ord_alph_long.h"

void		ft_swap(char **tab, int i)
{
	char	*tmp;

	tmp = tab[i - 1];
	tab[i - 1] = tab[i];
	tab[i] = tmp;
}

void		ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (tab[i])
	{
		j = i;
		l = k;
		while ((j > 0 && ft_strlen(tab[j]) < ft_strlen(tab[j - 1]))
				|| (j > 0 && ft_strlen(tab[l]) == ft_strlen(tab[l - 1])
					&& ft_strcmp_minor(tab[l], tab[l - 1]) < 0))
		{
			ft_swap(tab, j);
			--j;
			--l;
		}
		++i;
		++k;
	}
}

void		ord_alph_long(char *str)
{
	char	**tab;

	tab = ft_strsplit_oal(str);
	ft_sort_tab(tab);
	ft_print_tab(tab);
}
