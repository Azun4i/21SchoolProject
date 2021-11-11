/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:29:49 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:29:51 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
