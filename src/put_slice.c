#include "main.h"

static void	fill_img(int slice_number, int slice_half_height, t_all *all)
{
	int				upper;
	int				bottom;
	unsigned int	*img3d;

	upper = all->win.half_height - slice_half_height;
	if (upper < 0)
		all->slice.x_texture = -upper * all->slice.xscale;
	if (upper < 0)
		upper = 0;
	bottom = all->win.half_height + slice_half_height;
	if (bottom >= all->win.height)
		bottom = all->win.height - 1;
	img3d = (unsigned int *)all->win.addr2
		+ bottom * all->win.width + slice_number;
	while (bottom > upper)
	{
		*img3d = *(all->slice.texture + (int)all->slice.x_texture);
		img3d -= all->win.width;
		bottom--;
		all->slice.x_texture += all->slice.xscale;
	}
}

void	put_slice(int slice_number, int slice_half_height, t_all *all)
{
	all->slice.y_texture = 0;
	all->slice.x_texture = 0;
	if (all->rays.found_horz_wall)
	{
		if (!all->rays.isRayFacingDown)
			calc_scale_n_txtr(all);
		if (all->rays.isRayFacingDown)
			calc_scale_s_txtr(all);
	}
	if (all->rays.found_vert_wall)
	{
		if (!all->rays.isRayFacingLeft)
			calc_scale_e_txtr(all);
		if (all->rays.isRayFacingLeft)
			calc_scale_w_txtr(all);
	}
	fill_img(slice_number, slice_half_height, all);
}
