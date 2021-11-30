#include "main.h"

void	calculate_sprite_angle_and_distance(t_all *all)
{
	int	sprt_id;	

	sprt_id = 0;
	while (sprt_id < all->nbr_sprt)
	{
		all->sprt[sprt_id].dir = atan2(
				all->sprt[sprt_id].position.y - all->plr.pos.y,
				all->sprt[sprt_id].position.x - all->plr.pos.x);
		all->sprt[sprt_id].dist = sqrt(
				(all->plr.pos.x - all->sprt[sprt_id].position.x)
				* (all->plr.pos.x - all->sprt[sprt_id].position.x)
				+ (all->plr.pos.y - all->sprt[sprt_id].position.y)
				* (all->plr.pos.y - all->sprt[sprt_id].position.y));
		all->sprt[sprt_id].diff_angle = all->sprt[sprt_id].dir
			- all->plr.rotation_angle;
		if (all->sprt[sprt_id].diff_angle > PI)
			all->sprt[sprt_id].diff_angle -= PI2;
		if (all->sprt[sprt_id].diff_angle < -PI)
			all->sprt[sprt_id].diff_angle += PI2;
		sprt_id++;
	}
}
