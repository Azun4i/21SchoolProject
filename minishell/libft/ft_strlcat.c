/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:30:49 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:30:50 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	if (dest_len >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	if (ft_strlen(src) + dest_len + 1 <= dstsize)
	{
		while (src[i] != '\0')
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	else
	{
		while (dest_len + i + 2 <= dstsize)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (ft_strlen(src) + dest_len);
}
