void	sort_int_tab(int *tab, unsigned int size)
{
	int		tmp;
	int		count;
	int		tmp_count;
	int 	i = 0;

	count = 0;
	tmp = 0;
	while (count < (int)size)
	{
		tmp_count = count;
		while (count < (int)size && count > 0 && tab[count] < tab[count - 1])
		{
			tmp = tab[count - 1];
			tab[count - 1] = tab[count];
			tab[count] = tmp;
			count--;
		}
		count = tmp_count;
		count++;
	}
}
