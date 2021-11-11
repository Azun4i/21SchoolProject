/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:21:49 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:21:51 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

char	*rft_add_fpath_flag(char *path, char **flag)
{
	int		i;
	char	**tmp;
	char	*p;
	char	*tmp_path;
	int		fd_tmp;

	if (path == NULL || flag[0][0] == '.')
		return (ft_ft_do_local_0(path, flag));
	tmp = ft_split(path, ':');
	i = -1;
	while (tmp[++i])
	{
		p = ft_strjoin(tmp[i], "/");
		tmp_path = ft_strjoin(p, flag[0]);
		p = ft_free(p);
		fd_tmp = open(tmp_path, O_RDONLY);
		if (fd_tmp >= 0)
		{
			ft_free_mass(tmp, ft_count_mas(tmp));
			close(fd_tmp);
			return (tmp_path);
		}
		tmp_path = ft_free(tmp_path);
	}
	return (ft_free_mass(tmp, ft_count_mas(tmp)));
}

char	*ft_ft_do_local_0(char *path, char **flag)
{
	if (path == NULL)
		return (NULL);
	else
		return (ft_do_local(flag));
}

char	*ft_do_local(char **flag)
{
	char	pwd[2000];
	char	*path_full;
	char	*tmp;

	path_full = NULL;
	tmp = NULL;
	if (flag[0][0] == '.' && flag[0][1] == '/' && getcwd(pwd, 2000))
	{
		tmp = ft_strdup(flag[0] + 2);
		path_full = ft_strjoin(pwd, tmp);
		free(tmp);
		return (path_full);
	}
	else if (flag[0][0] == '.' && flag[0][1] == '.' && flag[0][2] == '/')
	{
		getcwd(pwd, 2000);
		if (ft_strlen(pwd) > 0)
			return (ft_do_zero(pwd, tmp, path_full, flag[0]));
	}
	return (NULL);
}

char	*ft_do_zero(char *pwd, char *tmp, char *path_full, char *flag)
{
	int		len;
	char	*tmp_tw_dot;

	len = ft_strlen(pwd);
	while (pwd[len--] != '/')
	{
		if (pwd[len] == '/')
		{
			pwd[len] = '\0';
			break ;
		}
	}
	tmp = ft_strdup(flag + 2);
	tmp_tw_dot = ft_strdup(pwd);
	path_full = ft_strjoin(tmp_tw_dot, tmp);
	free(tmp);
	free(tmp_tw_dot);
	return (path_full);
}
