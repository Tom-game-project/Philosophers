#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "philo_data.h"
#include "reaper.h"

int set_philos(
	t_philosopher_data philos[],
       	t_philo_fork forks[],
	t_info_table info, // 引数の情報
	pthread_mutex_t *print_mutex
);

/// すべてのスレッドから参照可能な死神構造体をセットする
int set_reaper_to_philo(
	t_philosopher_data philos[],
	t_reaper *reaper
);

t_philosopher_data *init_philos(
	t_philo_fork forks[],
	t_info_table info, // 引数の情報
	pthread_mutex_t *print_mutex
);

void *philo_thread_func(void *param);

#endif
