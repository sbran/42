/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 21:24:10 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:04:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = (char *)malloc(sizeof(tmp) * ft_strlen(s));
	if (!tmp && !f)
		return (NULL);
	while (s[count])
	{
		tmp[count] = f(count, (char)s[count]);
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}
