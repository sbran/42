/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:41:21 by sbran             #+#    #+#             */
/*   Updated: 2013/11/21 17:55:42 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*cpy_dest;
	char	*cpy_src;
	size_t	i;

	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	i = 0;
	while (i < size)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}
