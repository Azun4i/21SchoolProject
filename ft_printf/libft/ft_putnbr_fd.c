#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	s;

	i = n;
	if (i < 0)
	{
		i *= -1;
		write(fd, "-", 1);
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	s = (i % 10) + 48;
	write(fd, &s, 1);
}
