#include "ft_push_swap.h"

t_flag 	ft_find_mark(t_list_mass **a)
{
	int			content;
	t_flag		flag;
	t_list_mass	*ptr_a0;
	t_list_mass	*ptr_a1;

	ptr_a0 = *a;
	ptr_a1 = (*a)->next;
	ft_new_flag(&flag);
	content = (*a)->content;
	if (ptr_a0)
	{
		while (ptr_a1)
		{
			if (ptr_a0->content > ptr_a1->content)
			{
				flag.max_count++;
				flag.content = ptr_a0->content;
				ptr_a0 = ptr_a1;
			}
			ptr_a1 = ptr_a1->next;
		}
	}
	flag.content = content;
	return (flag);
}

void	ft_mark_up(t_list_mass **a, t_flag flag, int cnt_rra)
{
	t_list_mass	*ptr_a0;
	t_list_mass	*ptr_a1;

	cnt_rra = 0;
	while ((*a)->content != flag.content)
	{
		cnt_rra++;
		ft_rotate(a, "");
	}
	ptr_a0 = (*a);
	ptr_a1 = (*a)->next;
	(*a)->mark = 1;
	while (ptr_a1)
	{
		if (ptr_a0->content > ptr_a1->content)
		{
			ptr_a1->mark = 1;
			ptr_a0 = ptr_a1;
		}
		else
			ptr_a1->mark = 0;
		ptr_a1 = ptr_a1->next;
	}
	while (cnt_rra-- > 0)
		ft_rev_rotate (a, "");
}

t_flag 	ft_use_find_mark(t_list_mass **a, int len_l)
{
	t_flag	flag0;
	t_flag	flag1;

	ft_new_flag(&flag0);
	flag0.max_count = 0;
	while (len_l--)
	{
		flag1 = ft_find_mark(a);
		if (flag0.max_count < flag1.max_count)
			flag0 = flag1;
		ft_rev_rotate(a, "");
	}
	return (flag0);
}

void	ft_put_num_in_b(t_list_mass **a, t_list_mass **b)
{
	int			len_l;
	t_list_mass	*temp_a;

	len_l = ft_lstsize(*a);
	while (len_l--)
	{
		temp_a = *a;
		while (temp_a->next)
			temp_a = temp_a->next;
		if (temp_a->mark == 0)
			ft_push(a, b, "pb\n");
		else
			ft_rotate(a, "ra\n");
	}
}
