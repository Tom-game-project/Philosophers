#ifndef REAPER_H
#define REAPER_H

#include "philo_data.h"
#include <stdbool.h>
#include <pthread.h>
typedef struct s_reaper t_reaper;

typedef struct s_philosopher_data t_philosopher_data;
typedef struct s_info_table t_info_table;

/// プログラムが一回走るごとに、reaperスレッドが一つできます
struct s_reaper
{
	t_philosopher_data *philosophers;
	// それぞれの哲学者にアクセスするための配列
	t_philosopher_data *dead_philo; 
	// 死んだ哲学者の一人分のポインタ
	struct timeval dead_time_stamp;
	// 死んだ時間
	pthread_mutex_t mutex;
	t_info_table info;
       	// 死んだ哲学者が誰かを、それぞれの哲学者が状態を変化させる前に確認するので、その時にmutexを保護する
};

void *reaper_thread_func(void *param);

int set_reaper(t_reaper *reaper, t_info_table info, t_philosopher_data *philosophers);

t_reaper *init_reaper(t_info_table info, t_philosopher_data *philosophers);
#endif

