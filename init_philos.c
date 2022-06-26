/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:53 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:15:55 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(t_main *main)
{
	if (main->data.count_of_philo == -2
		|| main->data.time_to_die == -2
		|| main->data.time_to_eat == -2
		|| main->data.time_to_sleep == -2
		|| main->data.count_of_eat == -2)
	{
		printf("Invalid args.\n");
		return (1);
	}
	else
		return (0);
}

int	parse_args(char **argv, int argc, t_main *main)
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
		return (check_args(main));
	}
	else
		return (1);
}

int	init_philos(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = 0;
	main->philo = malloc (sizeof(t_philo) * main->data.count_of_philo);
	if (main->philo == NULL)
		return (1);
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
	return (0);
}

int	init_forks(t_main *main)
{
	int	i;
	int	count_ph;

	count_ph = main->data.count_of_philo;
	main->forks = malloc(sizeof(pthread_mutex_t) * count_ph + 1);
	if (main->forks == NULL)
		return (1);
	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
