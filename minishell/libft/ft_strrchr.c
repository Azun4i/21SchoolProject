/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:31:38 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:31:38 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	i;

	c1 = (char)c;
	if (c == '\0' && ft_strlen(s) == 0)
		return ((char *)s);
	if (ft_strlen(s) == 0)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i != 0)
	{
		if (s[i] == c1)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == c1)
		return ((char *)&s[i]);
	if (c1 == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
