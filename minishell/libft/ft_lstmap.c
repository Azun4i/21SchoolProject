/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:29:10 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:29:13 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (temp == NULL)
		return (NULL);
	if (lst->next != 0)
	{
		lst = lst->next;
		while (lst != 0)
		{
			new = ft_lstnew(f(lst->content));
			if (new == NULL)
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			ft_lstadd_back(&temp, new);
			lst = lst->next;
		}
	}
	return (temp);
}
