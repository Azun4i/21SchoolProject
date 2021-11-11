/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_redir_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:22:13 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:22:15 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

t_node	*ft_while_left(t_node *n, t_env **env, char *read_line, t_id *id)
{
	(void)env;
	(void)read_line;
	(void)id;
	while (n && ft_strcmp(n->cmd, "<") == 0)
	{
		if (n->next->cmd && ft_strcmp(n->next->cmd, "<") != 0)
			return (n);
		n = n->next;
	}
	return (NULL);
}

t_node	*ft_while_right(t_node *n, t_env **env, char *read_line, t_id *id)
{
	(void)env;
	(void)read_line;
	(void)id;
	while (n && ft_strcmp(n->cmd, ">") == 0)
	{
		if (n->next->cmd && ft_strcmp(n->next->cmd, ">") != 0)
			return (n);
		n = n->next;
	}
	return (NULL);
}

int	ft_is_redir(char *cmd)
{
	if (ft_strcmp(cmd, "<") == 0 && ft_strcmp(cmd, ">") == 0
		&& ft_strcmp(cmd, "<<") == 0 && ft_strcmp(cmd, ">>") == 0)
		return (0);
	return (1);
}

int	ft_is_pipe(char *cmd)
{
	if (ft_strcmp(cmd, "|") == 0)
		return (1);
	return (0);
}

void	ft_do_dup(t_node *n, t_id *id)
{
	(void)n;
	if (dup2(id->r_fd_in, 0) == -1)
		errors("dup2 error");
	if (dup2(id->r_fd_out, 1) == -1)
		errors("dup2 error");
}
