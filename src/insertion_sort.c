#include "main.h"

void	insertion_sort(int *array, int length, t_all *all)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (NULL == array || length <= 0)
		return ;
	i = 1;
	while (i < length)
	{
		tmp = array[i];
		j = i - 1;
		while (j >= 0 && all->sprt[tmp].dist < all->sprt[array[j]].dist)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
		i++;
	}
}
