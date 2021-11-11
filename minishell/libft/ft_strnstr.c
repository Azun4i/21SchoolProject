/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:31:10 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:31:30 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_helper(const char *big, const char *little, size_t i, size_t len)
{
	size_t		j;

	j = 0;
	while (big[i] == little[j] && big[i] != '\0'
		&& little[j] != '\0' && i < len)
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*substr;

	substr = (char *)big;
	i = 0;
	if (little[0] == '\0')
		return (substr);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			substr = (char *)&big[i];
			j = ft_helper(big, little, i, len);
			i++;
			if (little[j] == '\0')
				return (substr);
		}
		else
			i++;
	}
	return (NULL);
}
