/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:52:48 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:52:50 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern int	g_code;

int	check_next_symbol(char *line, int i)
{
	if ((line[i + 1] >= 48 && line[i + 1] <= 57)
		|| line[i + 1] == '_' || line[i + 1] == '?'
		|| (line[i + 1] >= 'A' && line[i + 1] <= 'Z')
		|| (line[i + 1] >= 'a' && line[i + 1] <= 'z'))
		return (0);
	else
		return (-1);
}

int	check_second_quote(char *line, int i, char c)
{
	i++;
	if (line[i] == '\0')
		return (-1);
	while (line[i] != '\0' && line[i] != c)
		i++;
	if (line[i] == '\0')
		return (-1);
	return (i + 1);
}

void	null_struct_dollar(t_dollar *d)
{
	d->i = 0;
	d->len = 0;
	d->flag = 2;
}
