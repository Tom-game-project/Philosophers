/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:01:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/11 17:54:47 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

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
	(void)fd;
	(void)format;
	return (0);
}
#endif
