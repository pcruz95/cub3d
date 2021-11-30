#include "main.h"

void	player_init(t_plr *plr, int cell_size)
{
	plr->radius = (int)round(cell_size / 2.8);
	plr->turn_direction = 0;
	plr->walk_direction = 0;
	plr->strafe_direction = 0;
	plr->rotation_angle = 0;
	plr->normal_speed = (double)cell_size / 20.0;
	plr->diagonal_speed = plr->normal_speed / SQRT2;
	plr->move_speed = plr->normal_speed;
	plr->delta_x = cos(plr->rotation_angle) * plr->move_speed;
	plr->delta_y = sin(plr->rotation_angle) * plr->move_speed;
}
