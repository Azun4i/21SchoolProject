/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:29 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:30 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*make new list for redir (get its args)*/

t_node	*ft_lstnew_redir(char *read_line, int i)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	while (read_line[i] != '<' && read_line[i] != '>'
		   && read_line[i] != '\0' && read_line[i] != '|')
		i++;
	if (read_line[i] != '|' && read_line[i] != '\0')
	{
		i = get_redir(read_line, i, new);
		i = skip_spaces(read_line, i);
	}
	new->next = NULL;
	return (new);
}

int	get_redir(char *read_line, int i, t_node *new)
{
	if ((read_line[i] == '>' && read_line[i + 1] == '>')
		|| (read_line[i] == '<' && read_line[i + 1] == '<'))
	{
		new->cmd = (char *)malloc(sizeof(char) * 3);
		if (new->cmd == NULL)
			malloc_error();
		new->cmd[0] = read_line[i];
		new->cmd[1] = read_line[i];
		new->cmd[2] = '\0';
		i = i + 2;
	}
	else
	{
		new->cmd = (char *)malloc(sizeof(char) * 2);
		if (new->cmd == NULL)
			malloc_error();
		new->cmd[0] = read_line[i];
		new->cmd[1] = '\0';
		i++;
	}
	i = skip_spaces(read_line, i);
	new->flags = 0;
	i = get_redir_arg(read_line, i, new);
	i = skip_spaces(read_line, i);
	return (i);
}

int	get_redir_arg(char *read_line, int i, t_node *new)
{
	int	start;
	int	j;

	if (read_line[i] == '\0' || read_line[i] == '|'
		|| read_line[i] == '<' || read_line[i] == '>')
		new->args = 0;
	else
	{
		start = i;
		while (read_line[i] != '\0' && read_line[i] != '|' && read_line[i]
			   != ' ' && read_line[i] != '>' && read_line[i] != '<')
			i++;
		new->args = (char **)malloc(sizeof(char *) * 2);
		if (new->args == NULL)
			malloc_error();
		new->args[1] = 0;
		new->args[0] = (char *)malloc(sizeof(char) * (i - start + 1));
		if (new->args == NULL)
			malloc_error();
		j = 0;
		while (start < i)
			new->args[0][j++] = read_line[start++];
		new->args[0][j] = '\0';
	}
	return (i);
}

/*skip redir and its args*/

int	skip_redir(char *read_line, int i)
{
	i = skip_spaces(read_line, i);
	while (read_line[i] == '<' || read_line[i] == '>')
	{
		while (read_line[i] == '<' || read_line[i] == '>')
			i++;
		i = skip_spaces(read_line, i);
		while (read_line[i] != '\0' && read_line[i] != ' '
			   && read_line[i] != '|')
			i++;
		i = skip_spaces(read_line, i);
	}
	return (i);
}

t_node	*ft_lstnew_pipe(char *read_line, int i)
{
	t_node	*new;

	(void)read_line;
	(void)i;
	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->cmd = (char *)malloc(sizeof(char) * 2);
	if (new->cmd == NULL)
	{
		free(new);
		malloc_error();
	}
	new->cmd[0] = '|';
	new->cmd[1] = '\0';
	new->flags = 0;
	new->args = 0;
	new->next = NULL;
	return (new);
}
