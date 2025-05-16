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
#include "philosopher.h"
#include "reaper.h"
#include "time.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static void	eat_time_offset(

	t_philosopher_data *data)
{
	useconds_t	d;
	useconds_t	wait_step;
	useconds_t	wait_time;

	if (data->info.number_of_philosophers % 2 == 1)
	{
		d = data->info.number_of_philosophers / 2 + 1;
		wait_step = data->info.time_to_eat / d;
		if (data->philo_id % 2 == 0)
			wait_time = wait_step * (data->philo_id / 2);
		else
			wait_time = wait_step * (data->philo_id / 2)
				+ data->info.time_to_eat;
		usleep_wrap(wait_time, data->last_act_timestamp);
	}
}

void	*philo_thread_func(void *param)
{
	t_philosopher_data	*data;

	data = (t_philosopher_data *)param;
	data->self_status = e_thinking;
	eat_time_offset(data);
	if (get_some_one_die(data->reaper, data))
		return (NULL);
	while (true)
	{
		if (data->self_status == e_thinking)
		{
			if (try_to_eat(data))
				break ;
		}
		else if (data->self_status == e_eating)
		{
			if (try_to_sleep(data))
				break ;
		}
		else
		{
			if (try_to_think(data))
				break ;
		}
	}
	return (NULL);
}
