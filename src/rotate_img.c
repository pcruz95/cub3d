#include "main.h"

static void	rot_img_init(t_all *all, void **data_addr, int **img_attr)
{
	all->rot_img._data_addr = (unsigned int *)(*data_addr);
	all->rot_img.rot_img = mlx_new_image(all->win.mlx,
			(*img_attr)[IMG_H], (*img_attr)[IMG_W]);
	all->rot_img.rot_data_addr = mlx_get_data_addr(all->rot_img.rot_img,
			&all->win.bits_per_pixel, (*img_attr)
			+ IMG_LINE_LEN, &all->win.endian);
	all->rot_img._rot_data_addr = (unsigned int *)all->rot_img.rot_data_addr;
	all->rot_img.r_img_x = (*img_attr)[IMG_H] - 1;
	all->rot_img.i = 0;
}

static void	copy_rot_img(t_all *all,
void **img_ptr, void **data_addr, int **img_attr)
{
	int	tmp;

	*data_addr = all->rot_img.rot_data_addr;
	*img_ptr = all->rot_img.rot_img;
	tmp = (*img_attr)[IMG_W];
	(*img_attr)[IMG_W] = (*img_attr)[IMG_H];
	(*img_attr)[IMG_H] = tmp;
}

void	rotate_img(t_all *all, void **img_ptr, void **data_addr, int **img_attr)
{
	rot_img_init(all, data_addr, img_attr);
	while (all->rot_img.r_img_x >= 0)
	{
		all->rot_img.rot_pxl = all->rot_img._rot_data_addr
			+ all->rot_img.r_img_x;
		all->rot_img.r_img_y = 0;
		while (all->rot_img.r_img_y < (*img_attr)[IMG_W])
		{
			*(all->rot_img.rot_pxl) = *(all->rot_img._data_addr
					+ all->rot_img.i);
			all->rot_img.rot_pxl += (*img_attr)[IMG_H];
			all->rot_img.r_img_y++;
			all->rot_img.i++;
		}
		all->rot_img.r_img_x--;
	}
	mlx_destroy_image(all->win.mlx, *img_ptr);
	copy_rot_img(all, img_ptr, data_addr, img_attr);
}
