/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:52:10 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:52:12 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern int	g_code;

int	ft_exit(char **flags, char **args, int i, int args_counter)
{
	int	code;

	code = g_code;
	while (flags[++i] != 0)
	{
		args_counter++;
		if (args_counter > 1)
			return (many_args_exit_error());
		if (is_all_digit(flags[i]) == -1)
			return (1);
		code = ft_atoi_exit(flags[i]);
	}
	i = -1;
	while (args && args[++i] != 0)
	{
		args_counter++;
		if (args_counter > 1)
			return (many_args_exit_error());
		if (is_all_digit(args[i]) == -1)
			return (1);
		code = ft_atoi_exit(args[i]);
	}
	g_code = code;
	return (1);
}

int	many_args_exit_error(void)
{
	printf("\033[91m<mohantochen>\033[0m: exit: too many arguments\n");
	g_code = 1;
	return (0);
}

int	is_all_digit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (arg[i] == '-' || arg[i] == '+')
		{
			i++;
			if (arg[i] == '\0')
			{
				printf("\033[91m<mohantochen>\033[0m: ");
				printf("exit: `%s': numeric argument required\n", arg);
				g_code = 255;
				return (-1);
			}
		}
		if (arg[i] < 48 || arg[i] > 57)
		{
			printf("\033[91m<mohantochen>\033[0m: ");
			printf("exit: `%s': numeric argument required\n", arg);
			g_code = 255;
			return (-1);
		}
	}
	return (0);
}

int	ft_atoi_exit(const char *nptr)
{
	int				i;
	int				minus_check;
	long long int	number;

	if (check_long_long(nptr) < 0)
		return (255);
	i = 0;
	minus_check = 1;
	number = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		   || nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			minus_check = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		number = number * 10 + (nptr[i++] - 48);
	number = number * minus_check;
	if (number < 0)
		number = 256 + number % 256;
	else if (number > 255)
		number = number % 256;
	return ((int)number);
}

int	check_long_long(const char *nptr)
{
	int	error_flag;

	error_flag = 0;
	if ((nptr[0] == '-' || nptr[0] == '+') && ft_strlen(nptr) > 20)
		error_flag = 1;
	if (nptr[0] == '-' && ft_strlen(nptr) == 20)
		if (ft_strcmp(nptr, "-9223372036854775808") > 0)
			error_flag = 1;
	if (nptr[0] == '+' && ft_strlen(nptr) == 20)
		if (ft_strcmp(nptr, "+9223372036854775807") > 0)
			error_flag = 1;
	if ((nptr[0] != '-' && nptr[0] != '+') && ft_strlen(nptr) == 19)
		if (ft_strcmp(nptr, "+9223372036854775807") > 0)
			error_flag = 1;
	if (error_flag == 1)
	{
		printf("\033[91m<mohantochen>\033[0m: ");
		printf("exit: `%s': numeric argument required\n", nptr);
		return (-1);
	}
	return (0);
}
