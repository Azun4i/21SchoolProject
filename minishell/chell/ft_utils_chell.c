/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_chell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:34:04 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:37:11 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_count_mass(char **mass)
{
	int	k;

	k = 0;
	while (mass[k] != NULL)
		k++;
	return (k);
}

int	ft_count_pipe(t_node *n)
{
	t_node	*tmp;
	int		cnt;

	cnt = 0;
	tmp = n;
	if (n != NULL)
	{
		while (tmp)
		{
			if ((ft_strcmp(tmp->cmd, "|") == 0))
				cnt++;
			tmp = tmp->next;
		}
	}
	return (cnt);
}

int	ft_lstsize_b(t_node *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_find_pipe(t_node *n)
{
	t_node	*tmp;

	if (ft_lstsize_b(n) > 0)
	{
		tmp = n;
		while (tmp)
		{
			if (ft_strcmp(tmp->cmd, "|") == 0)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}
