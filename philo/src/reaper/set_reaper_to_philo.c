
#include "reaper.h"

int set_reaper_to_philo(
	t_philosopher_data *philos,
	t_reaper *reaper
)
{
	int i;

	i = 0;
	while (i < reaper->info.number_of_philosophers)
	{
		philos[i].reaper = reaper;
		i += 1;
	}
	return (0);
}
