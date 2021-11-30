#include "main.h"

void	copy_img(void *dst, void *src, int size)
{
	int		i;
	long	*_dst;
	long	*_src;

	_dst = (long *)dst;
	_src = (long *)src;
	i = 0;
	while (i < size)
	{
		_dst[i] = _src[i];
		i++;
	}	
}

static void	copying(t_all *all, unsigned int *_dst, unsigned int *start_img)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	j = 0;
	y = 0;
	x = 0;
	while (y < all->map.mini_map_size)
	{
		x = 0;
		while (x < all->map.mini_map_size)
		{
			_dst[i] = start_img[j];
			i++;
			j++;
			x++;
		}
		j += all->win.line_length / 4 - (all->map.mini_map_size);
		y++;
	}
}

void	copy_mini_map(void *dst, void *src, t_all *all)
{
	t_pnt			start_map;
	unsigned int	*start_img;
	unsigned int	*_dst;

	start_map.y = all->plr.pos.y - (all->map.mini_map_size) / 2;
	start_map.x = all->plr.pos.x - (all->map.mini_map_size) / 2;
	if (start_map.x < 0.0)
		start_map.x = 0.0;
	if ((start_map.x + all->map.mini_map_size) > all->win.width)
		start_map.x = all->win.width - all->map.mini_map_size;
	if (start_map.y < 0.0)
		start_map.y = 0.0;
	if ((start_map.y + all->map.mini_map_size) > all->win.height)
		start_map.y = all->win.height - all->map.mini_map_size;
	start_img = (unsigned int *)(src + ((int)round(start_map.y)
				* all->win.line_length
				+ (int)round(start_map.x) * CHARS_PER_PIXEL));
	_dst = (unsigned int *)dst;
	copying(all, _dst, start_img);
}

static void	copying2(t_all *all, unsigned int *start_img,
unsigned int *start_tmp)
{
	int	i;
	int	j;
	int	y;
	int	x;

	i = 0;
	j = 0;
	y = 0;
	x = 0;
	while (y < all->map.plr_square)
	{
		x = 0;
		while (x < all->map.plr_square)
		{
			start_img[i] = start_tmp[j];
			i++;
			j++;
			x++;
		}
		i += all->win.line_length_ints - all->map.plr_square;
		j += all->win.line_length_ints - all->map.plr_square;
		y++;
	}
}

void	copy_map(void *dst, void *src, t_all *all)
{
	t_pnt			start_map;
	unsigned int	*start_img;
	unsigned int	*start_tmp;

	start_map.y = all->plr.pos.y - all->map.plr_square / 2;
	start_map.x = all->plr.pos.x - all->map.plr_square / 2;
	if (start_map.x < 0.0)
		start_map.x = 0.0;
	if ((start_map.x + all->map.plr_square) > all->win.width)
		start_map.x = all->win.width - all->map.plr_square;
	if (start_map.y < 0.0)
		start_map.y = 0.0;
	if ((start_map.y + all->map.mini_map_size) > all->win.height)
		start_map.y = all->win.height - all->map.plr_square;
	start_img = (unsigned int *)(dst + ((int)round(start_map.y)
				* all->win.line_length
				+ (int)round(start_map.x) * CHARS_PER_PIXEL));
	start_tmp = (unsigned int *)(src + ((int)round(start_map.y)
				* all->win.line_length
				+ (int)round(start_map.x) * CHARS_PER_PIXEL));
	copying2(all, start_img, start_tmp);
}
