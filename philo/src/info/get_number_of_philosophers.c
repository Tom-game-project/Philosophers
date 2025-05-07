#include "philo_data.h"
#include <pthread.h>

int get_number_of_philosophers(t_info_table *info)
{
	int number_of_philosophers;

	pthread_mutex_lock(&info->mutex);
	number_of_philosophers = info->number_of_philosophers;
	pthread_mutex_unlock(&info->mutex);
	return (number_of_philosophers);
}
