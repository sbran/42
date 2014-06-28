/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:10:24 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:05:33 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen((char *)s);
	tmp = (char *)s;
	while (*tmp)
		tmp++;
	while (i >= 0)
	{
		if (*tmp == c)
			return (tmp);
		tmp--;
		i--;
	}
	return (NULL);
}
