#include "libft.h"

int	ft_toupper(int s)
{
	if (s >= 97 && s <= 122)
		s -= 32;
	return (s);
}
