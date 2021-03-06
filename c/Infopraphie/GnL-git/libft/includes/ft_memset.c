/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:20:54 by sbran             #+#    #+#             */
/*   Updated: 2013/11/21 17:49:28 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = str;
	if (!c)
		ft_bzero (str2, n);
	else
		while (n--)
		{
			str2[i] = c;
			i++;
		}
	return (str2);
}
