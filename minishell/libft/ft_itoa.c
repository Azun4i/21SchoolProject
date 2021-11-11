/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:26:38 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:26:40 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_str(char *str, int length, int n)
{
	long	lnb;
	int		j;

	lnb = n;
	if (n < 0)
	{
		str[0] = '-';
		lnb = lnb * -1;
	}
	str[length] = '\0';
	j = length - 1;
	while (j > 0)
	{
		str[j] = lnb % 10 + 48;
		lnb = lnb / 10;
		j--;
	}
	if (n >= 0)
		str[j] = lnb % 10 + 48;
}

char	*ft_itoa(int n)
{
	long	lnb;
	long	temp_n;
	int		i;
	char	*str;

	lnb = n;
	if (n < 0)
		lnb = lnb * -1;
	temp_n = lnb;
	i = 0;
	while (temp_n > 0)
	{
		temp_n = temp_n / 10;
		i++;
	}
	if (n < 0)
		i = i + 1;
	if (n == 0)
		i = 1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	ft_create_str(str, i, n);
	return (str);
}
