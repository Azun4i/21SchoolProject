/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:30:45 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:30:46 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_if_null(char const *s1, char const *s2)
{
	char	*joined;

	if (s1 == NULL)
	{
		joined = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (joined == NULL)
			return (NULL);
		ft_strlcpy(joined, s2, ft_strlen(s2) + 1);
	}
	else
	{
		joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (joined == NULL)
			return (NULL);
		ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	}
	return (joined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		x;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
	{
		joined = ft_if_null(s1, s2);
		return (joined);
	}
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i] != '\0')
		joined[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[x++] = s2[i++];
	joined[x] = '\0';
	return (joined);
}
