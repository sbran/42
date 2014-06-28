/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 10:44:35 by sbran             #+#    #+#             */
/*   Updated: 2014/05/18 10:44:42 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_print_error(char *error)
{
	write(2, "\033[0;31;1m", 9);
	write(2, error, ft_strlen((const char *)error));
	write(2, "\033[0m", 4);
	write(2, "\n", 1);
}

void		ft_is_not_found(char *cmd)
{
	write(2, "\033[0;31;1m", 9);
	write(2, "minishell2: command not found: ", 24);
	write(2, cmd, ft_strlen((const char *)cmd));
	write(2, "\033[0m", 4);
	write(2, "\n", 1);
}
