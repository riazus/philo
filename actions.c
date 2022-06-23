#include "philo.h"

int ft_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].left_fork]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, FORK == 0);
		return (0);
	if (pthread_mutex_lock(&main->forks[main->philo[i].right_fork]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, FORK) == 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, FORK) == 0)
		return (0);
	main->philo[i].time_to_die = get_time();
	usleep(1000 * main->data.time_to_eat);
	drop_forks(main, i);
	return (1);
}

int ft_sleep(t_main *main, int i)
{
	if (philo_print(main->philo[i].id, SLEEP) == 0)
		return (0);
	usleep(1000 * main->data.time_to_sleep);
	return (1);
}

int ft_think(t_main *main, int i)
{
    
}
