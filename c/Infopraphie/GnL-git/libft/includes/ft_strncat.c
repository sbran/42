/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:44:31 by sbran             #+#    #+#             */
/*   Updated: 2013/11/29 17:44:38 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
    size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
    	i++;
	while (j < n && s2[j] != '\0')
	{
    	s1[i] = s2[j];
    	i++;
    	j++;
	}
	j++;
	s1[i] = '\0';
	return (s1);
}
