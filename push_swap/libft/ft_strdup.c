#include "libft.h"

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
