#include "ft_push_swap.h"

t_list_mass 	*ft_find_max(t_list_mass *a)
{
	t_list_mass	*ptr_a;
	t_list_mass	*p_max;

	ptr_a = a;
	p_max = ptr_a;
	while (ptr_a->next)
	{
		if (p_max->content < ptr_a->next->content)
			p_max = ptr_a->next;
		else
			ptr_a = ptr_a->next;
	}
	return (p_max);
}

t_list_mass 	*ft_find_min(t_list_mass *a)
{
	t_list_mass	*ptr_a;
	t_list_mass	*p_min;

	p_min = a;
	ptr_a = a;
	while (ptr_a->next)
	{
		if (p_min->content > ptr_a->next->content)
			p_min = ptr_a->next;
		else
			ptr_a = ptr_a->next;
	}
	return (p_min);
}

int	ft_find_place(t_list_mass **a, t_list_mass *min)
{
	int			place;
	t_list_mass	*ptr_a;

	ptr_a = *a;
	place = 0;
	while (ptr_a->content != min->content)
	{
		place++;
		ptr_a = ptr_a->next;
	}
	return (place);
}

void	ft_new_flag(t_flag *flag)
{
	flag->max_count = 1;
	flag->content = -1;
	flag->count_command = 0;
	flag->rrb = 0;
	flag->rra = 0;
	flag->rrr = 0;
	flag->rr = 0;
	flag->ra = 0;
	flag->rb = 0;
}

int	ft_find_sum_min(t_flag temp_min)
{
	int	min;

	min = 0;
	if (temp_min.ra >= 0)
		min += temp_min.ra;
	if (temp_min.rb >= 0)
		min += temp_min.rb;
	if (temp_min.rra >= 0)
		min += temp_min.rra;
	if (temp_min.rrb >= 0)
		min += temp_min.rrb;
	if (temp_min.rrr >= 0)
		min += temp_min.rrr;
	if (temp_min.rr >= 0)
		min += temp_min.rr;
	return (min);
}
