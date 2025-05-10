#ifndef TIME_H
#define TIME_H

#include <unistd.h>
#include <sys/time.h>

void delta_of_date(
	struct timeval *target,
	struct timeval right
);

int usleep_wrap(useconds_t wait_time, struct timeval base_time_stamp);

#endif
