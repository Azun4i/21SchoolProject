#include "libft.h"

int	ft_isalnum(int s)
{
	if ((s >= '0' && s <= '9')
		|| ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')))
		return (1);
	else
		return (0);
}
