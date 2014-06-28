/*
** my_strcapitalize.c for my_strcapitalize in /home/coutar_t//test_exo/Jour_06
**
** Made by thibaut coutard
** Login   <coutar_t@epitech.net>
**
** Started on  Mon Oct 10 17:12:35 2011 thibaut coutard
** Last update Sun Oct 16 16:00:42 2011 thibaut coutard
*/

char    *my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < 97 || str[i] > 122) && (str[i] < '0' || str[i] >'9'))
	{
	  while ((str[i] < 97 || str[i] > 122) && (str[i] < '0' || str[i] >'9'))
	    {
	      i = i + 1;
	    }
	  str[i] = str[i] - 32;
	}
      else  if (i == 0)
        {
          str[i] = str[i] - 32;
        }
      i = i + 1;
    }
  return (str);
}
