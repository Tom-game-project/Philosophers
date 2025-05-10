#include "philo_data.h"
#include "reaper.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
// 哲学者の脳みそ
//
#include <stdint.h>
#include "print.h"

void
update_last_eat_time(t_philosopher_data *data)
{
	pthread_mutex_lock(&data->time_mutex);
	gettimeofday(&data->last_eat_timestamp, NULL);
	pthread_mutex_unlock(&data->time_mutex);
}


/// 自分（哲学者自身）が自分の死を判定するための関数
/// 誰かが死んだかどうかの判定
/// 確認すべきこと、だれかが死んでいるかどうかまた、死んだのは自分かどうか
bool get_some_one_die(t_reaper *reaper, t_philosopher_data *self)
{
	bool some_one_die;

	pthread_mutex_lock(&reaper->mutex);
	some_one_die = reaper->dead_philo != NULL;
	if (reaper->dead_philo == self)
	{
		// 自分が死んだことを宣言する
		philo_print(self, reaper->dead_time_stamp, "died\n");
	}
	pthread_mutex_unlock(&reaper->mutex);
	return (some_one_die);
}

/// 考えながら食事の時間を待つ
///
bool try_to_eat(t_philosopher_data *data)
{
	//printf("philo_id: %p %d\n", &data->philo_id, data->philo_id);
	if (data->philo_id % 2 == 0)
	{
		// thinking
		pthread_mutex_lock(&data->l_fork->mutex);
		if (get_some_one_die(data->reaper, data))
		{
			pthread_mutex_unlock(&data->l_fork->mutex);
			return (true);
		}
		philo_print(data, data->last_act_timestamp, "has taken a fork\n");
		pthread_mutex_lock(&data->r_fork->mutex);
		// 次の状態に移る前に自身の死亡判定
		// 自身の状態が死なら死神のsome_one_dieをtrueにする(mutexを忘れずに)
		// スコープをなるべく小さくして、タイムロスをなくす
		// 自分含めほかの哲学者の死亡判定(some_one_dieをチェック)
		// usleepまたは、mutexを解除してからreturnの処理のどちらか
		if (get_some_one_die(data->reaper, data))
		{
			pthread_mutex_unlock(&data->r_fork->mutex);
			pthread_mutex_unlock(&data->l_fork->mutex);
			return (true);
		}
		philo_print(data, data->last_act_timestamp, "has taken a fork\n");
		gettimeofday(&data->last_act_timestamp, NULL);
		philo_print(data, data->last_act_timestamp, "is eating\n");
		data->self_status = e_eating; // 隣の人から箸を得られたら
		// eating
		usleep_wrap(data->info.time_to_eat, data->last_act_timestamp);
		pthread_mutex_unlock(&data->r_fork->mutex); // 箸を置く
		pthread_mutex_unlock(&data->l_fork->mutex);
		return (false);
	}
	else
	{
		// thinking
		pthread_mutex_lock(&data->r_fork->mutex);
		if (get_some_one_die(data->reaper, data))
		{
			pthread_mutex_unlock(&data->r_fork->mutex);
			return (true);
		}
		pthread_mutex_lock(&data->l_fork->mutex);
		// 次の状態に移る前に死亡判定
		if (get_some_one_die(data->reaper, data))
		{
			pthread_mutex_unlock(&data->l_fork->mutex);
			pthread_mutex_unlock(&data->r_fork->mutex);
			return (true);
		}
		gettimeofday(&data->last_act_timestamp, NULL);
		philo_print(data, data->last_act_timestamp, "is eating\n");
		data->self_status = e_eating; // 隣の人から箸を得られたら
		// sleeping
		usleep_wrap(data->info.time_to_eat, data->last_act_timestamp);
		pthread_mutex_unlock(&data->l_fork->mutex);
		pthread_mutex_unlock(&data->r_fork->mutex); // 箸を置く
		return (false);
	}
}

bool try_to_sleep(t_philosopher_data *data)
{
	if (get_some_one_die(data->reaper, data))
		return (true);
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is sleeping\n");
	data->self_status = e_sleeping;
	update_last_eat_time(data);
	usleep_wrap(data->info.time_to_sleep, data->last_act_timestamp);
	return (false);
}

bool try_to_think(t_philosopher_data *data)
{
	if (get_some_one_die(data->reaper, data))
		return (true);
	gettimeofday(&data->last_act_timestamp, NULL);
	philo_print(data, data->last_act_timestamp, "is thinking\n");
	data->self_status = e_thinking;
	return (false);
}

void *philo_thread_func(void *param)
{
	t_philosopher_data *data;
	data = (t_philosopher_data *) param;

	update_last_eat_time(data);
	data->self_status = e_thinking;
	gettimeofday(&data->last_act_timestamp, NULL);
	while (true) 
	{
		//printf("hello world\n");
		if (data->self_status == e_thinking)
		{
			if (try_to_eat(data))
				break ;
		}
		else if (data->self_status == e_eating)
		{
			if (try_to_sleep(data))
				break ;
		}
		else 
		{
			if (try_to_think(data))
				break ;
		}
	}
	return (NULL);
}
