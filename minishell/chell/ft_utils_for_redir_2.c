/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_redir_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:22:28 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:22:29 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_fd_in_get_fd_in(t_id *id, char *args, char *cmd, char *file_name)
{
	int		flag;
	int		fd;

	flag = -1;
	fd = 0;
	if (ft_strcmp(cmd, "<") == 0)
	{
		if (file_name)
			file_name = ft_free(file_name);
		file_name = ft_strdup(args);
		flag = 0;
		fd = ft_wat_redir_in(file_name, flag, id, fd);
		if (fd == -1)
		{
			dup2(id->save_o, 1);
			errors(args);
			return (-1);
		}
	}
	else
	{
		fd = double_redir_read(args, id);
		flag = 1;
	}
	return (fd);
}
