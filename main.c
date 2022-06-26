/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:03 by jannabel          #+#    #+#             */
/*   Updated: 2022/06/25 19:16:05 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (parse_args(argv, argc, &main))
		return (1);
	if (init_philos(&main))
		return (1);
	if (init_forks(&main))
		return (1);
	if (main.data.count_of_philo == 1)
	{
		if (case_one_philo(&main) == 0)
			return (1);
		return (0);
	}
	if (create_threads(&main))
		return (1);
	if (destroy_mutex(&main))
		return (1);
	philo_free(&main);
	return (0);
}

int	case_one_philo(t_main *main)
{
	printf("|lol1|\n");
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	printf("|lol2|\n");
	main->t0 = get_time();
	philo_print(main, 1, FORK);
	usleep(main->data.time_to_die * 1000);
	philo_print(main, 1, DIED);
	philo_free(main);
	return (1);
}
