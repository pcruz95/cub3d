#include "main.h"

char	*strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}
