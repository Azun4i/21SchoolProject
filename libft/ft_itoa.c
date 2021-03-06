#include "libft.h"

static int	ft_countintlen(long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		cnt++;
		n /= 10;
	}
	return (++cnt);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*str;

	i = n;
	len = ft_countintlen(i);
	if (i < 0)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	if (i < 0)
	{
		str[0] = '-';
		i = i * -1;
	}
	while (i >= 10)
	{
		str[--len] = (i % 10) + '0';
		i = i / 10;
	}
	str[--len] = i + '0';
	return (str);
}
