#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_list_mass
{
	int					content;
	int					mark;
	struct s_list_mass	*next;
}	t_list_mass;

typedef struct s_flag
{
	int	max_count;
	int	content;
	int	count_command;
	int	content_a;
	int	content_b;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rrr;
	int	rr;
}				t_flag;

void		ft_swap(t_list_mass **a, char *str);
void		ft_ss(t_list_mass **a, t_list_mass **b, char *str);
void		ft_push(t_list_mass **a, t_list_mass **b, char *str);
void		ft_rotate(t_list_mass **a, char *str);
void		ft_rev_rotate(t_list_mass **a, char *str);
void		ft_rrr(t_list_mass **a, t_list_mass **b, char *str);
void		ft_rr(t_list_mass **a, t_list_mass **b, char *str);
/*algoritm*/
void		ft_wat_sort_need(t_list_mass **a);
void		ft_sort_small_list(t_list_mass **a, t_list_mass **b, int len);
void		ft_sort_three(t_list_mass **a, t_list_mass *p_min,
				t_list_mass *p_max);
void		ft_sort_four(t_list_mass **a, t_list_mass **b, t_list_mass *p_max);
void		ft_sort_five(t_list_mass **a, t_list_mass **b, t_list_mass *p_min);

void		ft_count_func(t_list_mass **a, t_list_mass **b);

t_flag		ft_find_mark(t_list_mass **a);
void		ft_mark_up(t_list_mass **a, t_flag flag, int cnt_rra);
void		ft_put_num_in_b(t_list_mass **a, t_list_mass **b);
t_flag		ft_use_find_mark(t_list_mass **a, int len_l);
void		ft_mark_up_1(t_list_mass **a);
/*utils*/
t_list_mass	*ft_find_max(t_list_mass *a);
t_list_mass	*ft_find_min(t_list_mass *a);
void		ft_new_flag(t_flag *flag);
int			ft_find_place(t_list_mass **a, t_list_mass *min);
void		ft_do_max_first_a(t_list_mass **a, int len_l);
t_flag		ft_add_cmd_in_ctr(t_flag flag_quan, t_flag result);
t_flag		ft_add_cmd_in_ctrrr(t_flag flag_quan, t_flag result);
t_flag		ft_add_func(t_flag flag_quan, t_flag result);
t_flag		ft_do_if_not_quan(t_list_mass **a, t_list_mass *ptr_b, t_flag
				flag_quan, int len_l);
void		ft_find_quantity(t_list_mass **a, t_list_mass **b, int len_l,
				int cnt_cmd);
t_flag		ft_find_ra_rra_quan(t_list_mass **a, t_list_mass **b,
				t_flag flag_quan, int len_l);
t_flag		ft_find_min_quan(t_flag flag_quan);
int			ft_max_rr_rrr(int a, int b);
int			ft_find_sum_min(t_flag temp_min);
void		ft_sort(t_list_mass **a, t_list_mass **b, t_flag flag);
int			ft_find_place(t_list_mass **a, t_list_mass *min);
int			ft_check_if_sort(t_list_mass *head);
void		ft_chek_str_if_big(char *tmp_0);
void		ft_post_error(int error);
int			ft_chek_min_plus(char *str);
int			ft_chek_mass(const int *mas, int len);
t_list_mass	*ft_lstnew(int content);
void		ft_lstadd_back(t_list_mass **lst, t_list_mass *new);
int			ft_lstadd_front(t_list_mass **lst, t_list_mass *new);
void		ft_lstclear(t_list_mass **lst, void (*del)(void *));
void		ft_lstdelone(t_list_mass *lst, void (*del)(void *));
void		ft_lstiter(t_list_mass *lst, void (*f)(void *));
t_list_mass	*ft_lstlast(t_list_mass *lst);
int			ft_lstsize(t_list_mass *lst);
void		ft_free_stract(t_list_mass	*a);
void		ft_free_char(char **matrix);
char		*ft_if_space(char *argv);
#endif