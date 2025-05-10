/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:01:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:01:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#ifdef DEBUG

int	debug_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		rv;

	va_start(args, format);
	rv = vdprintf(fd, format, args);
	va_end(args);
	return (rv);
}
#else

int	debug_dprintf(int fd, const char *format, ...)
{
	(void) fd;
	(void) format;
	return (0);
}
#endif

