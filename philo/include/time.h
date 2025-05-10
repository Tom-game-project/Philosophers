#ifndef TIME_H
#define TIME_H

#include <unistd.h>
#include <sys/time.h>

void delta_of_date(
	struct timeval *target,
	struct timeval right
);

#endif
