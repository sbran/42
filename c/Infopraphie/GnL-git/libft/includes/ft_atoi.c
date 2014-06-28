/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:02:08 by sbran             #+#    #+#             */
/*   Updated: 2013/11/20 16:55:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *p)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while(*p == ' ' || *p == '\t' || *p == '\n' || 
		*p == '\f' || *p == '\r' || *p == '\v')
		p++;
	if(*p == '-' )
	{
		sign *= -1;
		p++;
	}
	else if(*p == '+')
		p++;
	if(!ft_isdigit(*p)) return 0;
	while(1)
	{
		res += *p - '0';
		p++;
		if(!ft_isdigit(*p))
			return (sign * res);
		res = res * 10;
	}
	return (sign * res);
}
