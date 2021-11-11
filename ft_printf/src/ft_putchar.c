#include "../includes/ft_printf.h"

int	ft_putchar(char c, int fd)
{
	int	i;

	i = write(fd, &c, 1);
	return (i);
}
