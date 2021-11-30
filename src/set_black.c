#include "main.h"

void	set_black(void	*addr, int size)
{
	int		i;
	long	*_addr;

	_addr = (long *)addr;
	i = 0;
	while (i < size)
	{
		_addr[i] = (long)0;
		i++;
	}
}

void	set_background(void	*addr, t_all *all)
{
	int				i;
	unsigned int	*_addr;

	_addr = (unsigned int *)addr;
	i = 0;
	while (i < all->win.half_all_pxls)
		_addr[i++] = all->win.ceiling_color;
	while (i < all->win.all_pxls)
		_addr[i++] = all->win.floor_color;
}	
