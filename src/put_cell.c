#include "main.h"

static void	cell_init(t_all *all, t_pnt *point)
{
	all->cell.start_x = point->x;
	all->cell.start_y = point->y;
	all->cell.stop_x = point->x + all->map.cell_size;
	all->cell.stop_y = point->y + all->map.cell_size;
	all->cell.start_collider_x = point->x - all->plr.radius;
	all->cell.start_collider_y = point->y - all->plr.radius;
	all->cell.stop_collider_x = all->cell.stop_x + all->plr.radius;
	all->cell.stop_collider_y = all->cell.stop_y + all->plr.radius;
	point->y = all->cell.start_collider_y;
}

void	put_cell(t_all *all, t_pnt point, int color)
{
	cell_init(all, &point);
	if (WHITE == color)
	{
		while (point.y < all->cell.stop_collider_y)
		{
			point.x = all->cell.start_collider_x;
			while (point.x < all->cell.stop_collider_x)
			{
				my_mlx_pixel_put(all, point, COLLIDER);
				point.x++;
			}
			point.y++;
		}
	}
	point.y = all->cell.start_y;
	while (point.y < all->cell.stop_y)
	{
		point.x = all->cell.start_x;
		while (point.x < all->cell.stop_x)
		{
			my_mlx_pixel_put(all, point, color);
			point.x++;
		}
		point.y++;
	}
}
