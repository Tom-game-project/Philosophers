#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#include "philo_data.h"
#include "philosopher.h"
#include "chopstick.h"
#include "reaper.h"


int main(int argc, char *args[])
{
	(void) argc;
	(void) args;
	t_info_table t;
	pthread_t *tid_table;
	t_philosopher_data *philosophers;
	t_reaper *reaper;
	t_philo_fork *forks;
	pthread_mutex_t print_mutex;

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
	t.number_of_times_each_philosopher_must_eat = 3;

	tid_table = (pthread_t*) malloc(sizeof(pthread_t) * t.number_of_philosophers + 1); // 哲学者の人数分のスレッドと死神用のスレッド
	forks = init_forks(t.number_of_philosophers);
	pthread_mutex_init(&print_mutex ,NULL);
	philosophers = init_philos(forks, t, &print_mutex);

	reaper = init_reaper(t, philosophers);
	set_reaper_to_philo(philosophers, reaper);

	int i;
	i = 0;
	while (i < t.number_of_philosophers)
	{
		pthread_create(&tid_table[i], NULL, philo_thread_func, &philosophers[i]);
		i += 1;
	}
	pthread_create(&tid_table[i], NULL, reaper_thread_func, reaper);

	/// thread の終了を待つ
	i = 0;
	while (i < t.number_of_philosophers + 1)
	{
		int ret;

		ret = pthread_join(tid_table[i], NULL);
		(void) ret;
		i += 1;
	}
}

