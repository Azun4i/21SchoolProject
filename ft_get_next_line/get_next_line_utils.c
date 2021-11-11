#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*s1;

	i = -1;
	len = ft_strlen(s);
	s1 = (char *)malloc((len + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	while (s[++i] != '\0')
		s1[i] = s[i];
	s1[i] = '\0';
	return (s1);
}

int	ft_strlen(const char *str)
{
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	*ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	i = -1;
	k = -1;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++k])
		str[i + k] = s2[k];
	str[i + k] = '\0';
	return (str);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
