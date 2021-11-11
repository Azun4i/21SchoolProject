#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	int		flag;
	int		sum_write_smbl;
	char	smbl;
	int		minus;
	int		neg_num;
	int		wrt_minus;
	int		wight;
	int		accur;
	int		dot;
	int		zero;
	int		space;
	char	*num;
	char	*str;
	char	*dict_low;
	char	*dict_app;
	char	*ptr_s;
	int		w_n;
	int		w_s;
	int		zero_f_d;
	int		konec;
	char	*str_null;
	int		pointer;
}	t_flag;

int		ft_printf(const char *s, ...);
int		ft_pars(char **str, va_list ptr_s, t_flag *ptr);
int		ft_wat_type_is(char **str, va_list ptr_s, t_flag *ptr);
void	first_chek(va_list ptr_s, t_flag *ptr, char **str);
void	second_chek(va_list ptr_s, t_flag *ptr, char **str);
int		ft_check_strct(t_flag *ptr);
int		ft_print_smbls(t_flag *ptr);
int		ft_printf_wight_str(t_flag *ptr);
int		ft_printf_wight_number(t_flag *ptr);
int		ft_print_w_acc_pointr(t_flag *ptr);
int		fft_use_putchr(t_flag *ptr);
void	fft_if_null(t_flag *ptr);
int		fft_chek_w_n(t_flag *ptr);
int		ft_putchar(char c, int fd);
void	*ft_free(char *str);
int		ft_putstr(char *s, int len);
int		ft_countintlen(long n);
int		fft_if_ptr_is_s(t_flag *ptr);
int		fft_use_putstr_num(t_flag *ptr);
void	in_to(unsigned long long q, t_flag *ptr);
void	in_to_point(unsigned long long q, t_flag *ptr);
int		ft_int_hex_len(unsigned int q);
int		ft_count_hex (unsigned long long i);
void	zero_chek(va_list ptr_s, t_flag *ptr, char **str);
void	fft_if_dot(t_flag *ptr);
void	fft_if_spas(t_flag *ptr, char **str);
void	fft_if_zero(t_flag *ptr, char **str);
void	fft_add_accur_wight(va_list ptr_s, t_flag *ptr, char **str);
void	fft_add_accur(va_list ptr_s, t_flag *ptr, char **str);
void	fft_if_star(va_list ptr_s, t_flag *ptr, char **str);
void	fft_wat_tupe2(char **str, va_list ptr_s, t_flag *ptr);
void	fft_xX_zero(t_flag *ptr, char **dict);
void	fft_xX_point(t_flag *ptr, char **dict);
void	ft_struct_new(t_flag *ptr);
int		ft_print_smbls(t_flag *ptr);
int		ft_check_strct(t_flag *ptr);
int		fft_check_strct_if_cs(t_flag *ptr);
int		fft_ckeck_if_dixXp(t_flag *ptr);
int		fft_check_wat_num_is(t_flag *ptr);
int		ft_print_acc_int(t_flag *ptr);
#endif