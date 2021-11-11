/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:16:27 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/25 17:41:47 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd (s, fd);
	write(fd, "\n", 1);
}

int	rft_print_error(char *str, int err_code)
{
	ft_putstr_fd("Error: ", 1);
	ft_putendl_fd(str, 1);
	return (err_code);
}

long long	get_tstm(void)
{
	struct timeval	t;
	long long		res;

	gettimeofday(&t, NULL);
	res = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (res);
}

void	rft_usleep(long long time)
{
	long long	check_time;

	check_time = get_tstm() + time;
	while (get_tstm() < check_time)
		usleep(330);
}
