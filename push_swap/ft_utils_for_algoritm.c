#include "ft_push_swap.h"

t_flag	ft_add_func(t_flag flag_quan, t_flag result)
{
	result.rra = flag_quan.rra;
	result.rb = flag_quan.rb;
	return (result);
}

t_flag	ft_add_cmd_in_ctr(t_flag flag_quan, t_flag result)
{
	if (flag_quan.ra > flag_quan.rb)
	{
		result.rr = flag_quan.rb;
		result.ra = flag_quan.ra - flag_quan.rb;
	}
	else
	{
		result.rr = flag_quan.ra;
		result.rb = flag_quan.rb - flag_quan.ra;
	}
	return (result);
}

t_flag	ft_add_cmd_in_ctrrr(t_flag flag_quan, t_flag result)
{
	if (flag_quan.rra > flag_quan.rrb)
	{
		result.rrr = flag_quan.rrb;
		result.rra = flag_quan.rra - flag_quan.rrb;
	}
	else
	{
		result.rrr = flag_quan.rra;
		result.rrb = flag_quan.rrb - flag_quan.rra;
	}
	return (result);
}

int	ft_max_rr_rrr(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_flag 	ft_do_if_not_quan(t_list_mass **a, t_list_mass *ptr_b, t_flag
flag_quan, int len_l)
{
	int			index;
	t_list_mass	*arr;
	t_list_mass	*ar;

	flag_quan.ra = 0;
	if ((*a)->content < ptr_b->content && ft_lstlast(*a)->content
		> ptr_b->content)
	{
		flag_quan.ra = 0;
		flag_quan.rra = 0;
	}
	else
	{
		index = 1;
		arr = ft_find_min(*a);
		ar = *a;
		while (arr->content != ar->content)
		{
			index++;
			ar = ar->next;
		}
		flag_quan.ra = len_l - index;
		flag_quan.rra = index;
	}
	return (flag_quan);
}
