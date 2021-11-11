/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*create env-lists first time*/

t_env	*create_env_list(t_env **enve, char **envp)
{
	t_env	*env;
	int		i;

	env = *enve;
	i = 0;
	while (envp[i] != 0)
	{
		ft_lstadd_back_env(&env, ft_lstnew_env(envp[i]));
		i++;
	}
	*enve = env;
	return (env);
}

/*create new list with key and value*/

t_env	*ft_lstnew_env(char *envp)
{
	t_env	*new;
	int		i;
	int		start;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (envp[i] != '=' && envp[i] != '\0')
		i++;
	new->key = (char *)malloc(sizeof(char) * (i + 1));
	if (new->key == NULL)
		return (NULL);
	start = -1;
	while (++start < i)
		new->key[start] = envp[start];
	new->key[start] = '\0';
	if (ft_lstnew_env_copyvalue(new, envp, i) == -1)
		malloc_error();
	new->next = NULL;
	return (new);
}

/*copy value to the newly created list*/

int	ft_lstnew_env_copyvalue(t_env *new, char *envp, int i)
{
	int	start;
	int	temp;

	if (envp[i] == '\0')
		new->value = NULL;
	else
	{
		temp = i + 1;
		while (envp[i] != '\0')
			i++;
		new->value = (char *)malloc(sizeof(char) * (i - temp + 1));
		if (new->value == NULL)
			return (-1);
		start = 0;
		while (temp < i)
			new->value[start++] = envp[temp++];
		new->value[start] = '\0';
	}
	return (0);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (new == 0 || lst == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = new;
	}
}
