#include "philo_data.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
// 哲学者の脳みそ
//
#include <stdint.h>

/// 自分（哲学者自身）が自分の死を判定するための関数
bool am_i_dead(t_philosopher_data *data, struct timeval now)
{
	
	(void) data;

	int32_t seconds = now.tv_sec - data->last_eat_timestamp.tv_sec;
	int32_t microseconds = now.tv_usec - data->last_eat_timestamp.tv_usec;
	useconds_t d =  seconds * 1000 + microseconds * 1e-3;
	
	return (d >= data->info->time_to_die);
}


/// 考えながら食事の時間を待つ
///
void try_to_eat(t_philosopher_data *data)
{
	if (data->philo_id % 2 == 0)
	{
		// thinking
		pthread_mutex_lock(&data->l_fork->mutex);
		pthread_mutex_lock(&data->r_fork->mutex);
		// 次の状態に移る前に自身の死亡判定
		// 自身の状態が死なら死神のsome_one_dieをtrueにする(mutexを忘れずに)
		// スコープをなるべく小さくして、タイムロスをなくす
		// 自分含めほかの哲学者の死亡判定(some_one_dieをチェック)
		// usleepまたは、mutexを解除してからreturnの処理のどちらか
		data->self_status = e_eating; // 隣の人から箸を得られたら
		// eating
		usleep(data->info->time_to_eat);
		pthread_mutex_unlock(&data->r_fork->mutex); // 箸を置く
		pthread_mutex_unlock(&data->l_fork->mutex);
	}
	else
	{
		// thinking
		pthread_mutex_lock(&data->r_fork->mutex);
		pthread_mutex_lock(&data->l_fork->mutex);
		// 次の状態に移る前に死亡判定
		data->self_status = e_eating; // 隣の人から箸を得られたら
		// sleeping
		usleep(data->info->time_to_eat);
		pthread_mutex_unlock(&data->l_fork->mutex);
		pthread_mutex_unlock(&data->r_fork->mutex); // 箸を置く
	}
	// eating counterをインクリメント
	// 次の状態に移る前に死亡判定
	// 死亡判定諸々が終わってからeating timestamp更新
	data->self_status = e_sleeping;
}

void philo_sleeping(t_philosopher_data *data)
{
	printf("I am philo%d time to sleep\n", data->philo_id);
	usleep(data->info->time_to_sleep);
	printf("I am philo%d time to think\n", data->philo_id);
	data->self_status = e_thinking;
	// 考え始める
}

void *philo_thread_func(void *param)
{
	t_philosopher_data *data;

	data = (t_philosopher_data *) param;

	(void) data;
	data->self_status = e_thinking;
	while (1) 
	{
		// 死神役のスレッドにアクセスして、
		// 他の哲学者が死んだかどうかをチェックする
		//
		if (data->self_status == e_thinking)
		{
			// TODO 
		} else if (data->self_status == e_sleeping)
		{


		}
		else 
		{
			// 条件式にe_eatingはないが、関数内部で変化するだけなのでここに来る場合は必ず死
			//die
			pthread_mutex_lock(&data->info->mutex);
			data->info->die_flag = true;
			pthread_mutex_unlock(&data->info->mutex);
			break;
		}
	}
	return (NULL);
}
