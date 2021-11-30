#include "main.h"

void	my_mlx_pixel_put3(t_all *all, t_pnt point, int color)
{
	unsigned int	*dst;

	if (point.x < 0 || point.y < 0
		|| point.x >= all->win.width || point.y >= all->win.height)
		return ;
	dst = calculate_address(all, point.x, point.y);
	*dst = color;
}

unsigned int	*calculate_map_address(t_all *all, int x, int y)
{
	return (all -> win.tmp_addr
		+ (y * all -> win.line_length + x * CHARS_PER_PIXEL));
}

void	player_line_pixel_put(t_all *all, t_pnt_int point, int color)
{
	unsigned int	*dst;

	if (point.x < 0 || point.y < 0
		|| point.x >= all->win.width || point.y >= all->win.height)
		return ;
	dst = calculate_address(all, point.x, point.y);
	if (WHITE == *dst)
		return ;
	*dst = color;
}
