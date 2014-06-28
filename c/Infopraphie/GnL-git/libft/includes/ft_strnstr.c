/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:51:42 by sbran             #+#    #+#             */
/*   Updated: 2013/11/22 17:51:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str;
	char	*str2;
	size_t	len1;
	size_t	len2;
	int	k;

	str = (char *)s1;
	str2 = (char *)s2;
	len2 = ft_strlen(str2);
	len1 = ft_strlen(str);
	if (len2 == 0)
		return (str);
	if ((k = n - len2 + 1) > (int)len1)
		k = len1 - len2 + 1;
	if (n > len2)
		n = len2;
	while (k > 0)
	{
		if (ft_strncmp(str, str2, n) == 0)
			return (str);
		str++;
		k--;
	}
	return (0);
}
