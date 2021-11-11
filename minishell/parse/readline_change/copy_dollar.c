/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:52:48 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:52:50 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

char	*copy_dollar(char *line, char *changed, int start, t_env *env)
{
	int		end;
	char	*key;
	int		j;

	if (line[start] == '?')
		return (copy_dollar_question(line, changed, env));
	end = find_dollar_end(line, start);
	key = (char *)malloc(sizeof(char) * (end - start + 1));
	if (key == NULL)
		malloc_error();
	j = 0;
	while (start < end)
		key[j++] = line[start++];
	key[j] = '\0';
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0 && env->value)
			changed = copy_dollar_envvalue(line, changed, key, env->value);
		env = env->next;
	}
	free(key);
	return (changed);
}

char	*copy_dollar_question(char *line, char *changed, t_env *env)
{
	char	*key;
	int		j;
	int		i;

	key = ft_itoa(g_code);
	if (key == NULL)
		malloc_error();
	i = 0;
	changed = ft_realloc(changed, (int)ft_strlen(line) + (int)ft_strlen(changed)
			- 2 + (int)ft_strlen(key));
	if (changed == NULL)
		malloc_error();
	j = (int)ft_strlen(changed);
	while (key[i] != '\0')
		changed[j++] = key[i++];
	free(key);
	(void)env;
	return (changed);
}

char	*copy_dollar_envvalue(char *line, char *changed, char *key,
							  char *envvalue)
{
	int	j;
	int	i;

	changed = ft_realloc(changed, (int)ft_strlen(line)
			+ (int)ft_strlen(changed)
			- ((int)ft_strlen(key) + 1)
			+ (int)ft_strlen(envvalue));
	if (changed == NULL)
		malloc_error();
	j = (int)ft_strlen(changed);
	i = 0;
	while (envvalue[i] != '\0')
		changed[j++] = envvalue[i++];
	changed[j] = '\0';
	return (changed);
}

char	*ft_realloc(char *source, int size)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (copy == NULL)
		malloc_error();
	i = -1;
	while (source[++i] != '\0')
		copy[i] = source[i];
	copy[i] = '\0';
	free(source);
	source = (char *)malloc(sizeof(char) * (size + 1));
	if (source == NULL)
		malloc_error();
	i = -1;
	while (copy[++i] != '\0')
		source[i] = copy[i];
	source[i] = '\0';
	while (++i <= size)
		source[i] = '\0';
	free(copy);
	return (source);
}

int	find_dollar_end(char *line, int i)
{
	if (line[i] == '?')
		return (i + 1);
	while (line[i] == '_'
		   || (line[i] >= 48 && line[i] <= 57)
		   || (line[i] >= 'a' && line[i] <= 'z')
		   || (line[i] >= 'A' && line[i] <= 'Z'))
		i++;
	return (i);
}
