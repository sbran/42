/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 13:29:19 by sbran             #+#    #+#             */
/*   Updated: 2014/06/29 13:29:21 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

typedef struct	s_infos
{
	char		empty;
	char		full;
	char		path;
	char		enter;
	char		exit;
	int			line;
	int			col;
	int			ln_path;
	int			enter_i;
	int			enter_j;
	int			exit_i;
	int			exit_j;
}				t_infos;

/*
** LABYRINTHE
*/
void			ft_print_map(char **map, t_infos infos, int i);
int				ft_check_exit(char **map, t_infos infos, int i, int j);
char			**ft_search_path(char **map, int i, int j, t_infos *infos);
void			ft_labyrinthe(char **map, t_infos *infos);

/*
** INIT
*/
void			check_size(char *buff, t_infos *infos);
char			*ft_init_arg_file(int fd, t_infos *infos);
char			*ft_init_arg(t_infos *infos);
void			ft_init_coord(t_infos *infos, char buff, int i, int j);

/*
** MOVE
*/
char			**ft_right(char **map, int i, int j, t_infos *infos);
char			**ft_left(char **map, int i, int j, t_infos *infos);
char			**ft_up(char **map, int i, int j, t_infos *infos);
char			**ft_down(char **map, int i, int j, t_infos *infos);

/*
** LIB
*/
char			**ft_malloc(char **map, int line, int col);
int				ft_strlen(char *str);
void			ft_putendl(char *str);

#endif