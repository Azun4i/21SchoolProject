/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:24:11 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:24:13 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

void	ft_pip_void(t_id *id, int argc, char *path)
{
	id->path = path;
	id->iter = 1;
	id->quan_argc = argc + 1;
	id->flag = NULL;
	id->path_fool = NULL;
}

void	*ft_free_mass(char **matrix, int j)
{
	while (j >= 0)
	{
		if (matrix[j])
			free(matrix[j]);
		j--;
	}
	if (matrix)
	{
		free(matrix);
		matrix = NULL;
	}
	return (NULL);
}

int	ft_count_mas(char **mas)
{
	int	i;

	i = 0;
	if (mas)
	{
		while (mas[i] != NULL)
			i++;
	}
	return (i);
}

char	*ft_find_path(char **env)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (env)
	{
		tmp = ft_strnstr(env[i], "PATH", 4);
		if (tmp != NULL)
			return (tmp);
		i++;
	}
	return (NULL);
}
