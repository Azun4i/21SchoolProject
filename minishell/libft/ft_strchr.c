/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:30:30 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:30:30 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	size_t			i;
	char			*s1;

	c1 = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
		{
			s1 = (char *)&s[i];
			return (s1);
		}
		i++;
	}
	if (c1 == '\0')
	{
		s1 = (char *)&s[i];
		return (s1);
	}
	return (NULL);
}
