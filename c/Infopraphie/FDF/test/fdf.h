/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 19:34:17 by atouzeau          #+#    #+#             */
/*   Updated: 2014/04/24 19:35:39 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH		1000
# define HEIGHT		700
# define PADDING	30
# define CTE1		0.8
# define CTE2		0.8

# define BUFF_SIZE	512

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct 	s_env
{
	void		*ptr;
	void		*win;
	char		**av;
	int			nbr_line;
	int			nbr_col;
	int			fd;
	char		*line;
	int			*tab;
}				t_env;

char	*ft_strdup_gnl(const char *str);
int		ft_get_next_line(const int fd, char **line);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
void    ft_draw_line(int w1, int h1, int w2, int h2, t_env env);
void    ft_draw_line2(int w1, int h1, int w2, int h2, t_env env);
#endif