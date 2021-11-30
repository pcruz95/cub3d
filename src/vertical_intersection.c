#include "main.h"

t_pnt	vertical_intersection(t_all *all)
{
	t_pnt	intercept;

	intercept.x = (int)all->plr.pos.x
		/ (int)all->map.cell_size * all->map.cell_size;
	if (!all->rays.isRayFacingLeft)
		intercept.x += all->map.cell_size;
	intercept.y = all->plr.pos.y
		+ (intercept.x - all->plr.pos.x) * all->rays.tan_ray_angle;
	if (all->rays.isRayFacingLeft)
		all->rays.v_xstep = -all->map.cell_size;
	else
		all->rays.v_xstep = all->map.cell_size;
	all->rays.v_ystep = all->map.cell_size * all->rays.tan_ray_angle;
	if (!all->rays.isRayFacingDown && all->rays.v_ystep >= 0)
		all->rays.v_ystep *= -1;
	if (all->rays.isRayFacingDown && all->rays.v_ystep < 0)
		all->rays.v_ystep *= -1;
	return (intercept);
}
