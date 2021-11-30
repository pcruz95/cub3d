#include "main.h"

static void	normalnaya_function(t_all *all)
{
	all->rgb.red = -1;
	all->rgb.green = -1;
	all->rgb.blue = -1;
}

static void	parse_rgb(t_all *all, char **line)
{
	all->rgb.tmp = *line;
	all->rgb.tmp++;
	if (' ' != *all->rgb.tmp)
	{
		printf("Error\n%s\n", "Wrong color");
		free(*line);
		exit(666);
	}
	all->rgb.red = ft_atoi(all->rgb.tmp);
	while ((',' != *all->rgb.tmp) && *all->rgb.tmp)
		all->rgb.tmp++;
	all->rgb.green = ft_atoi(++all->rgb.tmp);
	while ((',' != *all->rgb.tmp) && *all->rgb.tmp)
		all->rgb.tmp++;
	all->rgb.blue = ft_atoi(++all->rgb.tmp);
	if ((all->rgb.red < 0 || all->rgb.red > 255)
		|| (all->rgb.green < 0 || all->rgb.green > 255)
		|| (all->rgb.blue < 0 || all->rgb.blue > 255))
	{
		printf("Error\n%s\n", "Wrong color");
		free(*line);
		exit (666);
	}
}

void	floor_color(char **line, t_all *all, int *sttngs)
{
	normalnaya_function(all);
	parse_rgb(all, line);
	all->win.floor_color = trgb(0, all->rgb.red, all->rgb.green, all->rgb.blue);
	(*sttngs)--;
}

void	ceiling_color(char **line, t_all *all, int *sttngs)
{
	normalnaya_function(all);
	parse_rgb(all, line);
	all->win.ceiling_color = trgb(0, all->rgb.red,
			all->rgb.green, all->rgb.blue);
	(*sttngs)--;
}
