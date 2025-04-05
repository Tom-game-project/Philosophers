#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "philo_data.h"

int set_philos(
	t_philosopher_data philos[],
       	t_philo_fork forks[],
	t_info_table *info // 引数の情報
);

t_philosopher_data *init_philos(
	t_philo_fork forks[],
	t_info_table *info // 引数の情報
);

void *philo_thread_func(void *param);

#endif
