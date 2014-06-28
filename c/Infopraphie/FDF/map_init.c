/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Stouf <Stouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 19:30:50 by Stouf             #+#    #+#             */
/*   Updated: 2014/01/14 23:57:29 by Stouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

void            ft_stock_value(t_env *env)
{
    char        **tmp;
    int         i;
    int         j;

    i = 0;
    j = 0;
    env->tab = (int **)malloc(sizeof(int *) * (env->nbr_line + 1));
    env->tab[env->nbr_line] = '\0';
    while (i < env->nbr_line)
    {
        env->tab[i] = (int *)malloc(sizeof(int) * (env->nbr_col + 1));
        env->tab[i][env->nbr_col] = '\0';
        i++;
    }
    env->fd = open(env->argv[1], O_RDONLY);
    while (ft_get_next_line(env->fd, &env->line))
    {
        i = 0;
        tmp = ft_strsplit(env->line, ' ');
        while (i < env->nbr_col)
        {
            env->tab[j][i] = ft_atoi(tmp[i]);
            ft_putnbr(env->tab[j][i]);
            i++;
        }
        j++;
        ft_putchar('\n');
    }
}

void            ft_nbr_line_col(t_env *env)
{
    int         i;
    char        **tmp;

    env->nbr_line = 0;
    env->nbr_col = 0;
    env->fd = open(env->argv[1], O_RDONLY);
    while (ft_get_next_line(env->fd, &env->line))
    {
        i = 0;
        tmp = ft_strsplit(env->line, ' ');
        ft_putstr(env->line);
        ft_putchar('\n');
        while (tmp[i])
            i++;
        env->nbr_line++;
    }
    env->nbr_col = (i - 1);
}