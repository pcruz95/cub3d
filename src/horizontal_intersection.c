#include "main.h"

t_pnt	horizontal_intersection(t_all *all)
{
	t_pnt	intercept;

	intercept.y = (int)all->plr.pos.y
		/ (int)all->map.cell_size * all->map.cell_size;
	intercept.y += all->rays.isRayFacingDown * all->map.cell_size;
	intercept.x = all->plr.pos.x
		+ (intercept.y - all->plr.pos.y) / all->rays.tan_ray_angle;
	all->rays.h_xstep = all->map.cell_size / all->rays.tan_ray_angle;
	if (all->rays.isRayFacingLeft && all->rays.h_xstep >= 0)
		all->rays.h_xstep *= -1;
	if (!all->rays.isRayFacingLeft && all->rays.h_xstep < 0)
		all->rays.h_xstep *= -1;
	if (!all->rays.isRayFacingDown)
		all->rays.h_ystep = -all->map.cell_size;
	else
		all->rays.h_ystep = +all->map.cell_size;
	return (intercept);
}
