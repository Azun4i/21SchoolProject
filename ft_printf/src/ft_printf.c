#include "../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		len;
	int		cnt;
	int		sum_write_smbl;
	t_flag	ptr;
	va_list	ptr_p;

	cnt = 0;
	sum_write_smbl = 0;
	len = ft_strlen(s);
	va_start(ptr_p, s);
	while (*s && cnt++ < len)
	{
		if (*s != '%' && *s != '\0')
			sum_write_smbl += ft_putchar(*s, 1);
		if (*s == '%')
		{
			ft_struct_new(&ptr);
			sum_write_smbl += ft_pars((char **) &s, ptr_p, &ptr);
			sum_write_smbl += ft_check_strct(&ptr);
			ptr.num = ft_free(ptr.num);
		}
		s++;
	}
	va_end(ptr_p);
	return (sum_write_smbl);
}

int	ft_print_w_acc_pointr(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (ptr->wight || ptr->wight > ptr->accur)
	{
		sum_write_smbl += ft_printf_wight_number(ptr);
		sum_write_smbl += write(1, "0x", 2);
		sum_write_smbl += ft_print_acc_int(ptr);
		sum_write_smbl += ft_print_smbls(ptr);
	}
	else
	{
		sum_write_smbl += write(1, "0x", 2);
		sum_write_smbl += ft_print_acc_int(ptr);
		sum_write_smbl += ft_print_smbls(ptr);
	}
	return (sum_write_smbl);
}

int	fft_if_ptr_is_s(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if (*ptr->ptr_s == 's')
	{
		if (ptr->str == NULL)
		{
			if (ptr->accur >= 0)
				sum_write_smbl += ft_putstr(ptr->str_null, ptr->accur);
			else
				sum_write_smbl += ft_putstr(ptr->str_null, ft_strlen(
							ptr->str_null));
			return (sum_write_smbl);
		}
		if (ptr->accur >= 0)
			sum_write_smbl += ft_putstr(ptr->str, ptr->accur);
		else
			sum_write_smbl += ft_putstr(ptr->str, ft_strlen(ptr->str));
	}
	return (sum_write_smbl);
}

int	fft_use_putstr_num(t_flag *ptr)
{
	int	sum_write_smbl;

	sum_write_smbl = 0;
	if ((ptr->dot == 2 && ptr->accur == 0 && ptr->wight))
	{
		ptr->num = ft_free(ptr->num);
		ptr->num = ft_strdup(" ");
	}
	if ((ptr->dot == 1 && ptr->accur == 0 && ptr->wight == 0
			&& *ptr->num == '0'))
	{
		ptr->num = ft_free(ptr->num);
		ptr->num = ft_strdup("");
	}
	if (ptr->accur && ptr->accur >= (ft_strlen(ptr->num)))
		sum_write_smbl += ft_putstr(ptr->num, ptr->accur);
	else
		sum_write_smbl += ft_putstr(ptr->num, ft_strlen(ptr->num));
	return (sum_write_smbl);
}

int	ft_print_acc_int(t_flag *ptr)
{
	int	len;
	int	q;
	int	sum_write_smbl;

	sum_write_smbl = 0;
	len = ft_strlen(ptr->num);
	q = ptr->accur;
	if (ptr->accur > len)
	{
		while (q-- > len)
			sum_write_smbl += ft_putchar('0', 1);
	}
	return (sum_write_smbl);
}
