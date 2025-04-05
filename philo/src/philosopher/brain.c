#include "philo_data.h"
#include <stdio.h>

// 哲学者の脳みそ
//

void *philo_thread_func(void *param)
{
	t_philosopher_data *data;

	data = (t_philosopher_data *) param;
	printf("Iam philo%d\n", data->philo_id);
	return (NULL);
}
