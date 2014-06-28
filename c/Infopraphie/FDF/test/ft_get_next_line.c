
#include "fdf.h"

static void	ft_offset_adress(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
	{
		buff[j] = buff[i];
		j++;
		i++;
	}
	buff[j] = '\0';
}

static void	ft_free_line(char **cpy, char **line, char *buff)
{
	*cpy = *line;
	*line = ft_strjoin_gnl(*line, buff);
	free(*cpy);
}

static int	ft_concat_buff(char **line, char *buff, int ret, int fd)
{
	char	*cpy;

	if (!ft_strchr(buff, '\n'))
	{
		*line = ft_strdup_gnl(buff);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
			return (0);
		buff[ret] = '\0';
		ft_free_line(&cpy, line, buff);
		while (!ft_strchr(buff, '\n') && ret)
		{
			ft_offset_adress(buff);
			if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
				return (-1);
			if (!ret)
				return (0);
			buff[ret] = '\0';
			ft_free_line(&cpy, line, buff);
		}
		ft_offset_adress(buff);
	}
	return (1);
}

int			ft_get_next_line(const int fd, char **line)
{
	int			ret;
	static char	buff[BUFF_SIZE + 1];

	ret = 0;
	if (!line)
		return (-1);
	*line = NULL;
	if (fd == -1)
		return (-1);
	if (!(*buff))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
	}
	if ((ret = ft_concat_buff(line, buff, ret, fd)) == -1)
		return (-1);
	if (!ret)
		return (0);
	if (!(*line))
	{
		*line = ft_strdup_gnl(buff);
		ft_offset_adress(buff);
	}
	return (1);
}
