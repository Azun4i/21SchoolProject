#include "ft_pipex.h"

void	*ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

void	ft_pip_void(t_pip *pip)
{
	pip->path_fool = NULL;
	pip->env = NULL;
	pip->argv = NULL;
	pip->argc = 0;
	pip->flag = NULL;
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

	i = 0;
	tmp = NULL;
	while (env)
	{
		tmp = ft_strnstr(env[i], "PATH", 4);
		if (tmp != NULL)
			return (tmp);
		i++;
	}
	return (NULL);
}
