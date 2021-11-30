#include "main.h"

static void	normalnaya_function(t_all *all, t_pnt point, int sprt_id)
{
	all->sprt[sprt_id].position.x = point.x + all->map.cell_size / 2;
	all->sprt[sprt_id].position.y = point.y + all->map.cell_size / 2;
	put_cell(all, point, COLLIDER);
	circumference(all, all->sprt[sprt_id].position,
		all->map.cell_size / 4, BLUE);
}

static int	count_sprites(t_all *all)
{
	int		x;
	int		y;

	all->nbr_sprt = 0;
	x = 0;
	y = 0;
	while (all->map.map[y])
	{
		x = 0;
		while (all->map.map[y][x])
		{
			if (all->map.map[y][x] == '2')
				all->nbr_sprt++;
			x++;
		}
		y++;
	}
	return (all->nbr_sprt);
}

static void	set_sprt_pos(t_all *all)
{
	t_pnt	point;
	int		x;
	int		y;
	int		sprt_id;

	sprt_id = 0;
	x = 0;
	y = 0;
	while (all->map.map[y])
	{
		x = 0;
		point.x = 0;
		while (all->map.map[y][x])
		{
			if (all->map.map[y][x] == '2')
			{
				normalnaya_function(all, point, sprt_id);
				sprt_id++;
			}
			point.x += all->map.cell_size;
			x++;
		}
		point.y += all->map.cell_size;
		y++;
	}
}

void	sprts_init(t_all *all)
{
	count_sprites(all);
	all->sprt = (t_sprt *)malloc(sizeof(t_sprt) * all->nbr_sprt);
	if (!all->sprt)
	{
		printf("Error\nMALLOC FAILURE");
		exit (-666);
	}
	set_sprt_pos(all);
}
