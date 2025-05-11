/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:59:23 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 18:00:42 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chopstick.h"
#include "philo_data.h"
#include "philosopher.h"
#include "reaper.h"
#include "setargs.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	thread_loop(
	t_info_table arg_info,
	pthread_t *tid_table,
	struct s_characters characters
)
{
	int	i;

	i = 0;
	while (i < arg_info.number_of_philosophers)
	{
		pthread_create(&tid_table[i], NULL, philo_thread_func,
			&characters.philosophers[i]);
		i += 1;
	}
	pthread_create(&tid_table[i], NULL, reaper_thread_func, characters.reaper);
	i = 0;
	while (i < arg_info.number_of_philosophers + 1)
	{
		pthread_join(tid_table[i], NULL);
		i += 1;
	}
}

int	main(int argc, char *argv[])
{
	t_info_table		arg_info;
	pthread_t			*tid_table;
	struct s_characters	characters;
	pthread_mutex_t		print_mutex;

	if (!set_args(argc, argv, &arg_info))
	{
		printf("arg error\n");
		return (1);
	}
	tid_table = (pthread_t *)malloc(sizeof(pthread_t)
			* (arg_info.number_of_philosophers + 1));
	memset(tid_table, 0, sizeof(pthread_t) * (arg_info.number_of_philosophers
			+ 1));
	characters.forks = init_forks(arg_info.number_of_philosophers);
	pthread_mutex_init(&print_mutex, NULL);
	characters.philosophers = init_philos(characters.forks, arg_info,
			&print_mutex);
	characters.reaper = init_reaper(arg_info, characters.philosophers);
	set_reaper_to_philo(characters.philosophers, characters.reaper);
	thread_loop(arg_info, tid_table, characters);
	free(tid_table);
	free(characters.forks);
	free(characters.philosophers);
	free(characters.reaper);
}
