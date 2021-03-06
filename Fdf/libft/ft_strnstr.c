#include "libft.h"

char	*ft_strnstr(const char *haystack, const	char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (needle[k] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			while (haystack[i + k] == needle[k] && (i + k) < len)
			{
				k++;
				if (needle[k] == '\0')
					return ((char *) &haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
