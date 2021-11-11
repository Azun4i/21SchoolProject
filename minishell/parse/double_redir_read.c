/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_redir_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:20 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:22 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

void	r_read_left_redir_dup_back(t_id *id)
{
	if (id->iter % 2 == 0)
		dup2(id->fd_a[1], 1);
	else if (id->iter % 2 == 1)
		dup2(id->fd_b[1], 1);
}

int	double_redir_read(char *arg, t_id *id)
{
	int		pid;

	if ((pipe(id->rid_fd) < 0))
		errors("pipe");
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid)
	{
		waitpid(pid, 0, 0);
		close(id->rid_fd[1]);
	}
	else
	{
		close(id->rid_fd[0]);
		r_read_left_redir(arg, id);
	}
	signal(SIGINT, sigint_inter_handler);
	signal(SIGQUIT, sigquit_inter_handler);
	return (id->rid_fd[0]);
}

void	r_read_left_redir(char *arg, t_id *id)
{
	char	*line;

	dup2(id->save_o, 1);
	dup2(id->save_i, 0);
	while (1)
	{
		signal(SIGINT, sigint_handler_redir);
		signal(SIGQUIT, SIG_IGN);
		line = readline("> ");
		if (ft_strcmp(arg, line) == 0)
		{
			g_code = 0;
			break ;
		}
		ft_putendl_fd(line, id->rid_fd[1]);
		if (line)
			free(line);
		line = NULL;
	}
	r_read_left_redir_dup_back(id);
	signal(SIGINT, sigint_inter_handler);
	signal(SIGQUIT, sigquit_inter_handler);
	close(id->rid_fd[1]);
	exit(g_code);
}

void	malloc_error(void)
{
	printf("\033[91m<mohantochen>\033[0m: Malloc error: %s\n", strerror(errno));
	exit(1);
}
