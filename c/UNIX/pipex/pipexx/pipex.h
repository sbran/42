/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:54:16 by sraccah           #+#    #+#             */
/*   Updated: 2013/12/31 18:50:31 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>

extern char	**environ;

void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *str, int fd);
void    	ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *str);
void   		ft_putchar(char c);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_strsplit(char const *s, char c);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr(int nbr);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
