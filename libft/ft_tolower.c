#include "libft.h"

int	ft_tolower(int s)
{
	if (s >= 65 && s <= 90)
		s += 32;
	return (s);
}
