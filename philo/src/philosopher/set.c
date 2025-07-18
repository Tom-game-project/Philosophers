/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/16 16:10:34 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <bits/pthreadtypes.h>
#include <bits/types/struct_timeval.h>
#include <pthread.h>

static void	cpy_info(t_philosopher_data *data, t_info_table info)
{
	data->info.number_of_philosophers = info.number_of_philosophers;
	data->info.number_of_times_each_philosopher_must_eat = \
	info.number_of_times_each_philosopher_must_eat;
	data->info.time_to_die = info.time_to_die;
	data->info.time_to_eat = info.time_to_eat;
	data->info.time_to_sleep = info.time_to_sleep;
}

static void	set_time(struct timeval *target, struct timeval date)
{
	target->tv_sec = date.tv_sec;
	target->tv_usec = date.tv_usec;
}

int	set_philos(t_philosopher_data philos[], t_philo_fork forks[],
		t_info_table info, pthread_mutex_t *print_mutex)
{
	int				i;
	struct timeval	now;

	i = 0;
	gettimeofday(&now, NULL);
	while (i < info.number_of_philosophers)
	{
		cpy_info(&philos[i], info);
		philos[i].print_mutex = print_mutex;
		philos[i].philo_id = i;
		philos[i].eat_counter = 0;
		set_time(&philos[i].last_eat_timestamp, now);
		set_time(&philos[i].last_act_timestamp, now);
		pthread_mutex_init(&philos[i].time_mutex, NULL);
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % info.number_of_philosophers];
		i += 1;
	}
	return (0);
}
