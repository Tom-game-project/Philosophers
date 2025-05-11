/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopstick.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:17:41 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:17:41 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOPSTICK_H
# define CHOPSTICK_H

# include "philo_data.h"

int				set_forks(t_philo_fork f[], int number_of_philosophers);

t_philo_fork	*init_forks(int number_of_philosophers);

#endif
