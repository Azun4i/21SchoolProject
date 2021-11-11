#include "ft_push_swap.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>

void	ft_do_func(t_list_mass **a, t_list_mass **b, char *buf)
{
	if (ft_strnstr(buf, "pb", 2))
		ft_push(a, b, 0);
	else if (ft_strnstr(buf, "pa", 2))
		ft_push(b, a, 0);
	else if (ft_strnstr(buf, "sa", 2))
		ft_swap(a, 0);
	else if (ft_strnstr(buf, "sb", 2))
		ft_swap(b, 0);
	else if (ft_strnstr(buf, "ss", 2))
		ft_ss(a, b, 0);
	else if (ft_strnstr(buf, "rra", 3))
		ft_rev_rotate(a, 0);
	else if (ft_strnstr(buf, "rrb", 3))
		ft_rev_rotate(b, 0);
	else if (ft_strnstr(buf, "rrr", 3))
		ft_rrr(a, b, 0);
	else if (ft_strnstr(buf, "ra", 2))
		ft_rotate(a, 0);
	else if (ft_strnstr(buf, "rb", 2))
		ft_rotate(b, 0);
	else if (ft_strnstr(buf, "rr", 2))
		ft_rr(a, b, 0);
	else
		ft_post_error(1);
}

void	ft_checker(t_list_mass **a)
{
	char		*buf;
	t_list_mass	*b;

	b = NULL;
	buf = NULL;
	while (get_next_line(0, &buf))
	{
		ft_do_func(a, &b, buf);
		free(buf);
		buf = NULL;
	}
	free(buf);
	buf = NULL;
}

int 	ft_chek_sort(const int *mas, int len)
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
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	ft_check_if_sort0(t_list_mass *head)
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
	ft_chek_sort(mas, len);
	free(mas);
	mas = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	char		**tmp_0;
	t_list_mass	*a;

	a = NULL;
	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			tmp_0 = ft_split(ft_if_space(argv[i]), ' ');
			j = -1;
			while (tmp_0[++j])
			{
				ft_chek_str_if_big(tmp_0[j]);
				ft_lstadd_front(&a, ft_lstnew(ft_atoi(tmp_0[j])));
			}
			ft_free_char(tmp_0);
		}
		ft_checker(&a);
		ft_check_if_sort0(a);
		ft_free_stract(a);
	}
	return (0);
}
