/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:20 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:16:22 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = main->key;
	if (main->data.count_of_eat > 0)
	{
		while (main->philo[i].num_of_eates < main->data.count_of_eat
			&& !main->philo_dead)
		{
			if (main->philo_dead)
				break ;
			exec_routine(main, i);
		}
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
	i = 1;
	if (main->data.count_of_eat > 0)
	{
		while (main->philo[i].num_of_eates < main->data.count_of_eat
			&& !main->philo_dead)
		{
			if (philo_is_dead(main, &i))
				break ;
			i++;
		}
	}
	else
	{
		while (!main->philo_dead)
		{
			if (philo_is_dead(main, &i))
				break ;
			i++;
		}
	}
	return (NULL);
}

int	philo_print(t_main *main, int guid, char *status)
{
	long long	now;

	now = get_time() - main->t0;
	if (main->philo_dead)
		return (0);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->write);
		return (0);
	}
	printf("%lld - %d %s\n", now, guid, status);
	pthread_mutex_unlock(&main->write);
	return (1);
}
