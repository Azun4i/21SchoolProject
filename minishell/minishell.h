/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor/cchelste <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:54:37 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/25 14:54:39 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_node
{
	char			*cmd;
	char			**flags;
	char			**args;
	struct s_node	*next;
}	t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_dollar
{
	int	i;
	int	len;
	int	flag;
	int	start;
}	t_dollar;

typedef struct s_id
{
	pid_t	id;
	int		fd_a[2];
	int		fd_b[2];
	int		i_fd;
	int		o_fd;
	int		r_fd_out;
	int		r_fd_in;
	int		flag_redir;
	int		save_i;
	int		save_o;
	int		stat;
	int		rid_fd[2];
	int		argc;
	char	**argv;
	char	**env;
	char	*path;
	char	**flag;
	char	*path_fool;
	int		iter;
	int		quan_argc;
}	t_id;

/*readline*/
void	rl_replace_line(const char *text, int clear_undo);
void	rl_clear_history(void);

/*main*/
void	change_oldpwd_and_shlvl(t_env **env, int argc, char *argv[]);
void	change_shell_lvl(t_env **env, int i);
void	errors(char *message);

/*signals*/
void	sigint_handler(int sig_num);
void	sigquit_inter_handler(int sig_num);
void	sigint_inter_handler(int sig_num);
void	sigexit_handler(t_env **env, char *read_line, t_node **n, int ctrld);
void	sigint_handler_redir(int sig_num);

/*list_maker folder - parse_main_cycle.c*/
t_node	*parse(t_node **n, char *read_line);
void	ft_lstadd_back_shell(t_node **lst, t_node *new);
int		find_and_skip_redir(char *read_line, int i);
int		redir_detected(char *read_line, int i);
int		skip_spaces(char *read_line, int i);

/*list_maker folder - lstnew_cmd.c*/
t_node	*ft_lstnew_cmd(char *read_line, int i);
int		get_cmd(char *read_line, int i, t_node *new);

/*list_maker folder - lstnew_flags.c*/
int		get_flags(char *read_line, int i, t_node *new);
int		get_flags_malloc(t_node *new, int flags_counter);
int		get_flags_count_flags(char *read_line, int i);
int		get_flags_etc(char *read_line, int flag_num, t_node *new, int temp);

/*list_maker folder - lstnew_args.c*/
int		get_args(char *read_line, int i, t_node *new);
int		get_args_count_args(char *read_line, int i);
int		get_args_etc(char *read_line, t_node *new, int temp, int arg_num);
void	args_flags_replacer(char *str, int j);

/*list_maker folder - lstnew_redir_pipe.c*/
t_node	*ft_lstnew_redir(char *read_line, int i);
t_node	*ft_lstnew_pipe(char *read_line, int i);
int		get_redir(char *read_line, int i, t_node *new);
int		get_redir_arg(char *read_line, int i, t_node *new);
int		skip_redir(char *read_line, int i);

/*readline_change folder - readline_change.c*/
char	*change_line(char *line, t_env *env);
char	*copy_line_changed_main_cycle(char *changed, char *line, t_dollar *d,
			t_env *env);
char	*handle_inside_quotes(char *changed, char *line, t_dollar *d,
			t_env *env);

/*readline_change folder - copy_dollar.c*/
char	*copy_dollar(char *line, char *changed, int i, t_env *env);
char	*copy_dollar_question(char *line, char *changed, t_env *env);
char	*copy_dollar_envvalue(char *line, char *changed, char *key,
			char *envvalue);
char	*ft_realloc(char *source, int size);
int		find_dollar_end(char *line, int i);

/*readline_change folder - readline_utils.c*/
int		check_second_quote(char *line, int i, char c);
void	null_struct_dollar(t_dollar *d);
int		check_next_symbol(char *line, int i);

/*env folder - env_change.c*/
void	export_with_args(t_env **enve, char **keyvalue);
void	env_value_change(t_env **enve, char *keyvalue);
int		env_value_change_searchlist(t_env **enve, char *keyvalue, char *key,
			int flag_found);

/*env folder - env_change_utils.c*/
int		check_key(char *key);
int		check_for_equal(char *keyvalue);
char	*get_key(char *keyvalue);
char	*get_value(char *keyvalue);

/*env folder - env_creation.c*/
t_env	*create_env_list(t_env **env, char **envp);
t_env	*ft_lstnew_env(char *envp);
int		ft_lstnew_env_copyvalue(t_env *new, char *envp, int i);
void	ft_lstadd_back_env(t_env **lst, t_env *new);

