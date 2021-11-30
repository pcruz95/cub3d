#include "main.h"

static void	do_screenshot(t_all *all, char **argv)
{
	if (argv[2]
		&& !ft_strncmp(argv[2], "--save", ft_strlen("--save"))
		&& ft_strlen(argv[2]) == ft_strlen("--save"))
	{
		save_to_bmp(all);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_all	all;

	cub_parser(argv[1], &all);
	init(&all);
	sprts_init(&all);
	draw_map(&all);
	textures_init(&all);
	calculate_sprite_angle_and_distance(&all);
	set_background(all.win.back_addr, &all);
	copy_img(all.win.addr2, all.win.back_addr, all.win.half_all_pxls);
	cast_all_rays(&all);
	insertion_sort(all.sprt_indexies, all.nbr_sprt, &all);
	draw_all_sprites(&all);
	if (argc == 3)
		do_screenshot(&all, argv);
	mlx_hook(all.win.win2, 2, 1L << 0, check_key, &all);
	mlx_hook(all.win.win2, 3, 1L << 1, release_key, &all);
	mlx_hook(all.win.win2, 17, 1L << 0, close_win, &all);
	mlx_loop_hook(all.win.mlx, draw, &all);
	mlx_loop(all.win.mlx);
}
