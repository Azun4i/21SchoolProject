/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:34:00 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:34:01 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_redir_lef(t_node *n, t_id *id)
{
	t_node	*t_n;

	(void)id;
	t_n = n;
	while (t_n && (ft_strcmp(t_n->cmd, "|") != 0))
	{
		if (ft_strcmp(t_n->cmd, "<") == 0 || ft_strcmp(t_n->cmd, "<<") == 0)
		{
			if (!t_n->args)
			{
				dup2(id->save_o, 1);
				return (ft_syntax_error(NULL));
			}
		}
		t_n = t_n->next;
	}
	return (0);
}

int	ft_syntax_error(char *file_name)
{
	if (file_name)
		free(file_name);
	errno = 0;
	errors("syntax error near unexpected token");
	g_code = 258;
	return (-1);
}

int	ft_if_redir(t_node *n, t_env **env, char *read_line, t_id *id)
{
	(void)env;
	(void)read_line;
	(void)id;
	id->r_fd_out = 1;
	id->r_fd_in = 0;
	if (ft_redir_lef(n, id) == -1)
		return (-1);
	id->r_fd_out = ft_get_fd_out(n, id);
	id->r_fd_in = ft_get_fd_in(n, id);
	if (id->r_fd_out == -1 || id->r_fd_in == -1)
		return (0);
	if (is_biltin(n->cmd) == 1)
		ft_run_biltin(n, env, read_line, id);
	else
	{
		g_code = ft_other_func_exec(n, env, id);
	}
	return (0);
}

int	ft_get_fd_file(char *cmd, char *args, t_id *id)
{
	int	fd;

	(void )id;
	fd = -1;
	if (!args)
	{
		errors("syntax error near unexpected token");
		g_code = 258;
		return (fd);
	}
	if (ft_strcmp(cmd, ">") == 0 || ft_strcmp(cmd, "<") == 0)
	{
		if (ft_strcmp(cmd, "<") == 0)
			fd = open(args, O_RDONLY, 0644);
		else
			fd = open(args, O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
	else if (ft_strcmp(cmd, ">>") == 0)
		fd = open(args, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		g_code = 1;
	}
	return (fd);
}
