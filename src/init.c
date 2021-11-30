#include "main.h"

void	init(t_all *all)
{
	all->win.ratio = (double)all->win.width / all->win.height;
	all->key_flags = 0;
	all->map.cell_size = (all->win.width) / 100;
	all->map.mini_map_size = all->map.cell_size * 20;
	all->map.plr_square = all->map.cell_size * 5;
	player_init(&all->plr, all->map.cell_size);
	all->win.all_pxls = all->win.width * all->win.height;
	all->win.half_all_pxls = all->win.all_pxls / 2;
	all->win.half_width = all->win.width / 2;
	all->win.half_height = all->win.height / 2;
	all->win.bits_per_pixel = BITS_PER_PIXEL;
	all->ray_distances = (double *)malloc(sizeof(double) * all->win.width);
	if (!all->ray_distances)
	{
		printf("Error\nMALLOC FAILURE");
		exit (-666);
	}
	all->rays.dist2screen = all->win.half_width / TAN_FOV2;
	all->win.mlx = mlx_init();
	if (!all->win.mlx)
		exit (-666);
	window_and_map_init(all);
	mini_map_and_back_init(all);
	all->win.line_length_ints = all->win.line_length / 4;
}
