#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sing;

	num = 0;
	sing = 1;
	while (*str == ' ' || (*str == '\n' || *str =='\t'
			|| *str =='\v' || *str =='\f' || *str =='\r'))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str++;
		num -= '0';
	}
	return (num * sing);
}
