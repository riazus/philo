#include "philo.h"
/*
void* foo(void* p)
{
	printf("thread in foo\n");
	sleep(2);
	printf("after sleep\n");
	return NULL;
}

int parse_args(char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_atoi(argv[i]))
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	// if (!parse_args(argv) || argc != 5 || argc != 6)
	// {
	// 	error_msg("Check up your args!\n");
	// 	return (0);
	// }
	t_phil phil;
	phil.status = pthread_create(&phil.id, NULL, foo, NULL);
	pthread_join(phil.id, NULL);
	return (0);
}*/
/*
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define PHT_SIZE 5

typedef struct philosopher_tag
{
	const char *name;
	unsigned left_fork;
	unsigned right_fork;
} philosopher_t;

typedef struct table_tag
{
	pthread_mutex_t forks[PHT_SIZE];
} table_t;

typedef struct philosopher_args_tag
{
	const philosopher_t *philosopher;
	const table_t *table;
} philosopher_args_t;

pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;

void init_philosopher(philosopher_t *philosopher,
					  const char *name,
					  unsigned left_fork,
					  unsigned right_fork)
{
	philosopher->name = name;
	philosopher->left_fork = left_fork;
	philosopher->right_fork = right_fork;
}

void init_table(table_t *table) {
	size_t i;
	for (i = 0; i < PHT_SIZE; i++) {
		pthread_mutex_init(&table->forks[i], NULL);
	}
}

void* eat(void *args)
{
	philosopher_args_t *arg = (philosopher_args_t*) args;
	const philosopher_t *philosopher = arg->philosopher;
	const table_t *table = arg->table;
	unsigned rand;

	while (1)
	{
		printf("%s started dinner\n", philosopher->name);

		pthread_mutex_lock(&entry_point);
		pthread_mutex_lock(&table->forks[philosopher->left_fork]);
		srand(&rand);
		rand %= 1000;
		sleep(rand);
		pthread_mutex_lock(&table->forks[philosopher->right_fork]);
		pthread_mutex_unlock(&entry_point);

		printf("%s is eating after %d ms sleep\n", philosopher->name, rand);

		pthread_mutex_unlock(&table->forks[philosopher->right_fork]);
		pthread_mutex_unlock(&table->forks[philosopher->left_fork]);

		printf("%s finished dinner\n", philosopher->name);
	}
}
*/
void parse_args(char **argv, int argc, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		int i;

		i = 0;
		while (argv[++i])
		{
			if (i == 1 && argv[i] != NULL)
				data->number_of_philo = ft_atoi(argv[i]);
			if (i == 2)
				data->time_to_die = ft_atoi(argv[i]);
			if (i == 3)
				data->time_to_eat = ft_atoi(argv[i]);
			if (i == 4)
				data->time_to_sleep = ft_atoi(argv[i]);
			if (i == 5)
				data->count_of_eat = ft_atoi(argv[i]);
		}
	}
	else
		error_msg("invalid count of args!\n");
}

void    init_table(t_data *data)
{
	int i;
	
	i = 0;
	data->forks = malloc(sizeof (pthread_mutex_t) * data->number_of_philo);
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void init_philos(t_phil *phil, t_data *data)
{
	int i;
	
	i = 0;
	phil = malloc (sizeof(t_phil) * data->number_of_philo);
	while (i < data->number_of_philo)
	{
		phil[i].left_fork = i;
		if (i + 1 == data->number_of_philo)
			phil[i].right_fork = 0;
		else
			phil[i].right_fork = i + 1;
		i++;
	}
}

int main(int argc, char **argv)
{

	t_phil *phil;
	t_data data;

	parse_args(argv, argc, &data);
	// printf("|%d - number of philo|\n", data.number_of_philo);
	// printf("|%d - time to eat|\n", data.time_to_eat);
	// printf("|%d - time to die|\n", data.time_to_die);
	// printf("|%d - time to sleep|\n", data.time_to_sleep);
	// printf("|%d - count of eat|\n", data.count_of_eat);
	init_table(&data);
	//init_philos(phil, &data);
	int i;
	
	i = 0;
	phil = malloc (sizeof(t_phil) * data.number_of_philo);
	while (i < data.number_of_philo)
	{
		phil[i].left_fork = i;
		if (i + 1 == data.number_of_philo)
			phil[i].right_fork = 0;
		else
			phil[i].right_fork = i + 1;
		i++;
	}
	// pthread_t threads[PHT_SIZE];
	// philosopher_t philosophers[PHT_SIZE];
	// philosopher_args_t arguments[PHT_SIZE];
	// table_t table;
	// size_t i;

	// init_table(&table);

	// init_philosopher(&philosophers[0], "Alice", 0, 1);
	// init_philosopher(&philosophers[1], "Bob",   1, 2);
	// init_philosopher(&philosophers[2], "Clark", 2, 3);
	// init_philosopher(&philosophers[3], "Denis", 3, 4);
	// init_philosopher(&philosophers[4], "Eugin", 4, 0);

	// for (i = 0; i < PHT_SIZE; i++) {
	//     arguments[i].philosopher = &philosophers[i];
	//     arguments[i].table = &table;
	// }

	// for (i = 0; i < PHT_SIZE; i++) {
	//     pthread_create(&threads[i], NULL, eat, &arguments[i]);
	// }

	// for (i = 0; i < PHT_SIZE; i++) {
	//     pthread_join(threads[i], NULL);
	// }
	free(phil);
	free(&data);
}