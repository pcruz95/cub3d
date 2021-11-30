#include "main.h"

void	set_north_texture(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp += 2;
	if (' ' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	while (*tmp && ' ' == *tmp)
		tmp++;
	if ('.' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	all->txtr.n_texture_path = ft_strdup(tmp);
	(*sttngs)--;
}

void	set_south_texture(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp += 2;
	if (' ' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	while (*tmp && ' ' == *tmp)
		tmp++;
	if ('.' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	all->txtr.s_texture_path = ft_strdup(tmp);
	(*sttngs)--;
}

void	set_west_texture(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp += 2;
	if (' ' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	while (*tmp && ' ' == *tmp)
		tmp++;
	if ('.' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	all->txtr.w_texture_path = ft_strdup(tmp);
	(*sttngs)--;
}

void	set_east_texture(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp += 2;
	if (' ' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	while (*tmp && ' ' == *tmp)
		tmp++;
	if ('.' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	all->txtr.e_texture_path = ft_strdup(tmp);
	(*sttngs)--;
}

void	set_sprite_texture(char **line, t_all *all, int *sttngs)
{
	char	*tmp;

	tmp = *line;
	tmp++;
	while (*tmp && ' ' == *tmp)
		tmp++;
	if ('.' != *tmp)
	{
		printf("Error\n%s\n", "Wrong texture path");
		free(*line);
		exit(-666);
	}
	all->sprite_texture_path = ft_strdup(tmp);
	(*sttngs)--;
}
