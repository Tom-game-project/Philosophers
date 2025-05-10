#include <stdio.h>
#include "philo_data.h"
#include <pthread.h>
#include <unistd.h>

int philo_print(
	t_philosopher_data *data,
	struct timeval time,
	char *state
)
{
	useconds_t d;

	pthread_mutex_lock(data->print_mutex);
	d = time.tv_sec * 1000 + time.tv_usec * 1e-3;
	printf("%d %d %s", d, data->philo_id, state);
	pthread_mutex_unlock(data->print_mutex);
	return (0);
}
