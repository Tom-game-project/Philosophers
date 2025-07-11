/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reaper_to_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:59:02 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:59:37 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reaper.h"

int	set_reaper_to_philo(t_philosopher_data *philos, t_reaper *reaper)
{
	int	i;

	i = 0;
	while (i < reaper->info.number_of_philosophers)
	{
		philos[i].reaper = reaper;
		i += 1;
	}
	return (0);
}
