/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*search the key and change its value or add key and value if there is no*/

void	export_with_args(t_env **enve, char **keyvalue)
{
	int	j;

	j = 0;
	while (keyvalue[j] != 0)
	{
		env_value_change(enve, keyvalue[j]);
		j++;
	}
}

/*search the key and change its value or add key and value if there is no*/

void	env_value_change(t_env **enve, char *keyvalue)
{
	char	*key;
	int		flag_found;

	if ((keyvalue && keyvalue[0] == '=') || (keyvalue && keyvalue[0] == '\0'))
	{
		printf("\033[91m<mohantochen>\033[0m: ");
		printf("export: `%s': not a valid identifier\n", keyvalue);
		g_code = 1;
		return ;
	}
	flag_found = 0;
	key = get_key(keyvalue);
	if (key == NULL)
		malloc_error();
	if (check_key(key) == -1)
	{
		printf("\033[91m<mohantochen>\033[0m: ");
		printf("export: `%s': not a valid identifier\n", keyvalue);
		g_code = 1;
		free(key);
		return ;
	}
	if (env_value_change_searchlist(enve, keyvalue, key, flag_found) == -1)
		malloc_error();
	g_code = 0;
}

int	env_value_change_searchlist(t_env **enve, char *keyvalue, char *key,
								int flag_found)
{
	t_env	*temp;

	temp = *enve;
	while (temp != 0)
	{
		if (ft_strcmp(key, temp->key) == 0)
		{
			if (check_for_equal(keyvalue) == 1)
			{
				if (temp->value)
					free(temp->value);
				temp->value = get_value(keyvalue);
				if (temp->value == NULL)
					return (-1);
			}
			flag_found = 1;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	free(key);
	if (flag_found == 0)
		ft_lstadd_back_env(enve, ft_lstnew_env(keyvalue));
	return (0);
}
