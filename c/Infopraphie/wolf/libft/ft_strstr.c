/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:00:14 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:05:44 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)))
			s1++;
		else
			return ((char *)s1);
	}
	return (NULL);
}
