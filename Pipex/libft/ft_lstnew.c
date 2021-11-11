#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*ptr;

	ptr = malloc(sizeof (t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
