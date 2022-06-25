/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:15:37 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:15:45 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].left_fork]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, FORK) == 0)
		return (0);
	if (pthread_mutex_lock(&main->forks[main->philo[i].right_fork]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, FORK) == 0)
		return (0);
	if (philo_print(main, main->philo[i].guid, EAT) == 0)
		return (0);
	main->philo[i].time_to_die = get_time();
	usleep(1000 * main->data.time_to_eat);
	drop_forks(main, i);
	return (1);
}

int	ft_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].guid, SLEEP) == 0)
		return (0);
	usleep(1000 * main->data.time_to_sleep);
	return (1);
}

int	ft_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].guid, THINK) == 0)
		return (0);
	return (1);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->data.count_of_philo)
		*i = 0;
	time = get_time() - main->philo[*i].time_to_die;
	if (time > main->data.time_to_die)
	{
		philo_print(main, main->philo[*i].guid, DIED);
		main->philo_dead = 1;
		drop_forks(main, *i);
		return (1);
	}
	i++;
	return (0);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].left_fork]))
		return (0);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].right_fork]))
		return (0);
	main->philo[i].num_of_eates++;
	return (1);
}
