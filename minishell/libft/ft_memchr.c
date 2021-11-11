/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:29:40 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:29:40 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
		{
			s1 = &s2[i];
			return (s1);
		}
		i++;
	}
	return (NULL);
}
