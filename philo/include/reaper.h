/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:17:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:21:30 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAPER_H
# define REAPER_H

# include "philo_data.h"
# include <bits/pthreadtypes.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_reaper				t_reaper;

typedef struct s_philosopher_data	t_philosopher_data;
typedef struct s_info_table			t_info_table;

struct								s_reaper
{
	t_philosopher_data				*philosophers;
	t_philosopher_data				*dead_philo;
	struct timeval					dead_time_stamp;
	int								philo_counter;
	pthread_mutex_t					philo_counter_mutex;
	pthread_mutex_t					mutex;
	t_info_table					info;
};

void		*reaper_thread_func(void *param);

int			set_reaper(t_reaper *reaper, \
t_info_table info, t_philosopher_data *philosophers);

t_reaper	*init_reaper(t_info_table info, \
t_philosopher_data *philosophers);

int			set_reaper_to_philo(t_philosopher_data *philos, \
		t_reaper *reaper);

#endif
