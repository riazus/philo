#include "philo.h"

int main(int argc, char **argv)
{

	t_main main;

	parse_args(argv, argc, &main);
	//printf("|%d - number of philo|\n", main.data.count_of_philo);
	init_philos(&main);
	//printf("|%d - number of philo|\n", main.data.count_of_philo);
	init_forks(&main);
	//printf("|%d - number of philo|\n", main.data.count_of_philo);
	if (main.data.count_of_philo == 1)
	{
		//printf("|lol|\n");
		if (case_one_philo(&main) == 0)
			return (1);
		return (0);
	}
	printf("|creat thread|\n");
	create_threads(&main);

	
	printf("------------------------------\n");
}

int	case_one_philo(t_main *main)
{
	printf("|lol1|\n");
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	printf("|lol2|\n");
	main->t0 = get_time();
	philo_print(main, 1, FORK);
	//printf("|lol3|\n");
	usleep(main->data.time_to_die * 1000);
	philo_print(main, 1, DIED);
	philo_free(main);
	return (1);
}
