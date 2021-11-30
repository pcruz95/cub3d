#include "main.h"

int	my_free(int i, char **ptr1, char **ptr2)
{
	if (*ptr1 == NULL)
		return (-1);
	free(*ptr1);
	*ptr1 = NULL;
	ptr1 = NULL;
	if (i == 2)
	{
		if (*ptr2 == NULL)
			return (-1);
		free(*ptr2);
		*ptr2 = NULL;
		ptr2 = NULL;
	}
	return (-1);
}
