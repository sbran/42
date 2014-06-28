/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alph_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 22:27:54 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/17 11:45:58 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPH_LONG_H
# define ORD_ALPH_LONG_H

# define MIN(c) (c >= 'A' && c <= 'Z' ? c + 32 : c)

# include <stdbool.h>

/*
** ft_put
*/

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_swap(char **tab, int i);

/*
** ft_strsplit
*/

bool		is_spacetab(char c);
void		ft_strncpy(char *dest, char *src, int n);
int			nbr_of_word(char *str);
char		**ft_strsplit_oal(char *str);

/*
** ft_tab
*/

void		ft_print_tab(char **tab);
void		ft_sort_tab(char **tab);
int			ft_strcmp_minor(char *s1, char *s2);

void		ord_alph_long(char *str);

#endif /* !ORD_ALPH_LONG_H */