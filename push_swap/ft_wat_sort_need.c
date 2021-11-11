#include "ft_push_swap.h"

void	ft_wat_sort_need(t_list_mass **a)
{
	int			cnt_rra;
	int			len_l;
	t_flag		flag;
	t_list_mass	*ptr_a;
	t_list_mass	*b;

	cnt_rra = 0;
	b = NULL;
	ptr_a = *a;
	len_l = ft_lstsize(ptr_a);
	if (len_l > 5)
	{
		flag = ft_use_find_mark(a, len_l);
		ft_mark_up(a, flag, cnt_rra);
		ft_put_num_in_b(a, &b);
		ft_count_func(a, &b);
	}
	else
		ft_sort_small_list(a, &b, len_l);
	ft_do_max_first_a(a, ft_lstsize(*a));
}

void	ft_count_func(t_list_mass **a, t_list_mass **b)
{
	t_list_mass	*ptr_b;
	int			len_l;
	int			cnt_cmd;

	cnt_cmd = 1;
	ptr_b = *b;
	while (ptr_b)
	{
		len_l = ft_lstsize(ptr_b);
		ft_find_quantity(a, &ptr_b, len_l, cnt_cmd);
	}
}

void	ft_free_char(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j])
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_free_stract(t_list_mass	*a)
{
	t_list_mass	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	free(a);
}
