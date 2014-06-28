/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:02:25 by sbran             #+#    #+#             */
/*   Updated: 2014/05/16 20:16:32 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RGB_SKY 0x399EF6
# define RGB_FLOOR 0xBBACAC
# define RGB_WALL_N 0xAEEE00
# define RGB_WALL_E 0x480000
# define RGB_WALL_O 0x19003F
# define RGB_WALL_S 0xF6CA39
# define RGB_ITEM 0x56739A
# define SCREEN_X 800.0
# define SCREEN_Y 600.0
# define WALL 64.0
# define ANGCHVI 60.0
# define SPEED_MIN 0.25
# define SPEED_MAX 2.0

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct		s_env
{
	int				argc;
	char			**argv;
	int				nbr_line;
	int				nbr_col;
	int				fd;
	char			*line;
	int				**tab;
	void			*mlx;
	void			*win;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			walldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineh;
	int				drawstart;
	int				drawend;
	double			camerax;
	double			posx;
	double			posy;
	double			dirx;
	double			olddirx;
	double			diry;
	double			planex;
    double          oldplanex;
	double			oldplaney;
	double			planey;
	double			distx;
	double			disty;
    int             level;
    char            levelT[9];
    int             endx;
    int             endy;
    double          speed;
}					t_env;

void                ft_init_map(t_env *env);
void				init(t_env *env, int i);
int                 expose_hook(t_env *env);
int                 key_hook(int keycode, t_env *env);

int					check_hit(t_env *env);
void				calc_ray(t_env *env);
void				calc_draw(t_env *env);
void				move_up(t_env *env);
void				move_down(t_env *env);
void				move_left(t_env *env);
void				move_right(t_env *env);
void				ft_stock_value(t_env *env, char *argv);
void				ft_nbr_line_col(t_env *env, char *argv);
void                ft_next_level(t_env *env);
int                 hit_end(t_env *env);

#endif
