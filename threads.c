/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:30 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:16:32 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_join(main->philo[i].id, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(main->spectator, NULL) != 0)
		return (1);
	return (0);
}

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	while (i < main->data.count_of_philo)
	{
		main->key = i;
		//printf("|%d philo's key in create|\n", main->key);
		if (pthread_create(&main->philo[i].id, NULL, &routine, (void *)main)
			!= 0)
			return (1);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->spectator, NULL, &checker, (void *) main) != 0)
		return (1);
	usleep(1000);
	if (join_threads(main))
		return (1);
	return (0);
}

int	destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.count_of_philo)
	{
		if (pthread_mutex_destroy(&main->forks[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&main->write) != 0)
		return (1);
	return (0);
}
