/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:58:28 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:23:10 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <stdlib.h>
#include <stdio.h>
#include "chopstick.h"

t_philo_fork *init_forks(int number_of_philosophers)
{
	t_philo_fork *forks;

	forks = (t_philo_fork *) malloc(sizeof(t_philo_fork) * number_of_philosophers);
	if (forks == NULL)
		return (NULL);
	set_forks(forks, number_of_philosophers);
	return (forks);
}
