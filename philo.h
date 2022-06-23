#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_data
{
	int count_of_philo;
	int time_to_eat;
	int time_to_sleep;
	int time_to_die;
	int count_of_eat;
}               t_data;

typedef struct	s_philo
{
	pthread_t	id;
	int			guid;
	int			num_of_eates;
	long long	time_to_die;
	int    		left_fork;
	int    		right_fork;

}				t_philo;

typedef struct  s_main
{
	int				key;
	int				philo_dead;
	long long		t0;	
	t_philo			*philo;
	t_data			data;
	pthread_t		spectator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}     t_main;

/*UTILS*/
int     	ft_atoi(const char *str);
void    	error_msg(char *str);
void		unlock_forks(t_main *main);
long long	get_time(void);
void		philo_free(t_main *main);

/*INIT*/
void		parse_args(char **argv, int argc, t_main *main);
void		init_philos(t_main *main);
void		init_forks(t_main *main);

/*TRHEADS*/
void    	create_threads(t_main *main);
void    	destroy_mutex(t_main *main);

/*ROUTINE*/
void    	*routine(void *args);
void    	*checker(void *args);
int			philo_print(t_main *main, int guid, char *status);

/*ACTIONS*/
int			drop_forks(t_main *main, int i);
int			philo_is_dead(t_main *main, int *i);
int			ft_think(t_main *main, int i);
int			ft_sleep(t_main *main, int i);
int			ft_eat(t_main *main, int i);
int			case_one_philo(t_main *main);

#endif
