#include "main.h"

#define NBR_SETTING_LINES 8

static void	pre_init(t_all *all, int *sttngs)
{
	*sttngs = NBR_SETTING_LINES;
	all->win.width = -1;
	all->win.height = -1;
	all->win.floor_color = 0;
	all->win.ceiling_color = 0;
}

static void	setup_parameters(t_all *all, char **line, int *sttngs)
{
	if ('R' == **line)
		set_resolution(line, all, sttngs);
	if ('N' == (*line)[0] && 'O' == (*line)[1])
		set_north_texture(line, all, sttngs);
	if ('S' == (*line)[0] && 'O' == (*line)[1])
		set_south_texture(line, all, sttngs);
	if ('W' == (*line)[0] && 'E' == (*line)[1])
		set_west_texture(line, all, sttngs);
	if ('E' == (*line)[0] && 'A' == (*line)[1])
		set_east_texture(line, all, sttngs);
	if ('S' == (*line)[0] && ' ' == (*line)[1])
		set_sprite_texture(line, all, sttngs);
	if ('F' == **line)
		floor_color(line, all, sttngs);
	if ('C' == **line)
		ceiling_color(line, all, sttngs);
}

void	resolution_and_textures_path(int *fd, t_all *all)
{
	char	*line;
	int		gnl_returns;
	int		sttngs;

	pre_init(all, &sttngs);
	gnl_returns = get_next_line(*fd, &line);
	while (gnl_returns > 0 && sttngs)
	{
		setup_parameters(all, &line, &sttngs);
		free(line);
		gnl_returns = get_next_line(*fd, &line);
	}
	if (gnl_returns == -1)
		exit (-666);
	if (sttngs)
	{
		printf("Error\n%s\n", "Insufficient parameters");
		exit (-666);
	}
	free(line);
}
