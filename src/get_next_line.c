#include "get_next_line.h"
#include "main.h"

char			*g_ptr_to_n;
char			*g_buffer;
ssize_t			g_bytes_was_read;

static int	next_string(char **remainder, char **line, char *g_ptr_to_n)
{
	char			*tmp;

	*line = ft_strdup(*remainder);
	if (!(*line))
		return (my_free(1, remainder, NULL));
	if (*g_ptr_to_n == 0)
	{
		my_free(1, remainder, NULL);
		return (1);
	}
	tmp = ft_strdup(g_ptr_to_n);
	free(*remainder);
	*remainder = tmp;
	return (1);
}

static int	final_string(char **remainder, char **line, char **g_buffer)
{
	*line = ft_strjoin(*line, *remainder);
	if (*remainder && !(*line))
		return (my_free(2, g_buffer, remainder));
	my_free(2, g_buffer, remainder);
	return (0);
}

static int	get_string(char **remainder, char **line, int fd)
{
	g_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!g_buffer)
		return (-1);
	g_bytes_was_read = read(fd, g_buffer, BUFFER_SIZE);
	while (g_bytes_was_read > 0)
	{
		g_buffer[g_bytes_was_read] = 0;
		*remainder = ft_strjoin(*remainder, g_buffer);
		if (!(*remainder))
			return (my_free(2, &g_buffer, remainder));
		g_ptr_to_n = ft_strchr(*remainder, '\n');
		if (g_ptr_to_n)
		{
			free(g_buffer);
			*g_ptr_to_n = 0;
			g_ptr_to_n++;
			return (next_string(remainder, line, g_ptr_to_n));
		}
		g_bytes_was_read = read(fd, g_buffer, BUFFER_SIZE);
	}
	*line = ft_strdup("");
	if (!(*line))
		return (my_free(2, remainder, &g_buffer));
	return (final_string(remainder, line, &g_buffer));
}

int	get_next_line(int fd, char **line)
{
	char			*g_ptr_to_n;
	static char		*remainder[MAX_FD];

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1
		|| fd < 0 || fd > MAX_FD || !line)
		return (-1);
	g_ptr_to_n = NULL;
	if (remainder[fd])
	{
		g_ptr_to_n = ft_strchr(remainder[fd], '\n');
		if (g_ptr_to_n)
		{
			*g_ptr_to_n = 0;
			g_ptr_to_n++;
			return (next_string(remainder + fd, line, g_ptr_to_n));
		}
	}
	return (get_string(remainder + fd, line, fd));
}
