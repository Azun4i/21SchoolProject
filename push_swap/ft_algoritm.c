#include "ft_push_swap.h"

void	ft_find_quantity(t_list_mass **a, t_list_mass **b, int len_l,
						 int cnt_cmd)
{
	t_list_mass	*ptr_b;
	t_flag		flug_quan;
	t_flag		temp_min;
	t_flag		main_flag;
	int			min;

	min = 200000000;
	ft_new_flag(&flug_quan);
	ptr_b = *b;
	while (ptr_b)
	{
		flug_quan = ft_find_ra_rra_quan(a, &ptr_b, flug_quan, ft_lstsize(*a));
		flug_quan.rb = len_l - cnt_cmd;
		flug_quan.rrb = cnt_cmd;
		flug_quan.content_b = ptr_b->content;
		temp_min = ft_find_min_quan(flug_quan);
		if (ft_find_sum_min(temp_min) < min)
		{
			main_flag = temp_min;
			min = ft_find_sum_min(temp_min);
		}
		cnt_cmd++;
		ptr_b = ptr_b->next;
	}
	ft_sort(a, b, main_flag);
}

void	ft_sort(t_list_mass **a, t_list_mass **b, t_flag flag)
{
	if (flag.ra)
		while (flag.ra--)
			ft_rotate (a, "ra\n");
	if (flag.rb)
		while (flag.rb--)
			ft_rotate (b, "rb\n");
	if (flag.rr)
		while (flag.rr--)
			ft_rr (a, b, "rr\n");
	if (flag.rra)
		while (flag.rra--)
			ft_rev_rotate (a, "rra\n");
	if (flag.rrb)
		while (flag.rrb--)
			ft_rev_rotate (b, "rrb\n");
	if (flag.rrr)
		while (flag.rrr--)
			ft_rrr (a, b, "rrr\n");
	ft_push (b, a, "pa\n");
}

t_flag	ft_find_ra_rra_quan(t_list_mass **a, t_list_mass **b, t_flag flag_quan,
							  int len_l)
{
	t_list_mass	*first;
	t_list_mass	*next;
	t_list_mass	*ptr_b;

	ptr_b = *b;
	first = *a;
	next = first->next;
	flag_quan.count_command = 1;
	flag_quan.ra = -1;
	while (next)
	{
		if (first->content > ptr_b->content && ptr_b->content > next->content)
		{
			flag_quan.ra = len_l - flag_quan.count_command;
			flag_quan.rra = flag_quan.count_command;
			flag_quan.content_a = next->content;
			return (flag_quan);
		}
		flag_quan.count_command++;
		first = next;
		next = next->next;
	}
	if (flag_quan.ra == -1)
		flag_quan = ft_do_if_not_quan(a, ptr_b, flag_quan, len_l);
	return (flag_quan);
}

void	ft_do_max_first_a(t_list_mass **a, int len_l)
{
	t_list_mass	*max_cont;
	int			max_place;
	int			mod;

	max_cont = ft_find_max(*a);
	max_place = ft_find_place(a, max_cont);
	while ((*a)->content != max_cont->content)
	{
		mod = (len_l / 2) + (len_l % 2);
		if (max_place < mod)
			ft_rev_rotate(a, "rra\n");
		else
			ft_rotate(a, "ra\n");
	}
}

t_flag	ft_find_min_quan(t_flag flag_quan)
{
	int		sum_rra_rb;
	int		sum_ra_rrb;
	int		rr;
	int		rrr;
	t_flag	result;

	ft_new_flag(&result);
	sum_ra_rrb = flag_quan.ra + flag_quan.rrb;
	sum_rra_rb = flag_quan.rra + flag_quan.rb;
	rr = ft_max_rr_rrr(flag_quan.ra, flag_quan.rb);
	rrr = ft_max_rr_rrr(flag_quan.rra, flag_quan.rrb);
	if (sum_rra_rb <= sum_ra_rrb && sum_rra_rb <= rr && sum_rra_rb <= rrr)
		return (ft_add_func(flag_quan, result));
	else if (sum_ra_rrb <= sum_rra_rb && sum_ra_rrb <= rr && sum_ra_rrb <= rrr)
	{
		result.rrb = flag_quan.rrb;
		result.ra = flag_quan.ra;
		return (result);
	}
	else if (rr <= sum_ra_rrb && rr <= sum_rra_rb && rr <= rrr)
		return (ft_add_cmd_in_ctr(flag_quan, result));
	else if (rrr <= sum_ra_rrb && rrr <= sum_rra_rb && rrr <= rr)
		return (ft_add_cmd_in_ctrrr(flag_quan, result));
	return (result);
}
