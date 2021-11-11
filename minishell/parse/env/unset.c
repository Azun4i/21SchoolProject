/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

void	ft_unset_array(t_env **env, char **args)
{
	int	i;

	i = -1;
	while (args[++i] != 0)
	{
		if (there_is_nonvalid(args[i]) == 1)
		{
			g_code = 1;
			printf("\033[91m<mohantochen>\033[0m: ");
			printf("unset: `%s': not a valid identifier\n", args[i]);
		}
		else
		{
			ft_unset(env, args[i]);
			g_code = 0;
		}
	}
}

void	ft_unset(t_env **env, char *args)
{
	t_env	*temp;
	t_env	*temp2;
	t_env	*prev;

	prev = *env;
	temp = *env;
	while (temp != 0)
	{
		if (ft_strcmp(temp->key, args) == 0)
		{
			temp2 = temp;
			prev->next = temp->next;
			temp = prev;
			free(temp2->key);
			if (temp2->value)
				free(temp2->value);
			free(temp2);
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
}

int	there_is_nonvalid(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '\0')
		return (1);
	while (arg[i] != '\0')
	{
		if ((arg[i] >= 48 && arg[i] <= 57) || (arg[i] >= 'a' && arg[i] <= 'z')
			|| (arg[i] >= 'A' && arg[i] <= 'Z'))
			;
		else
			return (1);
		i++;
	}
	return (0);
}
