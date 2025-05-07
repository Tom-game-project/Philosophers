#ifndef REAPER_H
#define REAPER_H

#include <stdbool.h>
#include <pthread.h>
typedef struct s_reaper t_reaper;

/// プログラムが一回走るごとに、reaperスレッドが一つできます
struct s_reaper
{
	bool some_one_die; // 誰か他の哲学者が死んでいる
			   // any(philo)
	bool all_of_philo_are_full; // すべての哲学者がおなかいっぱい
				    // all(philo)
	pthread_mutex_t mutex;
};

#endif

