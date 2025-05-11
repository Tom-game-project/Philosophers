/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:54:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include "print.h"
#include "reaper.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	update_last_eat_time(t_philosopher_data *data)
{
	pthread_mutex_lock(&data->time_mutex);
	gettimeofday(&data->last_eat_timestamp, NULL);
	pthread_mutex_unlock(&data->time_mutex);
}

bool	get_some_one_die(t_reaper *reaper, t_philosopher_data *self)
{
	bool	some_one_die;

	pthread_mutex_lock(&reaper->mutex);
	some_one_die = reaper->dead_philo != NULL;
	if (reaper->dead_philo == self)
	{
		philo_print(self, \
			reaper->dead_time_stamp, "died\n");
		pthread_mutex_unlock(&reaper->mutex);
		return (true);
	}
	pthread_mutex_unlock(&reaper->mutex);
	return (some_one_die);
}

bool	is_full(t_philosopher_data data)
{
	bool	finish_eating;

	if (data.info.number_of_times_each_philosopher_must_eat == -1)
		return (false);
	pthread_mutex_lock(&data.reaper->philo_counter_mutex);
	finish_eating = \
		data.info.number_of_philosophers <= data.reaper->philo_counter;
	pthread_mutex_unlock(&data.reaper->philo_counter_mutex);
	return (finish_eating);
}

bool	special_die_proc(t_philosopher_data *data)
{
	pthread_mutex_lock(&data->reaper->mutex);
	usleep(data->info.time_to_die * 1000);
	usleep_wrap(data->info.time_to_die, data->last_act_timestamp);
	gettimeofday(&data->reaper->dead_time_stamp, NULL);
	philo_print(data, data->reaper->dead_time_stamp, "died\n");
	pthread_mutex_unlock(&data->reaper->mutex);
	return (true);
}
