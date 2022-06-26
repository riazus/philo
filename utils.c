/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:39 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:16:40 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		return (-2);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - '0');
		else
			return (-2);
		i++;
	}
	if (result <= 0)
		return (-2);
	return (result);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.count_of_philo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

// void	error_msg(char *str)
// {
// 	printf("%s", str);
// 	return (1);
// }

void	philo_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}
