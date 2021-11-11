/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_redir_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:22:22 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:22:24 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_get_flag_in_get_fd_out(char *args, char *cmd, t_id *id, int flag)
{
	if (ft_strcmp(cmd, ">>") == 0)
	{
		ft_get_fd_file(">>", args, id);
		flag = 1;
	}
	else
	{
		ft_get_fd_file(">", args, id);
		flag = 0;
	}
	return (flag);
}

int	ft_get_fd_out(t_node *n, t_id *id)
{
	t_node	*t_n;
	char	*file_name;
	int		flag;

	t_n = n;
	file_name = NULL;
	while (t_n && ft_strcmp(t_n->cmd, "|") != 0)
	{
		if (ft_strcmp(t_n->cmd, ">") == 0 || ft_strcmp(t_n->cmd, ">>") == 0)
		{
			if (!t_n->args)
				return (ft_syntax_error(file_name));
			flag = ft_get_flag_in_get_fd_out(t_n->args[0], t_n->cmd, id, flag);
			if (file_name)
				file_name = ft_free(file_name);
			file_name = ft_strdup(t_n->args[0]);
		}
		t_n = t_n->next;
	}
	return (ft_wat_redir_out(file_name, flag, id));
}

int	ft_wat_redir_out(char *file_name, int flag, t_id *id)
{
	int	fd;

	if (file_name && flag == 0)
	{
		fd = ft_get_fd_file(">", file_name, id);
		file_name = ft_free(file_name);
		return (fd);
	}
	else if (file_name && flag == 1)
	{
		fd = ft_get_fd_file(">>", file_name, id);
		file_name = ft_free(file_name);
		return (fd);
	}
	return (1);
}

int	ft_get_fd_in(t_node *n, t_id *id)
{
	char	*file_name;
	int		fd;

	file_name = NULL;
	fd = 0;
	while (n && ft_strcmp(n->cmd, "|") != 0)
	{
		if (ft_strcmp(n->cmd, "<") == 0 || ft_strcmp(n->cmd, "<<") == 0)
		{
			fd = ft_fd_in_get_fd_in(id, n->args[0], n->cmd, file_name);
			if (fd == -1)
				return (-1);
		}
		n = n->next;
	}
	return (fd);
}

int	ft_wat_redir_in(char *file_name, int flag, t_id *id, int fd)
{
	int	fd_1;

	if (file_name && flag == 0)
	{
		fd_1 = ft_get_fd_file("<", file_name, id);
		file_name = ft_free(file_name);
		return (fd_1);
	}
	else if (flag == 1)
	{
		if (file_name)
			file_name = ft_free(file_name);
		return (fd);
	}
	return (0);
}
