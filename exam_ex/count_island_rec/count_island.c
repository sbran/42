#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_tablen(char *str, int c)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			size++;
		i++;
	}
	return (size);
}

char	**ft_strsplit_cl(char *str, size_t size_tab, size_t size, char c)
{
	char	**tab;
	int		i;
	int 	j;
	size_t 	ln;

	i = 0;
	ln = 0;
	tab = (char **)malloc(sizeof(char *) * size_tab + 1);
	while (ln <= size_tab)
	{
		tab[ln] = (char *)malloc(sizeof(char) * size);
		ln++;
	}
	ln = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != '\0')
		{
			if (str[i] == c)
			{
				tab[ln][j] = '\0';
				break;
			}
			tab[ln][j++] = str[i++];
		}
		ln++;
		i++;
	}
	return (tab);
}

void	ft_print_tab(char **map, size_t ln_tab)
{
	size_t 	i;

	i = 0;
	while (i <= ln_tab)
	{
		ft_putendl(map[i]);
		i++;
	}
}

char	**ft_search_island(char **map, size_t ln_tab, size_t i, size_t j, int isle)
{
	map[i][j] = isle;
	if (j < ft_strlen(map[i]) && map[i][j + 1] == 'X')
		ft_search_island(map, ln_tab, i, (j + 1), isle);
	if ((i + 1) <= ln_tab && map[i + 1][j] == 'X')
		ft_search_island(map, ln_tab, (i + 1), j, isle);
	if (j > 0 && map[i][j - 1] == 'X')
		ft_search_island(map, ln_tab, i, (j - 1), isle);
	if (i > 0 && map[i - 1][j] == 'X')
		ft_search_island(map, ln_tab, (i - 1), j, isle);
	return (map);
}

char	**ft_count_island(char **map, size_t ln_tab, size_t i, size_t j, int isle)
{
	while (i <= ln_tab)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'X')
			{
				printf("%c\n", isle);
				if (isle > '9')
					exit(1);
				map[i][j] = isle;
				map = ft_search_island(map, ln_tab, i, j, isle);
				isle++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void	ft_island(char *file)
{
	int		i;
	int		fd;
	size_t	size;
	size_t	nb_str;
	char	*buff;
	char	**tab;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_putendl("Error: can't open file.");
	else
	{
		buff = (char *)malloc(sizeof(char) * 424242);
		i = 0;
		while (read(fd, &buff[i], 1) > 0)
		{
			if (buff[i] == '\n')
				size = i;
			i++;
		}
		nb_str = ft_tablen(buff, '\n');
		tab = ft_strsplit_cl(buff, nb_str, size, '\n');
		tab = ft_count_island(tab, nb_str, 0, 0, 48);
		ft_print_tab(tab, nb_str);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_island(av[1]);
	else
		ft_putchar('\n');
	return (0);
}