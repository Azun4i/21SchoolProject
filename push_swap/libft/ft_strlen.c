#include "libft.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count);
	if (str[count] == '\0')
		return (count);
	while (str[count] != '\0')
		count++;
	return (count);
}
