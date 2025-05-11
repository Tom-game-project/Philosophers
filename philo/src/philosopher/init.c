/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 16:58:43 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <bits/pthreadtypes.h>
#include <stdlib.h>
#include "philosopher.h"

/// freeが必要な配列を返却する
/// 長さはinfo->number_of_philosophers
t_philosopher_data *init_philos(
	t_philo_fork forks[],
	t_info_table info, // 引数の情報
	pthread_mutex_t *print_mutex
)
{
	t_philosopher_data *philosophers;

	philosophers = (t_philosopher_data *) malloc(sizeof(t_philosopher_data) * info.number_of_philosophers);
	if (philosophers == NULL)
		return (NULL);
	set_philos(philosophers, forks, info, print_mutex);
	return (philosophers);
}
