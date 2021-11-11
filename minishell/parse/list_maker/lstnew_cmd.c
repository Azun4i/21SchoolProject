/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:29 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:30 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*make new list for cmd (get its flags and args)*/

t_node	*ft_lstnew_cmd(char *read_line, int i)
{
	t_node	*new;

	i = skip_redir(read_line, i);
	if (read_line[i] == '\0' || read_line[i] == '|')
		return (NULL);
	new = malloc(sizeof(t_node));
	if (new == NULL)
		malloc_error();
	i = get_cmd(read_line, i, new);
	i = skip_redir(read_line, i);
	if (read_line[i] == '\0' || read_line[i] == '|')
	{
		i = get_flags(read_line, i, new);
		new->args = 0;
		new->next = NULL;
		return (new);
	}
	i = get_flags(read_line, i, new);
	i = skip_redir(read_line, i);
	if (read_line[i] == '\0' || read_line[i] == '|')
		new->args = 0;
	else
		i = get_args(read_line, i, new);
	new->next = NULL;
	return (new);
}

/*find cmd and save it*/

int	get_cmd(char *read_line, int i, t_node *new)
{
	int	j;
	int	start;

	start = i;
	while (read_line[i] != '\0' && read_line[i] != ' ' && read_line[i] != '|')
		i++;
	new->cmd = (char *)malloc(sizeof(char) * (i - start + 1));
	if (new->cmd == NULL)
		malloc_error();
	j = 0;
	while (start < i)
	{
		new->cmd[j] = read_line[start++];
		if (new->cmd[j] == 30)
			new->cmd[j] = ' ';
		else if (new->cmd[j] == 28)
			new->cmd[j] = '>';
		else if (new->cmd[j] == 29)
			new->cmd[j] = '<';
		else if (new->cmd[j] == 26)
			new->cmd[j] = '|';
		j++;
	}
	new->cmd[j] = '\0';
	return (skip_spaces(read_line, i));
}
