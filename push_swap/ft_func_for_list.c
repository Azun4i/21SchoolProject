#include "ft_push_swap.h"

t_list_mass	*ft_lstnew(int content)
{
	t_list_mass	*ptr;

	ptr = malloc(sizeof (t_list_mass));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list_mass **lst, t_list_mass *new)
{
	t_list_mass	*last_stct;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_stct = ft_lstlast(*lst);
			last_stct->next = new;
		}
	}
}

int	ft_lstadd_front(t_list_mass **lst, t_list_mass *new)
{
	t_list_mass	*cur;

	cur = *lst;
	if (cur)
	{
		while (cur->next)
		{
			if (cur->content == new->content)
				ft_post_error(3);
			cur = cur->next;
		}
		if (cur->content == new->content)
			ft_post_error(3);
	}
	new->next = *lst;
	*lst = new;
	return (0);
}

t_list_mass	*ft_lstlast(t_list_mass *lst)
{
	t_list_mass	*lst_n;

	lst_n = lst;
	if (lst == NULL)
		return (NULL);
	while (lst_n->next)
		lst_n = lst_n->next;
	return (lst_n);
}

int	ft_lstsize(t_list_mass *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
