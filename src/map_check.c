#include "main.h"

static void	check_symbols(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (all->map.map[y])
	{
		x = 0;
		while (all->map.map[y][x])
		{
			if (!ft_strchr(" 012NSWE", all->map.map[y][x]))
			{
				printf("Error\n%s\n", "WRONG MAP");
				exit(-666);
			}
			x++;
		}
		y++;
	}
}

static void	normal_f(t_all *all, int *x, int *y, int *find_player)
{
	if ((all->map.map[*y][*x] == '0' || all->map.map[*y][*x] == '2')
	&& (*y == 0 || *x == 0 || *y == all->map.map_height - 1
	|| *x == (int)ft_strlen(all->map.map[*y]) - 1
	|| all->map.map[*y][*x - 1] == ' '
	|| all->map.map[*y][*x + 1] == ' '
	|| (int)ft_strlen(all->map.map[*y - 1]) < *x + 1
	|| (int)ft_strlen(all->map.map[*y + 1]) < *x + 1
	|| all->map.map[*y - 1][*x] == ' '
	|| all->map.map[*y + 1][*x] == ' '))
	{
		printf("Error\n%s\n", "WRONG MAP");
		exit(-666);
	}
	if (all->map.map[*y][*x] == 'W' || all->map.map[*y][*x] == 'N'
		|| all->map.map[*y][*x] == 'S' || all->map.map[*y][*x] == 'E')
	{
		if (!*find_player)
			*find_player = 1;
		else
		{
			printf("Error\n%s\n", "WRONG MAP");
			exit(-666);
		}
	}
}

void	map_check(t_all *all)
{
	int		find_player;	
	int		x;
	int		y;

	check_symbols(all);
	y = 0;
	find_player = 0;
	while (all->map.map[y])
	{
		if (!(ft_strchr(all->map.map[y], '1'))
			&& y != all->map.map_height - 1)
		{
			printf("Error\n%s\n", "EMPTY LINE");
			exit(-666);
		}
		x = 0;
		while (all->map.map[y][x])
		{
			normal_f(all, &x, &y, &find_player);
			x++;
		}
		y++;
	}
}
