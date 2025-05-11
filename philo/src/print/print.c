/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:51 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 16:58:51 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	philo_print(t_philosopher_data *data, struct timeval time, char *state)
{
	long	d;

	pthread_mutex_lock(data->print_mutex);
	d = time.tv_sec * 1000 + time.tv_usec * 1e-3;
	printf("%ld %d %s", d, data->philo_id, state);
	pthread_mutex_unlock(data->print_mutex);
	return (0);
}
