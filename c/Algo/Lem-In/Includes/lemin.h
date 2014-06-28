/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:26:41 by sbran             #+#    #+#             */
/*   Updated: 2014/06/23 22:12:43 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIM_H
# define LEMIM_H

typedef struct		s_coord
{
	char			*name;
	unsigned int	coord_x;
	unsigned int	coord_y;
	s_coord			*next;
}					t_coord;

typedef struct		s_pipe
{
	char			*enter;
	char			*exit;
	s_pipe			*next;
}					t_pipe;

void				ft_parser(char *args, t_coord *coords, t_pipe *pipes);

#endif
