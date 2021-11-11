#include "ft_pipex_bonus.h"

void	*ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

void	ft_pip_void(t_pip *pip, char **argv, char **env, int argc)
{
	pip->argv = argv;
	pip->env = env;
	pip->iter = 0;
	pip->quan_argc = argc - 1;
	pip->flag = NULL;
	pip->path_fool = NULL;
}

void	ft_free_mass(char **matrix, int j)
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
}

int	ft_count_mas(char **mas)
{
	int	i;

	i = 0;
	while (mas[i] != NULL)
		i++;
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
