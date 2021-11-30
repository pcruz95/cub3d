#include "main.h"

void	window_and_map_init(t_all *all)
{
	all->win.win2 = mlx_new_window(all->win.mlx,
			all->win.width, all->win.height, TITLE);
	if (!all->win.win2)
		exit (-666);
	all->win.img2 = mlx_new_image(all->win.mlx,
			all->win.width, all->win.height);
	if (!all->win.img2)
		exit (-666);
	all->win.addr2 = mlx_get_data_addr(all->win.img2,
			&all->win.bits_per_pixel, &all->win.line_length, &all->win.endian);
	if (!all->win.addr2)
		exit (-666);
	all->win.img = mlx_new_image(all->win.mlx,
			all->win.width, all->win.height);
	if (!all->win.img)
		exit (-666);
	all->win.addr = mlx_get_data_addr(all->win.img,
			&all->win.bits_per_pixel, &all->win.line_length, &all->win.endian);
	if (!all->win.addr)
		exit (-666);
}

void	mini_map_and_back_init(t_all *all)
{
	all->win.tmp_img = mlx_new_image(all->win.mlx,
			all->win.width, all->win.height);
	if (!all->win.tmp_img)
		exit (-666);
	all->win.tmp_addr = mlx_get_data_addr(all->win.tmp_img,
			&all->win.bits_per_pixel, &all->win.line_length, &all->win.endian);
	if (!all->win.tmp_addr)
		exit (-666);
	all->win.mini_map_img = mlx_new_image(all->win.mlx,
			all->map.mini_map_size, all->map.mini_map_size);
	if (!all->win.mini_map_img)
		exit (-666);
	all->win.mini_map_addr = mlx_get_data_addr(all->win.mini_map_img,
			&all->win.bits_per_pixel,
			&all->win.mini_map_line_length, &all->win.endian);
	if (!all->win.mini_map_addr)
		exit (-666);
	all->win.back_img = mlx_new_image(all->win.mlx,
			all->win.width, all->win.height);
	if (!all->win.back_img)
		exit (-666);
	all->win.back_addr = mlx_get_data_addr(all->win.back_img,
			&all->win.bits_per_pixel, &all->win.line_length, &all->win.endian);
	if (!all->win.back_addr)
		exit (-666);
}
