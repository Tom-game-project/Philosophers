#ifndef PHILO_FORK_H
#define PHILO_FORK_H

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

/// 引数の情報を格納する
typedef struct s_info_table t_info_table;
typedef struct s_philo_fork t_philo_fork;
typedef enum e_philo_status t_philo_status;
typedef struct s_philosopher_data t_philosopher_data;

/// 以下の構造体はすべての哲学者が共有する
struct s_info_table
{
	// 引数で与えられる条件
	int number_of_philosophers;
	useconds_t time_to_die;
	useconds_t time_to_eat;
	useconds_t time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	bool die_flag; // 最初はfalse、哲学者が死んだタイミングでtrueになる
	pthread_mutex_t mutex;
};

enum e_philo_status
{
	e_die,
	e_thinking,
	e_eating,
	e_sleeping
};

struct s_philosopher_data
{
	int philo_id;  // スレッドごとの識別番号
	t_philo_status self_status;
	struct timeval last_eat_timestamp;
	uint64_t eat_counter;
	bool is_full; //指定した食事回数を超えたらfalse
	t_info_table *info; // 引数で与えられた条件と、他の哲学者が死んだかどうかの情報を保持する構造体
	t_philo_fork *r_fork; // 右手に持てるフォーク
	t_philo_fork *l_fork; // 左手に持てるフォーク
} ;

struct s_philo_fork
{
	pthread_mutex_t mutex; // この構造体のデータは
				// mutexで保護されている場合だけ触れる
	int	fork_id;
};

#endif
