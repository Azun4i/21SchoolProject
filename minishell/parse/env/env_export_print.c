/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

void	print_env(t_env *env)
{
	while (env != NULL)
	{
		if (env->value)
		{
			printf("%s=%s\n", env->key, env->value);
		}
		env = env->next;
	}
	g_code = 0;
}

/*copy env, sort, print and free it*/

void	export(t_env *env)
{
	t_env	*export;

	export = NULL;
	while (env != NULL)
	{
		ft_lstadd_back_env(&export, ft_lstnew_export(env->key, env->value));
		env = env->next;
	}
	sort_export(&export);
	print_export(export);
	free_env(&export);
	g_code = 0;
}

t_env	*ft_lstnew_export(char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		malloc_error();
	new->key = ft_strdup(key);
	if (new->key == NULL)
		malloc_error();
	if (value != NULL)
	{
		new->value = ft_strdup(value);
		if (new->value == NULL)
			malloc_error();
	}
	else
		new->value = NULL;
	new->next = NULL;
	return (new);
}

void	sort_export(t_env **export)
{
	char	*temp_key;
	char	*temp_value;
	int		swaps;
	t_env	*exp;

	swaps = 1;
	while (swaps > 0)
	{
		swaps = 0;
		exp = *export;
		while (exp->next != NULL)
		{
			if (ft_strcmp(exp->key, exp->next->key) > 0)
			{
				temp_key = exp->key;
				temp_value = exp->value;
				exp->key = exp->next->key;
				exp->value = exp->next->value;
				exp->next->key = temp_key;
				exp->next->value = temp_value;
				swaps++;
			}
			exp = exp->next;
		}
	}
}

void	print_export(t_env *export)
{
	while (export != NULL)
	{
		if (ft_strcmp(export->key, "_") != 0)
		{
			if (export->value)
				printf("declare -x %s=\"%s\"\n", export->key, export->value);
			else
				printf("declare -x %s\n", export->key);
		}
		export = export->next;
	}
}
