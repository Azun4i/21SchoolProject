/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:16:49 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/25 17:37:37 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 0
# define FALSE 1

typedef pthread_mutex_t	t_mutex;

typedef struct t_str
{
	int		control_die;
	int		flg_in_all;

}				t_str;

typedef struct s_pthread
{
	pthread_t				*threads;
	int						control_die;
	long long				deadline;
	unsigned int			name_phylo;
	unsigned long long		time_to_die;
	unsigned long long		time_to_eat;
	unsigned long long		time_to_sleep;
	unsigned int			times_eat;
	unsigned long long		tstmp_eat;
	unsigned long long		tstmp_die;
	long long				time_chek_to_die;
	unsigned long long		start_time;
	long long				num__philo_must_eat;
	t_mutex					*left_f;
	t_mutex					*right_f;
	t_mutex					*print;
	t_str					flag;
}				t_pthread;

typedef struct t_phylo
{
	long long			start_time;
	unsigned int		num_of_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	long long			num_of_time_philo_must_eat;
	unsigned long long	tstmp;
	t_mutex				*forks;
	t_mutex				print;
}				t_phylo;

unsigned long long	rft_atoi_l(const char *str);
void				r_help_print(t_pthread *phylo,
						unsigned long long time, int var);

/*cheker*/
int					chek_param(int args,
						char **argv, t_phylo *phylo, t_pthread *threads);

/*init*/
t_pthread			*initial_phylo(t_phylo *phylo,
						t_pthread *threads, unsigned int k);

/*do_phylo_live*/
void				*do_phylo_live(void *mas);

/*threads*/
int					r_get_started(t_phylo *phylo, t_pthread *threads);

/*utils*/
long long			get_tstm(void);
int					rft_print_error(char *str, int err_code);
void				rft_usleep(long long time);
int					ft_free_mtx(t_phylo *phylo,
						 t_pthread *threads, int err_code);

void				er_get_end(t_phylo *phylo, t_pthread *threads);
void				*check_die(t_phylo *phylo, t_pthread *threads);

#endif
