#include "main.h"

int	close_win(t_all *all)
{
	mlx_destroy_image(all->win.mlx, all->win.img2);
	mlx_destroy_image(all->win.mlx, all->win.img);
	mlx_destroy_image(all->win.mlx, all->win.tmp_img);
	mlx_destroy_image(all->win.mlx, all->win.mini_map_img);
	mlx_destroy_image(all->win.mlx, all->win.back_img);
	mlx_destroy_window(all->win.mlx, all->win.win2);
	exit(EXIT_SUCCESS);
}
