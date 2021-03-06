#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if ((ft_strlen(str1) || ft_strlen(str2)) == 0)
	{
		return (0);
	}
	while ((str1[i] || str2[i] != '\0') && (i < size))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
