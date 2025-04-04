#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "philo_data.h"

void *thread_func(void *param);

/// 哲学者たちのフォークを用意する
int set_forks(t_philo_fork f[], int number_of_philosophers)
{
	int i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(f[i].mutex, NULL);
		f[i].fork_id = i;
		i += 1;
	}
	return (0);
}

/// 哲学者を用意する
int set_philos(
	t_philosopher_data philos[],
       	t_philo_fork forks[],
       	int number_of_philosophers)
{
	int i;

	(void) philos;
	(void) forks;

	i = 0;
	while (i < number_of_philosophers)
	{
		i += 1;
	}
	return (0);
}

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
	t.number_of_philosophers = 5;
	t.time_to_die = 10;
	t.time_to_eat = 5;
	t.time_to_sleep = 10;
	t.number_of_times_each_philosopher_must_eat = -1;
	t.die_flag = false;

	tid_table = (pthread_t*) malloc(sizeof(pthread_t) * t.number_of_philosophers);
	philosophers = (t_philosopher_data *) malloc(sizeof(t_philosopher_data) * t.number_of_philosophers);
	forks = (t_philo_fork *) malloc(sizeof(t_philo_fork) * t.number_of_philosophers);
	int i;
	i = 0;
	while (i < t.number_of_philosophers)
	{
		int ret;
		ret = pthread_create(&tid_table[i], NULL, thread_func, NULL);
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
