/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:12:18 by sbran             #+#    #+#             */
/*   Updated: 2013/12/03 14:14:55 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_NEXT_LINE_H
# define NEXT_NEXT_LINE_H
# define BUFF_SIZE 10

# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h> /* A enlever avant le rendu !!! */

int		get_next_line(int fd, char **line);

#endif /* !NEXT_NEXT_LINE_H */
