#include "ft_push_swap.h"

char	*ft_if_space(char *argv)
{
	int	i;

	i = 0;
	if (!argv || argv[0] == '\0')
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	else
	{
		while (argv[i])
		{
			if (ft_isdigit(argv[i]) || argv[i] == '+' || (argv[i] == '-'
					&& ft_isdigit(argv[++i])))
				return (argv);
			else if (argv[i] == ' ' || argv[i] == '\0' || !ft_isdigit(argv[i]))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			i++;
		}
	}
	return (argv);
}
