#include "../includes/ft_printf.h"

void	second_chek(va_list ptr_s, t_flag *ptr, char **str)
{
	if (**str == '-')
	{
		ptr->minus = 1;
		while (**str == '-' || **str == '0')
			(*str)++;
	}
	if (**str == '0')
		while (**str == '0' )
			(*str)++;
	if (**str == '*')
		fft_if_star(ptr_s, ptr, str);
	if ((ft_isdigit(**str)) > 0)
		fft_add_accur_wight(ptr_s, ptr, str);
	if (**str == '.')
		fft_add_accur_wight(ptr_s, ptr, str);
	if (**str == '%')
	{
		ptr->konec = 1;
		ptr->smbl = '%';
	}
	if (ptr->accur > 0)
		ptr->zero = 0;
	ft_wat_type_is(str, ptr_s, ptr);
}

void	fft_if_star(va_list ptr_s, t_flag *ptr, char **str)
{
	ptr->wight = va_arg(ptr_s, int);
	if (ptr->wight < 0)
	{
		ptr->wight *= -1;
		ptr->minus = 1;
		ptr->zero = 0;
	}
	(*str)++;
}

int	ft_wat_type_is(char **str, va_list ptr_s, t_flag *ptr)
{
	unsigned long long	q;

	q = 0;
	ptr->ptr_s = *str;
	if (**str == '%')
		ptr->smbl = '%';
	if (**str == 'c')
	{
		ptr->konec = 1;
		ptr->smbl = va_arg(ptr_s, int);
	}
	if (**str == 's')
		ptr->str = va_arg(ptr_s, char *);
	if (**str == 'd' || **str == 'i' || **str == 'u' || **str == 'x' || **str
		== 'X')
		fft_wat_tupe2(str, ptr_s, ptr);
	else if (**str == 'p')
	{
		q = va_arg(ptr_s, unsigned long long);
		in_to_point(q, ptr);
	}
	return (0);
}

void	fft_wat_tupe2(char **str, va_list ptr_s, t_flag *ptr)
{
	long				i;
	unsigned int		y;

	if (**str == 'd' || **str == 'i')
	{
		i = va_arg(ptr_s, int);
		if (i < 0)
		{
			ptr->neg_num = 1;
			i *= -1;
		}
		ptr->num = ft_itoa(i);
		fft_if_dot(ptr);
	}
	else if (**str == 'u')
	{
		y = va_arg(ptr_s, unsigned int );
		ptr->num = ft_itoa(y);
		fft_if_dot(ptr);
	}
	else if (**str == 'x' || **str == 'X')
	{
		y = va_arg(ptr_s, unsigned int );
		in_to(y, ptr);
	}
}

void	fft_if_dot(t_flag *ptr)
{
	if (*ptr->num == '0' && ptr->dot == 1 && ptr->wight > 0)
		ptr->dot = 2;
	else
		ptr->dot = 1;
}
