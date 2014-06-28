/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:51:19 by sbran             #+#    #+#             */
/*   Updated: 2013/11/22 17:51:20 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	
	tmp = (char *)s + ft_strlen((char *)s);
	while (*tmp != (char)c && s)
	{
		if (tmp == s)
			return (0);
		tmp--;
	}
	return (tmp);
}
