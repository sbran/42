/*
** my_isneg.c for my_isneg in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Wed Oct  5 12:01:53 2011 thibaut coutard
** Last update Mon Jan  2 14:47:51 2012 thibaut coutard
*/

int	my_isneg(int nb)
{
  if (nb < 0)
    my_putchar('N');
  else
    my_putchar('P');
}
