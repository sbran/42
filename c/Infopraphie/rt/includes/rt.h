/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/24 18:00:35 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define SCREEN_X 800
# define SCREEN_Y 600

# include <mlx.h>
# include "libft.h"

/*
** Lists and Structures
*/

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
	double			r;
	int				color;
	struct	s_coord	*next;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	char			*line;
	char			**buff;
	t_coord			cam;
	t_coord			dir;
	t_coord			*sphere;
	t_coord			inter;
	t_coord			const_light;
	t_coord			light;
}					t_env;

typedef union		u_color
{
	int				c;
	unsigned char 	rgb[4];
}					t_color;

/*
** Mlx
*/

int				ft_expose_hook(t_env *env);
int				ft_key_hook(int keycode, t_env *env);
int				ft_mouse_hook(int button, int x, int y);

/*
** Init
*/

void			init_struct(t_env *env);
void			init_camera(t_env *env, char **buff);
void			init_light(t_env *env, char **buff);
void			init_sphere(t_env *env, char **buff);

/*
** ft_math
*/

double			touch_sphere(t_env *env, t_coord *point);
double			vector_add(t_coord *p1, t_coord *p2);
int				diffuse(t_env *env, double dist, int color);

#endif /* !RT_H */
