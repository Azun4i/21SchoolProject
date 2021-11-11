#include "ft_push_swap.h"

void	ft_sort_small_list(t_list_mass **a, t_list_mass **b, int len)
{
	t_list_mass	*p_min;
	t_list_mass	*p_max;

	p_min = ft_find_min(*a);
	p_max = ft_find_max(*a);
	if (len == 3)
		ft_sort_three(a, p_min, p_max);
	else if (len == 4)
		ft_sort_four(a, b, p_min);
	else if (len == 5)
		ft_sort_five(a, b, p_min);
}

void	ft_sort_three(t_list_mass **a, t_list_mass *p_min, t_list_mass *p_max)
{
	t_list_mass	*p_last;

	p_last = ft_lstlast(*a);
	if ((*a)->next->content == p_min->content
		&& (*a)->content == p_max->content)
		ft_swap(a, "sa\n");
	else if ((*a)->next->content == p_min->content && p_last->content
		== p_max->content)
		ft_rotate(a, "ra\n");
	else if ((*a)->next->content == p_max->content && p_last->content
		== p_min->content)
	{
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
	}
	else if ((*a)->content == p_min->content && p_last->content
		== p_max->content)
	{
		ft_swap(a, "sa\n");
		ft_rev_rotate(a, "rra\n");
	}
	else if ((*a)->next->content == p_max->content && (*a)->content
		== p_min->content)
		ft_rev_rotate(a, "rra\n");
}

void	ft_sort_four(t_list_mass **a, t_list_mass **b, t_list_mass *p_min)
{
	if ((*a)->next->content == p_min->content)
	{
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_push(a, b, "pb\n");
		ft_sort_three(a, ft_find_min(*a), ft_find_max(*a));
	}
	 else if ((*a)->content == p_min->content)
	{
		ft_rev_rotate(a, "rra\n");
		ft_push(a, b, "pb\n");
		ft_sort_three(a, ft_find_min(*a), ft_find_max(*a));
	}
	 else if ((ft_lstlast(*a)->content) == p_min->content)
	{
		ft_push(a, b, "pb\n");
		ft_sort_three(a, ft_find_min(*a), ft_find_max(*a));
	}
	 else if ((*a)->next->next->content == p_min->content)
	{
		ft_swap(a, "sa\n");
		ft_push(a, b, "pb\n");
		ft_sort_three(a, ft_find_min(*a), ft_find_max(*a));
	}
	ft_push(b, a, "pa\n");
}

void	ft_sort_five(t_list_mass **a, t_list_mass **b, t_list_mass *p_min)
{
	if ((*a)->content == p_min->content)
		ft_rev_rotate(a, "rra\n");
	else if ((ft_lstlast(*a)->content) == p_min->content)
		;
	else if ((*a)->next->next->content == p_min->content)
	{
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
	}
	else if ((*a)->next->content == p_min->content)
	{
		ft_rev_rotate(a, "rra\n");
		ft_rev_rotate(a, "rra\n");
	}
	else if ((*a)->next->next->next->content == p_min->content)
		ft_rotate(a, "ra\n");
	ft_push(a, b, "pb\n");
	ft_sort_four(a, b, ft_find_min(*a));
	ft_push(b, a, "pa\n");
}
