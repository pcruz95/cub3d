#include "main.h"

static void	mem_alloc_for_txtr_attr(t_all *all)
{
	all->txtr.n_texture_attr = (int *)malloc(SIZE_IMG_ATTR * sizeof(int));
	if (all->txtr.n_texture_attr == NULL)
	{
		printf("Error\n%s\n", "MALLOC FAILURE");
		exit(-666);
	}
	all->txtr.s_texture_attr = (int *)malloc(SIZE_IMG_ATTR * sizeof(int));
	if (all->txtr.s_texture_attr == NULL)
	{
		printf("Error\n%s\n", "MALLOC FAILURE");
		exit(-666);
	}
	all->txtr.w_texture_attr = (int *)malloc(SIZE_IMG_ATTR * sizeof(int));
	if (all->txtr.w_texture_attr == NULL)
	{
		printf("Error\n%s\n", "MALLOC FAILURE");
		exit(-666);
	}
	all->txtr.e_texture_attr = (int *)malloc(SIZE_IMG_ATTR * sizeof(int));
	if (all->txtr.e_texture_attr == NULL)
	{
		printf("Error\n%s\n", "MALLOC FAILURE");
		exit(-666);
	}
}

void	textures_init(t_all *all)
{
	mem_alloc_for_txtr_attr(all);
	mem_alloc_for_sprite_attr(all);
	convert_n_texture(all);
	convert_s_texture(all);
	convert_w_texture(all);
	convert_e_texture(all);
	convert_sprt_to_img(all);
	calculate_sprite_ratio(all);
	rotate_textures(all);
	set_sprt_indexes(all);
}
