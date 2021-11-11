#include "../includes/ft_printf.h"

int	ft_print_smbls(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (*ptr->ptr_s == 'c' || *ptr->ptr_s == '%')
		sum_write_smbl += ft_putchar(ptr->smbl, 1);
	if (*ptr->ptr_s == 'd' || *ptr->ptr_s == 'i' || *ptr->ptr_s == 'u'
		|| *ptr->ptr_s == 'x' || *ptr->ptr_s == 'X' || *ptr->ptr_s == 'p')
	{
		ptr->zero_f_d = 1;
		if (ptr->pointer && ptr->accur == 0 && !ptr->wight)
			return (sum_write_smbl);
		sum_write_smbl += fft_use_putstr_num(ptr);
	}
	if (*ptr->ptr_s == 's')
		sum_write_smbl += fft_if_ptr_is_s(ptr);
	return (sum_write_smbl);
}
