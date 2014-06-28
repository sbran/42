/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:44:59 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:05:50 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str)
		str[len] = '\0';
	else
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
