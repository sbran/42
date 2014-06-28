/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:39:24 by sbran             #+#    #+#             */
/*   Updated: 2014/05/13 00:40:54 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "infin_mult.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

size_t		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '0')
		i--;
	return (i);
}

char		*ft_strreverse(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0')
		i++;
	i--;
	while (j <= (int)ft_strlen(str))
	{
		res[j] = str[i];
		j++;
		i--;
	}
	res[j] = '\0';
	return (res);
}

char		*ft_strcpy(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(src));
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = src[i];
	return (str);
}

int 		ft_strcmp(char *s1, char *s2)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while ((s1[i] && s2[i]) || j == 1)
	{
		if (s1[i] != s2[i])
			j++;
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (42);
	return (s1[i] - s2[i]);
}

char		*ft_strrmv(char *s1)
{
	int 	i;
	int 	k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	if (s1[i] == '-')
	{
		k = 1;
		i--;
	}
	while (s1[i] == '0')
		i--;
	if (k == 1)
		s1[++i] = '-';
	s1[i + 1] = '\0';
	return (s1);
}

char		*ft_calc_res(char *res, char *add)
{
	char	*tmp_res;
	char	ret;
	char	ret_tmp;
	int		i;

	i = 0;
	ret = 0;
	tmp_res = (char *)malloc(sizeof(char) * ft_strlen(add) + 1);
	while (add[i] && res[i] >= '0' && res[i] <= '9')
	{
		ret_tmp = 0;
		tmp_res[i] = (((res[i] - 48) + ((add[i]) - 48)) % 10) + 48;
		tmp_res[i] += ret;
		if (tmp_res[i] > '9')
		{
			ret_tmp = 1;
			tmp_res[i] -= 10;
		}
		ret = (((res[i] - 48) + (add[i] - 48)) / 10) + ret_tmp;
		i++;
	}
	if (add[i])
	{
		tmp_res[i] = add[i] + ret_tmp + ret;
		if (tmp_res[i] > '9')
		{
			tmp_res[i] -= 10;
			tmp_res[++i] = '1';
		}
	}
	else
		tmp_res[i] = ret_tmp;
	return (tmp_res);
}

int 		ft_strcheck(char *s1, char *s2)
{
	int 	i;
	int 	k;

	i = 0;
	k = 0;
	if (s1[0] == '-' || s1[0] == '+')
		s1[0] = '0';
	if (s2[0] == '-' || s2[0] == '+')
		s2[0] = '0';
	while (s1[i] != '\0')
	{
		if (s1[i] != '0')
			k++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] != '0')
			k++;
		i++;
	}
	if (k >= 2)
		return (0);
	ft_putchar('0');
	return (1);
}

char		*ft_mult(char *val, char *mult)
{
	char	**tab;
	char	*res;
	size_t	len_val;
	size_t	len_mult;
	char	ret;
	char	ret_tmp;
	int		i;
	int		j;
	int		k;
	int		count;
	int		sign;

	i = 0;
	len_val = ft_strlen(val);
	len_mult = ft_strlen(mult);
	tab = (char **)malloc(sizeof(char *) * (len_mult));
	while (i <= (int)len_mult)
	{
		tab[i] = (char *)malloc(sizeof(char) * (len_val + len_mult) + 1);
		i++;
	}
	i = 0;
	res = NULL;
	sign = 1;
	if (val[0] == '-' && mult[0] == '-')
		sign = 1;
	else if (val[0] == '-' || mult[0] == '-')
		sign = -1;
	val = ft_strreverse(val);
	mult = ft_strreverse(mult);
	val = ft_strrmv(val);
	mult = ft_strrmv(mult);
	if (val[ft_strlen(val) - 1] == '-')
		val[ft_strlen(val) - 1] = '\0';
	if (mult[ft_strlen(mult) - 1] == '-')
		mult[ft_strlen(mult) - 1] = '\0';
	while (mult[i] != '\0')
	{
		j = 0;
		k = 0;
		ret = 0;
		count = 0;
		while (val[j] >= '0' && val[j] <= '9')
		{
			ret_tmp = 0;
			while (k < i)
			{
				tab[i][count] = '0';
				k++;
				count++;
			}
			tab[i][count] = (((mult[i] - 48) * ((val[j]) - 48)) % 10) + 48;
			tab[i][count] += ret;
			if (tab[i][count] > '9')
			{
				ret_tmp = 1;
				tab[i][count] -= 10;
			}
			ret = (((mult[i] - 48) * (val[j] - 48)) / 10) + ret_tmp;
			j++;
			count++;
		}
		tab[i][count] = (ret) + 48;
		if (res == NULL)
		{
			res = (char *)malloc(sizeof(char) * (len_val + len_mult) + 1);
			res = ft_strcpy(tab[i]);
		}
		else
			res = ft_calc_res(res, tab[i]);
		i++;
	}
	if (sign == -1)
		res[ft_strlen(res)] = '-';
	return (res);
}

int			main(int ac, char **av)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + ft_strlen(av[2])));
	if (ac == 3 && !ft_strcheck(av[1], av[2]))
	{
		if (ft_strlen(av[1]) <= ft_strlen(av[2]))
			res = ft_mult(av[2], av[1]);
		else
			res = ft_mult(av[1], av[2]);
		res = ft_strrmv(res);
		res = ft_strreverse(res);
		ft_putstr(res);
	}
	ft_putchar('\n');
	return (0);
}
