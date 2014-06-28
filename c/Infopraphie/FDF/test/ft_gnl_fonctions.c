
#include "fdf.h"

char			*ft_strjoin_gnl(const char *s1, const char *s2)
{
	int			i;
	int			j;
	char		*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = (char *)malloc
		((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_strdup_gnl(const char *str)
{
	size_t		i;
	char		*cpy;

	i = 0;
	if (!(cpy = malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
