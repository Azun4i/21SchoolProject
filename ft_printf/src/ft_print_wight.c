#include "../includes/ft_printf.h"

int	ft_printf_wight_str(t_flag *ptr)
{
	int	i;
	int	len;
	int	sum_write_smbl;

	i = -1;
	sum_write_smbl = 0;
	if (ptr->str == NULL)
		fft_if_null(ptr);
	else
	{
		if (ptr->accur >= 0 && ptr->accur < (ft_strlen(ptr->str)))
			ptr->w_s = ptr->wight - ptr->accur;
		else
			ptr->w_s = ptr->wight - (ft_strlen(ptr->str));
		if (ptr->smbl || ptr->konec == 1)
			ptr->w_s = ptr->wight - 1;
	}
	len = ptr->w_s;
	while (++i < len)
		sum_write_smbl += fft_use_putchr(ptr);
	return (sum_write_smbl);
}

int	ft_printf_wight_number(t_flag *ptr)
{
	int	i;
	int	len;
	int	sum_write_smbl;

	i = -1;
	len = 0;
	sum_write_smbl = 0;
	if (ptr->accur >= 0 && ptr->neg_num == 1 && ptr->accur < (ft_strlen
			(ptr->num)))
		ptr->w_n = ptr->wight - (ft_strlen(ptr->num) + 1);
	else if (ptr->accur >= 0 && ptr->accur < (ft_strlen(ptr->num)))
		ptr->w_n = ptr->wight - (ft_strlen(ptr->num));
	else if (ptr->accur >= 0 && ptr->neg_num == 1 && ptr->accur > (ft_strlen
			(ptr->num)))
		ptr->w_n = ptr->wight - ptr->accur - 1;
	else if (ptr->accur >= 0 && ptr->accur > (ft_strlen(ptr->num)))
		ptr->w_n = ptr->wight - ptr->accur;
	else if ((ptr->neg_num > 0 && ptr->wight > 0))
		ptr->w_n = ptr->wight - (ft_strlen(ptr->num) + 1);
	else
		ptr->w_n = ptr->wight - (ft_strlen(ptr->num));
	len = fft_chek_w_n(ptr);
	while (++i < len)
		sum_write_smbl += fft_use_putchr(ptr);
	return (sum_write_smbl);
}

int	fft_use_putchr(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (ptr->zero == 1)
		sum_write_smbl += ft_putchar('0', 1);
	else
		sum_write_smbl += ft_putchar(' ', 1);
	return (sum_write_smbl);
}

void	fft_if_null(t_flag *ptr)
{
	if (ptr->accur >= 0 && ptr->accur < (ft_strlen(ptr->str_null)))
		ptr->w_s = ptr->wight - ptr->accur;
	else
		ptr->w_s = ptr->wight - (ft_strlen(ptr->str_null));
	if (ptr->smbl || ptr->konec == 1)
		ptr->w_s = ptr->wight - 1;
}

int	fft_chek_w_n(t_flag *ptr)
{
	int	len;

	len = 0;
	if (*ptr->ptr_s == 'p')
		len = ptr->w_n - 2;
	else
		len = ptr->w_n;
	return (len);
}
