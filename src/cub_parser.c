#include "main.h"

static void	fill_map(t_all *all)
{
	int		i;

	i = 0;
	all->map.node = all->map.head;
	while (all->map.node)
	{
		all -> map.map[i] = ft_strdup(all->map.node -> line);
		if (!all -> map.map[i])
		{
			i -= 1;
			clear_map(all, i);
			clear_list(all->map.head);
			exit (-666);
		}
		all->map.node = all->map.node -> next_node;
		i++;
	}
	all -> map.map[i] = NULL;
	clear_list(all->map.head);
	map_check(all);
}

static void	read_map(t_all *all)
{
	int		gnl_ret;

	gnl_ret = 0;
	all->map.map_height = 0;
	all->map.head = init_list(NULL);
	all->map.node = all->map.head;
	resolution_and_textures_path(&all->map.fd, all);
	gnl_ret = get_next_line(all->map.fd, &all->map.node -> line);
	while (gnl_ret > 0)
	{
		append_to_list(all->map.head, NULL);
		all->map.node = all->map.node -> next_node;
		gnl_ret = get_next_line(all->map.fd, &all->map.node -> line);
	}
	if (gnl_ret == -1)
	{
		clear_list(all->map.head);
		exit (-666);
	}
}

static void	calculate_width_height(t_all *all)
{
	size_t	current_length;

	all->map.map_width = 0;
	all->map.node = all->map.head;
	while (all->map.node)
	{
		current_length = ft_strlen(all->map.node->line);
		if (current_length > (size_t)all->map.map_width)
			all->map.map_width = current_length;
		all->map.map_height++;
		all->map.node = all->map.node -> next_node;
	}
	if (all->map.map_height >= 60 || all->map.map_width >= 100)
	{
		clear_list(all->map.head);
		printf("Error\nMAP iS TOO BIG!");
		exit (-666);
	}
	all -> map.map = (char **)malloc(sizeof(char *)
			* (all->map.map_height + 1));
	if (!all -> map.map)
	{
		clear_list(all->map.head);
		exit (-666);
	}
}

void	cub_parser(char *str, t_all *all)
{
	int		i;

	i = 0;
	if (str)
	{
		i = 0;
		while (str[i] != '.' && str[i] != '\x00')
			i++;
		if (str[i] == '\x00' || str[i + 1] != 'c' || str[i + 2] != 'u'
			|| str[i + 3] != 'b' || str[i + 4] != '\x00')
		{
			printf("Error\nFile extension it not \".cub\"\n");
			exit (-666);
		}
	}
	all->map.fd = open(str, O_RDONLY);
	read_map(all);
	calculate_width_height(all);
	fill_map(all);
}

void	clear_map(t_all *all, int i)
{
	while (i >= 0)
		free(all -> map.map[i--]);
	free(all -> map.map);
}
