/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rft_atoi_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:17:03 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/25 17:24:08 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	r_help_print(t_pthread *phylo, unsigned long long time, int var)
{
	unsigned long long	res;

	res = time - phylo->start_time;
	pthread_mutex_lock(phylo->print);
	if (var == 1)
		printf("[timestamp: %lld] philosopher №%d has taken a fork\n",
			   res, phylo->name_phylo);
	else if (var == 2)
		printf("[timestamp: %lld] philosopher №%d is eating\n",
			   res, phylo->name_phylo);
	else if (var == 3)
		printf("[timestamp: %lld] philosopher №%d is sleeping\n",
			   res, phylo->name_phylo);
	else if (var == 4)
		printf("[timestamp: %lld] philosopher №%d is thinking\n",
			   res, phylo->name_phylo);
	else
		printf("[timestamp: %lld] philosopher №%d is died\n",
			   res, phylo->name_phylo);
	pthread_mutex_unlock(phylo->print);
}

int	ft_isdigit(int s)
{
	if (s >= '0' && s <= '9')
		return (1);
	else
		return (0);
}

static int	rft_int_len(const char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (!ft_isdigit(str[cnt]))
			return (-1);
		cnt++;
	}
	cnt = 0;
	while (str[cnt] >= '0' && str[cnt] <= '9')
		cnt++;
	return (cnt);
}

unsigned long long	rft_atoi_l(const char *str)
{
	unsigned long long	num;
	int					sing;
	int					len;

	num = 0;
	sing = 1;
	len = rft_int_len(str);
	if (len > 20 || len == 0 || len == -1)
		return (0);
	while (*str == ' ' || (*str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing *= 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str++;
		num -= '0';
	}
	return (num * sing);
}
