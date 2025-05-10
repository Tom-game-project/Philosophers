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
typedef struct s_reaper t_reaper;

/// 以下の構造体はすべての哲学者が共有する
struct s_info_table
{
	// 引数で与えられる条件
	int number_of_philosophers;
	useconds_t time_to_die;
	useconds_t time_to_eat;
	useconds_t time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
};

/// 哲学者の状態
enum e_philo_status
{
	e_die,
	e_thinking,
	e_eating,
	e_sleeping
};

/// 哲学者
struct s_philosopher_data
{
	int philo_id;  // スレッドごとの識別番号
	t_philo_status self_status;
	struct timeval last_eat_timestamp;
	pthread_mutex_t time_mutex; 
	// 死神から参照される、last_eat_timestamp
	// を保護する
	struct timeval last_act_timestamp;
	uint64_t eat_counter;
	pthread_mutex_t *print_mutex; // 哲学者が一つのメガホンを共有するイメージ
	//指定した食事回数を超えたらfalse
	t_info_table info; // 引数で与えられた条件と、
	t_reaper *reaper;
	t_philo_fork *r_fork; // 右手に持てるフォーク
	t_philo_fork *l_fork; // 左手に持てるフォーク
} ;

/// フォーク
struct s_philo_fork
{
	pthread_mutex_t mutex;	// この構造体のデータは
				// mutexで保護されている場合だけ触れる
	int	fork_id;
};

#endif
