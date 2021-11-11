#include "../includes/ft_printf.h"

int	ft_check_strct(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (!ptr->accur && ptr->zero && ptr->wight)
		ptr->zero = 0;
	if (ptr->ptr_s == NULL)
		return (0);
	if (*ptr->ptr_s == 'c' || *ptr->ptr_s == 's' || *ptr->ptr_s == '%')
		sum_write_smbl += fft_check_strct_if_cs(ptr);
	else
	{
		if (!ptr->minus)
			sum_write_smbl += fft_ckeck_if_dixXp(ptr);
		else
		{
			if (ptr->neg_num == 1)
				sum_write_smbl += write(1, "-", 1);
			if (*ptr->ptr_s == 'p')
				sum_write_smbl += write(1, "0x", 2);
			sum_write_smbl += ft_print_acc_int(ptr);
			sum_write_smbl += ft_print_smbls(ptr);
			sum_write_smbl += ft_printf_wight_number(ptr);
		}
	}
	return (sum_write_smbl);
}

int	fft_check_strct_if_cs(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (!ptr->minus)
	{
		sum_write_smbl += ft_printf_wight_str(ptr);
		sum_write_smbl += ft_print_smbls(ptr);
	}
	else
	{
		sum_write_smbl += ft_print_smbls(ptr);
		sum_write_smbl += ft_printf_wight_str(ptr);
	}
	return (sum_write_smbl);
}

int	fft_ckeck_if_dixXp(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (*ptr->ptr_s == 'p')
		return (ft_print_w_acc_pointr(ptr));
	if ((ptr->neg_num == 1 && ptr->wight && !ptr->zero))
		sum_write_smbl += fft_check_wat_num_is(ptr);
	else
	{
		if ((ptr->neg_num == 1 && !ptr->wight)
			|| (ptr->neg_num == 1 && ptr->wight > ptr->accur)
			|| (ptr->neg_num == 1 && ptr->zero))
		{
			sum_write_smbl += write(1, "-", 1);
			ptr->wrt_minus = 0;
		}
		sum_write_smbl += ft_printf_wight_number(ptr);
		sum_write_smbl += ft_print_acc_int(ptr);
		if (ptr->neg_num == 1 && ptr->wrt_minus < 0 && ptr->accur > 0)
			sum_write_smbl += write(1, "-", 1);
		sum_write_smbl += ft_print_smbls(ptr);
	}
	return (sum_write_smbl);
}

int	fft_check_wat_num_is(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	sum_write_smbl += ft_printf_wight_number(ptr);
	if ((ptr->neg_num == 1 && ptr->wight))
	{
		sum_write_smbl += write(1, "-", 1);
		ptr->wrt_minus = 0;
	}
	sum_write_smbl += ft_print_acc_int(ptr);
	if (ptr->neg_num == 1 && ptr->wrt_minus < 0 && ptr->accur > 0)
		sum_write_smbl += write(1, "-", 1);
	sum_write_smbl += ft_print_smbls(ptr);
	return (sum_write_smbl);
}

void	ft_struct_new(t_flag *ptr)
{
	ptr->flag = 0;
	ptr->sum_write_smbl = 0;
	ptr->minus = 0;
	ptr->smbl = 0;
	ptr->dot = 0;
	ptr->zero = 0;
	ptr->space = 0;
	ptr->wight = 0;
	ptr->accur = -1;
	ptr->num = NULL;
	ptr->str = NULL;
	ptr->konec = 0;
	ptr->str_null = "(null)";
	ptr->neg_num = -1;
	ptr->wrt_minus = -1;
	ptr->ptr_s = NULL;
	ptr->w_s = 0;
	ptr->w_n = 0;
	ptr->zero_f_d = 0;
	ptr->pointer = 0;
	ptr->dict_low = "0123456789abcdef";
	ptr->dict_app = "0123456789ABCDEF";
}
