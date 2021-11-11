/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*make array from env*/

char	**make_env_array(t_env *env)
{
	int		list_size;
	t_env	*temp;
	char	**array;

	list_size = 0;
	temp = env;
	while (temp != 0)
	{
		if (temp->value != NULL)
			list_size++;
		temp = temp->next;
	}
	array = (char **)malloc(sizeof(char *) * (list_size + 1));
	if (array == NULL)
		malloc_error();
	array[list_size] = 0;
	copy_env_array(env, array);
	return (array);
}

void	copy_env_array(t_env *env, char **array)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (env != 0)
	{
		j = 0;
		if (env->value != NULL)
		{
			array[++i] = (char *)malloc(sizeof(char) * (ft_strlen(env->key)
						+ ft_strlen(env->value) + 2));
			if (array[i] == NULL)
				malloc_error();
			k = 0;
			while (env->key[k] != '\0')
				array[i][j++] = env->key[k++];
			array[i][j++] = '=';
			k = 0;
			while (env->value[k] != '\0')
				array[i][j++] = env->value[k++];
			array[i][j++] = '\0';
		}
		env = env->next;
	}
}
