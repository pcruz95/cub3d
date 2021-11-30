#include "main.h" 

void	convert_n_texture(t_all *all)
{
	all->txtr.n_textrure_img = mlx_xpm_file_to_image(all->win.mlx,
			all->txtr.n_texture_path, &all->txtr.n_texture_attr[IMG_W],
			&all->txtr.n_texture_attr[IMG_H]);
	if (!all->txtr.n_textrure_img)
	{
		printf("Error\n%s\n", "Wrong texture path");
		exit (-666);
	}
	all->txtr.n_textrure_addr = mlx_get_data_addr(all->txtr.n_textrure_img,
			&all->win.bits_per_pixel,
			&all->txtr.n_texture_attr[IMG_LINE_LEN], &all->win.endian);
	if (!all->txtr.n_textrure_addr)
		exit (-666);
}

void	convert_s_texture(t_all *all)
{
	all->txtr.s_textrure_img = mlx_xpm_file_to_image(all->win.mlx,
			all->txtr.s_texture_path, &all->txtr.s_texture_attr[IMG_W],
			&all->txtr.s_texture_attr[IMG_H]);
	if (!all->txtr.s_textrure_img)
	{
		printf("Error\n%s\n", "Wrong texture path");
		exit (-666);
	}
	all->txtr.s_textrure_addr = mlx_get_data_addr(all->txtr.s_textrure_img,
			&all->win.bits_per_pixel,
			&all->txtr.s_texture_attr[IMG_LINE_LEN], &all->win.endian);
	if (!all->txtr.s_textrure_addr)
		exit (-666);
}

void	convert_w_texture(t_all *all)
{
	all->txtr.w_textrure_img = mlx_xpm_file_to_image(all->win.mlx,
			all->txtr.w_texture_path, &all->txtr.w_texture_attr[IMG_W],
			&all->txtr.w_texture_attr[IMG_H]);
	if (!all->txtr.w_textrure_img)
	{
		printf("Error\n%s\n", "Wrong texture path");
		exit (-666);
	}
	all->txtr.w_textrure_addr = mlx_get_data_addr(all->txtr.w_textrure_img,
			&all->win.bits_per_pixel,
			&all->txtr.w_texture_attr[IMG_LINE_LEN], &all->win.endian);
	if (!all->txtr.w_textrure_addr)
		exit (-666);
}

void	convert_e_texture(t_all *all)
{
	all->txtr.e_textrure_img = mlx_xpm_file_to_image(all->win.mlx,
			all->txtr.e_texture_path, &all->txtr.e_texture_attr[IMG_W],
			&all->txtr.e_texture_attr[IMG_H]);
	if (!all->txtr.e_textrure_img)
	{
		printf("Error\n%s\n", "Wrong texture path");
		exit (-666);
	}
	all->txtr.e_textrure_addr = mlx_get_data_addr(all->txtr.e_textrure_img,
			&all->win.bits_per_pixel,
			&all->txtr.e_texture_attr[IMG_LINE_LEN], &all->win.endian);
	if (!all->txtr.e_textrure_addr)
		exit (-666);
}

void	rotate_textures(t_all *all)
{
	rotate_img(all, &all->txtr.n_textrure_img,
		&all->txtr.n_textrure_addr, &all->txtr.n_texture_attr);
	rotate_img(all, &all->txtr.s_textrure_img,
		&all->txtr.s_textrure_addr, &all->txtr.s_texture_attr);
	rotate_img(all, &all->txtr.w_textrure_img,
		&all->txtr.w_textrure_addr, &all->txtr.w_texture_attr);
	rotate_img(all, &all->txtr.e_textrure_img,
		&all->txtr.e_textrure_addr, &all->txtr.e_texture_attr);
}
