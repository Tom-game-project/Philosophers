/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:59:12 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 18:05:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_data.h"
#include <stdbool.h>

static bool	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	str_to_num(int num, char *str)
{
	int	i;

	if (*str == '\0')
		return (num);
	if (!ft_isdigit(*str))
		return (-1);
	i = num * 10 + (*str - '0');
	return (str_to_num(i, ++str));
}

static bool	arg_check(int number_of_philosophers, int time_to_die,
		int time_to_eat, int time_to_sleep)
{
	return (number_of_philosophers > 0 && time_to_eat >= 0 && time_to_die >= 0
		&& time_to_sleep >= 0);
}

/// return true without error
bool	set_args(int argc, char *argv[], t_info_table *arg_info)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	if (!(argc == 5 || argc == 6))
		return (false);
	a = str_to_num(0, argv[1]);
	b = str_to_num(0, argv[2]);
	c = str_to_num(0, argv[3]);
	d = str_to_num(0, argv[4]);
	if (!arg_check(a, b, c, d))
		return (false);
	if (argc == 5)
		e = -1;
	else
		e = str_to_num(0, argv[5]);
	arg_info->number_of_philosophers = a;
	arg_info->time_to_die = b;
	arg_info->time_to_eat = c;
	arg_info->time_to_sleep = c;
	arg_info->number_of_times_each_philosopher_must_eat = e;
	return (argc == 5 || (argc == 6 && e >= 0));
}
