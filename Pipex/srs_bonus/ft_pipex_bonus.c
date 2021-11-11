#include "ft_pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_id	id;
	t_pip	pip;
	int		quan_fd;

	if (argc < 5)
		exit(1);
	ft_pip_void(&pip, env, argv, argc);
	quan_fd = argc - 3;
	if ((pipe(id.fd_a)) < 0 || (pipe(id.fd_b)) < 0)
		ft_print_error(2);
	ft_open_check(pip, &id, argv);
	while (quan_fd-- > 0)
	{
		id.id = fork();
		if (id.id < 0)
			ft_print_error(3);
		if (id.id == 0)
			bft_proc_child(pip, env, argv, &id);
		else
			bft_proc_main(&pip, &id);
	}
	wait(NULL);
	close(id.i_fd);
	close(id.o_fd);
	return (0);
}

void	ft_open_check(t_pip pip, t_id *id, char **argv)
{
	id->i_fd = open(argv[1], O_RDONLY);
	if (id->i_fd < 0)
		ft_print_error(4);
	id->o_fd = open(argv[pip.quan_argc], O_RDWR | O_TRUNC | O_CREAT,
			S_IREAD | S_IWRITE);
	if (id->o_fd < 0)
		ft_print_error(4);
}

t_pip	ft_add_fpath_flag_b(t_pip pip, char *path, char *argv)
{
	int		i;
	char	**tmp;
	char	**flag;
	char	*p;
	char	*tmp_path;

	tmp = ft_split(path, ':');
	flag = ft_split(argv, ' ');
	i = -1;
	while (tmp[++i])
	{
		p = ft_strjoin(tmp[i], "/");
		tmp_path = ft_strjoin(p, flag[0]);
		p = ft_free(p);
		if (access(tmp_path, 0) == 0)
		{
			pip.path_fool = tmp_path;
			pip.flag = flag;
			ft_free_mass(tmp, ft_count_mas(tmp));
			return (pip);
		}
		tmp_path = ft_free(tmp_path);
	}
	ft_print_error(8);
	return (pip);
}

void	ft_print_error(int er)
{
	if (er == 1)
		write(2, "To many arguments\n", 19);
	else if (er == 2)
		write(2, "Error pipe id\n", 15);
	else if (er == 3)
		write(2, "Error fork id\n", 15);
	else if (er == 4)
		write(2, "Can't open file\n", 17);
	else if (er == 5)
		write(2, "Error malloc\n", 14);
	else if (er == 6)
		write(2, "Exception path not found", 24);
	else if (er == 7)
		write(2, "Error dup2\n", 12);
	else if (er == 8)
		write(2, "Command not found\n", 19);
	exit(1);
}
