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
#include "reaper.h"
#include "philosopher.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	*philo_thread_func(void *param)
{
	t_philosopher_data	*data;

	data = (t_philosopher_data *)param;
	data->self_status = e_thinking;
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
