#include "ft_pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		id;
	int		pip_id;
	int		fd[2];
	t_pip	pip;

	if (argc <= 1)
		exit(1);
	if (argc != 5)
		ft_print_error(1);
	ft_pip_void(&pip);
	pip_id = pipe(fd);
	if (pip_id < 0)
		ft_print_error(2);
	id = fork();
	if (id < 0)
		ft_print_error(3);
	if (id == 0)
		ft_proc_child(pip, fd, env, argv);
	else
		ft_proc_main(pip, fd, env, argv);
	wait(NULL);
	return (0);
}

void	ft_proc_child(t_pip pip, int fd[], char **env, char **argv)
{
	int	i_fd;

	i_fd = open(argv[1], O_RDONLY);
	if (i_fd < 0)
		ft_print_error(4);
	close(fd[0]);
	pip = ft_add_fpath_flag(pip, ft_find_path(env), argv[2]);
	if (dup2(i_fd, 0) == -1 || dup2(fd[1], 1) == -1)
		ft_print_error(2);
	close(fd[1]);
	execve(pip.path_fool, pip.flag, env);
}

void	ft_proc_main(t_pip pip, int fd[], char **env, char **argv)
{
	int	o_fd;

	o_fd = open(argv[4], O_CREAT | O_RDWR, S_IRWXU);
	if (o_fd < 0)
		ft_print_error(4);
	close(fd[1]);
	pip = ft_add_fpath_flag(pip, ft_find_path(env), argv[3]);
	if (dup2(o_fd, 1) == -1 || dup2(fd[0], 0) == -1)
		ft_print_error(2);
	close(fd[0]);
	execve(pip.path_fool, pip.flag, env);
}

t_pip	ft_add_fpath_flag(t_pip pip, char *path, char *argv)
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
		write(2, "Error arguments\n", 17);
	else if (er == 2)
		write(2, "Error pipe id\n", 15);
	else if (er == 3)
		write(2, "Error fork id\n", 15);
	else if (er == 4)
		write(2, "Can't open file\n", 17);
	else if (er == 8)
		write(2, "Command not found\n", 19);
	exit(1);
}
