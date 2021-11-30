#include "main.h"

static void	calculate_ray_angle(t_all *all, long i)
{
	all->rays.ray_angle = all->plr.rotation_angle
		+ atan(((double)(i - all->win.half_width)) / all->rays.dist2screen);
	if (all->rays.ray_angle < 0)
		all->rays.ray_angle += PI2;
	if (all->rays.ray_angle > PI2)
		all->rays.ray_angle -= PI2;
	all->rays.isRayFacingDown = 0;
	if (all->rays.ray_angle <= PI)
		all->rays.isRayFacingDown = 1;
	all->rays.isRayFacingLeft = 0;
	if (all->rays.ray_angle > PI_DIV_2 && all->rays.ray_angle < 1.5 * PI)
		all->rays.isRayFacingLeft = 1;
	all->rays.tan_ray_angle = tan(all->rays.ray_angle);
}

static void	calculate_h_distance(t_all *all)
{
	while (all->rays.Hdistance <= all->rays.Vdistance)
	{
		if (all->rays.horz_intrcpt.x > 0
			&& all->rays.horz_intrcpt.x < all->win.width
			&& all->rays.horz_intrcpt.y > 0
			&& all->rays.horz_intrcpt.y < all->win.height
			&& WHITE == *(calculate_map_address(all, all->rays.horz_intrcpt.x,
					all->rays.horz_intrcpt.y - !all->rays.isRayFacingDown)))
		{
			all->rays.found_horz_wall = 1;
			all->rays.real_distance = all->rays.Hdistance;
			all->rays.wall_color = 0x66;
			break ;
		}
		all->rays.horz_intrcpt.x += all->rays.h_xstep;
		all->rays.horz_intrcpt.y += all->rays.h_ystep;
		all->rays.x_projection = all->rays.horz_intrcpt.x - all->plr.pos.x;
		all->rays.y_projection = all->rays.horz_intrcpt.y - all->plr.pos.y;
		all->rays.Hdistance = sqrt(all->rays.x_projection
				* all->rays.x_projection + all->rays.y_projection
				* all->rays.y_projection);
	}
}

static void	calculate_v_distance(t_all *all)
{
	while (all->rays.Vdistance < all->rays.Hdistance)
	{
		if (all->rays.vert_intrcpt.x > 0
			&& all->rays.vert_intrcpt.x < all->win.width
			&& all->rays.vert_intrcpt.y > 0
			&& all->rays.vert_intrcpt.y < all->win.height
			&& WHITE == *(calculate_map_address(all,
					all->rays.vert_intrcpt.x - all->rays.isRayFacingLeft,
					all->rays.vert_intrcpt.y)))
		{
			all->rays.found_vert_wall = 1;
			all->rays.real_distance = all->rays.Vdistance;
			all->rays.wall_color = 0x88;
			break ;
		}
		all->rays.vert_intrcpt.x += all->rays.v_xstep;
		all->rays.vert_intrcpt.y += all->rays.v_ystep;
		all->rays.x_projection = all->rays.vert_intrcpt.x - all->plr.pos.x;
		all->rays.y_projection = all->rays.vert_intrcpt.y - all->plr.pos.y;
		all->rays.Vdistance = sqrt(all->rays.x_projection
				* all->rays.x_projection + all->rays.y_projection
				* all->rays.y_projection);
	}
}

static void	find_h_v_intersection(t_all *all)
{
	all->rays.found_horz_wall = 0;
	all->rays.found_vert_wall = 0;
	all->rays.horz_intrcpt = horizontal_intersection(all);
	all->rays.vert_intrcpt = vertical_intersection(all);
	all->rays.x_projection = all->rays.vert_intrcpt.x - all->plr.pos.x;
	all->rays.y_projection = all->rays.vert_intrcpt.y - all->plr.pos.y;
	all->rays.Vdistance = sqrt(all->rays.x_projection * all->rays.x_projection
			+ all->rays.y_projection * all->rays.y_projection);
	all->rays.x_projection = all->rays.horz_intrcpt.x - all->plr.pos.x;
	all->rays.y_projection = all->rays.horz_intrcpt.y - all->plr.pos.y;
	all->rays.Hdistance = sqrt(all->rays.x_projection * all->rays.x_projection
			+ all->rays.y_projection * all->rays.y_projection);
}

void	cast_all_rays(t_all *all)
{
	long		i;

	i = 0;
	while (i < all->win.width)
	{
		calculate_ray_angle(all, i);
		find_h_v_intersection(all);
		while (!all->rays.found_horz_wall && !all->rays.found_vert_wall)
		{
			calculate_h_distance(all);
			calculate_v_distance(all);
		}
		all->rays.real_distance *= cos(all->plr.rotation_angle
				- all->rays.ray_angle);
		all->rays.Projected_Slice_Height = (all->map.cell_size
				/ all->rays.real_distance)
			* all->rays.dist2screen;
		put_slice(i, lround(all->rays.Projected_Slice_Height / 2), all);
		all->ray_distances[i] = all->rays.real_distance;
		i++;
	}
}