/*env folder - env_export_print.c*/
void	print_env(t_env *env);
void	export(t_env *env);
t_env	*ft_lstnew_export(char *key, char *value);
void	sort_export(t_env **export);
void	print_export(t_env *export);

/*env folder - env_to_array.c*/
char	**make_env_array(t_env *env);
void	copy_env_array(t_env *env, char **array);

/*env folder - unset.c*/
void	ft_unset(t_env **env, char *args);
void	ft_unset_array(t_env **env, char **args);
int		there_is_nonvalid(char *arg);

/*exit*/
int		ft_exit(char **flags, char **args, int i, int args_counter);
int		many_args_exit_error(void);
int		is_all_digit(char *arg);
int		ft_atoi_exit(const char *nptr);
int		check_long_long(const char *nptr);

/*double_redir_read.c*/
void	malloc_error(void);
int		double_redir_read(char *arg, t_id *id);

/*free*/
char	*free_list_line(char *read_line, t_node **n);
void	ft_lstclear_shell(t_node **lst, void (*del)(char *cmd, char **flags,
				char **args));
void	del(char *cmd, char **flags, char **args);
void	free_env(t_env **env);

/*cchelste*/
void	cchelste(t_node *n, t_env **env, char *read_line, t_id *id);
char	*rft_add_fpath_flag(char *path, char **flag);
int		rft_strchr(const char *s, int c);
void	ft_pipex(t_node *n, t_env *env, t_id *id, char *read_line);

/*builtins*/
void	rft_pwd(void);
void	rft_echo(char **flags, char **args);
int		rft_cd(char **path, char **flag, t_env **env, int result);
char	*ft_get_cwd(void);
void	ft_add_old_pwd(t_env **env);
void	ft_add_new_pwd(t_env **env);

/*utils_chell*/
int		ft_lstsize_b(t_node *lst);
char	*ft_find_key(t_env *env, char *key);
int		ft_count_pipe(t_node *n);
int		ft_other_func_exec(t_node *n, t_env **env, t_id *id);
int		ft_find_pipe(t_node *n);
char	*ft_do_local(char **flag);
char	**ft_do_add_args_flags(char **flag, char **args);
void	print_list(t_node *n);/*dell*/
void	*ft_free(char *str);
void	*ft_free_mass(char **matrix, int j);
char	*ft_find_path(char **env);
int		ft_count_mas(char **mas);
void	ft_pip_void(t_id *id, int argc, char *path);
void	bft_proc_main(t_id *id);
void	bft_proc_child(t_node *n, t_id *id, char *read_line, t_env **env_1);
void	ft_print_error(int er);
void	ft_open_check(t_id *id, char **argv);
void	ft_first_lst_var(t_node *n, t_id *id, char*read_line, t_env **env_1);
void	ft_first_lst_var_close(t_id *id);
int		ft_get_fd_file(char *cmd, char *args, t_id *id);
int		ft_found_left_red(t_node *n);
void	ft_do_dup(t_node *n, t_id *id);
char	*ft_ft_do_local_0(char *path, char **flag);
void	ft_run_biltin(t_node *n, t_env **env, char *read_line, t_id *id);
int		is_biltin(char *cmd);
int		ft_if_redir(t_node *n, t_env **env, char *read_line, t_id *id);
int		rft_check_path(char *path, char *env, t_node *n, t_id *id);
char	*ft_do_zero(char *pwd, char *tmp, char *path_full, char *flag);
void	ft_do_add_args_flags_litl(char	**tmp, char **flag, char **args);
int		ft_count_redir(t_node *n);
int		ft_find_rev_rdir(t_node *n);
t_node	*ft_while_left(t_node *n, t_env **env, char *read_line, t_id *id);
t_node	*ft_while_right(t_node *n, t_env **env, char *read_line, t_id *id);
int		ft_get_fd_out(t_node *n, t_id *id);
int		ft_get_fd_in(t_node *n, t_id *id);
int		ft_wat_redir_in(char *file_name, int flag, t_id *id, int fd);
int		ft_wat_redir_out(char *file_name, int flag, t_id *id);
int		ft_syntax_error(char *file_name);
int		ft_check_register(char *str);
int		ft_check_res_if_o(int result, char **flag, char **path);
void	r_read_left_redir(char *arg, t_id *id);
void	ft_utl_path_direct(t_node *n, t_env **env, t_id *id);
void	ft_do_errors(char *cmd);
void	ft_do_g_code(int stat, char	*path_full);
int		ft_get_flag_in_get_fd_out(char *args, char *cmd, t_id *id, int flag);
int		ft_fd_in_get_fd_in(t_id *id, char *args, char *cmd, char *file_name);

#endif
