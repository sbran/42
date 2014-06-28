#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>

int			ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	return (0);
}

int     ft_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		**ft_malloc(char **tab, int col, int line)
{
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * line + 1);
	while (i <= line)
		tab[i++] = (char *)malloc(sizeof(char) * col);
	tab[i] = NULL;
	return (tab);
}

char *ft_realloc(char *str, int size)
{
  char  *tmp;
  int   i;
  int   len;

  i = 0;
  len = ft_strlen(str);
  tmp = (char *)malloc(sizeof(char) * (len + size));
  while (i < len)
  {
    tmp[i] = str[i];
    i++;
  }
  while (i < (len + size))
    tmp[i++] = '\0';
  tmp[i] = '\0';
  if (str != NULL)
    free(str);
  return (tmp);
}

char		*ft_read(char *buff, int fd, int *len_tab, int *len_str)
{
	int		i;
	int		len_tmp;

	i = 0;
	len_tmp = 0;
  buff = (char *)malloc(sizeof(char) * 1);
	while ((read(fd, &buff[i], 1)) > 0)
	{
    if (i != 0)
      buff = ft_realloc(buff, 1);
		if (buff[i] != '.' && buff[i] != 'X' &&
				buff[i] != '\n' && buff[i] != '\0')
			return (NULL);
		if (buff[i] == '\n')
		{
			if (*len_tab == 1)
				*len_str = i;
			*len_tab = *len_tab + 1;
			if (*len_str != len_tmp)
          return (NULL);
			len_tmp = -1;
		}
		len_tmp++;
		i++;
	}
	if (buff[i - 1] == '\n')
      return (NULL);
	return (buff);
}

char		**ft_strsplit(char **tab, char *buff, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (buff[i] != '\0')
	{
		j = 0;
		while (buff[i] != '\0' && buff[i] != c)
		{
			tab[k][j++] = buff[i++];
			if (buff[i] == c)
				tab[k][j] = '\0';
			if (buff[i] == '\0')
			{
				tab[k][j] = '\0';
				return (tab);
			}
		}
		k++;
		i++;
	}
	return (NULL);
}

char		**ft_search_island(char **tab, int i, int j, int island)
{
	tab[i][j] = island;
	if (j < ft_strlen(tab[i]) && tab[i][j + 1] == 'X')
		tab = ft_search_island(tab, i, (j + 1), island);
	if (i < ft_strlen(tab[i]) && tab[i + 1][j] == 'X')
		tab = ft_search_island(tab, (i + 1), j, island);
	if (j > 0 && tab[i][j - 1] == 'X')
		tab = ft_search_island(tab, i, (j - 1), island);
	if (i > 0 && tab[i - 1][j] == 'X')
		tab = ft_search_island(tab, (i - 1), j, island);
	return (tab);
}

char		**ft_count_island(char **tab, int len_str, int len_tab)
{
	int		 i;
	int		j;
	int		island;

	i = 0;
	len_str = 0;
	i = len_str;
	island = 48;
	while (i <= len_tab)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'X')
			{
				if (island > 57)
					return (NULL);
				tab[i][j] = island;
				tab = ft_search_island(tab, i, j, island++);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void		ft_put_tab(char **tab, int len_tab)
{
	int		i;

	i = 0;
	while (i < len_tab)
		ft_putendl(tab[i++]);
}

int			ft_island(char *file)
{
	int		fd;
	int		len_str;
	int		len_tab;
	char	*buff;
	char	**tab;

	len_tab = 1;
	len_str = 0;
	tab = NULL;
	buff = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	if ((buff = ft_read(buff, fd, &len_tab, &len_str)) == NULL)
		return (-1);
	tab = ft_malloc(tab, len_str, len_tab);
	tab = ft_strsplit(tab, buff, '\n');
  free(buff);
	if ((tab = ft_count_island(tab, len_str, len_tab)) == NULL)
		return (-1);
	ft_put_tab(tab, len_tab);
  free(tab);
	return (0);
}

int		 main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_island(av[1]) == -1)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
