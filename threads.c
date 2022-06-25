#include "philo.h"

static void	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_join(main->philo[i].id, NULL) != 0)
			error_msg("Error while join philo thread\n");
		i++;
	}
	if (pthread_join(main->spectator, NULL) != 0)
		error_msg("Error while join spectrator thread\n");
}

void	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		error_msg("Error while init write mutex\n");
	while (i < main->data.count_of_philo)
	{
		main->key = i;
		printf("|%d philo's key in create|\n", main->key);
		if (pthread_create(&main->philo[i].id, NULL, &routine, (void *)main)
			!= 0)
			error_msg("Error while create philos threads\n");
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->spectator, NULL, &checker, (void *) main) != 0)
		error_msg("Error while create spectator thread\n");
	usleep(1000);
	join_threads(main);
}

void	destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_mutex_destroy(&main->forks[i]) != 0)
			error_msg("Error while destroy forks mutex\n");
		i++;
	}
	if (pthread_mutex_destroy(&main->write) != 0)
		error_msg("Error while destroy write mutex\n");
}
