#include "main.h"

static void	sprite_struct_init(t_all *all, int sprt_id)
{
	all->sprt[sprt_id].sprite_h = (all->map.cell_size / all->sprt[sprt_id].dist)
		* all->rays.dist2screen;
	all->sprt[sprt_id].sprite_w = (all->map.cell_size / all->sprt[sprt_id].dist)
		* all->rays.dist2screen * all->sprt[sprt_id].sprt_ratio;
	all->sprt[sprt_id].h_offset
		= (all->sprt[sprt_id].diff_angle * all->win.width)
		/ (PI / 2.515) + all->win.half_width - all->sprt[sprt_id].sprite_w / 2;
	all->sprt[sprt_id].v_offset = all->win.half_height
		- all->sprt[sprt_id].sprite_h / 2;
	all->sprt[sprt_id].i = 0;
	all->sprt[sprt_id].j = 0;
	all->sprt[sprt_id].color = 0;
}

static int	get_color(unsigned int *data, int width, int x, int y)
{
	return (*(data + y * width + x));
}

static void	set_color(t_all *all, int sprt_id)
{
	all->sprt[sprt_id].color = get_color(all->sprt[sprt_id].sprite_addr,
			all->sprt[sprt_id].sprite_attr[IMG_W],
			(int)(all->sprt[sprt_id].i * (all->sprt[sprt_id].sprite_attr[IMG_W]
					/ all->map.cell_size) * all->map.cell_size
				/ all->sprt[sprt_id].sprite_w),
			(int)(all->sprt[sprt_id].j
				* (all->sprt[sprt_id].sprite_attr[IMG_H]
					/ all->map.cell_size) * all->map.cell_size
				/ all->sprt[sprt_id].sprite_h));
}

static void	draw_spr_res(t_all *all, int sprt_id)
{
	unsigned int	*pxl_3d;

	pxl_3d = (unsigned int *)all->win.addr2;
	while (all->sprt[sprt_id].j < all->sprt[sprt_id].sprite_h - 2)
	{
		if (all->sprt[sprt_id].v_offset + all->sprt[sprt_id].j < 0
			|| all->sprt[sprt_id].v_offset
			+ all->sprt[sprt_id].j >= all->win.height)
		{
			all->sprt[sprt_id].j++;
			continue ;
		}
		set_color(all, sprt_id);
		if (all->sprt[sprt_id].color >= 0)
		{
			pxl_3d = (unsigned int *)all->win.addr2
				+ lround(all->sprt[sprt_id].v_offset
					+ all->sprt[sprt_id].j) * all->win.width
				+ lround(all->sprt[sprt_id].h_offset + all->sprt[sprt_id].i);
			*pxl_3d = all->sprt[sprt_id].color;
		}
		all->sprt[sprt_id].j++;
	}
	all->sprt[sprt_id].j = 0;
}

void	put_sprite(t_all *all, int sprt_id)
{
	int		slice_id;

	sprite_struct_init(all, sprt_id);
	slice_id = all->sprt[sprt_id].i;
	while (all->sprt[sprt_id].i < all->sprt[sprt_id].sprite_w)
	{
		if (all->sprt[sprt_id].h_offset + all->sprt[sprt_id].i < 0
			|| all->sprt[sprt_id].h_offset
			+ all->sprt[sprt_id].i >= all->win.width)
		{
			all->sprt[sprt_id].i++;
			continue ;
		}
		slice_id = all->sprt[sprt_id].i + all->sprt[sprt_id].h_offset - 1;
		if (all->ray_distances[slice_id] > all->sprt[sprt_id].dist)
			draw_spr_res(all, sprt_id);
		all->sprt[sprt_id].i++;
	}
}
