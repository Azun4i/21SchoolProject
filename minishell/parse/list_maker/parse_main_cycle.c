/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:29 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:30 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

/*parser main cycle*/

t_node	*parse(t_node **m, char *read_line)
{
	int		i;
	t_node	*n;

	n = *m;
	i = 0;
	while (read_line[i] != '\0')
	{
		ft_lstadd_back_shell(&n, ft_lstnew_cmd(read_line, i));
		while (redir_detected(read_line, i) == 1 && read_line[i] != '\0'
			   && read_line[i] != '|')
		{
			ft_lstadd_back_shell(&n, ft_lstnew_redir(read_line, i));
			i = find_and_skip_redir(read_line, i);
		}
		while (read_line[i] != '\0' && read_line[i] != '|')
			i++;
		if (read_line[i] == '|')
		{
			ft_lstadd_back_shell(&n, ft_lstnew_pipe(read_line, i));
			i++;
			i = skip_spaces(read_line, i);
		}
	}
	*m = n;
	return (n);
}

void	ft_lstadd_back_shell(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (new == 0 || lst == 0)
	{
		return ;
	}
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

int	redir_detected(char *read_line, int i)
{
	while (read_line[i] != '\0' && read_line[i] != '>'
		   && read_line[i] != '<' && read_line[i] != '|')
		i++;
	if (read_line[i] == '>' || read_line[i] == '<')
		return (1);
	return (0);
}

/*search and skip one redir and its arg*/

int	find_and_skip_redir(char *read_line, int i)
{
	while (read_line[i] != '<' && read_line[i] != '>'
		   && read_line[i] != '\0' && read_line[i] != '|')
		i++;
	if (read_line[i] == '<')
	{
		i++;
		if (read_line[i] == '<')
			i++;
	}
	else if (read_line[i] == '>')
	{
		i++;
		if (read_line[i] == '>')
			i++;
	}
	i = skip_spaces(read_line, i);
	while (read_line[i] != '\0' && read_line[i] != ' '
		   && read_line[i] != '>' && read_line[i] != '<'
		   && read_line[i] != '|')
		i++;
	i = skip_spaces(read_line, i);
	return (i);
}

int	skip_spaces(char *read_line, int i)
{
	while (read_line[i] == ' ')
		i++;
	return (i);
}
