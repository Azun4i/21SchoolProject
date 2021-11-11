#include "ft_push_swap.h"

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
		ft_check_if_sort(a);
		ft_wat_sort_need(&a);
		ft_free_stract(a);
	}
	return (0);
}
