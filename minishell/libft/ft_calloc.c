/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:24:24 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:24:28 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*cllc;
	size_t			i;
	unsigned char	*cllc1;

	cllc = malloc(nmemb * size);
	if (cllc == NULL)
		return (NULL);
	i = 0;
	cllc1 = (unsigned char *)cllc;
	while (i < nmemb * size)
	{
		cllc1[i] = 0;
		i++;
	}
	return (cllc);
}
