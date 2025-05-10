#include "reaper.h"
#include <pthread.h>
#include <stdlib.h>


t_reaper *init_reaper()
{
	t_reaper *reaper;

	reaper = (t_reaper*) malloc(sizeof(t_reaper));

	pthread_mutex_init(&reaper->mutex, NULL);
	return (reaper);
}
