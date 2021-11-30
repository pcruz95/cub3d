#include "main.h"

static void	very_normal_function(int n, int *sign,
unsigned int *abs_n, int *length)
{
	*sign = 0;
	if (n < 0)
		*sign = 1;
	*abs_n = -n;
	if (n > 0)
		*abs_n = n;
	*length = 0;
	if ((n == 0) || *sign)
		*length = 1;
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	abs_n;
	int				length;
	char			*str;

	very_normal_function(n, &sign, &abs_n, &length);
	while (n)
	{
		n /= 10;
		length++;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	while (length-- > sign)
	{
		str[length] = abs_n % 10 + '0';
		abs_n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
