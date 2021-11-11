/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:33:53 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:33:54 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	ft_run_biltin(t_node *n, t_env **env, char *read_line, t_id *id)
{
	int	result;

	result = 0;
	if (id->r_fd_in > 0 || id->r_fd_out > 1)
		ft_do_dup(n, id);
	if (ft_strcmp(n->cmd, "export") == 0 && n->args != 0)
		export_with_args(env, n->args);
	else if (ft_strcmp(n->cmd, "export") == 0)
		export(*env);
	else if (ft_strcmp(n->cmd, "env") == 0)
		print_env(*env);
	else if (ft_strcmp(n->cmd, "unset") == 0 && n->args != 0)
		ft_unset_array(env, n->args);
	else if (ft_strcmp(n->cmd, "exit") == 0 && n->flags[1] == 0 && n->args == 0)
		sigexit_handler(env, read_line, &n, 0);
	else if (ft_strcmp(n->cmd, "exit") == 0
		   && ft_exit(n->flags, n->args, 0, 0) == 1)
		sigexit_handler(env, read_line, &n, 0);
	else if (ft_check_register(n->cmd) == 1)
		rft_pwd();
	else if (ft_check_register(n->cmd) == 0)
		rft_echo(n->flags, n->args);
	else if (ft_strcmp(n->cmd, "cd") == 0)
		rft_cd(n->args, n->flags, env, result);
}

int	is_biltin(char *cmd)
{
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else if (ft_check_register(cmd) == 1)
		return (1);
	else if (ft_check_register(cmd) == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else
		return (0);
}

void	cchelste(t_node *n, t_env **env, char *read_line, t_id *id)
{
	signal(SIGINT, sigint_inter_handler);
	signal(SIGQUIT, sigquit_inter_handler);
	if (n == NULL)
		return ;
	if (ft_find_pipe(n) == 0)
		ft_if_redir(n, env, read_line, id);
	else
		ft_pipex(n, *env, id, read_line);
}

int	rft_check_path(char *path, char *env, t_node *n, t_id *id)
{
	if (env && path == NULL)
	{
		dup2(id->save_i, 0);
		dup2(id->save_o, 1);
		printf("\033[91m<mohantochen>\033[0m: %s: command not found\n",
			 n->flags[0]);
		g_code = 127;
	}
	else if (env == NULL && path == NULL)
	{
		dup2(id->save_i, 0);
		dup2(id->save_o, 1);
		printf("\033[91m<mohantochen>\033[0m: %s: No such file or "
			"directory\n", n->flags[0]);
		g_code = 127;
	}
	path = ft_free(path);
	return (g_code);
}

void	print_list(t_node *n)
{
	int	i;

	while (n != NULL)
	{
		printf("cmd: %s\n", n->cmd);
		if (n->flags != 0)
		{
			i = 0;
			while (n->flags[i] != 0)
			{
				printf("flags: %s\n", n->flags[i]);
				i++;
			}
		}
		if (n->args != 0)
		{
			i = 0;
			while (n->args[i] != 0)
			{
				printf("args: %s\n", n->args[i]);
				i++;
			}
		}
		n = n->next;
	}
}
