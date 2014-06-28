/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:46:22 by sbran             #+#    #+#             */
/*   Updated: 2013/11/21 18:30:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dest_tmp;
	char	*src_tmp;

	dest_tmp = dest;
	src_tmp = (char *)src;
	if (src != dest)
	{
		if (src > dest)
		{
			while (size--)
				*dest_tmp++ = *src_tmp++;
		}
		else
		{
			dest_tmp += size - 1;
			src_tmp += size - 1;
			while (size--)
				*dest_tmp-- = *src_tmp--;
		}
	}
	return (dest);
}
