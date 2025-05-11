/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:17:45 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:56:13 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info_table			t_info_table;
typedef struct s_philo_fork			t_philo_fork;
typedef enum e_philo_status			t_philo_status;
typedef struct s_philosopher_data	t_philosopher_data;
typedef struct s_reaper				t_reaper;

struct								s_info_table
{
	int								number_of_philosophers;
	useconds_t						time_to_die;
	useconds_t						time_to_eat;
	useconds_t						time_to_sleep;
	int								number_of_times_each_philosopher_must_eat;
};

enum								e_philo_status
{
	e_die,
	e_thinking,
	e_eating,
	e_sleeping
};

struct								s_philosopher_data
{
	int								philo_id;
	t_philo_status					self_status;
	struct timeval					last_eat_timestamp;
	pthread_mutex_t					time_mutex;
	struct timeval					last_act_timestamp;
	int								eat_counter;
	pthread_mutex_t					*print_mutex;
	t_info_table					info;
	t_reaper						*reaper;
	t_philo_fork					*r_fork;
	t_philo_fork					*l_fork;
};

struct								s_philo_fork
{
	pthread_mutex_t					mutex;
	int								fork_id;
};

struct s_characters
{
	t_philosopher_data			*philosophers;
	t_reaper					*reaper;
	t_philo_fork				*forks;
};

#endif
