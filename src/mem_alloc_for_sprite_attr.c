#include "main.h"

void	set_sprt_indexes(t_all *all)
{
	int		i;

	all->sprt_indexies = (int *)malloc(sizeof(int) * all->nbr_sprt);
	if (!all->sprt_indexies)
	{
		printf("Error\nMALLOC FAILURE");
		exit (-666);
	}
	i = 0;
	while (i < all->nbr_sprt)
	{
		all->sprt_indexies[i] = i;
		i++;
	}
}

void	mem_alloc_for_sprite_attr(t_all *all)
{
	int		sprt_id;

	sprt_id = 0;
	while (sprt_id < all->nbr_sprt)
	{
		all->sprt[sprt_id].sprite_attr
			= (int *)malloc(SIZE_IMG_ATTR * sizeof(int));
		if (!all->sprt[sprt_id].sprite_attr)
		{
			printf("Error\n%s\n", "MALLOC FAILURE");
			exit(-666);
		}
		sprt_id++;
	}
}

void	convert_sprt_to_img(t_all *all)
{
	int		sprt_id;

	sprt_id = 0;
	while (sprt_id < all->nbr_sprt)
	{
		all->sprt[sprt_id].sprite_img = mlx_xpm_file_to_image(all->win.mlx,
				all->sprite_texture_path,
				&all->sprt[sprt_id].sprite_attr[IMG_W],
				&all->sprt[sprt_id].sprite_attr[IMG_H]);
		if (!all->sprt[sprt_id].sprite_img)
		{
			printf("Error\n%s\n", "Wrong texture path");
			exit (-666);
		}
		all->sprt[sprt_id].sprite_addr
			= mlx_get_data_addr(all->sprt[sprt_id].sprite_img,
				&all->win.bits_per_pixel,
				&all->sprt[sprt_id].sprite_attr[IMG_LINE_LEN],
				&all->win.endian);
		if (!all->sprt[sprt_id].sprite_addr)
			exit(-666);
		sprt_id++;
	}
}

void	calculate_sprite_ratio(t_all *all)
{
	int	sprt_id;

	sprt_id = 0;
	while (sprt_id < all->nbr_sprt)
	{
		all->sprt[sprt_id].sprt_ratio
			= (double)all->sprt[sprt_id].sprite_attr[IMG_W]
			/ all->sprt[sprt_id].sprite_attr[IMG_H];
		sprt_id++;
	}
}
