/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:29 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:30 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*find and save all args for cmd*/

int	get_args(char *read_line, int i, t_node *new)
{
	int	args_counter;
	int	temp;
	int	arg_num;

	temp = i;
	args_counter = get_args_count_args(read_line, i);
	new->args = (char **)malloc(sizeof(char *) * (args_counter + 1));
	if (new->args == NULL)
		malloc_error();
	new->args[args_counter] = 0;
	arg_num = -1;
	while (++arg_num < args_counter)
	{
		temp = get_args_etc(read_line, new, temp, arg_num);
		if (temp == -1)
			malloc_error();
	}
	return (skip_spaces(read_line, temp));
}

int	get_args_count_args(char *read_line, int i)
{
	int	args_counter;

	args_counter = 0;
	while (read_line[i] != '\0' && read_line[i] != '|')
	{
		args_counter++;
		while (read_line[i] != '\0' && read_line[i] != ' ' && read_line[i]
			   != '<' && read_line[i] != '>' && read_line[i] != '|')
			i++;
		i = skip_spaces(read_line, i);
		i = skip_redir(read_line, i);
	}
	return (args_counter);
}

int	get_args_etc(char *read_line, t_node *new, int temp, int arg_num)
{
	int	j;
	int	start;

	start = temp;
	while (read_line[temp] != '\0' && read_line[temp] != ' '
		   && read_line[temp] != '<' && read_line[temp] != '>'
		   && read_line[temp] != '|')
		temp++;
	new->args[arg_num] = (char *)malloc(sizeof(char) * (temp - start + 1));
	if (new->args[arg_num] == NULL)
		return (-1);
	j = 0;
	while (start < temp)
	{
		new->args[arg_num][j] = read_line[start];
		args_flags_replacer(new->args[arg_num], j);
		if (new->args[arg_num][j] == 31)
			j--;
		j++;
		start++;
	}
	new->args[arg_num][j] = '\0';
	temp = skip_spaces(read_line, temp);
	temp = skip_redir(read_line, temp);
	return (temp);
}

void	args_flags_replacer(char *str, int j)
{
	if (str[j] == 30)
		str[j] = ' ';
	else if (str[j] == 28)
		str[j] = '>';
	else if (str[j] == 29)
		str[j] = '<';
	else if (str[j] == 26)
		str[j] = '|';
}
