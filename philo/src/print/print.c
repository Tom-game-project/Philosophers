#include <stdio.h>
#include "philo_data.h"
#include <pthread.h>

int philo_print(t_philosopher_data *data)
{
	pthread_mutex_lock(data->print_mutex);
	// print to say
	pthread_mutex_unlock(data->print_mutex);
	return (0);
}
