#include "main.h"

void	calc_scale_n_txtr(t_all *all)
{
	all->slice.xscale = (double)all->txtr.n_texture_attr[IMG_W]
		/ all->rays.Projected_Slice_Height;
	all->slice.yscale = (double)all->txtr.n_texture_attr[IMG_H]
		/ all->map.cell_size;
	all->slice.y_texture = (int)(fmod(all->rays.horz_intrcpt.x,
				all->map.cell_size) * all->slice.yscale);
	all->slice.texture = (unsigned int *)all->txtr.n_textrure_addr
		+ all->slice.y_texture * all->txtr.n_texture_attr[IMG_W];
}

void	calc_scale_s_txtr(t_all *all)
{
	all->slice.xscale = (double)all->txtr.s_texture_attr[IMG_W]
		/ all->rays.Projected_Slice_Height;
	all->slice.yscale = (double)all->txtr.s_texture_attr[IMG_H]
		/ all->map.cell_size;
	all->slice.y_texture = (int)((all->map.cell_size
				- fmod(all->rays.horz_intrcpt.x, all->map.cell_size))
			* all->slice.yscale);
	all->slice.texture = (unsigned int *)all->txtr.s_textrure_addr
		+ all->slice.y_texture * all->txtr.s_texture_attr[IMG_W];
}

void	calc_scale_w_txtr(t_all *all)
{
	all->slice.xscale = (double)all->txtr.w_texture_attr[IMG_W]
		/ all->rays.Projected_Slice_Height;
	all->slice.yscale = (double)all->txtr.w_texture_attr[IMG_H]
		/ all->map.cell_size;
	all->slice.y_texture = (int)((all->map.cell_size
				- fmod(all->rays.vert_intrcpt.y, all->map.cell_size))
			* all->slice.yscale);
	all->slice.texture = (unsigned int *)all->txtr.w_textrure_addr
		+ all->slice.y_texture * all->txtr.w_texture_attr[IMG_W];
}

void	calc_scale_e_txtr(t_all *all)
{
	all->slice.xscale = (double)all->txtr.e_texture_attr[IMG_W]
		/ all->rays.Projected_Slice_Height;
	all->slice.yscale = (double)all->txtr.e_texture_attr[IMG_H]
		/ all->map.cell_size;
	all->slice.y_texture = (int)(fmod(all->rays.vert_intrcpt.y,
				all->map.cell_size) * all->slice.yscale);
	all->slice.texture = (unsigned int *)all->txtr.e_textrure_addr
		+ all->slice.y_texture * all->txtr.e_texture_attr[IMG_W];
}
