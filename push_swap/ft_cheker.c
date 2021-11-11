#include "ft_push_swap.h"

int	ft_check_if_sort(t_list_mass *head)
{
	int			i;
	int			*mas;
	int			len;
	t_list_mass	*tmp;

	i = 0;
	tmp = head;
	len = ft_lstsize(tmp);
	mas = (int *) malloc(sizeof (int) * len);
	while (tmp->next != NULL && i != len - 1)
	{
		if (tmp->content < tmp->next->content)
			mas[i] = 1;
		else
			mas[i] = 0;
		i++;
		tmp = tmp->next;
	}
	ft_chek_mass(mas, len);
	free(mas);
	mas = NULL;
	return (0);
}

int	ft_chek_mass(const int *mas, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (mas[i] == 1)
			count++;
		i++;
	}
	if (count == 0)
		ft_post_error(4);
	return (0);
}

void	ft_chek_str_if_big(char *tmp_0)
{
	int		i;
	int		len;
	char	*str;
	int		minus;

	minus = ft_chek_min_plus(tmp_0);
	if (*tmp_0 == '-' || *tmp_0 == '+')
		tmp_0++;
	len = ft_strlen(tmp_0);
	if (len > 10)
		ft_post_error(2);
	if (minus == 1)
		str = "2147483648";
	else
		str = "2147483647";
	i = 0;
	while (len > i)
	{
		if ((ft_isdigit(tmp_0[i])) == 0)
			ft_post_error(1);
		if (str[i] - tmp_0[i] < 0 && len == 10)
			ft_post_error(2);
		i++;
	}
}

int	ft_chek_min_plus(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	if (str[i] == '-')
		minus = 1;
	return (minus);
}

void	ft_post_error(int error)
{
	if (error == 1)
		write (1, "Error\n", 6);
	else if (error == 2)
		write (1, "Error\n", 6);
	else if (error == 3)
		write (1, "Error\n", 6);
	else if (error == 4)
		;
	exit(0);
}
