#include "main.h"

static void	line_init(t_pnt_int p1, t_pnt_int p2, t_all *all)
{
	all->line.deltaX = abs(p2.x - p1.x);
	all->line.deltaY = abs(p2.y - p1.y);
	all->line.signX = -1;
	if (p1.x < p2.x)
		all->line.signX = 1;
	all->line.signY = -1;
	if (p1.y < p2.y)
		all->line.signY = 1;
	all->line.error = all->line.deltaX - all->line.deltaY;
}

void	player_line(t_pnt_int p1, t_pnt_int p2, t_all *all, int color)
{
	line_init(p1, p2, all);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (WHITE == *(calculate_address(all, p1.x, p1.y)))
			return ;
		if (!(p1.x < 0 || p1.x > all->win.width
				|| p1.y < 0 || p1.y > all->win.height)
			&& (RED != *(calculate_address(all, p1.x, p1.y))))
			player_line_pixel_put(all, p1, color);
		all->line.error2 = all->line.error * 2;
		if (all->line.error2 > -all->line.deltaY)
		{
			all->line.error -= all->line.deltaY;
			p1.x += all->line.signX;
		}
		if (all->line.error2 < all->line.deltaX)
		{
			all->line.error += all->line.deltaX;
			p1.y += all->line.signY;
		}
	}
}
