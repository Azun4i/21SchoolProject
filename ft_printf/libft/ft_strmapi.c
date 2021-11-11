#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = -1;
	if (!s)
		return (NULL);
	if (!f)
		return ((char *)s);
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[++i])
	{
		str[i] = (*f)(i, s[i]);
	}
	str[i] = '\0';
	return (str);
}
