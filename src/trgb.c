#include "main.h"

int	trgb(int t, int r, int g, int b)
{
	int		color;

	if ((t < 0 || t > 255)
		|| (r < 0 || r > 255)
		|| (g < 0 || g > 255)
		|| (b < 0 || b > 255))
		return (BLACK);
	color = 0;
	color |= (t << 24);
	color |= (r << 16);
	color |= (g << 8);
	color |= (b << 0);
	return (color);
}
