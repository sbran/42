/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 20:05:11 by sbran             #+#    #+#             */
/*   Updated: 2014/06/13 20:05:13 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

/*
** lib
*/
void		ft_putendl(char *str);
int			ft_strlen(char *str);
char		**ft_strplit(char **tab, char *buff, int c);
char		**ft_malloc(char **tab, int len_str, int len_tab);
void		ft_print_tab(char **tab, int len_tab);

/*
** count_island
*/
char		**ft_search_island(char **tab, int i, int j, int isle);
char		**ft_count_island(char **tab, int len_tab, int isle);
char		*ft_read(char *buff, int fd, int *len_tab, int *len_str);
int			ft_island(char *file);

#endif
