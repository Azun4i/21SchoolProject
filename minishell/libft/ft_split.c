/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:30:25 by cchelste          #+#    #+#             */
/*   Updated: 2021/08/25 15:30:26 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			words_count++;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (s[0] != c && s[i - 1] != c)
		return (words_count + 1);
	else if (s[0] == c && s[i - 1] == c)
		return (words_count - 1);
	else
		return (words_count);
}

static int	ft_len(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_free(char **sp, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	return (0);
}

static char	**ft_operations(char **sp, char const *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (x < ft_wcount(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		sp[x] = (char *)malloc(sizeof(char) * (ft_len(s, c, i) - i + 1));
		if (sp[x] == NULL && ft_free(sp, x) == 0)
			return (NULL);
		while (i < ft_len(s, c, i))
		{
			sp[x][j] = s[i];
			j++;
			i++;
		}
		sp[x][j] = '\0';
		x++;
	}
	sp[x] = 0;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		sp = (char **)malloc(sizeof(char *) * 1);
		if (sp == NULL)
			return (NULL);
		sp[0] = 0;
		return (sp);
	}
	sp = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (sp == NULL)
		return (NULL);
	sp = ft_operations(sp, s, c);
	return (sp);
}
