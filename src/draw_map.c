#include "main.h"

static void	make_transparent(t_all *all)
{
	t_pnt	point;

	point.y = 0;
	while (point.y < all->win.height)
	{
		point.x = 0;
		while (point.x < all->win.width)
		{
			if (BLACK == *(calculate_address(all, point.x, point.y)))
				my_mlx_pixel_put(all, point, 0xFF000000);
			point.x++;
		}
		point.y++;
	}
}

static void	set_orientation(t_all *all, t_pnt point, int x, int y)
{
	if (all->map.map[y][x] == '1')
		put_cell(all, point, WHITE);
	if (all->map.map[y][x] == 'W')
	{
		all->plr.pos = point;
		all->plr.rotation_angle = PI;
	}
	if (all->map.map[y][x] == 'E')
	{
		all->plr.pos = point;
		all->plr.rotation_angle = PI2;
	}
	if (all->map.map[y][x] == 'S')
	{
		all->plr.pos = point;
		all->plr.rotation_angle = PI_DIV_2;
	}
	if (all->map.map[y][x] == 'N')
	{
		all->plr.pos = point;
		all->plr.rotation_angle = -PI_DIV_2;
	}	
}

void	draw_map(t_all *all)
{
	int		x;
	int		y;
	t_pnt	point;

	y = 0;
	point.y = 0;
	while (all->map.map[y])
	{
		x = 0;
		point.x = 0;
		while (all->map.map[y][x])
		{
			set_orientation(all, point, x, y);
			point.x += all->map.cell_size;
			x++;
		}
		point.y += all->map.cell_size;
		y++;
	}
	all->plr.pos.x += all->map.cell_size / 2;
	all->plr.pos.y += all->map.cell_size / 2;
	make_transparent(all);
	clear_map(all, all->map.map_height);
	copy_img(all->win.tmp_addr, all->win.addr, all->win.half_all_pxls);
}
