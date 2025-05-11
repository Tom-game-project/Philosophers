/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:18:03 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:18:04 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>
# include <unistd.h>

void	delta_of_date(struct timeval *target, struct timeval right);

int		usleep_wrap(useconds_t wait_time, struct timeval base_time_stamp);

#endif
