#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct s_data
{
	int number_of_philo;
	int time_to_eat;
	int time_to_sleep;
	int time_to_die;
	int count_of_eat;
}               t_data;

typedef struct	s_philo
{
	int			key;
	pthread_t	id;
	int			num_of_eates;
	long long	time_to_die;
	int    		left_fork;
	int    		right_fork;

}				t_philo;

typedef struct  s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;	
	t_philo			*philo;
	t_data			data;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}     t_main;

/*UTILS*/
int     ft_atoi(const char *str);
void    error_msg(char *str);
void	unlock_forks(t_main *main);

/*INIT*/
void	parse_args(char **argv, int argc, t_main *main);
void	init_philos(t_main *main);
void	init_forks(t_main *main);

#endif