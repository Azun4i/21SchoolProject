#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mas;

	mas = malloc(nmemb * size);
	if (!(mas))
		return (NULL);
	ft_memset(mas, 0, nmemb * size);
	return (mas);
}
