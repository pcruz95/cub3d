#include "main.h"

#define HEADER_SIZE 54

static void	create_header(t_all *all, int size, int fd)
{
	unsigned char	header[HEADER_SIZE];

	ft_memset(header, 0, HEADER_SIZE);
	header[0] = (unsigned char) 'B';
	header[1] = (unsigned char) 'M';
	header[2] = (unsigned char)size;
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)all->win.width;
	header[19] = (unsigned char)(all->win.width >> 8);
	header[20] = (unsigned char)(all->win.width >> 16);
	header[21] = (unsigned char)(all->win.width >> 24);
	header[22] = (unsigned char)all->win.height;
	header[23] = (unsigned char)(all->win.height >> 8);
	header[24] = (unsigned char)(all->win.height >> 16);
	header[25] = (unsigned char)(all->win.height >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, HEADER_SIZE);
}

static void	write_img_data(t_all *all, int fd)
{
	unsigned int		color;
	int					y;
	int					x;

	y = all->win.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->win.width)
		{
			color = *((unsigned int *)all->win.addr2 + y * all->win.width + x);
			write(fd, &color, 3);
			x++;
		}
		y--;
	}
}

void	save_to_bmp(t_all *all)
{
	static int	screenshot_id;
	int			size;

	all->screenshot.corrected_width = all->win.width - (all->win.width % 4);
	all->screenshot.tmp = ft_itoa(screenshot_id);
	all->screenshot.filename = strjoin("screenshot_", all->screenshot.tmp);
	free(all->screenshot.tmp);
	all->screenshot.tmp = all->screenshot.filename;
	all->screenshot.filename = strjoin(all->screenshot.filename, ".bmp");
	free(all->screenshot.tmp);
	size = 54 + all->win.height * all->screenshot.corrected_width;
	all->screenshot.fd = open(all->screenshot.filename, O_CREAT | O_RDWR, 0666);
	if (all->screenshot.fd <= 0)
		printf("Error\n%s\n", "Failed to save screenshot");
	create_header(all, size, all->screenshot.fd);
	write_img_data(all, all->screenshot.fd);
	close(all->screenshot.fd);
	printf("Saved to %s\n", all->screenshot.filename);
	free(all->screenshot.filename);
	screenshot_id += 1;
}
