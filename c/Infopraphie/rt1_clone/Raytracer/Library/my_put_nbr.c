/*
** my_put_nbr.c for my_put_nbr in /home/coutar_t//test_exo
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Wed Oct  5 18:50:54 2011 thibaut coutard
** Last update Sat Nov 19 12:35:10 2011 thibaut coutard
*/

int	my_aff_a(char a, int p, int nb)
{
  int	n;

  n = 0;
  while (p != 0 )
    {
      a = '0' + ( (nb % (p * 10)) / p);
      p = p / 10;
      if (a != '0' || n != 0)
	{
	my_putchar(a);
      n = n + 1;
	}
    }
}

void	my_put_nbre (int nb)
{
  int	p;
  int	a;

      if (nb < 0)
	  {
	    nb = -nb;
	    my_putchar('-');
	  }
      p = 1000000000;
            a  =  '0' + ((nb % (p * 10) ) / p);
      my_aff_a(a, p, nb);
}

void	my_put_nbr(int nb)
{
  if (nb == 0)
    my_putchar ('0');
  else if (nb == -2147483648)
    my_putstr("-2147483648");
  else if (nb == 2147483647)
    my_putstr("2147483648");
  else
    my_put_nbre(nb);
}
