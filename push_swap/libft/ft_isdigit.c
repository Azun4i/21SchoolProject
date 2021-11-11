#include "libft.h"

int	ft_isdigit(int s)
{
	if (s >= '0' && s <= '9')
		return (1);
	else
		return (0);
}
