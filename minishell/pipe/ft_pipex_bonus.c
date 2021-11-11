/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:23:58 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:24:00 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	ft_do_g_code_in_pipe(int stat)
{
	if (stat != 0)
	{
		g_code = WEXITSTATUS(stat);
		if (g_code == 2)
			g_code = 258;
	}
	else
		g_code = 0;
}

int	ft_pipex_utils(t_node *n, t_env *env, t_id *id, char *read_line)
{
	id->id = fork();
	if (id->id < 0)
		errors("fork");
	if (id->id == 0)
	{
		bft_proc_child(n, id, read_line, &env);
		exit(g_code);
	}
	else
	{
		waitpid(id->id, &id->stat, WUNTRACED | WCONTINUED);
		ft_do_g_code_in_pipe(id->stat);
		bft_proc_main(id);
		if (g_code == 258)
			return (-100);
	}
	return (0);
}

void	ft_init_pipe(t_node *n, t_env *env, t_id *id)
{
	ft_pip_void(id, ft_count_pipe(n), ft_find_key(env, "PATH"));
	if ((pipe(id->fd_a)) < 0 || (pipe(id->fd_b)) < 0)
		errors("pipe");
}

void	ft_pipex(t_node *n, t_env *env, t_id *id, char *read_line)
{
	ft_init_pipe(n, env, id);
	while (n)
	{
		if (ft_strcmp(n->cmd, "|") == 0)
			n = n->next;
		else
		{
			if (ft_pipex_utils(n, env, id, read_line) == -100)
				break ;
			while (n && ft_strcmp(n->cmd, "|") != 0)
				n = n->next;
		}
	}
}

char	*ft_find_key(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
				return (tmp->value);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
