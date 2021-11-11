/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:29:55 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:29:56 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_helper(unsigned char *dst1, unsigned char *src1, size_t len)
{
	len = len - 1;
	while (len >= 0)
	{
		dst1[len] = src1[len];
		if (len != 0)
			len--;
		else
			break ;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
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
	if (&dst1[0] < &src1[0])
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else
	{
		ft_helper(dst1, src1, len);
	}
	return (dst);
}
