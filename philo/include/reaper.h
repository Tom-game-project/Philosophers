#ifndef REAPER_H
#define REAPER_H

#include "philo_data.h"
#include <stdbool.h>
#include <pthread.h>
typedef struct s_reaper t_reaper;

/// プログラムが一回走るごとに、reaperスレッドが一つできます
struct s_reaper
{
	t_philosopher_data *philosophers;
	// それぞれの哲学者にアクセスするための配列
	t_philosopher_data *dead_philo; 
	// 死んだ哲学者の一人分のポインタ
	pthread_mutex_t mutex;
	t_info_table info;
       	// 死んだ哲学者が誰かを、それぞれの哲学者が状態を変化させる前に確認するので、その時にmutexを保護する
};

#endif

