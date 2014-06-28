/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:32:16 by sbran             #+#    #+#             */
/*   Updated: 2014/01/26 18:03:50 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	count;

	count = 0;
	if (s && f)
	{
		while (s[count])
		{
			f(&s[count]);
			count++;
		}
	}
}
