#include "../includes/ft_printf.h"

void	fft_xX_point(t_flag *ptr, char **dict)
{
	if (ptr->accur == 0)
		*dict[0] = '\0';
	else
		*dict[0] = '0';
	ptr->num = ft_strdup(*dict);
	dict = ft_free(*dict);
}

int	ft_count_hex(unsigned long long i)
{
	int	len;

	len = 0;
	if (i == 0)
	{
		len++;
		return (len);
	}
	while (i)
	{
		i = i / 16;
		len++;
	}
	return (len);
}

int	ft_countintlen(long n)
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
	if (n < 10)
		cnt++;
	return (cnt);
}

int	ft_putstr(char *s, int len)
{
	int	i;
	int	q;

	i = -1;
	q = 0;
	if (!s)
		return (-1);
	while (++i < len && s[i] != '\0')
		q += write(1, &s[i], 1);
	return (q);
}

void	*ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}
