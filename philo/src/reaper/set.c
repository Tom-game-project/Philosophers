#include "philo_data.h"
#include "reaper.h"
#include <pthread.h>


static void 
cpy_info(t_reaper *data, t_info_table info)
{
	data->info.number_of_philosophers = info.number_of_philosophers;
	data->info.number_of_times_each_philosopher_must_eat = info.number_of_times_each_philosopher_must_eat;
	data->info.time_to_die = info.time_to_die;
	data->info.time_to_eat= info.time_to_eat;
	data->info.time_to_sleep = info.time_to_sleep;
}

int set_reaper(t_reaper *reaper, t_info_table info, t_philosopher_data *philosophers)
{
	reaper->dead_philo = NULL;
	reaper->philosophers = philosophers;
	pthread_mutex_init(&reaper->mutex, NULL);
	cpy_info(reaper, info);
	return (0);
}
