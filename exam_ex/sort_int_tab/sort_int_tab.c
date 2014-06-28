#include <stdio.h>
#include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int			tmp;
	unsigned	count;
	unsigned	j;

	tmp = 0;
	j = 0;
	while (j < size)
	{
		count = j;
		while (count < size && count > 0 && tab[count] < tab[count - 1])
		{
			tmp = tab[count - 1];
			tab[count - 1] = tab[count];
			tab[count] = tmp;
			count--;
		}
		j++;
	}
}

/*void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int     i;
    int             tmp;

    i = 0;
    while (i < size - 1)
    {
        while (tab[i] > tab[i + 1])
        {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = tmp;
            i = 0;
        }
        i++;
    }
}*/

int 	main(void)
{
	int 	*tab;
	int 	i;

	tab = (int *)malloc(sizeof(int) * 1024);
	tab[0] = 65;
	tab[1] = 42;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 1;
	tab[5] = -10;
	tab[6] = -19966;
	tab[7] = 896;
	tab[8] = 2;
	tab[9] = 9;
	tab[10] = 65;
	tab[11] = 42;
	tab[12] = 0;
	tab[13] = -3445454;
	tab[14] = 1;
	tab[15] = -10;
	tab[16] = -19966;
	tab[17] = 896;
	tab[18] = 236463;
	tab[19] = 9;
	tab[20] = 63465;
	tab[21] = 42;
	tab[22] = 0;
	tab[23] = 3460;
	tab[24] = 13463;
	tab[25] = -10;
	tab[26] = -19966;
	tab[27] = 896;
	tab[28] = 2636;
	tab[29] = 9463;
	tab[30] = 65;
	tab[31] = 42;
	tab[32] = 97896;
	tab[33] = 0;
	tab[34] = 134634;
	tab[35] = -10;
	tab[36] = -19966;
	tab[37] = 896;
	tab[38] = 2;
	tab[39] = 92525;
	tab[40] = 65;
	tab[41] = 42;
	tab[42] = 0;
	tab[43] = 0;
	tab[44] = 1;
	tab[45] = -10;
	tab[46] = -19966;
	tab[47] = 896;
	tab[48] = 2;
	tab[49] = 9;

	sort_int_tab(&tab[11], 10);
	i = 11;
	while (i < 21)
		printf("%d\n", tab[i++]);
	return (0);
}