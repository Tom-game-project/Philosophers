/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:23:35 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <stdio.h>

int	set_forks(t_philo_fork f[], int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&f[i].mutex, NULL);
		f[i].fork_id = i;
		i += 1;
	}
	return (0);
}
