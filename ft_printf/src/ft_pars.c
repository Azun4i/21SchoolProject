#include "../includes/ft_printf.h"

int	ft_pars(char **str, va_list ptr_s, t_flag *ptr)
{
	(*str)++;
	if (**str == '\0')
		return (0);
	else if (**str == ' ' || **str == '0' || (ft_isdigit(**str)) > 0)
		first_chek(ptr_s, ptr, str);
	else if (**str == '-' || **str == '.' || **str == '*')
		second_chek(ptr_s, ptr, str);
	else if (**str != ' ' || **str != '-' || **str == '%')
		ft_wat_type_is(str, ptr_s, ptr);
	return (0);
}

void	first_chek(va_list ptr_s, t_flag *ptr, char **str)
{
	if (**str == ' ')
		fft_if_spas(ptr, str);
	else if (**str == '0')
		fft_if_zero(ptr, str);
	if (**str == '-' || **str == '*')
	{
		second_chek(ptr_s, ptr, str);
		return ;
	}
	if (ft_isdigit(**str))
		fft_add_accur_wight(ptr_s, ptr, str);
	if (**str == '.')
		fft_add_accur_wight(ptr_s, ptr, str);
	if (**str == '%')
		ptr->ptr_s = *str;
	if (ptr->accur > 0)
		ptr->zero = 0;
	ft_wat_type_is(str, ptr_s, ptr);
}

void	fft_add_accur_wight(va_list ptr_s, t_flag *ptr, char **str)
{
	int		q;
	char	*tmp;

	q = 0;
	tmp = (char *) malloc(sizeof (char ) * ((ft_strlen(*str)) + 1));
	if (!tmp)
		return ;
	if (ft_isdigit(**str))
	{
		while ((ft_isdigit(**str)) > 0)
		{
			tmp[q++] = *(*str)++;
			tmp[q] = '\0';
		}
		ptr->wight = ft_atoi(tmp);
	}
	if (**str == '.')
		fft_add_accur(ptr_s, ptr, str);
	tmp = ft_free(tmp);
}

void	fft_add_accur(va_list ptr_s, t_flag *ptr, char **str)
{
	int		q;
	char	*tmp_1;

	tmp_1 = (char *) malloc(sizeof (char ) * ((ft_strlen(*str)) + 1));
	q = 0;
	if (!tmp_1)
		return ;
	if (**str == '.')
	{
		ptr->dot = 1;
		(*str)++;
		if (**str == '*')
		{
			ptr->accur = va_arg(ptr_s, int);
			(*str)++;
		}
		else
		{
			while ((ft_isdigit(**str)) > 0)
				tmp_1[q++] = *(*str)++;
			ptr->accur = ft_atoi(tmp_1);
		}
	}
	tmp_1 = ft_free(tmp_1);
}
