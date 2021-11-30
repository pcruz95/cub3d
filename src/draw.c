#include "main.h"

static void	check_collision(t_all *all)
{
	unsigned int	map_color_x;
	unsigned int	map_color_y;

	map_color_x = *(calculate_map_address(all,
				all->plr.pos.x, all->plr.old_position.y));
	map_color_y = *(calculate_map_address(all,
				all->plr.old_position.x, all->plr.pos.y));
	if (COLLIDER == map_color_x || WHITE == map_color_x)
		all->plr.pos.x = all->plr.old_position.x;
	if (COLLIDER == map_color_y || WHITE == map_color_y)
		all->plr.pos.y = all->plr.old_position.y;
	if (all->plr.pos.x < 0 || all->plr.pos.y < 0)
		all->plr.pos = all->plr.old_position;
}

static void	draw_player(t_all *all)
{
	t_pnt_int	player_line_start;
	t_pnt_int	player_line_stop;

	player_line_start.x = round(all->plr.pos.x);
	player_line_start.y = round(all->plr.pos.y);
	player_line_stop.x = round(all->plr.pos.x
			+ cos(all->plr.rotation_angle) * all->map.cell_size * 2);
	player_line_stop.y = round(all->plr.pos.y
			+ sin(all->plr.rotation_angle) * all->map.cell_size * 2);
	player_line(player_line_start, player_line_stop, all, RED);
	circumference(all, all->plr.pos, all->plr.radius, GREEN);
}

static void	control(t_all *all)
{
	all->plr.walk_direction = (all->key_flags & W) / W
		- (all->key_flags & S) / S;
	all->plr.turn_direction = (all->key_flags & RIGHT_ARROW) / RIGHT_ARROW
		- (all->key_flags & LEFT_ARROW) / LEFT_ARROW;
	all->plr.strafe_direction = (all->key_flags & D) / D
		- (all->key_flags & A) / A;
	if (all->key_flags & ESC)
		close_win(all);
}

int	draw(t_all *all)
{
	control(all);
	all->plr.old_position = all->plr.pos;
	circumference(all, all->plr.pos, all->plr.radius, GREEN);
	player_update(&all->plr, all->key_flags);
	check_collision(all);
	copy_img(all->win.addr2, all->win.back_addr, all->win.half_all_pxls);
	cast_all_rays(all);
	copy_map(all->win.addr, all->win.tmp_addr, all);
	insertion_sort(all->sprt_indexies, all->nbr_sprt, all);
	draw_all_sprites(all);
	draw_player(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win2, all->win.img2, 0, 0);
	copy_mini_map(all->win.mini_map_addr, all->win.addr, all);
	mlx_put_image_to_window(all->win.mlx,
		all->win.win2, all->win.mini_map_img, 0, 0);
	calculate_sprite_angle_and_distance(all);
	return (0);
}
