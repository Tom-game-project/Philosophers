#include "philo_data.h"
#include <stdio.h>

/// 哲学者に名前を与え
/// 両側にフォークを用意する
int set_philos(
	t_philosopher_data philos[],
       	t_philo_fork forks[],
	t_info_table *info // 引数の情報
)
{
	int i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		philos[i].info = info;
		philos[i].philo_id = i;
		//printf("philo_id: %p %d\n", &philos[i].philo_id, philos[i].philo_id);
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % info->number_of_philosophers];
		i += 1;
	}
	return (0);
}

