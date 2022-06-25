#include "philo.h"

static int	exec_routine(t_main *main, int i)
{
	if (!ft_eat(main, i))
		return (0);
	if (main->data.count_of_eat != main->philo[i].num_of_eates)
	{
		if (!ft_sleep(main, i))
			return (0);
		if (!ft_think(main, i))
			return (0);
	}
	return (1);
}

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	printf("|%d philo's key in routine|\n", main->key);
	i = main->key;
	printf("|%d philo's guid in routine|\n", main->philo[i].guid);
	if (main->philo[i].guid % 2 == 0)
	{
		printf("|%d - is $ 2|\n", main->philo[i].guid);
		usleep(50);
	}
	if (main->data.count_of_eat > 0)
	{
		while (main->philo[i].num_of_eates < main->data.count_of_eat
			&& !main->philo_dead)
			exec_routine(main, i);
	}
	else
	{
		while (!main->philo_dead)
		{
			if (!exec_routine(main, i))
				break ;
		}
	}
	return (NULL);
}

void	*checker(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->data.count_of_eat > 0)
	{
		while (main->philo[i].num_of_eates < main->data.count_of_eat
			&& !main->philo_dead)
		{
			if (philo_is_dead(main, &i))
				break ;
		}
	}
	else
	{
		while (!main->philo_dead)
		{
			if (philo_is_dead(main, &i))
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_main *main, int guid, char *status)
{
	long long	now;

	printf("|%d|\n", main->philo_dead);
	now = get_time() - main->t0;
	if (main->philo_dead)
		return (0);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->write);
		return (0);
	}
	printf("%lld.%lld - %d %s\n", now / 1000, now % 1000, guid, status);
	pthread_mutex_unlock(&main->write);
	return (1);
}
