/*
** my.h for my.h in /u/epitech_2016/coutar_t/rendu/include
** 
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
** 
** Started on  Thu Oct 13 10:41:56 2011 thibaut coutard
** Last update Sun Jun  3 19:40:37 2012 david heang
*/

#ifndef __MY_H__
#define __MY_H__

void	my_putchar(char);
int	my_isneg(int);
void	my_put_nbr(int);
void	my_swap(int *, int *);
void	my_putstr(char *);
void	my_puterror(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	my_str_isalpha(char *);
int	my_str_isnum(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
int	my_showstr(char *);
int	my_showmem(char *, int);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
void	*xmalloc(int);
int	xread(int, void *, int);
int	xopen(char *, int);
void	*xrealloc(void *, int);
int	my_strlcat(char *, char *, int);

#endif
