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
