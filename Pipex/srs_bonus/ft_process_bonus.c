#include "ft_pipex_bonus.h"

void	bft_proc_child(t_pip pip, char **env, char **argv, t_id *id)
{
	if (pip.iter == 0 || pip.quan_argc + 1 == pip.iter + 4)
		ft_first_lst_var(pip, env, argv, id);
	else
	{
		if (pip.iter % 2 == 1)
		{
			pip = ft_add_fpath_flag_b(pip, ft_find_path(env), argv[2 + pip
					.iter]);
			close(id->fd_b[0]);
			if ((dup2(id->fd_a[0], 0)) == -1 || (dup2(id->fd_b[1], 1)) == -1)
				ft_print_error(7);
		}
		else
		{
			pip = ft_add_fpath_flag_b(pip, ft_find_path(env), argv[2 + pip
					.iter]);
			close(id->fd_a[0]);
			if ((dup2(id->fd_b[0], 0)) == -1 || (dup2(id->fd_a[1], 1)) == -1)
				ft_print_error(7);
		}
	}
	execve(pip.path_fool, pip.flag, env);
}

void	bft_proc_main(t_pip *pip, t_id *id)
{
	if (pip->iter == 0 || (pip->quan_argc + 1 == pip->iter + 4))
		ft_first_lst_var_close(pip, id);
	else if (pip->iter % 2 == 1)
	{
		close(id->fd_a[0]);
		close(id->fd_b[1]);
		if (pipe(id->fd_a) < 0)
			ft_print_error(2);
	}
	else if (pip->iter % 2 == 0)
	{
		close(id->fd_a[1]);
		close(id->fd_b[0]);
		if (pipe(id->fd_b) < 0)
			ft_print_error(2);
	}
	pip->iter++;
}

void	ft_first_lst_var(t_pip pip, char **env, char **argv, t_id *id)
{
	if (pip.iter == 0)
	{
		pip = ft_add_fpath_flag_b(pip, ft_find_path(env), argv[2]);
		if (dup2(id->i_fd, 0) == -1)
			ft_print_error(7);
		if (dup2(id->fd_a[1], 1) == -1)
			ft_print_error(7);
	}
	else
	{
		pip = ft_add_fpath_flag_b(pip, ft_find_path(env), argv[2 + pip
				.iter]);
		if (pip.iter % 2 == 1)
		{
			if ((dup2(id->fd_a[0], 0)) == -1)
				ft_print_error(7);
		}
		else
			if ((dup2(id->fd_b[0], 0) == -1))
				ft_print_error(7);
		if (dup2(id->o_fd, 1) == -1)
			ft_print_error(7);
	}
	execve(pip.path_fool, pip.flag, env);
}

void	ft_first_lst_var_close(t_pip *pip, t_id *id)
{
	if (pip->iter == 0)
		close(id->fd_a[1]);
	else
	{
		if (pip->iter % 2 == 1)
			close(id->fd_a[0]);
		else if (pip->iter % 2 == 0)
			close(id->fd_b[0]);
	}
}
