/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:44:05 by sbran             #+#    #+#             */
/*   Updated: 2013/11/21 18:17:38 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int car, size_t size)
{
	char	*cpy_dest;
	char	*cpy_src;

	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	if (size == 0)
		return (0);
	while (size)
	{
		*cpy_dest = *cpy_src;
		if (*cpy_src == car)
		{
			cpy_dest++;
			return (cpy_dest);
		}
		cpy_src++;
		cpy_dest++;
		size--;
	}
	return (0);
}
