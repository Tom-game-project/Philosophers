#include "reaper.h"
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "philo_data.h"
#include "time.h"
#include <stdio.h>

bool is_dead(struct timeval last_eat_timestamp, long time_to_die)
{
	struct timeval now;

	gettimeofday(&now, NULL);

	long seconds = now.tv_sec - last_eat_timestamp.tv_sec;
	long microseconds = now.tv_usec - last_eat_timestamp.tv_usec;
	long d = seconds * 1000 + microseconds * 1e-3;
	//printf("useconds_t %lu %lu\n",time_to_die, d);
	return (time_to_die <= d);
}

#include <stdio.h>

bool set_dead_philo(t_reaper *data)
{
	int i;

	i = 0;
	while (i < data->info.number_of_philosophers)
	{
		pthread_mutex_lock(&data->mutex);
		pthread_mutex_lock(&data->philosophers[i].time_mutex);
		if (is_dead(data->philosophers[i].last_eat_timestamp, data->info.time_to_die))
		{
			data->dead_philo = &data->philosophers[i]; // ここで死んだ哲学者をセットする
			gettimeofday(&data->dead_time_stamp, NULL);
			pthread_mutex_unlock(&data->philosophers[i].time_mutex);
			pthread_mutex_unlock(&data->mutex);
			return (true);
		}
		pthread_mutex_unlock(&data->philosophers[i].time_mutex);
		pthread_mutex_unlock(&data->mutex);
		i += 1;
	}
	return (false);
}


void *reaper_thread_func(void *param)
{
	t_reaper *data;

	data = (t_reaper *)param;
	while (true) 
	{
		if (set_dead_philo(data))
			break ;
	}
	return (0);
}
