#include "../includes/ft_printf.h"

void	fft_if_spas(t_flag *ptr, char **str)
{
	ptr->space = 1;
	ptr->wight = 1;
	while (**str == ' ')
		(*str)++;
}

void	fft_if_zero(t_flag *ptr, char **str)
{
	ptr->zero = 1;
	while (**str == '0')
		(*str)++;
}

void	in_to(unsigned long long q, t_flag *ptr)
{
	int		bag;
	int		len;
	char	*dict;

	len = ft_count_hex(q);
	dict = (char *) malloc(len + 1);
	if (!dict)
		return ;
	dict[len--] = '\0';
	if (q == 0)
		return (fft_xX_zero(ptr, &dict));
	while (q)
	{
		bag = q % 16;
		if (*ptr->ptr_s == 'x')
			dict[len--] = ptr->dict_low[bag];
		else if (*ptr->ptr_s == 'X')
			dict[len--] = ptr->dict_app[bag];
		q = q / 16;
	}
	ptr->num = ft_strdup(dict);
	dict = ft_free(dict);
}

void	fft_xX_zero(t_flag *ptr, char **dict)
{
	if (ptr->accur == 0 && ptr->wight > 0)
		*dict[0] = ' ';
	else
		*dict[0] = '0';
	ptr->num = ft_strdup(*dict);
	dict = ft_free(*dict);
}

void	in_to_point(unsigned long long q, t_flag *ptr)
{
	int			bag;
	char		*dict;
	int			len;

	len = ft_count_hex(q);
	dict = (char *) malloc(len + 1);
	if (!dict)
		return ;
	dict[len--] = '\0';
	if (q == 0)
	{
		fft_xX_point(ptr, &dict);
		return ;
	}
	while (q)
	{
		bag = q % 16;
		dict[len--] = ptr->dict_low[bag];
		q = q / 16;
	}
	ptr->num = ft_strdup(dict);
	dict = ft_free(dict);
}
