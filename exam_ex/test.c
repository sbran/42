#include <unistd.h>

int		main(void)
{
	if(42)
		write(1, "a", 1);
	return (0);
}
