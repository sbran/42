/*
** xread.c for raytracer in /home/heang_d//ray_local
** 
** Made by david heang
** Login   <heang_d@epitech.net>
** 
** Started on  Sun Jun  3 18:56:19 2012 david heang
** Last update Sun Jun  3 20:16:47 2012 david heang
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<errno.h>

int	xread(int fd, void *buf, int count)
{
  int	ret;
  int	errno;

  ret = read(fd, buf, count);
  if (ret == -1)
    {
      if (errno == EISDIR)
	my_putstr("It's a directory.\n");
      else
	{
	  my_putstr("Error while reading ");
	  my_put_nbr(count);
	  my_putstr(" bytes from fd ");
	  my_put_nbr(fd);
	  my_putstr(".\n");
	}
      exit(EXIT_FAILURE);
    }
  return (ret);
}
