/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:57:43 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/19 22:32:36 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alph_long.h"

int			main(int ac, char **av)
{
	if (ac > 1)
		ord_alph_long(av[1]);
	else
		ft_putchar('\n');
	return (0);
}