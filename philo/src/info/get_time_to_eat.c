#include "philo_data.h"
#include <unistd.h>
#include <pthread.h>

/// なるべく、スコープの範囲を小さくした引数情報へのアクセス
useconds_t get_time_to_eat(t_info_table *info)
{
	useconds_t time_to_eat;

	pthread_mutex_lock(&info->mutex);
	time_to_eat = info->time_to_eat;
	pthread_mutex_lock(&info->mutex);
	return (time_to_eat);
}
