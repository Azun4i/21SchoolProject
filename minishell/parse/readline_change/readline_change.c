/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_change.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:52:48 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:52:50 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

char	*change_line(char *line, t_env *env)
{
	char		*changed;
	t_dollar	d;
	int			i;

	null_struct_dollar(&d);
	changed = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (changed == NULL)
		malloc_error();
	i = -1;
	while (++i <= (int)ft_strlen(line))
		changed[i] = '\0';
	changed = copy_line_changed_main_cycle(changed, line, &d, env);
	while (d.len <= (int)ft_strlen(changed))
		changed[d.len++] = '\0';
	free(line);
	return (changed);
}

char	*copy_line_changed_main_cycle(char *changed, char *line,
									  t_dollar *d, t_env *env)
{
	while (line[d->i] != '\0')
	{
		if ((line[d->i] == 34 || line[d->i] == 39)
			&& check_second_quote(line, d->i, line[d->i]) != -1)
		{
			if (line[d->i] == 39)
				d->flag = 1;
			else if (line[d->i] == 34)
				d->flag = 2;
			d->start = d->i + 1;
			d->i = check_second_quote(line, d->i, line[d->i]);
			changed = handle_inside_quotes(changed, line, d, env);
		}
		else if (d->flag == 2 && line[d->i] == '$' && line[d->i + 1] != '\0'
			&& check_next_symbol(line, d->i) != -1)
		{
			changed = copy_dollar(line, changed, d->i + 1, env);
			d->i = find_dollar_end(line, d->i + 1);
			d->len = (int)ft_strlen(changed);
		}
		else
			changed[d->len++] = line[d->i++];
	}
	return (changed);
}

char	*handle_inside_quotes(char *changed, char *line,
							  t_dollar *d, t_env *env)
{
	if (d->start == d->i - 1)
		changed[d->len++] = 31;
	while (d->start < d->i - 1)
	{
		if (line[d->start] == ' ')
			changed[d->len++] = 30;
		else if (line[d->start] == '>')
			changed[d->len++] = 28;
		else if (line[d->start] == '<')
			changed[d->len++] = 29;
		else if (line[d->start] == '|')
			changed[d->len++] = 26;
		else if (line[d->start] == '$' && d->flag == 2
			&& check_next_symbol(line, d->start) != -1)
		{
			changed = copy_dollar(line, changed, d->start + 1, env);
			d->start = find_dollar_end(line, d->start + 1) - 1;
			d->len = (int)ft_strlen(changed);
		}
		else
			changed[d->len++] = line[d->start];
		d->start++;
	}
	d->flag = 2;
	return (changed);
}
