/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:20 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:22 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

/*ctrl-C handler*/

void	sigint_handler(int sig_num)
{
	(void)sig_num;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	g_code = 1;
}

/*ctrl-D handler*/

void	sigexit_handler(t_env **env, char *read_line, t_node **n, int ctrld)
{
	free_env(env);
	free_list_line(read_line, n);
	rl_clear_history();
	if (ctrld)
	{
		rl_on_new_line();
		write(1, "\033[A", 3);
		rl_redisplay();
		write(1, "exit\n", 5);
	}
	else
		write(1, "exit\n", 5);
	if (g_code > 255)
		g_code = g_code % 256;
	exit(g_code);
}

/*ctrl-\ when interactive handler*/

void	sigquit_inter_handler(int sig_num)
{
	(void)sig_num;
	write(1, "Quit: 3\n", 8);
	rl_redisplay();
	write(1, "  ", 2);
	rl_replace_line("", 0);
	rl_redisplay();
	signal(SIGINT, sigint_inter_handler);
	signal(SIGQUIT, sigquit_inter_handler);
	g_code = 131;
}

/*ctrl-C when interactive handler*/

void	sigint_inter_handler(int sig_num)
{
	(void)sig_num;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	signal(SIGINT, sigint_inter_handler);
	signal(SIGQUIT, sigquit_inter_handler);
	g_code = 1;
}

/*ctrl-C handler when double redir*/

void	sigint_handler_redir(int sig_num)
{
	(void)sig_num;
	write(1, "\b\b", 2);
	g_code = 1;
	exit(g_code);
}
