/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:27:04 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:27:11 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (lst == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		del(temp->content);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}
