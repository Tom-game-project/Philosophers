#include <sys/time.h>
#include <unistd.h>

/// calc target - right and set
void delta_of_date(
	struct timeval *target,
	struct timeval right
)
{
	target->tv_sec = target->tv_sec - right.tv_sec;
	target->tv_usec = target->tv_usec - right.tv_usec;
}

//void cpy_date(struct timeval *target, struct timeval *orig)
//{
//	target ->tv_sec = orig->tv_sec;
//	target->tv_usec = orig->tv_usec;
//}

int usleep_wrap(useconds_t wait_time, struct timeval base_time_stamp)
{
	struct timeval now;
	useconds_t d;

	gettimeofday(&now, NULL);
	delta_of_date(&now, base_time_stamp);
	d =  now.tv_sec * 1000 + now.tv_usec * 1e-3;
	while (d < wait_time)
	{
		usleep(10);
		gettimeofday(&now, NULL);
		delta_of_date(&now, base_time_stamp);
		d =  now.tv_sec * 1000 + now.tv_usec * 1e-3;
	}
	return (0);
}
