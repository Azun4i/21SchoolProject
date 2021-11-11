/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rft_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:23:21 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:23:24 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	rft_cd(char **path, char **flag, t_env **env, int result)
{
	if (path || flag[1])
	{
		ft_add_old_pwd(env);
		if (flag[1] != NULL)
			result = chdir(flag[1]);
		else
			result = chdir(path[0]);
		ft_add_new_pwd(env);
	}
	else
	{
		if (ft_find_key(*env, "HOME") == NULL)
		{
			errors("cd: HOME not set");
			g_code = 1;
			return (-1);
		}
		else
			result = chdir(ft_find_key(*env, "HOME"));
	}
	if (result < 0)
		return (ft_check_res_if_o(result, flag, path));
	g_code = 0;
	return (result);
}

int	ft_check_res_if_o(int result, char **flag, char **path)
{
	if (flag[1] != NULL)
		errors(flag[1]);
	else
	{
		errors(path[0]);
		g_code = 1;
	}
	return (result);
}

void	ft_add_old_pwd(t_env **env)
{
	char	*old;
	char	*tmp_old;
	char	*pwd;

	old = "OLDPWD=";
	pwd = ft_get_cwd();
	tmp_old = ft_strjoin(old, pwd);
	free(pwd);
	env_value_change(env, tmp_old);
	free(tmp_old);
}

void	ft_add_new_pwd(t_env **env)
{
	char	*new;
	char	*tmp_pwd;
	char	*pwd;

	new = "PWD=";
	pwd = ft_get_cwd();
	tmp_pwd = ft_strjoin(new, pwd);
	free(pwd);
	env_value_change(env, tmp_pwd);
	free(tmp_pwd);
}

char	*ft_get_cwd(void)
{
	char	*pwd;

	pwd = ft_calloc(1024, 1);
	if (pwd == NULL)
		errors("Malloc error");
	if (getcwd(pwd, 1024))
	   ;
	return (pwd);
}
