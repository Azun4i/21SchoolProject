/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rft_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:23:28 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/04 10:23:30 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_chek_n(char *str, char j)
{
	int	k;

	k = 0;
	while (str[++k])
	{
		if (str[k] != j)
			return (1);
	}
	return (0);
}

void	rft_echo(char **flags, char **args)
{
	int	i;

	i = 1;
	if (args == NULL && flags[1] == NULL)
		write(1, "\n", 1);
	else
	{
		if (flags[1])
		{
			if (ft_chek_n(flags[1], 'n') != 0)
				printf("%s ", flags[1]);
			while (flags[++i] != NULL)
				printf("%s ", flags[i]);
		}
		i = -1;
		if (args)
			while (args[++i] != NULL)
				printf("%s ", args[i]);
		printf("\b");
		if (flags[1] && ft_chek_n(flags[1], 'n') == 0)
			;
		else
			printf("\n");
	}
	g_code = 0;
}

int	ft_check_register(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 3)
	{
		if ((str[0] == 'p' || str[0] == 'P') && (str[1] == 'w'
					|| str[1] == 'W') && (str[2] == 'd' || str[2] == 'D'))
			return (1);
	}
	else if (ft_strlen(str) == 4)
	{
		if ((str[0] == 'e' || str[0] == 'E') && (str[1] == 'c'
					|| str[1] == 'C') && (str[2] == 'h' || str[2] == 'H')
			&& (str[3] == 'o' || str[3] == 'O'))
			return (0);
	}
	return (-1);
}
