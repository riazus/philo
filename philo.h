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


typedef struct  s_phil
{
    pthread_t id;
    int status;
    int right_fork;
    int left_fork;
    int sleep;
    int eat;
    int die;
}     t_phil;

int ft_atoi(char *str);


#endif