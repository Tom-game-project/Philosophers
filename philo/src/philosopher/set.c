#include "philo_data.h"
#include <bits/pthreadtypes.h>

static void 
cpy_info(t_philosopher_data *data, t_info_table info)
{
	data->info.number_of_philosophers = info.number_of_philosophers;
	data->info.number_of_times_each_philosopher_must_eat = info.number_of_times_each_philosopher_must_eat;
	data->info.time_to_die = info.time_to_die;
	data->info.time_to_eat= info.time_to_eat;
	data->info.time_to_sleep = info.time_to_sleep;
}

/// 哲学者に名前を与え
/// 両側にフォークを用意する
int set_philos(
	t_philosopher_data philos[],
       	t_philo_fork forks[],
	t_info_table info, // 引数の情報
	pthread_mutex_t *print_mutex
)
{
	int i;

	i = 0;
	while (i < info.number_of_philosophers)
	{
		cpy_info(&philos[i], info);
		philos[i].print_mutex = print_mutex;
		philos[i].philo_id = i;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % info.number_of_philosophers];
		i += 1;
	}
	return (0);
}

