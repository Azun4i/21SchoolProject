/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:22:37 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:23:07 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

char	**ft_do_add_args_flags(char **flag, char **args)
{
	int		k;
	char	**tmp;
	int		len_flag;
	int		len_argc;

	len_flag = ft_count_mas(flag);
	len_argc = ft_count_mas(args);
	tmp = (char **) malloc(sizeof(char *) * (len_flag + len_argc) + 1);
	if (tmp == NULL)
		malloc_error();
	tmp[len_flag + len_argc] = NULL;
	if (ft_strcmp(flag[0], "/") == 0)
	{
		k = ft_strlen(flag[0]);
		while (flag[0][k--] != '/')
		{
			if (flag[0][k] == '/')
			{
				flag[0][k] = '\0';
				break ;
			}
		}
	}
	ft_do_add_args_flags_litl(tmp, flag, args);
	return (tmp);
}

void	ft_do_add_args_flags_litl(char **tmp, char **flag, char **args)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	while (flag[k])
	{
		tmp[k] = ft_strdup(flag[k]);
		k++;
	}
	if (args)
	{
		while (args[j])
		{
			tmp[k + j] = ft_strdup(args[j]);
			j++;
		}
	}
}

void	ft_do_if_path_direct(t_node *n, t_env **env, t_id *id)
{
	pid_t	p_id;
	int		stat;

	p_id = fork();
	if (p_id == 0)
		ft_utl_path_direct(n, env, id);
	else
	{
		waitpid(p_id, &stat, WUNTRACED | WCONTINUED);
		if (stat != 0)
		{
			g_code = WEXITSTATUS(stat);
			if (g_code == 2)
				g_code = 1;
		}
		else
			g_code = 0;
	}
	wait(NULL);
}

void	ft_do_if_path_normal(t_node *n, t_env **env, t_id *id, char *path)
{
	char	*path_full;
	char	**envp;
	char	**flag;

	path_full = path;
	flag = ft_do_add_args_flags(n->flags, n->args);
	envp = make_env_array(*env);
	if (id->r_fd_in > 0 || id->r_fd_out > 1)
		ft_do_dup(n, id);
	execve(path_full, flag, envp);
	path_full = ft_free(path_full);
	ft_free_mass(flag, ft_count_mas(flag));
	ft_free_mass(envp, ft_count_mas(envp));
}

int	ft_other_func_exec(t_node *n, t_env **env, t_id *id)
{
	pid_t	p_id;
	char	*path_full;
	int		stat;

	if (n->flags == NULL)
		return (g_code);
	if (ft_strchr(n->cmd, '/') != NULL)
	{
		ft_do_if_path_direct(n, env, id);
		return (g_code);
	}
	path_full = rft_add_fpath_flag(ft_find_key(*env, "PATH"), n->flags);
	if (path_full == NULL)
		return (rft_check_path(path_full, ft_find_key(*env, "PATH"), n, id));
	p_id = fork();
	if (p_id == 0)
	{
		ft_do_if_path_normal(n, env, id, path_full);
		if (g_code != 0)
			errors(n->args[0]);
		exit(g_code);
	}
	waitpid(p_id, &stat, WUNTRACED | WCONTINUED);
	ft_do_g_code(stat, path_full);
	return (g_code);
}
