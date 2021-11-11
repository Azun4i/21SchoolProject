/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor/cchelste <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:19 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:20 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_code = 0;

int	main(int argc, char *argv[], char *envp[])
{
	char	*read_line;
	t_node	*n;
	t_env	*env;
	t_id	id;

	id.save_i = dup(0);
	id.save_o = dup(1);
	errno = 0;
	env = create_env_list(&env, envp);
	change_oldpwd_and_shlvl(&env, argc, argv);
	while (1)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		read_line = readline("\033[91m<mohantochen> \033[0m");
		if (read_line == NULL)
			sigexit_handler(&env, read_line, &n, 1);
		if (read_line[0] != '\0')
			add_history(read_line);
		read_line = change_line(read_line, env);
		cchelste(parse(&n, read_line), &env, read_line, &id);
		read_line = free_list_line(read_line, &n);
		dup2(id.save_i, 0);
		dup2(id.save_o, 1);
	}
}

void	change_oldpwd_and_shlvl(t_env **env, int argc, char *argv[])
{
	ft_unset(env, "OLDPWD");
	env_value_change(env, "OLDPWD");
	change_shell_lvl(env, 1);
	(void)argc;
	(void)argv;
}

void	errors(char *message)
{
	if (errno)
		printf("\033[91m<mohantochen>\033[0m: %s: %s\n", message, strerror(errno));
	else
		printf("\033[91m<mohantochen>\033[0m: %s\n", message);
	errno = 0;
}

void	change_shell_lvl(t_env **env, int i)
{
	char	*temp;
	char	*temp1;
	t_env	*list;
	int		atoi_ret;

	list = *env;
	while (list != 0)
	{
		if (ft_strcmp(list->key, "SHLVL") == 0 && list->value != NULL)
		{
			atoi_ret = ft_atoi(list->value);
			if (atoi_ret < 0)
				atoi_ret = -1;
			temp1 = ft_itoa(atoi_ret + i);
			temp = ft_strjoin("SHLVL=", temp1);
			if (temp == NULL || temp1 == NULL)
				errors("Malloc error");
			env_value_change(env, temp);
			free(temp);
			free(temp1);
			return ;
		}
		list = list->next;
	}
	env_value_change(env, "SHLVL=1");
}
