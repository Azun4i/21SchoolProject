#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_new;
	t_list	*ptr_lst;

	ptr_lst = NULL;
	while (lst)
	{
		ptr_new = ft_lstnew((*f)(lst->content));
		if (!ptr_new)
		{
			ft_lstclear(&ptr_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&ptr_lst, ptr_new);
		lst = lst->next;
	}
	return (ptr_lst);
}
