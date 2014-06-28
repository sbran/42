/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:01:36 by sbran             #+#    #+#             */
/*   Updated: 2013/11/22 18:01:37 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (char*)malloc(size * sizeof(*mem));
	if (mem == NULL)
		return (mem);
	ft_bzero((void*)mem, size);
	return ((void*)mem);
}
