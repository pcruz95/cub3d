#include "main.h"

void	draw_all_sprites(t_all *all)
{
	int		sprt_id;

	sprt_id = all->nbr_sprt - 1;
	while (sprt_id >= 0)
	{
		put_sprite(all, all->sprt_indexies[sprt_id]);
		sprt_id--;
	}
}
