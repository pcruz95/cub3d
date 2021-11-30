#include "main.h"

void	player_update(t_plr *plr, int key_flags)
{
	plr->move_speed = plr->normal_speed;
	if (key_flags & SHIFT)
		plr->move_speed *= 2;
	plr->rotation_angle += ROTATION_SPEED * plr->turn_direction;
	if (plr->rotation_angle < PI)
		plr->rotation_angle += PI2;
	if (plr->rotation_angle > PI)
		plr->rotation_angle -= PI2;
	plr->delta_x = cos(plr->rotation_angle) * plr->move_speed;
	plr->delta_y = sin(plr->rotation_angle) * plr->move_speed;
	plr->pos.x += plr->delta_x * plr->walk_direction;
	plr->pos.y += plr->delta_y * plr->walk_direction;
	if (plr->strafe_direction && plr->walk_direction)
		plr->move_speed /= SQRT2;
	if (LEFT == plr->strafe_direction)
	{
		plr->pos.x += cos(plr->rotation_angle - PI_DIV_2) * plr->move_speed;
		plr->pos.y += sin(plr->rotation_angle - PI_DIV_2) * plr->move_speed;
	}
	if (RIGHT == plr->strafe_direction)
	{
		plr->pos.x += cos(plr->rotation_angle + PI_DIV_2) * plr->move_speed;
		plr->pos.y += sin(plr->rotation_angle + PI_DIV_2) * plr->move_speed;
	}
}
