#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#include "philo_data.h"
#include "philosopher.h"
#include "chopstick.h"

void *thread_func(void *param);

int main(int argc, char *args[])
{
	(void) argc;
	(void) args;
	t_info_table t;
	pthread_t *tid_table;
	t_philosopher_data *philosophers;
	t_philo_fork *forks;

	(void) t;
	(void) philosophers;
	(void) forks;

	/// 後で、引数を確かめる
	t.number_of_philosophers = 4;
	t.time_to_die = 410;
	t.time_to_eat = 200;
	t.time_to_sleep = 200;
	//t.time_to_die = 310; // 4 310 200 100
	//t.time_to_eat = 200;
	//t.time_to_sleep = 100;
	t.number_of_times_each_philosopher_must_eat = -1;
	t.die_flag = false;
	pthread_mutex_init(&t.mutex, NULL);

	tid_table = (pthread_t*) malloc(sizeof(pthread_t) * t.number_of_philosophers); // スレッド
	forks = init_forks(t.number_of_philosophers);
	philosophers = init_philos(forks, &t);

	int i;
	i = 0;
	while (i < t.number_of_philosophers)
	{
		int ret;
		ret = pthread_create(&tid_table[i], NULL, philo_thread_func, &philosophers[i]);
		(void) ret;
		i += 1;
	}

	/// thread の終了を待つ
	i = 0;
	while (i < t.number_of_philosophers)
	{
		int ret;

		ret = pthread_join(tid_table[i], NULL);
		(void) ret;
		i += 1;
	}
}

void *thread_func(void *param)
{
	// 非同期に実行する処理
	t_philosopher_data *data;

	data = param;
	printf("philo_id: %d\n", data->philo_id);
	return (NULL);
}
