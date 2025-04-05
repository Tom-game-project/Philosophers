#include "philo_data.h"
#include <stdio.h>

/// 哲学者たちのフォークを用意する
int set_forks(t_philo_fork f[], int number_of_philosophers)
{
	int i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&f[i].mutex, NULL);
		f[i].fork_id = i;
		i += 1;
	}
	return (0);
}

