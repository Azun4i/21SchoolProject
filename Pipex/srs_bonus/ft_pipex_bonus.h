#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pip
{
	int		argc;
	char	**argv;
	char	**env;
	char	**flag;
	char	*path_fool;
	int		iter;
	int		quan_argc;
}t_pip;

typedef struct s_id
{
	int	id;
	int	fd_a[2];
	int	fd_b[2];
	int	i_fd;
	int	o_fd;
}t_id;

void	*ft_free(char *str);
void	ft_free_mass(char **matrix, int j);
char	*ft_find_path(char **env);
int		ft_count_mas(char **mas);
void	ft_pip_void(t_pip *pip, char **argv, char **env, int argc);
t_pip	ft_add_fpath_flag_b(t_pip pip, char *path, char *argv);
void	bft_proc_main(t_pip *pip, t_id *id);
void	bft_proc_child(t_pip pip, char **env, char **argv, t_id *id);
void	ft_print_error(int er);
void	ft_open_check(t_pip pip, t_id *id, char **argv);
void	ft_first_lst_var(t_pip pip, char **env, char **argv, t_id *id);
void	ft_first_lst_var_close(t_pip *pip, t_id *id);
#endif
