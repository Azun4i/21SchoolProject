#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_lst;

	if (*lst || *del)
	{
		while (*lst)
		{
			ptr_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ptr_lst;
		}
	}
	return ;
}
