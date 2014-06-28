/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:55:22 by sbran             #+#    #+#             */
/*   Updated: 2013/11/21 19:31:12 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while(str[i] && i < size)
	{
		if (str[i] == c)
			return (&((str)[i]));
		i++;
	}
	if (c == 0)
		return (&((str)[i]));
	return (0);
}
