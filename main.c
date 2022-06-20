#include "philo.h"

int main(int argc, char **argv)
{

	t_main main;

	parse_args(argv, argc, &main);
	// printf("|%d - number of philo|\n", data.number_of_philo);
	init_philos(&main);
	init_forks(&main);
	if (main.data.number_of_philo == 1)
	{
		if (case_one_philo(&main) == 0)
			return (1);
		return (0);
	}
	
	printf("------------------------------\n");
}

int	case_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	main->t0 = get_time();
	philo_print(main, 1, B_BLUE, FORK);
	exec_action(main->input.time_to_die);
	philo_print(main, 1, PINK, DIED);
	philo_free(main);
	return (1);
}