/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:31:47 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:31:47 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_helper(char const *s, unsigned int start, char *sub,
					   size_t fin_len)
{
	size_t	i;

	i = 0;
	while (i < fin_len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	fin_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (len > (ft_strlen(s) - start))
		fin_len = ft_strlen(s) - start;
	else
		fin_len = len;
	sub = (char *)malloc(sizeof(char) * (fin_len + 1));
	if (sub == NULL)
		return (NULL);
	return (ft_helper(s, start, sub, fin_len));
}
