#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = n;
	while (i != 0)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
		i--;
	}
	return (s - n);
}
