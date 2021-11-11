/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:00 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:53:02 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

int	check_key(char *key)
{
	int	i;

	i = 0;
	if (key[0] >= 48 && key[i] <= 57)
		return (-1);
	while (key[i] != '\0')
	{
		if ((key[i] >= 48 && key[i] <= 57) || (key[i] >= 65 && key[i] <= 90)
			|| key[i] >= 95 || (key[i] >= 97 && key[i] <= 122))
			i++;
		else
			return (-1);
	}
	return (0);
}

/*check if there is '=' in the keyvalue string*/

int	check_for_equal(char *keyvalue)
{
	int	i;

	i = 0;
	while (keyvalue[i] != '\0')
	{
		if (keyvalue[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

/*get key part from "key=value"*/

char	*get_key(char *keyvalue)
{
	char	*key;
	int		i;

	i = 0;
	while (keyvalue[i] != '=' && keyvalue[i] != '\0')
		i++;
	key = (char *)malloc(sizeof(char) * (i + 1));
	if (key == NULL)
		malloc_error();
	else
	{
		i = 0;
		while (keyvalue[i] != '=' && keyvalue[i] != '\0')
		{
			key[i] = keyvalue[i];
			i++;
		}
		key[i] = '\0';
	}
	return (key);
}

/*get value part from "key=value"*/

char	*get_value(char *keyvalue)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (keyvalue[i] != '=' && keyvalue[i] != '\0')
		i++;
	if (keyvalue[i] == '\0')
		return (NULL);
	value = (char *)malloc(sizeof(char) * (ft_strlen(keyvalue) - i));
	if (value == NULL)
		malloc_error();
	else
	{
		j = 0;
		i++;
		while (keyvalue[i] != '\0')
		{
			value[j] = keyvalue[i];
			i++;
			j++;
		}
		value[j] = '\0';
	}
	return (value);
}
