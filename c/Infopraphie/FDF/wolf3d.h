/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:09:35 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/27 01:25:04 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define SKY 0x5EB6DD /*bleu ciel*/
# define FLOOR 0x183152 /*bleu fonce*/
# define WALL_N 0x8FCF3C /*vert*/
# define WALL_E 0xFF00B8 /*rose violet*/
# define WALL_O 0xFF0000 /*rouge*/
# define WALL_S 0xFFF168 /*jaune poussin*/
# define SCREEN_X 800.0
# define SCREEN_Y 600.0
# define WALL 64.0
# define ANGCHVI 60.0

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h> 

# include <stdio.h>

/*
** Lists and Structures
*/

typedef struct 	s_env
{
	void		*ptr;
	void		*win;
	int			ac;
	char		**av;
	int			nbr_line;
	int			nbr_col;
	int			fd;
	char		*line;
	int			**tab;
}				t_env;

typedef struct 	s_point
{
	double 	 	ray_posX;
    double  	ray_posY;
    double  	ray_dirX;
    double  	ray_dirY;
    int     	mapX;
    int     	mapY;
    double  	side_distX;
    double  	side_distY;
    double  	delta_distX;
    double  	delta_distY;
    double  	wall_dist;
    int     	stepX;
    int     	stepY;
    int     	hit;
    int     	side;
    int     	lineH;
    int     	draw_start;
    int     	draw_end;
	double  	cameraX;
    double  	posX;
    double  	posY;
    double  	dirX;
    double  	dirY;
    double  	planeX;
    double  	planeY;
}				t_point;

/*
** Protos
*/

void			ft_draw(t_env *env);
int 			ft_expose_hook(t_env *env);
int 			ft_key_hook(int keycode);
void            ft_stock_value(t_env *env);
void            ft_nbr_line_col(t_env *env);

#endif /* !WOLF3D_H */
