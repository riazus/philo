#include "philo.h"

void	parse_args(char **argv, int argc, t_main *main)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		while (argv[++i])
		{
			if (i == 1 && argv[i] != NULL)
				main->data.count_of_philo = ft_atoi(argv[i]);
			if (i == 2)
				main->data.time_to_die = ft_atoi(argv[i]);
			if (i == 3)
				main->data.time_to_eat = ft_atoi(argv[i]);
			if (i == 4)
				main->data.time_to_sleep = ft_atoi(argv[i]);
			if (i == 5)
				main->data.count_of_eat = ft_atoi(argv[i]);
		}
		if (i == 4)
			main->data.count_of_eat = -1;
	}
	else
		error_msg("invalid count of args!\n");
}

void	init_philos(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = 0;
	main->philo = malloc (sizeof(t_philo) * main->data.count_of_philo);
	if (main->philo == NULL)
		error_msg("Error while allocate memory for philos\n");
	while (i < main->data.count_of_philo)
	{
		main->philo[i].guid = i + 1;
		main->philo[i].num_of_eates = 0;
		main->philo[i].time_to_die = 0;
		main->philo[i].left_fork = i;
		if (i + 1 == main->data.count_of_philo)
			main->philo[i].right_fork = 0;
		else
			main->philo[i].right_fork = i + 1;
		i++;
	}
}

void	init_forks(t_main *main)
{
	int	i;
	int	count_ph;

	count_ph = main->data.count_of_philo;
	main->forks = malloc(sizeof(pthread_mutex_t) * count_ph + 1);
	if (main->forks == NULL)
		error_msg("Error while allcote memory for forks\n");
	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			error_msg("Error while init mutex");
		i++;
	}
}
