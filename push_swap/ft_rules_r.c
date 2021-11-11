#include "ft_push_swap.h"

void	ft_rotate(t_list_mass **a, char *str)
{
	t_list_mass	*a_last;
	t_list_mass	*a_prev;

	ft_putstr_fd(str, 1);
	a_last = *a;
	if (*a == NULL)
		return ;
	if (a_last)
	{
		if (a_last->next)
		{
			while (a_last->next)
			{
				a_prev = a_last;
				a_last = a_last->next;
			}
			a_last->next = *a;
			a_prev->next = NULL;
			*a = a_last;
		}
	}
}

void	ft_rr(t_list_mass **a, t_list_mass **b, char *str)
{
	ft_putstr_fd(str, 1);
	ft_rotate(a, 0);
	ft_rotate(b, 0);
}

void	ft_rev_rotate(t_list_mass **a, char *str)
{
	t_list_mass	*ptr_a;
	t_list_mass	*a_last;

	if (*a == NULL)
		return ;
	ptr_a = *a;
	(*a) = (*a)->next;
	ft_putstr_fd(str, 1);
	if (ptr_a)
	{
		if (ptr_a->next)
		{
			a_last = ft_lstlast(*a);
			ptr_a->next = NULL;
			a_last->next = ptr_a;
		}
	}
}

void	ft_rrr(t_list_mass **a, t_list_mass **b, char *str)
{
	ft_putstr_fd(str, 1);
	ft_rev_rotate(a, 0);
	ft_rev_rotate(b, 0);
}
