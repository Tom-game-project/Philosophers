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
#include "philosopher.h"
#include "time.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

bool	try_to_eat_right(t_philosopher_data *data)
{
	pthread_mutex_lock(&data->l_fork->mutex);
	if (get_some_one_die(data->reaper, data) || is_full(*data))
		return (pthread_mutex_unlock(&data->l_fork->mutex), true);
	philo_print(data, data->last_act_timestamp, "has taken a fork\n");
	if (data->info.number_of_philosophers == 1)
		return (special_die_proc(data));
	if (get_some_one_die(data->reaper, data) || is_full(*data))
		return (pthread_mutex_unlock(&data->l_fork->mutex), true);
	pthread_mutex_lock(&data->r_fork->mutex);
	if (get_some_one_die(data->reaper, data) || is_full(*data))
	{
		pthread_mutex_unlock(&data->r_fork->mutex);
		pthread_mutex_unlock(&data->l_fork->mutex);
		return (true);
	}
	philo_print(data, data->last_act_timestamp, "has taken a fork\n");
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is eating\n");
	data->self_status = e_eating;
	usleep_wrap(data->info.time_to_eat, data->last_act_timestamp);
	pthread_mutex_unlock(&data->r_fork->mutex);
	pthread_mutex_unlock(&data->l_fork->mutex);
	return (false);
}

bool	try_to_eat_left(t_philosopher_data *data)
{
	usleep(100);
	pthread_mutex_lock(&data->r_fork->mutex);
	if (get_some_one_die(data->reaper, data) || is_full(*data))
	{
		pthread_mutex_unlock(&data->r_fork->mutex);
		return (true);
	}
	philo_print(data, data->last_act_timestamp, "has taken a fork\n");
	pthread_mutex_lock(&data->l_fork->mutex);
	if (get_some_one_die(data->reaper, data) || is_full(*data))
	{
		pthread_mutex_unlock(&data->l_fork->mutex);
		pthread_mutex_unlock(&data->r_fork->mutex);
		return (true);
	}
	philo_print(data, data->last_act_timestamp, "has taken a fork\n");
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is eating\n");
	data->self_status = e_eating;
	usleep_wrap(data->info.time_to_eat, data->last_act_timestamp);
	pthread_mutex_unlock(&data->l_fork->mutex);
	pthread_mutex_unlock(&data->r_fork->mutex);
	return (false);
}

bool	try_to_eat(t_philosopher_data *data)
{
	if (data->philo_id % 2 == 0)
		return (try_to_eat_right(data));
	else
		return (try_to_eat_left(data));
}

bool	try_to_sleep(t_philosopher_data *data)
{
	data->eat_counter += 1;
	if (data->eat_counter == \
			data->info.number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&data->reaper->philo_counter_mutex);
		data->reaper->philo_counter += 1;
		pthread_mutex_unlock(&data->reaper->philo_counter_mutex);
	}
	if (get_some_one_die(data->reaper, data) || is_full(*data))
		return (true);
	update_last_eat_time(data);
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is sleeping\n");
	data->self_status = e_sleeping;
	usleep_wrap(data->info.time_to_sleep, \
			data->last_act_timestamp);
	return (false);
}

bool	try_to_think(t_philosopher_data *data)
{
	if (get_some_one_die(data->reaper, data) || is_full(*data))
		return (true);
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is thinking\n");
	data->self_status = e_thinking;
	return (false);
}
