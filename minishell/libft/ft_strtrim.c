/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:31:42 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:31:43 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_check(char c, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (1);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_trim(char const *s1, char *trimmed, size_t i, size_t j)
{
	size_t		x;

	x = 0;
	while (i < (j + 1))
	{
		trimmed[x] = s1[i];
		i++;
		x++;
	}
	trimmed[x] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*trimmed;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && (ft_set_check(s1[i], set) == 0))
		i++;
	if (i == ft_strlen(s1))
	{
		trimmed = (char *)malloc(sizeof(char) * 1);
		if (trimmed == NULL)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	else
		j = ft_strlen(s1) - 1;
	while (j > 0 && (ft_set_check(s1[j], set) == 0))
		j--;
	trimmed = (char *)malloc(sizeof(char) * (j - i + 2));
	if (trimmed == NULL)
		return (NULL);
	return (ft_trim(s1, trimmed, i, j));
}
