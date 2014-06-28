#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"

int	get_count_for_epur(char *str)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	count++;
      i++;
    }
  return (count);
}

char	*epur_str(char *str)
{
  int i;
  int j;
  int count;
  char *new;

  i = 0;
  j = 0;
  count = get_count_for_epur(str);
  new = xmalloc((my_strlen(str) - count + 1) * sizeof(*str));
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  new[j] = str[i];
	  j++;
	}
      i++;
    }
  new[j] = '\0';
  free(str);
  return (new);
}

char    **get_scene_in_tab(int fd, char **token)
{
  int   i;
  int   count;
  char  **tab;
  char  *str;
  char  *epur;

  i = 1;
  count = 1;
  tab = NULL;
  while ((str = get_next_line(fd)) != NULL)
    {
      if (tab == NULL)
        tab = malloc((i + 1) * sizeof(*tab));
      else
        tab = realloc(tab, (i + 1) * sizeof(*tab));
      epur = check_error(epur_str(str), count, token);
      if (epur != NULL)
        {
          tab[i - 1] = epur;
          tab[i] = NULL;
          i++;
	}
      count++;
    }
  return (tab);
}

void	free_double(char **tab)
{
  int i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int	get_scene(t_param *param, char *file)
{
  int	fd;
  char	**tab;
  char	**token;

  fd = xopen(file, O_RDONLY);
  token = token_tab();
  tab = get_scene_in_tab(fd, token);
  param = get_all_obj(param, tab);
  free_double(tab);
  return (0);
}
