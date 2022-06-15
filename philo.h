#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

struct  s_phil
{
    int num;
    int right_fork;
    int left_fork;
    int sleep;
    int eat;
    int die;
}		t_phil;




#endif