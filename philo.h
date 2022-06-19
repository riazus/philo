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
	pthread_mutex_t *forks;
	pthread_mutex_t picking_forks;
}               t_data;



typedef struct  s_phil
{
	pthread_t       id;
	int             status;
	int				key;
	unsigned int    left_fork;
	unsigned int    right_fork;
	t_data          data;
}     t_phil;

int     ft_atoi(const char *str);
void    error_msg(char *str);


#endif