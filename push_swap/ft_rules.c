#include "ft_push_swap.h"

void	ft_swap(t_list_mass **a, char *str)
{
	t_list_mass	*a_prev;
	t_list_mass	*one;
	t_list_mass	*second;
	int			count;

	if (a == NULL)
		return ;
	ft_putstr_fd(str, 1);
	count = 0;
	one = (*a);
	a_prev = (*a);
	if (one && one->next)
	{
		while (count++ < ((ft_lstsize(*a)) - 3))
			a_prev = a_prev->next;
		while (one->next)
		{
			second = one;
			one = one->next;
		}
		a_prev->next = one;
		one->next = second;
		second->next = NULL;
	}
}

void	ft_ss(t_list_mass **a, t_list_mass **b, char *str)
{
	ft_putstr_fd(str, 1);
	ft_swap(a, 0);
	ft_swap(b, 0);
}

void	ft_push(t_list_mass **p_a, t_list_mass **b, char *str)
{
	t_list_mass	*arr_a_last;
	t_list_mass	*arr_a_prev;

	if (p_a == NULL)
		return ;
	arr_a_last = *p_a;
	arr_a_prev = NULL;
	ft_putstr_fd(str, 1);
	if (arr_a_last)
	{
		while (arr_a_last->next)
		{
			arr_a_prev = arr_a_last;
			arr_a_last = arr_a_last->next;
		}
		ft_lstadd_back(b, arr_a_last);
		if (arr_a_prev != NULL)
			arr_a_prev->next = NULL;
		else
			(*p_a) = NULL;
	}
}
