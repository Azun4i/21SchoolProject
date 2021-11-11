#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n-- > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
	}
	return (dest - i);
}
