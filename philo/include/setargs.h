/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setargs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:17:58 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:17:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETARGS_H
# define SETARGS_H

# include "philo_data.h"
# include <stdbool.h>

bool	set_args(int argc, char *argv[], t_info_table *arg_info);
#endif
