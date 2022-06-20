#include "philo.h"

int create_threads(t_main *main)
{
    int i;

    i = 0;
    main->philo_dead = 0;
    main->t0 = get_time();
}