#include "main.h"

static void	circum_init(t_all *all, int *radius)
{
	all->circumference.x = 0;
	all->circumference.y = *radius;
	all->circumference.delta = 1 - 2 * (*radius);
	all->circumference.error = 0;
}

static void	put_pixels(t_all *all, t_pnt center, int color)
{
	all->circumference.draw_point.x = center.x + all->circumference.x;
	all->circumference.draw_point.y = center.y + all->circumference.y;
	my_mlx_pixel_put(all, all->circumference.draw_point, color);
	all->circumference.draw_point.x = center.x + all->circumference.x;
	all->circumference.draw_point.y = center.y - all->circumference.y;
	my_mlx_pixel_put(all, all->circumference.draw_point, color);
	all->circumference.draw_point.x = center.x - all->circumference.x;
	all->circumference.draw_point.y = center.y + all->circumference.y;
	my_mlx_pixel_put(all, all->circumference.draw_point, color);
	all->circumference.draw_point.x = center.x - all->circumference.x;
	all->circumference.draw_point.y = center.y - all->circumference.y;
	my_mlx_pixel_put(all, all->circumference.draw_point, color);
	all->circumference.error = 2
		* (all->circumference.delta + all->circumference.y) - 1;
}

void	circumference(t_all *all, t_pnt center, int radius, int color)
{
	circum_init(all, &radius);
	while (all->circumference.y >= 0)
	{
		put_pixels(all, center, color);
		if ((all->circumference.delta < 0) && (all->circumference.error <= 0))
		{
			all->circumference.delta += 2 * ++all->circumference.x + 1;
			continue ;
		}
		if ((all->circumference.delta > 0) && (all->circumference.error > 0))
		{
			all->circumference.delta -= 2 * --all->circumference.y + 1;
			continue ;
		}
		all->circumference.delta += 2
			* (++all->circumference.x - --all->circumference.y);
	}
}
