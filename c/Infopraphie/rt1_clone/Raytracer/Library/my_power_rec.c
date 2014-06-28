/*
** my_power_rec.c for my_power_rec in /home/coutar_t//test_exo/Jour_05
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Fri Oct  7 12:14:18 2011 thibaut coutard
** Last update Mon Jan  2 14:51:28 2012 thibaut coutard
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    {
      nb = 1;
      return nb;
    }
  else if (power < 0)
    {
      nb = 0;
      return nb;
    }
else if (power > 1)
  {
    nb = my_power_rec(nb, (power - 1)) * nb;
    return nb;
  }
 else if (power == 1)
   return nb;
}
