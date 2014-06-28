/*
** my_showstr.c for my_showstr in /u/epitech_2016/coutar_t/rendu/lib/my
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Tue Oct 11 15:36:21 2011 thibaut coutard
** Last update Mon Nov 14 11:26:48 2011 thibaut coutard
*/

char	my_base_16(char str, char *tab)
{
  char	res[1];
  int	a;

  a = 0;
  while (str != 0)
    {
      res[a] = str % 16;
      str = str / 16;
      a = a + 1;
    }
  if (*res < 15)
    my_putchar('0');
  res[0] = tab[res[0]];
  res[1] = tab[res[1]];
    my_putchar(*res);
}

int	my_showstr(char *str)
{
  char	tab[16];
  int	i;

  i = 0;
  tab_16(tab);
  while (str[i] != '\0')
    {
      if (str[i] < ' ' || str[i] > 126)
	{
	  my_putchar('\\');
	  my_base_16(str[i], tab);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

int	tab_16( char *tab)
{
  int	i;
  int	hex;

  i = 0;
  hex = 48;
  while (hex < 104)
    {
      if (hex == 58)
	hex = 97;
      tab[i] = hex;
      hex = hex + 1;
      i = i + 1;
    }
}
