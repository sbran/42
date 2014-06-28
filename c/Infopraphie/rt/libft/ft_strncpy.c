/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:30:57 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:05:07 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (n && s1[i] && s2[i])
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	while (n)
	{
		s1[i] = '\0';
		i++;
		n--;
	}
	return (s1);
}
