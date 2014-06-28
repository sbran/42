/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 20:04:36 by sbran             #+#    #+#             */
/*   Updated: 2014/06/13 20:04:40 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		**ft_strplit(char **tab, char *buff, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (buff[i] != '\0')
	{
		j = 0;
		while (buff[i] != c && buff[i] != '\0')
		{
			tab[k][j] = buff[i];
			i++;
			j++;
		}
		if (buff[i] == c)
			tab[k][j] = '\0';
		k++;
		i++;
	}
	buff[i - 1] = '\0';
	return (tab);
}

char		**ft_malloc(char **tab, int len_str, int len_tab)
{
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * len_tab + 1);
	while (i <= len_tab)
		tab[i++] = (char *)malloc(sizeof(char) * len_str);
	return (tab);
}

void		ft_print_tab(char **tab, int len_tab)
{
	int		i;

	i = 0;
	while (i < len_tab)
		ft_putendl(tab[i++]);
}
