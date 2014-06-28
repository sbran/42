/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 17:31:55 by exam              #+#    #+#             */
/*   Updated: 2014/02/20 18:22:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int 		ft_strcmp(char *s1, char *s2)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}


void	ft_rsort(char **tab, int nb)
{
	int		i;
	int		j;
	char	*tmp;
	int		tmp_count;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * 4242);
	while (i < nb)
	{
		tmp_count = i;
		while (i < nb && i > 0 && (ft_strcmp(tab[i], tab[i - 1]) < 0))
		{
			tmp = ft_strcpy(tmp, tab[i - 1]);
			tab[i - 1] = ft_strcpy(tab[i - 1], tab[i]);
			tab[i] = ft_strcpy(tab[i], tmp);
			i--;
		}
		i = tmp_count;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putendl(tab[i]);
		i--;
	}
	free(tmp);
}

int		main(int ac, char **av)
{
	char	**tab_str;
	int		i;

	i = 0;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		tab_str = (char **)malloc(sizeof(char *) * (ac - 1));
		while (i < ac - 1)
		{
			tab_str[i] = (char *)malloc(sizeof(char) * ft_strlen(av[i + 1]) + 1);
			tab_str[i] = ft_strcpy(tab_str[i], av[i + 1]);
			i++;
		}
		ft_rsort(tab_str, i);
		i = 0;
		while (i < ac - 1)
			free(tab_str[i++]);
	}
	return (0);
}
