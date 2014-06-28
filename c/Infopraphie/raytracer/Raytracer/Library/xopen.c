/*
** xopen.c for raytracer in /home/heang_d//ray_local
** 
** Made by david heang
** Login   <heang_d@epitech.net>
** 
** Started on  Sun Jun  3 19:05:49 2012 david heang
** Last update Sun Jun  3 20:14:35 2012 david heang
*/

#include	<stdlib.h>
#include	<errno.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

int	xopen(char *pathname, int flags)
{
  int	ret;
  int	errno;

  ret = open(pathname, flags);
  if (ret == -1)
    {
      if (errno == EACCES)
	my_putstr("Permission denied.\n");
      else if (errno == EISDIR || errno == ENOTDIR)
	{
	  my_putstr(pathname);
	  my_putstr(" is a directory.\n");
	}
      else if (errno == ENAMETOOLONG)
	my_putstr("The pathname is too long.\n");
      else if (errno == ENOENT)
	my_putstr("This file doesn't exist.\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
