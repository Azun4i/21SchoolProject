/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_do_path_direct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:22:03 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:22:06 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	ft_do_errors(char *cmd)
{
	char	*str;

	errno = 0;
	str = ft_strjoin(cmd, ": is a directory");
	errors(str);
	free(str);
	g_code = 126;
}

void	ft_utl_path_direct(t_node *n, t_env **env, t_id *id)
{
	char	**flag;
	char	**envp;

	flag = ft_do_add_args_flags(n->flags, n->args);
	if (open(n->cmd, O_RDONLY) > 0)
	{
		if (n->cmd[ft_strlen(n->cmd) - 1] == '/')
		{
			ft_do_errors(n->cmd);
			exit(g_code);
		}
		envp = make_env_array(*env);
		if (id->r_fd_in > 0 || id->r_fd_out > 1)
			ft_do_dup(n, id);
		g_code = execve(n->cmd, flag, envp);
		ft_free_mass(flag, ft_count_mas(flag));
		ft_free_mass(envp, ft_count_mas(envp));
		exit(g_code);
	}
	else
	{
		errors(flag[0]);
		g_code = 127;
		exit(g_code);
	}
}

void	ft_do_g_code(int stat, char	*path_full)
{
	if (stat != 0)
	{
		g_code = WEXITSTATUS(stat);
		if (g_code == 2)
			g_code = 1;
	}
	else
		g_code = 0;
	path_full = ft_free(path_full);
}
