/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:51:27 by sbran             #+#    #+#             */
/*   Updated: 2013/11/22 17:51:29 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str;
	char	*str2;
	size_t	i;

	str = (char *)s1;
	str2 = (char *)s2;
	i = ft_strlen(str2);
	if (!*str2)
		return (str);
	else if (!str2)
		return (0);
	while (*str)
	{
		if (ft_strncmp(str, str2, i) == 0)
			return (str);
		str++;
	}
	return (0);
}
