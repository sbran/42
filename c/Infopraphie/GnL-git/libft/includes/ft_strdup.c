/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:09:15 by sbran             #+#    #+#             */
/*   Updated: 2013/11/20 11:42:21 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
    char	*dup;
	char	*cpy_str;

	cpy_str = (char *)str;
	dup = (char *)malloc(ft_strlen(cpy_str) + 1);
	ft_strcpy(dup, str);
	return (dup);
}
