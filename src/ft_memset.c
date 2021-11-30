#include "main.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*(unsigned char *)ptr++ = (unsigned char)c;
	return (b);
}
