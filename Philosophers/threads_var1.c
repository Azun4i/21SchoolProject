/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_var1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:16:35 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/25 18:11:10 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*do_phylo_live_var(void *ms);

int	r_get_started(t_phylo *phylo, t_pthread *threads)
{
	unsigned int	k;

	k = 0;
	phylo->start_time = get_tstm();
	while (k < phylo->num_of_philo)
	{
		threads[k].time_chek_to_die = phylo->start_time
			+(long long)phylo->time_to_die;
		pthread_create((pthread_t *) &threads[k], NULL, do_phylo_live_var,
			(void *)&threads[k]);
		k++;
	}
	check_die(phylo, threads);
	er_get_end(phylo, threads);
	return (TRUE);
}

void	*check_die(t_phylo *phylo, t_pthread *threads)
{
	unsigned int	k;

	while (1)
	{
		k = 0;
		while (k < phylo->num_of_philo)
		{
			if (threads[k].num__philo_must_eat == 0)
			{
				pthread_mutex_lock(threads->print);
				threads[k].flag.control_die = TRUE;
				return (NULL);
			}
			if (get_tstm() > threads[k].time_chek_to_die)
			{
				pthread_mutex_lock(threads->print);
				printf("[timestamp: %lld] philosopher №%u is dead\n",
					   threads[k].time_to_die, threads[k].name_phylo);
				threads[k].flag.control_die = TRUE;
				return (NULL);
			}
			k++;
		}
	}
}

void	er_get_end(t_phylo *phylo, t_pthread *threads)
{
	unsigned int	k;

	k = 0;
	if (phylo->num_of_philo == 1)
		pthread_mutex_destroy(&threads->left_f[k]);
	while (threads[k].flag.control_die != FALSE && k < phylo->num_of_philo)
	{
		pthread_join(threads->threads[k], NULL);
		k++;
	}
	ft_free_mtx(phylo, threads, 1);
}

void	ft_do_eat(t_pthread	*phylo)
{
	pthread_mutex_lock(phylo->left_f);
	r_help_print(phylo, get_tstm(), 1);
	pthread_mutex_lock(phylo->right_f);
	r_help_print(phylo, get_tstm(), 1);
	if (phylo->num__philo_must_eat > 0)
		phylo->num__philo_must_eat--;
	phylo->time_chek_to_die = get_tstm() + (long long) phylo->time_to_die;
	r_help_print(phylo, get_tstm(), 2);
	rft_usleep((long long)phylo->time_to_eat);
	pthread_mutex_unlock(phylo->right_f);
	pthread_mutex_unlock(phylo->left_f);
}

void	*do_phylo_live_var(void *ms)
{
	t_pthread	*phylo;

	phylo = ms;
	if (phylo->name_phylo % 2 == 0)
		usleep(10000);
	while (phylo->flag.control_die != TRUE)
	{
		if (phylo->num__philo_must_eat == 0)
			return (NULL);
		ft_do_eat(phylo);
		r_help_print(phylo, get_tstm(), 3);
		rft_usleep((long long)phylo->time_to_sleep);
		r_help_print(phylo, get_tstm(), 4);
	}
	return (NULL);
}
