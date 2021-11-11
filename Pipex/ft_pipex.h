#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pip
{
	int		argc;
	char	**argv;
	char	**env;
	char	**flag;
	char	*path_fool;
}t_pip;

void	*ft_free(char *str);
void	ft_free_mass(char **matrix, int j);
char	*ft_find_path(char **env);
int		ft_count_mas(char **mas);
void	ft_pip_void(t_pip *pip);
t_pip	ft_add_fpath_flag(t_pip pip, char *path, char *argv);
void	ft_print_error(int er);
void	ft_proc_child(t_pip pip, int fd[], char **env, char **argv);
void	ft_proc_main(t_pip pip, int fd[], char **env, char **argv);
#endif
