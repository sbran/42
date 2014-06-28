/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:49:01 by sbran             #+#    #+#             */
/*   Updated: 2013/11/22 17:49:53 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (size && *(dest + dest_len))
	{
		dest_len++;
		size--;
	}
	if (size == 0)
		return (dest_len + ft_strlen((char *)src));
	while (*src)
	{
		if (size != 1)
		{
			*(dest + dest_len) = *src;
			dest++;
			size--;
		}
		src++;
		src_len++;
	}
	*(dest + dest_len) = '\0';
	return (dest_len + src_len);
}
