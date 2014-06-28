/*
** my_sort_int_tab.c for my_sort_int_tab in /home/coutar_t//test_exo/Jour_04
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 22:50:40 2011 thibaut coutard
** Last update Sun Oct 16 15:25:25 2011 thibaut coutard
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	compt;
  int	flag;
  int	i;

  compt = 0;
  flag = 0;
  i = 0;
  while ( compt != size - 1)
    {
      if (tab[compt] > tab[compt + 1])
	{
	  i = tab[compt];
	  tab[compt] = tab[compt + 1];
	  tab[compt + 1] = i;
	  flag = 1;
	}
      compt = compt + 1;
    }
  if (flag != 0)
    my_sort_int_tab(tab, size);
}
