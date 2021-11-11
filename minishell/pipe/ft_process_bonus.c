/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:24:04 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:24:06 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	bft_proc_child(t_node *n, t_id *id, char*read_line, t_env **env_1)
{
	if (id->iter == 1 || id->quan_argc == id->iter)
		ft_first_lst_var(n, id, read_line, env_1);
	else
	{
		if (id->iter % 2 == 0)
		{
			if ((dup2(id->fd_a[0], 0)) == -1 || (dup2(id->fd_b[1], 1)) == -1)
				errors("Bad file discriptor");
		}
		else
			if ((dup2(id->fd_b[0], 0)) == -1 || (dup2(id->fd_a[1], 1)) == -1)
				errors("Bad file discriptor");
	}
	if (ft_if_redir(n, env_1, read_line, id) == -1)
	{
		g_code = 258;
		exit(258);
	}
	exit(g_code);
}

void	bft_proc_main(t_id *id)
{
	if (id->iter == 1 || id->quan_argc == id->iter)
		ft_first_lst_var_close(id);
	else if (id->iter % 2 == 0)
	{
		close(id->fd_a[0]);
		close(id->fd_b[1]);
		if (pipe(id->fd_a) < 0)
			errors("Bad file discriptor");
	}
	else if (id->iter % 2 == 1)
	{
		close(id->fd_a[1]);
		close(id->fd_b[0]);
		if (pipe(id->fd_b) < 0)
			errors("Bad file discriptor");
	}
	id->iter++;
}

void	ft_first_lst_var(t_node *n, t_id *id, char*read_line, t_env **env_1)
{
	if (id->iter == 1)
	{
		if (dup2(id->fd_a[1], 1) == -1)
			errors("Bad file discriptor");
	}
	else
	{
		if (id->iter % 2 == 0)
			dup2(id->fd_a[0], 0);
		else if (id->iter % 2 == 1)
			dup2(id->fd_b[0], 0);
	}
	if (ft_if_redir(n, env_1, read_line, id) == -1)
	{
		g_code = 258;
		exit(258);
	}
	exit(g_code);
}

void	ft_first_lst_var_close(t_id *id)
{
	if (id->iter == 1)
	{
		close(id->fd_a[1]);
	}
	else
	{
		if (id->iter % 2 == 0)
			close(id->fd_a[0]);
		else if (id->iter % 2 == 1)
			close(id->fd_b[0]);
	}
}
