/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:52:31 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:52:32 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

char	*free_list_line(char *read_line, t_node **n)
{
	if (read_line)
		free(read_line);
	ft_lstclear_shell(n, del);
	return (NULL);
}

void	ft_lstclear_shell(t_node **lst, void (*del)(char *cmd, char **flags,
													char **args))
{
	t_node	*temp;
	t_node	*temp2;

	if (*lst == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		del(temp->cmd, temp->flags, temp->args);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}

void	del(char *cmd, char **flags, char **args)
{
	int	i;

	if (cmd)
		free(cmd);
	i = -1;
	if (flags)
	{
		while (flags[++i])
			free(flags[i]);
		free(flags);
	}
	i = -1;
	if (args)
	{
		while (args[++i])
			free(args[i]);
		free(args);
	}
}

void	free_env(t_env **lst)
{
	t_env	*temp;
	t_env	*temp2;

	if (*lst == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}
