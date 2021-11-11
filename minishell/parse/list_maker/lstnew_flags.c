/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:29 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:30 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

int	get_flags(char *read_line, int i, t_node *new)
{
	int	flags_counter;
	int	temp;
	int	flag_num;

	flags_counter = get_flags_count_flags(read_line, i);
	temp = i;
	if (get_flags_malloc(new, flags_counter) == -1)
		malloc_error();
	flag_num = 1;
	while (flag_num < flags_counter + 1)
	{
		if (read_line[temp] == '-')
		{
			temp = get_flags_etc(read_line, flag_num, new, temp);
			if (temp == -1)
				malloc_error();
			flag_num++;
		}
		else
			temp++;
	}
	return (skip_spaces(read_line, temp));
}

int	get_flags_malloc(t_node *new, int flags_counter)
{
	new->flags = (char **)malloc(sizeof(char *) * (flags_counter + 2));
	if (new->flags == NULL)
		return (-1);
	new->flags[0] = ft_strdup(new->cmd);
	new->flags[flags_counter + 1] = 0;
	if (new->flags[0] == NULL)
		return (-1);
	return (0);
}

int	get_flags_etc(char *read_line, int flag_num, t_node *new, int temp)
{
	int	start;
	int	j;

	start = temp;
	while (read_line[temp] != '\0' && read_line[temp] != ' '
		   && read_line[temp] != '<' && read_line[temp] != '>'
		   && read_line[temp] != '|')
		temp++;
	new->flags[flag_num] = malloc(sizeof(char) * (temp - start + 1));
	if (new->flags[flag_num] == NULL)
		return (-1);
	j = 0;
	while (start < temp)
	{
		new->flags[flag_num][j] = read_line[start];
		args_flags_replacer(new->flags[flag_num], j);
		j++;
		start++;
	}
	new->flags[flag_num][j] = '\0';
	return (temp);
}

int	get_flags_count_flags(char *read_line, int i)
{
	int	flags_counter;

	flags_counter = 0;
	while (read_line[i] != '\0' && read_line[i] != '|')
	{
		if (read_line[i] == '-')
		{
			flags_counter++;
			while (read_line[i] != '\0' && read_line[i] != ' '
				   && read_line[i] != '<' && read_line[i] != '>'
				   && read_line[i] != '|')
				i++;
			i = skip_spaces(read_line, i);
		}
		else
			break ;
	}
	return (flags_counter);
}
