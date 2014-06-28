#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int		i;
	char	*buff;

	i = 0;
	buff = (char *)malloc(sizeof(char) * 424242);
	while ((read(0, &buff[i], 1)) > 0)
		i++;
	printf("%s\n", buff);
	return 0;
}