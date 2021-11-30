#include "main.h"

static void	normalize_resolution(t_all *all)
{
	if (all->win.width < 100)
		all->win.width = 100;
	if (all->win.height < 100)
		all->win.height = 100;
	if (all->win.width > MAX_WIDTH)
		all->win.width = MAX_WIDTH;
	if (all->win.height > MAX_HEIGHT)
		all->win.height = MAX_HEIGHT;
}

void	set_resolution(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp++;
	if (' ' != *tmp)
	{
		printf("Error\n%s\n", "Wrong resolution");
		exit(-666);
	}
	all->win.width = ft_atoi(tmp);
	while ((*tmp < '0' || *tmp > '9') && *tmp)
		tmp++;
	while ((' ' != *tmp) && *tmp)
		tmp++;
	if (*tmp)
		all->win.height = ft_atoi(tmp);
	tmp = *line;
	if (all->win.width < 0 || all->win.height < 0)
	{
		printf("Error\n%s\n", "Wrong resolution");
		exit (-666);
	}
	normalize_resolution(all);
	(*sttngs)--;
}
