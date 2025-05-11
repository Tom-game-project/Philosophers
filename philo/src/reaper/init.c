#include "philo_data.h"
#include "reaper.h"
#include <pthread.h>
#include <stdlib.h>


t_reaper *init_reaper(t_info_table info, t_philosopher_data *philosophers)
{
	t_reaper *reaper;

	reaper = (t_reaper*) malloc(sizeof(t_reaper));

	set_reaper(reaper, info, philosophers);
	return (reaper);
}
