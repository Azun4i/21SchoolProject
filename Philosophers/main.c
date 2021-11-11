/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:16:56 by cchelste          #+#    #+#             */
/*   Updated: 2021/09/25 17:45:04 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	chek_param(int args, char **argv, t_phylo *phylo, t_pthread *threads)
{
	(void ) threads;
	if (args < 5 || args > 6)
		return (rft_print_error("of quantity arguments", FALSE));
	phylo->num_of_philo = rft_atoi_l(argv[1]);
	phylo->time_to_die = rft_atoi_l(argv[2]);
	phylo->time_to_eat = rft_atoi_l(argv[3]);
	phylo->time_to_sleep = rft_atoi_l(argv[4]);
	if (!phylo->time_to_sleep || !phylo->time_to_die || !phylo->time_to_eat
		|| !phylo->num_of_philo)
		return (rft_print_error("of arguments", FALSE));
	if (args == 6)
	{
		phylo->num_of_time_philo_must_eat = rft_atoi_l(argv[5]) + 1;
		if (!phylo->num_of_time_philo_must_eat)
			return (rft_print_error("of arguments", FALSE));
	}
	else
		phylo->num_of_time_philo_must_eat = -1;
	return (TRUE);
}

int	ft_free_mtx(t_phylo *phylo, t_pthread *threads, int err_code)
{
	unsigned int	k;

	k = 0;
	while (k < phylo->num_of_philo)
	{
		pthread_mutex_destroy(&phylo->forks[k]);
		k++;
	}
	free(phylo->forks);
	pthread_mutex_destroy(&phylo->print);
	if (threads)
	{
		k = 0;
		while (k < phylo->num_of_philo)
		{
			pthread_mutex_destroy(threads[k].left_f);
			pthread_mutex_destroy(threads[k].right_f);
			k++;
		}
	}
	return (err_code);
}

int	mutex_initial(t_phylo *phylo, t_pthread *threads)
{
	unsigned int	k;

	k = 0;
	phylo->forks = (t_mutex *) malloc(sizeof (t_mutex) * phylo->num_of_philo);
	if (phylo->forks == NULL)
	{
		rft_print_error("Mutex not allocated", FALSE);
		return (ft_free_mtx(phylo, threads, FALSE));
	}
	while (k < phylo->num_of_philo)
	{
		if (pthread_mutex_init(&phylo->forks[k], NULL) != 0)
		{
			rft_print_error("Mutex not allocated", FALSE);
			return (ft_free_mtx(phylo, threads, FALSE));
		}
		k++;
	}
	if (pthread_mutex_init(&phylo->print, NULL) != 0)
		return (ft_free_mtx(phylo, threads, FALSE));
	return (TRUE);
}

t_pthread	*initial_phylo(t_phylo *phylo, t_pthread *threads, unsigned int	k)
{
	long long		tm;

	threads = (t_pthread *)malloc(sizeof (t_pthread) * phylo->num_of_philo);
	if (threads == NULL)
	{
		rft_print_error("thread wasn't allocated", FALSE);
		return (NULL);
	}
	tm = get_tstm();
	while (k < phylo->num_of_philo)
	{
		threads[k].name_phylo = k + 1;
		threads[k].time_to_die = phylo->time_to_die;
		threads[k].time_to_eat = phylo->time_to_eat;
		threads[k].time_to_sleep = phylo->time_to_sleep;
		threads[k].left_f = &phylo->forks[k];
		threads[k].right_f = &phylo->forks[(k + 1) % phylo->num_of_philo];
		threads[k].start_time = tm;
		threads[k].num__philo_must_eat = phylo->num_of_time_philo_must_eat;
		threads[k].print = &phylo->print;
		threads[k].time_chek_to_die = 0;
		threads[k].flag.control_die = FALSE;
		k++;
	}
	return (threads);
}

int	main(int args, char *argv[])
{
	t_phylo			phylo;
	t_pthread		*threads;
	unsigned int	k;

	k = 0;
	threads = NULL;
	if (chek_param(args, argv, &phylo, threads) != TRUE)
		return (-1);
	mutex_initial(&phylo, threads);
	threads = initial_phylo(&phylo, threads, k);
	if (threads == NULL)
		return (1);
	r_get_started(&phylo, threads);
	return (0);
}
