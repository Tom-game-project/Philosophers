/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:17:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:20:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "philo_data.h"
# include "reaper.h"

int					set_philos(t_philosopher_data philos[],
						t_philo_fork forks[], t_info_table info,
						pthread_mutex_t *print_mutex);

int					set_reaper_to_philo(t_philosopher_data philos[],
						t_reaper *reaper);

t_philosopher_data	*init_philos(t_philo_fork forks[], t_info_table info,
						pthread_mutex_t *print_mutex);

void				*philo_thread_func(void *param);

#endif
